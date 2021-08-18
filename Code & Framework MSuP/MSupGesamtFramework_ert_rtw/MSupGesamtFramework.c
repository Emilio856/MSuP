/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MSupGesamtFramework.c
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

#include "MSupGesamtFramework.h"
#include "MSupGesamtFramework_private.h"
#define IN_Anfang_found_Schritt_uebertr (1U)
#define MSupGes_IN_x5_valid_data_found1 (6U)
#define MSupGesamtFr_IN_GeradeausFahren (1U)
#define MSupGesamtFr_IN_NO_ACTIVE_CHILD (0U)
#define MSupGesamtFr_IN_SchwarzOderBunt (4U)
#define MSupGesamtFra_IN_Daten_einlesen (1U)
#define MSupGesamtFram_IN_wert_erkannt2 (4U)
#define MSupGesamtFrame_IN_RechtsDrehen (3U)
#define MSupGesamtFrame_IN_rechtsdrehen (3U)
#define MSupGesamtFrame_IN_runterFahren (3U)
#define MSupGesamtFrame_IN_wert_erkannt (3U)
#define MSupGesamtFramew_IN_LinksDrehen (2U)
#define MSupGesamtFramew_IN_Rueckwaerts (4U)
#define MSupGesamtFramew_IN_linksdrehen (2U)
#define MSupGesamtFramewo_IN_hochFahren (1U)
#define MSupGesamtFramewo_IN_wartenkurz (10U)
#define MSupGesamtFramewo_IN_x1_search1 (5U)
#define MSupGesamtFramewor_IN_Position1 (1U)
#define MSupGesamtFramewor_IN_Position2 (2U)
#define MSupGesamtFramewor_IN_Position3 (3U)
#define MSupGesamtFramewor_IN_Position4 (4U)
#define MSupGesamtFramewor_IN_Position5 (5U)
#define MSupGesamtFramewor_IN_Uebergabe (7U)
#define MSupGesamtFramewor_IN_warten_ah (5U)
#define MSupGesamtFramework_IN_Anfang  (1U)
#define MSupGesamtFramework_IN_Bunt    (1U)
#define MSupGesamtFramework_IN_Ende    (2U)
#define MSupGesamtFramework_IN_Farbe   (2U)
#define MSupGesamtFramework_IN_Schwarz (3U)
#define MSupGesamtFramework_IN_Stehen  (5U)
#define MSupGesamtFramework_IN_Stop    (6U)
#define MSupGesamtFramework_IN_Ziel    (8U)
#define MSupGesamtFramework_IN_blau    (5U)
#define MSupGesamtFramework_IN_blau_a  (1U)
#define MSupGesamtFramework_IN_init    (2U)
#define MSupGesamtFramework_IN_oben    (2U)
#define MSupGesamtFramework_IN_rot     (6U)
#define MSupGesamtFramework_IN_rot_a   (4U)
#define MSupGesamtFramework_IN_unten   (4U)
#define MSupGesamtFramework_IN_warten  (3U)
#define MSupGesamtFramework_IN_warten3 (8U)
#define MSupGesamtFramework_IN_warten4 (9U)
#define MSupGesamtFramework_IN_warten_a (7U)
#define MSupGesamtFramework_IN_x0      (2U)
#define MSupGesamtFramework_IN_x1_1    (3U)

/* user code (top of source file) */
#include "i2c_reset.c"

/* Block signals (default storage) */
BlockIO_MSupGesamtFramework MSupGesamtFramework_B;

/* Block states (default storage) */
D_Work_MSupGesamtFramework MSupGesamtFramework_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_MSupGesamtFrame MSupGesamtFramew_PrevZCSigState;

/* Real-time model */
RT_MODEL_MSupGesamtFramework MSupGesamtFramework_M_;
RT_MODEL_MSupGesamtFramework *const MSupGesamtFramework_M =
  &MSupGesamtFramework_M_;

/* Forward declaration for local functions */
static void MSupG_enter_atomic_wert_erkannt(const uint16_T RateTransition[20]);

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
          uint8_T *y0 = &MSupGesamtFramework_B.I2CReceive_o1[0];
          for (i1=0; i1 < 10; i1++) {
            rx_loop= 0;
            while (I2caRegs.I2CFFRX.bit.RXFFST==0 && rx_loop<10000)
              rx_loop++;
            if (rx_loop!=10000) {
              y0[i1] = I2caRegs.I2CDRR;
              MSupGesamtFramework_B.I2CReceive_o2 = I2caRegs.I2CSTR.all;/* output i2c status */
            } else
              MSupGesamtFramework_B.I2CReceive_o2 = I2caRegs.I2CSTR.all | 0x40;/* output receive data loss status */
          }
        }
      }

      for (i = 0; i < 10; i++) {
        /* SignalConversion: '<S12>/ConcatBufferAtVector ConcatenateIn2' */
        MSupGesamtFramework_B.VectorConcatenate[i + 10] =
          MSupGesamtFramework_B.I2CReceive_o1[i];

        /* Delay: '<S12>/Delay' */
        MSupGesamtFramework_B.VectorConcatenate[i] =
          MSupGesamtFramework_DWork.Delay_DSTATE[i];

        /* Update for Delay: '<S12>/Delay' */
        MSupGesamtFramework_DWork.Delay_DSTATE[i] =
          MSupGesamtFramework_B.I2CReceive_o1[i];
      }
    }

    /* End of Outputs for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' */

    /* RateTransition: '<S2>/Rate Transition' */
    for (i = 0; i < 20; i++) {
      MSupGesamtFramework_DWork.RateTransition_Buffer[i +
        (MSupGesamtFramework_DWork.RateTransition_semaphoreTaken == 0) * 20] =
        MSupGesamtFramework_B.VectorConcatenate[i];
    }

    MSupGesamtFramework_DWork.RateTransition_ActiveBufIdx =
      (MSupGesamtFramework_DWork.RateTransition_semaphoreTaken == 0);

    /* End of RateTransition: '<S2>/Rate Transition' */
  }
}

/* Function for Chart: '<S2>/Chart8' */
static void MSupG_enter_atomic_wert_erkannt(const uint16_T RateTransition[20])
{
  /* Entry 'wert_erkannt': '<S10>:109' */
  MSupGesamtFramework_DWork.values_out1[0] = (int16_T)RateTransition[0];
  MSupGesamtFramework_DWork.values_out1[1] = (int16_T)RateTransition[1];
  MSupGesamtFramework_DWork.values_out1[2] = (int16_T)RateTransition[2];
  MSupGesamtFramework_DWork.values_out1[3] = (int16_T)RateTransition[3];
  MSupGesamtFramework_DWork.values_out1[4] = (int16_T)RateTransition[4];
  MSupGesamtFramework_DWork.values_out1[5] = (int16_T)RateTransition[5];
  MSupGesamtFramework_DWork.values_out1[6] = (int16_T)RateTransition[6];
  MSupGesamtFramework_DWork.values_out1[7] = (int16_T)RateTransition[7];
  MSupGesamtFramework_DWork.values_out1[8] = (int16_T)RateTransition[8];
  MSupGesamtFramework_DWork.values_out1[9] = (int16_T)RateTransition[9];
  MSupGesamtFramework_DWork.values_out1[10] = (int16_T)RateTransition[10];
  MSupGesamtFramework_DWork.values_out1[11] = (int16_T)RateTransition[11];
  MSupGesamtFramework_DWork.values_out1[12] = (int16_T)RateTransition[12];
  MSupGesamtFramework_DWork.values_out1[13] = (int16_T)RateTransition[13];
  MSupGesamtFramework_DWork.values_out1[14] = (int16_T)RateTransition[14];
  MSupGesamtFramework_DWork.values_out1[15] = (int16_T)RateTransition[15];
  MSupGesamtFramework_DWork.values_out1[16] = (int16_T)RateTransition[16];
  MSupGesamtFramework_DWork.values_out1[17] = (int16_T)RateTransition[17];
  MSupGesamtFramework_DWork.values_out1[18] = (int16_T)RateTransition[18];
  MSupGesamtFramework_DWork.values_out1[19] = (int16_T)RateTransition[19];
}

