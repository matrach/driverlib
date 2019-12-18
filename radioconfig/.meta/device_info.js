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
 *  ======== device_info.js ========
 *  Device information database
 */

"use strict";

// Module version
const RADIO_CONFIG_VERSION = "1.4";

// Common utility functions
const Common = system.getScript("/ti/devices/radioconfig/radioconfig_common.js");

// Global path to Radio configuration root
const ConfigPath = Common.basePath + "config/";

// Mapping SysCfg device name notation to SmartRF Studio format */
const devNameMap = {
    // SysCfg name : SmartRF Studio name
    CC1352R1F3RGZ: "cc1352r",
    CC1352P1F3RGZ: "cc1352p",
    CC1312R1F3RGZ: "cc1312r",
    CC2652R1FRGZ: "cc2652r",
    CC2642R1FRGZ: "cc2642r",
    CC2652RB: "cc2652rb",
    CC2652PRGZ: "cc2652p"
};

// SmartRF Studio compatible device name
const DeviceName = devNameMap[Common.Device];

if (!DeviceName) {
    throw Error(Common.Device + " is not supported by RadioConfig");
}

// true if High PA device
const highPaDevice = DeviceName === "cc1352p" || DeviceName === "cc2652p";

/*
 * Global device information
 */
const DevInfo = {
    // Path to the configuration data for the device
    devicePath: ConfigPath + DeviceName + "/",
    phyGroup: {
        prop: {},
        ble: {},
        ieee_15_4: {}
    },
    // PHY name: "ble", "prop" or "ieee_15_4"
    phy: "",
    // Board name on SmartRF Studio format
    target: "",
    // True if device supports High PA (CC1352P and CC2652P)
    highPaSupport: highPaDevice
};

// Load the device configuration database
const DevConfig = getDeviceConfig();

// Mapping PHY setting names to SmartRF Studio setting file names
let settingsMapProp = [];

// Proprietary settings for 2.4 GHz band
if (Common.HAS_2_4G_PROP) {
    settingsMapProp = [
        {
            name: "2gfsk100kbps",
            description: "100 kbps, 2-GFSK, 50 kHz deviation",
            file: "setting_tc900.json"
        },
        {
            name: "2gfsk250kbps",
            description: "250 kbps, 2-GFSK, 125 kHz deviation",
            file: "setting_tc901.json"
        },
        {
            name: "2msk250kbps",
            description: "250 kbps MSK, 62.5 kHz deviation",
            file: "setting_tc902.json"
        },
        {
            name: "custom2400",
            description: "Custom PHY Setting",
            file: "setting_tc900_custom.json"
        }
    ];
}

