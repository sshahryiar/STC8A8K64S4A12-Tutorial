#include "STC8xxx.h"
#include "BSP.h"


void setup(void);
    


void main(void)
{
    unsigned char i = 0;
    setup();
    
    while(1)
    {
      WKT_disable;
      
      for(i = 0; i <= 15; i++)  
      {
        P55_toggle;
        delay_ms(100);
      }
      
      WKT_enable;
      Go_to_Power_Down_State;
      
    };
}


void setup(void)
{
    CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
    
    P55_open_drain_mode;
	  
    WKT_set_interval(9000);
    
}