#ifndef __EXYNOS7570_CMU_H__
#define __EXYNOS7570_CMU_H__

#include "../pwrcal-clk.h"

enum clk_id {
	OSCCLK = fixed_rate_type,
	OSCCLK_FM_52M,
	CLK_MIF_DDRPHY0,
	TCXO, /*52MHZ*/
	WIFI2AP_USBPLL_CLK,
	CLKPHY_FSYS_USB20DRD_PHYCLOCK,
	CLKPHY_DISPAUD_MIPIPHY_TXBYTECLKHS,
	CLKPHY_DISPAUD_MIPIPHY_RXCLKESC0,
	CLKIO_DISPAUD_MIXER_BCLK_CP,
	CLKPHY_ISP_S_RXBYTECLKHS0_S4,
	NUM_OF_FIXED_RATE_TYPE = CLKPHY_ISP_S_RXBYTECLKHS0_S4 - fixed_rate_type + 1,

	MIF_FF_SHARED0_PLL_DIV2 = fixed_factor_type,
	MIF_FF_SHARED1_PLL_DIV2,
	MIF_FF_SHARED2_PLL_DIV2,
	NUM_OF_FIXED_FACTOR_TYPE = MIF_FF_SHARED2_PLL_DIV2 - fixed_factor_type + 1,

	CPUCL0_PLL = pll_type,
	SHARED0_PLL,
	SHARED1_PLL,
	SHARED2_PLL,
	AUD_PLL,
	WPLL_USB_PLL,
	NUM_OF_PLL_TYPE = WPLL_USB_PLL - pll_type + 1,

	CPUCL0_MUX_CPUCL0_PLL = mux_type,
	CPUCL0_MUX_CLK_CPUCL0,
	DISPAUD_MUX_AUD_PLL,
	MIF_MUX_SHARED0_PLL,
	MIF_MUX_SHARED1_PLL,
	MIF_MUX_SHARED2_PLL,
	MIF_MUX_CLK_MIF_PHY_CLK,
	MIF_MUX_CLK_MIF_PHY_CLK_A,
	MIF_MUX_CLK_MIF_PHY_CLK_B,
	MIF_MUX_CLK_MIF_BUSD,
	MIF_MUX_CLKCMU_G3D,
	MIF_MUX_CLKCMU_ISP_VRA,
	MIF_MUX_CLKCMU_ISP_CAM,
	MIF_MUX_CLKCMU_DISPAUD_BUS,
	MIF_MUX_CLKCMU_DISPAUD_DECON_INT_VCLK,
	MIF_MUX_CLKCMU_MFCMSCL_MSCL,
	MIF_MUX_CLKCMU_MFCMSCL_MFC,
	MIF_MUX_CLKCMU_FSYS_BUS,
	MIF_MUX_CLKCMU_FSYS_MMC0,
	MIF_MUX_CLKCMU_FSYS_MMC2,
	MIF_MUX_CLKCMU_FSYS_USB20DRD_REFCLK,
	MIF_MUX_CLKCMU_PERI_BUS,
	MIF_MUX_CLKCMU_PERI_UART_DEBUG,
	MIF_MUX_CLKCMU_PERI_UART_SENSOR,
	MIF_MUX_CLKCMU_PERI_SPI_REARFROM,
	MIF_MUX_CLKCMU_PERI_SPI_ESE,
	MIF_MUX_CLKCMU_PERI_USI_0,
	MIF_MUX_CLKCMU_PERI_USI_1,
	MIF_MUX_CLKCMU_APM,
	MIF_MUX_CLKCMU_ISP_SENSOR0,

	/* user_mux_type */
	APM_MUX_CLKCMU_APM_USER  = MIF_MUX_CLKCMU_ISP_SENSOR0 + 0x1001,
	CPUCL0_MUX_CLKCMU_CPUCL0_SWITCH_USER,
	DISPAUD_MUX_CLKCMU_DISPAUD_BUS_USER,
	DISPAUD_MUX_CLKCMU_DISPAUD_DECON_INT_VCLK_USER,
	DISPAUD_MUX_CLKCMU_DISPAUD_DECON_INT_ECLK_USER,
	DISPAUD_MUX_CLKPHY_DISPAUD_MIPIPHY_TXBYTECLKHS_USER,
	DISPAUD_MUX_CLKPHY_DISPAUD_MIPIPHY_RXCLKESC0_USER,
	FSYS_MUX_CLKPHY_FSYS_USB20DRD_PHYCLOCK_USER,
	G3D_MUX_CLKCMU_G3D_USER,
	ISP_MUX_CLKCMU_ISP_VRA_USER,
	ISP_MUX_CLKCMU_ISP_CAM_USER,
	ISP_MUX_CLKPHY_ISP_S_RXBYTECLKHS0_S4_USER,
	MFCMSCL_MUX_CLKCMU_MFCMSCL_MSCL_USER,
	MFCMSCL_MUX_CLKCMU_MFCMSCL_MFC_USER,
	NUM_OF_MUX_TYPE = MFCMSCL_MUX_CLKCMU_MFCMSCL_MFC_USER - 0x1000 - mux_type + 1,

