/*
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 *  ======== target_handler.js ========
 *  Module to handle TargetInfo boards
 */

"use strict";

// Common utility functions
const Common = system.getScript("/ti/devices/radioconfig/radioconfig_common.js");

// Needed for updating Tx Power overrides
const DeviceInfo = Common.getScript("device_info.js");

// Target information
let TargetInfo = "";
let CurrentTarget = "";

// Needed for getting new PA settings when frequency changes
let PaSettings = null;
let PaSettingsHi = null;
let PaSettingsProp24 = null;

let TargetSetting = null;
let TargetSettingHi = null;
let TargetSettingProp24 = null;

// Target configuration (index of all targets)
let TargetConfig = null;
let VirtualTarget = null;

// Avoid multiple loading av same file
const TgtFileCache = {};

// Path to target information (targets.json)
let TgtPath = null;

// Path to PA settings (pasettings.json)
let PaPath = null;

// Currently selected PA setting
let HighPA = false;

// Exported functions
exports = {
    init: init,
    getTargetList: getTargetList,
    getCurrentTarget: function() {
        return {
            board: CurrentTarget,
            virtual: TargetInfo.Name
        };
    },
    getTargetInfo: function() {
        return TargetInfo;
    },
    getRfDesign: function() {
        return TargetInfo.RfDesign;
    },
    getDevicePackage: function() {
        return TargetInfo.DevicePackage;
    },
    getIoPins: function() {
        const io = [];
        _.each(TargetInfo.IoSettings.IoPin, (pin) => {
            io.push(pin._name);
        });
        return io;
    },
    isHighPA: function() {
        return HighPA;
    },
    getTxPowerValuePA: getTxPowerValuePA,
    selectTargetPA: selectTargetPA,
    getTxPowerValueList: getTxPowerValueList,
    getPaSettingsByFreq: getPaSettingsByFreq,
    getFrequencyRanges: getFrequencyRanges,
    getPaTableSize: getPaTableSize,
    generateTxPowerHeader: generateTxPowerHeader,
    generateTxPowerCode: generateTxPowerCode
};

/* Target file formats:
*
*  1) single target file: CC2642R, CC1312R, CC2652RB
*  2) single virtual target: CC1352R
*  3) multiple virtual targets: CC1352P
*  4) list of target files: CC2652R
*/

/*!
 *  ======== init ========
 *
 *  Load target information data
 *
 *  @phy - phy group
 */
function init(phy) {
    // List of targets (converted from SmartRF Studio)
    const tgtIndexFile = DeviceInfo.getTargetIndex(phy);
    TargetConfig = system.getScript(tgtIndexFile);

    // Load current target file (converted from SmartRF Studio)
    TgtPath = DeviceInfo.getTargetPath(phy);
    const tgtFile = TargetConfig.targets.Default;

    // Check target file format
    if ("VirtualTarget" in TargetConfig.targets) {
        // Extract target name (format "default_target:target_name")
        const tmp = tgtFile.split(":");
        CurrentTarget = tmp[1];

        // Extract virtual target info
        const vt = TargetConfig.targets.VirtualTarget;
        if ("_name" in vt) {
            // Single virtual targets (CC1352R)
            VirtualTarget = vt;
        }
        else {
            // Assume multiple virtual targets (CC1352P)
            VirtualTarget = vt[0]; // LAUNCHXL-CC1352P1
        }
    }

    // Load PA settings (converted from SmartRF Studio)
    PaPath = DeviceInfo.getPaSettingsPath();
    loadTargetInfo();
    TargetInfo = TargetSetting.target;

    if (VirtualTarget === null) {
        // Simple format (no virtual targets): CC1312, CC2642, CC2652RB
        CurrentTarget = TargetInfo.Name;
    }
}

/*!
 *  ======== selectTargetPA ========
 *  Select a target board and High PA setting. This function only applies to CC1352P.
 *
 *  @param target - target name
 *  @phy - phy group
 *  @highPA - whether to select High Power output
 *  @prop24 - proprietary 2.4 GHz
 */
