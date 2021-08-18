/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MSupGesamt.c
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

#include "MSupGesamt.h"
#include "MSupGesamt_private.h"
#define IN_Anfang_found_Schritt_uebertr (1U)
#define MSupGes_IN_x5_valid_data_found1 (6U)
#define MSupGesamt_IN_Anfang           (1U)
#define MSupGesamt_IN_Bunt             (1U)
#define MSupGesamt_IN_Daten_einlesen   (1U)
#define MSupGesamt_IN_Ende             (2U)
#define MSupGesamt_IN_Farbe            (2U)
#define MSupGesamt_IN_GeradeausFahren  (1U)
#define MSupGesamt_IN_LinksDrehen      (2U)
#define MSupGesamt_IN_NO_ACTIVE_CHILD  (0U)
#define MSupGesamt_IN_Position1        (1U)
#define MSupGesamt_IN_Position21       (2U)
#define MSupGesamt_IN_RechtsDrehen     (3U)
#define MSupGesamt_IN_Rueckwaerts      (4U)
#define MSupGesamt_IN_Schwarz          (3U)
#define MSupGesamt_IN_SchwarzOderBunt  (4U)
#define MSupGesamt_IN_Stehen           (5U)
#define MSupGesamt_IN_Stop             (3U)
#define MSupGesamt_IN_blau             (5U)
#define MSupGesamt_IN_blau_i           (1U)
#define MSupGesamt_IN_hochFahren       (1U)
#define MSupGesamt_IN_init             (2U)
#define MSupGesamt_IN_linksdrehen      (2U)
#define MSupGesamt_IN_oben             (2U)
#define MSupGesamt_IN_rechtsdrehen     (3U)
#define MSupGesamt_IN_rot              (6U)
#define MSupGesamt_IN_rot_i            (4U)
#define MSupGesamt_IN_runterFahren     (3U)
#define MSupGesamt_IN_unten            (4U)
#define MSupGesamt_IN_warten           (3U)
#define MSupGesamt_IN_warten3          (8U)
#define MSupGesamt_IN_warten4          (9U)
#define MSupGesamt_IN_warten_i         (7U)
#define MSupGesamt_IN_warten_iu        (5U)
#define MSupGesamt_IN_wartenkurz       (10U)
#define MSupGesamt_IN_wert_erkannt     (3U)
#define MSupGesamt_IN_wert_erkannt2    (4U)
#define MSupGesamt_IN_x0               (2U)
#define MSupGesamt_IN_x1_1             (3U)
#define MSupGesamt_IN_x1_search1       (5U)

/* user code (top of source file) */
#include "i2c_reset.c"

/* Block signals (default storage) */
BlockIO_MSupGesamt MSupGesamt_B;

/* Block states (default storage) */
D_Work_MSupGesamt MSupGesamt_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_MSupGesamt MSupGesamt_PrevZCSigState;

/* Real-time model */
RT_MODEL_MSupGesamt MSupGesamt_M_;
RT_MODEL_MSupGesamt *const MSupGesamt_M = &MSupGesamt_M_;

/* Forward declaration for local functions */
static void MSupG_enter_atomic_wert_erkannt(const uint16_T RateTransition[20]);
static void rate_monotonic_scheduler(void);
static uint16_T adcInitFlag = 0;

