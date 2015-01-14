/*
 * Copyright 2012 Red Hat Inc.
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
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: Ben Skeggs
 */

#include <subdev/bios.h>
#include <subdev/bus.h>
#include <subdev/gpio.h>
#include <subdev/i2c.h>
#include <subdev/fuse.h>
#include <subdev/clk.h>
#include <subdev/therm.h>
#include <subdev/mxm.h>
#include <subdev/devinit.h>
#include <subdev/mc.h>
#include <subdev/timer.h>
#include <subdev/fb.h>
#include <subdev/ltc.h>
#include <subdev/ibus.h>
#include <subdev/instmem.h>
#include <subdev/mmu.h>
#include <subdev/bar.h>
#include <subdev/pmu.h>
#include <subdev/volt.h>

#include <engine/device.h>
#include <engine/dmaobj.h>
#include <engine/fifo.h>
#include <engine/software.h>
#include <engine/gr.h>
#include <engine/disp.h>
#include <engine/ce.h>
#include <engine/bsp.h>
#include <engine/msvld.h>
#include <engine/vp.h>
#include <engine/msppp.h>
#include <engine/pm.h>

int
nve0_identify(struct nouveau_device *device)
{
	switch (device->chipset) {
	case 0xe4:
		device->cname = "GK104";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nve0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nvc3_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  gk104_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nve0_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  nve4_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nve0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] = &nve0_pm_oclass;
		break;
	case 0xe7:
		device->cname = "GK107";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nve0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nvc3_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  nvd0_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nve0_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  nve4_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nve0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] = &nve0_pm_oclass;
		break;
	case 0xe6:
		device->cname = "GK106";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nve0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nvc3_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  gk104_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nve0_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  nve4_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nve0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] = &nve0_pm_oclass;
		break;
	case 0xea:
		device->cname = "GK20A";
		device->oclass[NVDEV_SUBDEV_CLK    ] = &gk20a_clk_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &gk20a_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  gk20a_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &gk20a_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] = nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &gk20a_bar_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  gk20a_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  gk20a_gr_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] = &nve0_pm_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &gk20a_volt_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  gk20a_pmu_oclass;
		break;
	case 0xf0:
		device->cname = "GK110";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nve0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nvc3_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  nvd0_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nve0_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  nvf0_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nvf0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] = &nvf0_pm_oclass;
		break;
	case 0xf1:
		device->cname = "GK110B";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nvd0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  nvc3_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  nvd0_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nve0_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  gk110b_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nvf0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		device->oclass[NVDEV_ENGINE_PM     ] = &nvf0_pm_oclass;
		break;
	case 0x106:
		device->cname = "GK208B";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nve0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  nv108_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv108_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  nv108_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nvf0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		break;
	case 0x108:
		device->cname = "GK208";
		device->oclass[NVDEV_SUBDEV_VBIOS  ] = &nouveau_bios_oclass;
		device->oclass[NVDEV_SUBDEV_GPIO   ] =  nve0_gpio_oclass;
		device->oclass[NVDEV_SUBDEV_I2C    ] =  nve0_i2c_oclass;
		device->oclass[NVDEV_SUBDEV_FUSE   ] = &gf100_fuse_oclass;
		device->oclass[NVDEV_SUBDEV_CLK    ] = &nve0_clk_oclass;
		device->oclass[NVDEV_SUBDEV_THERM  ] = &nvd0_therm_oclass;
		device->oclass[NVDEV_SUBDEV_MXM    ] = &nv50_mxm_oclass;
		device->oclass[NVDEV_SUBDEV_DEVINIT] =  nvc0_devinit_oclass;
		device->oclass[NVDEV_SUBDEV_MC     ] =  gk20a_mc_oclass;
		device->oclass[NVDEV_SUBDEV_BUS    ] =  nvc0_bus_oclass;
		device->oclass[NVDEV_SUBDEV_TIMER  ] = &nv04_timer_oclass;
		device->oclass[NVDEV_SUBDEV_FB     ] =  nve0_fb_oclass;
		device->oclass[NVDEV_SUBDEV_LTC    ] =  gk104_ltc_oclass;
		device->oclass[NVDEV_SUBDEV_IBUS   ] = &nve0_ibus_oclass;
		device->oclass[NVDEV_SUBDEV_INSTMEM] =  nv50_instmem_oclass;
		device->oclass[NVDEV_SUBDEV_MMU    ] = &nvc0_mmu_oclass;
		device->oclass[NVDEV_SUBDEV_BAR    ] = &nvc0_bar_oclass;
		device->oclass[NVDEV_SUBDEV_PMU    ] =  nv108_pmu_oclass;
		device->oclass[NVDEV_SUBDEV_VOLT   ] = &nv40_volt_oclass;
		device->oclass[NVDEV_ENGINE_DMAOBJ ] =  nvd0_dmaeng_oclass;
		device->oclass[NVDEV_ENGINE_FIFO   ] =  nv108_fifo_oclass;
		device->oclass[NVDEV_ENGINE_SW     ] =  nvc0_software_oclass;
		device->oclass[NVDEV_ENGINE_GR     ] =  nv108_gr_oclass;
		device->oclass[NVDEV_ENGINE_DISP   ] =  nvf0_disp_oclass;
		device->oclass[NVDEV_ENGINE_CE0    ] = &nve0_ce0_oclass;
		device->oclass[NVDEV_ENGINE_CE1    ] = &nve0_ce1_oclass;
		device->oclass[NVDEV_ENGINE_CE2    ] = &nve0_ce2_oclass;
		device->oclass[NVDEV_ENGINE_MSVLD  ] = &nve0_msvld_oclass;
		device->oclass[NVDEV_ENGINE_VP     ] = &nve0_vp_oclass;
		device->oclass[NVDEV_ENGINE_MSPPP  ] = &nvc0_msppp_oclass;
		break;
	default:
		nv_fatal(device, "unknown Kepler chipset\n");
		return -EINVAL;
	}

	return 0;
}