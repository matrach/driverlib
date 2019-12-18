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
 *  ======== Radio Configuration ========
 *  Radio configuration support.
 *
 *  Code used by to all RF Settings (Proprietary, BLE, TI 15.4 ...)
 */

"use strict";

// Common utility functions
const Common = system.getScript("/ti/devices/radioconfig/radioconfig_common.js");

// Other dependencies
const DeviceInfo = Common.getScript("device_info.js");
const CmdHandler = Common.getScript("cmd_handler.js");

// Target config
let TargetConfig = null;
if (DeviceInfo.hasHighPaSupport()) {
    TargetConfig = Common.getScript("target_config");
}

/*
 *  ======== updateConfigurables ========
 *  Update all configurables when the frequency band or PHY type has changed
 *
 *  @param inst  - module instance
 *  @param ui - module UI state
 *  @phyType - currently selected setting (PHY)
 *  @phyGroup - currently used PHY group
 */
function updateConfigurables(inst, ui, phyType, phyGroup) {
    const cmdHandler = CmdHandler.get(phyGroup, phyType);
    const rfData = cmdHandler.getRfData();
    _.each(rfData, (value, key) => {
        const readOnly = ui[key].readOnly;
        ui[key].readOnly = false;
        inst[key] = value;
        ui[key].readOnly = readOnly;
    });
    updateHighPA(inst, ui);
}

/*
 *  ======== updateHighPA ========
 *  Update high PA configurable when board or setting changes
 *
 *  @param inst  - module instance
 *  @param ui - module UI state
 */
function updateHighPA(inst, ui) {
    // Handle high PA separately
    if ("highPA" in inst) {
        const tgtName = inst.target;

        let prop24 = false;
        let freqBand = "2400";

        if ("freqBand" in inst) {
            // This is a proprietary setting
            freqBand = inst.freqBand;
            prop24 = freqBand === "2400";
        }
        const fb433 = freqBand === "433";

        // Get default high PA state
        if (inst.carrierFrequency < Common.LowFreqLimit && inst.carrierFrequency > 489) {
            // Special handling of P4/high PA settings
            freqBand = "490";
        }
        inst.highPA = TargetConfig.getOptimalHiPa(tgtName, freqBand) && !prop24;

        // Visibility of power tables
        ui.txPower.hidden = inst.highPA || fb433 || prop24;
        ui.txPowerHi.hidden = !inst.highPA || fb433 || prop24;

        if ("phyType433" in inst) {
            ui.txPower433.hidden = inst.highPA || !fb433;
            ui.txPower433Hi.hidden = !inst.highPA || !fb433;
        }
    }
}

/*
 *  ======== addPermission ========
 *  Add a configurable for controlling access and visibility
 *
 *  @param config - the configurable array to be extended with "permission" config
 *  @param callback - onChange callback
 */
function addPermission(config, callback) {
    config.push({
        name: "permission",
        displayName: "Permission",
        default: "None",
        onChange: callback,
        hidden: true,
        options: [
            {name: "None"},
            {name: "ReadWrite"},
            {name: "ReadOnly"}
        ]
    });
    // To aid in determining permissions
    config.push({
        name: "parent",
        displayName: "Parent",
        default: "Stack",
        hidden: true
    });
}


/*
 *  ======== addTxPowerConfigHigh ========
 *  Add a configurables for Target and PA selection
 *
 *  @param config - the setting to apply the new configurables to
 *  @param highPaDefault - initial highPA choice
 */