function selectTargetPA(target, phy, highPA, prop24) {
    CurrentTarget = target;
    let idx = highPA ? 1 : 0;

    if (prop24 && DeviceInfo.getDeviceName().includes("CC1352p")) {
        idx = 2;
    }

    // List of targets (converted from SmartRF Studio)
    const tgtIndexFile = DeviceInfo.getTargetIndex(phy);
    TargetConfig = system.getScript(tgtIndexFile);

    // Load current target file (converted from SmartRF Studio)
    let tgtFile = "";

    // Look for target in target index (targets.json)
    const tgt = _.find(TargetConfig.targets.VirtualTarget, ["_name", target]);

    tgtFile = tgt.Target[idx];
    VirtualTarget = tgt;

    _.each(TargetConfig.targets.VirtualTarget, (targt) => {
        if (targt._name === target) {
            tgtFile = targt.Target[idx];
            VirtualTarget = targt;
            return false;
        }
        return true;
    });

    // Apply if target found
    if (!(_.isNil(tgtFile))) {
        loadTargetInfo();

        HighPA = highPA;
        if (prop24) {
            TargetInfo = TargetSettingProp24.target;
        }
        else if (highPA) {
            TargetInfo = TargetSettingHi.target;
        }
        else {
            TargetInfo = TargetSetting.target;
        }
    }
    else {
        throw new Error("Target not found [" + TargetInfo.Name + ")");
    }
}

/*!
 *  ======== getTargetList ========
 *  Return a list of available targets for the current device
 *
 */
function getTargetList() {
    // Virtual targets: CC1352P(3), CC1352R(1)
    if (TargetConfig.targets.VirtualTarget) {
        const tgtList = Common.forceArray(TargetConfig.targets.VirtualTarget);
        return _.map(tgtList, tgt => tgt._name);
    }
    // List of targets: CC2652R(2)
    if (TargetConfig.targets.Target) {
        const tgtList = [];
        _.each(TargetConfig.targets.Target, (tgtFile) => {
            const tgt = system.getScript(TgtPath + tgtFile);
            tgtList.push(tgt.target.Name);
        });
        return tgtList;
    }
    // Single target: CC1312, CC2642
    return [CurrentTarget];
}


/*!
 *  ======== getPaTableSize ========
 *  Return the size of TX Power table (PA table)
 *
 *  @param freq - selected frequency (kHz)
 *  @paExport - PA table export setting (none, active, dual, combined)
 */
function getPaTableSize(freq, paExport, prop24) {
    let ret = 0;

    if (PaSettings != null && !paExport.includes("none")) {
        // List of PA settings
        const paList = getPaSettingsByFreq(freq, HighPA, prop24);

        // Table size including termination
        ret = paList.length + 1;
    }

    return ret;
}

/*!
 *  ======== generateTxPowerHeader ========
 *  Generate TX Power table header (PA table)
 *
 *  @param freq - selected frequency (kHz)
 *  @symNames - code export settings
 *  @param prop24 - True if proprietary 2.4 GHz
 */
