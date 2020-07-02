/*
 *(C) Copyright Black Sesame Technologies (Shanghai)Ltd. Co., 2020. All rights reserved.
 *
 * This file contains proprietary information that is the sole intellectual property of Black
 * Sesame Technologies (Shanghai)Ltd. Co. No part of this material or its documentation 
 * may be reproduced, distributed, transmitted, displayed or published in any manner 
 * without the written permission of Black Sesame Technologies (Shanghai)Ltd. Co.
 */

#ifndef __HS_CPU_GIC_H_
#define __HS_CPU_GIC_H_
#include <a1000/sysreg_base.h>

#define CPU_GIC_DISTRIBUTOR (GIC_BASE_ADDR + 0x1000)
#define CPU_GIC_CPU_INTERCACE (GIC_BASE_ADDR + 0x2000)
#define CPU_GIC_VIR_INTF_CTL (GIC_BASE_ADDR + 0x4000)
#define CPU_GIC_VIR_INTF_CTL_A (GIC_BASE_ADDR + 0x5000)
#define CPU_GIC_VIR_CPU_INTF (GIC_BASE_ADDR + 0x6000)

#define CPU_GIC_GICD_CTLR *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x000))
#define CPU_GIC_GICD_TYPER *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x004))
#define CPU_GIC_GICD_IIDR *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x008))
#define CPU_GIC_GICD_IGROUPR0                                                  \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x080))
#define CPU_GIC_GICD_IGROUPR0_ADDR (CPU_GIC_DISTRIBUTOR + 0x080)
#define CPU_GIC_GICD_ISENABLER0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x100))
#define CPU_GIC_GICD_ISENABLER0_ADDR (CPU_GIC_DISTRIBUTOR + 0x100)
#define CPU_GIC_GICD_ICENABLER0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x180))
#define CPU_GIC_GICD_ICENABLER0_ADDR (CPU_GIC_DISTRIBUTOR + 0x180)
#define CPU_GIC_GICD_ISPENDR0                                                  \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x200))
#define CPU_GIC_GICD_ICPENDR0                                                  \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x280))
#define CPU_GIC_GICD_ISACTIVER0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x300))
#define CPU_GIC_GICD_ICACTIVER0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x380))
#define CPU_GIC_GICD_IPRIORITYR0                                               \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x400))
#define CPU_GIC_GICD_ITARGETSR0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0x800))
#define CPU_GIC_GICD_ITARGETSR0_ADDR (CPU_GIC_DISTRIBUTOR + 0x800)

//Interrupt Configruation Registers
#define CPU_GIC_LEVEL_SENSITIVE (0 << 0)
#define CPU_GIC_EDGE_TRIGGERED (1 << 0)
#define CPU_GIC_N_N_MODEL (0 << 1)
#define CPU_GIC_1_N_MODEL (1 << 1)

#define CPU_GIC_GICD_ICFGR0                                                    \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xC00))
#define CPU_GIC_GICD_ICFGR0_ADDR (CPU_GIC_DISTRIBUTOR + 0xC00)

//
#define CPU_GIC_GICD_PPISR *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xD00))
#define CPU_GIC_GICD_SPISR0                                                    \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xD04))
#define CPU_GIC_GICD_SGIR *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xF00))
#define CPU_GIC_GICD_CPENDSGIR0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xF10))
#define CPU_GIC_GICD_SPENDSGIR0                                                \
	*((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xF20))
#define CPU_GIC_GICD_PIDR4 *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xFD0))
#define CPU_GIC_GICD_PIDR5 *((volatile unsigned *)(CPU_GIC_DISTRIBUTOR + 0xFD4))