function addTxPowerConfigHigh(config, highPaDefault) {
    const targetSelection = {
        name: "target",
        displayName: "Optimize PA-table for board/band",
        description: "Select the board (frequency band) to optimize the PA-table for",
        default: TargetConfig.getTargetName(),
        options: TargetConfig.getTargetMap(),
        hidden: TargetConfig.getBoardName() !== null,
        onChange: function(inst, ui) {
            // Update PA visibility and value
            updateHighPA(inst, ui);
            // Apply new values to target
            TargetConfig.reset(inst);
        }
    };

    const txPowHi = {
        name: "txPowerHi",
        displayName: "TX Power (dBm)",
        description: "The transmit power to use",
        default: "0",
        hidden: !highPaDefault
    };

    const highPa = {
        name: "highPA",
        displayName: "High PA",
        description: "Select if the High Power Amplifier on the device should be used",
        default: highPaDefault,
        onChange: function(inst, ui) {
            TargetConfig.reset(inst);
            // Swap power tables
            if ("phyType" in inst) {
                ui.txPower.hidden = inst.highPA;
                ui.txPowerHi.hidden = !inst.highPA;
            }
            if ("phyType868" in inst) {
                ui.txPower.hidden = inst.highPA || ui.phyType868.hidden;
                ui.txPowerHi.hidden = !inst.highPA || ui.phyType868.hidden;
            }
            if ("phyType433" in inst) {
                ui.txPower433.hidden = inst.highPA || ui.phyType433.hidden;
                ui.txPower433Hi.hidden = !inst.highPA || ui.phyType433.hidden;
            }
        }
    };

    // Find position of "txPower"
    let txPowerPos = 0;
    // Currently only prop contains a group with name PHY Properties
    const isProp = _.some(config, ["displayName", "PHY Properties"]);

    if (isProp) {
        const phyLayer = _.find(config, ["displayName", "PHY Properties"]);

        txPowerPos = _.findIndex(phyLayer.config, ["name", "txPower"]);
        phyLayer.config[txPowerPos].hidden = highPaDefault;

        // Insert before "txPower"
        phyLayer.config.splice(txPowerPos, 0, highPa, txPowHi);
    }
    else {
        txPowerPos = _.findIndex(config, ["name", "txPower"]);
        config[txPowerPos].hidden = highPaDefault;

        // Insert before "txPower"
        config.splice(txPowerPos, 0, highPa, txPowHi);
    }

    // Insert at start
    config.unshift(targetSelection);
}

/*
 *  ======== pruneConfig ========
 *  Removed 'key' member from options list
 *
 *  @param config - configurable array to be modified
 */
function pruneConfig(config) {
    _.each(config, (item) => {
        if (_.has(item, "options")) {
            _.each(item.options, (opt) => {
                delete opt.key;
            });
        }
        else if (_.has(item, "config")) {
            _.each(item.config, (subItem) => {
                if (_.has(subItem, "options")) {
                    _.each(subItem.options, (opt) => {
                        delete opt.key;
                    });
                }
            });
        }
    });
}

/*
 *  ======== moduleInstances ========
 *  Determines what modules are added as sub-modules
 *
 *  @param inst  - Module instance containing the config that changed
 *  @returns     - Array containing the dependency modules
 */
function moduleInstances(inst) {
    // Controls visibility/access of code export config
    const noAccess = inst.permission === "ReadOnly";

    return [
        {
            name: "codeExportConfig",
            displayName: "Code Export Configuration",
            moduleName: Common.basePath + "code_export_param",
            collapsed: true,
            readOnly: noAccess,
            hidden: noAccess,
            args: {
                selectedPhyType: Common.getPhyType(inst),
                selectedPhy: Common.getPhyGroup(inst)
            }
        }
    ];
}

/*
 *  ======== modules ========
 *  Determines what modules are added as static sub-modules
 *
 *  @returns     - Array containing a static dependency modules
 */
function modules() {
    return [{
        name: "RF",
        displayName: "RF Driver",
        moduleName: "/ti/drivers/RF",
        collapsed: true
    }];
}

exports = {
    updateConfigurables: updateConfigurables,
    addTxPowerConfigHigh: addTxPowerConfigHigh,
    addPermission: addPermission,
    pruneConfig: pruneConfig,
    modules: modules,
    moduleInstances: moduleInstances,
    templates: {
        "/ti/devices/radioconfig/templates/rf_settings.c.xdt":
            "/ti/devices/radioconfig/settings/phygroup.c.xdt",
        "/ti/devices/radioconfig/templates/rf_settings.h.xdt":
            "/ti/devices/radioconfig/settings/phygroup.h.xdt"
    }
};
