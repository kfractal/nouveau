/*
 * Copyright (c) 2015, NVIDIA CORPORATION. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef __hwref_gf100_therm_h__
#define __hwref_gf100_therm_h__

#define NV_THERM_WEIGHT_1                                  0x20024
#define NV_THERM_CONFIG1                                   0x20050
#define NV_THERM_CLK_SLOWDOWN_0(i)               (0x20160+((i)*4))
#define NV_THERM_CLK_SLOWDOWN_0_IDLE_FACTOR                  21:16
#define NV_THERM_GATE_CTRL(i)                    (0x20200+((i)*4))
#define NV_THERM_GATE_CTRL_ENG_CLK                             1:0
#define NV_THERM_GATE_CTRL_ENG_CLK_RUN                           0
#define NV_THERM_GATE_CTRL_ENG_CLK_AUTO                          1
#define NV_THERM_GATE_CTRL_ENG_CLK_STOP                          2
#define NV_THERM_GATE_CTRL_BLK_CLK                             3:2
#define NV_THERM_GATE_CTRL_BLK_CLK_RUN                           0
#define NV_THERM_GATE_CTRL_BLK_CLK_AUTO                          1
#define NV_THERM_GATE_CTRL_ENG_PWR                             5:4
#define NV_THERM_GATE_CTRL_ENG_PWR_AUTO                          1
#define NV_THERM_GATE_CTRL_ENG_PWR_OFF                           2
#define NV_THERM_GATE_CTRL_ENG_IDLE_FILT_EXP                  12:8
#define NV_THERM_GATE_CTRL_ENG_IDLE_FILT_MANT                15:13
#define NV_THERM_GATE_CTRL_ENG_DELAY_AFTER                   23:20
#define NV_THERM_FECS_IDLE_FILTER                          0x20288
#define NV_THERM_FECS_IDLE_FILTER_VALUE                       31:0
#define NV_THERM_HUBMMU_IDLE_FILTER                        0x2028c
#define NV_THERM_HUBMMU_IDLE_FILTER_VALUE                     31:0

#endif /* __hwref_gf100_therm_h__ */