	CPUCL0_DIV_CLK_CPUCL0_1 = div_type,
	CPUCL0_DIV_CLK_CPUCL0_2,
	CPUCL0_DIV_CLK_CPUCL0_ACLK,
	CPUCL0_DIV_CLK_CPUCL0_PCLK,
	CPUCL0_DIV_CLK_CPUCL0_ATCLK,
	CPUCL0_DIV_CLK_CPUCL0_PCLKDBG,
	CPUCL0_DIV_CLK_CPUCL0_CNTCLK,
	CPUCL0_DIV_CLK_CPUCL0_RUN_MONITOR,
	CPUCL0_DIV_CLK_CPUCL0_HPM,
	CPUCL0_DIV_CLK_CPUCL0_PLL,
	DISPAUD_DIV_CLK_DISPAUD_APB,
	DISPAUD_DIV_CLK_DISPAUD_DECON_INT_VCLK,
	DISPAUD_DIV_CLK_DISPAUD_DECON_INT_ECLK,
	DISPAUD_DIV_CLK_DISPAUD_MI2S,
	DISPAUD_DIV_CLK_DISPAUD_MIXER,
	DISPAUD_DIV_CLK_DISPAUD_OSCCLK_FM_52M_DIV,
	G3D_DIV_CLK_G3D_BUS,
	G3D_DIV_CLK_G3D_APB,
	ISP_DIV_CLK_ISP_CAM_HALF,
	MFCMSCL_DIV_CLK_MFCMSCL_APB,
	MIF_DIV_CLK_MIF_PHY_CLK2X,
	MIF_DIV_CLK_MIF_PHY_CLKM,
	MIF_DIV_CLKCMU_CP_SHARED0_PLL,
	MIF_DIV_CLKCMU_CP_SHARED1_PLL,
	MIF_DIV_CLKCMU_CP_SHARED2_PLL,
	MIF_DIV_CLK_MIF_BUSD,
	MIF_DIV_CLK_MIF_APB,
	MIF_DIV_CLKCMU_CPUCL0_SWITCH,
	MIF_DIV_CLKCMU_G3D,
	MIF_DIV_CLKCMU_ISP_VRA,
	MIF_DIV_CLKCMU_ISP_CAM,
	MIF_DIV_CLKCMU_DISPAUD_BUS,
	MIF_DIV_CLKCMU_DISPAUD_DECON_INT_VCLK,
	MIF_DIV_CLKCMU_MFCMSCL_MSCL,
	MIF_DIV_CLKCMU_MFCMSCL_MFC,
	MIF_DIV_CLKCMU_FSYS_BUS,
	MIF_DIV_CLKCMU_FSYS_MMC0,
	MIF_DIV_CLKCMU_FSYS_MMC2,
	MIF_DIV_CLKCMU_FSYS_USB20DRD_REFCLK,
	MIF_DIV_CLKCMU_PERI_BUS,
	MIF_DIV_CLKCMU_PERI_UART_DEBUG,
	MIF_DIV_CLKCMU_PERI_UART_SENSOR,
	MIF_DIV_CLKCMU_PERI_SPI_REARFROM,
	MIF_DIV_CLKCMU_PERI_SPI_ESE,
	MIF_DIV_CLKCMU_PERI_USI_0,
	MIF_DIV_CLKCMU_PERI_USI_1,
	MIF_DIV_CLKCMU_APM,
	MIF_DIV_CLKCMU_ISP_SENSOR0,
	MIF_DIV_CLKCMU_GNSS_EXTPLL_SCAN,
	PERI_DIV_CLK_PERI_USI_0_SPI,
	PERI_DIV_CLK_PERI_USI_1_SPI,
	NUM_OF_DIV_TYPE = PERI_DIV_CLK_PERI_USI_1_SPI - div_type + 1,