/* Hardware Interrupt Block: '<S2>/C28x Hardware Interrupt' */
void isr_int8pie2_task_fcn(void)
{
  /* Call the system: <S2>/Triggered Subsystem */
  {
    int16_T i;

    /* S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' */

    /* Output and update for function-call system: '<S2>/Triggered Subsystem' */
    {
      int16_T i;

      /* S-Function (c280xi2c_rx): '<S12>/I2C Receive' */
      {
        int rx_loop= 0;

        /* mode:0 (1:master 0:slave)  Addressing mode:0 (1:10-bit 0:7-bit)
           free data mode:0 (1:enbaled 0:disabled) digital loopback mode:0 (1:enabled 0:disabled)
           bit count:0 (0:8bit) NACK mode:1 (1:enabled 0: disabled) stop condition:0 (1:enabled 0: disabled)*/
        I2caRegs.I2CMDR.all = 57376;

        {
          int_T i1;
          uint8_T *y0 = &MSupGesamt_B.I2CReceive_o1[0];
          for (i1=0; i1 < 10; i1++) {
            rx_loop= 0;
            while (I2caRegs.I2CFFRX.bit.RXFFST==0 && rx_loop<10000)
              rx_loop++;
            if (rx_loop!=10000) {
              y0[i1] = I2caRegs.I2CDRR;
              MSupGesamt_B.I2CReceive_o2 = I2caRegs.I2CSTR.all;/* output i2c status */
            } else
              MSupGesamt_B.I2CReceive_o2 = I2caRegs.I2CSTR.all | 0x40;/* output receive data loss status */
          }
        }
      }

      for (i = 0; i < 10; i++) {
        /* SignalConversion: '<S12>/ConcatBufferAtVector ConcatenateIn2' */
        MSupGesamt_B.VectorConcatenate[i + 10] = MSupGesamt_B.I2CReceive_o1[i];

        /* Delay: '<S12>/Delay' */
        MSupGesamt_B.VectorConcatenate[i] = MSupGesamt_DWork.Delay_DSTATE[i];

        /* Update for Delay: '<S12>/Delay' */
        MSupGesamt_DWork.Delay_DSTATE[i] = MSupGesamt_B.I2CReceive_o1[i];
      }
    }

    /* End of Outputs for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' */

    /* RateTransition: '<S2>/Rate Transition' */
    for (i = 0; i < 20; i++) {
      MSupGesamt_DWork.RateTransition_Buffer[i +
        (MSupGesamt_DWork.RateTransition_semaphoreTaken == 0) * 20] =
        MSupGesamt_B.VectorConcatenate[i];
    }

    MSupGesamt_DWork.RateTransition_ActiveBufIdx =
      (MSupGesamt_DWork.RateTransition_semaphoreTaken == 0);

    /* End of RateTransition: '<S2>/Rate Transition' */
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void MSupGesamt_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(MSupGesamt_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(MSupGesamt_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  MSupGesamt_M->Timing.RateInteraction.TID0_1 =
    (MSupGesamt_M->Timing.TaskCounters.TID[1] == 0);
  MSupGesamt_M->Timing.RateInteraction.TID0_2 =
    (MSupGesamt_M->Timing.TaskCounters.TID[2] == 0);

  /* tid 1 shares data with slower tid rate: 2 */
  if (MSupGesamt_M->Timing.TaskCounters.TID[1] == 0) {
    MSupGesamt_M->Timing.RateInteraction.TID1_2 =
      (MSupGesamt_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MSupGesamt_M->Timing.TaskCounters.TID[1])++;
  if ((MSupGesamt_M->Timing.TaskCounters.TID[1]) > 499) {/* Sample time: [0.01s, 0.0s] */
    MSupGesamt_M->Timing.TaskCounters.TID[1] = 0;
  }

  (MSupGesamt_M->Timing.TaskCounters.TID[2])++;
  if ((MSupGesamt_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [0.1s, 0.0s] */
    MSupGesamt_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Function for Chart: '<S2>/Chart8' */
static void MSupG_enter_atomic_wert_erkannt(const uint16_T RateTransition[20])
{
  /* Entry 'wert_erkannt': '<S10>:109' */
  MSupGesamt_DWork.values_out1[0] = (int16_T)RateTransition[0];
  MSupGesamt_DWork.values_out1[1] = (int16_T)RateTransition[1];
  MSupGesamt_DWork.values_out1[2] = (int16_T)RateTransition[2];
  MSupGesamt_DWork.values_out1[3] = (int16_T)RateTransition[3];
  MSupGesamt_DWork.values_out1[4] = (int16_T)RateTransition[4];
  MSupGesamt_DWork.values_out1[5] = (int16_T)RateTransition[5];
  MSupGesamt_DWork.values_out1[6] = (int16_T)RateTransition[6];
  MSupGesamt_DWork.values_out1[7] = (int16_T)RateTransition[7];
  MSupGesamt_DWork.values_out1[8] = (int16_T)RateTransition[8];
  MSupGesamt_DWork.values_out1[9] = (int16_T)RateTransition[9];
  MSupGesamt_DWork.values_out1[10] = (int16_T)RateTransition[10];
  MSupGesamt_DWork.values_out1[11] = (int16_T)RateTransition[11];
  MSupGesamt_DWork.values_out1[12] = (int16_T)RateTransition[12];
  MSupGesamt_DWork.values_out1[13] = (int16_T)RateTransition[13];
  MSupGesamt_DWork.values_out1[14] = (int16_T)RateTransition[14];
  MSupGesamt_DWork.values_out1[15] = (int16_T)RateTransition[15];
  MSupGesamt_DWork.values_out1[16] = (int16_T)RateTransition[16];
  MSupGesamt_DWork.values_out1[17] = (int16_T)RateTransition[17];
  MSupGesamt_DWork.values_out1[18] = (int16_T)RateTransition[18];
  MSupGesamt_DWork.values_out1[19] = (int16_T)RateTransition[19];
}

/* Model step function for TID0 */
void MSupGesamt_step0(void)            /* Sample time: [2.0E-5s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Switch3;
  int16_T rtb_PWM_Out;

  {                                    /* Sample time: [2.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S4>/TmpRTBAtSensorenInport1' */
  if (MSupGesamt_M->Timing.RateInteraction.TID0_2) {
    MSupGesamt_B.TmpRTBAtSensorenInport1 =
      MSupGesamt_DWork.TmpRTBAtSensorenInport1_Buffer0;
  }

  /* End of RateTransition: '<S4>/TmpRTBAtSensorenInport1' */

  /* S-Function (c280xadc): '<Root>/Farbsensor' */
  {
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;  /* Reset SEQ1 module*/
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;/*clear INT sequencer*/
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;  /* Software Trigger*/
    while (AdcRegs.ADCST.bit.INT_SEQ1 == 0) {
    }                                  /*Wait for Sequencer INT bit to clear */

    asm(" RPT #11 || NOP");
    MSupGesamt_B.Farbsensor = (AdcRegs.ADCRESULT0) >> 4;
  }

  /* Chart: '<S4>/Sensoren' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (MSupGesamt_DWork.temporalCounter_i1_o < 32767U) {
    MSupGesamt_DWork.temporalCounter_i1_o++;
  }

  /* Gateway: Subsystem1/Sensoren */
  /* During: Subsystem1/Sensoren */
  if (MSupGesamt_DWork.is_active_c1_MSupGesamt == 0U) {
    /* Entry: Subsystem1/Sensoren */
    MSupGesamt_DWork.is_active_c1_MSupGesamt = 1U;

    /* Entry Internal: Subsystem1/Sensoren */
    /* Transition: '<S22>:4' */
    MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_warten_i;

    /* Entry 'warten': '<S22>:3' */
    MSupGesamt_B.PWM_Out = 0.0;
  } else {
    switch (MSupGesamt_DWork.is_c1_MSupGesamt) {
     case MSupGesamt_IN_Bunt:
      /* During 'Bunt': '<S22>:14' */
      if (MSupGesamt_B.TmpRTBAtSensorenInport1 == 1.0F) {
        /* Transition: '<S22>:36' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_wartenkurz;
        MSupGesamt_DWork.temporalCounter_i1_o = 0U;
      } else {
        MSupGesamt_B.PWM_Out = 80.0;
        MSupGesamt_B.richtung = 1.0;
      }
      break;

     case MSupGesamt_IN_Farbe:
      /* During 'Farbe': '<S22>:29' */
      if (MSupGesamt_B.Farbsensor > 1500.0) {
        /* Transition: '<S22>:27' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_blau;

        /* Entry 'blau': '<S22>:26' */
        MSupGesamt_B.farbenStatus = 0.0;
      } else {
        if (MSupGesamt_B.Farbsensor < 1500.0) {
          /* Transition: '<S22>:28' */
          MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_rot;

          /* Entry 'rot': '<S22>:24' */
          MSupGesamt_B.farbenStatus = 1.0;
        }
      }
      break;

     case MSupGesamt_IN_Schwarz:
      /* During 'Schwarz': '<S22>:12' */
      if (MSupGesamt_B.TmpRTBAtSensorenInport1 == 1.0F) {
        /* Transition: '<S22>:17' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_wartenkurz;
        MSupGesamt_DWork.temporalCounter_i1_o = 0U;
      } else {
        MSupGesamt_B.PWM_Out = 80.0;
        MSupGesamt_B.richtung = 0.0;
      }
      break;

     case MSupGesamt_IN_SchwarzOderBunt:
      /* During 'SchwarzOderBunt': '<S22>:19' */
      if (MSupGesamt_B.Farbsensor < 2340.0) {
        /* Transition: '<S22>:16' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_Farbe;
      } else {
        if (MSupGesamt_B.Farbsensor > 2340.0) {
          /* Transition: '<S22>:15' */
          MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_Schwarz;

          /* Entry 'Schwarz': '<S22>:12' */
          MSupGesamt_B.PWM_Out = 80.0;
          MSupGesamt_B.richtung = 0.0;
        }
      }
      break;

     case MSupGesamt_IN_blau:
      MSupGesamt_B.farbenStatus = 0.0;

      /* During 'blau': '<S22>:26' */
      /* Transition: '<S22>:30' */
      MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_warten4;
      break;

     case MSupGesamt_IN_rot:
      MSupGesamt_B.farbenStatus = 1.0;

      /* During 'rot': '<S22>:24' */
      /* Transition: '<S22>:31' */
      MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_warten4;
      break;

     case MSupGesamt_IN_warten_i:
      /* During 'warten': '<S22>:3' */
      if (MSupGesamt_B.TmpRTBAtSensorenInport1 == 0.0F) {
        /* Transition: '<S22>:20' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_warten3;
        MSupGesamt_DWork.temporalCounter_i1_o = 0U;
      }
      break;

     case MSupGesamt_IN_warten3:
      /* During 'warten3': '<S22>:42' */
      if (MSupGesamt_DWork.temporalCounter_i1_o >= 25000U) {
        /* Transition: '<S22>:43' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_SchwarzOderBunt;
      }
      break;

     case MSupGesamt_IN_warten4:
      /* During 'warten4': '<S22>:44' */
      if (MSupGesamt_DWork.UnitDelay_DSTATE_o == 0.0F) {
        /* Transition: '<S22>:45' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_Bunt;

        /* Entry 'Bunt': '<S22>:14' */
        MSupGesamt_B.PWM_Out = 80.0;
        MSupGesamt_B.richtung = 1.0;
      }
      break;

     default:
      /* During 'wartenkurz': '<S22>:22' */
      if (MSupGesamt_DWork.temporalCounter_i1_o >= 50U) {
        /* Transition: '<S22>:23' */
        MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_warten_i;

        /* Entry 'warten': '<S22>:3' */
        MSupGesamt_B.PWM_Out = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Sensoren' */

  /* RateTransition: '<Root>/TmpRTBAtSwitch1Inport2' */
  if (MSupGesamt_M->Timing.RateInteraction.TID0_1) {
    MSupGesamt_B.TmpRTBAtSwitch1Inport2 =
      MSupGesamt_DWork.TmpRTBAtSwitch1Inport2_Buffer0;
  }

  /* End of RateTransition: '<Root>/TmpRTBAtSwitch1Inport2' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (MSupGesamt_B.TmpRTBAtSwitch1Inport2 > MSupGesamt_P.Switch1_Threshold) {
    rtb_Switch3 = MSupGesamt_B.PWM_Out;
  } else {
    rtb_Switch3 = MSupGesamt_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* S-Function (c280xpwm): '<Root>/PWM Kicker' */

  /*-- Update CMPB value for ePWM5 --*/
  {
    EPwm5Regs.CMPB = (uint16_T)((uint32_T)EPwm5Regs.TBPRD * rtb_Switch3 * 0.01);
  }

  /* Chart: '<S4>/Weichen Steuerung' */
  if (MSupGesamt_DWork.temporalCounter_i1_n < 16383U) {
    MSupGesamt_DWork.temporalCounter_i1_n++;
  }

  /* Gateway: Subsystem1/Weichen Steuerung */
  /* During: Subsystem1/Weichen Steuerung */
  if (MSupGesamt_DWork.is_active_c8_MSupGesamt == 0U) {
    /* Entry: Subsystem1/Weichen Steuerung */
    MSupGesamt_DWork.is_active_c8_MSupGesamt = 1U;

    /* Entry Internal: Subsystem1/Weichen Steuerung */
    /* Transition: '<S23>:2' */
    MSupGesamt_DWork.is_c8_MSupGesamt = MSupGesamt_IN_blau_i;

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    /* Entry 'blau': '<S23>:1' */
    MSupGesamt_DWork.UnitDelay_DSTATE_o = 0.0F;
    rtb_PWM_Out = 0;
  } else {
    switch (MSupGesamt_DWork.is_c8_MSupGesamt) {
     case MSupGesamt_IN_blau_i:
      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamt_DWork.UnitDelay_DSTATE_o = 0.0F;
      rtb_PWM_Out = 0;

      /* During 'blau': '<S23>:1' */
      if (MSupGesamt_B.farbenStatus == 1.0) {
        /* Transition: '<S23>:8' */
        MSupGesamt_DWork.is_c8_MSupGesamt = MSupGesamt_IN_rechtsdrehen;
        MSupGesamt_DWork.temporalCounter_i1_n = 0U;

        /* Entry 'rechtsdrehen': '<S23>:6' */
        rtb_PWM_Out = 50;
        MSupGesamt_B.DIR_d = 1.0;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        MSupGesamt_DWork.UnitDelay_DSTATE_o = 1.0F;
      }
      break;

     case MSupGesamt_IN_linksdrehen:
      rtb_PWM_Out = 50;
      MSupGesamt_B.DIR_d = 0.0;

      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamt_DWork.UnitDelay_DSTATE_o = 1.0F;

      /* During 'linksdrehen': '<S23>:7' */
      if (MSupGesamt_DWork.temporalCounter_i1_n >= 9500U) {
        /* Transition: '<S23>:11' */
        MSupGesamt_DWork.is_c8_MSupGesamt = MSupGesamt_IN_blau_i;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        /* Entry 'blau': '<S23>:1' */
        MSupGesamt_DWork.UnitDelay_DSTATE_o = 0.0F;
        rtb_PWM_Out = 0;
      }
      break;

     case MSupGesamt_IN_rechtsdrehen:
      rtb_PWM_Out = 50;
      MSupGesamt_B.DIR_d = 1.0;

      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamt_DWork.UnitDelay_DSTATE_o = 1.0F;

      /* During 'rechtsdrehen': '<S23>:6' */
      if (MSupGesamt_DWork.temporalCounter_i1_n >= 9500U) {
        /* Transition: '<S23>:9' */
        MSupGesamt_DWork.is_c8_MSupGesamt = MSupGesamt_IN_rot_i;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        /* Entry 'rot': '<S23>:4' */
        MSupGesamt_DWork.UnitDelay_DSTATE_o = 0.0F;
        rtb_PWM_Out = 0;
      }
      break;

     default:
      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamt_DWork.UnitDelay_DSTATE_o = 0.0F;
      rtb_PWM_Out = 0;

      /* During 'rot': '<S23>:4' */
      if (MSupGesamt_B.farbenStatus == 0.0) {
        /* Transition: '<S23>:10' */
        MSupGesamt_DWork.is_c8_MSupGesamt = MSupGesamt_IN_linksdrehen;
        MSupGesamt_DWork.temporalCounter_i1_n = 0U;

        /* Entry 'linksdrehen': '<S23>:7' */
        rtb_PWM_Out = 50;
        MSupGesamt_B.DIR_d = 0.0;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        MSupGesamt_DWork.UnitDelay_DSTATE_o = 1.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Weichen Steuerung' */

  /* RateTransition: '<Root>/TmpRTBAtSwitch3Inport2' */
  if (MSupGesamt_M->Timing.RateInteraction.TID0_1) {
    MSupGesamt_B.TmpRTBAtSwitch3Inport2 =
      MSupGesamt_DWork.TmpRTBAtSwitch3Inport2_Buffer0;
  }

  /* End of RateTransition: '<Root>/TmpRTBAtSwitch3Inport2' */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (MSupGesamt_B.TmpRTBAtSwitch3Inport2 > MSupGesamt_P.Switch3_Threshold) {
    rtb_Switch3 = rtb_PWM_Out;
  } else {
    rtb_Switch3 = MSupGesamt_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* S-Function (c280xpwm): '<Root>/PWM Weiche' */

  /*-- Update CMPB value for ePWM6 --*/
  {
    EPwm6Regs.CMPB = (uint16_T)((uint32_T)EPwm6Regs.TBPRD * rtb_Switch3 * 0.01);
  }

  /* S-Function (c280xgpio_do): '<Root>/Richtung Weiche' */
  {
    if (MSupGesamt_B.DIR_d)
      GpioDataRegs.GPASET.bit.GPIO16 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO16 = 1;
  }

  /* S-Function (c280xgpio_do): '<Root>/Ricktung Kicker' */
  {
    if (MSupGesamt_B.richtung)
      GpioDataRegs.GPASET.bit.GPIO15 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO15 = 1;
  }
}

/* Model step function for TID1 */
void MSupGesamt_step1(void)            /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Switch6;
  int32_T bitIdx;
  uint32_T u;
  int32_T intVal;
  real32_T distanz;
  real32_T x_dif;
  real32_T y_dif;
  real32_T winkelVor;
  ZCEventType zcEvent;
  real_T rtb_PWM_Out;
  int16_T rtb_stop;
  int16_T rtb_ziel;
  uint16_T rtb_IntegertoBitConverter2[8];
  uint16_T rtb_IntegertoBitConverter3[8];
  uint16_T rtb_IntegertoBitConverter1[8];
  uint16_T rtb_IntegertoBitConverter4[8];
  uint16_T rtb_IntegertoBitConverter5[8];
  uint16_T rtb_IntegertoBitConverter6[8];
  uint16_T RateTransition[20];
  int16_T i;

  /* Chart: '<S3>/Strecken Koordinaten' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  /* Gateway: Subsystem/Strecken Koordinaten */
  /* During: Subsystem/Strecken Koordinaten */
  if (MSupGesamt_DWork.is_active_c6_MSupGesamt == 0U) {
    /* Entry: Subsystem/Strecken Koordinaten */
    MSupGesamt_DWork.is_active_c6_MSupGesamt = 1U;

    /* Entry Internal: Subsystem/Strecken Koordinaten */
    /* Transition: '<S20>:56' */
    MSupGesamt_DWork.is_c6_MSupGesamt = MSupGesamt_IN_Position1;

    /* Entry 'Position1': '<S20>:46' */
    MSupGesamt_B.x_soll = 8036.0F;
    MSupGesamt_B.y_soll = 3476.0F;
    rtb_stop = 0;
    MSupGesamt_B.rueck = 0.0F;
    MSupGesamt_B.finish = 0.0;
    MSupGesamt_B.uebergabe = 0.0;
  } else {
    switch (MSupGesamt_DWork.is_c6_MSupGesamt) {
     case MSupGesamt_IN_Position1:
      MSupGesamt_B.x_soll = 8036.0F;
      MSupGesamt_B.y_soll = 3476.0F;
      rtb_stop = 0;
      MSupGesamt_B.rueck = 0.0F;
      MSupGesamt_B.finish = 0.0;
      MSupGesamt_B.uebergabe = 0.0;

      /* During 'Position1': '<S20>:46' */
      if (MSupGesamt_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:136' */
        MSupGesamt_DWork.is_c6_MSupGesamt = MSupGesamt_IN_Position21;

        /* Entry 'Position21': '<S20>:137' */
        MSupGesamt_B.x_soll = 10029.0F;
        MSupGesamt_B.y_soll = 2391.0F;
        MSupGesamt_B.rueck = 0.0F;
      }
      break;

     case MSupGesamt_IN_Position21:
      MSupGesamt_B.x_soll = 10029.0F;
      MSupGesamt_B.y_soll = 2391.0F;
      rtb_stop = 0;
      MSupGesamt_B.rueck = 0.0F;

      /* During 'Position21': '<S20>:137' */
      if (MSupGesamt_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:138' */
        MSupGesamt_DWork.is_c6_MSupGesamt = MSupGesamt_IN_Stop;

        /* Entry 'Stop': '<S20>:50' */
        rtb_stop = 1;
        MSupGesamt_B.finish = 1.0;
      }
      break;

     default:
      rtb_stop = 1;
      MSupGesamt_B.finish = 1.0;

      /* During 'Stop': '<S20>:50' */
      break;
    }
  }

  /* End of Chart: '<S3>/Strecken Koordinaten' */

  /* RateTransition: '<S2>/Rate Transition' */
  MSupGesamt_DWork.RateTransition_semaphoreTaken =
    MSupGesamt_DWork.RateTransition_ActiveBufIdx;
  rtb_ziel = MSupGesamt_DWork.RateTransition_semaphoreTaken * 20;
  for (i = 0; i < 20; i++) {
    RateTransition[i] = MSupGesamt_DWork.RateTransition_Buffer[i + rtb_ziel];
  }

  /* End of RateTransition: '<S2>/Rate Transition' */

  /* Chart: '<S2>/Chart8' */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart8 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart8 */
  if (MSupGesamt_DWork.is_active_c17_MSupGesamt == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart8 */
    MSupGesamt_DWork.is_active_c17_MSupGesamt = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart8 */
    /* Transition: '<S10>:3' */
    MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_init;

    /* Entry 'init': '<S10>:2' */
    MSupGesamt_DWork.values_out1[0] = 0;
    MSupGesamt_DWork.values_out1[1] = 0;
    MSupGesamt_DWork.values_out1[2] = 0;
    MSupGesamt_DWork.values_out1[3] = 0;
    MSupGesamt_DWork.values_out1[4] = 0;
    MSupGesamt_DWork.values_out1[5] = 0;
    MSupGesamt_DWork.values_out1[6] = 0;
    MSupGesamt_DWork.values_out1[7] = 0;
    MSupGesamt_DWork.values_out1[8] = 0;
    MSupGesamt_DWork.values_out1[9] = 0;
    MSupGesamt_DWork.values_out1[10] = 0;
    MSupGesamt_DWork.values_out1[11] = 0;
    MSupGesamt_DWork.values_out1[12] = 0;
    MSupGesamt_DWork.values_out1[13] = 0;
    MSupGesamt_DWork.values_out1[14] = 0;
    MSupGesamt_DWork.values_out1[15] = 0;
    MSupGesamt_DWork.values_out1[16] = 0;
    MSupGesamt_DWork.values_out1[17] = 0;
    MSupGesamt_DWork.values_out1[18] = 0;
    MSupGesamt_DWork.values_out1[19] = 0;
  } else {
    switch (MSupGesamt_DWork.is_c17_MSupGesamt) {
     case IN_Anfang_found_Schritt_uebertr:
      /* During 'Anfang_found_Schritt_uebertragen_weglassen_performance': '<S10>:126' */
      if ((c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
            (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
              (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 1)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 2)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 3)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 4)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 5)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 6)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 7)]),
            MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
            (MSupGesamt_DWork.search, 8)]) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 256) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 512) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 1536) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 1280) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 1024) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 768) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search],
                    MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamt_DWork.search, 1)]),
                   MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamt_DWork.search, 2)]),
                  MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamt_DWork.search, 3)]),
                 MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamt_DWork.search, 4)]),
                MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamt_DWork.search, 5)]),
               MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamt_DWork.search, 6)]),
              MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamt_DWork.search, 7)]),
             MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamt_DWork.search, 8)]), 1792) ==
           MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamt_DWork.search, 9)])) {
        /* Transition: '<S10>:144' */
        /* Transition: '<S10>:145' */
        /* Transition: '<S10>:146' */
        /* Transition: '<S10>:151' */
        /* Transition: '<S10>:150' */
        /* Transition: '<S10>:149' */
        /* Transition: '<S10>:147' */
        /* Transition: '<S10>:156' */
        MSupGesamt_DWork.is_c17_MSupGesamt = MSupGes_IN_x5_valid_data_found1;

        /* Entry 'x5_valid_data_found1': '<S10>:148' */
        MSupGesamt_B.valid_values1 =
          MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 1)];
        MSupGesamt_B.valid_values2 =
          MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 2)];
        MSupGesamt_B.valid_values3 =
          MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 3)];
        MSupGesamt_B.valid_values4 =
          MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 4)];
        MSupGesamt_B.valid_values5 =
          MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 5)];
        MSupGesamt_B.valid_values6 =
          MSupGesamt_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 6)];
        MSupGesamt_DWork.zaehler = c28x_add_s32_s32_s32_sat
          (MSupGesamt_DWork.zaehler, 1L);
      } else {
        /* Transition: '<S10>:135' */
        MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_x1_search1;

        /* Entry 'x1_search1': '<S10>:125' */
        MSupGesamt_DWork.search = c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 1);
      }
      break;

     case MSupGesamt_IN_init:
      /* During 'init': '<S10>:2' */
      /* Transition: '<S10>:112' */
      MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_wert_erkannt;
      MSupG_enter_atomic_wert_erkannt(RateTransition);
      break;

     case MSupGesamt_IN_wert_erkannt:
      /* During 'wert_erkannt': '<S10>:109' */
      /* Transition: '<S10>:116' */
      MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_wert_erkannt2;

      /* Entry 'wert_erkannt2': '<S10>:115' */
      MSupGesamt_DWork.search = 0;
      MSupGesamt_DWork.counter = c28x_add_s32_s32_s32_sat
        (MSupGesamt_DWork.counter, 1L);
      break;

     case MSupGesamt_IN_wert_erkannt2:
      /* During 'wert_erkannt2': '<S10>:115' */
      if (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search] == 88) {
        /* Transition: '<S10>:127' */
        MSupGesamt_DWork.is_c17_MSupGesamt = IN_Anfang_found_Schritt_uebertr;

        /* Entry 'Anfang_found_Schritt_uebertragen_weglassen_performance': '<S10>:126' */
        MSupGesamt_DWork.x_found = c28x_add_s32_s32_s32_sat
          (MSupGesamt_DWork.x_found, 1L);
      } else {
        /* Transition: '<S10>:128' */
        MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_x1_search1;

        /* Entry 'x1_search1': '<S10>:125' */
        MSupGesamt_DWork.search = c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 1);
      }
      break;

     case MSupGesamt_IN_x1_search1:
      /* During 'x1_search1': '<S10>:125' */
      if (MSupGesamt_DWork.values_out1[MSupGesamt_DWork.search] == 88) {
        /* Transition: '<S10>:129' */
        MSupGesamt_DWork.is_c17_MSupGesamt = IN_Anfang_found_Schritt_uebertr;

        /* Entry 'Anfang_found_Schritt_uebertragen_weglassen_performance': '<S10>:126' */
        MSupGesamt_DWork.x_found = c28x_add_s32_s32_s32_sat
          (MSupGesamt_DWork.x_found, 1L);
      } else if (MSupGesamt_DWork.search < 19) {
        /* Transition: '<S10>:130' */
        MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_x1_search1;

        /* Entry 'x1_search1': '<S10>:125' */
        MSupGesamt_DWork.search = c28x_add_s16_s16_s16_sat
          (MSupGesamt_DWork.search, 1);
      } else {
        /* Transition: '<S10>:133' */
        MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_wert_erkannt;
        MSupG_enter_atomic_wert_erkannt(RateTransition);
      }
      break;

     default:
      /* During 'x5_valid_data_found1': '<S10>:148' */
      /* Transition: '<S10>:152' */
      MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_wert_erkannt;
      MSupG_enter_atomic_wert_erkannt(RateTransition);
      break;
    }
  }

  /* End of Chart: '<S2>/Chart8' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter2' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamt_B.valid_values1;
  for (rtb_ziel = 0; rtb_ziel < 8; rtb_ziel++) {
    rtb_IntegertoBitConverter2[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter2' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter3' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamt_B.valid_values2;
  for (rtb_ziel = 0; rtb_ziel < 8; rtb_ziel++) {
    rtb_IntegertoBitConverter3[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter3' */

  /* Chart: '<S2>/Chart6' */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart6 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart6 */
  if (MSupGesamt_DWork.is_active_c16_MSupGesamt == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart6 */
    MSupGesamt_DWork.is_active_c16_MSupGesamt = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart6 */
    /* Transition: '<S9>:3' */
    MSupGesamt_DWork.is_c16_MSupGesamt = MSupGesamt_IN_x0;
  } else {
    switch (MSupGesamt_DWork.is_c16_MSupGesamt) {
     case MSupGesamt_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S9>:17' */
      /* Transition: '<S9>:24' */
      MSupGesamt_DWork.is_c16_MSupGesamt = MSupGesamt_IN_x1_1;

      /* Entry 'x1_1': '<S9>:26' */
      MSupGesamt_B.int16x_bin[0] = rtb_IntegertoBitConverter2[0];
      MSupGesamt_B.int16x_bin[1] = rtb_IntegertoBitConverter2[1];
      MSupGesamt_B.int16x_bin[2] = rtb_IntegertoBitConverter2[2];
      MSupGesamt_B.int16x_bin[3] = rtb_IntegertoBitConverter2[3];
      MSupGesamt_B.int16x_bin[4] = rtb_IntegertoBitConverter2[4];
      MSupGesamt_B.int16x_bin[5] = rtb_IntegertoBitConverter2[5];
      MSupGesamt_B.int16x_bin[6] = rtb_IntegertoBitConverter2[6];
      MSupGesamt_B.int16x_bin[7] = rtb_IntegertoBitConverter2[7];
      MSupGesamt_B.int16x_bin[8] = rtb_IntegertoBitConverter3[0];
      MSupGesamt_B.int16x_bin[9] = rtb_IntegertoBitConverter3[1];
      MSupGesamt_B.int16x_bin[10] = rtb_IntegertoBitConverter3[2];
      MSupGesamt_B.int16x_bin[11] = rtb_IntegertoBitConverter3[3];
      MSupGesamt_B.int16x_bin[12] = rtb_IntegertoBitConverter3[4];
      MSupGesamt_B.int16x_bin[13] = rtb_IntegertoBitConverter3[5];
      MSupGesamt_B.int16x_bin[14] = rtb_IntegertoBitConverter3[6];
      MSupGesamt_B.int16x_bin[15] = rtb_IntegertoBitConverter3[7];
      break;

     case MSupGesamt_IN_x0:
      /* During 'x0': '<S9>:2' */
      /* Transition: '<S9>:7' */
      MSupGesamt_DWork.is_c16_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S9>:26' */
      /* Transition: '<S9>:25' */
      MSupGesamt_DWork.is_c16_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart6' */

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  intVal = 0L;
  for (rtb_ziel = 0; rtb_ziel < 16; rtb_ziel++) {
    /* Input bit order is MSB first */
    intVal <<= 1UL;
    intVal |= (int32_T)(real32_T)floor(MSupGesamt_B.int16x_bin[bitIdx]);
    if ((rtb_ziel == 0) && (intVal != 0L)) {
      /* Output Integer values are signed, do sign extension */
      intVal = -1L;
    }

    bitIdx++;
  }

  x_dif = (real32_T)intVal;

  /* End of S-Function (scominttobit): '<S2>/Bit to Integer Converter' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter1' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamt_B.valid_values3;
  for (rtb_ziel = 0; rtb_ziel < 8; rtb_ziel++) {
    rtb_IntegertoBitConverter1[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter1' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter4' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamt_B.valid_values4;
  for (rtb_ziel = 0; rtb_ziel < 8; rtb_ziel++) {
    rtb_IntegertoBitConverter4[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter4' */

  /* Chart: '<S2>/Chart2' */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart2 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart2 */
  if (MSupGesamt_DWork.is_active_c13_MSupGesamt == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart2 */
    MSupGesamt_DWork.is_active_c13_MSupGesamt = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart2 */
    /* Transition: '<S7>:3' */
    MSupGesamt_DWork.is_c13_MSupGesamt = MSupGesamt_IN_x0;
  } else {
    switch (MSupGesamt_DWork.is_c13_MSupGesamt) {
     case MSupGesamt_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S7>:17' */
      /* Transition: '<S7>:24' */
      MSupGesamt_DWork.is_c13_MSupGesamt = MSupGesamt_IN_x1_1;

      /* Entry 'x1_1': '<S7>:26' */
      MSupGesamt_B.int16y_bin[0] = rtb_IntegertoBitConverter1[0];
      MSupGesamt_B.int16y_bin[1] = rtb_IntegertoBitConverter1[1];
      MSupGesamt_B.int16y_bin[2] = rtb_IntegertoBitConverter1[2];
      MSupGesamt_B.int16y_bin[3] = rtb_IntegertoBitConverter1[3];
      MSupGesamt_B.int16y_bin[4] = rtb_IntegertoBitConverter1[4];
      MSupGesamt_B.int16y_bin[5] = rtb_IntegertoBitConverter1[5];
      MSupGesamt_B.int16y_bin[6] = rtb_IntegertoBitConverter1[6];
      MSupGesamt_B.int16y_bin[7] = rtb_IntegertoBitConverter1[7];
      MSupGesamt_B.int16y_bin[8] = rtb_IntegertoBitConverter4[0];
      MSupGesamt_B.int16y_bin[9] = rtb_IntegertoBitConverter4[1];
      MSupGesamt_B.int16y_bin[10] = rtb_IntegertoBitConverter4[2];
      MSupGesamt_B.int16y_bin[11] = rtb_IntegertoBitConverter4[3];
      MSupGesamt_B.int16y_bin[12] = rtb_IntegertoBitConverter4[4];
      MSupGesamt_B.int16y_bin[13] = rtb_IntegertoBitConverter4[5];
      MSupGesamt_B.int16y_bin[14] = rtb_IntegertoBitConverter4[6];
      MSupGesamt_B.int16y_bin[15] = rtb_IntegertoBitConverter4[7];
      break;

     case MSupGesamt_IN_x0:
      /* During 'x0': '<S7>:2' */
      /* Transition: '<S7>:7' */
      MSupGesamt_DWork.is_c13_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S7>:26' */
      /* Transition: '<S7>:25' */
      MSupGesamt_DWork.is_c13_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart2' */

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter1' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  intVal = 0L;
  for (rtb_ziel = 0; rtb_ziel < 16; rtb_ziel++) {
    /* Input bit order is MSB first */
    intVal <<= 1UL;
    intVal |= (int32_T)(real32_T)floor(MSupGesamt_B.int16y_bin[bitIdx]);
    if ((rtb_ziel == 0) && (intVal != 0L)) {
      /* Output Integer values are signed, do sign extension */
      intVal = -1L;
    }

    bitIdx++;
  }

  y_dif = (real32_T)intVal;

  /* End of S-Function (scominttobit): '<S2>/Bit to Integer Converter1' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter5' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamt_B.valid_values5;
  for (rtb_ziel = 0; rtb_ziel < 8; rtb_ziel++) {
    rtb_IntegertoBitConverter5[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter5' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter6' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamt_B.valid_values6;
  for (rtb_ziel = 0; rtb_ziel < 8; rtb_ziel++) {
    rtb_IntegertoBitConverter6[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter6' */

  /* Chart: '<S2>/Chart4' */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart4 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart4 */
  if (MSupGesamt_DWork.is_active_c14_MSupGesamt == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart4 */
    MSupGesamt_DWork.is_active_c14_MSupGesamt = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart4 */
    /* Transition: '<S8>:3' */
    MSupGesamt_DWork.is_c14_MSupGesamt = MSupGesamt_IN_x0;
  } else {
    switch (MSupGesamt_DWork.is_c14_MSupGesamt) {
     case MSupGesamt_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S8>:17' */
      /* Transition: '<S8>:24' */
      MSupGesamt_DWork.is_c14_MSupGesamt = MSupGesamt_IN_x1_1;

      /* Entry 'x1_1': '<S8>:26' */
      MSupGesamt_B.int16a1_bin[0] = rtb_IntegertoBitConverter5[0];
      MSupGesamt_B.int16a1_bin[1] = rtb_IntegertoBitConverter5[1];
      MSupGesamt_B.int16a1_bin[2] = rtb_IntegertoBitConverter5[2];
      MSupGesamt_B.int16a1_bin[3] = rtb_IntegertoBitConverter5[3];
      MSupGesamt_B.int16a1_bin[4] = rtb_IntegertoBitConverter5[4];
      MSupGesamt_B.int16a1_bin[5] = rtb_IntegertoBitConverter5[5];
      MSupGesamt_B.int16a1_bin[6] = rtb_IntegertoBitConverter5[6];
      MSupGesamt_B.int16a1_bin[7] = rtb_IntegertoBitConverter5[7];
      MSupGesamt_B.int16a1_bin[8] = rtb_IntegertoBitConverter6[0];
      MSupGesamt_B.int16a1_bin[9] = rtb_IntegertoBitConverter6[1];
      MSupGesamt_B.int16a1_bin[10] = rtb_IntegertoBitConverter6[2];
      MSupGesamt_B.int16a1_bin[11] = rtb_IntegertoBitConverter6[3];
      MSupGesamt_B.int16a1_bin[12] = rtb_IntegertoBitConverter6[4];
      MSupGesamt_B.int16a1_bin[13] = rtb_IntegertoBitConverter6[5];
      MSupGesamt_B.int16a1_bin[14] = rtb_IntegertoBitConverter6[6];
      MSupGesamt_B.int16a1_bin[15] = rtb_IntegertoBitConverter6[7];
      break;

     case MSupGesamt_IN_x0:
      /* During 'x0': '<S8>:2' */
      /* Transition: '<S8>:7' */
      MSupGesamt_DWork.is_c14_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S8>:26' */
      /* Transition: '<S8>:25' */
      MSupGesamt_DWork.is_c14_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart4' */

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter2' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  intVal = 0L;
  for (rtb_ziel = 0; rtb_ziel < 16; rtb_ziel++) {
    /* Input bit order is MSB first */
    intVal <<= 1UL;
    intVal |= (int32_T)(real32_T)floor(MSupGesamt_B.int16a1_bin[bitIdx]);
    if ((rtb_ziel == 0) && (intVal != 0L)) {
      /* Output Integer values are signed, do sign extension */
      intVal = -1L;
    }

    bitIdx++;
  }

  /* MATLAB Function: '<S3>/Winkel und Distanz' incorporates:
   *  S-Function (scominttobit): '<S2>/Bit to Integer Converter2'
   */
  /* MATLAB Function 'Subsystem/Winkel und Distanz': '<S21>:1' */
  /* '<S21>:1:4' */
  x_dif = MSupGesamt_B.x_soll - x_dif;

  /* '<S21>:1:5' */
  y_dif = MSupGesamt_B.y_soll - y_dif;

  /* '<S21>:1:6' */
  distanz = (real32_T)sqrt(x_dif * x_dif + y_dif * y_dif);

  /* '<S21>:1:7' */
  winkelVor = (real32_T)atan(y_dif / x_dif) * 57.2957802F;
  if (x_dif < 0.0F) {
    /* '<S21>:1:10' */
    /* '<S21>:1:11' */
    winkelVor += 180.0F;
  } else {
    if (y_dif < 0.0F) {
      /* '<S21>:1:13' */
      /* '<S21>:1:14' */
      winkelVor += 360.0F;
    }
  }

  if (MSupGesamt_B.rueck == 1.0F) {
    /* '<S21>:1:18' */
    /* '<S21>:1:19' */
    winkelVor += 180.0F;
    if (winkelVor > 360.0F) {
      /* '<S21>:1:20' */
      /* '<S21>:1:21' */
      winkelVor -= 360.0F;
    }
  }

  /* '<S21>:1:26' */
  winkelVor -= (real32_T)intVal / 10.0F;
  if (winkelVor > 175.0F) {
    /* '<S21>:1:29' */
    /* '<S21>:1:30' */
    winkelVor -= 360.0F;
  }

  /* '<S21>:1:33' */
  if (distanz < 300.0F) {
    /* '<S21>:1:36' */
    /* '<S21>:1:37' */
    rtb_ziel = 1;
  } else {
    /* '<S21>:1:39' */
    rtb_ziel = 0;
  }

  /* Chart: '<S3>/Fahrt Modi' incorporates:
   *  Constant: '<S3>/drehGes '
   *  Constant: '<S3>/normalGes '
   *  MATLAB Function: '<S3>/Winkel und Distanz'
   */
  /* Gateway: Subsystem/Fahrt Modi */
  /* During: Subsystem/Fahrt Modi */
  if (MSupGesamt_DWork.is_active_c2_MSupGesamt == 0U) {
    /* Entry: Subsystem/Fahrt Modi */
    MSupGesamt_DWork.is_active_c2_MSupGesamt = 1U;

    /* Entry Internal: Subsystem/Fahrt Modi */
    /* Transition: '<S17>:8' */
    MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_Stehen;

    /* Entry 'Stehen': '<S17>:7' */
    MSupGesamt_B.PWM_1_L = 0.0;
    MSupGesamt_B.PWM_2_R = 0.0;
  } else {
    switch (MSupGesamt_DWork.is_c2_MSupGesamt) {
     case MSupGesamt_IN_GeradeausFahren:
      /* During 'GeradeausFahren': '<S17>:12' */
      if ((winkelVor < -10.0F) || (winkelVor > 10.0F) || (rtb_stop == 1)) {
        /* Transition: '<S17>:31' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
        MSupGesamt_B.PWM_1_L = 0.0;
        MSupGesamt_B.PWM_2_R = 0.0;
      }
      break;

     case MSupGesamt_IN_LinksDrehen:
      /* During 'LinksDrehen': '<S17>:9' */
      if (((winkelVor > -10.0F) && (winkelVor < 10.0F)) || (rtb_stop == 1) ||
          (distanz < 300.0F)) {
        /* Transition: '<S17>:33' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
        MSupGesamt_B.PWM_1_L = 0.0;
        MSupGesamt_B.PWM_2_R = 0.0;
      } else {
        if (winkelVor < -10.0F) {
          /* Transition: '<S17>:41' */
          MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_RechtsDrehen;

          /* Entry 'RechtsDrehen': '<S17>:10' */
          MSupGesamt_B.PWM_1_L = MSupGesamt_P.drehGes_Value;
          MSupGesamt_B.PWM_2_R = -MSupGesamt_P.drehGes_Value;
        }
      }
      break;

     case MSupGesamt_IN_RechtsDrehen:
      /* During 'RechtsDrehen': '<S17>:10' */
      if (((winkelVor > -10.0F) && (winkelVor < 10.0F)) || (rtb_stop == 1) ||
          (distanz < 300.0F)) {
        /* Transition: '<S17>:39' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
        MSupGesamt_B.PWM_1_L = 0.0;
        MSupGesamt_B.PWM_2_R = 0.0;
      } else {
        if (winkelVor > 10.0F) {
          /* Transition: '<S17>:42' */
          MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_LinksDrehen;

          /* Entry 'LinksDrehen': '<S17>:9' */
          MSupGesamt_B.PWM_1_L = -MSupGesamt_P.drehGes_Value;
          MSupGesamt_B.PWM_2_R = MSupGesamt_P.drehGes_Value;
        }
      }
      break;

     case MSupGesamt_IN_Rueckwaerts:
      /* During 'Rueckwaerts': '<S17>:43' */
      if ((winkelVor < -10.0F) || (winkelVor > 10.0F) || (rtb_stop == 1)) {
        /* Transition: '<S17>:46' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
        MSupGesamt_B.PWM_1_L = 0.0;
        MSupGesamt_B.PWM_2_R = 0.0;
      }
      break;

     default:
      /* During 'Stehen': '<S17>:7' */
      if ((winkelVor > -10.0F) && (winkelVor < 10.0F) && (rtb_stop == 0) &&
          (MSupGesamt_B.rueck == 0.0F)) {
        /* Transition: '<S17>:30' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_GeradeausFahren;

        /* Entry 'GeradeausFahren': '<S17>:12' */
        MSupGesamt_B.PWM_1_L = MSupGesamt_P.normalGes_Value;
        MSupGesamt_B.PWM_2_R = MSupGesamt_P.normalGes_Value;
      } else if ((winkelVor > 10.0F) && (rtb_stop == 0)) {
        /* Transition: '<S17>:32' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_LinksDrehen;

        /* Entry 'LinksDrehen': '<S17>:9' */
        MSupGesamt_B.PWM_1_L = -MSupGesamt_P.drehGes_Value;
        MSupGesamt_B.PWM_2_R = MSupGesamt_P.drehGes_Value;
      } else if ((winkelVor < -10.0F) && (rtb_stop == 0)) {
        /* Transition: '<S17>:34' */
        MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_RechtsDrehen;

        /* Entry 'RechtsDrehen': '<S17>:10' */
        MSupGesamt_B.PWM_1_L = MSupGesamt_P.drehGes_Value;
        MSupGesamt_B.PWM_2_R = -MSupGesamt_P.drehGes_Value;
      } else {
        if ((winkelVor > -10.0F) && (winkelVor < 10.0F) && (rtb_stop == 0) &&
            (MSupGesamt_B.rueck == 1.0F)) {
          /* Transition: '<S17>:45' */
          MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_Rueckwaerts;

          /* Entry 'Rueckwaerts': '<S17>:43' */
          MSupGesamt_B.PWM_1_L = -MSupGesamt_P.drehGes_Value;
          MSupGesamt_B.PWM_2_R = -MSupGesamt_P.drehGes_Value;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Fahrt Modi' */

  /* MATLAB Function: '<S3>/Richtungs Wechsel M1 ' */
  /* MATLAB Function 'Subsystem/Richtungs Wechsel M1 ': '<S18>:1' */
  if (MSupGesamt_B.PWM_1_L > 0.0) {
    /* '<S18>:1:2' */
    /* '<S18>:1:3' */
    MSupGesamt_B.Switch5 = 0.0;
  } else {
    /* '<S18>:1:5' */
    MSupGesamt_B.Switch5 = 1.0;
  }

  /* End of MATLAB Function: '<S3>/Richtungs Wechsel M1 ' */

  /* S-Function (c280xgpio_do): '<Root>/DR MotorFL' */
  {
    if (MSupGesamt_B.Switch5)
      GpioDataRegs.GPASET.bit.GPIO21 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;
  }

  /* MATLAB Function: '<S3>/Richtungs Wechsel M2' */
  /* MATLAB Function 'Subsystem/Richtungs Wechsel M2': '<S19>:1' */
  if (MSupGesamt_B.PWM_2_R > 0.0) {
    /* '<S19>:1:2' */
    /* '<S19>:1:3' */
    MSupGesamt_B.Switch5 = 0.0;
  } else {
    /* '<S19>:1:5' */
    MSupGesamt_B.Switch5 = 1.0;
  }

  /* End of MATLAB Function: '<S3>/Richtungs Wechsel M2' */

  /* S-Function (c280xgpio_do): '<Root>/DR MotorFL1' */
  {
    if (MSupGesamt_B.Switch5)
      GpioDataRegs.GPASET.bit.GPIO20 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;
  }

  /* RateTransition: '<Root>/TmpRTBAtChartInport1' */
  if (MSupGesamt_M->Timing.RateInteraction.TID1_2) {
    MSupGesamt_B.TmpRTBAtChartInport1 =
      MSupGesamt_DWork.TmpRTBAtChartInport1_Buffer0;
  }

  /* End of RateTransition: '<Root>/TmpRTBAtChartInport1' */

  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  /* During: Chart */
  if (MSupGesamt_DWork.is_active_c3_MSupGesamt == 0U) {
    /* Entry: Chart */
    MSupGesamt_DWork.is_active_c3_MSupGesamt = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:2' */
    MSupGesamt_DWork.is_c3_MSupGesamt = MSupGesamt_IN_warten;

    /* Entry 'warten': '<S1>:9' */
    rtb_stop = 0;
  } else {
    switch (MSupGesamt_DWork.is_c3_MSupGesamt) {
     case MSupGesamt_IN_Anfang:
      rtb_stop = 1;

      /* During 'Anfang': '<S1>:1' */
      if (MSupGesamt_B.finish == 1.0) {
        /* Transition: '<S1>:7' */
        MSupGesamt_DWork.is_c3_MSupGesamt = MSupGesamt_IN_Ende;

        /* Entry 'Ende': '<S1>:3' */
        rtb_stop = 0;
      }
      break;

     case MSupGesamt_IN_Ende:
      rtb_stop = 0;

      /* During 'Ende': '<S1>:3' */
      break;

     default:
      rtb_stop = 0;

      /* During 'warten': '<S1>:9' */
      if (MSupGesamt_B.TmpRTBAtChartInport1 == 1L) {
        /* Transition: '<S1>:10' */
        MSupGesamt_DWork.is_c3_MSupGesamt = MSupGesamt_IN_Anfang;

        /* Entry 'Anfang': '<S1>:1' */
        rtb_stop = 1;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Switch: '<Root>/Switch4' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant7'
   */
  if (rtb_stop > MSupGesamt_P.Switch4_Threshold) {
    MSupGesamt_B.Switch5 = MSupGesamt_P.Constant7_Value;
  } else {
    MSupGesamt_B.Switch5 = MSupGesamt_P.Constant4_Value;
  }

  /* End of Switch: '<Root>/Switch4' */

  /* S-Function (c280xgpio_do): '<Root>/Förderband 1' */
  {
    if (MSupGesamt_B.Switch5)
      GpioDataRegs.GPBSET.bit.GPIO58 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO58 = 1;
  }

  /* Switch: '<Root>/Switch5' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant8'
   */
  if (rtb_stop > MSupGesamt_P.Switch5_Threshold) {
    MSupGesamt_B.Switch5 = MSupGesamt_P.Constant8_Value;
  } else {
    MSupGesamt_B.Switch5 = MSupGesamt_P.Constant5_Value;
  }

  /* End of Switch: '<Root>/Switch5' */

  /* S-Function (c280xgpio_do): '<Root>/Förderband 2' */
  {
    if (MSupGesamt_B.Switch5)
      GpioDataRegs.GPBSET.bit.GPIO61 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;
  }

  /* Logic: '<Root>/NOT' */
  MSupGesamt_B.NOT = (rtb_stop == 0);

  /* S-Function (c280xgpio_do): '<Root>/Glühbirne' */
  {
    if (MSupGesamt_B.NOT)
      GpioDataRegs.GPBSET.bit.GPIO60 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Abs: '<S3>/Abs'
   *  Constant: '<Root>/Constant'
   */
  if (rtb_stop > MSupGesamt_P.Switch_Threshold) {
    rtb_Switch6 = fabs(MSupGesamt_B.PWM_1_L);
  } else {
    rtb_Switch6 = MSupGesamt_P.Constant_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (c280xpwm): '<Root>/M1 links Motor' */

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)((uint32_T)EPwm2Regs.TBPRD * rtb_Switch6 * 0.01);
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Abs: '<S3>/Abs1'
   *  Constant: '<Root>/Constant2'
   */
  if (rtb_stop > MSupGesamt_P.Switch2_Threshold) {
    rtb_Switch6 = fabs(MSupGesamt_B.PWM_2_R);
  } else {
    rtb_Switch6 = MSupGesamt_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* S-Function (c280xpwm): '<Root>/M2 rechts Motor' */

  /*-- Update CMPB value for ePWM1 --*/
  {
    EPwm1Regs.CMPB = (uint16_T)((uint32_T)EPwm1Regs.TBPRD * rtb_Switch6 * 0.01);
  }

  /* RateTransition: '<S5>/TmpRTBAtChartInport2' */
  if (MSupGesamt_M->Timing.RateInteraction.TID1_2) {
    MSupGesamt_B.TmpRTBAtChartInport2 =
      MSupGesamt_DWork.TmpRTBAtChartInport2_Buffer0;

    /* RateTransition: '<S5>/TmpRTBAtChartInport3' */
    MSupGesamt_B.TmpRTBAtChartInport3 =
      MSupGesamt_DWork.TmpRTBAtChartInport3_Buffer0;
  }

  /* End of RateTransition: '<S5>/TmpRTBAtChartInport2' */

  /* Chart: '<S5>/Chart' */
  if (MSupGesamt_DWork.temporalCounter_i1 < 511U) {
    MSupGesamt_DWork.temporalCounter_i1++;
  }

  /* Gateway: Subsystem2/Chart */
  /* During: Subsystem2/Chart */
  if (MSupGesamt_DWork.is_active_c9_MSupGesamt == 0U) {
    /* Entry: Subsystem2/Chart */
    MSupGesamt_DWork.is_active_c9_MSupGesamt = 1U;

    /* Entry Internal: Subsystem2/Chart */
    /* Transition: '<S24>:7' */
    MSupGesamt_DWork.is_c9_MSupGesamt = MSupGesamt_IN_warten_iu;

    /* Entry 'warten': '<S24>:6' */
    rtb_PWM_Out = 0.0;
    MSupGesamt_B.DIR = 0.0;
  } else {
    switch (MSupGesamt_DWork.is_c9_MSupGesamt) {
     case MSupGesamt_IN_hochFahren:
      rtb_PWM_Out = 100.0;
      MSupGesamt_B.DIR = 0.0;

      /* During 'hochFahren': '<S24>:8' */
      if (MSupGesamt_B.TmpRTBAtChartInport2 == 1.0F) {
        /* Transition: '<S24>:11' */
        MSupGesamt_DWork.is_c9_MSupGesamt = MSupGesamt_IN_oben;
        MSupGesamt_DWork.temporalCounter_i1 = 0U;

        /* Entry 'oben': '<S24>:10' */
        rtb_PWM_Out = 0.0;
        MSupGesamt_B.DIR = 0.0;
      }
      break;

     case MSupGesamt_IN_oben:
      rtb_PWM_Out = 0.0;
      MSupGesamt_B.DIR = 0.0;

      /* During 'oben': '<S24>:10' */
      if (MSupGesamt_DWork.temporalCounter_i1 >= 500U) {
        /* Transition: '<S24>:13' */
        MSupGesamt_DWork.is_c9_MSupGesamt = MSupGesamt_IN_runterFahren;

        /* Entry 'runterFahren': '<S24>:12' */
        rtb_PWM_Out = 100.0;
        MSupGesamt_B.DIR = 1.0;
      }
      break;

     case MSupGesamt_IN_runterFahren:
      rtb_PWM_Out = 100.0;
      MSupGesamt_B.DIR = 1.0;

      /* During 'runterFahren': '<S24>:12' */
      if (MSupGesamt_B.TmpRTBAtChartInport3 == 1.0F) {
        /* Transition: '<S24>:17' */
        MSupGesamt_DWork.is_c9_MSupGesamt = MSupGesamt_IN_unten;

        /* Entry 'unten': '<S24>:14' */
        rtb_PWM_Out = 0.0;
        MSupGesamt_B.DIR = 0.0;
      }
      break;

     case MSupGesamt_IN_unten:
      rtb_PWM_Out = 0.0;
      MSupGesamt_B.DIR = 0.0;

      /* During 'unten': '<S24>:14' */
      break;

     default:
      rtb_PWM_Out = 0.0;
      MSupGesamt_B.DIR = 0.0;

      /* During 'warten': '<S24>:6' */
      if (MSupGesamt_B.uebergabe == 1.0) {
        /* Transition: '<S24>:9' */
        MSupGesamt_DWork.is_c9_MSupGesamt = MSupGesamt_IN_hochFahren;

        /* Entry 'hochFahren': '<S24>:8' */
        rtb_PWM_Out = 100.0;
        MSupGesamt_B.DIR = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Switch: '<Root>/Switch6' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  if (rtb_stop > MSupGesamt_P.Switch6_Threshold) {
    rtb_Switch6 = rtb_PWM_Out;
  } else {
    rtb_Switch6 = MSupGesamt_P.Constant6_Value;
  }

  /* End of Switch: '<Root>/Switch6' */

  /* S-Function (c280xpwm): '<Root>/Motor Aufzug' */

  /*-- Update CMPB value for ePWM3 --*/
  {
    EPwm3Regs.CMPB = (uint16_T)((uint32_T)EPwm3Regs.TBPRD * rtb_Switch6 * 0.01);
  }

  /* S-Function (c280xgpio_do): '<Root>/Richtung Motor Aufzug' */
  {
    if (MSupGesamt_B.DIR)
      GpioDataRegs.GPASET.bit.GPIO17 = 1;
    else
      GpioDataRegs.GPACLEAR.bit.GPIO17 = 1;
  }

  /* Chart: '<S2>/Chart1' */
  /* Integer to Bit Conversion */
  /* Integer to Bit Conversion */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart1 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart1 */
  if (MSupGesamt_DWork.is_active_c11_MSupGesamt == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart1 */
    MSupGesamt_DWork.is_active_c11_MSupGesamt = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart1 */
    /* Transition: '<S6>:3' */
    MSupGesamt_DWork.is_c11_MSupGesamt = MSupGesamt_IN_x0;
  } else {
    switch (MSupGesamt_DWork.is_c11_MSupGesamt) {
     case MSupGesamt_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S6>:17' */
      /* Transition: '<S6>:24' */
      MSupGesamt_DWork.is_c11_MSupGesamt = MSupGesamt_IN_x1_1;

      /* Entry 'x1_1': '<S6>:26' */
      break;

     case MSupGesamt_IN_x0:
      /* During 'x0': '<S6>:2' */
      /* Transition: '<S6>:7' */
      MSupGesamt_DWork.is_c11_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S6>:26' */
      /* Transition: '<S6>:25' */
      MSupGesamt_DWork.is_c11_MSupGesamt = MSupGesamt_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* DiscretePulseGenerator: '<S11>/Pulse Generator' */
  rtb_PWM_Out = (MSupGesamt_DWork.clockTickCounter <
                 MSupGesamt_P.PulseGenerator_Duty) &&
    (MSupGesamt_DWork.clockTickCounter >= 0L) ? MSupGesamt_P.PulseGenerator_Amp :
    0.0;
  if (MSupGesamt_DWork.clockTickCounter >= MSupGesamt_P.PulseGenerator_Period -
      1.0) {
    MSupGesamt_DWork.clockTickCounter = 0L;
  } else {
    MSupGesamt_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S11>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<S11>/I2C Reinitialisierung' incorporates:
   *  TriggerPort: '<S13>/Trigger'
   */
  zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &MSupGesamt_PrevZCSigState.I2CReinitialisierung_Trig_ZCE,
                     (rtb_PWM_Out));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S13>/I2C Reinitialisierung' */
    /* MATLAB Function 'Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reinitialisierung/I2C Reinitialisierung': '<S15>:1' */
    init_i2c();
  }

  /* End of Outputs for SubSystem: '<S11>/I2C Reinitialisierung' */

  /* Outputs for Triggered SubSystem: '<S11>/I2C Reset' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &MSupGesamt_PrevZCSigState.I2CReset_Trig_ZCE,
                     (rtb_PWM_Out));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S14>/I2C Reset' */
    /* MATLAB Function 'Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reset/I2C Reset': '<S16>:1' */
    reset_i2c();
  }

  /* End of Outputs for SubSystem: '<S11>/I2C Reset' */

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  MSupGesamt_DWork.UnitDelay_DSTATE = rtb_ziel;

  /* Update for RateTransition: '<Root>/TmpRTBAtSwitch1Inport2' */
  MSupGesamt_DWork.TmpRTBAtSwitch1Inport2_Buffer0 = rtb_stop;

  /* Update for RateTransition: '<Root>/TmpRTBAtSwitch3Inport2' */
  MSupGesamt_DWork.TmpRTBAtSwitch3Inport2_Buffer0 = rtb_stop;
}

/* Model step function for TID2 */
void MSupGesamt_step2(void)            /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (c280xgpio_di): '<Root>/Lichtsensor' */
  {
    MSupGesamt_B.Lichtsensor = GpioDataRegs.GPADAT.bit.GPIO25;
  }

  /* S-Function (c280xgpio_di): '<Root>/Start Taster' */
  {
    MSupGesamt_B.StartTaster = GpioDataRegs.GPADAT.bit.GPIO31;
  }

  /* S-Function (c280xgpio_di): '<Root>/Taster Oben' */
  {
    MSupGesamt_B.TasterOben = GpioDataRegs.GPADAT.bit.GPIO26;
  }

  /* S-Function (c280xgpio_di): '<Root>/Taster Unten' */
  {
    MSupGesamt_B.TasterUnten = GpioDataRegs.GPADAT.bit.GPIO27;
  }

  /* Update for RateTransition: '<Root>/TmpRTBAtChartInport1' */
  MSupGesamt_DWork.TmpRTBAtChartInport1_Buffer0 = MSupGesamt_B.StartTaster;

  /* Update for RateTransition: '<S5>/TmpRTBAtChartInport2' */
  MSupGesamt_DWork.TmpRTBAtChartInport2_Buffer0 = MSupGesamt_B.TasterOben;

  /* Update for RateTransition: '<S5>/TmpRTBAtChartInport3' */
  MSupGesamt_DWork.TmpRTBAtChartInport3_Buffer0 = MSupGesamt_B.TasterUnten;

  /* Update for RateTransition: '<S4>/TmpRTBAtSensorenInport1' */
  MSupGesamt_DWork.TmpRTBAtSensorenInport1_Buffer0 = MSupGesamt_B.Lichtsensor;
}

/* Model initialize function */
void MSupGesamt_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MSupGesamt_M, 0,
                sizeof(RT_MODEL_MSupGesamt));

  /* block I/O */
  (void) memset(((void *) &MSupGesamt_B), 0,
                sizeof(BlockIO_MSupGesamt));

  /* states (dwork) */
  (void) memset((void *)&MSupGesamt_DWork, 0,
                sizeof(D_Work_MSupGesamt));

  {
    int16_T i;

    /* Start for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' incorporates:
     *  SubSystem: '<S2>/Triggered Subsystem'
     */
    /* Start for function-call system: '<S2>/Triggered Subsystem' */

    /* Start for S-Function (c280xi2c_rx): '<S12>/I2C Receive' */

    /* Initialize MSupGesamt_B.I2CReceive_o1[0] */
    {
      MSupGesamt_B.I2CReceive_o1[0] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[1] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[2] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[3] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[4] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[5] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[6] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[7] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[8] = (uint8_T)0.0;
      MSupGesamt_B.I2CReceive_o1[9] = (uint8_T)0.0;
    }

    /* Start for S-Function (c280xgpio_do): '<Root>/DR MotorFL' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFF3FF;
    GpioCtrlRegs.GPADIR.all |= 0x200000;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<Root>/DR MotorFL1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFCFF;
    GpioCtrlRegs.GPADIR.all |= 0x100000;
    EDIS;

    /* Start for RateTransition: '<Root>/TmpRTBAtChartInport1' */
    MSupGesamt_B.TmpRTBAtChartInport1 =
      MSupGesamt_P.TmpRTBAtChartInport1_InitialCon;

    /* Start for S-Function (c280xgpio_do): '<Root>/Förderband 1' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xFFCFFFFF;
    GpioCtrlRegs.GPBDIR.all |= 0x4000000;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<Root>/Förderband 2' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xF3FFFFFF;
    GpioCtrlRegs.GPBDIR.all |= 0x20000000;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<Root>/Glühbirne' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xFCFFFFFF;
    GpioCtrlRegs.GPBDIR.all |= 0x10000000;
    EDIS;

    /* Start for S-Function (c280xpwm): '<Root>/M1 links Motor' */

    /*** Initialize ePWM2 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm2Regs.TBPRD = 64000;

      /* // Time-Base Control Register
         EPwm2Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
         EPwm2Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
         EPwm2Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm2Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
         EPwm2Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
         EPwm2Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm2Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FBF) | 0x30;

      /* // Time-Base Phase Register
         EPwm2Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
       */
      EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
      EPwm2Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm2Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm2Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm2Regs.CMPA.half.CMPA = 32000;
      EPwm2Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm2Regs.AQCTLA.all = 150;
      EPwm2Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm2Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm2Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm2Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm2Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
         EPwm2Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
         EPwm2Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
       */
      EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x3F) | 0x0;
      EPwm2Regs.DBRED = 0;
      EPwm2Regs.DBFED = 0;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm2Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
         EPwm2Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm2Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM2SOCA Period Select
         EPwm2Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm2Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm2Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM2SOCB Period Select
         EPwm2Regs.ETSEL.bit.INTEN      = 0;          // EPWM2INTn Enable
         EPwm2Regs.ETSEL.bit.INTSEL     = 1;          // EPWM2INTn Select
         EPwm2Regs.ETPS.bit.INTPRD      = 1;          // EPWM2INTn Period Select
       */
      EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0F) | 0x1101;
      EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303) | 0x1101;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm2Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm2Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm2Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm2Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm2Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm2Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM2A
         EPwm2Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM2B
       */
      EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xF) | 0xF;

      /* // Trip-Zone Enable Interrupt Register
         EPwm2Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm2Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for S-Function (c280xpwm): '<Root>/M2 rechts Motor' */

    /*** Initialize ePWM1 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm1Regs.TBPRD = 64000;

      /* // Time-Base Control Register
         EPwm1Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
         EPwm1Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
         EPwm1Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm1Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
         EPwm1Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
         EPwm1Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm1Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FBF) | 0x30;

      /* // Time-Base Phase Register
         EPwm1Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
       */
      EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
      EPwm1Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm1Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm1Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm1Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm1Regs.CMPA.half.CMPA = 32000;
      EPwm1Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm1Regs.AQCTLA.all = 150;
      EPwm1Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm1Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm1Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm1Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm1Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
         EPwm1Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
         EPwm1Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
       */
      EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x3F) | 0x0;
      EPwm1Regs.DBRED = 0;
      EPwm1Regs.DBFED = 0;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm1Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
         EPwm1Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm1Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM1SOCA Period Select
         EPwm1Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm1Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm1Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM1SOCB Period Select
         EPwm1Regs.ETSEL.bit.INTEN      = 0;          // EPWM1INTn Enable
         EPwm1Regs.ETSEL.bit.INTSEL     = 1;          // EPWM1INTn Select
         EPwm1Regs.ETPS.bit.INTPRD      = 1;          // EPWM1INTn Period Select
       */
      EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0F) | 0x1101;
      EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303) | 0x1101;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm1Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm1Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm1Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm1Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm1Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm1Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
         EPwm1Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
       */
      EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xF) | 0xF;

      /* // Trip-Zone Enable Interrupt Register
         EPwm1Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm1Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for RateTransition: '<S5>/TmpRTBAtChartInport2' */
    MSupGesamt_B.TmpRTBAtChartInport2 =
      MSupGesamt_P.TmpRTBAtChartInport2_InitialCon;

    /* Start for RateTransition: '<S5>/TmpRTBAtChartInport3' */
    MSupGesamt_B.TmpRTBAtChartInport3 =
      MSupGesamt_P.TmpRTBAtChartInport3_InitialCon;

    /* Start for S-Function (c280xpwm): '<Root>/Motor Aufzug' */

    /*** Initialize ePWM3 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm3Regs.TBPRD = 64000;

      /* // Time-Base Control Register
         EPwm3Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
         EPwm3Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
         EPwm3Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm3Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
         EPwm3Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
         EPwm3Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm3Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FBF) | 0x30;

      /* // Time-Base Phase Register
         EPwm3Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
       */
      EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
      EPwm3Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm3Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm3Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm3Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm3Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm3Regs.CMPA.half.CMPA = 32000;
      EPwm3Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm3Regs.AQCTLA.all = 150;
      EPwm3Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm3Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm3Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm3Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm3Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
         EPwm3Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
         EPwm3Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
       */
      EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x3F) | 0x0;
      EPwm3Regs.DBRED = 0;
      EPwm3Regs.DBFED = 0;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm3Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
         EPwm3Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm3Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM3SOCA Period Select
         EPwm3Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm3Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm3Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM3SOCB Period Select
         EPwm3Regs.ETSEL.bit.INTEN      = 0;          // EPWM3INTn Enable
         EPwm3Regs.ETSEL.bit.INTSEL     = 1;          // EPWM3INTn Select
         EPwm3Regs.ETPS.bit.INTPRD      = 1;          // EPWM3INTn Period Select
       */
      EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0F) | 0x1101;
      EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303) | 0x1101;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm3Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm3Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm3Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm3Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm3Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm3Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM3A
         EPwm3Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM3B
       */
      EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xF) | 0xF;

      /* // Trip-Zone Enable Interrupt Register
         EPwm3Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm3Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for RateTransition: '<S4>/TmpRTBAtSensorenInport1' */
    MSupGesamt_B.TmpRTBAtSensorenInport1 =
      MSupGesamt_P.TmpRTBAtSensorenInport1_Initial;

    /* Start for S-Function (c280xadc): '<Root>/Farbsensor' */
    if (adcInitFlag == 0) {
      InitAdc();
      adcInitFlag = 1;
    }

    config_ADC_A (0U, 2U, 0U, 0U, 0U);

    /* Start for RateTransition: '<Root>/TmpRTBAtSwitch1Inport2' */
    MSupGesamt_B.TmpRTBAtSwitch1Inport2 =
      MSupGesamt_P.TmpRTBAtSwitch1Inport2_InitialC;

    /* Start for S-Function (c280xpwm): '<Root>/PWM Kicker' */

    /*** Initialize ePWM5 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm5Regs.TBPRD = 64000;

      /* // Time-Base Control Register
         EPwm5Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
         EPwm5Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
         EPwm5Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm5Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
         EPwm5Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
         EPwm5Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm5Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FBF) | 0x30;

      /* // Time-Base Phase Register
         EPwm5Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
       */
      EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
      EPwm5Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm5Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm5Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm5Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm5Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm5Regs.CMPA.half.CMPA = 32000;
      EPwm5Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm5Regs.AQCTLA.all = 36;
      EPwm5Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm5Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm5Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm5Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm5Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
         EPwm5Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
         EPwm5Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
       */
      EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x3F) | 0x0;
      EPwm5Regs.DBRED = 0;
      EPwm5Regs.DBFED = 0;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm5Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
         EPwm5Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm5Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM5SOCA Period Select
         EPwm5Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm5Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm5Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM5SOCB Period Select
         EPwm5Regs.ETSEL.bit.INTEN      = 0;          // EPWM5INTn Enable
         EPwm5Regs.ETSEL.bit.INTSEL     = 1;          // EPWM5INTn Select
         EPwm5Regs.ETPS.bit.INTPRD      = 1;          // EPWM5INTn Period Select
       */
      EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF0F) | 0x1101;
      EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x3303) | 0x1101;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm5Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm5Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm5Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm5Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm5Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm5Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM5A
         EPwm5Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM5B
       */
      EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xF) | 0xF;

      /* // Trip-Zone Enable Interrupt Register
         EPwm5Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm5Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for RateTransition: '<Root>/TmpRTBAtSwitch3Inport2' */
    MSupGesamt_B.TmpRTBAtSwitch3Inport2 =
      MSupGesamt_P.TmpRTBAtSwitch3Inport2_InitialC;

    /* Start for S-Function (c280xpwm): '<Root>/PWM Weiche' */

    /*** Initialize ePWM6 modules ***/
    {
      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm6Regs.TBPRD = 64000;

      /* // Time-Base Control Register
         EPwm6Regs.TBCTL.bit.CTRMODE    = 0;          // Counter Mode
         EPwm6Regs.TBCTL.bit.SYNCOSEL   = 3;          // Sync output select
         EPwm6Regs.TBCTL.bit.PRDLD      = 0;          // Shadow select
         EPwm6Regs.TBCTL.bit.PHSEN      = 0;          // Phase load enable
         EPwm6Regs.TBCTL.bit.PHSDIR     = 0;          // Phase Direction
         EPwm6Regs.TBCTL.bit.HSPCLKDIV  = 0;          // High speed time pre-scale
         EPwm6Regs.TBCTL.bit.CLKDIV     = 0;          // Timebase clock pre-scale
       */
      EPwm6Regs.TBCTL.all = (EPwm6Regs.TBCTL.all & ~0x3FBF) | 0x30;

      /* // Time-Base Phase Register
         EPwm6Regs.TBPHS.half.TBPHS     = 0;          // Phase offset register
       */
      EPwm6Regs.TBPHS.all = (EPwm6Regs.TBPHS.all & ~0xFFFF0000) | 0x0;
      EPwm6Regs.TBCTR = 0x0000;        /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /* // Counter-Compare Control Register
         EPwm6Regs.CMPCTL.bit.SHDWAMODE = 0;  // Compare A block operating mode.
         EPwm6Regs.CMPCTL.bit.SHDWBMODE = 0;  // Compare B block operating mode.
         EPwm6Regs.CMPCTL.bit.LOADAMODE = 0;          // Active compare A
         EPwm6Regs.CMPCTL.bit.LOADBMODE = 0;          // Active compare A
       */
      EPwm6Regs.CMPCTL.all = (EPwm6Regs.CMPCTL.all & ~0x5F) | 0x0;
      EPwm6Regs.CMPA.half.CMPA = 32000;
      EPwm6Regs.CMPB = 0;

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm6Regs.AQCTLA.all = 36;
      EPwm6Regs.AQCTLB.all = 264;

      /* // Action-Qualifier Software Force Register
         EPwm6Regs.AQSFRC.bit.RLDCSF    = 0;          // Reload from Shadow options
       */
      EPwm6Regs.AQSFRC.all = (EPwm6Regs.AQSFRC.all & ~0xC0) | 0x0;

      /* // Action-Qualifier Continuous S/W Force Register Set
         EPwm6Regs.AQCSFRC.bit.CSFA     = 0;          // Continuous Software Force on output A
         EPwm6Regs.AQCSFRC.bit.CSFB     = 0;          // Continuous Software Force on output B
       */
      EPwm6Regs.AQCSFRC.all = (EPwm6Regs.AQCSFRC.all & ~0xF) | 0x0;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /* // Dead-Band Generator Control Register
         EPwm6Regs.DBCTL.bit.OUT_MODE   = 0;          // Dead Band Output Mode Control
         EPwm6Regs.DBCTL.bit.IN_MODE    = 0;          // Dead Band Input Select Mode Control
         EPwm6Regs.DBCTL.bit.POLSEL     = 0;          // Polarity Select Control
       */
      EPwm6Regs.DBCTL.all = (EPwm6Regs.DBCTL.all & ~0x3F) | 0x0;
      EPwm6Regs.DBRED = 0;
      EPwm6Regs.DBFED = 0;

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /* // Event-Trigger Selection and Event-Trigger Pre-Scale Register
         EPwm6Regs.ETSEL.bit.SOCAEN     = 0;          // Start of conversion A Enable
         EPwm6Regs.ETSEL.bit.SOCASEL    = 1;          // Start of conversion A Select
         EPwm6Regs.ETPS.bit.SOCAPRD     = 1;          // EPWM6SOCA Period Select
         EPwm6Regs.ETSEL.bit.SOCBEN     = 0;          // Start of conversion B Enable
         EPwm6Regs.ETSEL.bit.SOCBSEL    = 1;          // Start of conversion B Select
         EPwm6Regs.ETPS.bit.SOCBPRD     = 1;          // EPWM6SOCB Period Select
         EPwm6Regs.ETSEL.bit.INTEN      = 0;          // EPWM6INTn Enable
         EPwm6Regs.ETSEL.bit.INTSEL     = 1;          // EPWM6INTn Select
         EPwm6Regs.ETPS.bit.INTPRD      = 1;          // EPWM6INTn Period Select
       */
      EPwm6Regs.ETSEL.all = (EPwm6Regs.ETSEL.all & ~0xFF0F) | 0x1101;
      EPwm6Regs.ETPS.all = (EPwm6Regs.ETPS.all & ~0x3303) | 0x1101;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /* // PWM-Chopper Control Register
         EPwm6Regs.PCCTL.bit.CHPEN      = 0;          // PWM chopping enable
         EPwm6Regs.PCCTL.bit.CHPFREQ    = 0;          // Chopping clock frequency
         EPwm6Regs.PCCTL.bit.OSHTWTH    = 0;          // One-shot pulse width
         EPwm6Regs.PCCTL.bit.CHPDUTY    = 0;          // Chopping clock Duty cycle
       */
      EPwm6Regs.PCCTL.all = (EPwm6Regs.PCCTL.all & ~0x7FF) | 0x0;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm6Regs.TZSEL.all = 0;

      /* // Trip-Zone Control Register
         EPwm6Regs.TZCTL.bit.TZA        = 3;          // TZ1 to TZ6 Trip Action On EPWM6A
         EPwm6Regs.TZCTL.bit.TZB        = 3;          // TZ1 to TZ6 Trip Action On EPWM6B
       */
      EPwm6Regs.TZCTL.all = (EPwm6Regs.TZCTL.all & ~0xF) | 0xF;

      /* // Trip-Zone Enable Interrupt Register
         EPwm6Regs.TZEINT.bit.OST       = 0;          // Trip Zones One Shot Int Enable
         EPwm6Regs.TZEINT.bit.CBC       = 0;          // Trip Zones Cycle By Cycle Int Enable
       */
      EPwm6Regs.TZEINT.all = (EPwm6Regs.TZEINT.all & ~0x6) | 0x0;
      EDIS;
    }

    /* Start for S-Function (c280xgpio_do): '<Root>/Richtung Motor Aufzug' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFFF3;
    GpioCtrlRegs.GPADIR.all |= 0x20000;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<Root>/Richtung Weiche' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFFFFC;
    GpioCtrlRegs.GPADIR.all |= 0x10000;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<Root>/Ricktung Kicker' */
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all &= 0x3FFFFFFF;
    GpioCtrlRegs.GPADIR.all |= 0x8000;
    EDIS;

    /* Start for S-Function (c280xgpio_di): '<Root>/Lichtsensor' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFF3FFFF;
    GpioCtrlRegs.GPADIR.all &= 0xFDFFFFFF;
    EDIS;

    /* Start for S-Function (c280xgpio_di): '<Root>/Start Taster' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFF;
    GpioCtrlRegs.GPADIR.all &= 0x7FFFFFFF;
    EDIS;

    /* Start for S-Function (c280xgpio_di): '<Root>/Taster Oben' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFCFFFFF;
    GpioCtrlRegs.GPADIR.all &= 0xFBFFFFFF;
    EDIS;

    /* Start for S-Function (c280xgpio_di): '<Root>/Taster Unten' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFF3FFFFF;
    GpioCtrlRegs.GPADIR.all &= 0xF7FFFFFF;
    EDIS;
    MSupGesamt_PrevZCSigState.I2CReinitialisierung_Trig_ZCE =
      UNINITIALIZED_ZCSIG;
    MSupGesamt_PrevZCSigState.I2CReset_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    MSupGesamt_DWork.UnitDelay_DSTATE = MSupGesamt_P.UnitDelay_InitialCondition;

    /* InitializeConditions for RateTransition: '<S2>/Rate Transition' */
    for (i = 0; i < 20; i++) {
      MSupGesamt_DWork.RateTransition_Buffer[i] =
        MSupGesamt_P.RateTransition_InitialCondition;
    }

    /* End of InitializeConditions for RateTransition: '<S2>/Rate Transition' */

    /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtChartInport1' */
    MSupGesamt_DWork.TmpRTBAtChartInport1_Buffer0 =
      MSupGesamt_P.TmpRTBAtChartInport1_InitialCon;

    /* InitializeConditions for RateTransition: '<S5>/TmpRTBAtChartInport2' */
    MSupGesamt_DWork.TmpRTBAtChartInport2_Buffer0 =
      MSupGesamt_P.TmpRTBAtChartInport2_InitialCon;

    /* InitializeConditions for RateTransition: '<S5>/TmpRTBAtChartInport3' */
    MSupGesamt_DWork.TmpRTBAtChartInport3_Buffer0 =
      MSupGesamt_P.TmpRTBAtChartInport3_InitialCon;

    /* InitializeConditions for RateTransition: '<S4>/TmpRTBAtSensorenInport1' */
    MSupGesamt_DWork.TmpRTBAtSensorenInport1_Buffer0 =
      MSupGesamt_P.TmpRTBAtSensorenInport1_Initial;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
    MSupGesamt_DWork.UnitDelay_DSTATE_o =
      MSupGesamt_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtSwitch1Inport2' */
    MSupGesamt_DWork.TmpRTBAtSwitch1Inport2_Buffer0 =
      MSupGesamt_P.TmpRTBAtSwitch1Inport2_InitialC;

    /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtSwitch3Inport2' */
    MSupGesamt_DWork.TmpRTBAtSwitch3Inport2_Buffer0 =
      MSupGesamt_P.TmpRTBAtSwitch3Inport2_InitialC;

    /* InitializeConditions for DiscretePulseGenerator: '<S11>/Pulse Generator' */
    MSupGesamt_DWork.clockTickCounter = 0L;

    /* SystemInitialize for Chart: '<S3>/Strecken Koordinaten' */
    MSupGesamt_DWork.is_active_c6_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c6_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' incorporates:
     *  SubSystem: '<S2>/Triggered Subsystem'
     */
    /* System initialize for function-call system: '<S2>/Triggered Subsystem' */
    {
      int16_T i;

      /* InitializeConditions for Delay: '<S12>/Delay' */
      for (i = 0; i < 10; i++) {
        MSupGesamt_DWork.Delay_DSTATE[i] = MSupGesamt_P.Delay_InitialCondition;
      }

      /* End of InitializeConditions for Delay: '<S12>/Delay' */
    }

    /* End of SystemInitialize for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' */

    /* SystemInitialize for Chart: '<S2>/Chart8' */
    MSupGesamt_DWork.is_active_c17_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c17_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;
    for (i = 0; i < 20; i++) {
      MSupGesamt_DWork.values_out1[i] = 0;
    }

    MSupGesamt_DWork.zaehler = 0L;
    MSupGesamt_DWork.search = 0;
    MSupGesamt_DWork.counter = 0L;
    MSupGesamt_DWork.x_found = 0L;
    MSupGesamt_B.valid_values1 = 0;
    MSupGesamt_B.valid_values2 = 0;
    MSupGesamt_B.valid_values3 = 0;
    MSupGesamt_B.valid_values4 = 0;
    MSupGesamt_B.valid_values5 = 0;
    MSupGesamt_B.valid_values6 = 0;

    /* End of SystemInitialize for Chart: '<S2>/Chart8' */

    /* SystemInitialize for Chart: '<S2>/Chart6' */
    MSupGesamt_DWork.is_active_c16_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c16_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S2>/Chart2' */
    MSupGesamt_DWork.is_active_c13_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c13_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S2>/Chart4' */
    MSupGesamt_DWork.is_active_c14_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c14_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;
    for (i = 0; i < 16; i++) {
      /* SystemInitialize for Chart: '<S2>/Chart6' */
      MSupGesamt_B.int16x_bin[i] = 0.0F;

      /* SystemInitialize for Chart: '<S2>/Chart2' */
      MSupGesamt_B.int16y_bin[i] = 0.0F;

      /* SystemInitialize for Chart: '<S2>/Chart4' */
      MSupGesamt_B.int16a1_bin[i] = 0.0F;
    }

    /* SystemInitialize for Chart: '<S3>/Fahrt Modi' */
    MSupGesamt_DWork.is_active_c2_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c2_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    MSupGesamt_DWork.is_active_c3_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c3_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S5>/Chart' */
    MSupGesamt_DWork.temporalCounter_i1 = 0U;
    MSupGesamt_DWork.is_active_c9_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c9_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S4>/Sensoren' */
    MSupGesamt_DWork.temporalCounter_i1_o = 0U;
    MSupGesamt_DWork.is_active_c1_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c1_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S4>/Weichen Steuerung' */
    MSupGesamt_DWork.temporalCounter_i1_n = 0U;
    MSupGesamt_DWork.is_active_c8_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c8_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S2>/Chart1' */
    MSupGesamt_DWork.is_active_c11_MSupGesamt = 0U;
    MSupGesamt_DWork.is_c11_MSupGesamt = MSupGesamt_IN_NO_ACTIVE_CHILD;
  }
}

/* Model terminate function */
void MSupGesamt_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
