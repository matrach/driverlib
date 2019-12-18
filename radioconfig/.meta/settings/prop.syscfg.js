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
 *  ======== prop.syscfg.js ========
 *  Radio configuration support for proprietary settings.
 */

"use strict";

/* Common utility functions */
const Common = system.getScript("/ti/devices/radioconfig/radioconfig_common.js");

/* Other dependencies */
const RFBase = Common.getScript("radioconfig");
const DevInfo = Common.getScript("device_info.js");
const CmdHandler = Common.getScript("cmd_handler.js");
const TargetHandler = Common.getScript("target_handler.js");
const ParameterHandler = Common.getScript("parameter_handler.js");

/* Documentation */
const PropDocs = Common.getScript("settings/prop_docs.js");
const SharedDocs = Common.getScript("settings/shared_docs.js");

/* PHY group */
const PHY_GROUP = Common.PHY_PROP;
DevInfo.addPhyGroup(PHY_GROUP);

const HAS_SUB1G = Common.IS_SUB1GHZ_DEVICE();
const HAS_24G = Common.HAS_2_4G_PROP;

/* Target config */
const highPaSupport = DevInfo.hasHighPaSupport();

let TargetConfig = null;
if (highPaSupport) {
    TargetConfig = Common.getScript("target_config");
    TargetConfig.init(PHY_GROUP);
}

/* Short-hand for error reporting */
const logError = Common.logError;
const logWarning = Common.logWarning;

/* Setting specific configurable */
const tmp = system.getScript(DevInfo.getSyscfgParams(PHY_GROUP));
const config = _.cloneDeep(tmp);

const settingSpecific = {
    displayName: "RF Settings Proprietary",
    description: "RF Settings Proprietary",
    longDescription: "RF Settings module for proprietary Sub-1 GHz protocols",
    phyGroup: PHY_GROUP,
    validate: validate,
    config: config
};

let freqBandOptions = [];
let phyOptions = {};

// All CC13x2 devices support proprietary sub-1GHz PHYs */
if (HAS_SUB1G) {
    freqBandOptions = [
        {
            name: "868",
            displayName: "779 - 930 MHz"
        },
        {
            name: "433",
            displayName: "431 - 527 MHz"
        }
    ];

    /* eslint-disable quote-props */
    phyOptions = {
        "868": getPhyOptions("868"),
        "433": getPhyOptions("433")
    };
    /* eslint-enable quote-props */

    /* Default frequency band, hidden */
    addPhyConfigurable("868", false);
    addPhyConfigurable("433", true);
}

if (HAS_24G) {
    // CC2652R1/P, and CC1353R/P support 2.4 GHz proprietary PHYs
    freqBandOptions.push(
        {
            name: "2400",
            displayName: "2400 - 2480 MHz"
        }
    );

    /* eslint-disable quote-props */
    phyOptions["2400"] = getPhyOptions("2400");
    /* eslint-enable quote-props */

    /* Default frequency band, hidden */
    addPhyConfigurable("2400", HAS_SUB1G);
}

/* Add frequency band configurable */
config.unshift({
    name: "freqBand",
    displayName: "Frequency Band",
    description: "Select the frequency band",
    options: freqBandOptions,
    default: Common.getDefaultFreqBand(),
    onChange: (inst, ui) => {
        const prop24 = inst.freqBand === "2400";

        if (HAS_SUB1G) {
            const c868hidden = inst.freqBand !== "868";
            ui.phyType868.hidden = c868hidden;
            ui.txPower.hidden = c868hidden;

            const c433Hidden = inst.freqBand !== "433";
            ui.phyType433.hidden = c433Hidden;
            ui.txPower433.hidden = c433Hidden;
        }

        if (HAS_24G) {
            ui.phyType2400.hidden = !prop24;
            ui.txPower2400.hidden = !prop24;
        }

        if (highPaSupport) {
            ui.highPA.hidden = prop24;
        }

        const phyType = phyOptions[inst.freqBand][0].name;
        if (inst.freqBand === "868") {
            inst.phyType868 = phyType;
        }
        else if (inst.freqBand === "433") {
            inst.phyType433 = phyType;
        }
        else {
            inst.phyType2400 = phyType;
        }

        /* Hides configurables not relevant to the selected PHY */
        hideIrrelevantConfigurables(inst, ui);

        /* Refresh the view */
        RFBase.updateConfigurables(inst, ui, phyType, PHY_GROUP);
    }
});