function generateTxPowerHeader(freq, symNames, prop24) {
    const paExport = symNames.paExport;

    if (PaSettings != null && !paExport.includes("none")) {
        // Size definition
        let codeSz = "// TX Power table size definition\n";

        // struct declaration
        const comment = "// TX Power Table Object\n";
        const typeName = "RF_TxPowerTable_Entry ";
        let code = comment + "extern " + typeName;

        if (paExport.includes("active")) {
            // Active PA table
            const paList = getPaSettingsByFreq(freq, HighPA, prop24);
            codeSz += "#define " + symNames.txPowerSize + " " + (paList.length + 1);

            code += symNames.txPower + "[];\n";
        }
        else {
            const paListStd = getPaSettingsByFreq(freq, false, prop24);
            const paListHi = getPaSettingsByFreq(freq, true, prop24);

            if (paExport.includes("dual")) {
                // Standard PA table
                const lenStd = paListStd.length;
                const lenHi = paListHi.length;
                let txpName = symNames.txPower + "_TxStd";
                let txSizeName = symNames.txPowerSize + "_TXSTD";
                codeSz += "#define " + txSizeName + " " + (lenStd + 1) + "\n";
                code += txpName + "[];\n";

                // High PA table
                txpName = symNames.txPower + "_Tx20";
                txSizeName = symNames.txPowerSize + "_TX20";
                codeSz += "#define " + txSizeName + " " + (lenHi + 1);
                code += "extern " + typeName + txpName + "[];\n";
            }
            else {
                // Combined PA table
                const paListComb = combinePaTable(paListStd, paListHi);
                codeSz += "#define " + symNames.txPowerSize + " " + (paListComb.length + 1);
                code += symNames.txPower + "[];\n";
            }
        }
        codeSz += "\n\n";

        return codeSz + code;
    }
    return null;
}

/*!
 *  ======== generateTxPowerCode ========
 *  Generate TX Power table (PA table)
 *
 *  @param freq - selected frequency (kHz)
 *  @symNames - code export settings
 *  @param prop24 - True if proprietary 2.4 GHz
 */
function generateTxPowerCode(freq, symNames, prop24) {
    const paExport = symNames.paExport;

    if (PaSettings != null && !paExport.includes("none")) {
        const comment = "// TX Power table\n"
            + "// The RF_TxPowerTable_DEFAULT_PA_ENTRY and RF_TxPowerTable_HIGH_PA_ENTRY macros are defined in RF.h.\n"
            + "// The following arguments are required:\n"
            + "// RF_TxPowerTable_DEFAULT_PA_ENTRY(bias, gain, boost coefficient)\n"
            + "// RF_TxPowerTable_HIGH_PA_ENTRY(bias, ibboost, boost, coefficient, ldoTrim)\n"
            + "// See the Technical Reference Manual for further details about the \"txPower\" Command field.\n"
            + "// The PA settings require the CCFG_FORCE_VDDR_HH = 0 unless stated otherwise.\n";
        const typeName = "RF_TxPowerTable_Entry ";
        let code = typeName;

        if (paExport.includes("active")) {
            // Active PA table
            const paList = getPaSettingsByFreq(freq, HighPA, prop24);

            code += symNames.txPower + "[" + symNames.txPowerSize + "] =\n{\n";
            code += generatePaTableCode(paList, false);
        }
        else {
            const paListStd = getPaSettingsByFreq(freq, false, prop24);
            const paListHi = getPaSettingsByFreq(freq, true, prop24);

            if (paExport.includes("dual")) {
                // Standard PA table
                const codeStd = generatePaTableCode(paListStd, false);
                const codeHi = generatePaTableCode(paListHi, false);
                let txpName = symNames.txPower + "_TxStd";
                let txSizeName = symNames.txPowerSize + "_TXSTD";
                code += txpName + "[" + txSizeName + "] =\n{\n";
                code += codeStd;
                code += "    RF_TxPowerTable_TERMINATION_ENTRY\n};\n\n";

                // High PA table
                txpName = symNames.txPower + "_Tx20";
                txSizeName = symNames.txPowerSize + "_TX20";
                code += typeName + txpName + "[" + txSizeName + "] =\n{\n";
                code += codeHi;
            }
            else {
                // Combined PA table
                const paListComb = combinePaTable(paListStd, paListHi);
                const codeComb = generatePaTableCode(paListComb, true);

                code += symNames.txPower + "[" + symNames.txPowerSize + "] =\n{\n";
                code += codeComb;
            }
        }
        code += "    RF_TxPowerTable_TERMINATION_ENTRY\n};\n";

        return comment + code;
    }
    return null;
}

/*!
 *  ======== getTxPowerValueList ========
 *  Get list of available Tx power values for a given frequency.
 *
 *  @param freq - selected frequency (kHz)
 *  @param highPA - set if using high PA table
 *  @param prop24 - True if proprietary 2.4 GHz
 */
