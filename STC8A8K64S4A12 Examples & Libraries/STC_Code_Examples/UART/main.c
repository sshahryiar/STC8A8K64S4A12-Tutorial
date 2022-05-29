#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"


void setup(void);


void main(void)
{
  unsigned char msg1[10] = {"MicroArena"};
  unsigned char msg2[10] = {"SShahryiar"};
  
  char i = 0x00;
  
  char rcv_1 = 0x00;
  char rcv_4 = 0x00;
  
  setup();

  LCD_goto(0, 0);
  LCD_putstr("TXD1: ");
  LCD_goto(10, 0);
  LCD_putstr("RXD1: ");

  LCD_goto(0, 1);
  LCD_putstr("TXD4: ");
  LCD_goto(10, 1);
  LCD_putstr("RXD4: ");

  while(1)
  {   
    for(i = 0; i < 10; i++)
    {     
      UART1_write_buffer(msg1[i]);
      UART4_write_buffer(msg2[i]);  
      
      LCD_goto(5, 0);
      LCD_putchar(msg1[i]);
      LCD_goto(5, 1);
      LCD_putchar(msg2[i]);
      
      rcv_1 = UART1_read_buffer();  
      rcv_4 = UART4_read_buffer();

      LCD_goto(15, 0);
      LCD_putchar(rcv_1);      
      LCD_goto(15, 1);
      LCD_putchar(rcv_4);
      
      delay_ms(900);
    }
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  UART1_pin_option(0xC0);
  UART1_init(9600, \
             UART1_baud_source_TMR2, \
             UART1_timer_12T, \
             12000000);
  
  UART4_pin_option(0x04);
  UART4_init(9600, \
             UART4_baud_source_TMR4, \
             UART4_timer_1T, \
             12000000);

  LCD_init();
  LCD_clear_home();
}