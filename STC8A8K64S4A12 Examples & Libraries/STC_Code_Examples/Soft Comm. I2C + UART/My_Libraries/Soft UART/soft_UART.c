#include "soft_UART.h"


void soft_UART_init(void)
{
  TXing = FALSE;
  RXing = FALSE;
  TX_CNT = 0x00;
  RX_CNT = 0x00;
  TX_done = TRUE;
  RX_done = FALSE;

  TMR2_setup(TMR2_sysclk, \
             TMR2_clk_prescalar_1T);

  TMR2_load_counter_16(tmr_load_value);

  TMR2_start;

  _enable_TMR_2_interrupt;
  _enable_global_interrupt;
}


void TMR_2_ISR(void)        
interrupt 12
{
    if(RXing == TRUE)
    {
        if(--RX_CNT == 0x00)
        {
            RX_CNT = 0x03;

            if(--RX_Bit == 0x00)
            {
                RX_Buffer = RX_Data;
                RXing = FALSE;
                RX_done = TRUE;
            }

            else
            {
                RX_Data >>= 0x01;

                if(RXD_pin == HIGH)
                {
                    RX_Data |= 0x80;
                }
            }       
        }
    }

    else if(RXD_pin == FALSE)
    {
        RXing = TRUE;
        RX_CNT = 0x04;
        RX_Bit = 0x09;
    }

    if(--TX_CNT == 0x00)
    {
        TX_CNT = 0x03;

        if(TXing == TRUE)
        {
            if(TX_Bit == 0x00)
            {
                TXD_pin = LOW;
                TX_Data = TX_Buffer;
                TX_Bit = 0x09;
            }

            else
            {
                TX_Data >>= 0x01;

                if(--TX_Bit == 0x00)
                {
                    TXD_pin = HIGH;
                    TXing = FALSE;
                    TX_done = TRUE;
                }

                else
                {
                    TXD_pin = CY;
                }                
            }
            
        }
    }
}