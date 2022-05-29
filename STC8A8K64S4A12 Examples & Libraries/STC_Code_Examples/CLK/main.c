#include "STC8xxx.h"
#include "BSP.h"


void setup(void);
void toggle(void);


void main(void)
{

	setup();
	
	while(1)
	{
        
	};
}


void setup(void)
{
    P55_open_drain_mode;
    
    CLK_set_sys_clk(IRC_24M, 4, MCLK_SYSCLK_div_1, MCLK_out_P54);
    toggle();
    
    CLK_set_sys_clk(IRC_24M, 6, MCLK_SYSCLK_div_8, MCLK_out_P54);
    toggle();
    
    CLK_set_sys_clk(IRC_24M, 24, MCLK_SYSCLK_div_1, MCLK_out_P54);
    toggle();
    
    CLK_set_sys_clk(IRC_32k, 1, MCLK_SYSCLK_div_1, MCLK_out_P54);
    toggle();
}


void toggle(void)
{
    unsigned char i = 10;
    
    while(i > 0)
    {
        P55_toggle;
        delay_ms(60);
        i--;
    };
}
