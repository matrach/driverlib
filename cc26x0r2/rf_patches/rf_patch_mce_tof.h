/******************************************************************************
*  Filename:       rf_patch_mce_tof.h
*  Revised:        $Date: 2018-11-02 11:52:02 +0100 (fr, 02 nov 2018) $
*  Revision:       $Revision: 18756 $
*
*  Description: RF core patch for supporting time-of-flight radio measurements in CC2640R2F
*
*  Copyright (c) 2015-2017, Texas Instruments Incorporated
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

#ifndef _RF_PATCH_MCE_TOF_H
#define _RF_PATCH_MCE_TOF_H

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

MCE_PATCH_TYPE patchTofMce[509] = { 
   0x00036055,
   0x00f1000f,
   0x00000000,
   0x000c8000,
   0x00000000,
   0x0c650000,
   0x80000000,
   0x00008012,
   0x091e0000,
   0x03500594,
   0x00000000,
   0x00c27c20,
   0x00130000,
   0x00507f7f,
   0xfe6b2840,
   0xdeade8ca,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x00000000,
   0x07d00011,
   0x6fdd2fea,
   0x0fb00ff0,
   0xf80f0003,
   0x007f7f30,
   0x3030001f,
   0x8010005a,
   0x01900000,
   0x40000800,
   0xc1020c65,
   0xc0013162,
   0x1e008150,
   0x1a10404d,
   0x1020604f,
   0x6f131a10,
   0x16116e23,
   0x684f1612,
   0xc0307000,
   0x722067f4,
   0xa32d7248,
   0x73057303,
   0x73047203,
   0x72047306,
   0x72767376,
   0x8001c7c0,
   0x90010001,
   0x08019010,
   0x720c9001,
   0x720e720d,
   0x7100b0c0,
   0xb0f0a0c0,
   0x81327218,
   0x39521020,
   0x00200670,
   0x11011630,
   0x6c011401,
   0x6098608a,
   0x618160ba,
   0x608a621e,
   0x608a608a,
   0x6098608a,
   0x618160ba,
   0x608a621e,
   0x608a608a,
   0x67f4c040,
   0xc0506092,
   0x609067f4,
   0x60931220,
   0x81811210,
   0x91800010,
   0x606cb070,
   0xc282c011,
   0x1820c560,
   0x6e236f13,
   0x16121611,
   0x7c10689c,
   0xc02297e0,
   0x39818131,
   0xd0601812,
   0x67f49862,
   0x97c07be0,
   0x40921e01,
   0x97c07bb0,
   0x97e07c20,
   0x93507bf0,
   0x93007c00,
   0x92d07c30,
   0x6092b330,
   0xc0706787,
   0xb5a091c0,
   0xb7646719,
   0x6733b203,
   0x8724a5a0,
   0x87349454,
   0x8ad49464,
   0x86149434,
   0x87249444,
   0x87349434,
   0x8ab09444,
   0x40d42200,
   0xb110b0e0,
   0xb0c5b0c0,
   0xb0f0b116,
   0xb110b0e0,
   0x2a007b50,
   0xc0f19060,
   0x40e11e0e,
   0x97811611,
   0xc037b762,
   0x8ad4b041,
   0xb0f58613,
   0xa760c031,
   0xb0737100,
   0x94439434,
   0x8090b061,
   0x45762200,
   0x1e0280b2,
   0x22504502,
   0x821040e7,
   0x44ff2200,
   0x40e7220f,
   0x67ad100f,
   0x100f60e7,
   0x60e767c3,
   0xb110a0e0,
   0xb0e6a760,
   0xc031b116,
   0xb7607100,
   0x8090b88e,
   0x45762200,
   0x1e0280b2,
   0x2250451e,
   0x82104107,
   0x451b2200,
   0x4107220f,
   0x67ad100f,
   0x100f6107,
   0x610767c3,
   0xb204a763,
   0x936cb889,
   0x720ea0c5,
   0xb0f1b0c1,
   0x97877100,
   0x7100b0f1,
   0xc3f0b32d,
   0xb0749780,
   0x93b0c0d0,
   0x95e18791,
   0x879167ce,
   0xb0f11401,
   0xb88b7100,
   0xb078b88a,
   0x9780c210,
   0xb205a202,
   0x7100b0f1,
   0xb06ea32d,
   0xa0c17276,
   0x31828942,
   0xc0703d82,
   0x8a6367f4,
   0x14238a82,
   0x8a928a74,
   0x89821424,
   0x897106f2,
   0x00123141,
   0xcff295f2,
   0x31430424,
   0x00343143,
   0xc8f09604,
   0xb205695c,
   0xa0e0b110,
   0xa0e6b116,
   0x7276b764,
   0xa003a5a0,
   0xc7c0a002,
   0x72039010,
   0x73057204,
   0xa2027306,
   0x8212b205,
   0x456d1e02,
   0xc0807220,
   0x609267f4,
   0xa202b205,
   0xd0908792,
   0x67f49862,
   0x720c720e,
   0x730f7311,
   0xc00f615e,
   0xc0706787,
   0x671991c0,
   0x67f4c0a0,
   0xb064b013,
   0x22008ab0,
   0xb0e0418f,
   0xb0e6b110,
   0xb0c5b0c0,
   0xb116b0f1,
   0xb7627276,
   0x1e0ec0e1,
   0x1611419a,
   0xc0379781,
   0xb202b041,
   0xa760c031,
   0x7100b0f5,
   0xb760b073,
   0x8090b88e,
   0x46152200,
   0x1e0280b2,
   0x225045b8,
   0x8210419e,
   0x45b52200,
   0x419e220f,
   0x67ad100f,
   0x100f619e,
   0x619e67c3,
   0xb204b763,
   0x936cb889,
   0x720ea0c5,
   0x26408180,
   0xb0c19180,
   0x7100b0f1,
   0x9787b041,
   0x7100b0f1,
   0xc3f0b32d,
   0xb0749780,
   0x93b0c0d0,
   0x7100b0f1,
   0xc210b078,
   0xa2029780,
   0x7100b0f1,
   0xb06ea32d,
   0xa0c1a760,
   0x87e167ce,
   0x81701401,
   0x97811401,
   0xb0c6b0f6,
   0xb0f67100,
   0x8090a0c6,
   0x46152200,
   0x8724b012,
   0x87349454,
   0x8ad49464,
   0x86149434,
   0x72769444,
   0x2a208200,
   0x92002630,
   0xc0706733,
   0x89428601,
   0x3d823182,
   0x69fdc310,
   0xb0f1b064,
   0xb0e6b116,
   0xb0e0b110,
   0x8212b205,
   0x46041e02,
   0x7276b764,
   0xa002a003,
   0x9010c7c0,
   0x72047203,
   0x73067305,
   0x67f4c0b0,
   0xc0c06092,
   0xb20567f4,
   0x720c720e,
   0x730f7311,
   0x62047276,
   0xc00b6787,
   0x91c0c070,
   0xc0d06719,
   0xb76467f4,
   0x7223725f,
   0x8ab0b013,
   0x422f2200,
   0xb110b0e0,
   0x84386235,
   0x84508449,
   0x94308461,
   0xb0e09441,
   0xb0f0b110,
   0xb0c0b064,
   0xb061b0c5,
   0x1e1bb041,
   0x72764242,
   0x72acb762,
   0xc070c0b7,
   0x42481e0e,
   0xc0b71610,
   0xb2029780,
   0xc031b0f5,
   0x7100a760,
   0x9438b073,
   0xb0619449,
   0x22008090,
   0x80b2470e,
   0x46651e02,
   0x424a2250,
   0x22008210,
   0x220f4662,
   0x100f424a,
   0x624a67ad,
   0x67c3100f,
   0xb110624a,
   0xb0e6a760,
   0x7100b116,
   0xb88eb760,
   0x22008090,
   0x80b2470e,
   0x467f1e02,
   0x42692250,
   0x22008210,
   0x220f467c,
   0x100f4269,
   0x626967ad,
   0x67c3100f,
   0xb2046107,
   0x429a1e1b,
   0xb766a765,
   0xb88bb763,
   0x06f38983,
   0x31448974,
   0x95f30043,
   0x8a808a63,
   0x8a901403,
   0x14048a74,
   0x31433143,
   0x96040034,
   0x26508180,
   0x62d49180,
   0x8180a763,
   0x91802640,
   0xb8899787,
   0xa0c5936c,
   0xb0c1720e,
   0xb0f1b0f1,
   0xb32d7100,
   0x9780c3e0,
   0xc0d0b074,
   0x879193b0,
   0x67ce95e1,
   0x7100b0f1,
   0xc210b078,
   0xa2029780,
   0xb0f1b205,
   0xa32d7100,
   0x7276b06e,
   0x8942a0c1,
   0x3d823182,
   0x8983b88b,
   0x897406f3,
   0x00433144,
   0x8a639233,
   0x14038a80,
   0x8a748a90,
   0x31431404,
   0x00343143,
   0xc8f09604,
   0x62f56ad2,
   0x8724bac0,
   0x87349454,
   0x8ad49464,
   0x86149434,
   0xc01b9444,
   0x84498438,
   0x84618450,
   0x94419430,
   0xb0f0b0e0,
   0xa202b064,
   0x22628212,
   0x722042e7,
   0xb0f5b064,
   0xb116b110,
   0xc410b202,
   0x67ad6af2,
   0xb205624a,
   0xa0e0b110,
   0xa0e6b116,
   0x7276b764,
   0xa003a5a0,
   0xc7c0a002,
   0x72039010,
   0x73057204,
   0xa2027306,
   0x8212b205,
   0x47051e02,
   0xc0e07220,
   0x609267f4,
   0xa202b205,
   0xd0f08792,
   0x67f49862,
   0x720c720e,
   0x730f7311,
   0x821262f6,
   0x43192212,
   0xb016b006,
   0xb002b012,
   0xb014b004,
   0x90307b40,
   0x7b509050,
   0x90609040,
   0xb0d7b107,
   0xb0727100,
   0xd680a0d7,
   0x67ad6b2e,
   0x93b0c090,
   0xbac07000,
   0x9780c040,
   0xb760b761,
   0xb0f1b0c1,
   0x6d017b30,
   0x9ae16d01,
   0x72767100,
   0xb0f1a0c1,
   0x72297b37,
   0x8ab29485,
   0xb003c0f3,
   0x8140b013,
   0x81609290,
   0xb0d09490,
   0x7100b100,
   0x475b2202,
   0x94908450,
   0xb1009293,
   0x84607100,
   0xb1009490,
   0x84307100,
   0x92939490,
   0x7100b100,
   0x94908440,
   0x7100b100,
   0x94908ae0,
   0x7100b100,
   0xc0409486,
   0xb7619780,
   0xb0c1b760,
   0xa0d0b0f1,
   0x7100b100,
   0xa0c17276,
   0x85a0b0f1,
   0x437a1e10,
   0x6381b205,
   0xb766a765,
   0x8200b763,
   0x26202a30,
   0xc0909200,
   0xaac06b82,
   0x67f4c100,
   0x72207000,
   0xc0f07218,
   0x722c9290,
   0x92a1c1f1,
   0x7b26c015,
   0x7b6c7b37,
   0x22008ab0,
   0x7b90439c,
   0x87c09400,
   0x7bb09410,
   0x63a29420,
   0x94007bc0,
   0x94107bd0,
   0x942087c0,
   0x9486aac0,
   0x91b0c100,
   0x398e813e,
   0x1e0ec01d,
   0xc03d43ac,
   0x724e7000,
   0x7b82724f,
   0x9362b053,
   0x6bb3c3b0,
   0x88907388,
   0x88a194e0,
   0x936694f1,
   0x93607b70,
   0x88a48893,
   0x3d333133,
   0x3d343134,
   0x98817000,
   0x88a48893,
   0x3d633133,
   0x3d643134,
   0x94f494e3,
   0x7000b053,
   0x43e51e0e,
   0x8a708a61,
   0x4fdf1810,
   0x10d1c002,
   0x18121611,
   0x3d201620,
   0x4ff31c20,
   0x16101020,
   0x162063f3,
   0x1cd03d20,
   0x10d04bf3,
   0xc00063f3,
   0x8a63c082,
   0x18348a74,
   0x4fef1c24,
   0x4bf11442,
   0x10d063f3,
   0xc00063f3,
   0x700018d0,
   0x88409850,
   0x47f52200,
   0x7000b830
};

PATCH_FUN_SPEC void rf_patch_mce_tof(void)
{
#ifdef __PATCH_NO_UNROLLING
   uint32_t i;
   for (i = 0; i < 509; i++) {
      HWREG(RFC_MCERAM_BASE + 4 * i) = patchTofMce[i];
   }
#else
   const uint32_t *pS = patchTofMce;
   volatile unsigned long *pD = &HWREG(RFC_MCERAM_BASE);
   uint32_t t1, t2, t3, t4, t5, t6, t7, t8;
   uint32_t nIterations = 63;

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
