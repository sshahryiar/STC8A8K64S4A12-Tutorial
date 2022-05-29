/* Timer 2 */

//Mode = 16 bit auto-reload

//clk_src
#define TMR2_sysclk                                     0x00
#define TMR2_ext_T2_P12_clk                             0x08

//clk_ps
#define TMR2_clk_prescalar_12T                          0x00
#define TMR2_clk_prescalar_1T                           0x04

#define TMR2_clear                                      do{AUXR &= 0xF3;}while(0)


#define TMR2_setup(clk_src, clk_ps)                     do{ \
                                                            TMR2_clear; \
                                                            AUXR |= (clk_src | clk_ps); \
                                                          }while(0)


#define TMR2_start                                      bit_set(AUXR, 4)
#define TMR2_stop                                       bit_clr(AUXR, 4)


#define TMR2_load_counter_8(HB, LB)                     do{ \
                                                            T2L = LB; \
                                                            T2H = HB; \
                                                          }while(0)

#define TMR2_load_counter_16(value)                     do{ \
                                                            T2L = (value & 0x00FF); \
                                                            T2H = (value >> 0x08); \
                                                          }while(0)

unsigned int TMR2_get_counter(void)
{
    unsigned int tmp = 0x0000;

    tmp = T2H;
    tmp <<= 8;
    tmp |= T2L;

    return tmp;
}  