/* Model step function */
void MSupGesamtFramework_step(void)
{
  int32_T bitIdx;
  uint32_T u;
  int16_T j;
  int32_T intVal;
  real32_T distanz;
  real32_T x_dif;
  real32_T y_dif;
  real32_T winkelVor;
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;
  int16_T rtb_stop;
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
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  /* Gateway: Subsystem/Strecken Koordinaten */
  /* During: Subsystem/Strecken Koordinaten */
  if (MSupGesamtFramework_DWork.is_active_c6_MSupGesamtFramewor == 0U) {
    /* Entry: Subsystem/Strecken Koordinaten */
    MSupGesamtFramework_DWork.is_active_c6_MSupGesamtFramewor = 1U;

    /* Entry Internal: Subsystem/Strecken Koordinaten */
    /* Transition: '<S20>:56' */
    MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
      MSupGesamtFramewor_IN_Position1;

    /* Entry 'Position1': '<S20>:46' */
    MSupGesamtFramework_B.x_soll = 3470.0F;
    MSupGesamtFramework_B.y_soll = 2360.0F;
    rtb_stop = 0;
    MSupGesamtFramework_B.rueck = 0.0F;
    MSupGesamtFramework_B.finish = 0.0;
    MSupGesamtFramework_B.uebergabe = 0.0F;
  } else {
    switch (MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework) {
     case MSupGesamtFramewor_IN_Position1:
      MSupGesamtFramework_B.x_soll = 3470.0F;
      MSupGesamtFramework_B.y_soll = 2360.0F;
      rtb_stop = 0;
      MSupGesamtFramework_B.rueck = 0.0F;
      MSupGesamtFramework_B.finish = 0.0;

      /* During 'Position1': '<S20>:46' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:53' */
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramewor_IN_Position2;

        /* Entry 'Position2': '<S20>:48' */
        MSupGesamtFramework_B.x_soll = 4350.0F;
        MSupGesamtFramework_B.y_soll = 7800.0F;
        MSupGesamtFramework_B.rueck = 0.0F;
      }
      break;

     case MSupGesamtFramewor_IN_Position2:
      MSupGesamtFramework_B.x_soll = 4350.0F;
      MSupGesamtFramework_B.y_soll = 7800.0F;
      rtb_stop = 0;
      MSupGesamtFramework_B.rueck = 0.0F;

      /* During 'Position2': '<S20>:48' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:51' */
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramewor_IN_Position3;

        /* Entry 'Position3': '<S20>:45' */
        MSupGesamtFramework_B.x_soll = 8510.0F;
        MSupGesamtFramework_B.y_soll = 7110.0F;
        MSupGesamtFramework_B.rueck = 0.0F;
      }
      break;

     case MSupGesamtFramewor_IN_Position3:
      MSupGesamtFramework_B.x_soll = 8510.0F;
      MSupGesamtFramework_B.y_soll = 7110.0F;
      rtb_stop = 0;
      MSupGesamtFramework_B.rueck = 0.0F;

      /* During 'Position3': '<S20>:45' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:52' */
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramewor_IN_Position4;

        /* Entry 'Position4': '<S20>:49' */
        MSupGesamtFramework_B.x_soll = 7900.0F;
        MSupGesamtFramework_B.y_soll = 4060.0F;
        MSupGesamtFramework_B.rueck = 0.0F;
      }
      break;

     case MSupGesamtFramewor_IN_Position4:
      MSupGesamtFramework_B.x_soll = 7900.0F;
      MSupGesamtFramework_B.y_soll = 4060.0F;
      rtb_stop = 0;
      MSupGesamtFramework_B.rueck = 0.0F;

      /* During 'Position4': '<S20>:49' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:59' */
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramewor_IN_Position5;

        /* Entry 'Position5': '<S20>:58' */
        MSupGesamtFramework_B.x_soll = 10170.0F;
        MSupGesamtFramework_B.y_soll = 4916.0F;
        MSupGesamtFramework_B.rueck = 1.0F;
      }
      break;

     case MSupGesamtFramewor_IN_Position5:
      MSupGesamtFramework_B.x_soll = 10170.0F;
      MSupGesamtFramework_B.y_soll = 4916.0F;
      rtb_stop = 0;
      MSupGesamtFramework_B.rueck = 1.0F;

      /* During 'Position5': '<S20>:58' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:60' */
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramewor_IN_Uebergabe;

        /* Entry 'Uebergabe': '<S20>:61' */
        MSupGesamtFramework_B.uebergabe = 1.0F;
        rtb_stop = 1;
      }
      break;

     case MSupGesamtFramework_IN_Stop:
      rtb_stop = 1;
      MSupGesamtFramework_B.finish = 1.0;

      /* During 'Stop': '<S20>:50' */
      break;

     case MSupGesamtFramewor_IN_Uebergabe:
      rtb_stop = 1;

      /* During 'Uebergabe': '<S20>:61' */
      if (MSupGesamtFramework_DWork.UnitDelay1_DSTATE == 1.0) {
        /* Transition: '<S20>:62' */
        /* Exit 'Uebergabe': '<S20>:61' */
        MSupGesamtFramework_B.uebergabe = 0.0F;
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramework_IN_Ziel;

        /* Entry 'Ziel': '<S20>:47' */
        MSupGesamtFramework_B.x_soll = 8550.0F;
        MSupGesamtFramework_B.y_soll = -2150.0F;
        rtb_stop = 0;
        MSupGesamtFramework_B.rueck = 0.0F;
      }
      break;

     default:
      MSupGesamtFramework_B.x_soll = 8550.0F;
      MSupGesamtFramework_B.y_soll = -2150.0F;
      rtb_stop = 0;
      MSupGesamtFramework_B.rueck = 0.0F;

      /* During 'Ziel': '<S20>:47' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE == 1.0) {
        /* Transition: '<S20>:55' */
        MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
          MSupGesamtFramework_IN_Stop;

        /* Entry 'Stop': '<S20>:50' */
        rtb_stop = 1;
        MSupGesamtFramework_B.finish = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Strecken Koordinaten' */

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  if (MSupGesamtFramework_DWork.temporalCounter_i1 < 32767U) {
    MSupGesamtFramework_DWork.temporalCounter_i1++;
  }

  /* Gateway: Chart */
  /* During: Chart */
  if (MSupGesamtFramework_DWork.is_active_c3_MSupGesamtFramewor == 0U) {
    /* Entry: Chart */
    MSupGesamtFramework_DWork.is_active_c3_MSupGesamtFramewor = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:2' */
    MSupGesamtFramework_DWork.is_c3_MSupGesamtFramework =
      MSupGesamtFramework_IN_warten;

    /* Entry 'warten': '<S1>:9' */
  } else {
    switch (MSupGesamtFramework_DWork.is_c3_MSupGesamtFramework) {
     case MSupGesamtFramework_IN_Anfang:
      /* During 'Anfang': '<S1>:1' */
      if ((MSupGesamtFramework_DWork.temporalCounter_i1 >= 17500U) ||
          (MSupGesamtFramework_B.finish == 1.0)) {
        /* Transition: '<S1>:4' */
        /* Transition: '<S1>:7' */
        MSupGesamtFramework_DWork.is_c3_MSupGesamtFramework =
          MSupGesamtFramework_IN_Ende;

        /* Entry 'Ende': '<S1>:3' */
      }
      break;

     case MSupGesamtFramework_IN_Ende:
      /* During 'Ende': '<S1>:3' */
      break;

     default:
      /* During 'warten': '<S1>:9' */
      if (MSupGesamtFramework_P.Constant9_Value == 1.0) {
        /* Transition: '<S1>:10' */
        MSupGesamtFramework_DWork.is_c3_MSupGesamtFramework =
          MSupGesamtFramework_IN_Anfang;
        MSupGesamtFramework_DWork.temporalCounter_i1 = 0U;

        /* Entry 'Anfang': '<S1>:1' */
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
  /* RateTransition: '<S2>/Rate Transition' */
  MSupGesamtFramework_DWork.RateTransition_semaphoreTaken =
    MSupGesamtFramework_DWork.RateTransition_ActiveBufIdx;
  j = MSupGesamtFramework_DWork.RateTransition_semaphoreTaken * 20;
  for (i = 0; i < 20; i++) {
    RateTransition[i] = MSupGesamtFramework_DWork.RateTransition_Buffer[i + j];
  }

  /* End of RateTransition: '<S2>/Rate Transition' */

  /* Chart: '<S2>/Chart8' */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart8 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart8 */
  if (MSupGesamtFramework_DWork.is_active_c17_MSupGesamtFramewo == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart8 */
    MSupGesamtFramework_DWork.is_active_c17_MSupGesamtFramewo = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart8 */
    /* Transition: '<S10>:3' */
    MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
      MSupGesamtFramework_IN_init;

    /* Entry 'init': '<S10>:2' */
    MSupGesamtFramework_DWork.values_out1[0] = 0;
    MSupGesamtFramework_DWork.values_out1[1] = 0;
    MSupGesamtFramework_DWork.values_out1[2] = 0;
    MSupGesamtFramework_DWork.values_out1[3] = 0;
    MSupGesamtFramework_DWork.values_out1[4] = 0;
    MSupGesamtFramework_DWork.values_out1[5] = 0;
    MSupGesamtFramework_DWork.values_out1[6] = 0;
    MSupGesamtFramework_DWork.values_out1[7] = 0;
    MSupGesamtFramework_DWork.values_out1[8] = 0;
    MSupGesamtFramework_DWork.values_out1[9] = 0;
    MSupGesamtFramework_DWork.values_out1[10] = 0;
    MSupGesamtFramework_DWork.values_out1[11] = 0;
    MSupGesamtFramework_DWork.values_out1[12] = 0;
    MSupGesamtFramework_DWork.values_out1[13] = 0;
    MSupGesamtFramework_DWork.values_out1[14] = 0;
    MSupGesamtFramework_DWork.values_out1[15] = 0;
    MSupGesamtFramework_DWork.values_out1[16] = 0;
    MSupGesamtFramework_DWork.values_out1[17] = 0;
    MSupGesamtFramework_DWork.values_out1[18] = 0;
    MSupGesamtFramework_DWork.values_out1[19] = 0;
  } else {
    switch (MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework) {
     case IN_Anfang_found_Schritt_uebertr:
      /* During 'Anfang_found_Schritt_uebertragen_weglassen_performance': '<S10>:126' */
      if ((c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
            (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
              (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 1)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 2)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 3)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 4)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 5)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 6)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 7)]),
            MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
            (MSupGesamtFramework_DWork.search, 8)]) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 256) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 512) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 1536) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 1280) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 1024) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 768) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)]) || (c28x_sub_s16_s16_s16_sat
           (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
             (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
               (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                 (c28x_add_s16_s16_s16_sat(c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search],
                    MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                    (MSupGesamtFramework_DWork.search, 1)]),
                   MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                   (MSupGesamtFramework_DWork.search, 2)]),
                  MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                  (MSupGesamtFramework_DWork.search, 3)]),
                 MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                 (MSupGesamtFramework_DWork.search, 4)]),
                MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
                (MSupGesamtFramework_DWork.search, 5)]),
               MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
               (MSupGesamtFramework_DWork.search, 6)]),
              MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
              (MSupGesamtFramework_DWork.search, 7)]),
             MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
             (MSupGesamtFramework_DWork.search, 8)]), 1792) ==
           MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
           (MSupGesamtFramework_DWork.search, 9)])) {
        /* Transition: '<S10>:144' */
        /* Transition: '<S10>:145' */
        /* Transition: '<S10>:146' */
        /* Transition: '<S10>:151' */
        /* Transition: '<S10>:150' */
        /* Transition: '<S10>:149' */
        /* Transition: '<S10>:147' */
        /* Transition: '<S10>:156' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          MSupGes_IN_x5_valid_data_found1;

        /* Entry 'x5_valid_data_found1': '<S10>:148' */
        MSupGesamtFramework_B.valid_values1 =
          MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 1)];
        MSupGesamtFramework_B.valid_values2 =
          MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 2)];
        MSupGesamtFramework_B.valid_values3 =
          MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 3)];
        MSupGesamtFramework_B.valid_values4 =
          MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 4)];
        MSupGesamtFramework_B.valid_values5 =
          MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 5)];
        MSupGesamtFramework_B.valid_values6 =
          MSupGesamtFramework_DWork.values_out1[c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 6)];
        MSupGesamtFramework_DWork.zaehler = c28x_add_s32_s32_s32_sat
          (MSupGesamtFramework_DWork.zaehler, 1L);
      } else {
        /* Transition: '<S10>:135' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          MSupGesamtFramewo_IN_x1_search1;

        /* Entry 'x1_search1': '<S10>:125' */
        MSupGesamtFramework_DWork.search = c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 1);
      }
      break;

     case MSupGesamtFramework_IN_init:
      /* During 'init': '<S10>:2' */
      /* Transition: '<S10>:112' */
      MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
        MSupGesamtFrame_IN_wert_erkannt;
      MSupG_enter_atomic_wert_erkannt(RateTransition);
      break;

     case MSupGesamtFrame_IN_wert_erkannt:
      /* During 'wert_erkannt': '<S10>:109' */
      /* Transition: '<S10>:116' */
      MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
        MSupGesamtFram_IN_wert_erkannt2;

      /* Entry 'wert_erkannt2': '<S10>:115' */
      MSupGesamtFramework_DWork.search = 0;
      MSupGesamtFramework_DWork.counter = c28x_add_s32_s32_s32_sat
        (MSupGesamtFramework_DWork.counter, 1L);
      break;

     case MSupGesamtFram_IN_wert_erkannt2:
      /* During 'wert_erkannt2': '<S10>:115' */
      if (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search]
          == 88) {
        /* Transition: '<S10>:127' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          IN_Anfang_found_Schritt_uebertr;

        /* Entry 'Anfang_found_Schritt_uebertragen_weglassen_performance': '<S10>:126' */
        MSupGesamtFramework_DWork.x_found = c28x_add_s32_s32_s32_sat
          (MSupGesamtFramework_DWork.x_found, 1L);
      } else {
        /* Transition: '<S10>:128' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          MSupGesamtFramewo_IN_x1_search1;

        /* Entry 'x1_search1': '<S10>:125' */
        MSupGesamtFramework_DWork.search = c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 1);
      }
      break;

     case MSupGesamtFramewo_IN_x1_search1:
      /* During 'x1_search1': '<S10>:125' */
      if (MSupGesamtFramework_DWork.values_out1[MSupGesamtFramework_DWork.search]
          == 88) {
        /* Transition: '<S10>:129' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          IN_Anfang_found_Schritt_uebertr;

        /* Entry 'Anfang_found_Schritt_uebertragen_weglassen_performance': '<S10>:126' */
        MSupGesamtFramework_DWork.x_found = c28x_add_s32_s32_s32_sat
          (MSupGesamtFramework_DWork.x_found, 1L);
      } else if (MSupGesamtFramework_DWork.search < 19) {
        /* Transition: '<S10>:130' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          MSupGesamtFramewo_IN_x1_search1;

        /* Entry 'x1_search1': '<S10>:125' */
        MSupGesamtFramework_DWork.search = c28x_add_s16_s16_s16_sat
          (MSupGesamtFramework_DWork.search, 1);
      } else {
        /* Transition: '<S10>:133' */
        MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
          MSupGesamtFrame_IN_wert_erkannt;
        MSupG_enter_atomic_wert_erkannt(RateTransition);
      }
      break;

     default:
      /* During 'x5_valid_data_found1': '<S10>:148' */
      /* Transition: '<S10>:152' */
      MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
        MSupGesamtFrame_IN_wert_erkannt;
      MSupG_enter_atomic_wert_erkannt(RateTransition);
      break;
    }
  }

  /* End of Chart: '<S2>/Chart8' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter2' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamtFramework_B.valid_values1;
  for (j = 0; j < 8; j++) {
    rtb_IntegertoBitConverter2[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter2' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter3' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamtFramework_B.valid_values2;
  for (j = 0; j < 8; j++) {
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
  if (MSupGesamtFramework_DWork.is_active_c16_MSupGesamtFramewo == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart6 */
    MSupGesamtFramework_DWork.is_active_c16_MSupGesamtFramewo = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart6 */
    /* Transition: '<S9>:3' */
    MSupGesamtFramework_DWork.is_c16_MSupGesamtFramework =
      MSupGesamtFramework_IN_x0;
  } else {
    switch (MSupGesamtFramework_DWork.is_c16_MSupGesamtFramework) {
     case MSupGesamtFra_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S9>:17' */
      /* Transition: '<S9>:24' */
      MSupGesamtFramework_DWork.is_c16_MSupGesamtFramework =
        MSupGesamtFramework_IN_x1_1;

      /* Entry 'x1_1': '<S9>:26' */
      MSupGesamtFramework_B.int16x_bin[0] = rtb_IntegertoBitConverter2[0];
      MSupGesamtFramework_B.int16x_bin[1] = rtb_IntegertoBitConverter2[1];
      MSupGesamtFramework_B.int16x_bin[2] = rtb_IntegertoBitConverter2[2];
      MSupGesamtFramework_B.int16x_bin[3] = rtb_IntegertoBitConverter2[3];
      MSupGesamtFramework_B.int16x_bin[4] = rtb_IntegertoBitConverter2[4];
      MSupGesamtFramework_B.int16x_bin[5] = rtb_IntegertoBitConverter2[5];
      MSupGesamtFramework_B.int16x_bin[6] = rtb_IntegertoBitConverter2[6];
      MSupGesamtFramework_B.int16x_bin[7] = rtb_IntegertoBitConverter2[7];
      MSupGesamtFramework_B.int16x_bin[8] = rtb_IntegertoBitConverter3[0];
      MSupGesamtFramework_B.int16x_bin[9] = rtb_IntegertoBitConverter3[1];
      MSupGesamtFramework_B.int16x_bin[10] = rtb_IntegertoBitConverter3[2];
      MSupGesamtFramework_B.int16x_bin[11] = rtb_IntegertoBitConverter3[3];
      MSupGesamtFramework_B.int16x_bin[12] = rtb_IntegertoBitConverter3[4];
      MSupGesamtFramework_B.int16x_bin[13] = rtb_IntegertoBitConverter3[5];
      MSupGesamtFramework_B.int16x_bin[14] = rtb_IntegertoBitConverter3[6];
      MSupGesamtFramework_B.int16x_bin[15] = rtb_IntegertoBitConverter3[7];
      break;

     case MSupGesamtFramework_IN_x0:
      /* During 'x0': '<S9>:2' */
      /* Transition: '<S9>:7' */
      MSupGesamtFramework_DWork.is_c16_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S9>:26' */
      /* Transition: '<S9>:25' */
      MSupGesamtFramework_DWork.is_c16_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart6' */

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  intVal = 0L;
  for (j = 0; j < 16; j++) {
    /* Input bit order is MSB first */
    intVal <<= 1UL;
    intVal |= (int32_T)(real32_T)floor(MSupGesamtFramework_B.int16x_bin[bitIdx]);
    if ((j == 0) && (intVal != 0L)) {
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
  u = (uint32_T)MSupGesamtFramework_B.valid_values3;
  for (j = 0; j < 8; j++) {
    rtb_IntegertoBitConverter1[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter1' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter4' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamtFramework_B.valid_values4;
  for (j = 0; j < 8; j++) {
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
  if (MSupGesamtFramework_DWork.is_active_c13_MSupGesamtFramewo == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart2 */
    MSupGesamtFramework_DWork.is_active_c13_MSupGesamtFramewo = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart2 */
    /* Transition: '<S7>:3' */
    MSupGesamtFramework_DWork.is_c13_MSupGesamtFramework =
      MSupGesamtFramework_IN_x0;
  } else {
    switch (MSupGesamtFramework_DWork.is_c13_MSupGesamtFramework) {
     case MSupGesamtFra_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S7>:17' */
      /* Transition: '<S7>:24' */
      MSupGesamtFramework_DWork.is_c13_MSupGesamtFramework =
        MSupGesamtFramework_IN_x1_1;

      /* Entry 'x1_1': '<S7>:26' */
      MSupGesamtFramework_B.int16y_bin[0] = rtb_IntegertoBitConverter1[0];
      MSupGesamtFramework_B.int16y_bin[1] = rtb_IntegertoBitConverter1[1];
      MSupGesamtFramework_B.int16y_bin[2] = rtb_IntegertoBitConverter1[2];
      MSupGesamtFramework_B.int16y_bin[3] = rtb_IntegertoBitConverter1[3];
      MSupGesamtFramework_B.int16y_bin[4] = rtb_IntegertoBitConverter1[4];
      MSupGesamtFramework_B.int16y_bin[5] = rtb_IntegertoBitConverter1[5];
      MSupGesamtFramework_B.int16y_bin[6] = rtb_IntegertoBitConverter1[6];
      MSupGesamtFramework_B.int16y_bin[7] = rtb_IntegertoBitConverter1[7];
      MSupGesamtFramework_B.int16y_bin[8] = rtb_IntegertoBitConverter4[0];
      MSupGesamtFramework_B.int16y_bin[9] = rtb_IntegertoBitConverter4[1];
      MSupGesamtFramework_B.int16y_bin[10] = rtb_IntegertoBitConverter4[2];
      MSupGesamtFramework_B.int16y_bin[11] = rtb_IntegertoBitConverter4[3];
      MSupGesamtFramework_B.int16y_bin[12] = rtb_IntegertoBitConverter4[4];
      MSupGesamtFramework_B.int16y_bin[13] = rtb_IntegertoBitConverter4[5];
      MSupGesamtFramework_B.int16y_bin[14] = rtb_IntegertoBitConverter4[6];
      MSupGesamtFramework_B.int16y_bin[15] = rtb_IntegertoBitConverter4[7];
      break;

     case MSupGesamtFramework_IN_x0:
      /* During 'x0': '<S7>:2' */
      /* Transition: '<S7>:7' */
      MSupGesamtFramework_DWork.is_c13_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S7>:26' */
      /* Transition: '<S7>:25' */
      MSupGesamtFramework_DWork.is_c13_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart2' */

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter1' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  intVal = 0L;
  for (j = 0; j < 16; j++) {
    /* Input bit order is MSB first */
    intVal <<= 1UL;
    intVal |= (int32_T)(real32_T)floor(MSupGesamtFramework_B.int16y_bin[bitIdx]);
    if ((j == 0) && (intVal != 0L)) {
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
  u = (uint32_T)MSupGesamtFramework_B.valid_values5;
  for (j = 0; j < 8; j++) {
    rtb_IntegertoBitConverter5[bitIdx - 1L] = (uint16_T)((int16_T)u & 1);
    u >>= 1;
    bitIdx--;
  }

  /* End of S-Function (scominttobit): '<S2>/Integer to Bit Converter5' */

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter6' */
  /* Integer to Bit Conversion */
  bitIdx = 8L;
  u = (uint32_T)MSupGesamtFramework_B.valid_values6;
  for (j = 0; j < 8; j++) {
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
  if (MSupGesamtFramework_DWork.is_active_c14_MSupGesamtFramewo == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart4 */
    MSupGesamtFramework_DWork.is_active_c14_MSupGesamtFramewo = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart4 */
    /* Transition: '<S8>:3' */
    MSupGesamtFramework_DWork.is_c14_MSupGesamtFramework =
      MSupGesamtFramework_IN_x0;
  } else {
    switch (MSupGesamtFramework_DWork.is_c14_MSupGesamtFramework) {
     case MSupGesamtFra_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S8>:17' */
      /* Transition: '<S8>:24' */
      MSupGesamtFramework_DWork.is_c14_MSupGesamtFramework =
        MSupGesamtFramework_IN_x1_1;

      /* Entry 'x1_1': '<S8>:26' */
      MSupGesamtFramework_B.int16a1_bin[0] = rtb_IntegertoBitConverter5[0];
      MSupGesamtFramework_B.int16a1_bin[1] = rtb_IntegertoBitConverter5[1];
      MSupGesamtFramework_B.int16a1_bin[2] = rtb_IntegertoBitConverter5[2];
      MSupGesamtFramework_B.int16a1_bin[3] = rtb_IntegertoBitConverter5[3];
      MSupGesamtFramework_B.int16a1_bin[4] = rtb_IntegertoBitConverter5[4];
      MSupGesamtFramework_B.int16a1_bin[5] = rtb_IntegertoBitConverter5[5];
      MSupGesamtFramework_B.int16a1_bin[6] = rtb_IntegertoBitConverter5[6];
      MSupGesamtFramework_B.int16a1_bin[7] = rtb_IntegertoBitConverter5[7];
      MSupGesamtFramework_B.int16a1_bin[8] = rtb_IntegertoBitConverter6[0];
      MSupGesamtFramework_B.int16a1_bin[9] = rtb_IntegertoBitConverter6[1];
      MSupGesamtFramework_B.int16a1_bin[10] = rtb_IntegertoBitConverter6[2];
      MSupGesamtFramework_B.int16a1_bin[11] = rtb_IntegertoBitConverter6[3];
      MSupGesamtFramework_B.int16a1_bin[12] = rtb_IntegertoBitConverter6[4];
      MSupGesamtFramework_B.int16a1_bin[13] = rtb_IntegertoBitConverter6[5];
      MSupGesamtFramework_B.int16a1_bin[14] = rtb_IntegertoBitConverter6[6];
      MSupGesamtFramework_B.int16a1_bin[15] = rtb_IntegertoBitConverter6[7];
      break;

     case MSupGesamtFramework_IN_x0:
      /* During 'x0': '<S8>:2' */
      /* Transition: '<S8>:7' */
      MSupGesamtFramework_DWork.is_c14_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S8>:26' */
      /* Transition: '<S8>:25' */
      MSupGesamtFramework_DWork.is_c14_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart4' */

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter2' */
  /* Bit to Integer Conversion */
  bitIdx = 0L;
  intVal = 0L;
  for (j = 0; j < 16; j++) {
    /* Input bit order is MSB first */
    intVal <<= 1UL;
    intVal |= (int32_T)(real32_T)floor(MSupGesamtFramework_B.int16a1_bin[bitIdx]);
    if ((j == 0) && (intVal != 0L)) {
      /* Output Integer values are signed, do sign extension */
      intVal = -1L;
    }

    bitIdx++;
  }

  /* Chart: '<S2>/Chart1' */
  /* Integer to Bit Conversion */
  /* Integer to Bit Conversion */
  /* Gateway: Modul Positionswerte
     Sampletime = 0.01 s/Chart1 */
  /* During: Modul Positionswerte
     Sampletime = 0.01 s/Chart1 */
  if (MSupGesamtFramework_DWork.is_active_c11_MSupGesamtFramewo == 0U) {
    /* Entry: Modul Positionswerte
       Sampletime = 0.01 s/Chart1 */
    MSupGesamtFramework_DWork.is_active_c11_MSupGesamtFramewo = 1U;

    /* Entry Internal: Modul Positionswerte
       Sampletime = 0.01 s/Chart1 */
    /* Transition: '<S6>:3' */
    MSupGesamtFramework_DWork.is_c11_MSupGesamtFramework =
      MSupGesamtFramework_IN_x0;
  } else {
    switch (MSupGesamtFramework_DWork.is_c11_MSupGesamtFramework) {
     case MSupGesamtFra_IN_Daten_einlesen:
      /* During 'Daten_einlesen': '<S6>:17' */
      /* Transition: '<S6>:24' */
      MSupGesamtFramework_DWork.is_c11_MSupGesamtFramework =
        MSupGesamtFramework_IN_x1_1;

      /* Entry 'x1_1': '<S6>:26' */
      break;

     case MSupGesamtFramework_IN_x0:
      /* During 'x0': '<S6>:2' */
      /* Transition: '<S6>:7' */
      MSupGesamtFramework_DWork.is_c11_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;

     default:
      /* During 'x1_1': '<S6>:26' */
      /* Transition: '<S6>:25' */
      MSupGesamtFramework_DWork.is_c11_MSupGesamtFramework =
        MSupGesamtFra_IN_Daten_einlesen;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* DiscretePulseGenerator: '<S11>/Pulse Generator' */
  rtb_PulseGenerator = (MSupGesamtFramework_DWork.clockTickCounter <
                        MSupGesamtFramework_P.PulseGenerator_Duty) &&
    (MSupGesamtFramework_DWork.clockTickCounter >= 0L) ?
    MSupGesamtFramework_P.PulseGenerator_Amp : 0.0;
  if (MSupGesamtFramework_DWork.clockTickCounter >=
      MSupGesamtFramework_P.PulseGenerator_Period - 1.0) {
    MSupGesamtFramework_DWork.clockTickCounter = 0L;
  } else {
    MSupGesamtFramework_DWork.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S11>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<S11>/I2C Reinitialisierung' incorporates:
   *  TriggerPort: '<S13>/Trigger'
   */
  zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                     &MSupGesamtFramew_PrevZCSigState.I2CReinitialisierung_Trig_ZCE,
                     (rtb_PulseGenerator));
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
                     &MSupGesamtFramew_PrevZCSigState.I2CReset_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* MATLAB Function: '<S14>/I2C Reset' */
    /* MATLAB Function 'Modul Positionswerte Sampletime = 0.01 s/I2C Reset (behebt Stabilitätsprobleme der I2C-Verbindung)/I2C Reset/I2C Reset': '<S16>:1' */
    reset_i2c();
  }

  /* End of Outputs for SubSystem: '<S11>/I2C Reset' */

  /* MATLAB Function: '<S3>/Winkel und Distanz' incorporates:
   *  S-Function (scominttobit): '<S2>/Bit to Integer Converter2'
   */
  /* MATLAB Function 'Subsystem/Winkel und Distanz': '<S21>:1' */
  /* '<S21>:1:4' */
  x_dif = MSupGesamtFramework_B.x_soll - x_dif;

  /* '<S21>:1:5' */
  y_dif = MSupGesamtFramework_B.y_soll - y_dif;

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

  if (MSupGesamtFramework_B.rueck == 1.0F) {
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
    /* Update for UnitDelay: '<S3>/Unit Delay' */
    /* '<S21>:1:36' */
    /* '<S21>:1:37' */
    MSupGesamtFramework_DWork.UnitDelay_DSTATE = 1.0;
  } else {
    /* Update for UnitDelay: '<S3>/Unit Delay' */
    /* '<S21>:1:39' */
    MSupGesamtFramework_DWork.UnitDelay_DSTATE = 0.0;
  }

  /* Chart: '<S3>/Fahrt Modi' incorporates:
   *  MATLAB Function: '<S3>/Winkel und Distanz'
   */
  /* Gateway: Subsystem/Fahrt Modi */
  /* During: Subsystem/Fahrt Modi */
  if (MSupGesamtFramework_DWork.is_active_c2_MSupGesamtFramewor == 0U) {
    /* Entry: Subsystem/Fahrt Modi */
    MSupGesamtFramework_DWork.is_active_c2_MSupGesamtFramewor = 1U;

    /* Entry Internal: Subsystem/Fahrt Modi */
    /* Transition: '<S17>:8' */
    MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
      MSupGesamtFramework_IN_Stehen;

    /* Entry 'Stehen': '<S17>:7' */
  } else {
    switch (MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework) {
     case MSupGesamtFr_IN_GeradeausFahren:
      /* During 'GeradeausFahren': '<S17>:12' */
      if ((winkelVor < -10.0F) || (winkelVor > 10.0F) || (rtb_stop == 1)) {
        /* Transition: '<S17>:31' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFramework_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
      }
      break;

     case MSupGesamtFramew_IN_LinksDrehen:
      /* During 'LinksDrehen': '<S17>:9' */
      if (((winkelVor > -10.0F) && (winkelVor < 10.0F)) || (rtb_stop == 1) ||
          (distanz < 300.0F)) {
        /* Transition: '<S17>:33' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFramework_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
      } else {
        if (winkelVor < -10.0F) {
          /* Transition: '<S17>:41' */
          MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
            MSupGesamtFrame_IN_RechtsDrehen;

          /* Entry 'RechtsDrehen': '<S17>:10' */
        }
      }
      break;

     case MSupGesamtFrame_IN_RechtsDrehen:
      /* During 'RechtsDrehen': '<S17>:10' */
      if (((winkelVor > -10.0F) && (winkelVor < 10.0F)) || (rtb_stop == 1) ||
          (distanz < 300.0F)) {
        /* Transition: '<S17>:39' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFramework_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
      } else {
        if (winkelVor > 10.0F) {
          /* Transition: '<S17>:42' */
          MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
            MSupGesamtFramew_IN_LinksDrehen;

          /* Entry 'LinksDrehen': '<S17>:9' */
        }
      }
      break;

     case MSupGesamtFramew_IN_Rueckwaerts:
      /* During 'Rueckwaerts': '<S17>:43' */
      if ((winkelVor < -10.0F) || (winkelVor > 10.0F) || (rtb_stop == 1)) {
        /* Transition: '<S17>:46' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFramework_IN_Stehen;

        /* Entry 'Stehen': '<S17>:7' */
      }
      break;

     default:
      /* During 'Stehen': '<S17>:7' */
      if ((winkelVor > -10.0F) && (winkelVor < 10.0F) && (rtb_stop == 0) &&
          (MSupGesamtFramework_B.rueck == 0.0F)) {
        /* Transition: '<S17>:30' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFr_IN_GeradeausFahren;

        /* Entry 'GeradeausFahren': '<S17>:12' */
      } else if ((winkelVor > 10.0F) && (rtb_stop == 0)) {
        /* Transition: '<S17>:32' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFramew_IN_LinksDrehen;

        /* Entry 'LinksDrehen': '<S17>:9' */
      } else if ((winkelVor < -10.0F) && (rtb_stop == 0)) {
        /* Transition: '<S17>:34' */
        MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
          MSupGesamtFrame_IN_RechtsDrehen;

        /* Entry 'RechtsDrehen': '<S17>:10' */
      } else {
        if ((winkelVor > -10.0F) && (winkelVor < 10.0F) && (rtb_stop == 0) &&
            (MSupGesamtFramework_B.rueck == 1.0F)) {
          /* Transition: '<S17>:45' */
          MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
            MSupGesamtFramew_IN_Rueckwaerts;

          /* Entry 'Rueckwaerts': '<S17>:43' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Fahrt Modi' */

  /* Chart: '<S5>/Chart' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant11'
   */
  /* MATLAB Function 'Subsystem/Richtungs Wechsel M1 ': '<S18>:1' */
  /* MATLAB Function 'Subsystem/Richtungs Wechsel M2': '<S19>:1' */
  if (MSupGesamtFramework_DWork.temporalCounter_i1_l < 127U) {
    MSupGesamtFramework_DWork.temporalCounter_i1_l = ((int16_T)
      MSupGesamtFramework_DWork.temporalCounter_i1_l + 1) & 255U;
  }

  /* Gateway: Subsystem2/Chart */
  /* During: Subsystem2/Chart */
  if (MSupGesamtFramework_DWork.is_active_c9_MSupGesamtFramewor == 0U) {
    /* Entry: Subsystem2/Chart */
    MSupGesamtFramework_DWork.is_active_c9_MSupGesamtFramewor = 1U;

    /* Entry Internal: Subsystem2/Chart */
    /* Transition: '<S24>:7' */
    MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework =
      MSupGesamtFramewor_IN_warten_ah;

    /* Entry 'warten': '<S24>:6' */
    MSupGesamtFramework_B.angekommen = 0.0;
  } else {
    switch (MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework) {
     case MSupGesamtFramewo_IN_hochFahren:
      /* During 'hochFahren': '<S24>:8' */
      if (MSupGesamtFramework_P.Constant10_Value == 1.0) {
        /* Transition: '<S24>:11' */
        MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework =
          MSupGesamtFramework_IN_oben;
        MSupGesamtFramework_DWork.temporalCounter_i1_l = 0U;

        /* Entry 'oben': '<S24>:10' */
      }
      break;

     case MSupGesamtFramework_IN_oben:
      /* During 'oben': '<S24>:10' */
      if (MSupGesamtFramework_DWork.temporalCounter_i1_l >= 100U) {
        /* Transition: '<S24>:13' */
        MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework =
          MSupGesamtFrame_IN_runterFahren;

        /* Entry 'runterFahren': '<S24>:12' */
        MSupGesamtFramework_B.angekommen = 1.0;
      }
      break;

     case MSupGesamtFrame_IN_runterFahren:
      MSupGesamtFramework_B.angekommen = 1.0;

      /* During 'runterFahren': '<S24>:12' */
      if (MSupGesamtFramework_P.Constant11_Value == 1.0) {
        /* Transition: '<S24>:17' */
        MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework =
          MSupGesamtFramework_IN_unten;

        /* Entry 'unten': '<S24>:14' */
      }
      break;

     case MSupGesamtFramework_IN_unten:
      /* During 'unten': '<S24>:14' */
      break;

     default:
      MSupGesamtFramework_B.angekommen = 0.0;

      /* During 'warten': '<S24>:6' */
      if (MSupGesamtFramework_B.uebergabe == 1.0F) {
        /* Transition: '<S24>:9' */
        MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework =
          MSupGesamtFramewo_IN_hochFahren;

        /* Entry 'hochFahren': '<S24>:8' */
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Chart: '<S4>/Sensoren' incorporates:
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant13'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (MSupGesamtFramework_DWork.temporalCounter_i1_o < 31U) {
    MSupGesamtFramework_DWork.temporalCounter_i1_o = ((int16_T)
      MSupGesamtFramework_DWork.temporalCounter_i1_o + 1) & 255U;
  }

  /* Gateway: Subsystem1/Sensoren */
  /* During: Subsystem1/Sensoren */
  if (MSupGesamtFramework_DWork.is_active_c1_MSupGesamtFramewor == 0U) {
    /* Entry: Subsystem1/Sensoren */
    MSupGesamtFramework_DWork.is_active_c1_MSupGesamtFramewor = 1U;

    /* Entry Internal: Subsystem1/Sensoren */
    /* Transition: '<S22>:4' */
    MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
      MSupGesamtFramework_IN_warten_a;

    /* Entry 'warten': '<S22>:3' */
  } else {
    switch (MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework) {
     case MSupGesamtFramework_IN_Bunt:
      /* During 'Bunt': '<S22>:14' */
      if (MSupGesamtFramework_P.Constant12_Value == 1.0) {
        /* Transition: '<S22>:36' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramewo_IN_wartenkurz;
        MSupGesamtFramework_DWork.temporalCounter_i1_o = 0U;
      }
      break;

     case MSupGesamtFramework_IN_Farbe:
      /* During 'Farbe': '<S22>:29' */
      if (MSupGesamtFramework_P.Constant13_Value > 1000.0) {
        /* Transition: '<S22>:27' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramework_IN_blau;

        /* Entry 'blau': '<S22>:26' */
        MSupGesamtFramework_B.farbenStatus = 0.0;
      } else {
        if (MSupGesamtFramework_P.Constant13_Value < 1000.0) {
          /* Transition: '<S22>:28' */
          MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
            MSupGesamtFramework_IN_rot;

          /* Entry 'rot': '<S22>:24' */
          MSupGesamtFramework_B.farbenStatus = 1.0;
        }
      }
      break;

     case MSupGesamtFramework_IN_Schwarz:
      /* During 'Schwarz': '<S22>:12' */
      if (MSupGesamtFramework_P.Constant12_Value == 1.0) {
        /* Transition: '<S22>:17' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramewo_IN_wartenkurz;
        MSupGesamtFramework_DWork.temporalCounter_i1_o = 0U;
      }
      break;

     case MSupGesamtFr_IN_SchwarzOderBunt:
      /* During 'SchwarzOderBunt': '<S22>:19' */
      if (MSupGesamtFramework_P.Constant13_Value < 2200.0) {
        /* Transition: '<S22>:16' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramework_IN_Farbe;
      } else {
        if (MSupGesamtFramework_P.Constant13_Value > 2200.0) {
          /* Transition: '<S22>:15' */
          MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
            MSupGesamtFramework_IN_Schwarz;

          /* Entry 'Schwarz': '<S22>:12' */
        }
      }
      break;

     case MSupGesamtFramework_IN_blau:
      MSupGesamtFramework_B.farbenStatus = 0.0;

      /* During 'blau': '<S22>:26' */
      /* Transition: '<S22>:30' */
      MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
        MSupGesamtFramework_IN_warten4;
      break;

     case MSupGesamtFramework_IN_rot:
      MSupGesamtFramework_B.farbenStatus = 1.0;

      /* During 'rot': '<S22>:24' */
      /* Transition: '<S22>:31' */
      MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
        MSupGesamtFramework_IN_warten4;
      break;

     case MSupGesamtFramework_IN_warten_a:
      /* During 'warten': '<S22>:3' */
      if (MSupGesamtFramework_P.Constant12_Value == 0.0) {
        /* Transition: '<S22>:20' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramework_IN_warten3;
        MSupGesamtFramework_DWork.temporalCounter_i1_o = 0U;
      }
      break;

     case MSupGesamtFramework_IN_warten3:
      /* During 'warten3': '<S22>:42' */
      if (MSupGesamtFramework_DWork.temporalCounter_i1_o >= 20U) {
        /* Transition: '<S22>:43' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFr_IN_SchwarzOderBunt;
      }
      break;

     case MSupGesamtFramework_IN_warten4:
      /* During 'warten4': '<S22>:44' */
      if (MSupGesamtFramework_DWork.UnitDelay_DSTATE_o == 0.0F) {
        /* Transition: '<S22>:45' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramework_IN_Bunt;

        /* Entry 'Bunt': '<S22>:14' */
      }
      break;

     default:
      /* During 'wartenkurz': '<S22>:22' */
      if (MSupGesamtFramework_DWork.temporalCounter_i1_o >= 3U) {
        /* Transition: '<S22>:23' */
        MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
          MSupGesamtFramework_IN_warten_a;

        /* Entry 'warten': '<S22>:3' */
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Sensoren' */

  /* Chart: '<S4>/Weichen Steuerung' */
  if (MSupGesamtFramework_DWork.temporalCounter_i1_n < 31U) {
    MSupGesamtFramework_DWork.temporalCounter_i1_n = ((int16_T)
      MSupGesamtFramework_DWork.temporalCounter_i1_n + 1) & 255U;
  }

  /* Gateway: Subsystem1/Weichen Steuerung */
  /* During: Subsystem1/Weichen Steuerung */
  if (MSupGesamtFramework_DWork.is_active_c8_MSupGesamtFramewor == 0U) {
    /* Entry: Subsystem1/Weichen Steuerung */
    MSupGesamtFramework_DWork.is_active_c8_MSupGesamtFramewor = 1U;

    /* Entry Internal: Subsystem1/Weichen Steuerung */
    /* Transition: '<S23>:2' */
    MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework =
      MSupGesamtFramework_IN_blau_a;

    /* Update for UnitDelay: '<S4>/Unit Delay' */
    /* Entry 'blau': '<S23>:1' */
    MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 0.0F;
  } else {
    switch (MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework) {
     case MSupGesamtFramework_IN_blau_a:
      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 0.0F;

      /* During 'blau': '<S23>:1' */
      if (MSupGesamtFramework_B.farbenStatus == 1.0) {
        /* Transition: '<S23>:8' */
        MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework =
          MSupGesamtFrame_IN_rechtsdrehen;
        MSupGesamtFramework_DWork.temporalCounter_i1_n = 0U;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        /* Entry 'rechtsdrehen': '<S23>:6' */
        MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 1.0F;
      }
      break;

     case MSupGesamtFramew_IN_linksdrehen:
      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 1.0F;

      /* During 'linksdrehen': '<S23>:7' */
      if (MSupGesamtFramework_DWork.temporalCounter_i1_n >= 18U) {
        /* Transition: '<S23>:11' */
        MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework =
          MSupGesamtFramework_IN_blau_a;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        /* Entry 'blau': '<S23>:1' */
        MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 0.0F;
      }
      break;

     case MSupGesamtFrame_IN_rechtsdrehen:
      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 1.0F;

      /* During 'rechtsdrehen': '<S23>:6' */
      if (MSupGesamtFramework_DWork.temporalCounter_i1_n >= 18U) {
        /* Transition: '<S23>:9' */
        MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework =
          MSupGesamtFramework_IN_rot_a;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        /* Entry 'rot': '<S23>:4' */
        MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 0.0F;
      }
      break;

     default:
      /* Update for UnitDelay: '<S4>/Unit Delay' */
      MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 0.0F;

      /* During 'rot': '<S23>:4' */
      if (MSupGesamtFramework_B.farbenStatus == 0.0) {
        /* Transition: '<S23>:10' */
        MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework =
          MSupGesamtFramew_IN_linksdrehen;
        MSupGesamtFramework_DWork.temporalCounter_i1_n = 0U;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        /* Entry 'linksdrehen': '<S23>:7' */
        MSupGesamtFramework_DWork.UnitDelay_DSTATE_o = 1.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Weichen Steuerung' */

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  MSupGesamtFramework_DWork.UnitDelay1_DSTATE = MSupGesamtFramework_B.angekommen;
}

/* Model initialize function */
void MSupGesamtFramework_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(MSupGesamtFramework_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &MSupGesamtFramework_B), 0,
                sizeof(BlockIO_MSupGesamtFramework));

  /* states (dwork) */
  (void) memset((void *)&MSupGesamtFramework_DWork, 0,
                sizeof(D_Work_MSupGesamtFramework));

  {
    int16_T i;

    /* Start for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' incorporates:
     *  SubSystem: '<S2>/Triggered Subsystem'
     */
    /* Start for function-call system: '<S2>/Triggered Subsystem' */

    /* Start for S-Function (c280xi2c_rx): '<S12>/I2C Receive' */

    /* Initialize MSupGesamtFramework_B.I2CReceive_o1[0] */
    {
      MSupGesamtFramework_B.I2CReceive_o1[0] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[1] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[2] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[3] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[4] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[5] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[6] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[7] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[8] = (uint8_T)0.0;
      MSupGesamtFramework_B.I2CReceive_o1[9] = (uint8_T)0.0;
    }

    MSupGesamtFramew_PrevZCSigState.I2CReinitialisierung_Trig_ZCE =
      UNINITIALIZED_ZCSIG;
    MSupGesamtFramew_PrevZCSigState.I2CReset_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    MSupGesamtFramework_DWork.UnitDelay_DSTATE =
      MSupGesamtFramework_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
    MSupGesamtFramework_DWork.UnitDelay1_DSTATE =
      MSupGesamtFramework_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for RateTransition: '<S2>/Rate Transition' */
    for (i = 0; i < 20; i++) {
      MSupGesamtFramework_DWork.RateTransition_Buffer[i] =
        MSupGesamtFramework_P.RateTransition_InitialCondition;
    }

    /* End of InitializeConditions for RateTransition: '<S2>/Rate Transition' */

    /* InitializeConditions for DiscretePulseGenerator: '<S11>/Pulse Generator' */
    MSupGesamtFramework_DWork.clockTickCounter = 0L;

    /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
    MSupGesamtFramework_DWork.UnitDelay_DSTATE_o =
      MSupGesamtFramework_P.UnitDelay_InitialCondition_k;

    /* SystemInitialize for Chart: '<S3>/Strecken Koordinaten' */
    MSupGesamtFramework_DWork.is_active_c6_MSupGesamtFramewor = 0U;
    MSupGesamtFramework_DWork.is_c6_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    MSupGesamtFramework_DWork.temporalCounter_i1 = 0U;
    MSupGesamtFramework_DWork.is_active_c3_MSupGesamtFramewor = 0U;
    MSupGesamtFramework_DWork.is_c3_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' incorporates:
     *  SubSystem: '<S2>/Triggered Subsystem'
     */
    /* System initialize for function-call system: '<S2>/Triggered Subsystem' */
    {
      int16_T i;

      /* InitializeConditions for Delay: '<S12>/Delay' */
      for (i = 0; i < 10; i++) {
        MSupGesamtFramework_DWork.Delay_DSTATE[i] =
          MSupGesamtFramework_P.Delay_InitialCondition;
      }

      /* End of InitializeConditions for Delay: '<S12>/Delay' */
    }

    /* End of SystemInitialize for S-Function (c28xisr_c2000): '<S2>/C28x Hardware Interrupt' */

    /* SystemInitialize for Chart: '<S2>/Chart8' */
    MSupGesamtFramework_DWork.is_active_c17_MSupGesamtFramewo = 0U;
    MSupGesamtFramework_DWork.is_c17_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;
    for (i = 0; i < 20; i++) {
      MSupGesamtFramework_DWork.values_out1[i] = 0;
    }

    MSupGesamtFramework_DWork.zaehler = 0L;
    MSupGesamtFramework_DWork.search = 0;
    MSupGesamtFramework_DWork.counter = 0L;
    MSupGesamtFramework_DWork.x_found = 0L;
    MSupGesamtFramework_B.valid_values1 = 0;
    MSupGesamtFramework_B.valid_values2 = 0;
    MSupGesamtFramework_B.valid_values3 = 0;
    MSupGesamtFramework_B.valid_values4 = 0;
    MSupGesamtFramework_B.valid_values5 = 0;
    MSupGesamtFramework_B.valid_values6 = 0;

    /* End of SystemInitialize for Chart: '<S2>/Chart8' */

    /* SystemInitialize for Chart: '<S2>/Chart6' */
    MSupGesamtFramework_DWork.is_active_c16_MSupGesamtFramewo = 0U;
    MSupGesamtFramework_DWork.is_c16_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S2>/Chart2' */
    MSupGesamtFramework_DWork.is_active_c13_MSupGesamtFramewo = 0U;
    MSupGesamtFramework_DWork.is_c13_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S2>/Chart4' */
    MSupGesamtFramework_DWork.is_active_c14_MSupGesamtFramewo = 0U;
    MSupGesamtFramework_DWork.is_c14_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;
    for (i = 0; i < 16; i++) {
      /* SystemInitialize for Chart: '<S2>/Chart6' */
      MSupGesamtFramework_B.int16x_bin[i] = 0.0F;

      /* SystemInitialize for Chart: '<S2>/Chart2' */
      MSupGesamtFramework_B.int16y_bin[i] = 0.0F;

      /* SystemInitialize for Chart: '<S2>/Chart4' */
      MSupGesamtFramework_B.int16a1_bin[i] = 0.0F;
    }

    /* SystemInitialize for Chart: '<S2>/Chart1' */
    MSupGesamtFramework_DWork.is_active_c11_MSupGesamtFramewo = 0U;
    MSupGesamtFramework_DWork.is_c11_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S3>/Fahrt Modi' */
    MSupGesamtFramework_DWork.is_active_c2_MSupGesamtFramewor = 0U;
    MSupGesamtFramework_DWork.is_c2_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S5>/Chart' */
    MSupGesamtFramework_DWork.temporalCounter_i1_l = 0U;
    MSupGesamtFramework_DWork.is_active_c9_MSupGesamtFramewor = 0U;
    MSupGesamtFramework_DWork.is_c9_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S4>/Sensoren' */
    MSupGesamtFramework_DWork.temporalCounter_i1_o = 0U;
    MSupGesamtFramework_DWork.is_active_c1_MSupGesamtFramewor = 0U;
    MSupGesamtFramework_DWork.is_c1_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;

    /* SystemInitialize for Chart: '<S4>/Weichen Steuerung' */
    MSupGesamtFramework_DWork.temporalCounter_i1_n = 0U;
    MSupGesamtFramework_DWork.is_active_c8_MSupGesamtFramewor = 0U;
    MSupGesamtFramework_DWork.is_c8_MSupGesamtFramework =
      MSupGesamtFr_IN_NO_ACTIVE_CHILD;
  }
}

/* Model terminate function */
void MSupGesamtFramework_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