#define CPU_GIC_GICC_CTLR                                                      \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0000))
#define CPU_GIC_GICC_PMR                                                       \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0004))
#define CPU_GIC_GICC_BPR                                                       \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0008))
#define CPU_GIC_GICC_IAR                                                       \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x000C))
#define CPU_GIC_GICC_EOIR                                                      \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0010))
#define CPU_GIC_GICC_RPR                                                       \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0014))
#define CPU_GIC_GICC_HPPIR                                                     \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0018))
#define CPU_GIC_GICC_ABPR                                                      \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x001C))
#define CPU_GIC_GICC_AIAR                                                      \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0020))
#define CPU_GIC_GICC_AEOIR                                                     \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0024))
#define CPU_GIC_GICC_AHPPIR                                                    \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x0028))
#define CPU_GIC_GICC_APR0                                                      \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x00D0))
#define CPU_GIC_GICC_NSAPR0                                                    \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x00E0))
#define CPU_GIC_GICC_IIDR                                                      \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x00FC))
#define CPU_GIC_GICC_DIR                                                       \
	*((volatile unsigned *)(CPU_GIC_CPU_INTERCACE + 0x1000))

#define CPU_GIC_GICH_HCR *((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x000))
#define CPU_GIC_GICH_VTR *((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x004))
#define CPU_GIC_GICH_VMCR *((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x008))
#define CPU_GIC_GICH_MISR *((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x010))
#define CPU_GIC_GICH_EISR0                                                     \
	*((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x020))
#define CPU_GIC_GICH_EISR1                                                     \
	*((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x024))
#define CPU_GIC_GICH_ELSR0                                                     \
	*((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x030))
#define CPU_GIC_GICH_ELSR1                                                     \
	*((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x034))
#define CPU_GIC_GICH_APR *((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x0F0))
#define CPU_GIC_GICH_LR0 *((volatile unsigned *)(CPU_GIC_VIR_INTF_CTL + 0x100))
#define CPU_GIC_GICH_LR0_ADDR (CPU_GIC_VIR_INTF_CTL + 0x100)

#define CPU_GIC_GICV_CTLR                                                      \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0000))
#define CPU_GIC_GICV_PMR *((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0004))
#define CPU_GIC_GICV_BPR *((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0008))
#define CPU_GIC_GICV_IAR *((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x000C))
#define CPU_GIC_GICV_EOIR                                                      \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0010))
#define CPU_GIC_GICV_RPR *((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0014))
#define CPU_GIC_GICV_HPPIR                                                     \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0018))
#define CPU_GIC_GICV_ABPR                                                      \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x001C))
#define CPU_GIC_GICV_AIAR                                                      \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0020))
#define CPU_GIC_GICV_AEOIR                                                     \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0024))
#define CPU_GIC_GICV_AHPPIR                                                    \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x0028))
#define CPU_GIC_GICV_APR0                                                      \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x00D0))
#define CPU_GIC_GICV_NSAPR0                                                    \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x00E0))
#define CPU_GIC_GICV_IIDR                                                      \
	*((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x00FC))
#define CPU_GIC_GICV_DIR *((volatile unsigned *)(CPU_GIC_VIR_CPU_INTF + 0x1000))

void cpu_gicd_enable_grp0(void);
void cpu_gicd_enable_grp1(void);
void cpu_gicd_set_group(unsigned intr_id, unsigned group);
void cpu_gicd_set_enable(unsigned intr_id);
void cpu_gicd_clear_enable(unsigned intr_id);
void cpu_gicd_set_control(unsigned intr_id, unsigned control);
void cpu_gicd_set_targets(unsigned intr_id, unsigned targets);
void cpu_gicd_set_sgi(unsigned data);
void cpu_gicc_enable_grp0(void);
void cpu_gicc_enable_grp1(void);
void cpu_gicc_set_eoimodens(void);
void cpu_gicc_set_priority_mask(unsigned priority);
unsigned long cpu_gicc_get_priority_mask(void);
unsigned cpu_gicc_get_iar(void);
void cpu_gicc_set_eoir(unsigned eoi);
unsigned cpu_gicc_get_aiar(void);
void cpu_gicc_set_aeoir(unsigned eoi);
void cpu_gich_en(void);
void cpu_gich_set_lr(unsigned lr_id, unsigned data);
void cpu_gicv_enable_grp0(void);
void cpu_gicv_enable_grp1(void);
void cpu_gicv_set_eoimodens(void);
void cpu_gicv_set_priority_mask(unsigned priority);
unsigned cpu_gicv_get_iar(void);
void cpu_gicv_set_eoir(unsigned eoi);
unsigned cpu_gicv_get_aiar(void);
void cpu_gicv_set_aeoir(unsigned eoi);
#endif