	APM_GATE_CLK_APM_UID_APM_IPCLKPORT_ACLK_SYS = gate_type,
	APM_GATE_CLK_APM_UID_APM_IPCLKPORT_ACLK_CPU,
	APM_GATE_CLK_APM_UID_ASYNCS_APM_IPCLKPORT_I_CLK,
	APM_GATE_CLK_APM_UID_ASYNCM_APM_IPCLKPORT_I_CLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_SYSREG_CPUCL0_IPCLKPORT_CLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_PMU_CPUCL0_IPCLKPORT_I_CLK__PMU_CPUCL0,
	CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCS_D_CPUCL0_IPCLKPORT_I_CLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_SYSREG_CPUCL0_IPCLKPORT_PCLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_HPM_CPUCL0_IPCLKPORT_PCLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_PMU_CPUCL0_IPCLKPORT_I_PCLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_DUMP_PC_CPUCL0_IPCLKPORT_I_PCLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_BUSP1_CPUCL0_IPCLKPORT_ACLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCM_P_CPUCL0_IPCLKPORT_I_CLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_CSSYS_DBG_IPCLKPORT_ATCLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_SECJTAG_IPCLKPORT_i_clk,
	CPUCL0_GATE_CLK_CPUCL0_UID_DUMP_PC_CPUCL0_IPCLKPORT_I_PCLKDBG,
	CPUCL0_GATE_CLK_CPUCL0_UID_DBG_MUX_CPUCL0_IPCLKPORT_I_CLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_CSSYS_DBG_IPCLKPORT_PCLKDBG,
	CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCS_CSSYS_DBG_IPCLKPORT_PCLKS,
	CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCS_T_CSSYS_DBG_IPCLKPORT_ACLK,
	CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCM_P_CSSYS_DBG_IPCLKPORT_PCLKM,
	CPUCL0_GATE_CLK_CPUCL0_UID_HPM_CPUCL0_IPCLKPORT_I_HPM_TARGETCLK_C,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_OSCCLK,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS_PPMU,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS_DISP,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS_VPP,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_FM,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_AUD_AMP,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_AUD,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_DISP,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_APB_SECURE_SMMU_DISP,
	DISPAUD_GATE_CLK_DISPAUD_UID_DECON_IPCLKPORT_I_VCLK,
	DISPAUD_GATE_CLK_DISPAUD_UID_DSIM0_IPCLKPORT_I_TXBYTECLKHS,
	DISPAUD_GATE_CLK_DISPAUD_UID_DSIM0_IPCLKPORT_I_RXCLKESC0,
	DISPAUD_GATE_CLK_DISPAUD_UID_MI2S_AMP_IPCLKPORT_I2SCODCLKI,
	DISPAUD_GATE_CLK_DISPAUD_UID_MI2S_AUD_IPCLKPORT_I2SCODCLKI,
	DISPAUD_GATE_CLK_DISPAUD_UID_MIXER_AUD_IPCLKPORT_SYSCLK,
	DISPAUD_GATE_CLK_DISPAUD_UID_CON_DISPAUD_IPCLKPORT_I_CP2AUD_BCK,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_OSCCLK_FM_52M,
	DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_OSCCLK_FM_52M_DIV,
	FSYS_GATE_CLK_FSYS_UID_SYSREG_FSYS_IPCLKPORT_CLK,
	FSYS_GATE_CLK_FSYS_UID_PMU_FSYS_IPCLKPORT_I_CLK__PMU_FSYS,
	FSYS_GATE_CLK_FSYS_UID_BUSD1_FSYS_IPCLKPORT_ACLK,
	FSYS_GATE_CLK_FSYS_UID_BUSD0_FSYS_IPCLKPORT_ACLK,
	FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_HCLK_USB20_CTRL,
	FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_ACLK_HSDRD,
	FSYS_GATE_CLK_FSYS_UID_SYSREG_FSYS_IPCLKPORT_PCLK,
	FSYS_GATE_CLK_FSYS_UID_PPMU_FSYS_IPCLKPORT_PCLK,
	FSYS_GATE_CLK_FSYS_UID_PPMU_FSYS_IPCLKPORT_ACLK,
	FSYS_GATE_CLK_FSYS_UID_PMU_FSYS_IPCLKPORT_I_PCLK,
	FSYS_GATE_CLK_FSYS_UID_ASYNCS_D_FSYS_IPCLKPORT_I_CLK,
	FSYS_GATE_CLK_FSYS_UID_ASYNCM_P_FSYS_IPCLKPORT_I_CLK,
	FSYS_GATE_CLK_FSYS_UID_GPIO_FSYS_IPCLKPORT_PCLK,
	FSYS_GATE_CLK_FSYS_UID_MMC_CARD_IPCLKPORT_I_ACLK,
	FSYS_GATE_CLK_FSYS_UID_MMC_EMBD_IPCLKPORT_I_ACLK,
	FSYS_GATE_CLK_FSYS_UID_BR_BUSP1_FSYS_IPCLKPORT_aclk,
	FSYS_GATE_CLK_FSYS_UID_BUSP5_FSYS_IPCLKPORT_HCLK,
	FSYS_GATE_CLK_FSYS_UID_BUSP3_FSYS_IPCLKPORT_HCLK,
	FSYS_GATE_CLK_FSYS_UID_BUSP2_FSYS_IPCLKPORT_HCLK,
	FSYS_GATE_CLK_FSYS_UID_BUSP1_FSYS_IPCLKPORT_HCLK,
	FSYS_GATE_CLK_FSYS_UID_RTIC_IPCLKPORT_i_PCLK,
	FSYS_GATE_CLK_FSYS_UID_RTIC_IPCLKPORT_i_ACLK,
	FSYS_GATE_CLK_FSYS_UID_SSS_IPCLKPORT_i_PCLK,
	FSYS_GATE_CLK_FSYS_UID_SSS_IPCLKPORT_i_ACLK,
	FSYS_GATE_CLK_FSYS_UID_MMC_EMBD_IPCLKPORT_SDCLKIN,
	FSYS_GATE_CLK_FSYS_UID_MMC_CARD_IPCLKPORT_SDCLKIN,
	FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_HSDRD_ref_clk,
	FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_HSDRD_PHYCLOCK,
	FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_USB20_CLKCORE_0,
	G3D_GATE_CLK_G3D_UID_SYSREG_G3D_IPCLKPORT_CLK,
	G3D_GATE_CLK_G3D_UID_PMU_G3D_IPCLKPORT_I_CLK__PMU_G3D,
	G3D_GATE_CLK_G3D_UID_QE_G3D_IPCLKPORT_ACLK,
	G3D_GATE_CLK_G3D_UID_PPMU_G3D_IPCLKPORT_ACLK,
	G3D_GATE_CLK_G3D_UID_G3D_IPCLKPORT_CLK,
	G3D_GATE_CLK_G3D_UID_REGSLICE_D1_G3D_IPCLKPORT_aclk,
	G3D_GATE_CLK_G3D_UID_REGSLICE_D0_G3D_IPCLKPORT_aclk,
	G3D_GATE_CLK_G3D_UID_IXIU_D_G3D_IPCLKPORT_ACLK,
	G3D_GATE_CLK_G3D_UID_ASYNCS_D1_G3D_IPCLKPORT_I_CLK,
	G3D_GATE_CLK_G3D_UID_ASYNCS_D0_G3D_IPCLKPORT_I_CLK,
	G3D_GATE_CLK_G3D_UID_ASYNC_G3D_P_IPCLKPORT_PCLKM,
	G3D_GATE_CLK_G3D_UID_SYSREG_G3D_IPCLKPORT_PCLK,
	G3D_GATE_CLK_G3D_UID_QE_G3D_IPCLKPORT_PCLK,
	G3D_GATE_CLK_G3D_UID_PPMU_G3D_IPCLKPORT_PCLK,
	G3D_GATE_CLK_G3D_UID_PMU_G3D_IPCLKPORT_I_PCLK,
	G3D_GATE_CLK_G3D_UID_BUSP_G3D_IPCLKPORT_ACLK,
	G3D_GATE_CLK_G3D_UID_ASYNCM_P_G3D_IPCLKPORT_I_CLK,
	G3D_GATE_CLK_G3D_UID_ASYNC_G3D_P_IPCLKPORT_PCLKS,
	G3D_GATE_CLK_G3D_UID_CFW_G3D_IPCLKPORT_ACLK,
	G3D_GATE_CLK_G3D_UID_CFW_G3D_IPCLKPORT_PCLK,
	ISP_GATE_CLK_ISP_UID_CLK_ISP_OSCCLK,
	ISP_GATE_CLK_ISP_UID_CLK_ISP_VRA,
	ISP_GATE_CLK_ISP_UID_CLK_ISP_CAM,
	ISP_GATE_CLK_ISP_UID_CLKPHY_ISP_S_RXBYTECLKHS0_S4,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLK_MFCMSCL_OSCCLK,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MSCL_BI,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_D,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_JPEG,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_POLY,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_MFC,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLK_MFCMSCL_APB,
	MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_APB_SMMU_MSCL,
	MIF_GATE_CLK_MIF_UID_OTP_DESERIAL_MIF_IPCLKPORT_I_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_RCLK,
	MIF_GATE_CLK_MIF_UID_WRAP_ADC_IF_IPCLKPORT_I_OSC_SYS,
	MIF_GATE_CLK_MIF_UID_SYSREG_MIF_IPCLKPORT_CLK,
	MIF_GATE_CLK_MIF_UID_PMU_MIF_IPCLKPORT_I_CLK__PMU_MIF_JV,
	MIF_GATE_CLK_MIF_UID_DDR_PHY0_IPCLKPORT_clk,
	MIF_GATE_CLK_MIF_UID_DDR_PHY0_IPCLKPORT_clkm,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_APB_ACLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SECURE_APB_ACLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PEREV_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_MEMIF_WR_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_MEMIF_RD_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_MEMIF_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SCH_SLICE1_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SCH_SLICE0_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SCH_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_VCF_WR_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_VCF_RD_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_VCF_CLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_PPMU_CPU_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_QE_DMC0_CPU_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_ASYNCM_CPUCL0_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_ASYNCM_DBG_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_PDMA_MIF_IPCLKPORT_ACLK_PDMA0,
	MIF_GATE_CLK_MIF_UID_CLEANY_WLBT_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_CLEANY_GNSS_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_CLEANY_CEL_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_CPU0_MO_MON_IPCLKPORT_I_ACLK,
	MIF_GATE_CLK_MIF_UID_PPMU_CPU_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_SPEEDY_BATCHER_WRAPPER_IPCLKPORT_PCLK_BATCHER_SPEEDY,
	MIF_GATE_CLK_MIF_UID_SPEEDY_BATCHER_WRAPPER_IPCLKPORT_PCLK_BATCHER_CP,
	MIF_GATE_CLK_MIF_UID_SPEEDY_BATCHER_WRAPPER_IPCLKPORT_PCLK_BATCHER_AP,
	MIF_GATE_CLK_MIF_UID_SPEEDY_MIF_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_MAILBOX_WLBT_IPCLKPORT_CLK,
	MIF_GATE_CLK_MIF_UID_MAILBOX_GNSS_IPCLKPORT_CLK,
	MIF_GATE_CLK_MIF_UID_MAILBOX_CEL_IPCLKPORT_CLK,
	MIF_GATE_CLK_MIF_UID_ASYNCAPB_MIF_CSSYS_IPCLKPORT_PCLKS,
	MIF_GATE_CLK_MIF_UID_SYNC_INTC_SOC_IPCLKPORT_CLK,
	MIF_GATE_CLK_MIF_UID_INTC_SOC_IPCLKPORT_CLK,
	MIF_GATE_CLK_MIF_UID_AXI2APB_MIF_TREX_IPCLKPORT_ACLK,
	MIF_GATE_CLK_MIF_UID_AXI2AHB_MIF_P_IPCLKPORT_HCLK,
	MIF_GATE_CLK_MIF_UID_AHB2APB_MIF2_IPCLKPORT_HCLK,
	MIF_GATE_CLK_MIF_UID_AHB2APB_MIF1_IPCLKPORT_HCLK,
	MIF_GATE_CLK_MIF_UID_AHB2APB_MIF0_IPCLKPORT_HCLK,
	MIF_GATE_CLK_MIF_UID_AHB_BRIDGE_MIF_IPCLKPORT_HCLK,
	MIF_GATE_CLK_MIF_UID_QE_DMC0_CPU_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_DDRDMC0_APB_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK_PF,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_DDR_PHY0_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_WRAP_ADC_IF_IPCLKPORT_PCLK_S1,
	MIF_GATE_CLK_MIF_UID_WRAP_ADC_IF_IPCLKPORT_PCLK_S0,
	MIF_GATE_CLK_MIF_UID_GPIO_MIF_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_SYSREG_MIF_IPCLKPORT_PCLK,
	MIF_GATE_CLK_MIF_UID_PMU_MIF_IPCLKPORT_I_PCLK,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK_PF_SECURE,
	MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK_SECURE,
	MIF_GATE_CLK_MIF_UID_MAILBOX_SECURE_IPCLKPORT_CLK,
	MIF_GATE_CLKCMU_CP_SHARED0_PLL,
	MIF_GATE_CLKCMU_CP_SHARED1_PLL,
	MIF_GATE_CLKCMU_CP_SHARED2_PLL,
	MIF_GATE_CLKCMU_CPUCL0_SWITCH,
	MIF_GATE_CLKCMU_G3D,
	MIF_GATE_CLKCMU_ISP_VRA,
	MIF_GATE_CLKCMU_ISP_CAM,
	MIF_GATE_CLKCMU_DISPAUD_BUS,
	MIF_GATE_CLKCMU_DISPAUD_DECON_INT_VCLK,
	MIF_GATE_CLKCMU_MFCMSCL_MFC,
	MIF_GATE_CLKCMU_MFCMSCL_MSCL,
	MIF_GATE_CLKCMU_FSYS_BUS,
	MIF_GATE_CLKCMU_FSYS_MMC0,
	MIF_GATE_CLKCMU_FSYS_MMC2,
	MIF_GATE_CLKCMU_FSYS_USB20DRD_REFCLK,
	MIF_GATE_CLKCMU_PERI_BUS,
	MIF_GATE_CLKCMU_PERI_UART_DEBUG,
	MIF_GATE_CLKCMU_PERI_UART_SENSOR,
	MIF_GATE_CLKCMU_PERI_SPI_REARFROM,
	MIF_GATE_CLKCMU_PERI_SPI_ESE,
	MIF_GATE_CLKCMU_PERI_USI_0,
	MIF_GATE_CLKCMU_PERI_USI_1,
	MIF_GATE_CLKCMU_APM,
	MIF_GATE_CLKCMU_ISP_SENSOR0,
	MIF_GATE_CLKCMU_GNSS_TEST_EXTPLL_SCAN_CLK,
	MIF_GATE_CLK_MIF_UID_SPEEDY_MIF_IPCLKPORT_CLK,
	PERI_GATE_CLK_PERI_UID_TMU_CPUCL0_IPCLKPORT_I_CLK,
	PERI_GATE_CLK_PERI_UID_SYSREG_PERI_IPCLKPORT_CLK,
	PERI_GATE_CLK_PERI_UID_PWM_MOTOR_IPCLKPORT_i_OSCCLK,
	PERI_GATE_CLK_PERI_UID_PMU_PERI_IPCLKPORT_I_CLK__PMU_PERI,
	PERI_GATE_CLK_PERI_UID_CHIPID_IPCLKPORT_CLK,
	PERI_GATE_CLK_PERI_UID_PWM_MOTOR_IPCLKPORT_i_PCLK_S0,
	PERI_GATE_CLK_PERI_UID_PMU_PERI_IPCLKPORT_I_PCLK,
	PERI_GATE_CLK_PERI_UID_MCT_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_I2C_SENSOR2_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_I2C_SENSOR1_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_I2C_TSP_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_I2C_FUELGAUGE_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_I2C_NFC_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_I2C_MUIC_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_HSI2C_FRONTCAM_IPCLKPORT_iPCLK,
	PERI_GATE_CLK_PERI_UID_HSI2C_MAINCAM_IPCLKPORT_iPCLK,
	PERI_GATE_CLK_PERI_UID_HSI2C_FRONTSENSOR_IPCLKPORT_iPCLK,
	PERI_GATE_CLK_PERI_UID_HSI2C_REARAF_IPCLKPORT_iPCLK,
	PERI_GATE_CLK_PERI_UID_HSI2C_REARSENSOR_IPCLKPORT_iPCLK,
	PERI_GATE_CLK_PERI_UID_GPIO_TOUCH_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_GPIO_TOP_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_GPIO_NFC_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_GPIO_ESE_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_BUSP1_PERIS1_IPCLKPORT_HCLK,
	PERI_GATE_CLK_PERI_UID_BUSP1_PERIS0_IPCLKPORT_HCLK,
	PERI_GATE_CLK_PERI_UID_BUSP1_PERIC1_IPCLKPORT_HCLK,
	PERI_GATE_CLK_PERI_UID_BUSP1_PERIC0_IPCLKPORT_HCLK,
	PERI_GATE_CLK_PERI_UID_BUSP_BR_PERIC_IPCLKPORT_HCLK,
	PERI_GATE_CLK_PERI_UID_AXI2AHB_MSD32_PERI_IPCLKPORT_aclk,
	PERI_GATE_CLK_PERI_UID_ASYNCM_PERI_IPCLKPORT_I_CLK,
	PERI_GATE_CLK_PERI_UID_USI_1_IPCLKPORT_i_PCLK,
	PERI_GATE_CLK_PERI_UID_USI_0_IPCLKPORT_i_PCLK,
	PERI_GATE_CLK_PERI_UID_WDT_CPUCL0_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_UART_DEBUG_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_UART_SENSOR_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SYSREG_PERI_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SPI_ESE_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SPI_REARFROM_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SFRIF_TMU_CPUCL0_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SFRIF_GPIO_ALIVE_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC10_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC9_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC8_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC7_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC6_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC5_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC4_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC3_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC2_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC1_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_TZPC0_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SFRIF_CHIPID_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_OTP_CON_TOP_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SFRIF_RTC_ALIVE_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_SFRIF_RTC_TOP_IPCLKPORT_PCLK,
	PERI_GATE_CLK_PERI_UID_UART_DEBUG_IPCLKPORT_EXT_UCLK,
	PERI_GATE_CLK_PERI_UID_UART_SENSOR_IPCLKPORT_EXT_UCLK,
	PERI_GATE_CLK_PERI_UID_SPI_REARFROM_IPCLKPORT_SPI_EXT_CLK,
	PERI_GATE_CLK_PERI_UID_SPI_ESE_IPCLKPORT_SPI_EXT_CLK,
	PERI_GATE_CLK_PERI_UID_USI_0_IPCLKPORT_i_SCLK_UART,
	PERI_GATE_CLK_PERI_UID_USI_1_IPCLKPORT_i_SCLK_UART,
	PERI_GATE_CLK_PERI_UID_USI_0_IPCLKPORT_i_SCLK_SPI,
	PERI_GATE_CLK_PERI_UID_USI_1_IPCLKPORT_i_SCLK_SPI,
	MIF_MUXGATE_CLKCMU_ISP_VRA,
	MIF_MUXGATE_CLKCMU_ISP_CAM,
	MIF_MUXGATE_CLKCMU_DISPAUD_BUS,
	MIF_MUXGATE_CLKCMU_DISPAUD_DECON_INT_VCLK,
	MIF_MUXGATE_CLKCMU_MFCMSCL_MSCL,
	MIF_MUXGATE_CLKCMU_MFCMSCL_MFC,
	MIF_MUXGATE_CLKCMU_FSYS_BUS,
	MIF_MUXGATE_CLKCMU_FSYS_MMC0,
	MIF_MUXGATE_CLKCMU_FSYS_MMC2,
	MIF_MUXGATE_CLKCMU_FSYS_USB20DRD_REFCLK,
	MIF_MUXGATE_CLKCMU_PERI_BUS,
	MIF_MUXGATE_CLKCMU_PERI_UART_DEBUG,
	MIF_MUXGATE_CLKCMU_PERI_UART_SENSOR,
	MIF_MUXGATE_CLKCMU_PERI_SPI_REARFROM,
	MIF_MUXGATE_CLKCMU_PERI_SPI_ESE,
	MIF_MUXGATE_CLKCMU_PERI_USI_0,
	MIF_MUXGATE_CLKCMU_PERI_USI_1,
	MIF_MUXGATE_CLKCMU_APM,
	MIF_MUXGATE_CLKCMU_ISP_SENSOR0,
	PMU_DEBUG_CLKOUT_SEL08,
	PMU_DEBUG_CLKOUT_SEL09,
	PMU_DEBUG_CLKOUT_SEL10,
	PMU_DEBUG_CLKOUT_SEL11,
	PMU_DEBUG_CLKOUT_SEL12,
	PMU_DEBUG_CLKOUT_DISABLE,
	NUM_OF_GATE_TYPE = PMU_DEBUG_CLKOUT_DISABLE - gate_type + 1,

};

