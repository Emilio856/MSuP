/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MSupGesamt_private.h
 *
 * Code generated for Simulink model 'MSupGesamt'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jan 17 09:56:45 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MSupGesamt_private_h_
#define RTW_HEADER_MSupGesamt_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "MSupGesamt.h"

void config_ADC_A(uint16_T maxconvReg , uint16_T adcChselSEQ1Reg, uint16_T
                  adcChselSEQ2Reg, uint16_T adcChselSEQ3Reg, uint16_T
                  adcChselSEQ4Reg);
void isr_int8pie2_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int8pie2_task_fcn(void);

#endif                                 /* RTW_HEADER_MSupGesamt_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