// Proprietary settings for SUB 1GHz band
if (DeviceName === "cc1352r" || DeviceName === "cc1312r") {
    const settingsMapPropSub1G = [
        {
            name: "2gfsk50kbps",
            description: "50 kbps, 2-GFSK",
            file: "setting_tc106.json"
        },
        {
            name: "2gfsk50kbps154g",
            description: "50 kbps, 2-GFSK, 15.4g",
            file: "setting_tc106_154g.json"
        },
        {
            name: "2gfsk200kbps154g",
            description: "200 kbps, 2-GFSK, 15.4g",
            file: "setting_tc146_154g.json"
        },
        {
            name: "slr5kbps2gfsk",
            description: "5 kbps, SimpleLink Long Range",
            file: "setting_tc480.json"
        },
        {
            name: "slr2500bps2gfsk",
            description: "2.5 kbps, SimpleLink Long Range",
            file: "setting_tc481.json"
        },
        {
            name: "2gfsk50kbps433mhz",
            description: "50 kbps, 2-GFSK",
            file: "setting_tc112.json"
        },
        {
            name: "2gfsk50kbps433mhz154g",
            description: "50 kbps, 2-GFSK, 15.4g",
            file: "setting_tc112_154g.json"
        },
        {
            name: "slr5kbps433mhz",
            description: "5 kbps, SimpleLink Long Range",
            file: "setting_tc440.json"
        },
        {
            name: "slr2500bps433mhz",
            description: "2.5 kbps, SimpleLink Long Range",
            file: "setting_tc441.json"
        },
        {
            name: "custom868",
            description: "Custom PHY Setting",
            file: "setting_tc106_custom.json"
        },
        {
            name: "custom433",
            description: "Custom PHY Setting",
            file: "setting_tc112_custom.json"
        }
    ];

    if (DeviceName === "cc1312r") {
        settingsMapProp = settingsMapPropSub1G;
    }
    else {
        // CC1352R
        settingsMapProp = settingsMapProp.concat(settingsMapPropSub1G);
    }
}
else if (DeviceName === "cc1352p") {
    const settingsMapPropSub1G = [
        {
            name: "2gfsk50kbps",
            description: "50 kbps, 2-GFSK",
            file: "setting_tc706.json"
        },
        {
            name: "2gfsk50kbps154g",
            description: "50 kbps, 2-GFSK, 15.4g",
            file: "setting_tc706_154g.json"
        },
        {
            name: "2gfsk200kbps154g",
            description: "200 kbps, 2-GFSK, 15.4g, High PA",
            file: "setting_tc746_154g.json"
        },
        {
            name: "slr5kbps2gfsk",
            description: "5 kbps, SimpleLink Long Range",
            file: "setting_tc880.json"
        },
        {
            name: "slr2500bps2gfsk",
            description: "2.5 kbps, SimpleLink Long Range",
            file: "setting_tc881.json"
        },
        {
            name: "2gfsk50kbps433mhz",
            description: "50 kbps, 2-GFSK",
            file: "setting_tc112.json"
        },
        {
            name: "2gfsk50kbps154g433mhz",
            description: "50 kbps, 2-GFSK, 15.4g",
            file: "setting_tc112_154g.json"
        },
        {
            name: "slr5kbps2gfsk433mhz",
            description: "5 kbps, SimpleLink Long Range",
            file: "setting_tc440.json"
        },
        {
            name: "slr2500bps2gfsk433mhz",
            description: "2.5 kbps, SimpleLink Long Range",
            file: "setting_tc441.json"
        },
        {
            name: "mrfsk50kbps433mhz",
            description: "50 kbps, 2-GFSK, High PA",
            file: "setting_tc712.json"
        },
        {
            name: "mrfsk50kbps154g433mhz",
            description: "50 kbps, 2-GFSK, 15.4g, High PA",
            file: "setting_tc712_154g.json"
        },
        {
            name: "custom868",
            description: "Custom PHY Setting",
            file: "setting_tc706_custom.json"
        },
        {
            name: "custom433",
            description: "Custom PHY Setting",
            file: "setting_tc112_custom.json"
        }
    ];
    settingsMapProp = settingsMapProp.concat(settingsMapPropSub1G);
}

// Mapping PHY setting names to SmartRF Studio setting file names
const settingsMapBLE = [
    {
        name: "bt5le1m",
        description: "Bluetooth 5, 1 Mbps",
        file: "setting_bt5_le_1m.json"
    },
    {
        name: "bt5le1madvnc",
        description: "Bluetooth 5, 1 Mbps, BT4 compatible",
        file: "setting_bt5_le_1m_adv_nc.json"
    },
    {
        name: "bt5le2m",
        description: "Bluetooth 5, 2 Mbps",
        file: "setting_bt5_le_2m.json"
    },
    {
        name: "bt5lecodeds2",
        description: "Bluetooth 5, 500 kbps",
        file: "setting_bt5_le_coded_s2.json"
    },
    {
        name: "bt5lecodeds8",
        description: "Bluetooth 5, 125 kbps",
        file: "setting_bt5_le_coded_s8.json"
    }
];

const settingsMap154 = [
    {
        name: "ieee154",
        description: "IEEE 802.15.4, 250 kbps",
        file: "setting_ieee_802_15_4.json"
    }
];

