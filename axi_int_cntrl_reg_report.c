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
#include "xintc_l.h"


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
void axi_intc_register_report( u32 u32_reg_value, char *ps_reg_name, reg_defintion_st *p_reg_info  )
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
void axi_intc_reg_report( u32 u32_base  )
{

    u32     u32_temp=0;

    printf("\n\r");

	u32_temp = XIo_In32( u32_base + XIN_ISR_OFFSET);
    xil_printf("Interrupt Status Register(Each 1 stands for active interrupt, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_IPR_OFFSET);
    xil_printf("Interrupt Pending Register(Each 1 stands for pending interrupt, R): 0x%08x", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_IER_OFFSET);
    xil_printf("Interrupt Enable Register(Each 1 stands for enabled interrupt, R/W): 0x%08x\n\r", u32_temp);
    
	//u32_temp = XIo_In32( u32_base + XIN_IAR_OFFSET);
    //xil_printf("Interrupt Acknowledge Register(Write 1 to clear interrupt, Write only): 0x%08x", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_SIE_OFFSET);
    xil_printf("Set Interrupt Enable Register(Write 1 to enable interrupt, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_CIE_OFFSET);
    xil_printf("Clear Interrupt Enable Register(Write 1 to disable interrupt, R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_IVR_OFFSET);
    xil_printf("Interrupt Vector Register(Interrupt of the highest priority): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_MER_OFFSET);
    xil_printf("Master Enable  Register: 0x%08x\n\r", u32_temp);
    if( 0 != (u32_temp&1) )
    {
        xil_printf("Enabled the Irq output signal\n\r");
    }
    else
    {
        xil_printf("Disabled the Irq output signal\n\r");
    }

    if( 0 != (u32_temp&2) )
    {
        xil_printf("Only the hardware could generate interrupts\n\r");
    }
    else
    {
        xil_printf("Allowed software to write to the ISR to generate interrupts\n\r");
    }


	u32_temp = XIo_In32( u32_base + XIN_IMR_OFFSET);
    xil_printf("Interrupt Mode Register: 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XIN_IVAR_OFFSET);
    xil_printf("Interrupt Vector Address Register: 0x%08x\n\r", u32_temp);

    printf("\n\r");

}




