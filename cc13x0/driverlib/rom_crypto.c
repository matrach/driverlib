/*******************************************************************************
*  Filename:       rom_crypto.c
*  Revised:        $Date$
*  Revision:       $Revision$
*
*  Description:    This is the implementation for the API to the AES, ECC and
*                  SHA256 functions built into ROM on the CC26xx.
*
*  Copyright (c) 2015 - 2017, Texas Instruments Incorporated
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
*******************************************************************************/

#include <stdint.h>
#include "rom_crypto.h"

///////////////////////////////////* AES-128 *//////////////////////////////////

/* AES - ECB */
typedef void(*aes_ecb_encrypt_t)(uint8_t *, uint16_t, uint8_t *);
aes_ecb_encrypt_t ROM_AES_ECB_encrypt = (aes_ecb_encrypt_t)(0x10018a99);

typedef void(*aes_ecb_decrypt_t)(uint8_t *, uint16_t, uint8_t *);
aes_ecb_decrypt_t ROM_AES_ECB_decrypt = (aes_ecb_decrypt_t)(0x10018ac5);

//*****************************************************************************
// AES_ECB_EncryptData
//*****************************************************************************
void
AES_ECB_EncryptData(uint8_t *text, uint16_t textLen, uint8_t *aesKey)
{
    ROM_AES_ECB_encrypt(text, textLen, aesKey);
}

//*****************************************************************************
// AES_ECB_DecryptData
//*****************************************************************************
void
AES_ECB_DecryptData(uint8_t *text, uint16_t textLen, uint8_t *aesKey)
{
    ROM_AES_ECB_decrypt(text, textLen, aesKey);
}

/* AES - CCM */
typedef int8_t(*aes_ccm_encrypt_t)(uint8_t,
                                   uint8_t,
                                   uint8_t *,
                                   uint8_t *,
                                   uint16_t,
                                   uint8_t *,
                                   uint16_t,
                                   uint8_t *,
                                   uint8_t *,
                                   uint8_t);
aes_ccm_encrypt_t ROM_AES_CCM_encrypt = (aes_ccm_encrypt_t)(0x10018a19);

typedef int8_t(*aes_ccm_decrypt_t)(uint8_t,
                                   uint8_t,
                                   uint8_t *,
                                   uint8_t *,
                                   uint16_t,
                                   uint8_t *,
                                   uint16_t,
                                   uint8_t *,
                                   uint8_t *,
                                   uint8_t);
aes_ccm_decrypt_t ROM_AES_CCM_decrypt = (aes_ccm_decrypt_t)(0x10018a35);

//*****************************************************************************
// AES_CCM_EncryptData
//*****************************************************************************
int8_t
AES_CCM_EncryptData(uint8_t encryptFlag,
                    uint8_t MACLen,
                    uint8_t *nonce,
                    uint8_t *plainText,
                    uint16_t textLen,
                    uint8_t *addDataBuf,
                    uint16_t addBufLen,
                    uint8_t *aesKey,
                    uint8_t *MAC,
                    uint8_t ccmLVal)
{
    return ROM_AES_CCM_encrypt(encryptFlag,
                               MACLen,
                               nonce,
                               plainText,
                               textLen,
                               addDataBuf,
                               addBufLen,
                               aesKey,
                               MAC,
                               ccmLVal);
}

//*****************************************************************************
// AES_CCM_DecryptData
//*****************************************************************************
int8_t
AES_CCM_DecryptData(uint8_t decryptFlag,
                    uint8_t MACLen,
                    uint8_t *nonce,
                    uint8_t *cipherText,
                    uint16_t textLen,
                    uint8_t *addDataBuf,
                    uint16_t addBufLen,
                    uint8_t *aesKey,
                    uint8_t *MAC,
                    uint8_t ccmLVal)
{
    return ROM_AES_CCM_decrypt(decryptFlag,
                               MACLen,
                               nonce,
                               cipherText,
                               textLen,
                               addDataBuf,
                               addBufLen,
                               aesKey,
                               MAC,
                               ccmLVal);

}

