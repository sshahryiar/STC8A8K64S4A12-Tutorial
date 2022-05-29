#include "STC8xxx.h"
#include "BSP.h"


#define freq_change         (12000000L / 2 /38400)


unsigned int value = freq_change;


void setup(void);


void PCA_ISR(void)          
interrupt 7
{
  clear_PCA_0_flag;
  PCA0_load_value(value);
  value += freq_change;
}


void main(void)
{

  setup();
	
	while(1)
	{
    if(P52_get_input == FALSE)
		{
			P24_high;
      P55_low;
		}
    
    else
		{
			P24_low;
      P55_high;
		}
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
 
  P01_push_pull_mode;
  P55_open_drain_mode;
	
	P52_input_mode;
	P52_pull_up_enable;
  
  PCA_pin_option(0x10);
  
  PCA_setup(PCA_continue_counting_in_idle_mode, PCA_clk_sys_clk_div_1);
  
  PCA_0_mode(PCA_16_bit_high_speed_pulse_output);
    
  PCA_load_counter(0);
  PCA0_load_value(value);
  
  _enable_PCA_0_interrupt;
  _enable_global_interrupt;
  
  PCA_start_counter;
}


