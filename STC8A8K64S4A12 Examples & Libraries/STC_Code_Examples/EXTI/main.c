#include "STC8xxx.h"
#include "BSP.h"


unsigned char s = 0;
unsigned int i = 0;


void setup(void);
    

void EXT_0_ISR(void)        
interrupt 0 
{
    for(s = 0; s <= 9; s++)
    {
        P55_toggle;
        for(i = 0; i < 10000; i++);
    }
}


void EXT_1_ISR(void)        
interrupt 2
{
    for(s = 0; s <= 9; s++)
    {
        P55_toggle;
        for(i = 0; i < 30000; i++);
    }
}


void main(void)
{
    setup();
    
    while(1)
    {
        P55_low;        
    };
}


void setup(void)
{
    CLK_set_sys_clk(IRC_24M, 24, MCLK_SYSCLK_no_output, MCLK_out_P54);
    
    P55_open_drain_mode;
	        
    EXT_0_priority_0;
    EXT_0_falling_edge_detection_only;
    _enable_EXT_0_interrupt;
       
    EXT_1_priority_1;
    EXT_1_falling_edge_detection_only;
    _enable_EXT_1_interrupt;
    
    _enable_global_interrupt;
}