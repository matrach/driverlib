# Get directory of this makefile
MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Specify the default makedefs file, which can be overridden at the command line
MAKEDEFS = $(MAKEFILE_DIR)makedefs
include $(MAKEDEFS)

# Always builds phony rules
.PHONY: all clean

# Builds driverlib.lib
all :
		@ rm -f $(MAKEFILE_DIR)driverlib.lib
		@ rm -f $(MAKEFILE_DIR)*.o
		$(COMPILER_TOOL) --version
		@ echo TIARMCLANG: Compile adi.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "adi.o" $(MAKEFILE_DIR)../../../driverlib/adi.c
		@ echo TIARMCLANG: Compile aes.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aes.o" $(MAKEFILE_DIR)../../../driverlib/aes.c
		@ echo TIARMCLANG: Compile aon_batmon.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aon_batmon.o" $(MAKEFILE_DIR)../../../driverlib/aon_batmon.c
		@ echo TIARMCLANG: Compile aon_event.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aon_event.o" $(MAKEFILE_DIR)../../../driverlib/aon_event.c
		@ echo TIARMCLANG: Compile aon_ioc.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aon_ioc.o" $(MAKEFILE_DIR)../../../driverlib/aon_ioc.c
		@ echo TIARMCLANG: Compile aon_pmctl.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aon_pmctl.o" $(MAKEFILE_DIR)../../../driverlib/aon_pmctl.c
		@ echo TIARMCLANG: Compile aon_rtc.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aon_rtc.o" $(MAKEFILE_DIR)../../../driverlib/aon_rtc.c
		@ echo TIARMCLANG: Compile aux_adc.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aux_adc.o" $(MAKEFILE_DIR)../../../driverlib/aux_adc.c
		@ echo TIARMCLANG: Compile aux_smph.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aux_smph.o" $(MAKEFILE_DIR)../../../driverlib/aux_smph.c
		@ echo TIARMCLANG: Compile aux_sysif.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aux_sysif.o" $(MAKEFILE_DIR)../../../driverlib/aux_sysif.c
		@ echo TIARMCLANG: Compile aux_tdc.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "aux_tdc.o" $(MAKEFILE_DIR)../../../driverlib/aux_tdc.c
		@ echo TIARMCLANG: Compile ccfgread.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "ccfgread.o" $(MAKEFILE_DIR)../../../driverlib/ccfgread.c
		@ echo TIARMCLANG: Compile chipinfo.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "chipinfo.o" $(MAKEFILE_DIR)../../../driverlib/chipinfo.c
		@ echo TIARMCLANG: Compile cpu.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "cpu.o" $(MAKEFILE_DIR)../../../driverlib/cpu.c
		@ echo TIARMCLANG: Compile crypto.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "crypto.o" $(MAKEFILE_DIR)../../../driverlib/crypto.c
		@ echo TIARMCLANG: Compile ddi.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "ddi.o" $(MAKEFILE_DIR)../../../driverlib/ddi.c
		@ echo TIARMCLANG: Compile debug.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "debug.o" $(MAKEFILE_DIR)../../../driverlib/debug.c
		@ echo TIARMCLANG: Compile driverlib_release.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "driverlib_release.o" $(MAKEFILE_DIR)../../../driverlib/driverlib_release.c
		@ echo TIARMCLANG: Compile event.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "event.o" $(MAKEFILE_DIR)../../../driverlib/event.c
		@ echo TIARMCLANG: Compile flash.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "flash.o" $(MAKEFILE_DIR)../../../driverlib/flash.c
		@ echo TIARMCLANG: Compile gpio.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "gpio.o" $(MAKEFILE_DIR)../../../driverlib/gpio.c
		@ echo TIARMCLANG: Compile i2c.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "i2c.o" $(MAKEFILE_DIR)../../../driverlib/i2c.c
		@ echo TIARMCLANG: Compile i2s.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "i2s.o" $(MAKEFILE_DIR)../../../driverlib/i2s.c
		@ echo TIARMCLANG: Compile interrupt.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "interrupt.o" $(MAKEFILE_DIR)../../../driverlib/interrupt.c
		@ echo TIARMCLANG: Compile ioc.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "ioc.o" $(MAKEFILE_DIR)../../../driverlib/ioc.c
		@ echo TIARMCLANG: Compile osc.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "osc.o" $(MAKEFILE_DIR)../../../driverlib/osc.c
		@ echo TIARMCLANG: Compile pka.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "pka.o" $(MAKEFILE_DIR)../../../driverlib/pka.c
		@ echo TIARMCLANG: Compile prcm.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "prcm.o" $(MAKEFILE_DIR)../../../driverlib/prcm.c
		@ echo TIARMCLANG: Compile pwr_ctrl.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "pwr_ctrl.o" $(MAKEFILE_DIR)../../../driverlib/pwr_ctrl.c
		@ echo TIARMCLANG: Compile rom_crypto.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "rom_crypto.o" $(MAKEFILE_DIR)../../../driverlib/rom_crypto.c
		@ echo TIARMCLANG: Compile setup.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "setup.o" $(MAKEFILE_DIR)../../../driverlib/setup.c
		@ echo TIARMCLANG: Compile setup_rom.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "setup_rom.o" $(MAKEFILE_DIR)../../../driverlib/setup_rom.c
		@ echo TIARMCLANG: Compile sha2.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "sha2.o" $(MAKEFILE_DIR)../../../driverlib/sha2.c
		@ echo TIARMCLANG: Compile smph.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "smph.o" $(MAKEFILE_DIR)../../../driverlib/smph.c
		@ echo TIARMCLANG: Compile ssi.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "ssi.o" $(MAKEFILE_DIR)../../../driverlib/ssi.c
		@ echo TIARMCLANG: Compile sw_chacha.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "sw_chacha.o" $(MAKEFILE_DIR)../../../driverlib/sw_chacha.c
		@ echo TIARMCLANG: Compile sw_poly1305-donna.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "sw_poly1305-donna.o" $(MAKEFILE_DIR)../../../driverlib/sw_poly1305-donna.c
		@ echo TIARMCLANG: Compile systick.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "systick.o" $(MAKEFILE_DIR)../../../driverlib/systick.c
		@ echo TIARMCLANG: Compile sys_ctrl.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "sys_ctrl.o" $(MAKEFILE_DIR)../../../driverlib/sys_ctrl.c
		@ echo TIARMCLANG: Compile timer.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "timer.o" $(MAKEFILE_DIR)../../../driverlib/timer.c
		@ echo TIARMCLANG: Compile trng.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "trng.o" $(MAKEFILE_DIR)../../../driverlib/trng.c
		@ echo TIARMCLANG: Compile uart.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "uart.o" $(MAKEFILE_DIR)../../../driverlib/uart.c
		@ echo TIARMCLANG: Compile udma.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "udma.o" $(MAKEFILE_DIR)../../../driverlib/udma.c
		@ echo TIARMCLANG: Compile vims.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "vims.o" $(MAKEFILE_DIR)../../../driverlib/vims.c
		@ echo TIARMCLANG: Compile watchdog.c
		@ $(COMPILER_TOOL) -mthumb -march=armv7e-m -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Os -Wall -fno-strict-aliasing -gstrict-dwarf -pedantic -ffunction-sections -fdata-sections -std=c99 -c -g -o "watchdog.o" $(MAKEFILE_DIR)../../../driverlib/watchdog.c
		@ echo GCC: Archive driverlib.lib
		@ $(ARCHIVER_TOOL) rcs $(MAKEFILE_DIR)driverlib.lib $(MAKEFILE_DIR)adi.o $(MAKEFILE_DIR)aes.o $(MAKEFILE_DIR)aon_batmon.o $(MAKEFILE_DIR)aon_event.o $(MAKEFILE_DIR)aon_ioc.o $(MAKEFILE_DIR)aon_pmctl.o $(MAKEFILE_DIR)aon_rtc.o $(MAKEFILE_DIR)aux_adc.o $(MAKEFILE_DIR)aux_smph.o $(MAKEFILE_DIR)aux_sysif.o $(MAKEFILE_DIR)aux_tdc.o $(MAKEFILE_DIR)ccfgread.o $(MAKEFILE_DIR)chipinfo.o $(MAKEFILE_DIR)cpu.o $(MAKEFILE_DIR)crypto.o $(MAKEFILE_DIR)ddi.o $(MAKEFILE_DIR)debug.o $(MAKEFILE_DIR)driverlib_release.o $(MAKEFILE_DIR)event.o $(MAKEFILE_DIR)flash.o $(MAKEFILE_DIR)gpio.o $(MAKEFILE_DIR)i2c.o $(MAKEFILE_DIR)i2s.o $(MAKEFILE_DIR)interrupt.o $(MAKEFILE_DIR)ioc.o $(MAKEFILE_DIR)osc.o $(MAKEFILE_DIR)pka.o $(MAKEFILE_DIR)prcm.o $(MAKEFILE_DIR)pwr_ctrl.o $(MAKEFILE_DIR)rom_crypto.o $(MAKEFILE_DIR)setup.o $(MAKEFILE_DIR)setup_rom.o $(MAKEFILE_DIR)sha2.o $(MAKEFILE_DIR)smph.o $(MAKEFILE_DIR)ssi.o $(MAKEFILE_DIR)sw_chacha.o $(MAKEFILE_DIR)sw_poly1305-donna.o $(MAKEFILE_DIR)systick.o $(MAKEFILE_DIR)sys_ctrl.o $(MAKEFILE_DIR)timer.o $(MAKEFILE_DIR)trng.o $(MAKEFILE_DIR)uart.o $(MAKEFILE_DIR)udma.o $(MAKEFILE_DIR)vims.o $(MAKEFILE_DIR)watchdog.o
		@ rm -f $(MAKEFILE_DIR)*.o

# Deletes previous output and temporary files
clean :
		@ rm -fR $(MAKEFILE_DIR)*.o
		@ rm -fR $(MAKEFILE_DIR)*.lib
