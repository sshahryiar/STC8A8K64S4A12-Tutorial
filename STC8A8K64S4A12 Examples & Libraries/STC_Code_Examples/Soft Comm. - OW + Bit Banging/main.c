#include "STC8xxx.h"
#include "BSP.h"
#include "DS18B20.c"
#include "TM1637.c"


void setup(void);


void main(void)
{
  signed long t = 0;
  
  setup();


  while(1)
  {                                    
    t = ((signed long)DS18B20_get_temperature());                                                                                                                       
                                                                         
    if((t > 999) && (t >= 0))                                                                                                                    
    {
        TM1637_display_segments(0, 0x40, 0);                              
        TM1637_display_segments(1, 0x40, 0);        
    }                                                                                             
      
    else
    {
        TM1637_display_segments(0, seg_data[(t / 10)], 0);
        TM1637_display_segments(1, seg_data[(t % 10)], 0);          
    }   
    
    TM1637_display_segments(2, 0x63, 0);      
    TM1637_display_segments(3, 0x39, 0);                                                              
    
    delay_ms(600); 
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  TM1637_init();
  DS18B20_init();
}