// Exported from this module
exports = {
    addPhyGroup: addPhyGroup,
    getVersionInfo: getVersionInfo,
    getSettingMap: function(phy) {
        if (phy === Common.PHY_IEEE_15_4) {
            return settingsMap154;
        }
        else if (phy === Common.PHY_BLE) {
            return settingsMapBLE;
        }
        else if (phy === Common.PHY_PROP) {
            return settingsMapProp;
        }
        throw Error("Unknown protocol: ", phy);
    },
    getDeviceName: function() {
        return DeviceName;
    },
    getParamPath: function(phy) {
        return DevInfo.phyGroup[phy].paramPath;
    },
    getSettingPath: function(phy) {
        return getFilePathPhy("categories.json", phy);
    },
    getRfCommandDef: function(phy) {
        return getFullPathPhy("rf_command_definitions.json", phy);
    },
    getTargetPath: function(phy) {
        return getFilePathPhy("targets.json", phy);
    },
    getTargetIndex: function(phy) {
        return getFullPathPhy("targets.json", phy);
    },
    getPaSettingsPath: function() {
        return getFilePath("pasettings.json");
    },
    getFrontEndFile: function(phy) {
        return getFullPathPhy("frontend_settings.json", phy);
    },
    getCmdMapping: function(phy) {
        return getFullPathPhy("param_cmd_mapping.json", phy);
    },
    getSyscfgParams: function(phy) {
        return DevInfo.phyGroup[phy].paramPath + "param_syscfg.json";
    },
    hasHighPaSupport: function() {
        return DevInfo.highPaSupport;
    },
    getOverridePath: function(phy) {
        return getFilePathPhy("dummy_file_overrides.json", phy);
    }
};

/*!
 *  ======== getVersionInfo ========
 *  Get version information for RadioConfig and SmartRF Studio
 */
function getVersionInfo() {
    const deviceList = system.getScript(ConfigPath + "device_list.json");

    const smartRFDataVersion = deviceList.devicelist.version;
    return {moduleVersion: RADIO_CONFIG_VERSION, dataVersion: smartRFDataVersion};
}


/*!
 *  ======== getDeviceConfig ========
 *  Create a device configuration database.
 *
 *  Grouped by the PHY's that are available for the current device.
 */
function getDeviceConfig() {
    const files = system.getScript(DevInfo.devicePath + "device_config.json").configFiles.path;
    const fileLists = {
        default: [],
        ble: [],
        prop: [],
        ieee_15_4: []
    };

    _.each(files, (value) => {
        const entry = {
            path: value.$,
            file: value._file
        };

        let list;
        if ("_phy" in value) {
            const phy = value._phy;
            list = fileLists[phy];
        }
        else {
            list = fileLists.default;
        }

        if ("_version" in value) {
            // Versioned: remove base entry
            // assuming base entry is immediately before versioned entry
            list.pop();
        }
        list.push(entry);
    });

    return fileLists;
}

/*!
 *  ======== getFullPathPhy ========
 *  Return the path including the file name
 *
 * @param file - name of the file which path is to be determined
 * @param phy - ble, prop or ieee_154
 */
function getFullPathPhy(file, phy) {
    return getFilePathPhy(file, phy) + file;
}

/*!
 *  ======== getFilePath ========
 *  Return the path of a file.
 *
 * @param file - name of the file which path is to be determined
 */
function getFilePath(file) {
    return getFilePathPhy(file, DevInfo.phy);
}

/*!
 *  ======== getFilePathPhy ========
 *  Return the path of a file, restricted by PHY as filter
 *
 * @param file - name of the file which path is to be determined
 */
function getFilePathPhy(file, phy) {
    const fileList = DevConfig[phy].concat(DevConfig.default);

    // Get the file-object in the file list
    const correctFile = _.find(fileList, ["file", file]);

    if (_.isUndefined(correctFile)) {
        throw Error("No PHY path for " + phy + "/" + file);
    }

    return ConfigPath + correctFile.path + "/";
}

/*!
*  ======== addPhyGroup ========
*  Initialize the database for the specified PHY group
*
*  @param phy - PHY group short name (prop, ble, or ieee_15_4)
*/
function addPhyGroup(phy) {
    const phyPath = getFilePathPhy("rf_command_definitions.json", phy);
    const phyDir = phyPath.slice(0, -1);
    const paramPath = getFilePathPhy("param_definition.json", phy);

    const phyInfo = {
        phy: phy,
        phyPath: phyPath,
        phyDir: phyDir,
        paramPath: paramPath
    };
    DevInfo.phyGroup[phy] = phyInfo;
    DevInfo.phy = phy;
}