function getTxPowerValueList(freq, highPA, prop24) {
    const ret = [];
    const paList = getPaSettingsByFreq(freq, highPA, prop24);

    _.each(paList, (pv) => {
        const item = {};
        item.name = pv._text;
        item.key = pv.Value;
        ret.push(item);
    });

    return ret;
}

/*!
 *  ======== getTxPowerValuePA ========
 *  Get raw TX power value for PA devices
 *
 *  @param freqStr - selected frequency (kHz), represented as string
 *  @param reqHighPa - use high PA settings
 *  @param value - value in dBm and raw
 */
function getTxPowerValuePA(freqStr, reqHighPa, value) {
    const freq = parseFloat(freqStr);
    const data = {raw: "0", dbm: "0"};
    let paSetting = null;
    let paSettings;
    let targetInfo;

    // Pick settings according to PA
    if (reqHighPa) {
        paSettings = PaSettingsHi;
        targetInfo = TargetSettingHi.target;
    }
    else {
        paSettings = PaSettings;
        targetInfo = TargetSetting.target;
    }

    // Search for setting with the required frequency range
    const rfDesigns = paSettings.patables.RfDesign;
    _.each(rfDesigns, (item) => {
        const ranges = Common.forceArray(item.FrequencyRange);
        _.each(ranges, (fr) => {
            if (freq >= fr.Min && freq <= fr.Max && targetInfo.RfDesign === item._name) {
                paSetting = fr.PaSettingTable.PaSetting;
                return false;
            }
            return true;
        });
        if (paSetting !== null) {
            return false;
        }
        return true;
    });

    // If value not in list or default, use the first item
    if (paSetting !== null) {
        let pa = paSetting[0];
        _.each(paSetting, (item) => {
            if (item._text === value) {
                pa = item;
                return false;
            }
            return true;
        });

        if (reqHighPa) {
            data.raw = pa.TxHighPa;
        }
        else {
            data.raw = pa.Value;
        }
        data.dbm = pa._text;
    }
    else {
        // CC1352P/CC252P
        paSetting = paSettings.patables.DefaultPaTable.PaSetting;
        data.dbm = paSetting._text;
        data.raw = paSetting.Value;
    }

    return data;
}

/*
 * Private functions
 */

/*!
 *  ======== loadTargetInfo ========
 *  Load target information
 */
function loadTargetInfo() {
    if (VirtualTarget !== null) {
        // Default virtual target
        TargetSetting = loadTargetSetting(0);
        if (PaSettings === null) {
            PaSettings = loadPaSettings(TargetSetting);
        }

        // High PA virtual target
        if (DeviceInfo.hasHighPaSupport()) {
            TargetSettingHi = loadTargetSetting(1);
            if (PaSettingsHi === null) {
                PaSettingsHi = loadPaSettings(TargetSettingHi);
            }
        }
        // Proprietary 2.4 GHz virtual target CC1352P
        if (VirtualTarget.Target.length === 3) {
            TargetSettingProp24 = loadTargetSetting(2);
            if (PaSettingsProp24 === null) {
                PaSettingsProp24 = loadPaSettings(TargetSettingProp24);
            }
        }
        else {
            // Proprietary 2.4 GHz virtual target CC2652P
            TargetSettingProp24 = TargetSetting;
            PaSettingsProp24 = PaSettings;
        }
    }
    else {
        // Simple target file format
        const tgtFile = TargetConfig.targets.Default;

        if (tgtFile in TgtFileCache) {
            TargetSetting = TgtFileCache[tgtFile];
        }
        else {
            TargetSetting = system.getScript(TgtPath + tgtFile);
            TgtFileCache[tgtFile] = TargetSetting;
        }
        if (PaSettings === null) {
            PaSettings = loadPaSettings(TargetSetting);
        }
    }
}

