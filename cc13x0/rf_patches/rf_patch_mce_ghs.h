/******************************************************************************
*  Filename:       rf_patch_mce_ghs.h
*  Revised:        $Date: 2019-06-05 10:53:39 +0200 (Mi, 05 Jun 2019) $
*  Revision:       $Revision: 19080 $
*
*  Description: RF core patch for CC13x0 Generic 4FSK up to 1.5Mbps
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

#ifndef _RF_PATCH_MCE_GHS_H
#define _RF_PATCH_MCE_GHS_H

#include <stdint.h>
#include "../inc/hw_types.h"

#ifndef MCE_PATCH_TYPE
#define MCE_PATCH_TYPE static const uint32_t
#endif

#ifndef PATCH_FUN_SPEC
#define PATCH_FUN_SPEC static inline
#endif

#ifndef RFC_MCERAM_BASE
#define RFC_MCERAM_BASE 0x21008000
#endif

#ifndef MCE_PATCH_MODE
#define MCE_PATCH_MODE 0
#endif

MCE_PATCH_TYPE patchGhsMce[301] = { 
   0x2fcf603c,
   0x00f03f9d,
   0x0f30003d,
   0x003f0ff0,
   0x0000ff00,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00070003,
   0x31fd31fd,
   0x04000000,
   0x001d000f,
   0x000b0387,
   0x004340f4,
   0x80828000,
   0x00000f90,
   0x0510091e,
   0x00050054,
   0x11010000,
   0x0000003c,
   0x3030002f,
   0x0000027f,
   0xd3910000,
   0x0000193d,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x72487220,
   0x7303a32d,
   0x72037305,
   0x73067304,
   0x73767204,
   0xc7c07276,
   0x00018001,
   0x90109001,
   0x90010801,
   0x720d720c,
   0xb0c0720e,
   0xb0f07100,
   0x7218a0c0,
   0x10208132,
   0x06703952,
   0x16300020,
   0x14011101,
   0x60796c01,
   0x60f4607c,
   0x607961d9,
   0x60796079,
   0x6079607a,
   0x60f4607c,
   0x607961d9,
   0x60796079,
   0x1210607a,
   0x730f7220,
   0x73117310,
   0x00108181,
   0xb0709180,
   0x606f6051,
   0x606f6645,
   0x663bc030,
   0xc282c141,
   0x1820c470,
   0x6e236f13,
   0x16121611,
   0x78306882,
   0x78409ac0,
   0xc4829ad0,
   0x1820c5a0,
   0x12034093,
   0x16126e23,
   0x83606890,
   0x606f97e0,
   0x94908160,
   0x39808140,
   0x10012a70,
   0x84321611,
   0xc0f38444,
   0xc200c0f5,
   0x40ba1c01,
   0x1c10c100,
   0x4cb240b0,
   0x18031013,
   0x1a131830,
   0x39121a10,
   0x60ba68ad,
   0x60ba13f3,
   0x101513f3,
   0x1850c100,
   0x1a101a15,
   0x68b83914,
   0x7100b0d8,
   0xa0d8b108,
   0xb760b200,
   0x97808ac0,
   0xb0c1b0f1,
   0xb0f17100,
   0x7276a0c1,
   0xb003b480,
   0xb002b013,
   0x7229b012,
   0x7100b0d0,
   0x8140b100,
   0x71009290,
   0x8140b100,
   0x44d322f0,
   0x1c0313f0,
   0x929340df,
   0x71009492,
   0x9295b100,
   0x71009494,
   0xb0d0b100,
   0x7000a480,
   0xc030a0d1,
   0xc0409760,
   0xb0f19780,
   0x7100b0c1,
   0xa0c1b0f1,
   0xa0037276,
   0x7000a002,
   0x7310730f,
   0x663bc040,
   0x8ad0a2f0,
   0xc11092a0,
   0x649691c0,
   0x82b0b2f0,
   0xb48392a0,
   0xb0c3b0f3,
   0xa0c37100,
   0x606f64e6,
   0xb016b006,
   0xb014b004,
   0xb012b002,
   0x78728400,
   0x81430420,
   0x2a733983,
   0xc1f29473,
   0x31621832,
   0x31511021,
   0x00200012,
   0x10309400,
   0x39301610,
   0x41232210,
   0x31501220,
   0x31801003,
   0x935016a0,
   0x12041202,
   0x41352273,
   0x97c08430,
   0x1a8287d2,
   0x97c08450,
   0x1a8487d4,
   0x22636137,
   0x84404142,
   0x87d097c0,
   0x14021a80,
   0x97c08460,
   0x1a8087d0,
   0x614e1404,
   0x78818440,
   0x97c00410,
   0x1a4287d2,
   0x78818460,
   0x97c00410,
   0x1a4487d4,
   0x31543152,
   0x06333963,
   0x38321613,
   0x31823834,
   0x31843982,
   0x95720042,
   0x93607850,
   0x90307810,
   0x78209050,
   0x90609040,
   0xcb40b205,
   0x87e06964,
   0xb0f59360,
   0x8ae2a0c5,
   0x93028303,
   0xc00bc00c,
   0x31808140,
   0x39403980,
   0xc0f38141,
   0xc0140431,
   0xc0021441,
   0x69781412,
   0xb1013122,
   0x7100b0d1,
   0xa0d1b072,
   0xb06ea04e,
   0xb06cb011,
   0xa488a041,
   0x720ca487,
   0x720e720d,
   0xb7647276,
   0xc440a764,
   0xc0629760,
   0x9780c020,
   0xc07fc07e,
   0xb0f1b0e0,
   0xb0c5b0c1,
   0x7100b0f5,
   0xa0e0b760,
   0x80b0a0c5,
   0x45a12200,
   0xb88f6212,
   0xb0737100,
   0xb074978e,
   0x8961b201,
   0x18018570,
   0x8a609551,
   0x18018a71,
   0x4db81c21,
   0x49b61412,
   0x1c0161b9,
   0x4db841b9,
   0x61b9b487,
   0xb061b488,
   0x7100b0f1,
   0x978fb041,
   0x7100b0f1,
   0xb06eb04e,
   0x85528a73,
   0xb88c7000,
   0x89a48180,
   0x31843924,
   0x91840004,
   0x663bc050,
   0x93607850,
   0x72767376,
   0x72067248,
   0x72047202,
   0x73067305,
   0x1300606f,
   0xb32d91b0,
   0x663bc060,
   0x6508b0f8,
   0x93607860,
   0x1a101200,
   0xc3809780,
   0xc2809760,
   0xa0c19760,
   0x8090b0c6,
   0x44512200,
   0x1e048154,
   0x391441eb,
   0x97841694,
   0x8552b0f6,
   0x9862d070,
   0x8a62663b,
   0xe0808a73,
   0x98739862,
   0x8790663b,
   0x1c018781,
   0x18014a0f,
   0x4a0d1ef1,
   0x1af18781,
   0x71009781,
   0x16f1b0f6,
   0xa2059781,
   0xb0f67100,
   0x61c5a0c6,
   0x1e0d821d,
   0xc030418a,
   0x88939880,
   0x313388a4,
   0x22fd3134,
   0x3d334224,
   0x2afd3d34,
   0x30d430d3,
   0x622a8212,
   0x3cd3163d,
   0x1a3d3cd4,
   0x622a8212,
   0x94f494e3,
   0x618ab053,
   0x9880c030,
   0x31328892,
   0x88a33d32,
   0x3d333133,
   0x9862e090,
   0x663b9873,
   0x98507000,
   0x22008840,
   0xb830463c,
   0x81507000,
   0x425822f0,
   0xc102b070,
   0xc0013162,
   0x1e008150,
   0x22f04251,
   0xe5904252,
   0x39603160,
   0x10206252,
   0x6f131a10,
   0x16116e23,
   0x6a531612,
   0x00007000
};

PATCH_FUN_SPEC void rf_patch_mce_ghs(void)
{
#ifdef __PATCH_NO_UNROLLING
   uint32_t i;
   for (i = 0; i < 301; i++) {
      HWREG(RFC_MCERAM_BASE + 4 * i) = patchGhsMce[i];
   }
#else
   const uint32_t *pS = patchGhsMce;
   volatile unsigned long *pD = &HWREG(RFC_MCERAM_BASE);
   uint32_t t1, t2, t3, t4, t5, t6, t7, t8;
   uint32_t nIterations = 37;

   do {
      t1 = *pS++;
      t2 = *pS++;
      t3 = *pS++;
      t4 = *pS++;
      t5 = *pS++;
      t6 = *pS++;
      t7 = *pS++;
      t8 = *pS++;
      *pD++ = t1;
      *pD++ = t2;
      *pD++ = t3;
      *pD++ = t4;
      *pD++ = t5;
      *pD++ = t6;
      *pD++ = t7;
      *pD++ = t8;
   } while (--nIterations);

   t1 = *pS++;
   t2 = *pS++;
   t3 = *pS++;
   t4 = *pS++;
   t5 = *pS++;
   *pD++ = t1;
   *pD++ = t2;
   *pD++ = t3;
   *pD++ = t4;
   *pD++ = t5;
#endif
}

#endif
