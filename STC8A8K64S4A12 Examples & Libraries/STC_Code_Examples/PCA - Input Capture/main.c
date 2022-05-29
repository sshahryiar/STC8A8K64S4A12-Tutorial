#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"


unsigned int first_edge = 0x0000;
unsigned int second_edge = 0x0000;

unsigned long clks = 0x00000000;
unsigned long ov_cnt = 0x00000000;


void setup(void);


void PCA_ISR(void)          
interrupt 7
{
    if(check_PCA_Counter_overflow_flag)
    {
      ov_cnt++;;
      clear_PCA_Counter_overflow_flag;
    }
    
    if(check_PCA_0_flag)
    {
      second_edge = PCA_get_CCAP0();
      clks = ((65536*ov_cnt) + second_edge - first_edge);
      ov_cnt = 0;
      first_edge = second_edge;
      second_edge = 0;
      clear_PCA_0_flag;
    }
}


void main(void)
{
  float f = 0.0;
  
  unsigned char s = 0;
  
  setup();

  LCD_goto(0, 0);
  LCD_putstr("Period/ms:");
  
  LCD_goto(0, 1);
  LCD_putstr("Freq./kHz:");

  while(1)
  {
    PWM_stop_counter;
 
    switch(s)
    {
      case 1:
      {
        PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_1);  
        break;
      }
      
      case 2:
      {
        PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_4);      
        break;
      }
      
      case 3:
      {
        PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_3);  
        break;
      }      
      
      default:
      {
        PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_2);  
        break;
      }
    }
    PWM_start_counter;
    delay_ms(1000);
    
    f = (12000.0 / ((float)clks));
    print_I(11, 0, clks);  
    print_F(11, 1, f, 1);
    
    delay_ms(1000);
    
    s++;
    if(s > 3)
    {
      s = 0;
    }
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  PWM0_setup(PWM_pin_is_PWM_output, \
                   PWM_init_lvl_low, \
                   PWM_0_pin_P10, \
                   PWM_level_normal);
  
  PWM_clk_set(PWM_clk_sys_PS, PWM_clk_ps_sys_clk_div_2);  
  PWM_set_counter(500);  
        
  PWM_set_PWM0_T1(0);
  PWM_set_PWM0_T2(200); 
  
  PWM_start_counter;

  PCA_pin_option(0x00);
  
  PCA_setup(PCA_continue_counting_in_idle_mode, PCA_clk_sys_clk_div_1);
  PCA_load_counter(0x0000);
  
  PCA_0_mode(PCA_16_bit_falling_edge_capture);
  
  _enable_PCA_0_interrupt;
  _enable_PCA_counter_interrupt;
  _enable_global_interrupt;  
  
  PCA_start_counter;
  
  LCD_init();
  LCD_clear_home();
}