#include "STC8xxx.h"
#include "BSP.h"


#define DAT_pin_HIGH                    P41_high
#define DAT_pin_LOW                     P41_low

#define CLK_pin_HIGH                    P42_high
#define CLK_pin_LOW                     P42_low

#define refresh_time_in_us              315
#define max_tmr_cnt                     0xFFFF
#define tmr_val                         (max_tmr_cnt - refresh_time_in_us)



const unsigned char pos[0x08] =
{
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
};


const unsigned char num[0x0A] =
{
    0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F, 0x01, 0x09
};


unsigned char i = 0x00;

signed int value_1 = 0;
signed int value_2 = 0;


void setup(void);
void Write_74HC164(unsigned char val, unsigned char seg);


void ADC_ISR(void)          
interrupt 5
{
  value_1 = ((ADC_RES << 8) | ADC_RESL);
  value_2 = ((value_1 * 5000.0) / 4096.0);
  clear_ADC_flag;
}


void TMR_2_ISR(void)        
interrupt 12
{
    switch(i)
    {
        case 0:
        {
            Write_74HC164(num[(value_1 / 1000)], pos[3]);
            break;
        }

        case 1:
        {
            Write_74HC164((num[((value_1 % 1000) / 100)]), pos[2]);
            break;
        }

        case 2:
        {
            Write_74HC164(num[((value_1 % 100) / 10)], pos[1]);
            break;
        }

        case 3:
        {
            Write_74HC164(num[(value_1 % 10)], pos[0]);
            break;
        }

        case 4:
        {
            Write_74HC164(num[(value_2 / 1000)] & 0xFE, pos[7]);
            break;
        }

        case 5:
        {
            Write_74HC164((num[((value_2 % 1000) / 100)]), pos[6]);
            break;
        }

        case 6:
        {
            Write_74HC164(num[((value_2 % 100) / 10)], pos[5]);
            break;
        }

        case 7:
        {
            Write_74HC164(num[(value_2 % 10)], pos[4]);
            break;
        }
    }

    i++;

    if(i >= 8)
    {
        i = 0;
    }

    clear_TMR_2_overflow_flag;
}  


void main(void)
{	 
  setup();
	
	while(1)
	{
    ADC_set_channel(CH15);
    delay_ms(10);
    ADC_start_conversion;
    delay_ms(400);
	};
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);
  
  P41_push_pull_mode;
  P42_push_pull_mode;
  
  ADC_enable;
  ADC_result_format_right_aligned;
  ADC_set_conversion_speed(ADC_conv_128_CLKs);
  _enable_ADC_interrupt;
  
  TMR2_setup(TMR2_sysclk, TMR2_clk_prescalar_12T);
  TMR2_load_counter_16(tmr_val);
  TMR2_start;
  _enable_TMR_2_interrupt;
  _enable_global_interrupt;
}



void Write_74HC164(unsigned char val, unsigned char seg)
{
    unsigned char s = 0x10;
    unsigned int temp = 0x0000;

    temp = (unsigned int)seg;
    temp <<= 8;
    temp |= (unsigned int)val;

    while(s > 0)
    {
        if((temp & 0x0001) != 0x0000)
        {
            DAT_pin_HIGH;
        }
        else
        {
            DAT_pin_LOW;
        }

        CLK_pin_HIGH;
        
        temp >>= 1;
        s--;
        
        CLK_pin_LOW;
    }
}