/*!
 *  ======== generatePaTableCode ========
 *  Generate PA-table code
 *
 *  @param paList - list of PA settings
 *  @param combined - true if default and high output PA settings are combined
 */
function generatePaTableCode(paList, combined) {
    let code = "";
    let val = -100;

    // Generate code
    _.eachRight(paList, (pv) => {
        const paEntry = generatePaEntryString(pv);
        if ("Option" in pv && !combined) {
            code += "    // This setting requires CCFG_FORCE_VDDR_HH = 1.\n";
        }

        const dbm = parseFloat(pv._text);
        if (!Number.isInteger(dbm)) {
            code += "    // The original PA value (" + pv._text + " dBm) has been rounded to an integer value.\n";
        }
        let iDbm = combined ? Math.floor(dbm) : Math.round(dbm);
        if (iDbm === val) {
            iDbm += 1;
        }

        const str = "    {" + iDbm + ", " + paEntry + " },\n";
        code += str;
        val = iDbm;
    });
    return code;
}

/*!
 *  ======== combinePaTable ========
 *  Merge PA tables for default and HIGH PA
 *
 *  @param paListStd - settings for default TX power
 *  @param paListHi - settings for high TX power
 */
function combinePaTable(paListStd, paListHi) {
    const paListComb = _.cloneDeep(paListHi.concat(paListStd));
    const ret = [];
    let high = -100;

    _.eachRight(paListComb, (item) => {
        const val = parseFloat(item._text);
        // Throw away items that break the ascending order
        if (val > high) {
            ret.unshift(item);
            high = val;
            item._text = val;
        }
    });
    return ret;
}

/*!
 *  ======== loadPaSettings ========
 *  Load the PA settings for a specific target
 *
 *  @param tgtSetting - target setting object
 */
function loadPaSettings(tgtSetting) {
    const paFile = PaPath + tgtSetting.target.PaSettings;
    const paSettings = system.getScript(paFile);

    return paSettings;
}

/*!
 *  ======== loadTargetSetting ========
 *  Load target setting object by index in target list
 *
 *  @param index - position in list of targets
 */
function loadTargetSetting(index) {
    const vt = Common.forceArray(VirtualTarget.Target);
    const tgtFile = vt[index];

    let tgtSetting;
    if (tgtFile in TgtFileCache) {
        tgtSetting = TgtFileCache[tgtFile];
    }
    else {
        tgtSetting = system.getScript(TgtPath + tgtFile);
        TgtFileCache[tgtFile] = tgtSetting;
    }
    return tgtSetting;
}

/*!
 *  ======== getPaSettingsByFreq ========
 *  Get PA settings for a given frequency
 *
 *  @param freqStr - string representation of the frequency
 *  @param highPA - true if PA settings for high output are required
 *  @param prop24 - true if using proprietary 2.4 GHz settings
 */
function getPaSettingsByFreq(freqStr, highPA, prop24) {
    let setting = null;
    let paSettings = null;
    const freq = parseFloat(freqStr);

    if ("FrequencyRange" in PaSettings.patables.RfDesign) {
        const freqRanges = PaSettings.patables.RfDesign.FrequencyRange;
        if (freqRanges.constructor === Array) {
            // Single RF design, multiple frequency ranges (CC1352R, CC1312R)
            _.each(freqRanges, (fr) => {
                if (freq >= fr.Min && freq <= fr.Max) {
                    setting = fr.PaSettingTable.PaSetting;
                    return false;
                }
                // Continue looping
                return true;
            });
        }
        else if (freq >= freqRanges.Min && freq <= freqRanges.Max) {
            // Single RF design, single frequency range (CC2652R)
            setting = freqRanges.PaSettingTable.PaSetting;
        }
        paSettings = PaSettings;
    }
    else {
        // Multiple RF designs, one frequency range per target (CC1352P)
        const board = getBoardSettings(highPA, prop24);

        // Iterate RF designs (may have single or multiple ranges)
        const rfDesigns = board.paSettings.patables.RfDesign;
        _.each(rfDesigns, (item) => {
            let ranges = [];

            if ("Min" in item.FrequencyRange) {
                ranges.push(item.FrequencyRange);
            }
            else {
                ranges = item.FrequencyRange;
            }

            _.each(ranges, (fr) => {
                if (freq >= fr.Min && freq <= fr.Max && board.targetInfo.RfDesign === item._name) {
                    setting = fr.PaSettingTable.PaSetting;
                    return false;
                }
                return true;
            });
            if (setting != null) {
                return false;
            }
            paSettings = board.paSettings;
            return true;
        });
    }

    if (setting === null) {
        // CC1352P
        setting = paSettings.patables.DefaultPaTable;
    }
    return setting;
}