FIXEDRATE_EXTERN(OSCCLK)
FIXEDRATE_EXTERN(OSCCLK_FM_52M)
FIXEDRATE_EXTERN(CLK_MIF_DDRPHY0)
FIXEDRATE_EXTERN(TCXO)
FIXEDRATE_EXTERN(WIFI2AP_USBPLL_CLK)
FIXEDRATE_EXTERN(CLKPHY_FSYS_USB20DRD_PHYCLOCK)
FIXEDRATE_EXTERN(CLKPHY_DISPAUD_MIPIPHY_TXBYTECLKHS)
FIXEDRATE_EXTERN(CLKPHY_DISPAUD_MIPIPHY_RXCLKESC0)
FIXEDRATE_EXTERN(CLKIO_DISPAUD_MIXER_BCLK_CP)
FIXEDRATE_EXTERN(CLKPHY_ISP_S_RXBYTECLKHS0_S4)

FIXEDFACTOR_EXTERN(MIF_FF_SHARED0_PLL_DIV2)
FIXEDFACTOR_EXTERN(MIF_FF_SHARED1_PLL_DIV2)
FIXEDFACTOR_EXTERN(MIF_FF_SHARED2_PLL_DIV2)

PLL_EXTERN(CPUCL0_PLL)
PLL_EXTERN(SHARED0_PLL)
PLL_EXTERN(SHARED1_PLL)
PLL_EXTERN(SHARED2_PLL)
PLL_EXTERN(AUD_PLL)
PLL_EXTERN(WPLL_USB_PLL)

DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_1)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_2)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_ACLK)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_PCLK)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_ATCLK)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_PCLKDBG)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_CNTCLK)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_RUN_MONITOR)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_HPM)
DIV_EXTERN(CPUCL0_DIV_CLK_CPUCL0_PLL)
DIV_EXTERN(DISPAUD_DIV_CLK_DISPAUD_APB)
DIV_EXTERN(DISPAUD_DIV_CLK_DISPAUD_DECON_INT_VCLK)
DIV_EXTERN(DISPAUD_DIV_CLK_DISPAUD_DECON_INT_ECLK)
DIV_EXTERN(DISPAUD_DIV_CLK_DISPAUD_MI2S)
DIV_EXTERN(DISPAUD_DIV_CLK_DISPAUD_MIXER)
DIV_EXTERN(DISPAUD_DIV_CLK_DISPAUD_OSCCLK_FM_52M_DIV)
DIV_EXTERN(G3D_DIV_CLK_G3D_BUS)
DIV_EXTERN(G3D_DIV_CLK_G3D_APB)
DIV_EXTERN(ISP_DIV_CLK_ISP_CAM_HALF)
DIV_EXTERN(MFCMSCL_DIV_CLK_MFCMSCL_APB)
DIV_EXTERN(MIF_DIV_CLK_MIF_PHY_CLK2X)
DIV_EXTERN(MIF_DIV_CLK_MIF_PHY_CLKM)
DIV_EXTERN(MIF_DIV_CLKCMU_CP_SHARED0_PLL)
DIV_EXTERN(MIF_DIV_CLKCMU_CP_SHARED1_PLL)
DIV_EXTERN(MIF_DIV_CLKCMU_CP_SHARED2_PLL)
DIV_EXTERN(MIF_DIV_CLK_MIF_BUSD)
DIV_EXTERN(MIF_DIV_CLK_MIF_APB)
DIV_EXTERN(MIF_DIV_CLKCMU_CPUCL0_SWITCH)
DIV_EXTERN(MIF_DIV_CLKCMU_G3D)
DIV_EXTERN(MIF_DIV_CLKCMU_ISP_VRA)
DIV_EXTERN(MIF_DIV_CLKCMU_ISP_CAM)
DIV_EXTERN(MIF_DIV_CLKCMU_DISPAUD_BUS)
DIV_EXTERN(MIF_DIV_CLKCMU_DISPAUD_DECON_INT_VCLK)
DIV_EXTERN(MIF_DIV_CLKCMU_MFCMSCL_MSCL)
DIV_EXTERN(MIF_DIV_CLKCMU_MFCMSCL_MFC)
DIV_EXTERN(MIF_DIV_CLKCMU_FSYS_BUS)
DIV_EXTERN(MIF_DIV_CLKCMU_FSYS_MMC0)
DIV_EXTERN(MIF_DIV_CLKCMU_FSYS_MMC2)
DIV_EXTERN(MIF_DIV_CLKCMU_FSYS_USB20DRD_REFCLK)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_BUS)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_UART_DEBUG)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_UART_SENSOR)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_SPI_REARFROM)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_SPI_ESE)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_USI_0)
DIV_EXTERN(MIF_DIV_CLKCMU_PERI_USI_1)
DIV_EXTERN(MIF_DIV_CLKCMU_APM)
DIV_EXTERN(MIF_DIV_CLKCMU_ISP_SENSOR0)
DIV_EXTERN(MIF_DIV_CLKCMU_GNSS_EXTPLL_SCAN)
DIV_EXTERN(PERI_DIV_CLK_PERI_USI_0_SPI)
DIV_EXTERN(PERI_DIV_CLK_PERI_USI_1_SPI)

