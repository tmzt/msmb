/*
 * Copyright (c) 2011, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of Google, Inc. nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _PLATFORM_APQ8064_IOMAP_H_
#define _PLATFORM_APQ8064_IOMAP_H_

#define MSM_IOMAP_BASE      0x00100000
#define MSM_IOMAP_END       0x28000000

/* Shared memory */
#define MSM_SHARED_BASE       0x80000000
#define MSM_SHARED_IMEM_BASE  0x2A03F000
#define RESTART_REASON_ADDR  (MSM_SHARED_IMEM_BASE + 0x65C)

/* Peripherals */
#define TLMM_BASE_ADDR           0x00800000

/* GPIO */
#define GPIO_CONFIG_ADDR(x)     (TLMM_BASE_ADDR + 0x1000 + (x)*0x10)
#define GPIO_IN_OUT_ADDR(x)     (TLMM_BASE_ADDR + 0x1004 + (x)*0x10)

/* CLK CTL */
#define CLK_CTL_BASE             0x00900000
#define SDC_MD(n)               (CLK_CTL_BASE + 0x2828 + (32 * ((n) - 1)))
#define SDC_NS(n)               (CLK_CTL_BASE + 0x282C + (32 * ((n) - 1)))
#define USB_HS1_HCLK_CTL        (CLK_CTL_BASE + 0x2900)
#define USB_HS1_XCVR_FS_CLK_MD  (CLK_CTL_BASE + 0x2908)
#define USB_HS1_XCVR_FS_CLK_NS  (CLK_CTL_BASE + 0x290C)
#define GSBIn_HCLK_CTL(n)       (CLK_CTL_BASE + 0x29C0 + (32 * ((n) - 1)))
#define GSBIn_HCLK_FS(n)        (CLK_CTL_BASE + 0x29C4 + (32 * ((n) - 1)))
#define GSBIn_QUP_APPS_MD(n)    (CLK_CTL_BASE + 0x29C8 + (32 * ((n) - 1)))
#define GSBIn_QUP_APPS_NS(n)    (CLK_CTL_BASE + 0x29CC + (32 * ((n) - 1)))
#define GSBIn_UART_APPS_MD(n)   (CLK_CTL_BASE + 0x29D0 + (32 * ((n) - 1)))
#define GSBIn_UART_APPS_NS(n)   (CLK_CTL_BASE + 0x29D4 + (32 * ((n) - 1)))
#define MSM_BOOT_PLL8_STATUS    (CLK_CTL_BASE + 0x3158)
#define MSM_BOOT_PLL_ENABLE_SC0 (CLK_CTL_BASE + 0x34C0)

/* GIC */
#define MSM_GIC_DIST_BASE        0x02080000
#define MSM_GIC_CPU_BASE         0x02081000

/* TMR */
#define MSM_TMR_BASE             0x02000000
#define MSM_GPT_BASE            (MSM_TMR_BASE + 0x04)
#define MSM_DGT_BASE            (MSM_TMR_BASE + 0x24)
#define MSM_WDT0_RST            (MSM_TMR_BASE + 0x38)
#define MSM_WDT0_EN             (MSM_TMR_BASE + 0x40)
#define MSM_WDT0_BT             (MSM_TMR_BASE + 0x4C)
#define SPSS_TIMER_STATUS       (MSM_TMR_BASE + 0x88)

#define GPT_REG(off)            (MSM_GPT_BASE + (off))
#define DGT_REG(off)            (MSM_DGT_BASE + (off))

#define GPT_MATCH_VAL            GPT_REG(0x0000)
#define GPT_COUNT_VAL            GPT_REG(0x0004)
#define GPT_ENABLE               GPT_REG(0x0008)
#define GPT_CLEAR                GPT_REG(0x000C)

#define DGT_MATCH_VAL            DGT_REG(0x0000)
#define DGT_COUNT_VAL            DGT_REG(0x0004)
#define DGT_ENABLE               DGT_REG(0x0008)
#define DGT_CLEAR                DGT_REG(0x000C)
#define DGT_CLK_CTL              DGT_REG(0x0010)

#define MSM_USB_BASE             0x12500000
#define MSM_TCSR_BASE            0x1A400000
#define MSM_TCSR_WDOG_CFG       (MSM_TCSR_BASE + 0x30)

/* SDCC */
#define MSM_SDC1_BASE            0x12400000
#define MSM_SDC2_BASE            0x12140000
#define MSM_SDC3_BASE            0x12180000
#define MSM_SDC4_BASE            0x121C0000


/* GSBI/QUP/UART_DM */
#define GSBI_BASE(id)           ((id) <= 7 ? (0x16000000 + (((id)-1) << 20)) : \
                                             (0x1A000000 + (((id)-8) << 20)))
#define GSBI_UART_DM_BASE(id)   (GSBI_BASE(id) + 0x40000)
#define QUP_BASE(id)            (GSBI_BASE(id) + 0x80000)

#endif
