/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MSupGesamtFramework.h
 *
 * Code generated for Simulink model 'MSupGesamtFramework'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Dec 13 17:20:25 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MSupGesamtFramework_h_
#define RTW_HEADER_MSupGesamtFramework_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef MSupGesamtFramework_COMMON_INCLUDES_
# define MSupGesamtFramework_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#endif                                 /* MSupGesamtFramework_COMMON_INCLUDES_ */

#include "MSupGesamtFramework_types.h"

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

extern void init_I2C_GPIO(void);
extern void init_I2C_A(void);

/* user code (top of header file) */
#include "i2c_reset.h"

/* Block signals (default storage) */
typedef struct {
  real_T angekommen;                   /* '<S5>/Chart' */
  real_T farbenStatus;                 /* '<S4>/Sensoren' */
  real_T finish;                       /* '<S3>/Strecken Koordinaten' */
  real32_T x_soll;                     /* '<S3>/Strecken Koordinaten' */
  real32_T y_soll;                     /* '<S3>/Strecken Koordinaten' */
  real32_T rueck;                      /* '<S3>/Strecken Koordinaten' */
  real32_T uebergabe;                  /* '<S3>/Strecken Koordinaten' */
  real32_T int16x_bin[16];             /* '<S2>/Chart6' */
  real32_T int16a1_bin[16];            /* '<S2>/Chart4' */
  real32_T int16y_bin[16];             /* '<S2>/Chart2' */
  uint16_T I2CReceive_o2;              /* '<S12>/I2C Receive' */
  int16_T valid_values1;               /* '<S2>/Chart8' */
  int16_T valid_values2;               /* '<S2>/Chart8' */
  int16_T valid_values3;               /* '<S2>/Chart8' */
  int16_T valid_values4;               /* '<S2>/Chart8' */
  int16_T valid_values5;               /* '<S2>/Chart8' */
  int16_T valid_values6;               /* '<S2>/Chart8' */
  uint16_T I2CReceive_o1[10];          /* '<S12>/I2C Receive' */
  uint16_T VectorConcatenate[20];      /* '<S12>/Vector Concatenate' */
} BlockIO_MSupGesamtFramework;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S3>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_o;         /* '<S4>/Unit Delay' */
  int32_T clockTickCounter;            /* '<S11>/Pulse Generator' */
  int32_T zaehler;                     /* '<S2>/Chart8' */
  int32_T counter;                     /* '<S2>/Chart8' */
  int32_T x_found;                     /* '<S2>/Chart8' */
  volatile int16_T RateTransition_ActiveBufIdx;/* '<S2>/Rate Transition' */
  volatile int16_T RateTransition_semaphoreTaken;/* '<S2>/Rate Transition' */
  int16_T values_out1[20];             /* '<S2>/Chart8' */
  int16_T search;                      /* '<S2>/Chart8' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint16_T Delay_DSTATE[10];           /* '<S12>/Delay' */
  volatile uint16_T RateTransition_Buffer[40];/* '<S2>/Rate Transition' */
  uint16_T is_active_c9_MSupGesamtFramewor;/* '<S5>/Chart' */
  uint16_T is_c9_MSupGesamtFramework;  /* '<S5>/Chart' */
  uint16_T temporalCounter_i1_l;       /* '<S5>/Chart' */
  uint16_T is_active_c8_MSupGesamtFramewor;/* '<S4>/Weichen Steuerung' */
  uint16_T is_c8_MSupGesamtFramework;  /* '<S4>/Weichen Steuerung' */
  uint16_T temporalCounter_i1_n;       /* '<S4>/Weichen Steuerung' */
  uint16_T is_active_c1_MSupGesamtFramewor;/* '<S4>/Sensoren' */
  uint16_T is_c1_MSupGesamtFramework;  /* '<S4>/Sensoren' */
  uint16_T temporalCounter_i1_o;       /* '<S4>/Sensoren' */
  uint16_T is_active_c6_MSupGesamtFramewor;/* '<S3>/Strecken Koordinaten' */
  uint16_T is_c6_MSupGesamtFramework;  /* '<S3>/Strecken Koordinaten' */
  uint16_T is_active_c2_MSupGesamtFramewor;/* '<S3>/Fahrt Modi' */
  uint16_T is_c2_MSupGesamtFramework;  /* '<S3>/Fahrt Modi' */
  uint16_T is_active_c17_MSupGesamtFramewo;/* '<S2>/Chart8' */
  uint16_T is_c17_MSupGesamtFramework; /* '<S2>/Chart8' */
  uint16_T is_active_c16_MSupGesamtFramewo;/* '<S2>/Chart6' */
  uint16_T is_c16_MSupGesamtFramework; /* '<S2>/Chart6' */
  uint16_T is_active_c14_MSupGesamtFramewo;/* '<S2>/Chart4' */
  uint16_T is_c14_MSupGesamtFramework; /* '<S2>/Chart4' */
  uint16_T is_active_c13_MSupGesamtFramewo;/* '<S2>/Chart2' */
  uint16_T is_c13_MSupGesamtFramework; /* '<S2>/Chart2' */
  uint16_T is_active_c11_MSupGesamtFramewo;/* '<S2>/Chart1' */
  uint16_T is_c11_MSupGesamtFramework; /* '<S2>/Chart1' */
  uint16_T is_active_c3_MSupGesamtFramewor;/* '<Root>/Chart' */
  uint16_T is_c3_MSupGesamtFramework;  /* '<Root>/Chart' */
} D_Work_MSupGesamtFramework;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState I2CReset_Trig_ZCE;        /* '<S11>/I2C Reset' */
  ZCSigState I2CReinitialisierung_Trig_ZCE;/* '<S11>/I2C Reinitialisierung' */
} PrevZCSigStates_MSupGesamtFrame;

