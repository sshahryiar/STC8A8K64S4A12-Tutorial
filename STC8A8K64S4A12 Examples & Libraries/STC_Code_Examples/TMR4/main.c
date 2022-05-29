#include "STC8xxx.h"
#include "BSP.h"


void setup(void);


void main(void)
{	
	setup();
	
	while(1)
	{
      if(TMR4_get_counter() >= 0x9E58)
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
	CLK_set_sys_clk(IRC_24M, 24, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  P55_open_drain_mode;
	
  TMR4_setup(TMR4_sysclk, \
             TMR4_clk_prescalar_12T, \
             TMR4_no_clk_out);
  
  TMR4_load_counter_16(0x3CB0);
  TMR4_start;
}
