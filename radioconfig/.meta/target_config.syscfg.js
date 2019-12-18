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
 *  ======== target_config.syscfg.js ========
 */

"use strict";

// Common utility functions
const Common = system.getScript("/ti/devices/radioconfig/radioconfig_common.js");

// Target handler
const TargetHandler = Common.getScript("target_handler.js");

let TargetMap = null;
let TargetName = null;

/*
 *  ======== init ========
 *  Initialize the module
 *
 *  @param phyGroup  - "prop", "ble" or "ieee_15_4"
 */
function init(phyGroup) {
    TargetHandler.init(phyGroup, "868");
    // Get list of targets
    TargetMap = _.map(TargetHandler.getTargetList(), tgt => ({name: tgt}));

    _.forEach(TargetMap, (tgt) => {
        tgt.displayName = tgt.name;
        if (tgt.name === "LAUNCHXL-CC1352P1") tgt.displayName += " (779 - 930 MHz)";
        if (tgt.name === "LAUNCHXL-CC1352P-2") tgt.displayName += " (2400 - 2480 MHz)";
        if (tgt.name === "LAUNCHXL-CC1352P-4") tgt.displayName += " (431 - 527 MHz)";
    });

    // Determine target name. If the board is globally defined,
    // use this as default and make board selection read only.
    TargetName = getBoardName();
    if (TargetName === null) {
        TargetName = TargetMap[0].name;
    }
}


/*
 *  ======== reset ========
 *  Update the configurables when the target selection changes
 *
 *  @param inst  - Module instance containing the config that changed
 */
function reset(inst) {
    const phyGroup = Common.getPhyGroup(inst);
    TargetHandler.init(phyGroup);
}

/*!
 *  ======== getBoardName ========
 *  Get the name of the board
 *
 *  @returns String - Name of the board with prefix /ti/boards and
 *                    suffix .syscfg.json stripped off.  If no board
 *                    was specified, null is returned.
 */
function getBoardName() {
    let boardName = null;

    if (system.deviceData.board != null) {
        boardName = system.deviceData.board.source;

        // Strip off everything up to and including the last '/'
        boardName = boardName.replace(/.*\//, "");

        // Strip off everything after and including the first '.'
        boardName = boardName.replace(/\..*/, "");

        // Convert board name to SmartRF Studio notation
        if (boardName.includes("_LAUNCHXL")) {
            boardName = "LAUNCHXL-" + boardName.replace("_LAUNCHXL", "");
            boardName = boardName.replace("_", "-");
        }
        else {
            throw new Error("Unknown board [" + boardName + "]");
        }
    }
    return boardName;
}

/*!
 *  ======== getOptimalHiPa ========
 *  Get the optimal PA-setting based on frequency and Launchpad variant.
 *
 *  @param - boardName - name of target board
 *  @param - freqBand - 433, 490, 868 or 2400
 */
function getOptimalHiPa(boardName, freqBand) {
    let hiPa;

    switch (boardName) {
    case "LAUNCHXL-CC1352P1":
        hiPa = freqBand === "868";
        break;
    case "LAUNCHXL-CC1352P-2":
        hiPa = freqBand === "2400";
        break;
    case "LAUNCHXL-CC1352P-4":
        hiPa = freqBand === "490";
        break;
    default:
        hiPa = false;
    }
    return hiPa;
}

/*
 *  ======== TargetConfigModule ========
 *  Define the Target Configuration module properties and methods
 */
const TargetConfigModule = {
    displayName: "Target Configuration",
    description: "Target Configuration for CC1352P",
    longDescription: "The Target Configuration is used to select target board for RF devices",
    init: init,
    reset: reset,
    getOptimalHiPa: getOptimalHiPa,
    getBoardName: getBoardName,
    getTargetName: function() {
        return TargetName;
    },
    getTargetMap: function() {
        return TargetMap;
    }
};

/*
 *  ======== exports ========
 *  Export the Target Configuration module
 */
exports = TargetConfigModule;
