#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"


void setup(void);


void main(void)
{
  unsigned int ADC_count = 0x0000;
  float voltage = 0.0;

  setup();

  LCD_goto(0, 0);
  LCD_putstr("CH0/V:");

  LCD_goto(0, 1);
  LCD_putstr("CH1/V:");

  while(1)
  {
    ADC_count = ADC_get_result(CH0);
    voltage = (((float)ADC_count * 5.0) / 4095.0);
    print_F(10, 0, voltage, 3);
    
    ADC_count = ADC_get_result(CH1);
    voltage = (((float)ADC_count * 5.0) / 4095.0);
    print_F(10, 1, voltage, 3);
    
    delay_ms(400);
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 4, MCLK_SYSCLK_no_output, MCLK_out_P54);

  P10_input_mode;
  P11_input_mode;

  ADC_enable;
  ADC_result_format_right_aligned;
  ADC_set_conversion_speed(ADC_conv_256_CLKs);

  LCD_init();
  LCD_clear_home();
}