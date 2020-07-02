/*
 *(C) Copyright Black Sesame Technologies (Shanghai)Ltd. Co., 2020. All rights reserved.
 *
 * This file contains proprietary information that is the sole intellectual property of Black
 * Sesame Technologies (Shanghai)Ltd. Co. No part of this material or its documentation 
 * may be reproduced, distributed, transmitted, displayed or published in any manner 
 * without the written permission of Black Sesame Technologies (Shanghai)Ltd. Co.
 */

#ifndef __SYSREG_BASE_H_
#define __SYSREG_BASE_H_

#define IRAM_BASE_ADDR (0x0)

#define FLASE_GRP_BASE (0x10000000)
#ifdef CONFIG_R5_SECURE
#define QSPI0_BASE_ADDR     0x10000000
#else
#define QSPI0_BASE_ADDR     0x00000000
#endif
#define QSPI1_BASE_ADDR (0x14000000)
#define SRAM_BASE_ADDR (0x18000000)

/* low speed io */
#define LIO_GRP_BASE (0x20000000)
#define LIO_IP_OFFSET (0x1000)

#define I2C0_BASE_ADDR (0x20000000)
#define I2C1_BASE_ADDR (0x20001000)
#define I2C2_BASE_ADDR (0x20002000)
#define I2C3_BASE_ADDR (0x20003000)
#define I2C4_BASE_ADDR (0x20004000)
#define I2C5_BASE_ADDR (0x20005000)
#define I2C_IP_CNT 6

#define UART0_BASE_ADDR (0x20008000)
#define UART1_BASE_ADDR (0x2000A000)
#define UART2_BASE_ADDR (0x2000B000)
#define UART3_BASE_ADDR (0x20009000)

#define SPI0_BASE_ADDR (0x2000C000)
#define SPI1_BASE_ADDR (0x2000D000)
#define I2S0_BASE_ADDR (0x2000E000)
#define I2S1_BASE_ADDR (0x2000F000)
#define GPIO0_BASE_ADDR (0x20010000)
#define GPIO1_BASE_ADDR (0x20011000)

#define CANFD0_BASE_ADDR (0x20016000)
#define CANFD1_BASE_ADDR (0x20017000)

#define TIMER0_PWM0_BASE_ADDR (0x20012000)
#define TIMER1_PWM1_BASE_ADDR (0x20013000)
#define TIMER2_PWM2_BASE_ADDR (0x20014000)
#define TIMER3_PWM3_BASE_ADDR (0x20015000)
#define TIMER_PWM_IP_CNT 4

#define WDT0_BASE_ADDR (0x2001A000)
#define WDT1_BASE_ADDR (0x2001B000)
#define WDT2_BASE_ADDR (0x2001C000)
#define WDT3_BASE_ADDR (0x2001D000)

#define USB2_BASE_ADDR (0x30300000)

#define USB3_BASE_ADDR (0x30200000)

#define PCIE_4X_BASE_ADDR (0x30600000)
#define PCIE_2X_BASE_ADDR (0x30A00000)
#define PCIE_PHY_BASE_ADDR (0x30E02000)

#define SD_EMMC0_BASE_ADDR (0x30400000)
#define SD_EMMC1_BASE_ADDR (0x30500000)

#define GIC_BASE_ADDR (0X32000000)

#define DDRC0_CTRL_PHY_ADDR (0x38000000)
#define DDRC1_CTRL_PHY_ADDR (0x3C000000)

#define GPU_BASE_ADDR (0x33300000)

/* A55 ctrl */
#define A55_CTRL_ADDR (0x33000000)
#define A55_CRM_ADDR (0x33002000)

/* cv conctrl */
#define CV_SREG_ADDR (0x51030000)
#define CV_GWARP_ADDR (0x51040000)

#define ISP_BASE   (0x52000000)
#define GWARP_BASE      (0x53000000)
#define VOUT_BASE       (0x53080000)
#define VSP_BASE        (0x53090000)
#define BSMEM_BASE      (0x54000000)

/* CRM clock and reset */

#ifdef CONFIG_A55
#define SAFETY_CRM_ADDR (0x70035000)
#else
#define SAFETY_CRM_ADDR (0xC0035000)
#endif

