// 
// All data and information contained in or disclosed by this document are
// confidential and proprietary information of QUALCOMM Incorporated, and all
// rights therein are expressly reserved. By accepting this material, the
// recipient agrees that this material and the information contained therein are
// held in confidence and in trust and will not be used, copied, reproduced in
// whole or in part, nor its contents revealed in any manner to others without
// the express written permission of QUALCOMM Incorporated.
// 
// This technology was exported from the United States in accordance with the
// Export Administration Regulations. Diversion contrary to U.S. law prohibited.
// ------------------------------------------------------------------------------


/**
* @brief include file for Cortex M3 library
*
* @file  cm3_lib.h
* @author Anand Acharya
* @date Fri Aug 12 12:08:15 2011
*
* @version
* $Revision: 1.2 $
* @par Last check in date:
* $Date: Thu Dec 15 17:48:25 2011 $
* @par Last check in by:
* $Author: acharya $
*/

#ifndef __CM3_LIB_INCLUDED__
#define __CM3_LIB_INCLUDED__

#include <stdint.h>
#include <string.h>
#include "ARMCM3.h"
#include "core_cm3.h"
#include "core_cmInstr.h"
#include "core_cmFunc.h"

typedef void (* vv_int_func_type)(void);

static const uint32_t ipsr_mask = 0x000003FF;
static const uint32_t vecTableSize = 256;

#endif
