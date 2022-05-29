#include "DHT11.h"


extern unsigned char values[5] = {0x00, 0x00, 0x00, 0x00, 0x00}; 


void DHT11_init(void)
{
   DHT11_pin_init;
   delay_ms(1000);
}


unsigned char DHT11_get_byte(void)
{
   unsigned char s = 0x08;
   unsigned char value = 0x00;

   while(s > 0) 
   {
      value <<= 1;
      while(DHT11_pin_IN == LOW);
      large_delay_TMR_0(30);

      if(DHT11_pin_IN == HIGH)
      {
          value |= 1;
      }
      
      while(DHT11_pin_IN == HIGH);
      s--;
   }
   return value;
}


unsigned char DHT11_get_data(void)
{
   unsigned char s = 0;
   unsigned char check_sum = 0;

   DHT11_pin_HIGH;
   DHT11_pin_LOW;
   large_delay_TMR_0(18000);
   DHT11_pin_HIGH;
   large_delay_TMR_0(26);
   
   if(DHT11_pin_IN == HIGH)
   {
      return 1;
   }
   
   large_delay_TMR_0(80);
   
   if(DHT11_pin_IN == LOW)
   {
      return 2;
   }
   
   large_delay_TMR_0(80);

   for(s = 0; s <= 4; s++)
   {
       values[s] = DHT11_get_byte();
   }
  
   DHT11_pin_HIGH; 
   
   for(s = 0; s < 4; s++)
   {
       check_sum += values[s];
   }
   
   if(check_sum != values[4])
   {
      return 3;
   }
   else
   {
      return 0;
   }
}
