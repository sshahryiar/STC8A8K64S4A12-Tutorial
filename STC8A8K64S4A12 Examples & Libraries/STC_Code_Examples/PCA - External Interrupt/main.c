#include "STC8xxx.h"
#include "BSP.h"


void setup(void);


void PCA_ISR(void)          
interrupt 7
{
  if(check_PCA_0_flag)
  {
    clear_PCA_0_flag;
    P54_low;
  }
  if(check_PCA_1_flag)
  {
    clear_PCA_1_flag;
    P54_high;
  }  
  
}


void main(void)
{

  setup();
	
	while(1)
	{
    P55_toggle;
    delay_ms(400);
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);

  P54_push_pull_mode;
  P55_open_drain_mode;
  
  PCA_pin_option(0x00);
  
  PCA_setup(PCA_continue_counting_in_idle_mode, PCA_clk_sys_clk_div_1);
  
  PCA_0_mode(PCA_16_bit_falling_edge_capture);
  PCA_1_mode(PCA_16_bit_falling_edge_capture);
    
  PCA_load_counter(0);
  
  _enable_PCA_0_interrupt;
  _enable_PCA_1_interrupt;
  _enable_global_interrupt;
  
  PCA_start_counter;
}


