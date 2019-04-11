/******************************************************************************
*  Filename:       rf_patch_cpe_ble_cte_grx.h
*  Revised:        $Date: 2019-01-31 15:04:25 +0100 (to, 31 jan 2019) $
*  Revision:       $Revision: 18842 $
*
*  Description: RF core patch for Bluetooth 5.1 style locationing support if used in combination with MCE CTE patch
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
#ifndef _RF_PATCH_CPE_BLE_CTE_GRX_H
#define _RF_PATCH_CPE_BLE_CTE_GRX_H

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


CPE_PATCH_TYPE patchImageBleCteGrx[] = {
   0x2100047b,
   0x210007b5,
   0x210007c9,
   0x21000741,
   0x4617b5f8,
   0xf0004c0a,
   0x480af802,
   0xb5f84700,
   0x49099100,
   0xb5f84708,
   0x25004c05,
   0x48084e07,
   0x49084700,
   0x22216808,
   0x60084390,
   0x47004806,
   0x21000144,
   0x0000d07b,
   0x0000a963,
   0x40045040,
   0x0000a537,
   0x40048000,
   0x00005249,
   0x4801b510,
   0x00004700,
   0x000009d5,
   0x01c0b570,
   0x47204c00,
   0x000046d5,
   0x4ca8b5f8,
   0x46254aa8,
   0x7ca83540,
   0x4fa64623,
   0x32403320,
   0xd0042801,
   0xd0382802,
   0x478048a3,
   0x7ea1bdf8,
   0x6b906351,
   0xd52a0780,
   0xd9092910,
   0x6310200f,
   0x46086a96,
   0x63103811,
   0x04006a90,
   0xe0034330,
   0x1e407ee0,
   0x6a906310,
   0x2602683a,
   0x603a43b2,
   0xd00f2900,
   0x68d24a95,
   0x48954790,
   0x07896941,
   0x4893d1fc,
   0x68003040,
   0x489261e0,
   0x34204780,
   0xe0017320,
   0x73182000,
   0x200074ae,
   0x498ebdf8,
   0x60082010,
   0x6008498d,
   0x6a10e015,
   0xd01207c0,
   0x79406820,
   0xd0012800,
   0xe0002201,
   0x49882200,
   0x62c88a28,
   0x21026838,
   0x60384308,
   0x69e17b18,
   0xff72f7ff,
   0x2001bdf8,
   0xb5febdf8,
   0x7ec14881,
   0x29007f02,
   0xd07e4696,
   0x23004f76,
   0x37404c74,
   0x2207637b,
   0x2222633a,
   0x462e6bbd,
   0xd0fb4216,
   0xd57107ae,
   0x4d786abe,
   0x4d7161ee,
   0x07ad696d,
   0x4d6fd1fb,
   0x682d3540,
   0x9501b2ed,
   0xd51206ad,
   0xd8082904,
   0x02ad4675,
   0x1c6d4e70,
   0x25016375,
   0x55352652,
   0x2552e001,
   0x4d6d552b,
   0x4e6d682d,
   0x260172b5,
   0x2552e002,
   0x2600552b,
   0x726b4d69,
   0x22226bbb,
   0x4213461d,
   0x07aad0fa,
   0x4a59d544,
   0x6a933240,
   0x61d34a60,
   0x69524a59,
   0xd1fb0792,
   0x32404a57,
   0xb2d36812,
   0x79029300,
   0x401a7940,
   0xdb7c4290,
   0x7ea31990,
   0x321000c2,
   0x4a4d189b,
   0x32402700,
   0x9a016153,
   0x9a007522,
   0x62607562,
   0x36404626,
   0x7cb26220,
   0xd0532a00,
   0x6ad54a4c,
   0x462a4b4e,
   0x0892434a,
   0x4b42631a,
   0x33408235,
   0x22226b9d,
   0xd0fb4215,
   0xd53807aa,
   0x4a466a9b,
   0x4a3f61d3,
   0x079b6953,
   0x4a3dd1fc,
   0x68123240,
   0x06fab2d7,
   0xe057e001,
   0x0ed2e044,
   0x4a414694,
   0x46627257,
   0x2a131e92,
   0x2202d301,
   0x23014694,
   0x025b4a3d,
   0x46626053,
   0x467300d2,
   0x2a041ad2,
   0x2204da00,
   0x434b4613,
   0x428b4938,
   0x460bd900,
   0x33ff33ff,
   0x33024934,
   0x6809608b,
   0x43192321,
   0x60194b31,
   0x02894671,
   0x4a2c4311,
   0x49306351,
   0x02c96849,
   0x2003d506,
   0x80f002c0,
   0x72302002,
   0xbdfe2003,
   0x99019a00,
   0xfeb9f7ff,
   0x28007cb0,
   0x6aa0d008,
   0xd0022800,
   0x1c407007,
   0x6a6062a0,
   0x62601e40,
   0xd50906a8,
   0xbdfe2001,
   0x4821e7ff,
   0x6be14780,
   0x47882033,
   0xe7f56420,
   0x20356be1,
   0x64204788,
   0xe7f02000,
   0x3878480b,
   0xe7ec4780,
   0x31404907,
   0x28347108,
   0x2836d006,
   0x4916d006,
   0x18400080,
   0x477068c0,
   0x47704814,
   0x47704814,
   0x21000144,
   0x40045000,
   0x0000d05b,
   0x21000300,
   0x40042000,
   0x00005a8b,
   0xe000e280,
   0xe000e100,
   0x40045100,
   0x210000c8,
   0x40042100,
   0x40045280,
   0x40046080,
   0x210000e0,
   0x40048000,
   0x000001ff,
   0x40091040,
   0x0000b90d,
   0x0000df80,
   0x2100057b,
   0x210004bd,
   0x4c03b510,
   0xfe74f7ff,
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
   0xbd10fe59,
   0x40045080,
   0x40040000,
   0x40044000,
   0x21000280,
};
#define _NWORD_PATCHIMAGE_BLE_CTE_GRX 242

#define _NWORD_PATCHSYS_BLE_CTE_GRX 0



#ifndef _BLE_CTE_GRX_SYSRAM_START
#define _BLE_CTE_GRX_SYSRAM_START 0x20000000
#endif

#ifndef _BLE_CTE_GRX_CPERAM_START
#define _BLE_CTE_GRX_CPERAM_START 0x21000000
#endif

#define _BLE_CTE_GRX_SYS_PATCH_FIXED_ADDR 0x20000000

#define _BLE_CTE_GRX_PARSER_PATCH_TAB_OFFSET 0x0350
#define _BLE_CTE_GRX_PATCH_TAB_OFFSET 0x0358
#define _BLE_CTE_GRX_IRQPATCH_OFFSET 0x03E8
#define _BLE_CTE_GRX_PATCH_VEC_OFFSET 0x0448

PATCH_FUN_SPEC void enterBleCteGrxCpePatch(void)
{
#if (_NWORD_PATCHIMAGE_BLE_CTE_GRX > 0)
   uint32_t *pPatchVec = (uint32_t *) (_BLE_CTE_GRX_CPERAM_START + _BLE_CTE_GRX_PATCH_VEC_OFFSET);

   memcpy(pPatchVec, patchImageBleCteGrx, sizeof(patchImageBleCteGrx));
#endif
}

PATCH_FUN_SPEC void enterBleCteGrxSysPatch(void)
{
}

PATCH_FUN_SPEC void configureBleCteGrxPatch(void)
{
   uint8_t *pPatchTab = (uint8_t *) (_BLE_CTE_GRX_CPERAM_START + _BLE_CTE_GRX_PATCH_TAB_OFFSET);


   pPatchTab[74] = 0;
   pPatchTab[28] = 1;
   pPatchTab[64] = 2;
   pPatchTab[1] = 3;
}

PATCH_FUN_SPEC void applyBleCteGrxPatch(void)
{
   enterBleCteGrxSysPatch();
   enterBleCteGrxCpePatch();
   configureBleCteGrxPatch();
}

PATCH_FUN_SPEC void refreshBleCteGrxPatch(void)
{
   enterBleCteGrxCpePatch();
   configureBleCteGrxPatch();
}

PATCH_FUN_SPEC void rf_patch_cpe_ble_cte_grx(void)
{
   applyBleCteGrxPatch();
}


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  _RF_PATCH_CPE_BLE_CTE_GRX_H