/* AES - CTR */
typedef uint8_t(*aes_ctr_encrypt_t)(uint8_t *, uint16_t, uint8_t *, uint8_t *, uint8_t *);
aes_ctr_encrypt_t ROM_AES_CTR_encrypt = (aes_ctr_encrypt_t)(0x100175ed);

typedef uint8_t(*aes_ctr_decrypt_t)(uint8_t *, uint16_t, uint8_t *, uint8_t *, uint8_t *);
aes_ctr_decrypt_t ROM_AES_CTR_decrypt = (aes_ctr_decrypt_t)(0x10017771);

//*****************************************************************************
// AES_CTR_EncryptData
//*****************************************************************************
uint8_t
AES_CTR_EncryptData(uint8_t *plainText, uint16_t textLen, uint8_t *aesKey, uint8_t *nonce, uint8_t *initVector)
{
    return ROM_AES_CTR_encrypt(plainText, textLen, aesKey, nonce, initVector);
}

//*****************************************************************************
// AES_CTR_DecryptData
//*****************************************************************************
uint8_t
AES_CTR_DecryptData(uint8_t *cipherText, uint16_t textLen, uint8_t *aesKey, uint8_t *nonce, uint8_t *initVector)
{
    return ROM_AES_CTR_decrypt(cipherText, textLen, aesKey, nonce, initVector);
}

////////////////////////////////////* ECC *////////////////////////////////////
#ifdef ECC_PRIME_NIST256_CURVE
//#define PARAM_P NIST256_p;
#define PARAM_P 0x10018b0c;

//#define PARAM_R NIST256_r;
#define PARAM_R 0x10018b30;

//#define PARAM_A NIST256_a;
#define PARAM_A 0x10018b54;

//#define PARAM_B NIST256_b;
#define PARAM_B 0x10018b78;

//#define PARAM_GX NIST256_Gx;
#define PARAM_GX 0x10018b9c;

//#define PARAM_GY NIST256_Gy;
#define PARAM_GY 0x10018bc0;

#endif

// ECC ROM addresses of library functions for CC13x
#define IMPORTLENGTH        0x100159a9
#define IMPORTDATA          0x10015a35
#define EXPORTOPERAND       0x10015a11
#define zSUB                0x10015d5d
#define mMULT               0x10015f81
#define mADD                0x10016551
#define mSET                0x10015a9d
#define zSET                0x10015bcd
#define IMPORTMODULUS       0x100159ad
#define IMPORTOPERAND       0x100159d1

static uint32_t *eccRom_workzone;

typedef union
{
    uint8_t     byte[32];
    uint32_t    word[32 / sizeof(uint32_t)];
} PKA_EccParam256;

const PKA_EccParam256 k2Mont  = { .byte = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0xff, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff,
                                            0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                            0xfd, 0xff, 0xff, 0xff, 0x04, 0x00, 0x00, 0x00 }};

const PKA_EccParam256 aMont  = { .byte  = { 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                            0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x04, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff }};

const PKA_EccParam256 bMont  = { .byte  = { 0xdf, 0xbd, 0xc4, 0x29, 0x62, 0xdf, 0x9c, 0xd8,
                                            0x90, 0x30, 0x84, 0x78, 0xcd, 0x05, 0xf0, 0xac,
                                            0xd6, 0x2e, 0x21, 0xf7, 0xab, 0x20, 0xa2, 0xe5,
                                            0x34, 0x48, 0x87, 0x04, 0x1d, 0x06, 0x30, 0xdc }};

#define DATA_P_BUFFER_ADDR      0x20004f48
#define DATA_R_BUFFER_ADDR      0x20004f4c
#define DATA_A_BUFFER_ADDR      0x20004f50
#define DATA_B_BUFFER_ADDR      0x20004fa8
#define DATA_GX_BUFFER_ADDR     0x20004fa0
#define DATA_GY_BUFFER_ADDR     0x20004fa4
#define WIN_SIZE_BUFFER_ADDR    0x20004f40
#define WORKZONE_BUFFER_ADDR    0x20004f44

