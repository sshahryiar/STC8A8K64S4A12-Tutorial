#include "STC8xxx.h"
#include "BSP.h"


void setup(void);
void PWM_idle(void);


void main(void)
{
  signed int j = 0x0000;
  
  setup();
	
	while(1)
	{
    for(j = 0; j < 256; j++)
    {
      PCA_0_8_bit_PWM_reload_value(255 - j);
      PCA_1_8_bit_PWM_reload_value(j);
      PCA_2_8_bit_PWM_reload_value(255 - j);
      PCA_3_8_bit_PWM_reload_value(j);
      delay_ms(10);
    }     
      
    for(j = 255; j > -1; j--)
    {
      PCA_0_8_bit_PWM_reload_value(255 - j);
      PCA_1_8_bit_PWM_reload_value(j);
      PCA_2_8_bit_PWM_reload_value(255 - j);
      PCA_3_8_bit_PWM_reload_value(j);
      delay_ms(10);
    }     
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
 
  PCA_pin_option(0x10);
  
  PCA_setup(PCA_continue_counting_in_idle_mode, PCA_clk_sys_clk_div_1);
  
  PCA_n_PWM(0, PCA_PWM_without_interrupt, PCA_8_bit_PWM);
  PCA_n_PWM(1, PCA_PWM_without_interrupt, PCA_8_bit_PWM);
  PCA_n_PWM(2, PCA_PWM_without_interrupt, PCA_8_bit_PWM);
  PCA_n_PWM(3, PCA_PWM_without_interrupt, PCA_8_bit_PWM);
  
  PCA_0_8_bit_PWM_compare_value(0);	
  PCA_0_8_bit_PWM_reload_value(0);	
  
  PCA_1_8_bit_PWM_compare_value(0);	
  PCA_1_8_bit_PWM_reload_value(0);	
  
  PCA_2_8_bit_PWM_compare_value(0);	
  PCA_2_8_bit_PWM_reload_value(0);	
  
  PCA_3_8_bit_PWM_compare_value(0);	
  PCA_3_8_bit_PWM_reload_value(0);	
  
  PCA_load_counter(0);
  
  PCA_start_counter;
}


