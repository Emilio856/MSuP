/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MSupGesamt.h
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

#ifndef RTW_HEADER_MSupGesamt_h_
#define RTW_HEADER_MSupGesamt_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MSupGesamt_COMMON_INCLUDES_
# define MSupGesamt_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Gpio.h"
#include "DSP2833x_Examples.h"
#include "IQmathLib.h"
#endif                                 /* MSupGesamt_COMMON_INCLUDES_ */

#include "MSupGesamt_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_zcfcn.h"
#include "mw_C28x_addsub_s32.h"
#include "mw_C28x_s16.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void config_ePWM_GPIO (void);
extern void init_I2C_GPIO(void);
extern void init_I2C_A(void);

/* user code (top of header file) */
#include "i2c_reset.h"

/* Block signals (default storage) */
typedef struct {
  real_T Farbsensor;                   /* '<Root>/Farbsensor' */
  real_T DIR;                          /* '<S5>/Chart' */
  real_T DIR_d;                        /* '<S4>/Weichen Steuerung' */
  real_T PWM_Out;                      /* '<S4>/Sensoren' */
  real_T richtung;                     /* '<S4>/Sensoren' */
  real_T farbenStatus;                 /* '<S4>/Sensoren' */
  real_T finish;                       /* '<S3>/Strecken Koordinaten' */
  real_T uebergabe;                    /* '<S3>/Strecken Koordinaten' */
  real_T PWM_1_L;                      /* '<S3>/Fahrt Modi' */
  real_T PWM_2_R;                      /* '<S3>/Fahrt Modi' */
  real_T Switch5;                      /* '<Root>/Switch5' */
  real32_T TmpRTBAtChartInport2;
  real32_T TmpRTBAtChartInport3;
  real32_T TmpRTBAtSensorenInport1;
  real32_T TmpRTBAtSwitch1Inport2;     /* '<Root>/Chart' */
  real32_T TmpRTBAtSwitch3Inport2;     /* '<Root>/Chart' */
  real32_T Lichtsensor;                /* '<Root>/Lichtsensor' */
  real32_T TasterOben;                 /* '<Root>/Taster Oben' */
  real32_T TasterUnten;                /* '<Root>/Taster Unten' */
  real32_T x_soll;                     /* '<S3>/Strecken Koordinaten' */
  real32_T y_soll;                     /* '<S3>/Strecken Koordinaten' */
  real32_T rueck;                      /* '<S3>/Strecken Koordinaten' */
  real32_T int16x_bin[16];             /* '<S2>/Chart6' */
  real32_T int16a1_bin[16];            /* '<S2>/Chart4' */
  real32_T int16y_bin[16];             /* '<S2>/Chart2' */
  int32_T TmpRTBAtChartInport1;        /* '<Root>/Start Taster' */
  int32_T StartTaster;                 /* '<Root>/Start Taster' */
  uint16_T I2CReceive_o2;              /* '<S12>/I2C Receive' */
  int16_T valid_values1;               /* '<S2>/Chart8' */
  int16_T valid_values2;               /* '<S2>/Chart8' */
  int16_T valid_values3;               /* '<S2>/Chart8' */
  int16_T valid_values4;               /* '<S2>/Chart8' */
  int16_T valid_values5;               /* '<S2>/Chart8' */
  int16_T valid_values6;               /* '<S2>/Chart8' */
  uint16_T I2CReceive_o1[10];          /* '<S12>/I2C Receive' */
  uint16_T VectorConcatenate[20];      /* '<S12>/Vector Concatenate' */
  boolean_T NOT;                       /* '<Root>/NOT' */
} BlockIO_MSupGesamt;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o;         /* '<S4>/Unit Delay' */
  real32_T TmpRTBAtChartInport2_Buffer0;/* synthesized block */
  real32_T TmpRTBAtChartInport3_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSensorenInport1_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSwitch1Inport2_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSwitch3Inport2_Buffer0;/* synthesized block */
  int32_T TmpRTBAtChartInport1_Buffer0;/* synthesized block */
  int32_T clockTickCounter;            /* '<S11>/Pulse Generator' */
  int32_T zaehler;                     /* '<S2>/Chart8' */
  int32_T counter;                     /* '<S2>/Chart8' */
  int32_T x_found;                     /* '<S2>/Chart8' */
  volatile int16_T RateTransition_ActiveBufIdx;/* '<S2>/Rate Transition' */
  volatile int16_T RateTransition_semaphoreTaken;/* '<S2>/Rate Transition' */
  int16_T values_out1[20];             /* '<S2>/Chart8' */
  int16_T search;                      /* '<S2>/Chart8' */
  uint16_T temporalCounter_i1;         /* '<S5>/Chart' */
  uint16_T temporalCounter_i1_n;       /* '<S4>/Weichen Steuerung' */
  uint16_T temporalCounter_i1_o;       /* '<S4>/Sensoren' */
  uint16_T Delay_DSTATE[10];           /* '<S12>/Delay' */
  volatile uint16_T RateTransition_Buffer[40];/* '<S2>/Rate Transition' */
  uint16_T is_active_c9_MSupGesamt;    /* '<S5>/Chart' */
  uint16_T is_c9_MSupGesamt;           /* '<S5>/Chart' */
  uint16_T is_active_c8_MSupGesamt;    /* '<S4>/Weichen Steuerung' */
  uint16_T is_c8_MSupGesamt;           /* '<S4>/Weichen Steuerung' */
  uint16_T is_active_c1_MSupGesamt;    /* '<S4>/Sensoren' */
  uint16_T is_c1_MSupGesamt;           /* '<S4>/Sensoren' */
  uint16_T is_active_c6_MSupGesamt;    /* '<S3>/Strecken Koordinaten' */
  uint16_T is_c6_MSupGesamt;           /* '<S3>/Strecken Koordinaten' */
  uint16_T is_active_c2_MSupGesamt;    /* '<S3>/Fahrt Modi' */
  uint16_T is_c2_MSupGesamt;           /* '<S3>/Fahrt Modi' */
  uint16_T is_active_c17_MSupGesamt;   /* '<S2>/Chart8' */
  uint16_T is_c17_MSupGesamt;          /* '<S2>/Chart8' */
  uint16_T is_active_c16_MSupGesamt;   /* '<S2>/Chart6' */
  uint16_T is_c16_MSupGesamt;          /* '<S2>/Chart6' */
  uint16_T is_active_c14_MSupGesamt;   /* '<S2>/Chart4' */
  uint16_T is_c14_MSupGesamt;          /* '<S2>/Chart4' */
  uint16_T is_active_c13_MSupGesamt;   /* '<S2>/Chart2' */
  uint16_T is_c13_MSupGesamt;          /* '<S2>/Chart2' */
  uint16_T is_active_c11_MSupGesamt;   /* '<S2>/Chart1' */
  uint16_T is_c11_MSupGesamt;          /* '<S2>/Chart1' */
  uint16_T is_active_c3_MSupGesamt;    /* '<Root>/Chart' */
  uint16_T is_c3_MSupGesamt;           /* '<Root>/Chart' */
} D_Work_MSupGesamt;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState I2CReset_Trig_ZCE;        /* '<S11>/I2C Reset' */
  ZCSigState I2CReinitialisierung_Trig_ZCE;/* '<S11>/I2C Reinitialisierung' */
} PrevZCSigStates_MSupGesamt;

