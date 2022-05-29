#include "STC8xxx.h"
#include "BSP.h"


#define T_Load         (1000000L / 12 / 2)


unsigned int value = T_Load;


void setup(void);


void PCA_ISR(void)          
interrupt 7
{
  clear_PCA_0_flag;
  PCA0_load_value(value);
  P55_toggle;
  value += T_Load;
}


void main(void)
{

  setup();
	
	while(1)
	{
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 24, MCLK_SYSCLK_no_output, MCLK_out_P54);
 
  P55_open_drain_mode;
  
  PCA_pin_option(0x10);
  
  PCA_setup(PCA_continue_counting_in_idle_mode, PCA_clk_sys_clk_div_12);
  
  PCA_0_mode(PCA_16_bit_software_timer);
    
  PCA_load_counter(0);
  PCA0_load_value(T_Load);
  
  _enable_PCA_0_interrupt;
  _enable_global_interrupt;
  
  PCA_start_counter;
}


