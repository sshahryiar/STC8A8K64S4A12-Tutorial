#include "STC8xxx.h"
#include "BSP.h"


#define dead_time_cnt               1
#define pwm_max_cnt                 400 

#define PB_1                        !P12_get_input
#define PB_2                        !P13_get_input


void setup(void);
void set_PWM_duty(signed int value);


void main(void)
{	
  signed int duty = 0;
  
  setup();
	
	while(1)
	{
      if(PB_1)
      {
          duty += 10;
          delay_ms(100);
          
          if(duty >= pwm_max_cnt)
          {
            duty = pwm_max_cnt;
          }
      }
      if(PB_2)
      {
          duty -= 10;
          delay_ms(100);
          
          if(duty <= 0)
          {
            duty = 0;
          }
      }
      if(PB_1 || PB_2)
      {
        set_PWM_duty(duty);
      }
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  P12_input_mode;
  P13_input_mode;
  
  PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_1);
  
  PWM_set_counter(pwm_max_cnt);
  
  PWM0_setup(PWM_pin_is_PWM_output, \
             PWM_init_lvl_low, \
             PWM_0_pin_P10, \
             PWM_level_normal);
  
  PWM1_setup(PWM_pin_is_PWM_output, \
             PWM_init_lvl_low, \
             PWM_1_pin_P11, \
             PWM_level_normal);   
  
  PWM_start_counter;
}


void set_PWM_duty(signed int value)
{ 
  PWM_set_PWM0_T1(value);
  PWM_set_PWM0_T2(0);
  
  PWM_set_PWM1_T1(pwm_max_cnt - dead_time_cnt);
  PWM_set_PWM1_T2(value + dead_time_cnt);     
}


