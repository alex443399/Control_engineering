/*
 * Model_feedforward.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Model_feedforward".
 *
 * Model version              : 9.12
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Mar 17 16:18:40 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Model_feedforward.h"
#include "Model_feedforward_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "Model_feedforward_private.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "Model_feedforward_dt.h"

/* Block signals (default storage) */
B_Model_feedforward_T Model_feedforward_B;

/* Block states (default storage) */
DW_Model_feedforward_T Model_feedforward_DW;

/* Real-time model */
static RT_MODEL_Model_feedforward_T Model_feedforward_M_;
RT_MODEL_Model_feedforward_T *const Model_feedforward_M = &Model_feedforward_M_;

/* Forward declaration for local functions */
static void Model_feedforwar_emxInit_char_T(emxArray_char_T_Model_feedfor_T
  **pEmxArray, int32_T numDimensions);
static void Model__emxEnsureCapacity_char_T(emxArray_char_T_Model_feedfor_T
  *emxArray, int32_T oldNumel);
static void Model_feedforwar_emxFree_char_T(emxArray_char_T_Model_feedfor_T
  **pEmxArray);
static int8_T Model_feedforward_filedata(void);
static int8_T Model_feedforward_cfopen(const emxArray_char_T_Model_feedfor_T
  *cfilename, const char_T *cpermission);
