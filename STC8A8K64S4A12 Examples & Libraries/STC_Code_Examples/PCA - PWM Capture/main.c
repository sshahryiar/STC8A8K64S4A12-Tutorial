#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"


unsigned char state = 0x00;
unsigned int pulse_width = 0x0000;


void setup(void);


void PCA_ISR(void)          
interrupt 7
{   
  if(check_PCA_0_flag)
  {
    state ^= 1;
    clear_PCA_0_flag;
  }
  
  switch(state)
  {
    case 1:
    {
      PCA_load_counter(0x0000);
      break;    
    }
    
    default:
    {  
      pulse_width = PCA_get_CCAP0();
      break;
    }
  }
}


void main(void)
{
  float range = 0.0;
  
  setup();

  LCD_goto(0, 0); 
  LCD_putstr("Range/cm:"); 
  LCD_goto(0, 1); 
  LCD_putstr("Pulse/us:");  

  while(1)
  {
    P55_low;
    delay_ms(10);
    
    P16_high; 
    delay_us(10); 
    P16_low; 
    P55_high;
    
    range = ((((float)pulse_width) / 58.0)); 
    print_F(10, 0, range, 1); 
    print_I(10, 1, pulse_width);
    
    delay_ms(490);
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);

  P16_push_pull_mode;
  P55_open_drain_mode;
  
  PCA_pin_option(0x00);
  
  PCA_setup(PCA_continue_counting_in_idle_mode, PCA_clk_sys_clk_div_12);
  PCA_load_counter(0x0000);
  
  PCA_0_mode(PCA_16_bit_both_edge_capture);
  
  _enable_PCA_0_interrupt;
  _enable_global_interrupt;  
  
  PCA_start_counter;
  
  LCD_init();
  LCD_clear_home();
}