/* Add Target configurables to the top of the list */
if (highPaSupport) {
    const tgtName = TargetConfig.getTargetName();
    const optHiPa = TargetConfig.getOptimalHiPa(tgtName, "868");
    RFBase.addTxPowerConfigHigh(config, optHiPa);
}

/*
 *  ======== getPhyOptions ========
 *  Create PHY options list depending on frequency band
 *
 *  @param freqBand  - frequency band (868 or 433)
 *  @returns - list of PHY options for the frequency dependent configurable
 */
function getPhyOptions(freqBand) {
    const opts = [];
    const settingMap = DevInfo.getSettingMap(PHY_GROUP);
    _.each(settingMap, (s) => {
        const phyType = s.name;
        const cmdHandler = CmdHandler.get(PHY_GROUP, phyType);
        const freq = cmdHandler.getFrequencyBand();
        /* eslint-disable-next-line */
        if (freqBand == freq) {
            opts.push({
                name: phyType,
                displayName: s.description
            });
        }
    });
    return opts;
}

/*
 *  ======== addPhyConfigurable ========
 *  Add a PHY Type configurable
 *
 *  @param freqBand  - frequency band (868 or 433)
 *  @param hide - whether or not the configurable is initially hidden
 */
function addPhyConfigurable(freqBand, hide) {
    const phyOpt = phyOptions[freqBand];

    if (phyOpt.length > 0) {
        config.unshift({
            name: "phyType" + freqBand,
            displayName: "PHY Type",
            description: "Selects the PHY/setting",
            hidden: hide,
            options: phyOpt,
            default: phyOpt[0].name,
            onChange: function(inst, ui) {
                let phyType = Common.getPhyType(inst);

                if (phyType === "custom") {
                    const phyOption = phyOptions[inst.freqBand];
                    phyType = phyOption[0].name;
                }

                /* Hides configurables not relevant to the selected PHY */
                hideIrrelevantConfigurables(inst, ui);

                /* Refresh the view */
                RFBase.updateConfigurables(inst, ui, phyType, PHY_GROUP);
            }
        });
    }
}


/*!
 *  ======== initConfigurables ========
 *  Connect onChange callbacks for certain configurables
 */
function initConfigurables(configurable) {
    const dev = DevInfo.getDeviceName();
    const device24Only = dev === "cc2652r" || dev === "cc2652p";

    function processConfigurable(item) {
        switch (item.name) {
        case "permission":
            item.onChange = onPermissionChange;
            break;
        case "addressMode":
            item.onChange = function(inst, ui) {
                const Hidden = inst.addressMode === "No address check";
                ui.address0.hidden = Hidden;
                ui.address1.hidden = Hidden;
            };
            break;
        case "packetLengthConfig":
            item.onChange = function(inst, ui) {
                const Hidden = inst.packetLengthConfig === "Variable";
                ui.fixedPacketLength.hidden = Hidden;
            };
            break;
        case "txPower":
        case "txPower433":
            if (device24Only) {
                item.hidden = true;
            }
            break;
        case "highPA":
            if (device24Only) {
                item.hidden = true;
                item.default = false;
            }
            break;
        case "txPower2400":
            item.hidden = !device24Only;
            break;
        default:
            break;
        }
    }
    _.each(configurable, (item) => {
        if (_.has(item, "config")) {
            _.each(item.config, (subItem) => {
                processConfigurable(subItem);
            });
        }
        else {
            processConfigurable(item);
        }
    });
}

/*!
 *  ======== onPermissionChange ========
 *  1. Change permission according to permission configurable.
 *  2. Change visibility of address filter according to parent
 */
