/*
 * Model_feedback_types.h
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

#ifndef RTW_HEADER_Model_feedback_types_h_
#define RTW_HEADER_Model_feedback_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<S4>/SPERTE_measurement_function' */
#include <stdio.h>
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_Model_feedbac_T
#define typedef_emxArray_char_T_Model_feedbac_T

typedef struct emxArray_char_T emxArray_char_T_Model_feedbac_T;

#endif                             /* typedef_emxArray_char_T_Model_feedbac_T */

/* Parameters (default storage) */
typedef struct P_Model_feedback_T_ P_Model_feedback_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Model_feedback_T RT_MODEL_Model_feedback_T;

#endif                                 /* RTW_HEADER_Model_feedback_types_h_ */
