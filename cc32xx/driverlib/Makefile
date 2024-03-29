#******************************************************************************
#
# Makefile - Rules for building the driverlib.
#
#  Copyright (C) 2015 Texas Instruments Incorporated - http:#www.ti.com/
#
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#*****************************************************************************

# Find subdirectories
RELEASE-CCS-SUBDIRS   = $(wildcard ./ccs/Release/.)
RELEASE-TICLANG-SUBDIRS   = $(wildcard ./ticlang/Release/.)
RELEASE-GCC-SUBDIRS   = $(wildcard ./gcc/Release/.)
RELEASE-IAR-SUBDIRS   = $(wildcard ./iar/Release/.)

include ../../../../../imports.mak

RELEASE-SUBDIRS =
ifneq ($(CCS_ARMCOMPILER),)
	RELEASE-SUBDIRS += $(RELEASE-CCS-SUBDIRS)
endif
ifneq ($(TICLANG_ARMCOMPILER),)
	RELEASE-SUBDIRS += $(RELEASE-TICLANG-SUBDIRS)
endif
ifneq ($(GCC_ARMCOMPILER),)
	RELEASE-SUBDIRS += $(RELEASE-GCC-SUBDIRS)
endif
ifneq ($(IAR_ARMCOMPILER),)
	RELEASE-SUBDIRS += $(RELEASE-IAR-SUBDIRS)
endif

.PHONY: release $(RELEASE-SUBDIRS)

# rules for building
all: release

release: $(RELEASE-SUBDIRS)

$(RELEASE-SUBDIRS):
	@ $(MAKE) -C $@ -f makefile.defs

CLEAN-RELEASE-SUBDIRS = $(addprefix clean-,$(RELEASE-SUBDIRS))

.PHONY: clean-release $(CLEAN-RELEASE-SUBDIRS)

# rules for cleaning
clean: clean-release

clean-release: $(CLEAN-RELEASE-SUBDIRS)

$(CLEAN-RELEASE-SUBDIRS):
	@ $(MAKE) -C $(subst clean-,,$@) -f makefile.defs clean