#include "STC8xxx.h"
#include "BSP.h"


#define servo_min_duty     800
#define servo_max_duty    2200
#define step_change          5


void setup(void);
void PWM_idle(void);


void main(void)
{	
  unsigned int i = 0x0000;
  
  setup();
	
	while(1)
	{
    for(i = servo_min_duty; i < servo_max_duty; i += step_change)
    {
      PWM_set_PWM0_T1(i);  
      delay_ms(4);
    }
    
    for(i = servo_max_duty; i > servo_min_duty; i -= step_change)
    {
      PWM_set_PWM0_T1(i);  
      delay_ms(4);
    }
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
 
  PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_12);
  
  PWM_set_counter(20000);
  
  PWM0_setup(PWM_pin_is_PWM_output, \
             PWM_init_lvl_low, \
             PWM_0_pin_P20, \
             PWM_level_normal);
              
  PWM_set_PWM0_T1(1000);
  PWM_set_PWM0_T2(0);  
  
  PWM_start_counter;
}


