#include "STC8xxx.h"
#include "BSP.h"


void setup(void);


void main(void)
{	
	setup();
	
	while(1)
	{
    if(TMR1_get_counter() >= 32768)
    {
      P55_high;
    }
    else
    {
      P55_low;
    }    
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  P34_push_pull_mode;
 
  P35_input_mode;
  
	P55_open_drain_mode;
  
  TMR1_setup(TMR1_16_bit_non_auto_reload, \
             TMR1_ext_T1_P35_clk, \
             TMR1_clk_prescalar_12T, \
             TMR1_int_gate, \
             TMR1_P34_clk_out);
  
  TMR1_load_counter_8(0x00, 0x00);
  
  TMR1_start;
}
