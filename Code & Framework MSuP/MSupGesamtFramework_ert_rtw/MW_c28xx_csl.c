#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "MSupGesamtFramework.h"
#include "MSupGesamtFramework_private.h"

void enableExtInterrupt (void);
void disableWatchdog(void)
{
  int *WatchdogWDCR = (void *) 0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void I2CINT2A_isr(void)
{
  volatile unsigned int i2cRxFifoIntFlag_save = I2caRegs.I2CFFRX.bit.RXFFINT;
  isr_int8pie2_task_fcn();
  I2caRegs.I2CFFRX.bit.RXFFINTCLR = i2cRxFifoIntFlag_save;/* Clear Rx fifo int flag*/
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;/* Acknowledge to receive more interrupts*/
}

void enable_interrupts()
{
  EALLOW;
  PieVectTable.I2CINT2A = &I2CINT2A_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER8.bit.INTx2 = 1;   /* Enable interrupt I2CINT2A*/
  IER |= M_INT8;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                                /* Enable Global realtime interrupt DBGM*/
}

void configureGPIOExtInterrupt (void)
{
}

void enableExtInterrupt (void)
{
}