static uint32_t **dataP        = ((uint32_t **)DATA_P_BUFFER_ADDR);
static uint32_t **dataR        = ((uint32_t **)DATA_R_BUFFER_ADDR);
static uint32_t **dataA        = ((uint32_t **)DATA_A_BUFFER_ADDR);
static uint32_t **dataB        = ((uint32_t **)DATA_B_BUFFER_ADDR);
static uint32_t **dataGx       = ((uint32_t **)DATA_GX_BUFFER_ADDR);
static uint32_t **dataGy       = ((uint32_t **)DATA_GY_BUFFER_ADDR);
static uint8_t *winSize        = ((uint8_t *)WIN_SIZE_BUFFER_ADDR);
static uint32_t **workZone     = ((uint32_t **)WORKZONE_BUFFER_ADDR);

static bool buffersAreEqual(uint32_t *buffer0, uint32_t *buffer1, uint32_t bufferWordLength);
static bool isAllZeros(uint32_t *buffer, uint32_t bufferWordLength);

typedef uint32_t (*ImportLength_t)(uint32_t *);
ImportLength_t ROM_ECC_IMPORTLENGTH = (ImportLength_t)(IMPORTLENGTH);

typedef uint32_t (*ImportData_t)(uint32_t *, uint32_t *);
ImportData_t ROM_ECC_IMPORTDATA = (ImportData_t)(IMPORTDATA);

typedef uint32_t (*zSub_t)(uint32_t *, uint32_t *, uint32_t *);
zSub_t ROM_ECC_zSUB = (zSub_t)(zSUB);

typedef uint32_t (*mMult_t)(uint32_t *, uint32_t *, uint32_t *);
mMult_t ROM_ECC_mMULT = (mMult_t)(mMULT);

typedef uint32_t (*mAdd_t)(uint32_t *, uint32_t *, uint32_t *);
mAdd_t ROM_ECC_mADD = (mAdd_t)(mADD);

typedef void (*mSet_t)(uint32_t *, uint32_t);
mSet_t ROM_ECC_mSET = (mSet_t)(mSET);

typedef void(*zSet_t)(uint32_t);
zSet_t ROM_ECC_zSET = (zSet_t)(zSET);

typedef uint32_t (*ImportModulus_t)(uint32_t *, uint32_t *);
ImportModulus_t ROM_ECC_IMPORTMODULUS = (ImportModulus_t)(IMPORTMODULUS);

typedef uint8_t(*ecc_keygen_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *);
ecc_keygen_t ROM_ECC_generatekey = (ecc_keygen_t)(0x10017dbd);

typedef uint8_t(*ecdsa_sign_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *, uint32_t *);
ecdsa_sign_t ROM_ECDSA_sign = (ecdsa_sign_t)(0x10017969);

typedef uint8_t(*ecdsa_verify_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *, uint32_t *);
ecdsa_verify_t ROM_ECDSA_verify = (ecdsa_verify_t)(0x10017b01);

typedef uint8_t(*ecdh_computeSharedSecret_t)(uint32_t *, uint32_t *,uint32_t *, uint32_t *, uint32_t *);
ecdh_computeSharedSecret_t ROM_ECDH_computeSharedSecret = (ecdh_computeSharedSecret_t)(0x10017ded);

static bool buffersAreEqual(uint32_t *buffer0, uint32_t *buffer1, uint32_t bufferWordLength)
{
    uint32_t tempResult = 0;
    uint32_t i;

    // XOR each 32-bit word of the buffer together and OR the results.
    // If the OR'd result is non-zero, the buffers do not match.
    // There is no branch based on the content of the buffers here to avoid
    // timing attacks.

    for (i = 0; i < bufferWordLength; i++)
    {
        tempResult |= buffer0[i] ^ buffer1[i];
    }

    return ((tempResult == 0) ? true : false);
}

