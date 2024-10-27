/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI9 RXI (Receive data full) */
            [1] = sci_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [4] = sdhimmc_accs_isr, /* SDHIMMC1 ACCS (Card access) */
            [5] = sdhimmc_card_isr, /* SDHIMMC1 CARD (Card detect) */
            [6] = dmac_int_isr, /* DMAC0 INT (DMAC0 transfer end) */
            [7] = glcdc_line_detect_isr, /* GLCDC LINE DETECT (Specified line) */
            [8] = drw_int_isr, /* DRW INT (DRW interrupt) */
            [9] = jpeg_jedi_isr, /* JPEG JEDI (Compression/decompression process interrupt) */
            [10] = jpeg_jdti_isr, /* JPEG JDTI (Data transfer interrupt) */
            [11] = ssi_rxi_isr, /* SSI0 RXI (Receive data full) */
            [12] = ssi_int_isr, /* SSI0 INT (Error interrupt) */
            [13] = gpt_counter_overflow_isr, /* GPT2 COUNTER OVERFLOW (Overflow) */
            [14] = sci_spi_rxi_isr, /* SCI6 RXI (Receive data full) */
            [15] = sci_spi_txi_isr, /* SCI6 TXI (Transmit data empty) */
            [16] = sci_spi_tei_isr, /* SCI6 TEI (Transmit end) */
            [17] = sci_spi_eri_isr, /* SCI6 ERI (Receive error) */
            [18] = sci_spi_rxi_isr, /* SCI3 RXI (Receive data full) */
            [19] = sci_spi_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [20] = sci_spi_tei_isr, /* SCI3 TEI (Transmit end) */
            [21] = sci_spi_eri_isr, /* SCI3 ERI (Receive error) */
            [22] = can_error_isr, /* CAN0 ERROR (Error interrupt) */
            [23] = can_rx_isr, /* CAN0 MAILBOX RX (Reception complete interrupt) */
            [24] = can_tx_isr, /* CAN0 MAILBOX TX (Transmission complete interrupt) */
            [25] = can_rx_isr, /* CAN0 FIFO RX (Receive FIFO interrupt) */
            [26] = can_tx_isr, /* CAN0 FIFO TX (Transmit FIFO interrupt) */
            [27] = sci_spi_rxi_isr, /* SCI7 RXI (Receive data full) */
            [28] = sci_spi_txi_isr, /* SCI7 TXI (Transmit data empty) */
            [29] = sci_spi_tei_isr, /* SCI7 TEI (Transmit end) */
            [30] = sci_spi_eri_isr, /* SCI7 ERI (Receive error) */
            [31] = r_icu_isr, /* ICU IRQ10 (External pin interrupt 10) */
            [32] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [33] = r_icu_isr, /* ICU IRQ13 (External pin interrupt 13) */
            [34] = r_icu_isr, /* ICU IRQ9 (External pin interrupt 9) */
            [35] = ether_eint_isr, /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [36] = rtc_alarm_periodic_isr, /* RTC ALARM (Alarm interrupt) */
            [37] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
            [38] = sci_uart_rxi_isr, /* SCI4 RXI (Receive data full) */
            [39] = sci_uart_txi_isr, /* SCI4 TXI (Transmit data empty) */
            [40] = sci_uart_tei_isr, /* SCI4 TEI (Transmit end) */
            [41] = sci_uart_eri_isr, /* SCI4 ERI (Receive error) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_SCI9_RXI,GROUP0), /* SCI9 RXI (Receive data full) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TXI,GROUP1), /* SCI9 TXI (Transmit data empty) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_SCI9_TEI,GROUP2), /* SCI9 TEI (Transmit end) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_SCI9_ERI,GROUP3), /* SCI9 ERI (Receive error) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_SDHIMMC1_ACCS,GROUP4), /* SDHIMMC1 ACCS (Card access) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_SDHIMMC1_CARD,GROUP5), /* SDHIMMC1 CARD (Card detect) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_DMAC0_INT,GROUP6), /* DMAC0 INT (DMAC0 transfer end) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_GLCDC_LINE_DETECT,GROUP7), /* GLCDC LINE DETECT (Specified line) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_DRW_INT,GROUP0), /* DRW INT (DRW interrupt) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_JPEG_JEDI,GROUP1), /* JPEG JEDI (Compression/decompression process interrupt) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_JPEG_JDTI,GROUP2), /* JPEG JDTI (Data transfer interrupt) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_SSI0_RXI,GROUP3), /* SSI0 RXI (Receive data full) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_SSI0_INT,GROUP4), /* SSI0 INT (Error interrupt) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_GPT2_COUNTER_OVERFLOW,GROUP5), /* GPT2 COUNTER OVERFLOW (Overflow) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_SCI6_RXI,GROUP6), /* SCI6 RXI (Receive data full) */
            [15] = BSP_PRV_VECT_ENUM(EVENT_SCI6_TXI,GROUP7), /* SCI6 TXI (Transmit data empty) */
            [16] = BSP_PRV_VECT_ENUM(EVENT_SCI6_TEI,GROUP0), /* SCI6 TEI (Transmit end) */
            [17] = BSP_PRV_VECT_ENUM(EVENT_SCI6_ERI,GROUP1), /* SCI6 ERI (Receive error) */
            [18] = BSP_PRV_VECT_ENUM(EVENT_SCI3_RXI,GROUP2), /* SCI3 RXI (Receive data full) */
            [19] = BSP_PRV_VECT_ENUM(EVENT_SCI3_TXI,GROUP3), /* SCI3 TXI (Transmit data empty) */
            [20] = BSP_PRV_VECT_ENUM(EVENT_SCI3_TEI,GROUP4), /* SCI3 TEI (Transmit end) */
            [21] = BSP_PRV_VECT_ENUM(EVENT_SCI3_ERI,GROUP5), /* SCI3 ERI (Receive error) */
            [22] = BSP_PRV_VECT_ENUM(EVENT_CAN0_ERROR,GROUP6), /* CAN0 ERROR (Error interrupt) */
            [23] = BSP_PRV_VECT_ENUM(EVENT_CAN0_MAILBOX_RX,GROUP7), /* CAN0 MAILBOX RX (Reception complete interrupt) */
            [24] = BSP_PRV_VECT_ENUM(EVENT_CAN0_MAILBOX_TX,GROUP0), /* CAN0 MAILBOX TX (Transmission complete interrupt) */
            [25] = BSP_PRV_VECT_ENUM(EVENT_CAN0_FIFO_RX,GROUP1), /* CAN0 FIFO RX (Receive FIFO interrupt) */
            [26] = BSP_PRV_VECT_ENUM(EVENT_CAN0_FIFO_TX,GROUP2), /* CAN0 FIFO TX (Transmit FIFO interrupt) */
            [27] = BSP_PRV_VECT_ENUM(EVENT_SCI7_RXI,GROUP3), /* SCI7 RXI (Receive data full) */
            [28] = BSP_PRV_VECT_ENUM(EVENT_SCI7_TXI,GROUP4), /* SCI7 TXI (Transmit data empty) */
            [29] = BSP_PRV_VECT_ENUM(EVENT_SCI7_TEI,GROUP5), /* SCI7 TEI (Transmit end) */
            [30] = BSP_PRV_VECT_ENUM(EVENT_SCI7_ERI,GROUP6), /* SCI7 ERI (Receive error) */
            [31] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ10,GROUP7), /* ICU IRQ10 (External pin interrupt 10) */
            [32] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ11,FIXED), /* ICU IRQ11 (External pin interrupt 11) */
            [33] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ13,FIXED), /* ICU IRQ13 (External pin interrupt 13) */
            [34] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ9,FIXED), /* ICU IRQ9 (External pin interrupt 9) */
            [35] = BSP_PRV_VECT_ENUM(EVENT_EDMAC0_EINT,FIXED), /* EDMAC0 EINT (EDMAC 0 interrupt) */
            [36] = BSP_PRV_VECT_ENUM(EVENT_RTC_ALARM,FIXED), /* RTC ALARM (Alarm interrupt) */
            [37] = BSP_PRV_VECT_ENUM(EVENT_RTC_CARRY,FIXED), /* RTC CARRY (Carry interrupt) */
            [38] = BSP_PRV_VECT_ENUM(EVENT_SCI4_RXI,FIXED), /* SCI4 RXI (Receive data full) */
            [39] = BSP_PRV_VECT_ENUM(EVENT_SCI4_TXI,FIXED), /* SCI4 TXI (Transmit data empty) */
            [40] = BSP_PRV_VECT_ENUM(EVENT_SCI4_TEI,FIXED), /* SCI4 TEI (Transmit end) */
            [41] = BSP_PRV_VECT_ENUM(EVENT_SCI4_ERI,FIXED), /* SCI4 ERI (Receive error) */
        };
        #endif
        #endif