/* Parameters (default storage) */
struct Parameters_MSupGesamtFramework_ {
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant11'
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
  real_T normalGes_Value;              /* Expression: 80
                                        * Referenced by: '<S3>/normalGes '
                                        */
  real_T drehGes_Value;                /* Expression: 60
                                        * Referenced by: '<S3>/drehGes '
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 1600
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real32_T UnitDelay_InitialCondition_k;/* Computed Parameter: UnitDelay_InitialCondition_k
                                         * Referenced by: '<S4>/Unit Delay'
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
struct tag_RTM_MSupGesamtFramework {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_MSupGesamtFramework MSupGesamtFramework_P;

/* Block signals (default storage) */
extern BlockIO_MSupGesamtFramework MSupGesamtFramework_B;

/* Block states (default storage) */
extern D_Work_MSupGesamtFramework MSupGesamtFramework_DWork;

/* Model entry point functions */
extern void MSupGesamtFramework_initialize(void);
extern void MSupGesamtFramework_step(void);
extern void MSupGesamtFramework_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MSupGesamtFramework *const MSupGesamtFramework_M;

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
 * '<Root>' : 'MSupGesamtFramework'
 * '<S1>'   : 'MSupGesamtFramework/Chart'
 * '<S2>'   : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s'
 * '<S3>'   : 'MSupGesamtFramework/Subsystem'
 * '<S4>'   : 'MSupGesamtFramework/Subsystem1'
 * '<S5>'   : 'MSupGesamtFramework/Subsystem2'
 * '<S6>'   : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/Chart1'
 * '<S7>'   : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/Chart2'
 * '<S8>'   : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/Chart4'
 * '<S9>'   : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/Chart6'
 * '<S10>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/Chart8'
 * '<S11>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)'
 * '<S12>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/Triggered Subsystem'
 * '<S13>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reinitialisierung'
 * '<S14>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reset'
 * '<S15>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reinitialisierung/I2C Reinitialisierung'
 * '<S16>'  : 'MSupGesamtFramework/Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reset/I2C Reset'
 * '<S17>'  : 'MSupGesamtFramework/Subsystem/Fahrt Modi'
 * '<S18>'  : 'MSupGesamtFramework/Subsystem/Richtungs Wechsel M1 '
 * '<S19>'  : 'MSupGesamtFramework/Subsystem/Richtungs Wechsel M2'
 * '<S20>'  : 'MSupGesamtFramework/Subsystem/Strecken Koordinaten'
 * '<S21>'  : 'MSupGesamtFramework/Subsystem/Winkel und Distanz'
 * '<S22>'  : 'MSupGesamtFramework/Subsystem1/Sensoren'
 * '<S23>'  : 'MSupGesamtFramework/Subsystem1/Weichen Steuerung'
 * '<S24>'  : 'MSupGesamtFramework/Subsystem2/Chart'
 */
#endif                                 /* RTW_HEADER_MSupGesamtFramework_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
