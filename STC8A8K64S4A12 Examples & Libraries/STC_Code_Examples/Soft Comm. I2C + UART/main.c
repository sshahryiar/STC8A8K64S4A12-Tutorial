#include "STC8xxx.h"
#include "BSP.h"
#include "LCD_2_Wire.c"
#include "soft_UART.c"


void setup(void);


void main(void)
{
  unsigned char msg1[10] = {"0123456789"};
  unsigned char msg2[10] = {"!@#$%^&*()"};
  
  char i = 0x00;
  
  char rcv_s = 0x00;
  char rcv_3 = 0x00;
  
  setup();
  
  LCD_goto(0, 0);
  LCD_putstr("TXDs: ");
  LCD_goto(10, 0);
  LCD_putstr("TXD3: ");

  LCD_goto(0, 1);
  LCD_putstr("RXDs: ");
  LCD_goto(10, 1);
  LCD_putstr("RXD3: ");

  while(1)
  {
    for(i = 0; i < 10; i++)
    {     
      if(TX_done == TRUE)
      {
          TX_done = FALSE;
          TX_Buffer = msg1[i];
          TXing = TRUE;
      }
      
      UART3_write_buffer(msg2[i]);  
      
      LCD_goto(5, 0);
      LCD_putchar(msg1[i]);
      LCD_goto(15, 0);
      LCD_putchar(msg2[i]);
      
      if(RX_done == TRUE)
      {
        RX_done = FALSE;
        rcv_s = RX_Buffer;
      }     
      
      rcv_3 = UART3_read_buffer();

      LCD_goto(5, 1);
      LCD_putchar(rcv_s);      
      LCD_goto(15, 1);
      LCD_putchar(rcv_3);
      
      delay_ms(900);
    }
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_div_1, MCLK_out_P54);

  UART3_pin_option(0x00);
  
  UART3_init(9600, \
             UART3_baud_source_TMR3, \
             UART3_timer_1T, \
             12000000);
  
  LCD_init();
  LCD_clear_home();
  soft_UART_init();
}