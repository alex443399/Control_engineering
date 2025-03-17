#include <stdio.h>
#include <stdlib.h>
#include "Model_feedforward.h"
#include "Model_feedforward_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "ext_work.h"
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_mutex_t rateTaskFcnRunningMutex[1];
int testForRateOverrun(int rateID);
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(Model_feedforward_M) == (NULL)) &&
    !rtmGetStopRequested(Model_feedforward_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);
    pthread_mutex_lock(&rateTaskFcnRunningMutex[0]);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(Model_feedforward_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Model_feedforward_M, true);
      }

      if (rtmGetStopRequested(Model_feedforward_M) == true) {
        rtmSetErrorStatus(Model_feedforward_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Model_feedforward_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Model_feedforward_M, true);
      }
    }

    Model_feedforward_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    pthread_mutex_unlock(&rateTaskFcnRunningMutex[0]);
    stopRequested = !((rtmGetErrorStatus(Model_feedforward_M) == (NULL)) &&
                      !rtmGetStopRequested(Model_feedforward_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(Model_feedforward_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  MW_killPyserver();
  mwRaspiTerminate();

  /* Terminate model */
  Model_feedforward_terminate();
  rtExtModeShutdown(2);
  sem_post(&stopSem);
  return NULL;
}

int testForRateOverrun(int rateID)
{
  if (pthread_mutex_trylock(&rateTaskFcnRunningMutex[rateID]) == 0) {
    pthread_mutex_unlock(&rateTaskFcnRunningMutex[rateID]);
    return 0;                          /* Not overruning this rate */
  } else {
    reportOverrun(rateID);
    return 1;                          /* Overruning this rate */
  }
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  mwRaspiInit();
  MW_launchPyserver();
  rtmSetErrorStatus(Model_feedforward_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  Model_feedforward_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Model_feedforward_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Model_feedforward_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Model_feedforward_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.00025, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  {
    int idxMutex;
    for (idxMutex=0; idxMutex<1; idxMutex++)
      pthread_mutex_destroy(&rateTaskFcnRunningMutex[idxMutex]);
  }

  return 0;
}
