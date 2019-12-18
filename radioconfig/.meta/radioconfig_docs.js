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
 * ======== radioconfig_docs.js ========
 * Documentation for the RadioConfig module
 */

"use strict";

/* eslint-disable max-len */

const customLongDescription = `
The [__Custom RF module__][1] allows the user full flexibility 
in choosing what PHY settings to include in the application. It is possible 
to combine settings from all PHY groups (BLE, IEEE 802.15.4 and Proprietary). The module 
provides a set of typical (PHY) settings that are identical to SmartRF Studio, and also 
offers a proprietary custom setting for each of the frequency bands (433 MHz, 868 MHz, 2.4 GHz).

* [Usage Synopsis][2]
* [Examples][3]

[1]: /proprietary-rf/proprietary-rf-users-guide/sysconfig/proprietary-rf-driver.html "SysConfig Radio Configuration"
[2]: /proprietary-rf/proprietary-rf-users-guide/sysconfig/proprietary-rf-driver.html#adding-rf-settings "Adding RF Settings"
[3]: /proprietary-rf/proprietary-rf-users-guide/proprietary-rf-guide/examples-cc13x2_26x2.html#rf-driver-examples "Radio Configuration Examples"
`;

exports = {
    customLongDescription: customLongDescription
};
