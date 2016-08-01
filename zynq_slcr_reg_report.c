/******************************************************************************
*
* (c) Copyright 2013 Xilinx, Inc. All rights reserved.
*
* This file contains confidential and proprietary information of Xilinx, Inc.
* and is protected under U.S. and international copyright and other
* intellectual property laws.
*
* DISCLAIMER
* This disclaimer is not a license and does not grant any rights to the
* materials distributed herewith. Except as otherwise provided in a valid
* license issued to you by Xilinx, and to the maximum extent permitted by
* applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL
* FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS,
* IMPLIED, OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF
* MERCHANTABILITY, NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE;
* and (2) Xilinx shall not be liable (whether in contract or tort, including
* negligence, or under any other theory of liability) for any loss or damage
* of any kind or nature related to, arising under or in connection with these
* materials, including for any direct, or any indirect, special, incidental,
* or consequential loss or damage (including loss of data, profits, goodwill,
* or any type of loss or damage suffered as a result of any action brought by
* a third party) even if such damage or loss was reasonably foreseeable or
* Xilinx had been advised of the possibility of the same.
*
* CRITICAL APPLICATIONS
* Xilinx products are not designed or intended to be fail-safe, or for use in
* any application requiring fail-safe performance, such as life-support or
* safety devices or systems, Class III medical devices, nuclear facilities,
* applications related to the deployment of airbags, or any other applications
* that could lead to death, personal injury, or severe property or
* environmental damage (individually and collectively, "Critical
* Applications"). Customer assumes the sole risk and liability of any use of
* Xilinx products in Critical Applications, subject only to applicable laws
* and regulations governing limitations on product liability.
*
* THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE
* AT ALL TIMES.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file Mb_stack_unwind.c
*
* This file contains a design example using the MicroBlaze exception features.
*
* @note		None.
*
* <pre>
*
* MODIFICATION HISTORY:
*
* Ver       Who       Date               Changes
* -----   ----     --------    ---------------------------------------------
* 1.00a    Hank     03/10/14       First release
* </pre>
*
******************************************************************************/

/***************************** Include Files *********************************/

#include "xil_cache.h"
#include "xil_io.h"
#include "xil_types.h"

#include "dbg_print.h"
#include "reg_report.h"

#include "zynq_slcr_reg_report.h"



/************************** Constant Definitions *****************************/



/**************************** Type Definitions *******************************/



/***************** Macros (Inline Functions) Definitions *********************/


/************************** Variable Definitions *****************************/





/************************** Function Prototypes ******************************/




/************************** Function Implementation ******************************/





void mctrl_report( void )
{

    unsigned int ui_reg;


    static reg_defintion_st  zynq_mctrl_reg_definition[] =
    {
        /*     Type                    shift_right_num            mask         value     name                    info          */
        {  REG_BITS_TYPE_SHOW_DEC,      28,         0xf,        0x1, "Version ID for silicon", "" },
         //{  REG_BITS_TYPE_CHECK,      0,         0x1,        0x1, "", "" },
        //{  REG_BITS_TYPE_CHECK,      0,         0x1,        0x0, "", "" },
        //{  REG_BITS_TYPE_SHOW_DEC,      0,         0x1,        0x0, "", "" },
        {  0xffffffff,  0xffffffff,  0xffffffff, 0xffffffff, "", "" }
    };



    ui_reg = Xil_In32( 0xF8007080 );
	xil_printf("0xF8007080(Miscellaneous control Register):\t%08x\n\r", ui_reg);

    register_report( ui_reg, "Zynq Miscellaneous control Register", zynq_mctrl_reg_definition );

}