/*!
 *  ======== getFrequencyRanges ========
 *  Get the frequency ranges for the current RF device/target.
 *
 *  @param highPA - true if frequency ranges for high output are required
 *  @param prop24 - true if using proprietary 2.4 GHz settings
 */
function getFrequencyRanges(highPA, prop24) {
    let ranges = [];

    if ("FrequencyRange" in PaSettings.patables.RfDesign) {
        const freqRanges = PaSettings.patables.RfDesign.FrequencyRange;
        if (freqRanges.constructor === Array) {
            // Single RF design, multiple frequency ranges (CC1352R, CC1312R)
            _.each(freqRanges, (item) => {
                ranges.push(item);
            });
        }
        else {
            // Single RF design, single frequency range (CC2652R, CC2642R)
            ranges.push(freqRanges);
        }
    }
    else {
        // Multiple RF designs, one frequency range per target (CC1352P)

        // Get board settings
        const board = getBoardSettings(highPA, prop24);

        const rfDesigns = board.paSettings.patables.RfDesign;
        _.each(rfDesigns, (item) => {
            if (board.targetInfo.RfDesign === item._name) {
                if ("Min" in item.FrequencyRange) {
                    ranges.push(item.FrequencyRange);
                }
                else {
                    ranges = item.FrequencyRange;
                }
            }
        });
    }
    return ranges;
}

/*!
 *  ======== generatePaEntryString ========
 *  Generate the PA entry code string
 *
 *  @param pv - PA table entry
 */
/* eslint-disable no-bitwise */
function generatePaEntryString(pv) {
    const value = parseInt(pv.Value, 16);
    const highPA = value === 0xFFFF;
    const val = highPA ? pv.TxHighPa : value;
    const bias = val & 0x3f; /* bit 0..5 */
    const gain = (val >> 6) & 0x03; /* bit 6..7 */
    const boost = (val >> 8) & 0x01; /* bit 8 */
    const coefficient = (val >> 9) & 0x7f; /* bit 9..15 */
    let paEntry;

    if (highPA) {
        const ldoTrim = (val >> 16) & 0x3f; /* bit 16..21 */
        paEntry = "RF_TxPowerTable_HIGH_PA_ENTRY(" + bias + ", " + gain + ", "
      + boost + ", " + coefficient + ", " + ldoTrim + ")";
    }
    else {
        paEntry = "RF_TxPowerTable_DEFAULT_PA_ENTRY(" + bias + ", " + gain + ", "
      + boost + ", " + coefficient + ")";
    }
    return paEntry;
}
/* eslint-enable no-bitwise */


/*!
 *  ======== getBoardSettings ========
 *  Get board related information
 *
 *  @param highPA - true if high PA
 *  @param prop24 - true if 2.4 GHz proprietary
 */
function getBoardSettings(highPA, prop24) {
    const ret = {};
    // Pick settings according to PA
    if (prop24) {
        ret.paSettings = PaSettingsProp24;
        ret.targetInfo = TargetSettingProp24.target;
    }
    else if (highPA) {
        ret.paSettings = PaSettingsHi;
        ret.targetInfo = TargetSettingHi.target;
    }
    else {
        ret.paSettings = PaSettings;
        ret.targetInfo = TargetSetting.target;
    }
    return ret;
}
