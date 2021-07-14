/******************************************************************************
*  Filename:       rf_patch_cpe_ieee_coex.c
*
*  Description: RF core patch for IEEE 802.15.4-Coex support ("IEEE" API command set) in CC13x2 and CC26x2
*
*  Copyright (c) 2015-2021, Texas Instruments Incorporated
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

#include "rf_patch_cpe_ieee_coex.h"

#ifndef CPE_PATCH_TYPE
#define CPE_PATCH_TYPE static const uint32_t
#endif

#ifndef SYS_PATCH_TYPE
#define SYS_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC static
#endif

#ifndef _APPLY_PATCH_TAB
#define _APPLY_PATCH_TAB
#endif


CPE_PATCH_TYPE patchImageIeeeCoex[] = {
   0x2100406d,
   0x21004099,
   0x210040a5,
   0x2100416b,
   0x21004877,
   0x2100488b,
   0x210049bb,
   0x21004a2d,
   0x79654c07,
   0xf809f000,
   0x40697961,
   0xd5030749,
   0x4a042101,
   0x60110389,
   0xb570bd70,
   0x47084902,
   0x21000380,
   0x40041108,
   0x0000592d,
   0xf816f000,
   0x47004800,
   0x00007f57,
   0xf816f000,
   0x47004800,
   0x0000881b,
   0x4700b570,
   0x4700b5f8,
   0xb082b5f7,
   0x47204c00,
   0x000006bd,
   0x4700b5f8,
   0x490c6b80,
   0x0f000700,
   0x47707148,
   0x490a4a09,
   0x79502318,
   0x7e4956cb,
   0x428118c0,
   0x4608dd01,
   0x280fe002,
   0x200fdd00,
   0x090989d1,
   0x43010109,
   0x477081d1,
   0x210002e0,
   0x21000088,
   0x4b332201,
   0x48312102,
   0xb5104718,
   0xfcd8f000,
   0x47804830,
   0x6a404830,
   0xd10d2800,
   0x200a492f,
   0x28005608,
   0x1c40da09,
   0x4608d007,
   0x6a403820,
   0x4288492b,
   0x4780d100,
   0xf7ffbd10,
   0xbd10ffe1,
   0x4b292100,
   0x46084a27,
   0x20014718,
   0x02404927,
   0x48276008,
   0x780122fb,
   0x40114b23,
   0x21137001,
   0x20014a24,
   0xb5704718,
   0x46064923,
   0x4d1b4788,
   0x3d204604,
   0xd0082801,
   0xd5040420,
   0x85282000,
   0x6268481e,
   0x46202401,
   0x4630bd70,
   0xf8d0f000,
   0x49106a68,
   0x428839ec,
   0x4819d101,
   0x6a69e00b,
   0x383e480c,
   0xd1014281,
   0xe0044816,
   0x49166a68,
   0xd1024288,
   0x62684815,
   0x4807e7e5,
   0x4a146a41,
   0xd1e04291,
   0x62414913,
   0x0000e7dd,
   0x00000806,
   0x0000069f,
   0x000292a1,
   0x21000108,
   0x21000154,
   0x00029263,
   0x2100410f,
   0x0002b4b5,
   0xe000e180,
   0x21000380,
   0x2100453f,
   0x000296f7,
   0x21004105,
   0x2100414f,
   0x21004969,
   0x00028fe7,
   0x21004b43,
   0x00029569,
   0x21004145,
   0x22ff0783,
   0x409a0edb,
   0x0e090789,
   0x28004099,
   0x0700da0b,
   0x38080f00,
   0x48fc0883,
   0x1818009b,
   0x439369c3,
   0x61c3430b,
   0x08834770,
   0x009b48f8,
   0x68031818,
   0x430b4393,
   0x47706003,
   0x49f5b530,
   0x29007bc9,
   0x4cf4d02a,
   0x29006921,
   0x780ad026,
   0x0fdb07d3,
   0x2900d022,
   0x0852d020,
   0xd01d07d2,
   0x4bee4622,
   0x78522508,
   0xd00b2800,
   0xd4150790,
   0x43286958,
   0x20026158,
   0x70624302,
   0x22017908,
   0xe00a4310,
   0xd5090790,
   0x43a86958,
   0x20fd6158,
   0x70624002,
   0x08407908,
   0x71080040,
   0xb510bd30,
   0x7bc949dc,
   0xd0342900,
   0x4adb49da,
   0x69c93140,
   0x29006111,
   0x4bdad02d,
   0x230118c0,
   0xd0092800,
   0x1b00029c,
   0x2801d004,
   0x2802d00d,
   0xe021d113,
   0xe0097a48,
   0x70d37988,
   0x0fdb0703,
   0x71130780,
   0x71900fc0,
   0x7a08e007,
   0x070370d3,
   0x07800fdb,
   0x0fc07113,
   0x790b7150,
   0x402324fd,
   0x794878d4,
   0x43230064,
   0x0881710b,
   0xd00207c9,
   0x0fc00700,
   0xbd107150,
   0xe7e779c8,
   0x880049c1,
   0x42884249,
   0x49c0d008,
   0xd0054288,
   0x42881c49,
   0x1c49d002,
   0xd1004288,
   0x4770e7b3,
   0x4694b4f0,
   0x7bd24ab5,
   0xd03a2a00,
   0x69224cb4,
   0xd0362a00,
   0x07dd7813,
   0xd0320fed,
   0xd0302a00,
   0x07ef089d,
   0x26012500,
   0x46027360,
   0xd0012f00,
   0xe00070a6,
   0x085b70a5,
   0xd01b07db,
   0x732672e6,
   0xd11a2800,
   0x72e37963,
   0x29007323,
   0x79a3d102,
   0x732372e3,
   0x466348a2,
   0x2b0079c0,
   0x7ae3d004,
   0x4303408b,
   0xe00871e3,
   0x43b0408e,
   0x72e571e0,
   0xe002d107,
   0x732572e5,
   0x7ae071e5,
   0x2100bcf0,
   0xbcf0e740,
   0x4b964770,
   0x789ab510,
   0x46144619,
   0x438478c9,
   0x795bd002,
   0xd011430b,
   0xd00f2a00,
   0xd10d4381,
   0x49922001,
   0x60c803c0,
   0x38404890,
   0x04006ac0,
   0x207ed504,
   0xfbbaf000,
   0xbd102000,
   0xbd102001,
   0x4c86b5f8,
   0x25007ac1,
   0x29167aa2,
   0x2915d00e,
   0x2914d00c,
   0x2917d001,
   0x2a00d107,
   0x2200d005,
   0x46102101,
   0xff8af7ff,
   0xbdf872a5,
   0xd1fc2a00,
   0x4a7f2101,
   0x030e72a1,
   0x4a7e6016,
   0x4f7e6016,
   0x6a406039,
   0x38ff6160,
   0x3891497b,
   0x60083140,
   0x48796809,
   0x68403840,
   0xfb8ef000,
   0xd0032800,
   0x4873603d,
   0x60063080,
   0x38804871,
   0xbdf86006,
   0x4971b510,
   0x60484871,
   0x3840486f,
   0x220268c1,
   0x60c14311,
   0x0314486b,
   0x21006004,
   0xf7ff200d,
   0x4962feb9,
   0x72482001,
   0x6ac14869,
   0x431100a2,
   0x486362c1,
   0x60043880,
   0xb5f8bd10,
   0x4c624d5b,
   0x26017a28,
   0x03b63440,
   0xd11b2800,
   0x6006485c,
   0x6006485c,
   0x20014f5c,
   0x485b60b8,
   0x68413840,
   0x01122229,
   0x60a11889,
   0x684068a1,
   0xfb4cf000,
   0xd0042800,
   0x60b82000,
   0x30804851,
   0x48506006,
   0x60063880,
   0x1c407a28,
   0x7228b2c0,
   0x28026864,
   0x69a8d10e,
   0x382c1a20,
   0xd805281c,
   0x22012100,
   0xf7ff4608,
   0xe003ff13,
   0x72282000,
   0x60064844,
   0x61acbf00,
   0xb5f8bdf8,
   0x4c464847,
   0x26027ac0,
   0x29000781,
   0x4845da03,
   0x72a68120,
   0x07c0e006,
   0x4842d006,
   0x81201f40,
   0x72a02000,
   0xe00a2503,
   0x47806860,
   0x46014605,
   0xf7ff4620,
   0x2d00ff51,
   0x2d01d0f6,
   0x4f3ad053,
   0x28006a78,
   0x6a78d001,
   0x48374780,
   0x210a3020,
   0x1c895641,
   0x210ad003,
   0x1cc95641,
   0x6838d10a,
   0x88004926,
   0x42884249,
   0x6838d00a,
   0x88001c49,
   0xd0054288,
   0x1e40482b,
   0x72a68120,
   0xe0032503,
   0xd0012d03,
   0xd12e2d02,
   0x38204825,
   0x2d036806,
   0x2002d115,
   0xfae2f000,
   0x3840481d,
   0x69e16845,
   0xf0004628,
   0x2800fad5,
   0x2000d001,
   0x4810e006,
   0x89413020,
   0x1b4069e0,
   0xfad6f000,
   0x89e081e0,
   0x6a207570,
   0x481661b0,
   0x38206a21,
   0x7b606181,
   0x7aa175b0,
   0x22018920,
   0xfaccf000,
   0x28006a78,
   0x6a78d001,
   0xbdf84780,
   0xe000ed00,
   0xe000e400,
   0x210000a8,
   0x21004c50,
   0x40041100,
   0xffffd7ff,
   0x00002c01,
   0x40045040,
   0xe000e180,
   0xe000e280,
   0x40043040,
   0x00001702,
   0x40046080,
   0x21000240,
   0x21000154,
   0x00002407,
   0x21000108,
   0x48f8b510,
   0x49f86800,
   0xd1084288,
   0x49f72001,
   0x60080300,
   0x46112201,
   0xf7ff2000,
   0x48f4fe65,
   0xbd104780,
   0x4cefb570,
   0x8005f3ef,
   0xd10e281e,
   0x79e84df0,
   0xd00807c0,
   0x780048ef,
   0xd004280e,
   0x46112200,
   0xf7ff4610,
   0x2000fe4f,
   0xf3ef7228,
   0x381e8005,
   0xfa7ef000,
   0x28006820,
   0x6820d001,
   0xbd704780,
   0x4ee3b5f8,
   0x27007a70,
   0x28004cdf,
   0x48e2d004,
   0x0a006840,
   0xd0062817,
   0x7d0548e0,
   0x478048e0,
   0xd02d2d06,
   0x4adfe034,
   0x60512101,
   0x72777031,
   0x230348dc,
   0x60033040,
   0x016d2561,
   0x604160c5,
   0x23596143,
   0x6203019b,
   0x20076181,
   0x49d26210,
   0x68483940,
   0x684a3018,
   0xd3fc4282,
   0xf0002000,
   0x48d1fa4d,
   0x22026941,
   0x61414391,
   0x48cdbf00,
   0x6ac13080,
   0x0c490449,
   0x031062c1,
   0xe76a6020,
   0x280078b0,
   0x7830d0fb,
   0xd1f82800,
   0xfe94f7ff,
   0xd1f42d04,
   0xfeadf7ff,
   0x780048be,
   0xd1ee280e,
   0x60200328,
   0x22012100,
   0xf7ff4608,
   0x7237fdeb,
   0xb5f8e751,
   0x6ac048bb,
   0x4ebd4fbc,
   0x07c14dbd,
   0x2403d001,
   0x0700e04c,
   0x2c010f84,
   0x2c02d004,
   0x7fb0d107,
   0xd13f2800,
   0xf7ff2001,
   0x2800fe16,
   0x2c01d004,
   0x2c02d027,
   0xe032d022,
   0x20014cad,
   0x46016060,
   0xf00048b0,
   0x20a1fa07,
   0x01002101,
   0xfa02f000,
   0x210120c3,
   0xf0000100,
   0x2007fa03,
   0x24036220,
   0x2101489e,
   0x21007001,
   0x6af87241,
   0x0c400440,
   0x200162f8,
   0x03404997,
   0xe0176008,
   0x28007fb0,
   0x2001d110,
   0xf9e0f000,
   0x08407ae8,
   0xd00407c0,
   0x69414898,
   0x43112202,
   0x2c026141,
   0x2c03d002,
   0xe024d004,
   0xf0002001,
   0xe020f9e1,
   0x2000498b,
   0x6af87248,
   0x0c400440,
   0x210162f8,
   0xf7ff200d,
   0x4988fceb,
   0x60482000,
   0x4f822001,
   0x60380340,
   0xf0002000,
   0x2001f9cb,
   0x60380280,
   0x08407ae8,
   0xd00407c0,
   0x69424883,
   0x438a2102,
   0x77b46142,
   0xb510e6d7,
   0xf7ff4884,
   0x2200fc19,
   0x46104611,
   0xfd66f7ff,
   0x4880bd10,
   0x38b4b510,
   0xfc10f7ff,
   0xb5f8bd10,
   0x4c7d487e,
   0x25007ac0,
   0x26020780,
   0xda032800,
   0x8120487b,
   0x250372a6,
   0x78c0487a,
   0xd0032800,
   0x81204879,
   0x250372a6,
   0x20ffb672,
   0xf0003001,
   0xb662f999,
   0xe00a4f64,
   0x28007838,
   0x2083d004,
   0xf954f000,
   0xe0042503,
   0x47806860,
   0x2d004605,
   0xb672d0f2,
   0x300120ff,
   0xf98af000,
   0x4869b662,
   0x28007840,
   0x4869d010,
   0x07406840,
   0x4854d50c,
   0x68003880,
   0xd5070700,
   0xf0002080,
   0x4862f937,
   0x81201cc0,
   0x250372a6,
   0x28007838,
   0x2000d009,
   0x207f7278,
   0xf92af000,
   0x1d00485b,
   0x72a68120,
   0x2d03e004,
   0x2d02d002,
   0xe670d006,
   0xf966f000,
   0xf96af000,
   0xf96ef000,
   0x89207aa1,
   0xf0002201,
   0x483df92d,
   0x29006801,
   0x6800d0ef,
   0xe65e4780,
   0x4c4fb510,
   0x5620200a,
   0xd1141c80,
   0x21207ae0,
   0x21bf4308,
   0x72e04008,
   0x38204620,
   0x29006a41,
   0x6a40d001,
   0x200a4780,
   0x1cc05620,
   0x493ed110,
   0x39e02002,
   0x49307308,
   0x70082000,
   0x46112201,
   0xf7ff4610,
   0x2118fcd3,
   0x4a3e4b3f,
   0x47982001,
   0xb5f8bd10,
   0x48314607,
   0x7bc44e27,
   0x468c2000,
   0x2c004615,
   0x6931d012,
   0xd0032900,
   0x07c47808,
   0xd00b0fe4,
   0x79327831,
   0xd1024391,
   0x07c00900,
   0x2200d104,
   0x46104611,
   0xfc32f7ff,
   0x4661462a,
   0xf7ff4638,
   0x2d00fb5d,
   0x4824d002,
   0xe0013820,
   0x38204827,
   0xd00c2c00,
   0x28006800,
   0x2101d109,
   0x40a979f0,
   0x22004388,
   0x461171f0,
   0xf7ff4610,
   0xe5fcfc17,
   0x4c18b510,
   0x3ce04820,
   0xfb46f7ff,
   0x7d603420,
   0xd03b2800,
   0x20004907,
   0x22017008,
   0x46104601,
   0x0000e037,
   0x210002a8,
   0x2100453f,
   0xe000e180,
   0x00000b73,
   0x21004c50,
   0x21000018,
   0x40043040,
   0x210002c0,
   0x000074f5,
   0x40046000,
   0x40041100,
   0x40046080,
   0x210002a0,
   0x210000a8,
   0x00001670,
   0x00005b3f,
   0x21000240,
   0x21000154,
   0x00002407,
   0x21000380,
   0x00002802,
   0x40045080,
   0x21000128,
   0x21004897,
   0x0002b4b5,
   0x00029de9,
   0x46112200,
   0xf7ff4610,
   0xbd10fc49,
   0x4828b570,
   0x7bc02500,
   0xd0372800,
   0x69084926,
   0xd0032800,
   0x07c07800,
   0xd02f0fc0,
   0x7ae04c23,
   0x2804380e,
   0x7808d82a,
   0x28004e21,
   0x6af0d019,
   0xd01607c0,
   0xf0002501,
   0x491ef897,
   0x60882020,
   0xf0002000,
   0x481cf897,
   0x49166840,
   0x8cc93980,
   0x21001840,
   0xf0006160,
   0x6822f893,
   0x20024621,
   0x7ae04790,
   0xd1022812,
   0x07c06af0,
   0x2d00d101,
   0x2200d004,
   0x46104611,
   0xfc0af7ff,
   0xb510bd70,
   0x4c0a480e,
   0x34204780,
   0x28007de0,
   0x2801d007,
   0x2201d104,
   0x20002101,
   0xfbfaf7ff,
   0x2200bd10,
   0x0000e7f8,
   0x210000a8,
   0x21004c50,
   0x21000160,
   0x40046000,
   0x40041100,
   0x40043000,
   0x00028fe7,
   0x4801b403,
   0xbd019001,
   0x00003cc3,
   0x4801b403,
   0xbd019001,
   0x000075d1,
   0x4801b403,
   0xbd019001,
   0x00000fc1,
   0x4801b403,
   0xbd019001,
   0x00009361,
   0x4801b403,
   0xbd019001,
   0x0000069f,
   0x4801b403,
   0xbd019001,
   0x00000c45,
   0x4801b403,
   0xbd019001,
   0x000085bd,
   0x4801b403,
   0xbd019001,
   0x00004e75,
   0x4801b403,
   0xbd019001,
   0x00004e4f,
   0x4801b403,
   0xbd019001,
   0x0000900f,
   0x4801b403,
   0xbd019001,
   0x0000424f,
   0x4801b403,
   0xbd019001,
   0x0000423d,
   0x4801b403,
   0xbd019001,
   0x00007d65,
   0x4801b403,
   0xbd019001,
   0x00006655,
   0x4801b403,
   0xbd019001,
   0x00005d1b,
   0x4801b403,
   0xbd019001,
   0x00008303,
   0x4801b403,
   0xbd019001,
   0x000075f7,
   0x01000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000405,
};
#define _NWORD_PATCHIMAGE_IEEE_COEX 777

#define _NWORD_PATCHCPEHD_IEEE_COEX 0

#define _NWORD_PATCHSYS_IEEE_COEX 0

#define _IRQ_PATCH_0 0x2100466d
#define _IRQ_PATCH_1 0x21004691
#define _IRQ_PATCH_2 0x210046d1
#define _IRQ_PATCH_3 0x21004783


#ifndef _IEEE_COEX_SYSRAM_START
#define _IEEE_COEX_SYSRAM_START 0x20000000
#endif

#ifndef _IEEE_COEX_CPERAM_START
#define _IEEE_COEX_CPERAM_START 0x21000000
#endif

#define _IEEE_COEX_SYS_PATCH_FIXED_ADDR 0x20000000

#define _IEEE_COEX_PATCH_VEC_ADDR_OFFSET 0x03D0
#define _IEEE_COEX_PATCH_TAB_OFFSET 0x03D4
#define _IEEE_COEX_IRQPATCH_OFFSET 0x0480
#define _IEEE_COEX_PATCH_VEC_OFFSET 0x404C

#define _IEEE_COEX_PATCH_CPEHD_OFFSET 0x04E0

#ifndef _IEEE_COEX_NO_PROG_STATE_VAR
static uint8_t bIeeeCoexPatchEntered = 0;
#endif

PATCH_FUN_SPEC void enterIeeeCoexCpePatch(void)
{
#if (_NWORD_PATCHIMAGE_IEEE_COEX > 0)
   uint32_t *pPatchVec = (uint32_t *) (_IEEE_COEX_CPERAM_START + _IEEE_COEX_PATCH_VEC_OFFSET);

   memcpy(pPatchVec, patchImageIeeeCoex, sizeof(patchImageIeeeCoex));
#endif
}

PATCH_FUN_SPEC void enterIeeeCoexCpeHdPatch(void)
{
#if (_NWORD_PATCHCPEHD_IEEE_COEX > 0)
   uint32_t *pPatchCpeHd = (uint32_t *) (_IEEE_COEX_CPERAM_START + _IEEE_COEX_PATCH_CPEHD_OFFSET);

   memcpy(pPatchCpeHd, patchCpeHd, sizeof(patchCpeHd));
#endif
}

PATCH_FUN_SPEC void enterIeeeCoexSysPatch(void)
{
}

PATCH_FUN_SPEC void configureIeeeCoexPatch(void)
{
   uint8_t *pPatchTab = (uint8_t *) (_IEEE_COEX_CPERAM_START + _IEEE_COEX_PATCH_TAB_OFFSET);
   uint32_t *pIrqPatch = (uint32_t *) (_IEEE_COEX_CPERAM_START + _IEEE_COEX_IRQPATCH_OFFSET);


   pPatchTab[76] = 0;
   pPatchTab[140] = 1;
   pPatchTab[150] = 2;
   pPatchTab[164] = 3;
   pPatchTab[79] = 4;
   pPatchTab[78] = 5;
   pPatchTab[40] = 6;
   pPatchTab[57] = 7;

   pIrqPatch[15] = _IRQ_PATCH_0;
   pIrqPatch[19] = _IRQ_PATCH_1;
   pIrqPatch[17] = _IRQ_PATCH_2;
   pIrqPatch[21] = _IRQ_PATCH_3;
}

PATCH_FUN_SPEC void applyIeeeCoexPatch(void)
{
#ifdef _IEEE_COEX_NO_PROG_STATE_VAR
   enterIeeeCoexSysPatch();
   enterIeeeCoexCpePatch();
#else
   if (!bIeeeCoexPatchEntered)
   {
      enterIeeeCoexSysPatch();
      enterIeeeCoexCpePatch();
      bIeeeCoexPatchEntered = 1;
   }
#endif
   enterIeeeCoexCpeHdPatch();
   configureIeeeCoexPatch();
}

void refreshIeeeCoexPatch(void)
{
   enterIeeeCoexCpeHdPatch();
   configureIeeeCoexPatch();
}

void cleanIeeeCoexPatch(void)
{
#ifndef _IEEE_COEX_NO_PROG_STATE_VAR
   bIeeeCoexPatchEntered = 0;
#endif
}

void rf_patch_cpe_ieee_coex(void)
{
   applyIeeeCoexPatch();
}

#undef _IRQ_PATCH_0
#undef _IRQ_PATCH_1
#undef _IRQ_PATCH_2
#undef _IRQ_PATCH_3

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif


