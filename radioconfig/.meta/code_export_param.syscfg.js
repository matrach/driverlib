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
 *  ======== code_export_param.syscfg.js ========
 *  Module to configure code generation
 */

"use strict";

// Common utility functions
const Common = system.getScript("/ti/devices/radioconfig/radioconfig_common.js");

// Other dependencies
const DevInfo = Common.getScript("device_info.js");
const CmdHandler = Common.getScript("cmd_handler.js");

// Documentation
const CodeExportDocs = Common.getScript("code_export_param_docs.js");

// Protocol support
const hasProp = Common.HAS_PROP;
const hasBle = Common.HAS_BLE;
const hasIeee = Common.HAS_IEEE_15_4;

// Storage for generated variable names, used by code generation template
const symNames = {
    txPower: "txPowerTable",
    txPowerSize: "TX_POWER_TABLE_SIZE",
    rfMode: "RF_prop",
    overrides: "pOverrides"
};

// Symbols that need a post-fix appended
const needPostfix = [
    "txPower",
    "txPowerSize",
    "overrides",
    "rfMode"
];

// List of RF commands that can be individually configured
const rfCmdNames = {};

// Cache for global configurables
const globalCache = {};

// Cache for setting specific configurables, indexed by PHY type
const configCache = {};

// Manage changes in symbol generation method
let nSymGenChanges = 0;

// Configurables that need to be preserved in each instance
const needCache = [
    "rfMode",
    "txPower",
    "txPowerSize",
    "overrides",
    "cmdPrefix",
    "cmdFormat",
    "cmdList_prop",
    "cmdList_ble",
    "cmdList_ieee_15_4",
    "stackOverride",
    "stackOverrideMacro",
    "appOverride",
    "appOverrideMacro"
];

// Configurable that need to be preserved globally
const needCacheGlobal = [
    "paExport",
    "useMulti",
    "useConst"
];

// List of PA options
const paOptions = getPaOptions();

// List of commands by PHY group
const CmdMap = {};

// Storage for customized command list (additional commands kept when changing PHY)
let cmdListCustom = [];
let PhyGroup = "none";

const cmdSymbolsCat = {
    displayName: "RF Command Symbols",
    collapsed: true,
    config: [
        // Command variable name prefix
        {
            name: "cmdPrefix",
            displayName: "RF Command Variable Prefix",
            onChange: onCmdFormatChanged,
            default: "RF_"
        },
        // Command variable name format
        {
            name: "cmdFormat",
            displayName: "RF Command Variable Format",
            onChange: onCmdFormatChanged,
            options: [{
                name: "camelCase"
            }, {
                name: "underscore_case"
            }],
            default: "camelCase"
        }
    ]
};

// Add RF command configurables
if (hasProp) {
    createCommandList(Common.PHY_PROP);
}

if (hasBle) {
    createCommandList(Common.PHY_BLE);
}

if (hasIeee) {
    createCommandList(Common.PHY_IEEE_15_4);
}

// Module configurable
const config = [
    // Symbol generation method
    {
        name: "symGenMethod",
        displayName: "Symbol Name Generation Method",
        onChange: onSymGenMethodChanged,
        options: [{
            name: "Legacy"
        }, {
            name: "Automatic"
        }, {
            name: "Custom"
        }],
        default: "Automatic"
    },
    // PA table export config
    {
        name: "paExport",
        displayName: "PA table Export Method",
        description: "Select how PA table is to be exported",
        onChange: onPaExportChanged,
        // Active PA table as default
        default: paOptions[1].name,
        options: paOptions,
        getDisabledOptions: function(inst) {
            const phyGroup = inst.selectedPhy;
            if (DevInfo.hasHighPaSupport() && phyGroup === Common.PHY_PROP) {
                const cmdHandler = CmdHandler.get(phyGroup, inst.selectedPhyType);

                if (cmdHandler.getFrequencyBand() === 2400) {
                    const msg = "Not available for 2.4 GHz proprietary";
                    return [
                        {
                            name: "dual",
                            reason: msg
                        },
                        {
                            name: "combined",
                            reason: msg
                        }
                    ];
                }
            }
            return [];
        }
    },
    // Use const qualifier
    {
        name: "useConst",
        displayName: "Make generated RF commands constant",
        description: "Use 'const' qualifier for RF Core commands",
        default: false
    },
    // Use multi-protocol
    {
        name: "useMulti",
        displayName: "Use Multi-protocol patch",
        description: "Use multi-protocol rather than individual protocol patches",
        default: false
    },
    // Stack specific override
    {
        name: "stackOverride",
        displayName: "Stack override file",
        description: "Path to a file that contains stack specific overrides",
        default: ""
    },
    // Stack specific override macro
    {
        name: "stackOverrideMacro",
        displayName: "Stack override macro",
        description: "Macro to use for including stack overrides",
        default: ""
    },
    // App specific override
    {
        name: "appOverride",
        displayName: "Application override file",
        description: "Path to a file that contains application specific overrides",
        default: ""
    },
    // App specific override macro
    {
        name: "appOverrideMacro",
        displayName: "Application override macro",
        description: "Macro to use for including application overrides",
        default: ""
    },
    // RF Command Symbols category
    cmdSymbolsCat,
    {
        displayName: "Other Symbols",
        collapsed: true,
        config: [
            // TI-RTOS RF Mode Object
            {
                name: "rfMode",
                displayName: "RF Mode Symbol Name",
                default: symNames.rfMode
            },
            // TX Power table
            {
                name: "txPower",
                displayName: "TX Power Table Symbol Name",
                default: symNames.txPower
            },
            // TX Power table size definition
            {
                name: "txPowerSize",
                displayName: "TX Power Table Size Symbol Name",
                default: symNames.txPowerSize
            },
            // Overrides
            {
                name: "overrides",
                displayName: "Overrides Table Symbol Name",
                description: "Use multi-protocol rather than individual protocol patches",
                default: symNames.overrides
            }
        ]
    },
    {
        name: "selectedPhy",
        default: "none",
        hidden: true,
        onChange: reset
    },
    {
        name: "selectedPhyType",
        default: "none",
        hidden: true
    }
];

// Add documentation to main commands
Common.initLongDescription(config, CodeExportDocs.codeExportDocs);

// Module exports
exports = {
    displayName: "Code Export Configuration",
    config: config,
    validate: validate,
    getSymNames: getSymNames,
    createCommandList: createCommandList,
    getCustomOverrideInfo: getCustomOverrideInfo
};


/*!
 * ======== createCommandList ========
 * Create list of commands for a PHY group. This must be done
 * at load time, as option lists can not be modified on the fly.
 *
 * @param phyGroup - ble, prop or ieee_15_4
 */
function createCommandList(phyGroup) {
    const cmdMap = {};
    // Collect all commands used by this PHY group
    const settingMap = DevInfo.getSettingMap(phyGroup);
    _.each(settingMap, (s) => {
        const phyType = s.name;
        const cmdHandler = CmdHandler.get(phyGroup, phyType);
        const cmdList = cmdHandler.getCmdList("all");
        _.each(cmdList, (cmd) => {
            const id = _.camelCase(cmd);
            cmdMap[id] = {
                id: id,
                cmd: cmd,
                description: cmdHandler.getCommandDescription(cmd)
            };
        });
    });
    CmdMap[phyGroup] = _.cloneDeep(cmdMap);

    // Create command option list
    const cmdOpts = _.map(cmdMap, item => ({
        name: item.id,
        displayName: item.cmd,
        description: item.description
    }));

    // Add command list configurable
    const cmdListName = "cmdList_" + phyGroup;
    const cmdConfig = {
        name: cmdListName,
        displayName: "RF Command List",
        description: "List of supported RF Commands",
        minSelections: 0,
        options: cmdOpts,
        default: [], // all commands unchecked by default
        onChange: function(inst, ui) {
            cmdListCustom = inst[cmdListName];
            updateCommandVisibility(inst, ui);
            onCmdFormatChanged(inst);
        }
    };

    cmdSymbolsCat.config.push(cmdConfig);

    // Add each command as a configurable
    _.each(cmdMap, (item) => {
        let value = "RF_" + item.id;
        const name = item.id;
        if (name.includes("SetupPa")) {
            value = value.replace("Pa", "");
        }

        // Keep list of commands
        if (!(name in rfCmdNames)) {
            rfCmdNames[name] = value;
            const cfg = {
                name: name,
                displayName: item.cmd,
                description: item.description,
                hidden: true,
                default: value
            };
            cmdSymbolsCat.config.push(cfg);
        }
    });
}

/*!
 * ======== updateCommandVisibility ========
 * Update the visibility state of the individual commands
 *
 * @param inst - Code Export Param instance
 * @param ui - UI state object
 */
function updateCommandVisibility(inst, ui) {
    const cmdListActive = getSelectedCommands(inst);
    const cdmListAll = CmdMap[PhyGroup];

    // Show checked commands only
    _.forEach(cdmListAll, (cmd) => {
        const id = cmd.id;
        if (cmdListActive.includes(id)) {
            ui[id].hidden = false;
        }
        else {
            ui[id].hidden = true;
        }
    });
}

/*!
 * ======== updatePhyTypeCommands ========
 * Set the visibility state of RF commands according to their presence
 * in the active PHY setting of the active PHY group
 *
 * @param inst - Code Export Param instance
 * @param ui - UI state object
 */
function updatePhyTypeCommands(inst, ui) {
    const phySetting = inst.selectedPhyType;
    const key = "cmdList_" + PhyGroup;

    if (key in inst) {
        // Current command list
        let cmdList = inst[key];

        if (cmdList.length === 0) {
            // Use default (basic) command list the first time
            cmdList = CmdHandler.get(PhyGroup, phySetting).getCmdList("basic");
        }

        // Create list of checked commands in Command list
        const selected = [];
        _.each(cmdList, (cmd) => {
            const id = _.camelCase(cmd);
            selected.push(id);
        });

        // Apply list of selected commands
        inst[key] = selected;

        // Update visibility of individual commands
        updateCommandVisibility(inst, ui);
    }
}

/*!
 * ======== reset ========
 * Set the visibility state of RF commands according to their presence in the PHY
 * group of the active instance. Example: if BLE is used, only common and BLE commands
 * should be visible.
 *
 * @param inst - Code Export Param instance
 * @param ui - UI state object
 */
function reset(inst, ui) {
    // Clear custom command selection when PHY group changes
    if (PhyGroup !== inst.selectedPhy) {
        PhyGroup = inst.selectedPhy;
        cmdListCustom = [];
    }

    // Update visibility of command selection
    const visDescr = {
        prop: PhyGroup !== Common.PHY_PROP,
        ble: PhyGroup !== Common.PHY_BLE,
        ieee_15_4: PhyGroup !== Common.PHY_IEEE_15_4
    };

    _.each(visDescr, (hidden, pg) => {
        const keyId = "cmdList_" + pg;
        if (keyId in ui) {
            ui[keyId].hidden = hidden;
        }
    });

    // Restore configurable values
    nSymGenChanges = 0;
    readCache(inst);

    // Merge in any changes made to the command list
    const cmdListName = "cmdList_" + PhyGroup;
    let cmdListCached = inst[cmdListName];

    cmdListCached = _.union(cmdListCached, cmdListCustom);
    inst[cmdListName] = cmdListCached;

    // Update the command list
    updatePhyTypeCommands(inst, ui);

    if (nSymGenChanges === 0) {
        // When the module is instantiated this function must be called
        // once and only once. This will have been automatically done
        // in readCache if 'symGenMethod' has changed.
        onSymGenMethodChanged(inst, ui);
    }
}


/*!
 *  ======== getSelectedCommands ========
 *  Get list of selected commands
 *
 *  @param inst - active instance
 */
function getSelectedCommands(inst) {
    const phyGroup = inst.selectedPhy;
    const key = "cmdList_" + phyGroup;
    let ret = [];
    if (key in inst) {
        ret = inst[key];
    }
    return ret;
}

/*!
 *  ======== getHiddenCommands ========
 *  Get list of hidden commands
 *
 *  @param inst - active instance
 */
function getHiddenCommands(inst) {
    const hidden = [];
    const visible = getSelectedCommands(inst);

    _.each(rfCmdNames, (val, cmd) => {
        if (!visible.includes(cmd)) {
            hidden.push(cmd);
        }
    });
    return hidden;
}

/*!
 *  ======== getSymNames ========
 *  Get variable names
 *
 *  @param inst - active instance
 */
function getSymNames(inst) {
    const automatic = inst.symGenMethod === "Automatic";
    const cache = {};
    const activeCmds = getSelectedCommands(inst);
    const hiddenCmds = getHiddenCommands(inst);

    for (const name in inst) {
        if (!name.includes("$") && !hiddenCmds.includes(name)) {
            cache[name] = inst[name];
            if (automatic) {
                if (needPostfix.includes(name) || activeCmds.includes(name)) {
                    cache[name] = getDefaultValue(inst, name);
                }
            }
        }
    }

    return cache;
}

/*
 * Callbacks for configurable change handling
 *
 */

/*!
 * ======== onSymGenMethodChanged ========
 * Invoked when symbol name generation method changed
 *
 * @param inst - active instance
 * @param ui - active UI
 */
function onSymGenMethodChanged(inst, ui) {
    const automatic = inst.symGenMethod === "Automatic";
    const customEnable = inst.symGenMethod === "Custom";
    const allVars = Object.assign({}, symNames, rfCmdNames);

    // Set RF Commands read-write when custom mode
    if (customEnable) {
        for (const name in allVars) {
            if (name in ui) {
                ui[name].readOnly = false;
            }
        }
    }

    if (customEnable || automatic) {
        // Restore default values
        for (const name in allVars) {
            if (name in inst) {
                inst[name] = getDefaultValue(inst, name);
            }
        }
    }
    else {
        // Restore default values for symbols
        for (const name in symNames) {
            if (name in inst) {
                inst[name] = getDefaultValue(inst, name);
            }
        }
        // Refresh command names
        onCmdFormatChanged(inst, ui);
    }

    // Set RF Commands read-only when not custom mode
    if (!customEnable) {
        for (const name in allVars) {
            if (name in ui) {
                ui[name].readOnly = true;
            }
        }
    }

    ui.cmdPrefix.hidden = customEnable || automatic;
    ui.cmdFormat.hidden = customEnable || automatic;

    nSymGenChanges += 1;
}

/*!
 * ======== onSymGenMethodChanged ========
 * Invoked when symbol name format for RF Commands changed
 *
 * @param inst - active instance
 */
function onCmdFormatChanged(inst) {
    if (inst.symGenMethod !== "Legacy") {
        return;
    }
    const activeCommands = getSelectedCommands(inst);

    _.each(activeCommands, (cmdName) => {
        const name = getDefaultValue(inst, cmdName).replace("RF_", "");
        let newName = inst.cmdPrefix;
        if (inst.cmdFormat === "camelCase") {
            newName += name;
        }
        else {
            newName += _.snakeCase(name);
        }
        inst[cmdName] = newName;
    });
}

/*!
 * ======== onPaExportChanged ========
 * Invoked when PA export options changed
 *
 * @param inst - active instance
 * @param ui - UI state
 */
function onPaExportChanged(inst, ui) {
    const hidden = inst.paExport === "none";
    ui.txPower.hidden = hidden;
    ui.txPowerSize.hidden = hidden;
}

/*!
 * ======== readCache ========
 * Read cached values
 *
 * @param inst - active instance
 */
function readCache(inst) {
    const key = inst.selectedPhyType;
    if (!(key in configCache)) {
        writeCache(inst);
    }
    else {
        // RF commands
        const cmds = getSelectedCommands(inst);
        _.each(cmds, (cfg) => {
            inst[cfg] = configCache[key][cfg];
        });

        // Other symbols
        _.each(needCache, (cfg) => {
            if (cfg in inst) {
                inst[cfg] = configCache[key][cfg];
            }
        });

        _.each(needCacheGlobal, (cfg) => {
            if (cfg in inst && cfg in globalCache) {
                inst[cfg] = globalCache[cfg];
            }
        });
    }
}

/*!
 * ======== writeCache ========
 * Stored instance values in cache
 *
 * @param inst - active instance
 */
function writeCache(inst) {
    const key = inst.selectedPhyType;

    if (!(key in configCache)) {
        configCache[key] = {};
    }

    // RF commands
    const cmds = getSelectedCommands(inst);
    _.each(cmds, (cfg) => {
        configCache[key][cfg] = inst[cfg];
    });

    // Other symbols
    _.each(needCache, (cfg) => {
        configCache[key][cfg] = inst[cfg];
    });

    _.each(needCacheGlobal, (cfg) => {
        if (cfg in inst) {
            globalCache[cfg] = inst[cfg];
        }
    });
}

/*!
 * ======== getDefaultValue ========
 * Get default value of a configurable
 *
 * @param inst - active instance
 * @param cfgName - configurable name
 */
function getDefaultValue(inst, cfgName) {
    const cfgs = inst.$module.config;
    let ret = "";
    function setRet(cfg) {
        if (cfgName === cfg.name) {
            ret = cfg.default;
            return false;
        }
        return true;
    }
    _.each(cfgs, (cfg) => {
        if (_.has(cfg, "config")) {
            _.each(cfg.config, (subcfg) => {
                setRet(subcfg);
            });
        }
        else {
            setRet(cfg);
        }
    });

    if (inst.symGenMethod === "Automatic") {
        const name = inst.$name;
        const instIdx = name.substr(name.length - 1);
        ret += "_" + inst.selectedPhyType + "_" + instIdx;
    }
    return ret;
}

/*!
 * ======== getPaOptions ========
 * Get PA export table configuration options
 */
function getPaOptions() {
    let paOpt = [{
        name: "none",
        displayName: "No PA table"
    }, {
        name: "active",
        displayName: "Active PA table"
    }];

    if (DevInfo.hasHighPaSupport()) {
        // Add options for High PA devices
        const hiPaOpt = [{
            name: "dual",
            displayName: "Standard and High Gain PA tables"
        }, {
            name: "combined",
            displayName: "Combined PA table"
        }];

        paOpt = paOpt.concat(hiPaOpt);
    }
    return paOpt;
}

/*!
 * ======== getDefaultValue ========
 * Check if symbols are duplicated
 *
 * @param myInst - active instance
 * @param validation - validation object
 */
function checkDuplicateSymbols(myInst, validation) {
    const modules = system.modules;
    const symMap = [];
    let hasLegacy = false;

    // Iterate RadioConfig modules
    _.each(modules, (mod) => {
        if (mod.$name.includes("radioconfig/settings")) {
            const instances = mod.$instances;
            // Iterate module instances
            _.each(instances, (inst) => {
                const ce = inst.codeExportConfig;
                const isLegacy = ce.symGenMethod === "Legacy";

                // Check if more than one instance used legacy code generation
                if (isLegacy) {
                    if (!hasLegacy) {
                        hasLegacy = true;
                    }
                    else {
                        Common.logError(validation, myInst, "symGenMethod",
                            "Legacy mode code generation can only be applied to one PHY.");
                        return false;
                    }
                    return true;
                }

                // Iterate symbols
                const rfCmds = getSelectedCommands(ce);
                const symList = needPostfix.concat(rfCmds);

                let nRfCmdErr = 0;
                _.each(symList, (sym) => {
                    if (sym in myInst) {
                        if (symMap.includes(ce[sym])) {
                            // Symbol already in use
                            if (rfCmds.includes(sym) && isLegacy) {
                                nRfCmdErr += 1;
                            }
                            else {
                                Common.logError(validation, myInst, sym, "symbol duplicated");
                            }
                        }
                        else {
                            // Mark symbol as used
                            symMap.push(ce[sym]);
                        }
                    }
                });

                if (nRfCmdErr > 0) {
                    const msg = "RF Command symbols duplicated. Make sure that command prefix"
                        + " or command format are unique across all settings.";
                    Common.logError(validation, myInst, "cmdPrefix", msg);
                    return false;
                }
                return true;
            });
        }
    });
}

/*!
*  ======== getCustomOverrideInfo ========
*  Get information on stack overrides
*/
function getCustomOverrideInfo() {
    const modules = system.modules;
    const paths = [];
    const macros = [];

    // Iterate RadioConfig modules
    _.each(modules, (mod) => {
        if (mod.$name.includes("radioconfig/settings")) {
            const instances = mod.$instances;
            _.each(instances, (inst) => {
                const ce = inst.codeExportConfig;

                // Stack overrides
                let path = ce.stackOverride;
                let macro = ce.stackOverrideMacro;
                if (path !== "" && macro !== "") {
                    paths.push(path);
                    macros.push(macro);
                }

                // Application overrides
                path = ce.appOverride;
                macro = ce.appOverrideMacro;
                if (path !== "" && macro !== "") {
                    paths.push(path);
                    macros.push(macro);
                }
            });
        }
    });
    return {
        paths: _.union(paths),
        macros: _.union(macros)
    };
}

/*!
 *  ======== validate ========
 *  Validate this module's configuration
 *
 *  @param inst - Code Export Param instance to be validated
 *  @param validation - Issue reporting object
 */
function validate(inst, validation) {
    writeCache(inst);

    // Verify unique symbols
    checkDuplicateSymbols(inst, validation);

    // Verify valid C symbols
    for (const name in symNames) {
        if (name in inst) {
            const val = inst[name];
            if (Common.isCName(val)) {
                if (val === "") {
                    Common.logError(validation, inst, name, "empty variable name not allowed");
                }
            }
            else {
                Common.logError(validation, inst, name, "'" + val + "' is not a valid C identifier");
            }
        }
    }

    // Verify stack override file path name and stack override macro name
    const filePath = inst.stackOverride;
    if (filePath !== "") {
        // Check that the file is in the '/ti' name space
        if (filePath.substr(0, 3) !== "ti/") {
            Common.logError(validation, inst, "stackOverride", "Stack override file must reside in 'ti' name-space.");
        }
        else {
            validateCustomOverride(inst, validation, "stackOverride", "stackOverrideMacro");
        }
    }

    // Verify application override file path name and application override macro name
    validateCustomOverride(inst, validation, "appOverride", "appOverrideMacro");
}


/*!
 *  ======== validateCustomOverride ========
 *  Validate path- and macro names for custom overrides
 *
 *  @param inst - Code Export Param instance to be validated
 *  @param validation - Issue reporting object
 *  @param path - Name of "path" configurable, stores custom override file name
 *  @param macro - Name of "macro" configurable, stores macro name
 */
function validateCustomOverride(inst, validation, path, macro) {
    const filePath = inst[path];
    const macroName = inst[macro];

    if (filePath !== "") {
        // Check that the file has the extension .h and is a combination of letters, digits and '_'
        // The path may be of the pattern /dir/file.h or ../../file.h
        const pathRegEx = RegExp(/^(\.\.\/)*([a-zA-Z0-9_]+\/)*([a-zA-Z0-9_]+)+\.h$/);
        if (!pathRegEx.test(filePath)) {
            Common.logError(validation, inst, path,
                "File name must have extension .h and contain only alphanumeric and underscore letters. "
                + "UNIX relative path format expected.");
        }

        // Check that the macro is valid
        if (Common.isCName(macroName)) {
            if (macroName === "") {
                Common.logError(validation, inst, macro, "Override macro name must be present.");
            }
        }
        else {
            Common.logError(validation, inst, macro, "'" + macroName + "' is not a valid C identifier");
        }
    }
    else if (macroName !== "") {
        Common.logError(validation, inst, path, "Override file name must be present.");
    }
}
