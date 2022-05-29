#include "STC8xxx.h"
#include "BSP.h"


void setup(void);
    


void main(void)
{
    unsigned char i = 0;
  
    setup();
    
    while(1)
    {
        P11_toggle;
        
        if(P52_get_input == FALSE)
        {
            for(i = 0; i <= 9; i++)
            {
              P10_toggle;
              delay_ms(100); 
            }
            
            while(1);
        }
        
        delay_ms(200);   
        WDT_reset;        
    };
}


void setup(void)
{
    CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
    
    P52_input_mode;
  	P52_pull_up_enable;
  
    P10_push_pull_mode;
    P11_push_pull_mode;  

    WDT_setup(WDT_continue_counting_in_idle_mode, WDT_div_factor_32);
}