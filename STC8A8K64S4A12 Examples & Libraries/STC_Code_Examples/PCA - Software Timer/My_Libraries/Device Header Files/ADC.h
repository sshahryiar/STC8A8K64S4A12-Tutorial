#define CH0                                  0x00    //P1.0
#define CH1                                  0x01    //P1.1
#define CH2                                  0x02    //P1.2
#define CH3                                  0x03    //P1.3
#define CH4                                  0x04    //P1.4
#define CH5                                  0x05    //P1.5
#define CH6                                  0x06    //P1.6
#define CH7                                  0x07    //P1.7
#define CH8                                  0x08    //P0.0
#define CH9                                  0x09    //P0.1
#define CH10                                 0x0A    //P0.2
#define CH11                                 0x0B    //P0.3
#define CH12                                 0x0C    //P0.4
#define CH13                                 0x0D    //P0.5
#define CH14                                 0x0E    //P0.6
#define CH15                                 0x0F    //Internal 1.344V reference source

#define ADC_set_channel(ch)                  do{ \
                                                  ADC_CONTR &= 0xF0; \
                                                  ADC_CONTR |= ch; \
                                               }while(0)

#define ADC_enable                           bit_set(ADC_CONTR, 7)
#define ADC_disable                          bit_clr(ADC_CONTR, 7)

#define ADC_start_conversion                 bit_set(ADC_CONTR, 6)

#define ADC_result_format_left_aligned       bit_clr(ADCCFG, 5)        
#define ADC_result_format_right_aligned      bit_set(ADCCFG, 5)    


#define ADC_conv_32_CLKs                     0x00
#define ADC_conv_64_CLKs                     0x01
#define ADC_conv_96_CLKs                     0x02
#define ADC_conv_128_CLKs                    0x03
#define ADC_conv_160_CLKs                    0x04
#define ADC_conv_192_CLKs                    0x05
#define ADC_conv_224_CLKs                    0x06
#define ADC_conv_256_CLKs                    0x07
#define ADC_conv_288_CLKs                    0x08
#define ADC_conv_320_CLKs                    0x09
#define ADC_conv_352_CLKs                    0x0A
#define ADC_conv_384_CLKs                    0x0B
#define ADC_conv_416_CLKs                    0x0C
#define ADC_conv_448_CLKs                    0x0D
#define ADC_conv_480_CLKs                    0x0E
#define ADC_conv_512_CLKs                    0x0F

#define ADC_set_conversion_speed(spd)        do{ \
                                                  ADCCFG &= 0xF0; \
                                                  ADCCFG |= spd; \
                                               }while(0)

#define ADC_clear                            do{ \
                                                  ADC_CONTR = 0x00; \
                                                  ADC_CFG = 0x00; \
                                               }while(0)  


unsigned int ADC_get_result(unsigned char channel)
{
    register unsigned int value = 0x0000;
       
    ADC_set_channel(channel);
    delay_ms(1);

    ADC_start_conversion;
    while(!check_ADC_flag);
    clear_ADC_flag;  
  
    value = ((ADC_RES << 8) | ADC_RESL);
  
    return value;
}