static int32_T Model_feedforward_cfclose(real_T fid);
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void Model_feedforwar_emxInit_char_T(emxArray_char_T_Model_feedfor_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Model_feedfor_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Model_feedfor_T *)malloc(sizeof
    (emxArray_char_T_Model_feedfor_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Model__emxEnsureCapacity_char_T(emxArray_char_T_Model_feedfor_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void Model_feedforwar_emxFree_char_T(emxArray_char_T_Model_feedfor_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Model_feedfor_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Model_feedfor_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int8_T Model_feedforward_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Model_feedforward_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int8_T Model_feedforward_cfopen(const emxArray_char_T_Model_feedfor_T
  *cfilename, const char_T *cpermission)
{
  emxArray_char_T_Model_feedfor_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Model_feedforward_filedata();
  if (j >= 1) {
    Model_feedforwar_emxInit_char_T(&ccfilename, 2);
    loop_ub = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    Model__emxEnsureCapacity_char_T(ccfilename, loop_ub);
    loop_ub = cfilename->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename->data[0], &cfilename->data[0], (uint32_T)loop_ub *
             sizeof(char_T));
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    Model_feedforward_B.filestar_m = fopen(&ccfilename->data[0], cpermission);
    Model_feedforwar_emxFree_char_T(&ccfilename);
    if (Model_feedforward_B.filestar_m != NULL) {
      Model_feedforward_DW.eml_openfiles[j - 1] = Model_feedforward_B.filestar_m;
      Model_feedforward_DW.eml_autoflush[j - 1] = true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S4>/SPERTE_measurement_function' */
static int32_T Model_feedforward_cfclose(real_T fid)
{
  FILE* filestar;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
  st = -1;
  fileid = (int8_T)fid;
  if (((int8_T)fid < 0) || (fid != (int8_T)fid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    filestar = Model_feedforward_DW.eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    filestar = stdin;
  } else if (b_fileid == 1) {
    filestar = stdout;
  } else if (b_fileid == 2) {
    filestar = stderr;
  } else {
    filestar = NULL;
  }

  if ((filestar != NULL) && (fileid >= 3)) {
    cst = fclose(filestar);
    if (cst == 0) {
      st = 0;
      Model_feedforward_DW.eml_openfiles[fileid - 3] = NULL;
      Model_feedforward_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

/* Model step function */
void Model_feedforward_step(void)
{
  emxArray_char_T_Model_feedfor_T *str;
  emxArray_char_T_Model_feedfor_T *str_0;
  int32_T i;
  int32_T tmp;
  uint32_T qY;
  int8_T b_fileid;
  boolean_T autoflush;

  /* Constant: '<S5>/Start setpoint' */
  Model_feedforward_B.Startsetpoint = Model_feedforward_P.Refpower_stat;

  /* S-Function (ref3b): '<S6>/S-Function' */

  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Signum: '<S2>/Sign' */
  if (rtIsNaN(Model_feedforward_B.SFunction[1])) {
    Model_feedforward_B.Sign = (rtNaN);
  } else if (Model_feedforward_B.SFunction[1] < 0.0) {
    Model_feedforward_B.Sign = -1.0;
  } else {
    Model_feedforward_B.Sign = (Model_feedforward_B.SFunction[1] > 0.0);
  }

  /* End of Signum: '<S2>/Sign' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Gain: '<S2>/Gain1'
   *  SignalConversion generated from: '<S2>/Gain1'
   */
  if (Model_feedforward_P.ManualSwitch_CurrentSetting == 1) {
    Model_feedforward_B.Add = (Model_feedforward_P.Gain1_Gain[0] *
      Model_feedforward_B.SFunction[0] + Model_feedforward_P.Gain1_Gain[1] *
      Model_feedforward_B.Sign) + Model_feedforward_B.SFunction[1] *
      Model_feedforward_P.Gain1_Gain[2];
  } else {
    Model_feedforward_B.Add = 0.0;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* S-Function (ec_Supervisor): '<S9>/S-Function' */

  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S8>/ec_Ebox' */

  /* Level2 S-Function Block: '<S8>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* ManualSwitch: '<Root>/Select encoder' incorporates:
   *  Gain: '<S3>/count2rad'
   */
  if (Model_feedforward_P.Selectencoder_CurrentSetting == 1) {
    Model_feedforward_B.e = Model_feedforward_P.count2rad_Gain *
      Model_feedforward_B.ec_Ebox_o2[0];
  } else {
    Model_feedforward_B.e = Model_feedforward_P.count2rad_Gain *
      Model_feedforward_B.ec_Ebox_o2[1];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  ManualSwitch: '<Root>/Select encoder'
   *  Quantizer: '<Root>/Quantizer1'
   */
  Model_feedforward_B.e = rt_roundd_snf(Model_feedforward_B.SFunction[2] /
    Model_feedforward_P.Quantizer1_Interval) *
    Model_feedforward_P.Quantizer1_Interval - Model_feedforward_B.e;

  /* Gain: '<S7>/Gain1' */
  Model_feedforward_B.Gain1 = Model_feedforward_P.Gain1_Gain_l *
    Model_feedforward_B.e;

  /* S-Function (dpd): '<S7>/Dctpd2' */

  /* Level2 S-Function Block: '<S7>/Dctpd2' (dpd) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S7>/Dct2lowpass3' */

  /* Level2 S-Function Block: '<S7>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dleadlag): '<S7>/Dctleadlag4' */

  /* Level2 S-Function Block: '<S7>/Dctleadlag4' (dleadlag) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S7>/Dctnotch5' */

  /* Level2 S-Function Block: '<S7>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* RandomNumber: '<Root>/Noise' */
  Model_feedforward_B.Noise = Model_feedforward_DW.NextOutput;

  /* Gain: '<S2>/Gain2' */
  Model_feedforward_B.Gain2[0] = Model_feedforward_P.Gain2_Gain[0] *
    Model_feedforward_B.SFunction[0];
  Model_feedforward_B.Gain2[1] = Model_feedforward_P.Gain2_Gain[1] *
    Model_feedforward_B.Sign;
  Model_feedforward_B.Gain2[2] = Model_feedforward_B.SFunction[1] *
    Model_feedforward_P.Gain2_Gain[2];
  Model_feedforward_B.Gain2[3] = Model_feedforward_P.Gain2_Gain[3] *
    Model_feedforward_B.e;

  /* Constant: '<S3>/Constant1' */
  memcpy(&Model_feedforward_B.Constant1[0],
         &Model_feedforward_P.Constant1_Value[0], sizeof(real_T) << 3U);

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Model_feedforward_B.Gain[0] = Model_feedforward_P.Gain_Gain *
    Model_feedforward_P.Constant_Value[0];
  Model_feedforward_B.Gain[1] = Model_feedforward_P.Gain_Gain *
    Model_feedforward_P.Constant_Value[1];

  /* Sum: '<Root>/Add' */
  Model_feedforward_B.Sign = (Model_feedforward_B.Add +
    Model_feedforward_B.Dctnotch5) + Model_feedforward_B.Noise;

  /* Saturate: '<S3>/Saturation' */
  if (Model_feedforward_B.Sign > Model_feedforward_P.Saturation_UpperSat) {
    Model_feedforward_B.Sign = Model_feedforward_P.Saturation_UpperSat;
  } else if (Model_feedforward_B.Sign < Model_feedforward_P.Saturation_LowerSat)
  {
    Model_feedforward_B.Sign = Model_feedforward_P.Saturation_LowerSat;
  }

  /* Saturate: '<S8>/Saturation' */
  if (Model_feedforward_B.Sign > Model_feedforward_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    Model_feedforward_B.Saturation[0] =
      Model_feedforward_P.Saturation_UpperSat_d;
  } else if (Model_feedforward_B.Sign <
             Model_feedforward_P.Saturation_LowerSat_e) {
    /* Saturate: '<S8>/Saturation' */
    Model_feedforward_B.Saturation[0] =
      Model_feedforward_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S8>/Saturation' */
    Model_feedforward_B.Saturation[0] = Model_feedforward_B.Sign;
  }

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  if (Model_feedforward_P.Constant2_Value >
      Model_feedforward_P.Saturation_UpperSat) {
    Model_feedforward_B.Sign = Model_feedforward_P.Saturation_UpperSat;
  } else if (Model_feedforward_P.Constant2_Value <
             Model_feedforward_P.Saturation_LowerSat) {
    Model_feedforward_B.Sign = Model_feedforward_P.Saturation_LowerSat;
  } else {
    Model_feedforward_B.Sign = Model_feedforward_P.Constant2_Value;
  }

  /* Saturate: '<S8>/Saturation' */
  if (Model_feedforward_B.Sign > Model_feedforward_P.Saturation_UpperSat_d) {
    /* Saturate: '<S8>/Saturation' */
    Model_feedforward_B.Saturation[1] =
      Model_feedforward_P.Saturation_UpperSat_d;
  } else if (Model_feedforward_B.Sign <
             Model_feedforward_P.Saturation_LowerSat_e) {
    /* Saturate: '<S8>/Saturation' */
    Model_feedforward_B.Saturation[1] =
      Model_feedforward_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S8>/Saturation' */
    Model_feedforward_B.Saturation[1] = Model_feedforward_B.Sign;
  }

  /* MATLAB Function: '<S4>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S4>/SPERTE_measurement_samples'
   *  Constant: '<S4>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S10>/ SFunction '
   */
  if ((((Model_feedforward_P.MeasurementBlock_triggertype == 1) &&
        (Model_feedforward_P.MeasurementBlock_trigger_comman == 1)) ||
       ((Model_feedforward_P.MeasurementBlock_triggertype == 2) &&
        (Model_feedforward_P.MeasurementBlock_trigger_comman == 1))) &&
      (Model_feedforward_DW.busy != 1)) {
    i = (int32_T)snprintf(NULL, 0, "measurement_%d.bin", Model_feedforward_DW.NF)
      + 1;
    Model_feedforwar_emxInit_char_T(&str, 2);
    tmp = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = i;
    Model__emxEnsureCapacity_char_T(str, tmp);
    snprintf(&str->data[0], (size_t)i, "measurement_%d.bin",
             Model_feedforward_DW.NF);
    if (i - 1 < 1) {
      i = -1;
    } else {
      i -= 2;
    }

    Model_feedforwar_emxInit_char_T(&str_0, 2);
    tmp = str_0->size[0] * str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = i + 1;
    Model__emxEnsureCapacity_char_T(str_0, tmp);
    if (i >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)(i + 1) * sizeof(char_T));
    }

    Model_feedforwar_emxFree_char_T(&str);
    b_fileid = Model_feedforward_cfopen(str_0, "wb");
    Model_feedforwar_emxFree_char_T(&str_0);
    Model_feedforward_DW.fileID = b_fileid;
    i = Model_feedforward_DW.NF + 1;
    if (Model_feedforward_DW.NF + 1 > 32767) {
      i = 32767;
    }

    Model_feedforward_DW.NF = (int16_T)i;
    Model_feedforward_DW.busy = 1U;
    Model_feedforward_DW.NS = 0U;
  }

  if (Model_feedforward_DW.busy == 1) {
    if (Model_feedforward_DW.NS < Model_feedforward_P.MeasurementBlock_N_samples)
    {
      b_fileid = (int8_T)Model_feedforward_DW.fileID;
      if (((int8_T)Model_feedforward_DW.fileID < 0) ||
          (Model_feedforward_DW.fileID != (int8_T)Model_feedforward_DW.fileID))
      {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        Model_feedforward_B.filestar =
          Model_feedforward_DW.eml_openfiles[b_fileid - 3];
        autoflush = Model_feedforward_DW.eml_autoflush[b_fileid - 3];
      } else if (b_fileid == 0) {
        Model_feedforward_B.filestar = stdin;
        autoflush = true;
      } else if (b_fileid == 1) {
        Model_feedforward_B.filestar = stdout;
        autoflush = true;
      } else if (b_fileid == 2) {
        Model_feedforward_B.filestar = stderr;
        autoflush = true;
      } else {
        Model_feedforward_B.filestar = NULL;
        autoflush = true;
      }

      if (!(Model_feedforward_DW.fileID != 0.0)) {
        Model_feedforward_B.filestar = NULL;
      }

      if (!(Model_feedforward_B.filestar == NULL)) {
        Model_feedforward_B.xout[0] = (real32_T)Model_feedforward_B.e;
        Model_feedforward_B.xout[1] = (real32_T)Model_feedforward_B.SFunction[0];
        Model_feedforward_B.xout[2] = (real32_T)Model_feedforward_B.SFunction[1];
        Model_feedforward_B.bytesOutSizet = fwrite(&Model_feedforward_B.xout[0],
          sizeof(real32_T), (size_t)3, Model_feedforward_B.filestar);
        if (((real_T)Model_feedforward_B.bytesOutSizet > 0.0) && autoflush) {
          fflush(Model_feedforward_B.filestar);
        }
      }

      qY = Model_feedforward_DW.NS + 1U;
      if (Model_feedforward_DW.NS + 1U < Model_feedforward_DW.NS) {
        qY = MAX_uint32_T;
      }

      Model_feedforward_DW.NS = qY;
    } else {
      Model_feedforward_cfclose(Model_feedforward_DW.fileID);
      Model_feedforward_DW.busy = 0U;
      Model_feedforward_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S4>/SPERTE_measurement_function' */

  /* Update for RandomNumber: '<Root>/Noise' */
  Model_feedforward_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&Model_feedforward_DW.RandSeed) * Model_feedforward_P.Noise_StdDev +
    Model_feedforward_P.Noise_Mean;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)Model_feedforward_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.00025s, 0.0s] */
    rtExtModeUpload(1, (real_T)Model_feedforward_M->Timing.t[1]);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Model_feedforward_M)!=-1) &&
        !((rtmGetTFinal(Model_feedforward_M)-Model_feedforward_M->Timing.t[0]) >
          Model_feedforward_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Model_feedforward_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Model_feedforward_M)) {
      rtmSetErrorStatus(Model_feedforward_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Model_feedforward_M->Timing.clockTick0)) {
    ++Model_feedforward_M->Timing.clockTickH0;
  }

  Model_feedforward_M->Timing.t[0] = Model_feedforward_M->Timing.clockTick0 *
    Model_feedforward_M->Timing.stepSize0 +
    Model_feedforward_M->Timing.clockTickH0 *
    Model_feedforward_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.00025s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Model_feedforward_M->Timing.clockTick1)) {
      ++Model_feedforward_M->Timing.clockTickH1;
    }

    Model_feedforward_M->Timing.t[1] = Model_feedforward_M->Timing.clockTick1 *
      Model_feedforward_M->Timing.stepSize1 +
      Model_feedforward_M->Timing.clockTickH1 *
      Model_feedforward_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Model_feedforward_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Model_feedforward_M, 0,
                sizeof(RT_MODEL_Model_feedforward_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Model_feedforward_M->solverInfo,
                          &Model_feedforward_M->Timing.simTimeStep);
    rtsiSetTPtr(&Model_feedforward_M->solverInfo, &rtmGetTPtr
                (Model_feedforward_M));
    rtsiSetStepSizePtr(&Model_feedforward_M->solverInfo,
                       &Model_feedforward_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Model_feedforward_M->solverInfo, (&rtmGetErrorStatus
      (Model_feedforward_M)));
    rtsiSetRTModelPtr(&Model_feedforward_M->solverInfo, Model_feedforward_M);
  }

  rtsiSetSimTimeStep(&Model_feedforward_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Model_feedforward_M->solverInfo,"FixedStepDiscrete");
  Model_feedforward_M->solverInfoPtr = (&Model_feedforward_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Model_feedforward_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Model_feedforward_M points to
       static memory which is guaranteed to be non-NULL" */
    Model_feedforward_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Model_feedforward_M->Timing.sampleTimes =
      (&Model_feedforward_M->Timing.sampleTimesArray[0]);
    Model_feedforward_M->Timing.offsetTimes =
      (&Model_feedforward_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Model_feedforward_M->Timing.sampleTimes[0] = (0.0);
    Model_feedforward_M->Timing.sampleTimes[1] = (0.00025);

    /* task offsets */
    Model_feedforward_M->Timing.offsetTimes[0] = (0.0);
    Model_feedforward_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Model_feedforward_M, &Model_feedforward_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Model_feedforward_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Model_feedforward_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Model_feedforward_M, -1);
  Model_feedforward_M->Timing.stepSize0 = 0.00025;
  Model_feedforward_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  Model_feedforward_M->Sizes.checksums[0] = (149769691U);
  Model_feedforward_M->Sizes.checksums[1] = (254669655U);
  Model_feedforward_M->Sizes.checksums[2] = (4168494185U);
  Model_feedforward_M->Sizes.checksums[3] = (737528693U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Model_feedforward_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Model_feedforward_M->extModeInfo,
      &Model_feedforward_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Model_feedforward_M->extModeInfo,
                        Model_feedforward_M->Sizes.checksums);
    rteiSetTPtr(Model_feedforward_M->extModeInfo, rtmGetTPtr(Model_feedforward_M));
  }

  Model_feedforward_M->solverInfoPtr = (&Model_feedforward_M->solverInfo);
  Model_feedforward_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&Model_feedforward_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&Model_feedforward_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &Model_feedforward_B), 0,
                sizeof(B_Model_feedforward_T));

  /* states (dwork) */
  (void) memset((void *)&Model_feedforward_DW, 0,
                sizeof(DW_Model_feedforward_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Model_feedforward_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 24;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Model_feedforward_M->NonInlinedSFcns.sfcnInfo;
    Model_feedforward_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Model_feedforward_M)));
    Model_feedforward_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Model_feedforward_M->Sizes.numSampTimes);
    Model_feedforward_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Model_feedforward_M)[0]);
    Model_feedforward_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Model_feedforward_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Model_feedforward_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Model_feedforward_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Model_feedforward_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Model_feedforward_M));
    rtssSetStepSizePtr(sfcnInfo, &Model_feedforward_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Model_feedforward_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Model_feedforward_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Model_feedforward_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Model_feedforward_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Model_feedforward_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Model_feedforward_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Model_feedforward_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Model_feedforward_M->solverInfoPtr);
  }

  Model_feedforward_M->Sizes.numSFcns = (7);

  /* register each child */
  {
    (void) memset((void *)&Model_feedforward_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  7*sizeof(SimStruct));
    Model_feedforward_M->childSfunctions =
      (&Model_feedforward_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 7; i++) {
        Model_feedforward_M->childSfunctions[i] =
          (&Model_feedforward_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Model_feedforward/<S6>/S-Function (ref3b) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &Model_feedforward_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Model_feedforward_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "Model_feedforward/Subsystem/S-Function");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Model_feedforward_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Model_feedforward_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Model_feedforward_DW.SFunction_RWORK[0]);
      }

      /* registration */
      ref3b(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Model_feedforward/<S9>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Model_feedforward_B.SFunction_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Model_feedforward/Fourth Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Model_feedforward_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)Model_feedforward_P.SFunction_P2_Size);
      }

      /* registration */
      ec_Supervisor(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Model_feedforward/<S8>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Model_feedforward_B.Saturation;
          sfcnUPtrs[1] = &Model_feedforward_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = Model_feedforward_B.Gain;
          sfcnUPtrs[1] = &Model_feedforward_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn2.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = Model_feedforward_B.Constant1;
            for (i1=0; i1 < 8; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Model_feedforward_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            Model_feedforward_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            Model_feedforward_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "Model_feedforward/Fourth Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Model_feedforward_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: Model_feedforward/<S7>/Dctpd2 (dpd) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Model_feedforward_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Model_feedforward_B.Dctpd2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd2");
      ssSetPath(rts,
                "Model_feedforward/Controller (motor side)/ff_controller_1/Dctpd2");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Model_feedforward_P.Dctpd2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Model_feedforward_P.Dctpd2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Model_feedforward_P.Dctpd2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Model_feedforward_DW.Dctpd2_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Model_feedforward_DW.Dctpd2_RWORK[0]);
      }

      /* registration */
      dpd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Model_feedforward/<S7>/Dct2lowpass3 (dlowpass2) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &Model_feedforward_B.Dctpd2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Model_feedforward_B.Dct2lowpass3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass3");
      ssSetPath(rts,
                "Model_feedforward/Controller (motor side)/ff_controller_1/Dct2lowpass3");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Model_feedforward_P.Dct2lowpass3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Model_feedforward_P.Dct2lowpass3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Model_feedforward_P.Dct2lowpass3_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Model_feedforward_DW.Dct2lowpass3_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Model_feedforward_DW.Dct2lowpass3_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Model_feedforward/<S7>/Dctleadlag4 (dleadlag) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &Model_feedforward_B.Dct2lowpass3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Model_feedforward_B.Dctleadlag4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag4");
      ssSetPath(rts,
                "Model_feedforward/Controller (motor side)/ff_controller_1/Dctleadlag4");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Model_feedforward_P.Dctleadlag4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Model_feedforward_P.Dctleadlag4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Model_feedforward_P.Dctleadlag4_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Model_feedforward_DW.Dctleadlag4_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Model_feedforward_DW.Dctleadlag4_RWORK[0]);
      }

      /* registration */
      dleadlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Model_feedforward/<S7>/Dctnotch5 (dnotch) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Model_feedforward_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Model_feedforward_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Model_feedforward_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Model_feedforward_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Model_feedforward_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Model_feedforward_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Model_feedforward_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Model_feedforward_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Model_feedforward_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Model_feedforward_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &Model_feedforward_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Model_feedforward_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &Model_feedforward_B.Dctleadlag4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Model_feedforward_B.Dctnotch5));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch5");
      ssSetPath(rts,
                "Model_feedforward/Controller (motor side)/ff_controller_1/Dctnotch5");
      ssSetRTModel(rts,Model_feedforward_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Model_feedforward_P.Dctnotch5_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Model_feedforward_P.Dctnotch5_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Model_feedforward_P.Dctnotch5_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Model_feedforward_P.Dctnotch5_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Model_feedforward_P.Dctnotch5_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Model_feedforward_DW.Dctnotch5_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Model_feedforward_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Model_feedforward_DW.Dctnotch5_RWORK[0]);
      }

      /* registration */
      dnotch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for Constant: '<S5>/Start setpoint' */
  Model_feedforward_B.Startsetpoint = Model_feedforward_P.Refpower_stat;

  /* Start for S-Function (ec_Supervisor): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dpd): '<S7>/Dctpd2' */
  /* Level2 S-Function Block: '<S7>/Dctpd2' (dpd) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S7>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S7>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S7>/Dctleadlag4' */
  /* Level2 S-Function Block: '<S7>/Dctleadlag4' (dleadlag) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S7>/Dctnotch5' */
  /* Level2 S-Function Block: '<S7>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Constant1' */
  memcpy(&Model_feedforward_B.Constant1[0],
         &Model_feedforward_P.Constant1_Value[0], sizeof(real_T) << 3U);

  {
    FILE* a;
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for S-Function (ref3b): '<S6>/S-Function' */
    /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
    {
      SimStruct *rts = Model_feedforward_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for RandomNumber: '<Root>/Noise' */
    tmp = floor(Model_feedforward_P.Noise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    Model_feedforward_DW.RandSeed = ((((tseed - ((uint32_T)i << 16U)) +
      (uint32_T)t) << 16U) + (uint32_T)t) + (uint32_T)i;
    if (Model_feedforward_DW.RandSeed < 1U) {
      Model_feedforward_DW.RandSeed = 1144108930U;
    } else if (Model_feedforward_DW.RandSeed > 2147483646U) {
      Model_feedforward_DW.RandSeed = 2147483646U;
    }

    Model_feedforward_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Model_feedforward_DW.RandSeed) * Model_feedforward_P.Noise_StdDev +
      Model_feedforward_P.Noise_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Noise' */

    /* SystemInitialize for MATLAB Function: '<S4>/SPERTE_measurement_function' */
    a = NULL;
    for (i = 0; i < 20; i++) {
      Model_feedforward_DW.eml_autoflush[i] = false;
      Model_feedforward_DW.eml_openfiles[i] = a;
    }

    Model_feedforward_DW.NF = 0;
    Model_feedforward_DW.NS = 0U;
    Model_feedforward_DW.fileID = 0.0;
    Model_feedforward_DW.busy = 0U;

    /* End of SystemInitialize for MATLAB Function: '<S4>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void Model_feedforward_terminate(void)
{
  /* Terminate for S-Function (ref3b): '<S6>/S-Function' */
  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Supervisor): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S8>/ec_Ebox' */
  /* Level2 S-Function Block: '<S8>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S7>/Dctpd2' */
  /* Level2 S-Function Block: '<S7>/Dctpd2' (dpd) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S7>/Dct2lowpass3' */
  /* Level2 S-Function Block: '<S7>/Dct2lowpass3' (dlowpass2) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S7>/Dctleadlag4' */
  /* Level2 S-Function Block: '<S7>/Dctleadlag4' (dleadlag) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S7>/Dctnotch5' */
  /* Level2 S-Function Block: '<S7>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts = Model_feedforward_M->childSfunctions[6];
    sfcnTerminate(rts);
  }
}
