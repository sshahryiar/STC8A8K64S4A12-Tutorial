#include <intrins.h>


#define osc_freq_in_MHz                12.0
#define osc_scalar                     (12.0 / osc_freq_in_MHz) 


void delay_us(unsigned int value)
{
  value = ((float)value / (float)osc_scalar);
  
  while(value > 0)
  {
		_nop_();
		value--;
  }
}


void delay_ms(unsigned int value)
{ 
  while(value > 0)
  {
    --value;
    delay_us(1000);
  }
}