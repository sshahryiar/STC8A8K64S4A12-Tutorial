#include "STC8xxx.h"
#include "BSP.h"


#define steps 33


void setup(void);
void PWM_idle(void);


void main(void)
{	
	signed char i = 0x00;
  signed char j = 0x00;

  const unsigned int duty1_value[steps] = {0, 950, 1892, 2817, 3717, 4582, 5407, 6182, 6901, 7558, 8146,
                                           8660, 9096, 9450, 9718, 9898, 9988, 9995, 9897, 9717, 9449, 9095,
                                           8658, 8144, 7555, 6898, 6179, 5403, 4579, 3713, 2813, 1888 ,946};

  const unsigned int duty2_value[steps] = {8658, 8144, 7555, 6898, 6179, 5403, 4579, 3713, 2813, 1888 ,946,
                                           0, 950, 1892, 2817, 3717, 4582, 5407, 6182, 6901, 7558, 8146,
                                           8660, 9096, 9450, 9718, 9898, 9988, 9995, 9897, 9717, 9449, 9095};

  const unsigned int duty3_value[steps] = {8660, 9096, 9450, 9718, 9898, 9988, 9995, 9897, 9717, 9449, 9095,
                                           8658, 8144, 7555, 6898, 6179, 5403, 4579, 3713, 2813, 1888 ,946,
                                           0, 950, 1892, 2817, 3717, 4582, 5407, 6182, 6901, 7558, 8146};
  
  setup();
	
	while(1)
	{
    for(j = 0; j < 6; j++)
    {
      for(i = 0; i < steps; i++)
      {
          PWM_set_PWM0_T2(duty1_value[i]);
          PWM_set_PWM1_T2(duty2_value[i]);
          PWM_set_PWM2_T2(duty3_value[i]);
          delay_ms(60);
      }
    }
    
    PWM_idle();
    
    for(j = 0; j < 6; j++)
    {
      for(i = 0; i < steps; i++)
      {
          PWM_set_PWM0_T2(duty1_value[i]);
          PWM_set_PWM1_T2(duty1_value[i]);
          PWM_set_PWM2_T2(duty1_value[i]);
          delay_ms(60);
      }
    }
    
    PWM_idle();
	};
}


void setup(void)
{
	CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
 
  PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_2);
  
  PWM_set_counter(10000);
  
  PWM0_setup(PWM_pin_is_PWM_output, \
             PWM_init_lvl_low, \
             PWM_0_pin_P10, \
             PWM_level_normal);
  
  PWM1_setup(PWM_pin_is_PWM_output, \
             PWM_init_lvl_low, \
             PWM_1_pin_P11, \
             PWM_level_normal);
             
  PWM2_setup(PWM_pin_is_PWM_output, \
             PWM_init_lvl_low, \
             PWM_2_pin_P12, \
             PWM_level_normal);
             
  PWM_set_PWM0_T1(0);
  PWM_set_PWM0_T2(0);
  
  PWM_set_PWM1_T1(0);
  PWM_set_PWM1_T2(0);
  
  PWM_set_PWM2_T1(0);
  PWM_set_PWM2_T2(0);
  
  
  PWM_start_counter;
}


void PWM_idle(void)
{
  PWM0_hold_level(PWM_HLD_L_low);
  PWM1_hold_level(PWM_HLD_L_low);
  PWM2_hold_level(PWM_HLD_L_low); 
  delay_ms(100);
  PWM0_hold_level(PWM_level_normal);
  PWM1_hold_level(PWM_level_normal);
  PWM2_hold_level(PWM_level_normal);  
  delay_ms(100);
}