MUX_EXTERN(APM_MUX_CLKCMU_APM_USER)
MUX_EXTERN(CPUCL0_MUX_CPUCL0_PLL)
MUX_EXTERN(CPUCL0_MUX_CLKCMU_CPUCL0_SWITCH_USER)
MUX_EXTERN(CPUCL0_MUX_CLK_CPUCL0)
MUX_EXTERN(DISPAUD_MUX_AUD_PLL)
MUX_EXTERN(DISPAUD_MUX_CLKCMU_DISPAUD_BUS_USER)
MUX_EXTERN(DISPAUD_MUX_CLKCMU_DISPAUD_DECON_INT_VCLK_USER)
MUX_EXTERN(DISPAUD_MUX_CLKCMU_DISPAUD_DECON_INT_ECLK_USER)
MUX_EXTERN(DISPAUD_MUX_CLKPHY_DISPAUD_MIPIPHY_TXBYTECLKHS_USER)
MUX_EXTERN(DISPAUD_MUX_CLKPHY_DISPAUD_MIPIPHY_RXCLKESC0_USER)
MUX_EXTERN(FSYS_MUX_CLKPHY_FSYS_USB20DRD_PHYCLOCK_USER)
MUX_EXTERN(G3D_MUX_CLKCMU_G3D_USER)
MUX_EXTERN(ISP_MUX_CLKCMU_ISP_VRA_USER)
MUX_EXTERN(ISP_MUX_CLKCMU_ISP_CAM_USER)
MUX_EXTERN(ISP_MUX_CLKPHY_ISP_S_RXBYTECLKHS0_S4_USER)
MUX_EXTERN(MFCMSCL_MUX_CLKCMU_MFCMSCL_MSCL_USER)
MUX_EXTERN(MFCMSCL_MUX_CLKCMU_MFCMSCL_MFC_USER)
MUX_EXTERN(MIF_MUX_SHARED0_PLL)
MUX_EXTERN(MIF_MUX_SHARED1_PLL)
MUX_EXTERN(MIF_MUX_SHARED2_PLL)
MUX_EXTERN(MIF_MUX_CLK_MIF_PHY_CLK)
MUX_EXTERN(MIF_MUX_CLK_MIF_PHY_CLK_A)
MUX_EXTERN(MIF_MUX_CLK_MIF_PHY_CLK_B)
MUX_EXTERN(MIF_MUX_CLK_MIF_BUSD)
MUX_EXTERN(MIF_MUX_CLKCMU_G3D)
MUX_EXTERN(MIF_MUX_CLKCMU_ISP_VRA)
MUX_EXTERN(MIF_MUX_CLKCMU_ISP_CAM)
MUX_EXTERN(MIF_MUX_CLKCMU_DISPAUD_BUS)
MUX_EXTERN(MIF_MUX_CLKCMU_DISPAUD_DECON_INT_VCLK)
MUX_EXTERN(MIF_MUX_CLKCMU_MFCMSCL_MSCL)
MUX_EXTERN(MIF_MUX_CLKCMU_MFCMSCL_MFC)
MUX_EXTERN(MIF_MUX_CLKCMU_FSYS_BUS)
MUX_EXTERN(MIF_MUX_CLKCMU_FSYS_MMC0)
MUX_EXTERN(MIF_MUX_CLKCMU_FSYS_MMC2)
MUX_EXTERN(MIF_MUX_CLKCMU_FSYS_USB20DRD_REFCLK)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_BUS)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_UART_DEBUG)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_UART_SENSOR)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_SPI_REARFROM)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_SPI_ESE)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_USI_0)
MUX_EXTERN(MIF_MUX_CLKCMU_PERI_USI_1)
MUX_EXTERN(MIF_MUX_CLKCMU_APM)
MUX_EXTERN(MIF_MUX_CLKCMU_ISP_SENSOR0)

