#include "i2c_reset.h"

#define MST 10
#define XA 8
#define BC 0
#define FDF 3
#define IRS 5

#define RXFFIENA 5
#define RXFFIL 0
#define RXFFINTCLR 6

void init_i2c( void ) {
    /* Initialize I2C */

    uint16_T* I2CMDR  = (uint16_T*)0x7909;    /* I2CMDR register address */
    uint16_T* I2COAR  = (uint16_T*)0x7900;    /* I2COAR register address */
    uint16_T* I2CFFRX = (uint16_T*)0x7921;    /* I2CFFRX register address */
    uint16_T* I2CFFTX = (uint16_T*)0x7920;    /* I2CFFTX register address */

    *I2CMDR &= ~( 1 << MST );                 /* Select master or slave mode*/
    *I2COAR = 9;                              /* Set own address*/
    *I2CMDR &= ~( 1 << XA );                  /* Expanded address bit (1:Enable 0:Disable)*/
    *I2CMDR &= ~( 1 << BC );                  /* Set bit count bits*/
    *I2CMDR &= ~( 1 << FDF );                 /* Free data mode (1:Enable 0:Disable)*/
    *I2CFFRX |= ( 1 << RXFFIENA );            /* Enable Rx Fifo interrupt*/
    *I2CFFRX &= ~( 0x1f << RXFFIL );          /* Clear fifo interrupt level*/
    *I2CFFRX |= ( 10 << RXFFIL );             /* Set fifo interrupt level*/
    *I2CFFRX |= (1 << RXFFINTCLR );           /* Clear Rx interrupt flag*/
    *I2CFFRX |= 0x6000;                       /* Enable TxFIFO mode*/
    *I2CFFRX |= 0x2000;                       /* Enable RxFIFO mode*/
    *I2CMDR |= ( 1 << IRS );                  /* Take I2C out of reset*/
}

void reset_i2c( void ) {
    /* Reset I2C */
    
    uint16_T* I2CMDR  = (uint16_T*)0x7909;    /* I2CMDR register address */

    *I2CMDR &= ~( 1 << IRS );                 /* I2C reset*/
}
