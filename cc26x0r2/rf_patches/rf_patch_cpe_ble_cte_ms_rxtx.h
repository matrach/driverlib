/******************************************************************************
*  Filename:       rf_patch_cpe_ble_cte_ms_rxtx.h
*  Revised:        $Date: 2019-08-23 12:24:13 +0200 (Fri, 23 Aug 2019) $
*  Revision:       $Revision: 19131 $
*
*  Description: RF core patch for Bluetooth 5.1 style locationing support with CTE aware receiver for master and slave
*
*  Copyright (c) 2015-2019, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/
#ifndef _RF_PATCH_CPE_BLE_CTE_MS_RXTX_H
#define _RF_PATCH_CPE_BLE_CTE_MS_RXTX_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <string.h>

#ifndef CPE_PATCH_TYPE
#define CPE_PATCH_TYPE static const uint32_t
#endif

#ifndef SYS_PATCH_TYPE
#define SYS_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC static inline
#endif

#ifndef _APPLY_PATCH_TAB
#define _APPLY_PATCH_TAB
#endif


CPE_PATCH_TYPE patchImageBleCteMsRxtx[] = {
   0x210004f5,
   0x21000749,
   0x210007e1,
   0x210007f5,
   0x4801b430,
   0x00004700,
   0x00009e6d,
   0x4c01b510,
   0x47084901,
   0x21000144,
   0x0000a5c3,
   0x4c02b5f8,
   0x4e022500,
   0x47004802,
   0x21000144,
   0x40045040,
   0x0000a537,
   0x4801b510,
   0x00004700,
   0x000009d5,
   0x01c0b570,
   0x47204c00,
   0x000046d5,
   0xb5104859,
   0x31204601,
   0x34604604,
   0x75a27bca,
   0x73c82002,
   0x47804855,
   0xd1182800,
   0x06097de1,
   0x4953d515,
   0x7fcb4a53,
   0x07896951,
   0x4952d1fc,
   0x495261cb,
   0x62cb2307,
   0x69542305,
   0xd1fc07a4,
   0x421c6b8c,
   0x4a4bd0f9,
   0x68123240,
   0xbd10624a,
   0xb5104845,
   0x31604601,
   0x7d89460a,
   0x5419232f,
   0xd00f2902,
   0x7fc94942,
   0xd0112900,
   0x0ec906c9,
   0x2b121e8b,
   0x7d03d81d,
   0x43232420,
   0x20807503,
   0xe0174301,
   0xff96f7ff,
   0xd0002800,
   0xbd102001,
   0x06897d01,
   0x6a01d50d,
   0xdd0a2901,
   0x78496e81,
   0x0ec906c9,
   0x2b121e8b,
   0x7d43d803,
   0x75431e5b,
   0x2100e000,
   0x200075d1,
   0xb5f0bd10,
   0x4d30492a,
   0x3460460c,
   0x28007de0,
   0x26ffd04a,
   0xd01a28ff,
   0x06024b2c,
   0x68cad401,
   0x4a23e008,
   0x7bdf0640,
   0x68d20e40,
   0xd0082f01,
   0x60ca3220,
   0x19d20147,
   0x7bda60ca,
   0xd0022a01,
   0x3210e003,
   0x0640e7f5,
   0x62480e00,
   0x202f75e6,
   0x02004b1c,
   0x4c1e6358,
   0x27146a48,
   0x07d26b9a,
   0x220fd010,
   0xe00362da,
   0xdd072801,
   0x1e80625c,
   0xdd192800,
   0x07d26b9a,
   0xe005d1f6,
   0x62d82007,
   0xe011625e,
   0xdd0f2800,
   0x423a6b9a,
   0x4a0ad0e6,
   0x7b523a60,
   0x635a0212,
   0x22084b0e,
   0x4b0e601a,
   0x6248601a,
   0xbdf02001,
   0x640d2000,
   0x0000bdf0,
   0x21000144,
   0x00009eb7,
   0x210000a8,
   0x40042000,
   0x40042100,
   0x40045040,
   0x0000a2fb,
   0x21000164,
   0x0000ffff,
   0xe000e280,
   0xe000e100,
   0x483eb5f8,
   0x2200493c,
   0x26226342,
   0x6b849200,
   0x42334623,
   0x07a3d0fb,
   0x4838d546,
   0x48386a83,
   0x483863c3,
   0x07806940,
   0x4836d1fb,
   0x68003040,
   0x828bb283,
   0xd5050698,
   0x5c40202f,
   0xd0012802,
   0xe0002501,
   0x48302500,
   0x72420a1f,
   0x46bc4a2f,
   0x78d27890,
   0x42824038,
   0x1942db23,
   0x00d27e8f,
   0x18ba3210,
   0x617a4f25,
   0x62086248,
   0xd0132d00,
   0x63392107,
   0x46216bbc,
   0xd0fb4231,
   0xd50b07a1,
   0x491f6aba,
   0x491f61ca,
   0x0792694a,
   0x491dd1fc,
   0x68093140,
   0x72514a1c,
   0x4662b2d9,
   0xfecef7ff,
   0x2000e002,
   0x900043c0,
   0xd50106a0,
   0xbdf82001,
   0xf7ff9800,
   0xbdf8febb,
   0x4c0fb510,
   0xf83ff000,
   0xd1152800,
   0x7a514a10,
   0xd0112900,
   0x5d09212f,
   0x68e12901,
   0x3120d00d,
   0x7a5160e1,
   0x0ec906c9,
   0x2a131e8a,
   0x2102d300,
   0x014968e2,
   0x60e11851,
   0x3110bd10,
   0x0000e7f0,
   0x21000144,
   0x40045040,
   0x40042100,
   0x40042000,
   0x210000e0,
   0x210000c8,
   0x2801491e,
   0xd00c7108,
   0xd00c2804,
   0xd00c2807,
   0xd0042808,
   0x0080491a,
   0x68c01840,
   0x48194770,
   0x48194770,
   0x48194770,
   0x48194770,
   0xb5f84770,
   0x48184c12,
   0x46253c40,
   0x7b2f3560,
   0x732e2600,
   0x732f4780,
   0x43017b69,
   0x2f00d117,
   0x7e61d015,
   0xd00e2900,
   0x31204621,
   0x08537c0a,
   0xd10007db,
   0x6a237626,
   0x2b007b49,
   0x2304d101,
   0x42114319,
   0x7d21d002,
   0xd40006c9,
   0xbdf875e6,
   0x21000184,
   0x0000df80,
   0x210006f1,
   0x210004a5,
   0x2100055f,
   0x21000639,
   0x0000a767,
   0x4c03b510,
   0xfe52f7ff,
   0x28006820,
   0xbd10d1fa,
   0x40041100,
   0x480db510,
   0x6b406b84,
   0x04e00141,
   0x43010ec0,
   0x4b0ab672,
   0xb2826818,
   0x43101558,
   0x48086018,
   0x601a6880,
   0x4a07b662,
   0x22907953,
   0x07224353,
   0xf7ff0f12,
   0xbd10fe37,
   0x40045080,
   0x40040000,
   0x40044000,
   0x21000280,
};
#define _NWORD_PATCHIMAGE_BLE_CTE_MS_RXTX 253

#define _NWORD_PATCHSYS_BLE_CTE_MS_RXTX 0



#ifndef _BLE_CTE_MS_RXTX_SYSRAM_START
#define _BLE_CTE_MS_RXTX_SYSRAM_START 0x20000000
#endif

#ifndef _BLE_CTE_MS_RXTX_CPERAM_START
#define _BLE_CTE_MS_RXTX_CPERAM_START 0x21000000
#endif

#define _BLE_CTE_MS_RXTX_SYS_PATCH_FIXED_ADDR 0x20000000

#define _BLE_CTE_MS_RXTX_PARSER_PATCH_TAB_OFFSET 0x0350
#define _BLE_CTE_MS_RXTX_PATCH_TAB_OFFSET 0x0358
#define _BLE_CTE_MS_RXTX_IRQPATCH_OFFSET 0x03E8
#define _BLE_CTE_MS_RXTX_PATCH_VEC_OFFSET 0x0448

PATCH_FUN_SPEC void enterBleCteMsRxtxCpePatch(void)
{
#if (_NWORD_PATCHIMAGE_BLE_CTE_MS_RXTX > 0)
   uint32_t *pPatchVec = (uint32_t *) (_BLE_CTE_MS_RXTX_CPERAM_START + _BLE_CTE_MS_RXTX_PATCH_VEC_OFFSET);

   memcpy(pPatchVec, patchImageBleCteMsRxtx, sizeof(patchImageBleCteMsRxtx));
#endif
}

PATCH_FUN_SPEC void enterBleCteMsRxtxSysPatch(void)
{
}

PATCH_FUN_SPEC void configureBleCteMsRxtxPatch(void)
{
   uint8_t *pPatchTab = (uint8_t *) (_BLE_CTE_MS_RXTX_CPERAM_START + _BLE_CTE_MS_RXTX_PATCH_TAB_OFFSET);


   pPatchTab[23] = 0;
   pPatchTab[1] = 1;
   pPatchTab[28] = 2;
   pPatchTab[64] = 3;
}

PATCH_FUN_SPEC void applyBleCteMsRxtxPatch(void)
{
   enterBleCteMsRxtxSysPatch();
   enterBleCteMsRxtxCpePatch();
   configureBleCteMsRxtxPatch();
}

PATCH_FUN_SPEC void refreshBleCteMsRxtxPatch(void)
{
   enterBleCteMsRxtxCpePatch();
   configureBleCteMsRxtxPatch();
}

PATCH_FUN_SPEC void rf_patch_cpe_ble_cte_ms_rxtx(void)
{
   applyBleCteMsRxtxPatch();
}


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  _RF_PATCH_CPE_BLE_CTE_MS_RXTX_H