/* secure ip address */
#define R5_CONFIG_ADDR (0xf0000000)
#define SECURE_CTRL_ADDR (0xf0001000)
#define OTP_BASE_ADDR (0xf0002000)
#define SECURE_TIMER_ADDR (0xf0003000)
#define SECURE_WDT_ADDR (0xf0004000)
#define TRNG_BASE_ADDR (0xf0005000)
#define AES_BASE_ADDR (0xf0006000)
#define MSHA_BASE_ADDR (0xf0007000)
#define SM_BASE_ADDR (0xf0008000)
#define CRC_BASE_ADDR (0xf0009000)
#define SECURE_INTC_ADDR (0xf000A000)
#define PKA_BASE_ADDR (0xf0010000)

#define LSP0_CRM_ADDR (0x20020000)
#define LSP1_CRM_ADDR (0x20021000)
#define QSPI0_XIP_ENABLE_REG (LSP0_CRM_ADDR + 0x10)
#define SAFETY_RELEASE_BIT (28)
#define A55_RELEASE_BIT (30)

/***********************crpm & sysctrl reg detail********************/
#define SECURE_CLOCK_CTRL (SECURE_CTRL_ADDR + 0x0)
#define SECURE_BLOCK_RELEASE (SECURE_CTRL_ADDR + 0x4)
#define SECURE_SRAM_FIREWALL (SECURE_CTRL_ADDR + 0x10)

#define SAFETY_RELEASE_CTRL (SAFETY_CRM_ADDR + 0x8)
#define SAFETY_WDT_CTRL (SAFETY_CRM_ADDR + 0xc)
#define SAFETY_A55_FIREWALL (SAFETY_CRM_ADDR + 0x114)
#define SAFETY_PMM_CFG0 (AON_PMM_REG_BASE_ADDR + 0x0)

#define A55_BOOT_RVBARADDR0 (A55_CTRL_ADDR + 0x2C)
#define A55_CRM_BLOCK_RELEASE (A55_CRM_ADDR + 0x4)
#define A55_CRM_BLOCK_HW_RST1 (A55_CRM_ADDR + 0xC0)

#define CV_SREG_CORE_RELEASE (CV_SREG_ADDR + 0x0)
#define CV_SREG_CORE1_START (CV_SREG_ADDR + 0x4)
#define CV_SREG_CORE2_START (CV_SREG_ADDR + 0x8)
#define CV_SREG_CORE3_START (CV_SREG_ADDR + 0xC)
#define CV_SREG_CORE4_START (CV_SREG_ADDR + 0x10)

/* r5 safety */
#define SAFETY_GIC_BASE_ADDR (0xc0000000)
#define TOP_CRM_BASE_ADDR (0x33002000)

#define SRAM_FIREWALL 0xF0001010
#define SEC_SAFETY_RESET_CTRL 0xC0035008
#define TOP_CRM_BLOCK_HW_RST1 0X330020C0
#define SYS_CTRL_RVBARADDR0 0X3300002C

/* a55 */
#define A55_WDT0_BASE_ADDR (0x32009000)
#define A55_WDT1_BASE_ADDR (0x3200A000)
#define A55_WDT2_BASE_ADDR (0x3200B000)
#define A55_WDT3_BASE_ADDR (0x3200C000)
#define A55_WDT4_BASE_ADDR (0x3200D000)
#define A55_WDT5_BASE_ADDR (0x3200E000)
#define A55_WDT6_BASE_ADDR (0x3200F000)
#define A55_WDT7_BASE_ADDR (0x32010000)

#define A55_TIMER_BASE_ADDR (0x32008000)

#define GMAC0_BASE_ADDR (0x30000000)
#define GMAC1_BASE_ADDR (0x30100000)

#define GDMA_BASE_ADDR (0x33200000)
#define SDMA_BASE_ADDR (0xc0020000)

#define DDR_MEMORY0_ADDR_START (0x80000000)
#define DDR_MEMORY0_ADDR_SIZE (0x7FFFFFFF)
#ifdef CONFIG_A55
#define DDR_MEMORY1_ADDR_START (0x100000000)
#define DDR_MEMORY1_ADDR_SIZE (0x17FFFFFFF)
#else
#define DDR_MEMORY1_ADDR_START (0x0)
#define DDR_MEMORY1_ADDR_SIZE (0x0)
#endif

/* pinmux config register */
#define TOP_PMM_REG_BASE_ADDR (0x33001000)
#ifdef CONFIG_A55
#define AON_PMM_REG_BASE_ADDR (0x70038000)
#else
#define AON_PMM_REG_BASE_ADDR (0xC0038000)
#endif

#define IPC_BASE 0x33100000

#define CPU_CSR_BASE_ADDR 0x32011000

#define CPU_NOC_BASE_ADDR (0x33400000)
#define CORE_NOC_BASE_ADDR (0x33420000)

#endif // ifndef __SYSREG_BASE_H_
