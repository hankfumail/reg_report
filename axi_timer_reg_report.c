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
#include "xtmrctr_l.h"


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
void axi_timer_cntrl_sts_register_report( u32 u32_reg_value, char *ps_reg_name, reg_defintion_st *p_reg_info  )
{

    u32     u32_temp=0;


    static reg_defintion_st     mb_msr_reg_definition[] =
    {
        /*     Type                    shift_right_num            mask         value     name                    info          */
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "Timer 0 Mode", " Timer mode is capture" },
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x0, "Timer 0 Mode", " Timer mode is generate" },
        {  REG_BITS_TYPE_CHECK,      1,         0x1,        0x1, "Up/Down Count Timer 0", "Timer functions as Down counter" },
        {  REG_BITS_TYPE_CHECK,      1,         0x1,        0x0, "Up/Down Count Timer 0", "Timer functions as up counter" },
        {  REG_BITS_TYPE_CHECK,      4,         0x1,        0x1, "Auto Reload/Hold Timer 0", "Reload generate value or overwrite capture value" },
        {  REG_BITS_TYPE_CHECK,      4,         0x1,        0x0, "Auto Reload/Hold Timer 0", " Hold counter or capture value" },
        {  REG_BITS_TYPE_CHECK,      5,         0x1,        0x1, "Load Timer 0", "Loads timer with value in TLR0" },
        {  REG_BITS_TYPE_CHECK,      5,         0x1,        0x0, "Load Timer 0", "No load" },
        {  REG_BITS_TYPE_CHECK,      6,         0x1,        0x1, "Enable Interrupt for Timer 0", "Disable interrupt signal" },
        {  REG_BITS_TYPE_CHECK,      6,         0x1,        0x0, "Enable Interrupt for Timer 0", "Enable interrupt signal" },
        {  REG_BITS_TYPE_CHECK,      7,         0x1,        0x1, "Enable Timer 0", "Enable timer (counter runs)" },
        {  REG_BITS_TYPE_CHECK,      7,         0x1,        0x0, "Enable Timer 0", "Disable timer (counter halts)" },
        {  REG_BITS_TYPE_CHECK,      8,         0x1,        0x1, "Timer 0 Interrupt(Write 1 to clear)", "Interrupt has occurred" },
        {  REG_BITS_TYPE_CHECK,      8,         0x1,        0x0, "Timer 0 Interrupt(Write 1 to clear)", "No interrupt has occurred" },
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "Pulse Width Modulation for Timer 0", "Enabled" },
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x0, "Pulse Width Modulation for Timer 0", "Disabled" },
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "Enable All Timers", "Enabled" },
        //{  REG_BITS_TYPE_CHECK,      0,         0x1,        0x0, "", "" },
        {  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "cascade mode of timers", "Enabled" },
        //{  REG_BITS_TYPE_CHECK,      0,         0x1,        0x0, "cascade mode of timers", "" },
        //{  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "", "" },
        //{  REG_BITS_TYPE_CHECK,      0,         0x1,        0x0, "", "" },
        {  0xffffffff,  0xffffffff,  0xffffffff, 0xffffffff, "", "" }
    };

    register_report( u32_temp, "Timer 0 Control/Status Register", mb_msr_reg_definition );
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
void axi_timer_reg_report( u32 u32_base  )
{

    u32     u32_temp=0;

    printf("\n\r");

	u32_temp = XIo_In32( u32_base + XTC_TCSR_OFFSET);
    xil_printf("Control/Status Register(R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XTC_TLR_OFFSET);
    xil_printf("Load Register(R/W): 0x%08x\n\r", u32_temp);

	u32_temp = XIo_In32( u32_base + XTC_TCR_OFFSET);
    xil_printf("Timer counter Register(R/W): 0x%08x\n\r", u32_temp);


    if( 0 != (u32_temp&1) )
    {
        xil_printf("\n\r");
    }
    else
    {
        xil_printf("\n\r");
    }


    if( 0 != (u32_temp&1) )
    {
        xil_printf("\n\r");
    }
    else
    {
        xil_printf("\n\r");
    }


    if( 0 != (u32_temp&1) )
    {
        xil_printf("\n\r");
    }
    else
    {
        xil_printf("\n\r");
    }


    if( 0 != (u32_temp&1) )
    {
        xil_printf("\n\r");
    }
    else
    {
        xil_printf("\n\r");
    }


    printf("\n\r");

}




