/******************************************************************************
*  Filename:       rf_patch_mce_ble_cte.h
*  Revised:        $Date: 2019-01-31 15:04:25 +0100 (Thu, 31 Jan 2019) $
*  Revision:       $Revision: 18842 $
*
*  Description: RF core patch for Bluetooth 5.1 style locationing
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

#ifndef _RF_PATCH_MCE_BLE_CTE_H
#define _RF_PATCH_MCE_BLE_CTE_H

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

MCE_PATCH_TYPE patchBleCteMce[248] = { 
   0x2dee6027,
   0x5f972fcf,
   0x000002d0,
   0x00070003,
   0x0000001f,
   0x40000000,
   0x0000000c,
   0x00091488,
   0x000105f9,
   0x808b8000,
   0x00000f50,
   0x05900a1d,
   0x00050000,
   0x7b200400,
   0x000000c1,
   0x7f27000f,
   0x0000017f,
   0x00000000,
   0x005f0000,
   0x72130000,
   0x7220b0f0,
   0x720d720c,
   0x7248720e,
   0xa475a32d,
   0x72047203,
   0x73067305,
   0x72767376,
   0x9010c7c0,
   0xb0c0a594,
   0xa0c07100,
   0x7218b0f0,
   0x10208132,
   0x06703952,
   0x16300020,
   0x14011101,
   0x604f6c01,
   0x6080605c,
   0x610360f0,
   0x604f604f,
   0x60536050,
   0x12206053,
   0x12106054,
   0x7310730f,
   0x81817311,
   0x91800010,
   0x6039b070,
   0xc282c061,
   0x1820c470,
   0x6e236f13,
   0x16121611,
   0xc4826860,
   0x1820c810,
   0x1203406d,
   0x16126e23,
   0x7840686a,
   0x83009ab0,
   0xd3f09ae0,
   0x60539220,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x7276b005,
   0x91c0c100,
   0xb100b108,
   0xb0f1b0f3,
   0x7100b0d8,
   0xa0d8b108,
   0xb760b200,
   0x97808ab0,
   0x8140b0f1,
   0x2a703980,
   0x16111001,
   0x84448432,
   0xc0f5c0f3,
   0x1c01c200,
   0x8171409d,
   0x40a31e01,
   0x68a1c500,
   0xb0c19241,
   0xb0127100,
   0xb0f1b002,
   0x7276a0c1,
   0xb4807229,
   0xb003b013,
   0x7100b0d0,
   0x8140b100,
   0x81609290,
   0x71009490,
   0x9293b100,
   0x71009492,
   0x9295b100,
   0xe0309494,
   0x98749862,
   0x710065e9,
   0xa0d0b100,
   0xb483a480,
   0x7100b0c3,
   0xa0c3b0f3,
   0x9760c030,
   0x9780c020,
   0x7100b0c1,
   0xa0c1b0f1,
   0x72487276,
   0xa002a003,
   0x73057248,
   0x73767306,
   0xa2007276,
   0x9010c7c0,
   0x00006053,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x1e028172,
   0xb0054102,
   0xb0cfb0ff,
   0x7100658f,
   0xa0cfb0ff,
   0x1c128261,
   0xe0404103,
   0x98729861,
   0x60f365e9,
   0x72ad658f,
   0xb06cb205,
   0xb089b011,
   0xa0c1b475,
   0xb11da0c0,
   0xb0c5b0ed,
   0xc031b0f5,
   0x80907100,
   0x45de2250,
   0xa760a182,
   0xb7607378,
   0x22108990,
   0xb182411c,
   0x3160b074,
   0x100f3d80,
   0x7311720e,
   0xa0c5b201,
   0x22008090,
   0x8153443c,
   0x41241e03,
   0x879087ab,
   0x312318b0,
   0xc2b01803,
   0x8ad81803,
   0x41361e08,
   0x1803c2c0,
   0xa7609783,
   0xb760b0f1,
   0xb0c1b0c0,
   0x456122f3,
   0x415d1e08,
   0xb0777100,
   0x9780c090,
   0x7100b0f1,
   0x10f08301,
   0x3d101610,
   0x1a111801,
   0x39589301,
   0x31283958,
   0x1483c0e3,
   0xb0f19783,
   0x8ac07100,
   0xb59494b0,
   0x31638ad3,
   0x97833943,
   0x7100b0f1,
   0x22008090,
   0x956f443c,
   0xc093a0c0,
   0x90f79783,
   0x7100a205,
   0xb078b32d,
   0xc243a475,
   0x90f79783,
   0x80907100,
   0x443c2200,
   0x7276a32d,
   0x72047202,
   0x72037206,
   0x73057204,
   0x72207306,
   0x73057248,
   0x80907306,
   0x44f02200,
   0x72487220,
   0x73067305,
   0x72767376,
   0x9010c7c0,
   0x986fe050,
   0x65e99872,
   0x84406053,
   0x87d097c0,
   0x8470100e,
   0x419c2240,
   0x97c08430,
   0x140e87d0,
   0x180ec080,
   0x180ec080,
   0x97c08460,
   0x100f87d0,
   0x22408470,
   0x845041ab,
   0x87d097c0,
   0xc080140f,
   0xc080180f,
   0x8321180f,
   0x39613131,
   0x31113981,
   0x11001631,
   0x6c001410,
   0x311e311f,
   0x311e311f,
   0x318e318f,
   0x00ef398e,
   0x8210957f,
   0x45c72230,
   0x7100b0c5,
   0xa0c5b0f5,
   0xc10061bf,
   0x781091b0,
   0x8ae09760,
   0x13e79300,
   0x26ca120a,
   0xb01226ea,
   0xb016b014,
   0xb004b002,
   0x7820b006,
   0x90309050,
   0x90607830,
   0x70009040,
   0x88939881,
   0x313388a4,
   0x31343d63,
   0x94e33d64,
   0xb05394f4,
   0x9850610e,
   0x22008840,
   0xb83045ea,
   0x00007000
};

PATCH_FUN_SPEC void rf_patch_mce_ble_cte(void)
{
#ifdef __PATCH_NO_UNROLLING
   uint32_t i;
   for (i = 0; i < 248; i++) {
      HWREG(RFC_MCERAM_BASE + 4 * i) = patchBleCteMce[i];
   }
#else
   const uint32_t *pS = patchBleCteMce;
   volatile unsigned long *pD = &HWREG(RFC_MCERAM_BASE);
   uint32_t t1, t2, t3, t4, t5, t6, t7, t8;
   uint32_t nIterations = 31;

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
#endif
}

#endif
