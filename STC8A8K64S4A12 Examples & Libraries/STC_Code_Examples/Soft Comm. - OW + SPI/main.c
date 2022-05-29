#include "STC8xxx.h"
#include "BSP.h"
#include "DHT11.c"
#include "SSD1306.c"


void setup(void);


void main(void)
{
  unsigned char state = 0x00;
  
  setup();
  
  OLED_print_string(24, 0, "Temp/Deg C");  
  OLED_print_string(24, 4, "Rel.Hum /%");

  while(1)
  {                                    
    state = DHT11_get_data();
      
    switch(state)
    {
			case 1:
			{
			}
			case 2:
			{
				 OLED_print_string(56, 2, "   ");
         OLED_print_string(56, 6, "   ");
				 break;
			}
			case 3:
			{
				 OLED_print_string(56, 2, "--");
         OLED_print_string(56, 6, "--");
				 break;
			}
			default:
			{         
         OLED_print_chr(55, 2, values[2]);
         OLED_print_chr(55, 6, values[0]);
				 break;
			}
    }
    
    delay_ms(1000);
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  DHT11_init();
  OLED_init();
}