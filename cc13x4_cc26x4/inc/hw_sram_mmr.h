/******************************************************************************
*  Filename:       hw_sram_mmr_h
*
* Copyright (c) 2015 - 2017, Texas Instruments Incorporated
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1) Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2) Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3) Neither the name of the ORGANIZATION nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_SRAM_MMR_H__
#define __HW_SRAM_MMR_H__

//*****************************************************************************
//
// This section defines the register offsets of
// SRAM_MMR component
//
//*****************************************************************************
// Parity Error Control
#define SRAM_MMR_O_PER_CTL                                          0x00000000

// Parity Error Check
#define SRAM_MMR_O_PER_CHK                                          0x00000004

// Parity Error Debug
#define SRAM_MMR_O_PER_DBG                                          0x00000008

// Memory Control
#define SRAM_MMR_O_MEM_CTL                                          0x0000000C

// Memory Status
#define SRAM_MMR_O_MEM_STA                                          0x00000010

//*****************************************************************************
//
// Register: SRAM_MMR_O_PER_CTL
//
//*****************************************************************************
// Field:     [8] PER_DISABLE
//
// Parity Status Disable
//
// 0: A parity error will update PER_CHK.PER_ADDR field
// 1: Parity error does not update PER_CHK.PER_ADDR field
#define SRAM_MMR_PER_CTL_PER_DISABLE                                0x00000100
#define SRAM_MMR_PER_CTL_PER_DISABLE_BITN                                    8
#define SRAM_MMR_PER_CTL_PER_DISABLE_M                              0x00000100
#define SRAM_MMR_PER_CTL_PER_DISABLE_S                                       8

// Field:     [0] PER_DEBUG_ENABLE
//
// Parity Error Debug Enable
//
// 0: Normal operation
// 1: An address offset can be written to PER_DBG.PER_DEBUG_ADDR and parity
// errors will be generated on reads from within this offset
#define SRAM_MMR_PER_CTL_PER_DEBUG_ENABLE                           0x00000001
#define SRAM_MMR_PER_CTL_PER_DEBUG_ENABLE_BITN                               0
#define SRAM_MMR_PER_CTL_PER_DEBUG_ENABLE_M                         0x00000001
#define SRAM_MMR_PER_CTL_PER_DEBUG_ENABLE_S                                  0

//*****************************************************************************
//
// Register: SRAM_MMR_O_PER_CHK
//
//*****************************************************************************
// Field:  [23:0] PER_ADDR
//
// Parity Error Address Offset
// Returns the last address offset which resulted in a parity error during an
// SRAM read. The address offset returned is always the word-aligned address
// that contains the location with the parity error. For parity faults on non
// word-aligned accesses, CPU_SCS:BFAR.ADDRESS will hold the address of the
// location that resulted in parity error.
#define SRAM_MMR_PER_CHK_PER_ADDR_W                                         24
#define SRAM_MMR_PER_CHK_PER_ADDR_M                                 0x00FFFFFF
#define SRAM_MMR_PER_CHK_PER_ADDR_S                                          0

//*****************************************************************************
//
// Register: SRAM_MMR_O_PER_DBG
//
//*****************************************************************************
// Field:  [23:0] PER_DEBUG_ADDR
//
// Debug Parity Error Address Offset
// When PER_CTL.PER_DEBUG is 1, this field is used to set a parity debug
// address offset. The address offset must be a word-aligned address. Writes
// within this address offset will force incorrect parity bits to be stored
// together with the data written. The following reads within this same address
// offset will thus result in parity errors to be generated.
#define SRAM_MMR_PER_DBG_PER_DEBUG_ADDR_W                                   24
#define SRAM_MMR_PER_DBG_PER_DEBUG_ADDR_M                           0x00FFFFFF
#define SRAM_MMR_PER_DBG_PER_DEBUG_ADDR_S                                    0

//*****************************************************************************
//
// Register: SRAM_MMR_O_MEM_CTL
//
//*****************************************************************************
// Field:  [31:8] MEM_SEL
//
// Memory Instance Select
//
// This field is used to enable/disable initialization of each SRAM instance
// when triggered using MEM_CTL.MEM_CLR_EN. Each bit corresponds to the
// respective SRAM instance.
//
// bit[x]:
// 0: Initialization of instance x is disabled
// 1: Initialization of instance x is enabled
#define SRAM_MMR_MEM_CTL_MEM_SEL_W                                          24
#define SRAM_MMR_MEM_CTL_MEM_SEL_M                                  0xFFFFFF00
#define SRAM_MMR_MEM_CTL_MEM_SEL_S                                           8

// Field:     [1] MEM_BUSY
//
// Memory Busy status
//
// 0: Memory accepts transfers
// 1: Memory controller is busy during initialization. Read and write transfers
// are not performed.
#define SRAM_MMR_MEM_CTL_MEM_BUSY                                   0x00000002
#define SRAM_MMR_MEM_CTL_MEM_BUSY_BITN                                       1
#define SRAM_MMR_MEM_CTL_MEM_BUSY_M                                 0x00000002
#define SRAM_MMR_MEM_CTL_MEM_BUSY_S                                          1

// Field:     [0] MEM_CLR_EN
//
// Memory Contents Initialization enable
//
// Writing 1 to MEM_CLR_EN will start memory initialization. The contents of
// all byte locations will be initialized to 0x00. MEM_BUSY will be 1 until
// memory initialization has completed.
#define SRAM_MMR_MEM_CTL_MEM_CLR_EN                                 0x00000001
#define SRAM_MMR_MEM_CTL_MEM_CLR_EN_BITN                                     0
#define SRAM_MMR_MEM_CTL_MEM_CLR_EN_M                               0x00000001
#define SRAM_MMR_MEM_CTL_MEM_CLR_EN_S                                        0

//*****************************************************************************
//
// Register: SRAM_MMR_O_MEM_STA
//
//*****************************************************************************
// Field:  [31:8] MEM_STA
//
// Memory Instance Status
//
// This field gives the current status of each SRAM instance. When an instance
// is being initialized the corresponding bit is set to 1, 0 otherwise.
//
// bit[x]:
// 0 : Instance x is in normal mode
// 1 : Instance x is getting initialized
#define SRAM_MMR_MEM_STA_MEM_STA_W                                          24
#define SRAM_MMR_MEM_STA_MEM_STA_M                                  0xFFFFFF00
#define SRAM_MMR_MEM_STA_MEM_STA_S                                           8


#endif // __SRAM_MMR__
