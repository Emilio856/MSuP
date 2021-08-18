#include "c2000BoardSupport.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "MSupGesamt.h"
#include "MSupGesamt_private.h"

void init_I2C_GPIO(void)
{
  EALLOW;                              /* Initial I2C GPIO pin*/
  GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;  /* Enable pull-up for GPIO32 (SDAA)*/
  GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;  /* Enable pull-up for GPIO33 (SCLA)*/
  GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1; /* Configure GPIO32 for SDAA operation*/
  GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1; /* Configure GPIO33 for SCLA operation*/
  EDIS;
}

void init_I2C_A(void)
{
  /* Initialize I2C*/
  EALLOW;
  EDIS;
  I2caRegs.I2CMDR.bit.MST = 0;         /* Select master or slave mode*/
  I2caRegs.I2COAR = 9;                 /* Set own address*/
  I2caRegs.I2CMDR.bit.XA = 0;          /* Expanded address bit (1:Enable 0:Disable)*/
  I2caRegs.I2CMDR.bit.BC = 0;          /* Set bit count bits*/
  I2caRegs.I2CMDR.bit.FDF = 0;         /* Free data mode (1:Enable 0:Disable)*/
  I2caRegs.I2CFFRX.bit.RXFFIENA = 1;   /* Enable Rx Fifo interrupt*/
  I2caRegs.I2CFFRX.bit.RXFFIL = 10;    /* Set fifo interrupt level*/
  I2caRegs.I2CFFRX.bit.RXFFINTCLR = 1; /* Clear Rx interrupt flag*/
  I2caRegs.I2CFFTX.all |= 0x6000;      /* Enable TxFIFO mode*/
  I2caRegs.I2CFFRX.all |= 0x2000;      /* Enable RxFIFO mode*/
  I2caRegs.I2CMDR.bit.IRS = 1;         /* Take I2C out of reset*/
}
