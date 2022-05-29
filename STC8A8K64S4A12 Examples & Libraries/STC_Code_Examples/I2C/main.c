#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"
#include "DHT12.c"


void setup(void);


void main(void)
{
  unsigned char state = 0x00;
	
	float T = 0.0;
	float RH = 0.0;
  
  setup();
	
	LCD_goto(0, 0);
	LCD_putstr("R.H / %:");
	LCD_goto(0, 1);
	LCD_putstr("Temp/ C:");
	print_symbol(5, 1, 0);
	
	while(1)
	{
	    state = DHT12_get_data(&RH, &T);
		
			switch(state)
			{
				case no_error:
				{
					print_F(11, 0, RH, 1);
          print_F(11, 1, T, 1);
					break;
				}
				
				default:
				{
					LCD_goto(12, 0);
					LCD_putstr("--.-");
					LCD_goto(12, 1);
					LCD_putstr("--.-");
				}
			}
			
			P55_toggle;
			delay_ms(400);
	};
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);

  P55_open_drain_mode;

  LCD_init();
  LCD_clear_home();
  load_custom_symbol();
  
  DHT12_init();
}