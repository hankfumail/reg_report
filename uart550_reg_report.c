/*
 * Copyright (c) 2009 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */


#include <stdio.h>

//#include "sleep.h"


#include "xil_types.h"
#include "xil_io.h"

#include "reg_report.h"
#include "dbg_print.h"


#include "xio.h"
#include "xuartns550_l.h"



/***************** Macros (Inline Functions) Definitions *********************/




/**************************** Type Definitions *******************************/



/************************** Constant Definitions *****************************/



/************************** Variable Definitions *****************************/



/************************** Function Prototypes ******************************/



/************************** Function Implementation ******************************/










/****************************************************************************
*
* Read and report Auxiliary Control Register.
*
* @param    None.
*
* @return    None.
*
* @note        None.
*
****************************************************************************/
void uart550_int_register_report( u32 u32_reg_value, char *ps_reg_name, reg_defintion_st *p_reg_info  )
{
    u32     u32_temp=0;


    static reg_defintion_st     mb_msr_reg_definition[] =
    {
        /*     Type                    shift_right_num            mask         value     name                    info          */
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "Arithmetic Carry Copy", "Carry (No Borrow) Copy" },
        {  0xffffffff,  0xffffffff,  0xffffffff, 0xffffffff, "", "" }
    };

    register_report( u32_temp, "MicroBlaze Machine Status Register", mb_msr_reg_definition );
    printf("\n\r");


}




/****************************************************************************
*
* Read and report Auxiliary Control Register.
*
* @param    None.
*
* @return    None.
*
* @note        None.
*
****************************************************************************/
void uart550_reg_report( u32 u32_base  )
{
    u32     u32_temp=0;

    printf("\n\r");

	//u32_temp = XIo_In32( u32_base + XUN_RBR_OFFSET );
    //xil_printf("Receive buffer Register(R): 0x%08x\n\r", u32_temp);

	//u32_temp = XIo_In32( u32_base + XUN_THR_OFFSET );
    //xil_printf("Transmit holding Register(W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XUN_IER_OFFSET );
    xil_printf("Interrupt enable Register(R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XUN_IIR_OFFSET );
    xil_printf("Interrupt id Register(R/W): 0x%08x\n\r", u32_temp);
    if( 0 != (u32_temp&1) )
    {
        xil_printf("Interrupt is pending\n\r");
        u32_temp &= 0x0e;
        if( 0 == u32_temp )
        {
            xil_printf("Modem status interrupt.\n\r");
        }
        else if( 2 == u32_temp )
        {
            xil_printf("Transmitter Holding Register Empty.\n\r");
        }
        else if( 4 == u32_temp )
        {
            xil_printf("Character Timeout .\n\r");
        }
        else if( 8 == u32_temp )
        {
            xil_printf("Received Data Available.\n\r");
        }
        else 
        {
            xil_printf("Receiver Line Status.\n\r");
        }
    }


	u32_temp = XIo_In32( u32_base + XUN_FCR_OFFSET );
    xil_printf("Fifo control Register(Write only): 0x%08x\n\r", u32_temp);
    if( 0 != (u32_temp&1) )
    {
        xil_printf("FIFO enabled.\n\r");
    }
    
	u32_temp = XIo_In32( u32_base + XUN_LCR_OFFSET );
    xil_printf("Line Control  Register(, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XUN_MCR_OFFSET );
    xil_printf("Modem Control Register(, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XUN_LSR_OFFSET );
    xil_printf("Line Status Register(, R/W): 0x%08x\n\r", u32_temp);
    if( 0 != (u32_temp&0x1) )
    {
        xil_printf("Data Ready.\n\r");
    }
    if( 0 != (u32_temp&0x2) )
    {
        xil_printf("Overrun Error.\n\r");
    }
    if( 0 != (u32_temp&0x4) )
    {
        xil_printf("Parity Error.\n\r");
    }
    if( 0 != (u32_temp&0x8) )
    {
        xil_printf("Framing Error.\n\r");
    }
    if( 0 != (u32_temp&0x10) )
    {
        xil_printf("Break Interrupt.\n\r");
    }
    if( 0 != (u32_temp&0x20) )
    {
        xil_printf("Transmitter Holding Register Empty.\n\r");
    }
    if( 0 != (u32_temp&0x40) )
    {
        xil_printf("Transmitter Empty.\n\r");
    }
    if( 0 != (u32_temp&0x80) )
    {
        xil_printf("Error in RCVR FIFO.\n\r");
    }

	u32_temp = XIo_In32( u32_base + XUN_MSR_OFFSET );
    xil_printf("Modem Status Register(, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XUN_DRLS_OFFSET );
    xil_printf("Divisor LSB Register(, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XUN_DRLM_OFFSET );
    xil_printf("Divisor MSB Register(, R/W): 0x%08x\n\r", u32_temp);

    if( 0 != (u32_temp&2) )
    {
        xil_printf("Only the hardware could generate interrupts\n\r");
    }
    else
    {
        xil_printf("Allowed software to write to the ISR to generate interrupts\n\r");
    }

    printf("\n\r");

}