function onPermissionChange(inst, ui) {
    // Set access to selected RF parameters
    const readOnly = inst.permission === "ReadOnly";
    const configs = [
        "address0", "address1", "deviation", "symbolRate",
        "preambleCount", "preambleMode", "syncWordLength", "syncWord",
        "packetLengthConfig", "fixedPacketLength", "packetLengthRx",
        "addressMode"];

    _.each(configs, (item) => {
        ui[item].readOnly = readOnly;
    });

    // RX address filter hidden if parent is a stack
    if (Common.usedByStack(inst, "Stack")) {
        ui.address0.hidden = true;
        ui.address1.hidden = true;
        ui.addressMode.hidden = true;
    }

    // Frequency band
    // - Custom stack: ReadOnly
    // - Standard stack: controlled by the 'permission' configurable
    const freqReadOnly = readOnly || Common.usedByStack(inst, "Custom");
    ui.freqBand.readOnly = freqReadOnly;

    // PHY type
    // - Custom stack, static PHY: ReadOnly
    // - Custom stack, custom PHY: ReadWrite
    // - Standard stack: controlled by the 'permission' configurable
    let phyTypeReadOnly = false;
    if (Common.usedByStack(inst, "Custom")) {
        const phyType = Common.getPhyType(inst);
        phyTypeReadOnly = !phyType.includes("custom");
    }
    else {
        phyTypeReadOnly = readOnly;
    }

    if (HAS_SUB1G) {
        ui.phyType868.readOnly = phyTypeReadOnly;
        ui.phyType433.readOnly = phyTypeReadOnly;
    }

    if (HAS_24G) {
        ui.phyType2400.readOnly = phyTypeReadOnly;
    }
}

/*!
 *  ======== hideIrrelevantConfigurables ========
 *  Hides configurables that is not relevant for the chosen phyType
 *
 * @param inst - RF Settings instance
 * @param ui - RF Setting UI instance
 */
function hideIrrelevantConfigurables(inst, ui) {
    const phyType = Common.getPhyType(inst);
    const isIeee154 = _.includes(phyType, "154g");

    // Read Only if IEEE 802.15.4
    ui.syncWord.readOnly = isIeee154;
    ui.syncWordLength.readOnly = isIeee154;
    ui.preambleMode.readOnly = isIeee154;

    // Make sure the packetLengthConfig is correct for IEEE 802.15.4
    if (isIeee154) {
        inst.packetLengthConfig = "Variable";
    }
    ui.packetLengthConfig.readOnly = isIeee154;

    // Hide if IEEE 802.15.4
    ui.packetLengthRx.hidden = isIeee154;
    ui.fixedPacketLength.hidden = isIeee154;
}

/*!
 *  ======== validate ========
 *  Validate this module's configuration
 *
 *  @param inst       - RF Settings instance to be validated
 *  @param validation - Issue reporting object
 */
