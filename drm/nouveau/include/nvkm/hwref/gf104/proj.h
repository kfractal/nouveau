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
#ifndef __hwref_gf104_proj_h__
#define __hwref_gf104_proj_h__

#define NV_GPC_PRI_BASE                                   0x500000
#define NV_GPC_PRI_SHARED_BASE                            0x418000
#define NV_GPC_PRI_STRIDE                                   0x8000
#define NV_LTC_PRI_STRIDE                                   0x2000
#define NV_LTS_PRI_STRIDE                                    0x400
#define NV_HOST_NUM_PBDMA                                        3
#define NV_SCAL_FAMILY_MAX_GPCS                                 32
#define NV_SCAL_FAMILY_MAX_TPC_PER_GPC                           8
#define NV_SCAL_LITTER_NUM_FBPS                                  6
#define NV_SCAL_LITTER_NUM_GPCS                                  4
#define NV_SCAL_LITTER_NUM_TPC_PER_GPC                           4
#define NV_SCAL_LITTER_NUM_ZCULL_BANKS                           4
#define NV_ROP_PRI_BASE                                   0x410000
#define NV_ROP_PRI_SHARED_BASE                            0x408800
#define NV_ROP_PRI_STRIDE                                    0x400
#define NV_TPC_IN_GPC_BASE                                  0x4000
#define NV_TPC_IN_GPC_SHARED_BASE                           0x1800
#define NV_TPC_IN_GPC_STRIDE                                 0x800

#endif /* __hwref_gf104_proj_h__ */