GATE_EXTERN(APM_GATE_CLK_APM_UID_APM_IPCLKPORT_ACLK_SYS)
GATE_EXTERN(APM_GATE_CLK_APM_UID_APM_IPCLKPORT_ACLK_CPU)
GATE_EXTERN(APM_GATE_CLK_APM_UID_ASYNCS_APM_IPCLKPORT_I_CLK)
GATE_EXTERN(APM_GATE_CLK_APM_UID_ASYNCM_APM_IPCLKPORT_I_CLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_SYSREG_CPUCL0_IPCLKPORT_CLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_PMU_CPUCL0_IPCLKPORT_I_CLK__PMU_CPUCL0)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCS_D_CPUCL0_IPCLKPORT_I_CLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_SYSREG_CPUCL0_IPCLKPORT_PCLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_HPM_CPUCL0_IPCLKPORT_PCLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_PMU_CPUCL0_IPCLKPORT_I_PCLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_DUMP_PC_CPUCL0_IPCLKPORT_I_PCLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_BUSP1_CPUCL0_IPCLKPORT_ACLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCM_P_CPUCL0_IPCLKPORT_I_CLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_CSSYS_DBG_IPCLKPORT_ATCLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_SECJTAG_IPCLKPORT_i_clk)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_DUMP_PC_CPUCL0_IPCLKPORT_I_PCLKDBG)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_DBG_MUX_CPUCL0_IPCLKPORT_I_CLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_CSSYS_DBG_IPCLKPORT_PCLKDBG)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCS_CSSYS_DBG_IPCLKPORT_PCLKS)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCS_T_CSSYS_DBG_IPCLKPORT_ACLK)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_ASYNCM_P_CSSYS_DBG_IPCLKPORT_PCLKM)
GATE_EXTERN(CPUCL0_GATE_CLK_CPUCL0_UID_HPM_CPUCL0_IPCLKPORT_I_HPM_TARGETCLK_C)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_OSCCLK)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS_PPMU)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS_DISP)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS_VPP)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_BUS)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_FM)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_AUD_AMP)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_AUD)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB_DISP)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_APB)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLKCMU_DISPAUD_APB_SECURE_SMMU_DISP)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_DECON_IPCLKPORT_I_VCLK)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_DSIM0_IPCLKPORT_I_TXBYTECLKHS)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_DSIM0_IPCLKPORT_I_RXCLKESC0)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_MI2S_AMP_IPCLKPORT_I2SCODCLKI)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_MI2S_AUD_IPCLKPORT_I2SCODCLKI)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_MIXER_AUD_IPCLKPORT_SYSCLK)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CON_DISPAUD_IPCLKPORT_I_CP2AUD_BCK)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_OSCCLK_FM_52M)
GATE_EXTERN(DISPAUD_GATE_CLK_DISPAUD_UID_CLK_DISPAUD_OSCCLK_FM_52M_DIV)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_SYSREG_FSYS_IPCLKPORT_CLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_PMU_FSYS_IPCLKPORT_I_CLK__PMU_FSYS)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BUSD1_FSYS_IPCLKPORT_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BUSD0_FSYS_IPCLKPORT_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_HCLK_USB20_CTRL)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_ACLK_HSDRD)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_SYSREG_FSYS_IPCLKPORT_PCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_PPMU_FSYS_IPCLKPORT_PCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_PPMU_FSYS_IPCLKPORT_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_PMU_FSYS_IPCLKPORT_I_PCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_ASYNCS_D_FSYS_IPCLKPORT_I_CLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_ASYNCM_P_FSYS_IPCLKPORT_I_CLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_GPIO_FSYS_IPCLKPORT_PCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_MMC_CARD_IPCLKPORT_I_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_MMC_EMBD_IPCLKPORT_I_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BR_BUSP1_FSYS_IPCLKPORT_aclk)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BUSP5_FSYS_IPCLKPORT_HCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BUSP3_FSYS_IPCLKPORT_HCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BUSP2_FSYS_IPCLKPORT_HCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_BUSP1_FSYS_IPCLKPORT_HCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_RTIC_IPCLKPORT_i_PCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_RTIC_IPCLKPORT_i_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_SSS_IPCLKPORT_i_PCLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_SSS_IPCLKPORT_i_ACLK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_MMC_EMBD_IPCLKPORT_SDCLKIN)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_MMC_CARD_IPCLKPORT_SDCLKIN)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_HSDRD_ref_clk)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_HSDRD_PHYCLOCK)
GATE_EXTERN(FSYS_GATE_CLK_FSYS_UID_USB20DRD_IPCLKPORT_USB20_CLKCORE_0)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_SYSREG_G3D_IPCLKPORT_CLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_PMU_G3D_IPCLKPORT_I_CLK__PMU_G3D)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_QE_G3D_IPCLKPORT_ACLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_PPMU_G3D_IPCLKPORT_ACLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_G3D_IPCLKPORT_CLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_REGSLICE_D1_G3D_IPCLKPORT_aclk)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_REGSLICE_D0_G3D_IPCLKPORT_aclk)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_IXIU_D_G3D_IPCLKPORT_ACLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_ASYNCS_D1_G3D_IPCLKPORT_I_CLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_ASYNCS_D0_G3D_IPCLKPORT_I_CLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_ASYNC_G3D_P_IPCLKPORT_PCLKM)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_SYSREG_G3D_IPCLKPORT_PCLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_QE_G3D_IPCLKPORT_PCLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_PPMU_G3D_IPCLKPORT_PCLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_PMU_G3D_IPCLKPORT_I_PCLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_BUSP_G3D_IPCLKPORT_ACLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_ASYNCM_P_G3D_IPCLKPORT_I_CLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_ASYNC_G3D_P_IPCLKPORT_PCLKS)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_CFW_G3D_IPCLKPORT_ACLK)
GATE_EXTERN(G3D_GATE_CLK_G3D_UID_CFW_G3D_IPCLKPORT_PCLK)
GATE_EXTERN(ISP_GATE_CLK_ISP_UID_CLK_ISP_OSCCLK)
GATE_EXTERN(ISP_GATE_CLK_ISP_UID_CLK_ISP_VRA)
GATE_EXTERN(ISP_GATE_CLK_ISP_UID_CLK_ISP_CAM)
GATE_EXTERN(ISP_GATE_CLK_ISP_UID_CLKPHY_ISP_S_RXBYTECLKHS0_S4)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLK_MFCMSCL_OSCCLK)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MSCL_BI)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_D)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_JPEG)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_POLY)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_MFC_MFC)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLK_MFCMSCL_APB)
GATE_EXTERN(MFCMSCL_GATE_CLK_MFCMSCL_UID_CLKCMU_MFCMSCL_APB_SMMU_MSCL)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_OTP_DESERIAL_MIF_IPCLKPORT_I_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_RCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_WRAP_ADC_IF_IPCLKPORT_I_OSC_SYS)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SYSREG_MIF_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_PMU_MIF_IPCLKPORT_I_CLK__PMU_MIF_JV)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DDR_PHY0_IPCLKPORT_clk)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DDR_PHY0_IPCLKPORT_clkm)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_APB_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SECURE_APB_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PEREV_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_MEMIF_WR_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_MEMIF_RD_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_MEMIF_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SCH_SLICE1_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SCH_SLICE0_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_SCH_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_VCF_WR_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_VCF_RD_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_VCF_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_PPMU_CPU_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_QE_DMC0_CPU_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_ASYNCM_CPUCL0_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_ASYNCM_DBG_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_PDMA_MIF_IPCLKPORT_ACLK_PDMA0)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_CLEANY_WLBT_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_CLEANY_GNSS_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_CLEANY_CEL_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_CPU0_MO_MON_IPCLKPORT_I_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_PPMU_CPU_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SPEEDY_BATCHER_WRAPPER_IPCLKPORT_PCLK_BATCHER_SPEEDY)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SPEEDY_BATCHER_WRAPPER_IPCLKPORT_PCLK_BATCHER_CP)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SPEEDY_BATCHER_WRAPPER_IPCLKPORT_PCLK_BATCHER_AP)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SPEEDY_MIF_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_MAILBOX_WLBT_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_MAILBOX_GNSS_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_MAILBOX_CEL_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_ASYNCAPB_MIF_CSSYS_IPCLKPORT_PCLKS)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SYNC_INTC_SOC_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_INTC_SOC_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_AXI2APB_MIF_TREX_IPCLKPORT_ACLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_AXI2AHB_MIF_P_IPCLKPORT_HCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_AHB2APB_MIF2_IPCLKPORT_HCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_AHB2APB_MIF1_IPCLKPORT_HCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_AHB2APB_MIF0_IPCLKPORT_HCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_AHB_BRIDGE_MIF_IPCLKPORT_HCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_QE_DMC0_CPU_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DDRDMC0_APB_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK_PF)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DDR_PHY0_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_WRAP_ADC_IF_IPCLKPORT_PCLK_S1)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_WRAP_ADC_IF_IPCLKPORT_PCLK_S0)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_GPIO_MIF_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SYSREG_MIF_IPCLKPORT_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_PMU_MIF_IPCLKPORT_I_PCLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK_PF_SECURE)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_DMC0_IPCLKPORT_PCLK_SECURE)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_MAILBOX_SECURE_IPCLKPORT_CLK)
GATE_EXTERN(MIF_GATE_CLKCMU_CP_SHARED0_PLL)
GATE_EXTERN(MIF_GATE_CLKCMU_CP_SHARED1_PLL)
GATE_EXTERN(MIF_GATE_CLKCMU_CP_SHARED2_PLL)
GATE_EXTERN(MIF_GATE_CLKCMU_CPUCL0_SWITCH)
GATE_EXTERN(MIF_GATE_CLKCMU_G3D)
GATE_EXTERN(MIF_GATE_CLKCMU_ISP_VRA)
GATE_EXTERN(MIF_GATE_CLKCMU_ISP_CAM)
GATE_EXTERN(MIF_GATE_CLKCMU_DISPAUD_BUS)
GATE_EXTERN(MIF_GATE_CLKCMU_DISPAUD_DECON_INT_VCLK)
GATE_EXTERN(MIF_GATE_CLKCMU_MFCMSCL_MFC)
GATE_EXTERN(MIF_GATE_CLKCMU_MFCMSCL_MSCL)
GATE_EXTERN(MIF_GATE_CLKCMU_FSYS_BUS)
GATE_EXTERN(MIF_GATE_CLKCMU_FSYS_MMC0)
GATE_EXTERN(MIF_GATE_CLKCMU_FSYS_MMC2)
GATE_EXTERN(MIF_GATE_CLKCMU_FSYS_USB20DRD_REFCLK)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_BUS)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_UART_DEBUG)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_UART_SENSOR)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_SPI_REARFROM)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_SPI_ESE)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_USI_0)
GATE_EXTERN(MIF_GATE_CLKCMU_PERI_USI_1)
GATE_EXTERN(MIF_GATE_CLKCMU_APM)
GATE_EXTERN(MIF_GATE_CLKCMU_ISP_SENSOR0)
GATE_EXTERN(MIF_GATE_CLKCMU_GNSS_TEST_EXTPLL_SCAN_CLK)
GATE_EXTERN(MIF_GATE_CLK_MIF_UID_SPEEDY_MIF_IPCLKPORT_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TMU_CPUCL0_IPCLKPORT_I_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SYSREG_PERI_IPCLKPORT_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_PWM_MOTOR_IPCLKPORT_i_OSCCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_PMU_PERI_IPCLKPORT_I_CLK__PMU_PERI)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_CHIPID_IPCLKPORT_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_PWM_MOTOR_IPCLKPORT_i_PCLK_S0)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_PMU_PERI_IPCLKPORT_I_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_MCT_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_I2C_SENSOR2_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_I2C_SENSOR1_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_I2C_TSP_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_I2C_FUELGAUGE_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_I2C_NFC_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_I2C_MUIC_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_HSI2C_FRONTCAM_IPCLKPORT_iPCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_HSI2C_MAINCAM_IPCLKPORT_iPCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_HSI2C_FRONTSENSOR_IPCLKPORT_iPCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_HSI2C_REARAF_IPCLKPORT_iPCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_HSI2C_REARSENSOR_IPCLKPORT_iPCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_GPIO_TOUCH_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_GPIO_TOP_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_GPIO_NFC_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_GPIO_ESE_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_BUSP1_PERIS1_IPCLKPORT_HCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_BUSP1_PERIS0_IPCLKPORT_HCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_BUSP1_PERIC1_IPCLKPORT_HCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_BUSP1_PERIC0_IPCLKPORT_HCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_BUSP_BR_PERIC_IPCLKPORT_HCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_AXI2AHB_MSD32_PERI_IPCLKPORT_aclk)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_ASYNCM_PERI_IPCLKPORT_I_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_USI_1_IPCLKPORT_i_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_USI_0_IPCLKPORT_i_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_WDT_CPUCL0_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_UART_DEBUG_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_UART_SENSOR_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SYSREG_PERI_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SPI_ESE_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SPI_REARFROM_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SFRIF_TMU_CPUCL0_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SFRIF_GPIO_ALIVE_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC10_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC9_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC8_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC7_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC6_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC5_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC4_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC3_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC2_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC1_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_TZPC0_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SFRIF_CHIPID_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_OTP_CON_TOP_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SFRIF_RTC_ALIVE_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SFRIF_RTC_TOP_IPCLKPORT_PCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_UART_DEBUG_IPCLKPORT_EXT_UCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_UART_SENSOR_IPCLKPORT_EXT_UCLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SPI_REARFROM_IPCLKPORT_SPI_EXT_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_SPI_ESE_IPCLKPORT_SPI_EXT_CLK)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_USI_0_IPCLKPORT_i_SCLK_UART)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_USI_1_IPCLKPORT_i_SCLK_UART)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_USI_0_IPCLKPORT_i_SCLK_SPI)
GATE_EXTERN(PERI_GATE_CLK_PERI_UID_USI_1_IPCLKPORT_i_SCLK_SPI)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_ISP_VRA)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_ISP_CAM)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_DISPAUD_BUS)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_DISPAUD_DECON_INT_VCLK)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_MFCMSCL_MSCL)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_MFCMSCL_MFC)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_FSYS_BUS)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_FSYS_MMC0)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_FSYS_MMC2)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_FSYS_USB20DRD_REFCLK)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_BUS)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_UART_DEBUG)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_UART_SENSOR)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_SPI_REARFROM)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_SPI_ESE)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_USI_0)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_PERI_USI_1)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_APM)
GATE_EXTERN(MIF_MUXGATE_CLKCMU_ISP_SENSOR0)

GATE_EXTERN(PMU_DEBUG_CLKOUT_SEL08)
GATE_EXTERN(PMU_DEBUG_CLKOUT_SEL09)
GATE_EXTERN(PMU_DEBUG_CLKOUT_SEL10)
GATE_EXTERN(PMU_DEBUG_CLKOUT_SEL11)
GATE_EXTERN(PMU_DEBUG_CLKOUT_SEL12)
GATE_EXTERN(PMU_DEBUG_CLKOUT_DISABLE)

#endif