static bool isAllZeros(uint32_t *buffer, uint32_t bufferWordLength)
{
    uint32_t i;
    uint32_t bufferBits = 0;
    bool status;

    for (i = 0; i < bufferWordLength; i++)
    {
        bufferBits |= buffer[i];
    }

    if (bufferBits == 0)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

//*****************************************************************************
// ECC_initialize
//*****************************************************************************
void
ECC_initialize(uint32_t *pWorkzone)
{
    // Initialize curve parameters
    *dataP = (uint32_t *)PARAM_P;

    *dataR = (uint32_t *)PARAM_R;

    *dataA = (uint32_t *)PARAM_A;

    *dataB = (uint32_t *)PARAM_B;

    *dataGx = (uint32_t *)PARAM_GX;

    *dataGy = (uint32_t *)PARAM_GY;

    // Initialize window size
    *winSize = (uint8_t) ECC_WINDOW_SIZE;

    // Initialize work zone
    *workZone = (uint32_t *) pWorkzone;

    eccRom_workzone = pWorkzone;

    // Set ECC ROM's global LEN variable used by zSUB
    ROM_ECC_zSET(ROM_ECC_IMPORTLENGTH(*dataP));

}

//*****************************************************************************
// ECC_validatePublicKeyWeierstrass
//*****************************************************************************
static uint8_t ECC_validatePublicKeyWeierstrass(uint32_t *curvePointX, uint32_t *curvePointY)
{
    uint32_t pkaResult;
    uint32_t len;

    // Some operation require modulus form operators of 10 words length
    // ROM_ECC_IMPORTLENGTH() returns the word length of input (Parameter P)
    uint32_t modBufLen = ROM_ECC_IMPORTLENGTH(*dataP) + 2;

    uint32_t *primeMod10Wrd;
    uint32_t *xImp;
    uint32_t *yImp;
    uint32_t *primeMod;
    uint32_t *tempBuf1;
    uint32_t *tempBuf2;
    uint32_t *gxMont;
    uint32_t *gyMont;
    uint32_t *x2Hat;
    uint32_t *x3Hat;
    uint32_t *xaHat;
    uint32_t *y2Hat;

    // Use allocated workzone instead of allocating memory
    primeMod10Wrd = eccRom_workzone;
    xImp          = (primeMod10Wrd + modBufLen);
    yImp          = (xImp + modBufLen);
    primeMod      = (yImp + modBufLen);
    gxMont        = (primeMod + modBufLen);
    gyMont        = (gxMont + modBufLen);
    x2Hat         = (gyMont + modBufLen);
    x3Hat         = (x2Hat + modBufLen);
    xaHat         = (x3Hat + modBufLen);
    y2Hat         = (xaHat + modBufLen);
    tempBuf1      = (y2Hat + modBufLen);
    tempBuf2      = (tempBuf1 + modBufLen);

    // Clear the locations used in the allocated workzone before loading data into the workzone
    memset(eccRom_workzone, 0x00, 12 * modBufLen * sizeof(uint32_t));

    // Load curve order as modulus
    len = ROM_ECC_IMPORTMODULUS(primeMod10Wrd, *dataP);

    // Set prime mod
    ROM_ECC_mSET(primeMod10Wrd, len);

    // Import  X point to operand format form for range check
    ROM_ECC_IMPORTDATA(xImp, curvePointX);

    // Import  Y point to operand format form for range check
    ROM_ECC_IMPORTDATA(yImp, curvePointY);

    // Import  P point to operand format form for range check
    ROM_ECC_IMPORTDATA(primeMod, *dataP);

    // Verify X != 0 (not point at infinity)
    if (isAllZeros(xImp, len))
    {
        return ECC_X_ZERO;
    }

    // Verify Y != 0 (not point at infinity)
    if (isAllZeros(yImp, len))
    {
        return ECC_Y_ZERO;
    }

    // Check X point range by subtracting the X-P
    // If  X <= [P-1], zSUB will return 1 indicating borrow and len'th byte will be set to zero
    pkaResult = ROM_ECC_zSUB(tempBuf1, xImp, primeMod);

    if((pkaResult != 1) || (tempBuf1[len] != 0))
    {
        return ECC_X_LARGER_THAN_PRIME;
    }

    // Clear buffer
    memset(tempBuf1, 0x00, (modBufLen*sizeof(uint32_t)));

    // Check Y point range by subtracting the Y-P
    // If  Y <= [P-1], zSUB will return 1 indicating borrow and len'th byte will be set to zero
    pkaResult = ROM_ECC_zSUB(tempBuf1, yImp, primeMod);

    if((pkaResult != 1) || (tempBuf1[len] != 0))
    {
        return ECC_Y_LARGER_THAN_PRIME;
    }

    // No need to compute the Montgomery constant
    // Convert point to  [X, Y] Montgomery format
    ROM_ECC_mMULT(gxMont, xImp, (uint32_t *)&k2Mont.word);  // Both X and Y points are in operand format
    ROM_ECC_mMULT(gyMont, yImp, (uint32_t *)&k2Mont.word);

    // Compute x^2 hat
    ROM_ECC_mMULT(x2Hat, gxMont, gxMont);

    // Compute x^3 hat
    ROM_ECC_mMULT(x3Hat, x2Hat, gxMont);

    // Compute xa hat
    ROM_ECC_mMULT(xaHat, gxMont, (uint32_t *)&aMont.word);

    // Compute x3.ax hat
    memset(tempBuf1, 0x00, sizeof(uint32_t)*10);
    ROM_ECC_mADD(tempBuf1, x3Hat, xaHat);

    // Compute x3.ax.b hat
    ROM_ECC_mADD(tempBuf1, tempBuf1, (uint32_t *)&bMont.word);

    // Compute y2 hat
    ROM_ECC_mMULT(y2Hat, gyMont, gyMont);

    memset(tempBuf2, 0x00, modBufLen * sizeof(uint32_t));

    if(buffersAreEqual(y2Hat, tempBuf1, len) != true)
    {
        return ECC_POINT_NOT_ON_CURVE;
    }

    return ECC_POINT_ON_CURVE;
}

//*****************************************************************************
// ECC_validatePrivateKeyWeierstrass
//*****************************************************************************
static uint8_t ECC_validatePrivateKeyWeierstrass(uint32_t *privateKey)
{
    uint32_t result;

    // ROM_ECC_IMPORTLENGTH() returns the word length of input (Parameter P)
    uint32_t len = ROM_ECC_IMPORTLENGTH(*dataP);

    // Some operation require modulus form operators of 10 words length
    uint32_t modBufLen = len + 2;

    uint32_t *order;
    uint32_t *privKey;
    uint32_t *tempBuf;

    order = eccRom_workzone;
    privKey = (order + modBufLen);
    tempBuf = (privKey + modBufLen);

    // Clear the locations used in the allocated workzone before loading data before loading data used in the workzone
    memset(eccRom_workzone, 0x00, 3 * modBufLen * sizeof(uint32_t));

    // Import order to operand format form for range check
    ROM_ECC_IMPORTDATA(order, *dataR);

    // Import private key to operand format form for range check
    ROM_ECC_IMPORTDATA(privKey, privateKey);

    // Verify private key != 0
    if (isAllZeros(privKey, len))
    {
        return PRIVATE_KEY_ZERO;
    }

    // Check private key range by subtracting privateKey-N
    // If  private key <= [P-1], zSUB will return 1 indicating borrow and len'th byte will be set to zero
    result = ROM_ECC_zSUB(tempBuf, privKey, order);

    if((result != 1) || (tempBuf[len] != 0))
    {
        return PRIVATE_KEY_LARGER_EQUAL_ORDER;
    }

    return ECC_PRIVATE_VALID;
}

//*****************************************************************************
// ECC_generateKey
//*****************************************************************************
uint8_t
ECC_generateKey(uint32_t *randString, uint32_t *privateKey, uint32_t *publicKey_x, uint32_t *publicKey_y)
{
    uint8_t status;

    status = ECC_validatePrivateKeyWeierstrass(privateKey);
    if (status == ECC_PRIVATE_VALID)
    {
        status = (uint8_t)ROM_ECC_generatekey((uint32_t*)randString,
                                              (uint32_t*)privateKey,
                                              (uint32_t*)publicKey_x,
                                              (uint32_t*)publicKey_y);
    }

    return status;

}

//*****************************************************************************
// ECC_generateKeyWithoutValidation
//*****************************************************************************
uint8_t
ECC_generateKeyWithoutValidation(uint32_t *randString,
                                 uint32_t *privateKey,
                                 uint32_t *publicKey_x,
                                 uint32_t *publicKey_y)
{
    return (uint8_t)ROM_ECC_generatekey((uint32_t*)randString,
                                    (uint32_t*)privateKey,
                                    (uint32_t*)publicKey_x,
                                    (uint32_t*)publicKey_y);

}

//*****************************************************************************
// ECC_ECDSA_sign
//*****************************************************************************
uint8_t
ECC_ECDSA_sign(uint32_t *secretKey, uint32_t *text, uint32_t *randString, uint32_t *sign1, uint32_t *sign2)
{
  uint8_t status;

  status = ECC_validatePrivateKeyWeierstrass(randString);
  if(status == ECC_PRIVATE_VALID)
  {
    status = (uint8_t)ROM_ECDSA_sign((uint32_t*)secretKey,
                                     (uint32_t*)text,
                                     (uint32_t*)randString,
                                     (uint32_t*)sign1,
                                     (uint32_t*)sign2);
  }
  else
  {
    status = ECC_ECDSA_RAND_STRING_INVALID;
  }

  return status;
}

//*****************************************************************************
// ECC_ECDSA_signWithoutValidation
//*****************************************************************************
uint8_t
ECC_ECDSA_signWithoutValidation(uint32_t *secretKey,
                                uint32_t *text,
                                uint32_t *randString,
                                uint32_t *sign1,
                                uint32_t *sign2)
{
    return (uint8_t)ROM_ECDSA_sign((uint32_t*)secretKey,
                                   (uint32_t*)text,
                                   (uint32_t*)randString,
                                   (uint32_t*)sign1,
                                   (uint32_t*)sign2);
}

//*****************************************************************************
// ECC_ECDSA_verify
//*****************************************************************************
uint8_t
ECC_ECDSA_verify(uint32_t *publicKey_x, uint32_t *publicKey_y, uint32_t *text, uint32_t *sign1, uint32_t *sign2)
{
    uint8_t status;

    status = ECC_validatePublicKeyWeierstrass(publicKey_x, publicKey_y);
    if (status != ECC_POINT_ON_CURVE)
    {
        return status;
    }

    status = ECC_validatePrivateKeyWeierstrass(sign1);
    if (status != ECC_PRIVATE_VALID)
    {
        return ECC_ECDSA_S1_INVALID;
    }

    status = ECC_validatePrivateKeyWeierstrass(sign2);
    if (status != ECC_PRIVATE_VALID)
    {
        return ECC_ECDSA_S2_INVALID;
    }

    return (uint8_t)ROM_ECDSA_verify((uint32_t*)publicKey_x,
                                     (uint32_t*)publicKey_y,
                                     (uint32_t*)text,
                                     (uint32_t*)sign1,
                                     (uint32_t*)sign2);
}

//*****************************************************************************
// ECC_ECDSA_verifyWithoutValidation
//*****************************************************************************
uint8_t
ECC_ECDSA_verifyWithoutValidation(uint32_t *publicKey_x,
                                  uint32_t *publicKey_y,
                                  uint32_t *text,
                                  uint32_t *sign1,
                                  uint32_t *sign2)
{
    return (uint8_t)ROM_ECDSA_verify((uint32_t*)publicKey_x,
                                     (uint32_t*)publicKey_y,
                                     (uint32_t*)text,
                                     (uint32_t*)sign1,
                                     (uint32_t*)sign2);
}

//*****************************************************************************
// ECC_ECDH_computeSharedSecret
//*****************************************************************************
uint8_t
ECC_ECDH_computeSharedSecret(uint32_t *privateKey,
                             uint32_t *publicKey_x,
                             uint32_t *publicKey_y,
                             uint32_t *sharedSecret_x,
                             uint32_t *sharedSecret_y)
{
    uint8_t status = 0;

    status = ECC_validatePublicKeyWeierstrass(publicKey_x, publicKey_y);
    if (status == ECC_POINT_ON_CURVE)
    {
        status = (uint8_t)ROM_ECDH_computeSharedSecret((uint32_t*)privateKey,
                                                       (uint32_t*)publicKey_x,
                                                       (uint32_t*)publicKey_y,
                                                       (uint32_t*)sharedSecret_x,
                                                       (uint32_t*)sharedSecret_y);
    }

    return status;
}

//*****************************************************************************
// ECC_ECDH_computeSharedSecretWithoutValidation
//*****************************************************************************
uint8_t
ECC_ECDH_computeSharedSecretWithoutValidation(uint32_t *privateKey,
                                              uint32_t *publicKey_x,
                                              uint32_t *publicKey_y,
                                              uint32_t *sharedSecret_x,
                                              uint32_t *sharedSecret_y)
{
    return (uint8_t)ROM_ECDH_computeSharedSecret((uint32_t*)privateKey,
                                                 (uint32_t*)publicKey_x,
                                                 (uint32_t*)publicKey_y,
                                                 (uint32_t*)sharedSecret_x,
                                                 (uint32_t*)sharedSecret_y);
}

//////////////////////////////////* SHA-256 *///////////////////////////////////

typedef uint8_t(*sha256_full_t)(SHA256_memory_t *, uint8_t *, uint8_t *, uint32_t);
sha256_full_t ROM_SHA256_runFullAlg = (sha256_full_t)(0x10018129);

typedef uint8_t(*sha256_init_t)(SHA256_memory_t *);
sha256_init_t ROM_SHA256_initialize = (sha256_init_t)(0x10017ffd);

typedef uint8_t(*sha256_process_t)(SHA256_memory_t *, uint8_t *, uint32_t);
sha256_process_t ROM_SHA256_execute = (sha256_process_t)(0x10018019);

typedef uint8_t(*sha256_final_t)(SHA256_memory_t *, uint8_t *);
sha256_final_t ROM_SHA256_output = (sha256_final_t)(0x10018089);

//*****************************************************************************
// SHA256_runFullAlgorithm
//*****************************************************************************
uint8_t
SHA256_runFullAlgorithm(SHA256_memory_t *memory, uint8_t *pBufIn, uint32_t bufLen, uint8_t *pBufOut)
{
    return (uint8_t)ROM_SHA256_runFullAlg(memory, pBufOut, pBufIn, bufLen);
}

//*****************************************************************************
// SHA256_initialize
//*****************************************************************************
uint8_t
SHA256_initialize(SHA256_memory_t *memory)
{
    return (uint8_t)ROM_SHA256_initialize(memory);
}

//*****************************************************************************
// SHA256_execute
//*****************************************************************************
uint8_t
SHA256_execute(SHA256_memory_t *memory, uint8_t *pBufIn, uint32_t bufLen)
{
    return (uint8_t)ROM_SHA256_execute(memory,pBufIn, bufLen);
}

//*****************************************************************************
// SHA256_output
//*****************************************************************************
uint8_t
SHA256_output(SHA256_memory_t *memory, uint8_t *pBufOut)
{
    return (uint8_t)ROM_SHA256_output(memory, pBufOut);
}