/* Parameters (default storage) */
struct Parameters_MSupGesamt_ {
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T normalGes_Value;              /* Expression: 90
                                        * Referenced by: '<S3>/normalGes '
                                        */
  real_T drehGes_Value;                /* Expression: 75
                                        * Referenced by: '<S3>/drehGes '
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S11>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 250
                                        * Referenced by: '<S11>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 1
                                        * Referenced by: '<S11>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S11>/Pulse Generator'
                                        */
  int32_T TmpRTBAtChartInport1_InitialCon;/* Computed Parameter: TmpRTBAtChartInport1_InitialCon
                                           * Referenced by: synthesized block
                                           */
  real32_T UnitDelay1_InitialCondition;/* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */
  real32_T Switch4_Threshold;          /* Computed Parameter: Switch4_Threshold
                                        * Referenced by: '<Root>/Switch4'
                                        */
  real32_T Switch5_Threshold;          /* Computed Parameter: Switch5_Threshold
                                        * Referenced by: '<Root>/Switch5'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  real32_T Switch2_Threshold;          /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real32_T TmpRTBAtChartInport2_InitialCon;/* Computed Parameter: TmpRTBAtChartInport2_InitialCon
                                            * Referenced by: synthesized block
                                            */
  real32_T TmpRTBAtChartInport3_InitialCon;/* Computed Parameter: TmpRTBAtChartInport3_InitialCon
                                            * Referenced by: synthesized block
                                            */
  real32_T Switch6_Threshold;          /* Computed Parameter: Switch6_Threshold
                                        * Referenced by: '<Root>/Switch6'
                                        */
  real32_T TmpRTBAtSensorenInport1_Initial;/* Computed Parameter: TmpRTBAtSensorenInport1_Initial
                                            * Referenced by: synthesized block
                                            */
  real32_T UnitDelay_InitialCondition_k;/* Computed Parameter: UnitDelay_InitialCondition_k
                                         * Referenced by: '<S4>/Unit Delay'
                                         */
  real32_T TmpRTBAtSwitch1Inport2_InitialC;/* Computed Parameter: TmpRTBAtSwitch1Inport2_InitialC
                                            * Referenced by: synthesized block
                                            */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real32_T TmpRTBAtSwitch3Inport2_InitialC;/* Computed Parameter: TmpRTBAtSwitch3Inport2_InitialC
                                            * Referenced by: synthesized block
                                            */
  real32_T Switch3_Threshold;          /* Computed Parameter: Switch3_Threshold
                                        * Referenced by: '<Root>/Switch3'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint16_T Delay_InitialCondition;     /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint16_T RateTransition_InitialCondition;/* Computed Parameter: RateTransition_InitialCondition
                                            * Referenced by: '<S2>/Rate Transition'
                                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_MSupGesamt {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_MSupGesamt MSupGesamt_P;

/* Block signals (default storage) */
extern BlockIO_MSupGesamt MSupGesamt_B;

/* Block states (default storage) */
extern D_Work_MSupGesamt MSupGesamt_DWork;

/* External function called from main */
extern void MSupGesamt_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void MSupGesamt_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void MSupGesamt_initialize(void);
extern void MSupGesamt_step0(void);
extern void MSupGesamt_step1(void);
extern void MSupGesamt_step2(void);
extern void MSupGesamt_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MSupGesamt *const MSupGesamt_M;

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
 * '<Root>' : 'MSupGesamt'
 * '<S1>'   : 'MSupGesamt/Chart'
 * '<S2>'   : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s'
 * '<S3>'   : 'MSupGesamt/Subsystem'
 * '<S4>'   : 'MSupGesamt/Subsystem1'
 * '<S5>'   : 'MSupGesamt/Subsystem2'
 * '<S6>'   : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/Chart1'
 * '<S7>'   : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/Chart2'
 * '<S8>'   : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/Chart4'
 * '<S9>'   : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/Chart6'
 * '<S10>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/Chart8'
 * '<S11>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)'
 * '<S12>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/Triggered Subsystem'
 * '<S13>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reinitialisierung'
 * '<S14>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reset'
 * '<S15>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reinitialisierung/I2C Reinitialisierung'
 * '<S16>'  : 'MSupGesamt/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reset/I2C Reset'
 * '<S17>'  : 'MSupGesamt/Subsystem/Fahrt Modi'
 * '<S18>'  : 'MSupGesamt/Subsystem/Richtungs Wechsel M1 '
 * '<S19>'  : 'MSupGesamt/Subsystem/Richtungs Wechsel M2'
 * '<S20>'  : 'MSupGesamt/Subsystem/Strecken Koordinaten'
 * '<S21>'  : 'MSupGesamt/Subsystem/Winkel und Distanz'
 * '<S22>'  : 'MSupGesamt/Subsystem1/Sensoren'
 * '<S23>'  : 'MSupGesamt/Subsystem1/Weichen Steuerung'
 * '<S24>'  : 'MSupGesamt/Subsystem2/Chart'
 */
#endif                                 /* RTW_HEADER_MSupGesamt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