function validate(inst, validation) {
    const MIN_FREQ = 0;
    const MAX_FREQ = 3000;
    const BAND_24G = inst.freqBand === "2400";
    const SYM_RATE_MAX = BAND_24G ? 2200 : 200;

    // Validation common to all PHY groups
    Common.validateBasic(inst, validation);

    // Validate frequency ranges
    const freq = inst.carrierFrequency;
    const loFreq = freq < Common.LowFreqLimit;

    // Sanity check
    if (freq < MIN_FREQ || freq > MAX_FREQ) {
        logError(validation, inst, "carrierFrequency",
            "Valid range: " + MIN_FREQ + " to " + MAX_FREQ + " MHz");
        return;
    }

    // Check for correct frequency band
    const loFreqBand = inst.freqBand === "433";
    if (BAND_24G) {
        if (freq < 2400) {
            logError(validation, inst, "carrierFrequency",
                "Carrier Frequency does not match the selected Frequency Band");
            return;
        }
    }
    else if (loFreqBand !== loFreq) {
        logError(validation, inst, "carrierFrequency",
            "Carrier Frequency does not match the selected Frequency Band");
        return;
    }

    // Update RF commands with data from current instance
    const cmdHandler = CmdHandler.get(PHY_GROUP, Common.getPhyType(inst));
    cmdHandler.updateRfCommands(inst);

    const prop24 = inst.freqBand === "2400";
    const highPA = DevInfo.hasHighPaSupport() && !prop24 ? inst.highPA : false;
    const paSetting = TargetHandler.getPaSettingsByFreq(freq, highPA, prop24);

    if (paSetting.length > 1) {
        // Valid range, check if characterized
        let isOutsideofRange = true;
        let cRanges;

        if (loFreqBand) {
            cRanges = [
                {
                    Min: 431,
                    Max: 527
                }
            ];
        }
        else if (inst.freqBand === "868") {
            cRanges = [
                {
                    Min: 863,
                    Max: 876
                },
                {
                    Min: 902,
                    Max: 930
                }
            ];
        }
        else {
            cRanges = [
                {
                    Min: 2402,
                    Max: 2480
                }
            ];
        }

        let rangeMsg = "";
        _.each(cRanges, (range) => {
            rangeMsg += " [" + range.Min + ".." + range.Max + "]";
            const tempResult = (freq < range.Min || freq > range.Max);
            isOutsideofRange = isOutsideofRange && tempResult;
        });

        if (isOutsideofRange) {
            let msg = "The selected frequency belongs to a range that has not been characterized"
            + ", settings can give non-optimal performance";
            msg += " Characterized ranges:" + rangeMsg;
            logWarning(validation, inst, "carrierFrequency", msg);
        }
    }
    else {
        // No PA-table, not a valid range
        const freqRanges = TargetHandler.getFrequencyRanges(highPA);
        let midFreq = parseInt(inst.freqBand);
        if (loFreqBand) {
            midFreq = 490;
        }

        let msg = "Frequency out of range. Valid range:";
        _.each(freqRanges, (range) => {
            if (midFreq >= range.Min && midFreq <= range.Max) {
                msg += " [" + range.Min + ".." + range.Max + "]";
            }
        });
        logError(validation, inst, "carrierFrequency", msg);
        return;
    }

    // Validate symbol rate
    if (inst.symbolRate < 9.6 || inst.symbolRate > SYM_RATE_MAX) {
        logError(validation, inst, "symbolRate", "Valid range: 9.6 to " + SYM_RATE_MAX + " kBaud");
        return;
    }

    // Validate deviation
    if (inst.deviation < 0 || inst.deviation > 1000) {
        logError(validation, inst, "deviation", "Valid range: 0 to 1000 kHz");
        return;
    }

    // Validate Address0
    if (inst.address0 > 0xFF || inst.address0 < 0) {
        logError(validation, inst, "address0", "RX Address0 must be a number between 0x00 and 0xFF");
        return;
    }

    // Validate Address1
    if (inst.address1 > 0xFF || inst.address1 < 0) {
        logError(validation, inst, "address1", "RX Address1 must be a number between 0x00 and 0xFF");
        return;
    }

    // Validate SyncWord
    if (inst.syncWord > 0xFFFFFFFF || inst.syncWord < 0) {
        logError(validation, inst, "syncWord", "Sync Word must be a number between 0x0 and 0xFFFFFFFF");
        return;
    }

    const syncWordBits = _.toInteger(inst.syncWordLength.replace(" Bits", ""));
    const maxLength = (2 ** syncWordBits) - 1;
    let maxLengthHex = _.toUpper(maxLength.toString(16));
    if (maxLengthHex.length !== 8) {
        maxLengthHex = "0".repeat(8 - maxLengthHex.length) + maxLengthHex;
    }
    if (inst.syncWord > maxLength || inst.syncWord < 0) {
        logWarning(validation, inst, "syncWord", "Sync Word will ignore bits above "
            + inst.syncWordLength + ", Max 0x" + maxLengthHex);
    }

    // Validate packetLengthRx
    if (_.includes(Common.getPhyType(inst), "154g")) {
        if (inst.packetLengthRx > 2047 || inst.packetLengthRx < 0) {
            logError(validation, inst, "packetLengthRx", "Max Packet Length must be between 0 and 2047");
            return;
        }
    }
    else if (inst.packetLengthRx > 255 || inst.packetLengthRx < 0) {
        logError(validation, inst, "packetLengthRx", "Max Packet Length must be between 0 and 255");
        return;
    }

    // Validate fixedPacketLength
    if (_.includes(Common.getPhyType(inst), "154g")) {
        if (inst.fixedPacketLength > 2047 || inst.fixedPacketLength < 0) {
            logError(validation, inst, "fixedPacketLength", "Fixed Packet Length must be between 0 and 2047");
            return;
        }
    }
    else if (inst.fixedPacketLength > 255 || inst.fixedPacketLength < 0) {
        logError(validation, inst, "fixedPacketLength", "Fixed Packet Length must be between 0 and 255");
        return;
    }

    // Validate consistency between frequency, symbol rate and RX Bandwidth
    const result = ParameterHandler.validateFreqSymrateRxBW(freq, inst.symbolRate, inst.rxFilterBw);
    if (!(_.isUndefined(result))) {
        logError(validation, inst, result.inst, result.message);
        return;
    }

    // Validate TX power CCFG
    const ccfg = system.modules["/ti/devices/CCFG"];

    // This is a temporary fix until CCFG is included in the SDK
    if (ccfg != null) {
        const txPower = loFreq ? inst.txPower433 : inst.txPower;

        // Force VDDR off
        if (ParameterHandler.validateTXpower(txPower, freq, prop24) && ccfg.$static.forceVddr === false) {
            logWarning(validation, ccfg.$static, "forceVddr",
                "The selected RF TX Power requires Force VDDR to be enabled.");

            const cfg = loFreq ? "txPower433" : "txPower";
            logWarning(validation, inst, cfg,
                "The selected TX Power requires Force VDDR in the Device Configuration module to be enabled.");
        }
        // Force VDDR on
        else if (!ParameterHandler.validateTXpower(txPower, freq, prop24) && ccfg.$static.forceVddr === true) {
            logWarning(validation, ccfg.$static, "forceVddr",
                "The selected RF TX Power has not been characterized with Force VDDR enabled.");

            const cfg = loFreq ? "txPower433" : "txPower";
            logWarning(validation, inst, cfg,
                "The selected TX Power has not been characterized with Force VDDR in the Device Configuration "
                + "module enabled, and may give wrong output power and higher current draw.");
        }
    }

    // Validate if all phys have the same target (only for CC1352P without board)
    if (DevInfo.hasHighPaSupport() && TargetConfig.getBoardName() === null) {
        if (Common.validateTarget()) {
            logError(validation, inst, "target", "When no board is selected the"
            + " frequency band must be consistent across all PHY types (protocols)");
        }
    }
}

