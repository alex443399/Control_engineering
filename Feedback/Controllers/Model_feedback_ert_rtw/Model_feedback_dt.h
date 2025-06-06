/*
 * Model_feedback_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Model_feedback".
 *
 * Model version              : 9.14
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Mar 21 13:00:18 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(FILE*),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "FILE*",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Model_feedback_B.Startsetpoint), 0, 0, 46 }
  ,

  { (char_T *)(&Model_feedback_DW.Downsample_Buffer[0]), 0, 0, 71 },

  { (char_T *)(&Model_feedback_DW.Scope_PWORK.LoggedData), 11, 0, 2 },

  { (char_T *)(&Model_feedback_DW.RandSeed), 7, 0, 2 },

  { (char_T *)(&Model_feedback_DW.NF), 4, 0, 1 },

  { (char_T *)(&Model_feedback_DW.busy), 3, 0, 1 },

  { (char_T *)(&Model_feedback_DW.eml_autoflush[0]), 8, 0, 20 },

  { (char_T *)(&Model_feedback_DW.eml_openfiles[0]), 17, 0, 20 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Model_feedback_P.SFunction_P1_Size[0]), 0, 0, 21 },

  { (char_T *)(&Model_feedback_P.MeasurementBlock_N_samples), 7, 0, 1 },

  { (char_T *)(&Model_feedback_P.MeasurementBlock_trigger_comman), 3, 0, 2 },

  { (char_T *)(&Model_feedback_P.Quantizer1_Interval), 0, 0, 95 },

  { (char_T *)(&Model_feedback_P.Selectencoder_CurrentSetting), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] Model_feedback_dt.h */
