#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"


#define BASE_ADDRESS  0x0400


void setup(void);


void main(void)
{
  unsigned char i = 0;

  setup();
  
  LCD_goto(0, 0); 
	LCD_putstr("R Addr:");
	LCD_goto(0, 1); 
	LCD_putstr("R Data:");
  
	i = IAP_read(BASE_ADDRESS);
	delay_ms(10);
	print_I(11, 0, BASE_ADDRESS);
	print_C(14, 1, i);
		
	delay_ms(2000);
	
  if(i == 0)
  {
    LCD_clear_home();
    LCD_goto(0, 0); 
    LCD_putstr("Performing Erase");
    LCD_goto(0, 1); 
    LCD_putstr("....");
    IAP_erase(BASE_ADDRESS); 
    delay_ms(1000);
  } 
  
  LCD_clear_home();
  delay_ms(100);
  
	LCD_goto(0, 0); 
	LCD_putstr("W Addr:");
	LCD_goto(0, 1); 
	LCD_putstr("W Data:");

  i = (P1 & 0x03);
	IAP_write(BASE_ADDRESS, i);
	print_I(11, 0, BASE_ADDRESS);    
	print_C(14, 1, i);

  delay_ms(2000);
  
  LCD_clear_home();
  delay_ms(100);
  
  LCD_goto(0, 0); 
	LCD_putstr("R Addr:");
	LCD_goto(0, 1); 
	LCD_putstr("R Data:");
  
	i = IAP_read(BASE_ADDRESS);
	delay_ms(10);
	print_I(11, 0, BASE_ADDRESS);
	print_C(14, 1, i);
		
	delay_ms(2000);
  
  
  while(1)
  {

  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_div_1, MCLK_out_P54);

  P10_input_mode;
  P11_input_mode;
  
  LCD_init();
  LCD_clear_home();
}