/*
 * Model_feedforward.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Model_feedforward".
 *
 * Model version              : 9.12
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Mar 17 15:59:14 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Model_feedforward_h_
#define RTW_HEADER_Model_feedforward_h_
#ifndef Model_feedforward_COMMON_INCLUDES_
#define Model_feedforward_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* Model_feedforward_COMMON_INCLUDES_ */

#include "Model_feedforward_types.h"
#include <stddef.h>
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "rtGetInf.h"
#include <float.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  size_t bytesOutSizet;
  FILE* filestar;
  FILE* filestar_m;
  real_T Startsetpoint;                /* '<S5>/Start setpoint' */
  real_T SFunction[3];                 /* '<S6>/S-Function' */
  real_T SFunction_b;                  /* '<S9>/S-Function' */
  real_T ec_Ebox_o1[2];                /* '<S8>/ec_Ebox' */
  real_T ec_Ebox_o2[2];                /* '<S8>/ec_Ebox' */
  real_T ec_Ebox_o3[8];                /* '<S8>/ec_Ebox' */
  real_T Gain1;                        /* '<S7>/Gain1' */
  real_T Dctpd2;                       /* '<S7>/Dctpd2' */
  real_T Dct2lowpass3;                 /* '<S7>/Dct2lowpass3' */
  real_T Dctleadlag4;                  /* '<S7>/Dctleadlag4' */
  real_T Dctnotch5;                    /* '<S7>/Dctnotch5' */
  real_T Noise;                        /* '<Root>/Noise' */
  real_T Gain2[4];                     /* '<S2>/Gain2' */
  real_T Constant1[8];                 /* '<S3>/Constant1' */
  real_T Gain[2];                      /* '<S8>/Gain' */
  real_T Saturation[2];                /* '<S8>/Saturation' */
  real32_T xout[3];
  real_T Sign;                         /* '<S2>/Sign' */
  real_T Add;                          /* '<Root>/Add' */
  real_T e;                            /* '<Root>/Sum' */
} B_Model_feedforward_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T NextOutput;                   /* '<Root>/Noise' */
  real_T fileID;                       /* '<S4>/SPERTE_measurement_function' */
  real_T SFunction_RWORK[50];          /* '<S6>/S-Function' */
  real_T Dctpd2_RWORK[2];              /* '<S7>/Dctpd2' */
  real_T Dct2lowpass3_RWORK[4];        /* '<S7>/Dct2lowpass3' */
  real_T Dctleadlag4_RWORK[2];         /* '<S7>/Dctleadlag4' */
  real_T Dctnotch5_RWORK[4];           /* '<S7>/Dctnotch5' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  uint32_T RandSeed;                   /* '<Root>/Noise' */
  uint32_T NS;                         /* '<S4>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S4>/SPERTE_measurement_function' */
  uint8_T busy;                        /* '<S4>/SPERTE_measurement_function' */
  boolean_T eml_autoflush[20];         /* '<S4>/SPERTE_measurement_function' */
  FILE* eml_openfiles[20];             /* '<S4>/SPERTE_measurement_function' */
} DW_Model_feedforward_T;

