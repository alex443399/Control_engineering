/*
 * Model_feedback_data.c
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

#include "Model_feedback.h"

/* Block parameters (default storage) */
P_Model_feedback_T Model_feedback_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S7>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S7>/S-Function'
   */
  { 0.0, 125.0, 0.0, 0.0, 5.8928, -1.0, 125.0, 0.0, 0.0, 22.0, 22.0, 0.0, 0.211,
    0.211, 0.0, 10000.0, 10000.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S6>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S4>/SPERTE_measurement_samples'
   */
  240000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S4>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S4>/SPERTE_measurement_function'
   */
  2U,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S10>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S10>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S10>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S10>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S9>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S9>/ec_Ebox'
   */
  0.0,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S3>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: [-0.00038 -0.005 -0.00002]
   * Referenced by: '<S2>/Gain1'
   */
  { -0.00038, -0.005, -2.0E-5 },

  /* Expression: -1.8
   * Referenced by: '<S8>/Gain1'
   */
  -1.8,

  /* Computed Parameter: Dctpd2_P1_Size
   * Referenced by: '<S8>/Dctpd2'
   */
  { 1.0, 1.0 },

  /* Expression: kp
   * Referenced by: '<S8>/Dctpd2'
   */
  0.1,

  /* Computed Parameter: Dctpd2_P2_Size
   * Referenced by: '<S8>/Dctpd2'
   */
  { 1.0, 1.0 },

  /* Expression: kv
   * Referenced by: '<S8>/Dctpd2'
   */
  0.001,

  /* Computed Parameter: Dctpd2_P3_Size
   * Referenced by: '<S8>/Dctpd2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctpd2'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass3_P1_Size
   * Referenced by: '<S8>/Dct2lowpass3'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dct2lowpass3'
   */
  200.0,

  /* Computed Parameter: Dct2lowpass3_P2_Size
   * Referenced by: '<S8>/Dct2lowpass3'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dct2lowpass3'
   */
  0.7,

  /* Computed Parameter: Dct2lowpass3_P3_Size
   * Referenced by: '<S8>/Dct2lowpass3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dct2lowpass3'
   */
  0.001,

  /* Computed Parameter: Dctnotch4_P1_Size
   * Referenced by: '<S8>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctnotch4'
   */
  60.5,

  /* Computed Parameter: Dctnotch4_P2_Size
   * Referenced by: '<S8>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctnotch4'
   */
  0.004,

  /* Computed Parameter: Dctnotch4_P3_Size
   * Referenced by: '<S8>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctnotch4'
   */
  50.0,

  /* Computed Parameter: Dctnotch4_P4_Size
   * Referenced by: '<S8>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dctnotch4'
   */
  1.0,

  /* Computed Parameter: Dctnotch4_P5_Size
   * Referenced by: '<S8>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctnotch4'
   */
  0.001,

  /* Computed Parameter: Dctleadlag5_P1_Size
   * Referenced by: '<S8>/Dctleadlag5'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctleadlag5'
   */
  1.0,

  /* Computed Parameter: Dctleadlag5_P2_Size
   * Referenced by: '<S8>/Dctleadlag5'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctleadlag5'
   */
  40.0,

  /* Computed Parameter: Dctleadlag5_P3_Size
   * Referenced by: '<S8>/Dctleadlag5'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctleadlag5'
   */
  0.001,

  /* Computed Parameter: Dctnotch6_P1_Size
   * Referenced by: '<S8>/Dctnotch6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S8>/Dctnotch6'
   */
  3.5,

  /* Computed Parameter: Dctnotch6_P2_Size
   * Referenced by: '<S8>/Dctnotch6'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S8>/Dctnotch6'
   */
  1.0,

  /* Computed Parameter: Dctnotch6_P3_Size
   * Referenced by: '<S8>/Dctnotch6'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S8>/Dctnotch6'
   */
  3.5,

  /* Computed Parameter: Dctnotch6_P4_Size
   * Referenced by: '<S8>/Dctnotch6'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S8>/Dctnotch6'
   */
  0.001,

  /* Computed Parameter: Dctnotch6_P5_Size
   * Referenced by: '<S8>/Dctnotch6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S8>/Dctnotch6'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Computed Parameter: Noise_StdDev
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: [0.001 0.05 0.001 1]
   * Referenced by: '<S2>/Gain2'
   */
  { 0.001, 0.05, 0.001, 1.0 },

  /* Expression: [0,0]
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S3>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S3>/Constant2'
   */
  0.0,

  /* Expression: 1/100
   * Referenced by: '<S9>/Gain'
   */
  0.01,

  /* Expression: 2.5
   * Referenced by: '<S3>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S3>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S9>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S9>/Saturation'
   */
  -10.0,

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