/*!
 *  ======== extend ========
 *  Extends Proprietary object to include RadioConfig Basic module
 *
 */
function extend(base) {
    /* Add permission configurable */
    RFBase.addPermission(settingSpecific.config, onPermissionChange);

    /* Initialize state of UI elements (readOnly when appropriate) */
    initConfigurables(settingSpecific.config);
    Common.initLongDescription(settingSpecific.config, PropDocs.propDocs);
    Common.initLongDescription(settingSpecific.config, SharedDocs.sharedDocs);

    if (HAS_24G) {
        if (phyOptions["2400"].length > 0) {
            /* Make sure our copy of configurables is updated */
            const cmdHandler = CmdHandler.get(PHY_GROUP, phyOptions["2400"][0].name);
            cmdHandler.initConfigurables(settingSpecific.config);
        }
    }

    if (HAS_SUB1G) {
        if (phyOptions["433"].length > 0) {
            /* Make sure our copy of configurables is updated */
            const cmdHandler = CmdHandler.get(PHY_GROUP, phyOptions["433"][0].name);
            cmdHandler.initConfigurables(settingSpecific.config);
        }

        if (phyOptions["868"].length > 0) {
            /* Make sure our copy of configurables is updated */
            const cmdHandler = CmdHandler.get(PHY_GROUP, phyOptions["868"][0].name);
            cmdHandler.initConfigurables(settingSpecific.config);
        }
    }

    RFBase.pruneConfig(settingSpecific.config);

    return (Object.assign({}, base, settingSpecific));
}

exports = extend(RFBase);