/* Parameters (default storage) */
struct P_Model_feedforward_T_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real_T ref_part[18];                 /* Variable: ref_part
                                        * Referenced by: '<S6>/S-Function'
                                        */
  real_T Refpower_stat;                /* Mask Parameter: Refpower_stat
                                        * Referenced by: '<S5>/Start setpoint'
                                        */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S4>/SPERTE_measurement_samples'
                                    */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S4>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S4>/SPERTE_measurement_function'
                                  */
  real_T Gain1_Gain[3];                /* Expression: [-0.00038 -0.005 -0.00002]
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Quantizer1_Interval;          /* Expression: (2*pi)/(500*4)
                                        * Referenced by: '<Root>/Quantizer1'
                                        */
  real_T SFunction_P1_Size_k[2];      /* Computed Parameter: SFunction_P1_Size_k
                                       * Referenced by: '<S9>/S-Function'
                                       */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S9>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S9>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S9>/S-Function'
                                        */
  real_T ec_Ebox_P1_Size[2];           /* Computed Parameter: ec_Ebox_P1_Size
                                        * Referenced by: '<S8>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1;                   /* Expression: link_id
                                        * Referenced by: '<S8>/ec_Ebox'
                                        */
  real_T count2rad_Gain;               /* Expression: (2*pi)/(4*500)
                                        * Referenced by: '<S3>/count2rad'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1.2
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Dctpd2_P1_Size[2];            /* Computed Parameter: Dctpd2_P1_Size
                                        * Referenced by: '<S7>/Dctpd2'
                                        */
  real_T Dctpd2_P1;                    /* Expression: kp
                                        * Referenced by: '<S7>/Dctpd2'
                                        */
  real_T Dctpd2_P2_Size[2];            /* Computed Parameter: Dctpd2_P2_Size
                                        * Referenced by: '<S7>/Dctpd2'
                                        */
  real_T Dctpd2_P2;                    /* Expression: kv
                                        * Referenced by: '<S7>/Dctpd2'
                                        */
  real_T Dctpd2_P3_Size[2];            /* Computed Parameter: Dctpd2_P3_Size
                                        * Referenced by: '<S7>/Dctpd2'
                                        */
  real_T Dctpd2_P3;                    /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctpd2'
                                        */
  real_T Dct2lowpass3_P1_Size[2];    /* Computed Parameter: Dct2lowpass3_P1_Size
                                      * Referenced by: '<S7>/Dct2lowpass3'
                                      */
  real_T Dct2lowpass3_P1;              /* Expression: f_den
                                        * Referenced by: '<S7>/Dct2lowpass3'
                                        */
  real_T Dct2lowpass3_P2_Size[2];    /* Computed Parameter: Dct2lowpass3_P2_Size
                                      * Referenced by: '<S7>/Dct2lowpass3'
                                      */
  real_T Dct2lowpass3_P2;              /* Expression: b_den
                                        * Referenced by: '<S7>/Dct2lowpass3'
                                        */
  real_T Dct2lowpass3_P3_Size[2];    /* Computed Parameter: Dct2lowpass3_P3_Size
                                      * Referenced by: '<S7>/Dct2lowpass3'
                                      */
  real_T Dct2lowpass3_P3;              /* Expression: 0.001
                                        * Referenced by: '<S7>/Dct2lowpass3'
                                        */
  real_T Dctleadlag4_P1_Size[2];      /* Computed Parameter: Dctleadlag4_P1_Size
                                       * Referenced by: '<S7>/Dctleadlag4'
                                       */
  real_T Dctleadlag4_P1;               /* Expression: f_num
                                        * Referenced by: '<S7>/Dctleadlag4'
                                        */
  real_T Dctleadlag4_P2_Size[2];      /* Computed Parameter: Dctleadlag4_P2_Size
                                       * Referenced by: '<S7>/Dctleadlag4'
                                       */
  real_T Dctleadlag4_P2;               /* Expression: f_den
                                        * Referenced by: '<S7>/Dctleadlag4'
                                        */
  real_T Dctleadlag4_P3_Size[2];      /* Computed Parameter: Dctleadlag4_P3_Size
                                       * Referenced by: '<S7>/Dctleadlag4'
                                       */
  real_T Dctleadlag4_P3;               /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctleadlag4'
                                        */
  real_T Dctnotch5_P1_Size[2];         /* Computed Parameter: Dctnotch5_P1_Size
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P1;                 /* Expression: f_num
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P2_Size[2];         /* Computed Parameter: Dctnotch5_P2_Size
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P2;                 /* Expression: b_num
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P3_Size[2];         /* Computed Parameter: Dctnotch5_P3_Size
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P3;                 /* Expression: f_den
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P4_Size[2];         /* Computed Parameter: Dctnotch5_P4_Size
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P4;                 /* Expression: b_den
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P5_Size[2];         /* Computed Parameter: Dctnotch5_P5_Size
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Dctnotch5_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S7>/Dctnotch5'
                                        */
  real_T Noise_Mean;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_StdDev;                 /* Computed Parameter: Noise_StdDev
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_Seed;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Gain2_Gain[4];                /* Expression: [0.001 0.05 0.001 1]
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Constant_Value[2];            /* Expression: [0,0]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value[8];           /* Expression: [0,0,0,0,0,0,0,0]
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/100
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -2.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 10
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -10
                                        * Referenced by: '<S8>/Saturation'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T Selectencoder_CurrentSetting;
                             /* Computed Parameter: Selectencoder_CurrentSetting
                              * Referenced by: '<Root>/Select encoder'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_Model_feedforward_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[7];
    SimStruct *childSFunctionPtrs[7];
    struct _ssBlkInfo2 blkInfo2[7];
    struct _ssSFcnModelMethods2 methods2[7];
    struct _ssSFcnModelMethods3 methods3[7];
    struct _ssSFcnModelMethods4 methods4[7];
    struct _ssStatesInfo2 statesInfo2[7];
    ssPeriodicStatesInfo periodicStatesInfo[7];
    struct _ssPortInfo2 inputOutputPortInfo2[7];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Model_feedforward_T Model_feedforward_P;

/* Block signals (default storage) */
extern B_Model_feedforward_T Model_feedforward_B;

/* Block states (default storage) */
extern DW_Model_feedforward_T Model_feedforward_DW;

/* Model entry point functions */
extern void Model_feedforward_initialize(void);
extern void Model_feedforward_step(void);
extern void Model_feedforward_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Model_feedforward_T *const Model_feedforward_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Model_feedforward'
 * '<S1>'   : 'Model_feedforward/Controller (motor side)'
 * '<S2>'   : 'Model_feedforward/Feedforward 1'
 * '<S3>'   : 'Model_feedforward/Fourth Order Motion System'
 * '<S4>'   : 'Model_feedforward/Measurement Block'
 * '<S5>'   : 'Model_feedforward/Ref power'
 * '<S6>'   : 'Model_feedforward/Subsystem'
 * '<S7>'   : 'Model_feedforward/Controller (motor side)/ff_controller_1'
 * '<S8>'   : 'Model_feedforward/Fourth Order Motion System/Ethercat E-box'
 * '<S9>'   : 'Model_feedforward/Fourth Order Motion System/Ethercat Supervisor'
 * '<S10>'  : 'Model_feedforward/Measurement Block/SPERTE_measurement_function'
 */
#endif                                 /* RTW_HEADER_Model_feedforward_h_ */
