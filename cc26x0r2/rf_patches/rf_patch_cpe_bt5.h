/******************************************************************************
*  Filename:       rf_patch_cpe_bt5.h
*  Revised:        $Date: 2019-08-14 13:58:58 +0200 (Mi, 14 Aug 2019) $
*  Revision:       $Revision: 19122 $
*
*  Description: RF core patch for Bluetooth 5 support in CC2640R2F
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
#ifndef _RF_PATCH_CPE_BT5_H
#define _RF_PATCH_CPE_BT5_H

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


CPE_PATCH_TYPE patchImageBt5[] = {
   0x210005d7,
   0x21000777,
   0x2100099f,
   0x2100047d,
   0x21000489,
   0x210004a1,
   0x21000a35,
   0x21000a49,
   0x210004d1,
   0x210004f1,
   0x461db570,
   0x47204c00,
   0x0000b287,
   0x0a004670,
   0x28c44a05,
   0x4710d004,
   0x32e44a03,
   0x90042001,
   0x20004902,
   0x47107008,
   0x0000679d,
   0x210001dc,
   0x88084903,
   0x46714a03,
   0xd0004290,
   0x47081c89,
   0x2100018a,
   0x00001404,
   0x4801b510,
   0x00004700,
   0x000009d5,
   0x01c0b570,
   0x47204c00,
   0x000046d5,
   0x21014805,
   0x438a6802,
   0x6b836002,
   0x6383438b,
   0x6002430a,
   0x47004801,
   0x40046000,
   0x000051a5,
   0x4a094808,
   0x429a6803,
   0x4808d10a,
   0x4b088902,
   0xd0011ad2,
   0xd1032a01,
   0x49066e00,
   0x99034788,
   0x47184b05,
   0x21000254,
   0x000094ef,
   0x21000144,
   0x00001821,
   0x0000344f,
   0x0000055f,
   0x4cffb5f8,
   0x462548ff,
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
   0x4cecb570,
   0x6a604625,
   0x28003580,
   0x2050d11d,
   0x22005d00,
   0xd0172800,
   0x5d002060,
   0x07c00880,
   0x6869d012,
   0x0b808888,
   0xd10d2801,
   0x7dc048e3,
   0x07c00840,
   0x48e1d008,
   0x6bc03820,
   0x28006800,
   0x61e9d002,
   0xe0006068,
   0x48dd61ea,
   0x6a614780,
   0xd1032900,
   0x290069e9,
   0x6069d000,
   0x8801bd70,
   0x18894ad8,
   0xd8062903,
   0x217c48d7,
   0x49d78501,
   0x20016241,
   0x49d64770,
   0xb5f84708,
   0x49d54ccd,
   0x36204626,
   0x46257b70,
   0x90003540,
   0x00b8792f,
   0x68c01840,
   0x28004780,
   0x49c8d128,
   0x09097dc9,
   0xd02307c9,
   0x32604622,
   0xd0202f15,
   0x23007d29,
   0x07ff094f,
   0x7c6dd003,
   0xd0002d00,
   0x9f002301,
   0x43bb6f65,
   0x7b73d012,
   0xd00f2b00,
   0x065b7d23,
   0x88d2d50c,
   0x2a010b92,
   0x08c9d108,
   0xd00507c9,
   0x0b8988a9,
   0xd1012901,
   0x73712100,
   0x7ce9bdf8,
   0x4fb98925,
   0x42bd2301,
   0x2300d0e1,
   0xb510e7df,
   0x46204cac,
   0x7c013040,
   0xd0022902,
   0xd01e2901,
   0x6821e052,
   0x754179c9,
   0x34806821,
   0x60a2688a,
   0x29027d41,
   0x2900d048,
   0x1ecbd046,
   0xd8072b06,
   0x49a50088,
   0x38401840,
   0x18106b80,
   0xe03b60a0,
   0x02c92103,
   0x210280c1,
   0x20037201,
   0x499bbd10,
   0x08497dc9,
   0xd02f07c9,
   0x31604621,
   0x0852784a,
   0xd02907d2,
   0x0b8988c9,
   0xd1252901,
   0x09417d00,
   0xd00c07c9,
   0x07006f61,
   0x0fc08809,
   0x04090240,
   0x66204308,
   0x1c806f60,
   0xf9c6f000,
   0x488be013,
   0x6bc03820,
   0x28006840,
   0x4a90d00e,
   0x78012300,
   0x1a5956d3,
   0x00c9d408,
   0x78411808,
   0xd00307c9,
   0x66216801,
   0x66606840,
   0x47804889,
   0xb570bd10,
   0x49844c7c,
   0x36404626,
   0x00a87935,
   0x68c01840,
   0x2d0a4780,
   0xd0104621,
   0x780a3154,
   0x07db0993,
   0x73b2d004,
   0x2303780a,
   0x700a431a,
   0xb2ca8921,
   0xd3012a2b,
   0x81213928,
   0x3153bd70,
   0x496de7ed,
   0x31404602,
   0x3a087108,
   0x2a220081,
   0x4875d804,
   0x38401808,
   0x47706a00,
   0xd007283c,
   0xd007283d,
   0xd0072847,
   0x1808486b,
   0x477068c0,
   0x4770486e,
   0x4770486e,
   0x4770486e,
   0x485eb570,
   0x3040496d,
   0x09407cc0,
   0xd00807c0,
   0x486b4d5c,
   0x8b2c3d20,
   0x83284320,
   0x832c4788,
   0x4788bd70,
   0xb510bd70,
   0x4c544866,
   0x28024780,
   0x4621d10e,
   0x88ca3140,
   0x429a4b63,
   0x7ccad108,
   0x07d20952,
   0x7d22d004,
   0xd4010692,
   0x80ca1d9a,
   0xb570bd10,
   0x890a4949,
   0x30504608,
   0x2a28b2d2,
   0x680ad107,
   0x614268d2,
   0x7ad27a93,
   0x189a0212,
   0x4a458302,
   0x3aac7803,
   0xd0112b00,
   0x2b017983,
   0x7c03d10e,
   0x07db095b,
   0x4d3ed00a,
   0x74c17d09,
   0x7f6c3d20,
   0x43202020,
   0x47907768,
   0xbd70776c,
   0x74c121ff,
   0xbd704790,
   0x4c34b570,
   0x46254847,
   0x47803550,
   0xd1092802,
   0x88e13440,
   0x42914a42,
   0x7ce9d104,
   0xd4010689,
   0x80e11d91,
   0xb570bd70,
   0x4604482a,
   0x7da53440,
   0xd0122d01,
   0x06497d01,
   0x21800fca,
   0x7c21540a,
   0xd10a2900,
   0x78403060,
   0x07c00880,
   0x7ce0d002,
   0xd5020700,
   0x75a02001,
   0x2000e000,
   0x483273a0,
   0x75a54780,
   0x481bbd70,
   0x21003090,
   0x482f7081,
   0xb5704700,
   0x482e4c17,
   0x35204625,
   0x47807b6e,
   0xd15a2800,
   0x31404621,
   0x2a007c0a,
   0x7d8ad055,
   0x2a033150,
   0x2a04d052,
   0x2e00d14f,
   0x4622d14d,
   0x78133260,
   0x07db089b,
   0x2384d047,
   0x889b591b,
   0x2b010b9b,
   0x788bd141,
   0x2b004908,
   0xd0407dc9,
   0x07c908c9,
   0x7d21d039,
   0xd5360609,
   0x0b898bd1,
   0xe02f2901,
   0x21000144,
   0x0000a767,
   0x210000c8,
   0x0000c997,
   0xffffe7d5,
   0x210000ec,
   0x00009657,
   0x00009663,
   0x0000df80,
   0x00001804,
   0x21000b3c,
   0x0000d575,
   0x21000ab0,
   0x21000737,
   0x21000677,
   0x210005f3,
   0x0000ad53,
   0x00002020,
   0x0000b4f5,
   0x00001404,
   0x0000cb37,
   0x0000bcf3,
   0x0000b863,
   0x0000be1d,
   0x2100d101,
   0xbd707369,
   0x708a2201,
   0x0889bd70,
   0xb5f8e7bd,
   0x4c224607,
   0x5d00204e,
   0x07ee0985,
   0x2e0025fb,
   0x7d26d017,
   0x0f240734,
   0xd0032c05,
   0x42202401,
   0xe012d002,
   0xe7fa2402,
   0xd00509c0,
   0xd5030670,
   0x0f806848,
   0xd0082801,
   0x005b085b,
   0x00520852,
   0x2800e003,
   0x402bd001,
   0x2b06402a,
   0x2010d003,
   0xd0102b02,
   0x2302e010,
   0x4638402a,
   0xfd38f7ff,
   0xda072800,
   0x1ab900c2,
   0x7e493920,
   0x42112214,
   0x2000d100,
   0x4302bdf8,
   0x461c4303,
   0xf7ff4638,
   0x07e1fd27,
   0x4902d0f6,
   0xbdf87008,
   0x21000144,
   0x21000b3c,
   0x4c03b510,
   0xfd3ef7ff,
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
   0xbd10fd23,
   0x40045080,
   0x40040000,
   0x40044000,
   0x21000280,
   0x07810882,
   0x0ec90092,
   0x78c0ca0c,
   0x424940ca,
   0x408b3120,
   0x0211431a,
   0x06000a09,
   0x47704308,
   0x2100052d,
   0x0000a9f7,
   0x21000737,
   0x210007b1,
   0x0000adf7,
   0x0000ae2d,
   0x0000ae55,
   0x0000ae9d,
   0x0000afab,
   0x0000b021,
   0x0000b08b,
   0x0000b109,
   0x0000b151,
   0x210005f3,
   0x0000b431,
   0x0000b47b,
   0x210007d7,
   0x0000b5ed,
   0x0000b821,
   0x210008bf,
   0x0000baeb,
   0x0000bc0b,
   0x2100087f,
   0x210008cb,
   0x0000bf91,
   0x0000c1a7,
   0x0000c251,
   0x0000c459,
   0x0000c7f9,
   0x21000803,
   0x21000579,
   0x0000ca89,
   0x0000cacb,
   0x0000caf9,
   0x21000859,
   0x00000000,
};
#define _NWORD_PATCHIMAGE_BT5 446

#define _NWORD_PATCHSYS_BT5 0



#ifndef _BT5_SYSRAM_START
#define _BT5_SYSRAM_START 0x20000000
#endif

#ifndef _BT5_CPERAM_START
#define _BT5_CPERAM_START 0x21000000
#endif

#define _BT5_SYS_PATCH_FIXED_ADDR 0x20000000

#define _BT5_PARSER_PATCH_TAB_OFFSET 0x0350
#define _BT5_PATCH_TAB_OFFSET 0x0358
#define _BT5_IRQPATCH_OFFSET 0x03E8
#define _BT5_PATCH_VEC_OFFSET 0x0448

PATCH_FUN_SPEC void enterBt5CpePatch(void)
{
#if (_NWORD_PATCHIMAGE_BT5 > 0)
   uint32_t *pPatchVec = (uint32_t *) (_BT5_CPERAM_START + _BT5_PATCH_VEC_OFFSET);

   memcpy(pPatchVec, patchImageBt5, sizeof(patchImageBt5));
#endif
}

PATCH_FUN_SPEC void enterBt5SysPatch(void)
{
}

PATCH_FUN_SPEC void configureBt5Patch(void)
{
   uint8_t *pParserPatchTab = (uint8_t *) (_BT5_CPERAM_START + _BT5_PARSER_PATCH_TAB_OFFSET);
   uint8_t *pPatchTab = (uint8_t *) (_BT5_CPERAM_START + _BT5_PATCH_TAB_OFFSET);


   pParserPatchTab[1] = 0;
   pPatchTab[1] = 1;
   pPatchTab[18] = 2;
   pPatchTab[105] = 3;
   pPatchTab[108] = 4;
   pPatchTab[22] = 5;
   pPatchTab[28] = 6;
   pPatchTab[64] = 7;
   pPatchTab[72] = 8;
   pPatchTab[36] = 9;
}

PATCH_FUN_SPEC void applyBt5Patch(void)
{
   enterBt5SysPatch();
   enterBt5CpePatch();
   configureBt5Patch();
}

PATCH_FUN_SPEC void refreshBt5Patch(void)
{
   enterBt5CpePatch();
   configureBt5Patch();
}

PATCH_FUN_SPEC void rf_patch_cpe_bt5(void)
{
   applyBt5Patch();
}


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  _RF_PATCH_CPE_BT5_H

