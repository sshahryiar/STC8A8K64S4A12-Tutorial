/* Timer 3 */

//clk_src
#define TMR3_sysclk                                     0x00
#define TMR3_ext_T3_P04_clk                             0x04

//clk_ps
#define TMR3_clk_prescalar_12T                          0x00
#define TMR3_clk_prescalar_1T                           0x02

//out
#define TMR3_no_clk_out                                 0x00
#define TMR3_P05_clk_out                                0x01

#define TMR3_clear                                      do{T4T3M &= 0xF8;}while(0)


#define TMR3_setup(clk_src, clk_ps, out)                do{ \
                                                            TMR3_clear; \
                                                            T4T3M |= (clk_src | clk_ps | out); \
                                                          }while(0)


#define TMR3_start                                      bit_set(T4T3M, 3)
#define TMR3_stop                                       bit_clr(T4T3M, 3)


#define TMR3_load_counter_8(HB, LB)                     do{ \
                                                            T3L = LB; \
                                                            T3H = HB; \
                                                          }while(0)

#define TMR3_load_counter_16(value)                     do{ \
                                                            T3L = (value & 0x00FF); \
                                                            T3H = (value >> 0x08); \
                                                          }while(0)

unsigned int TMR3_get_counter(void)
{
    unsigned int tmp = 0x0000;

    tmp = T3H;
    tmp <<= 8;
    tmp |= T3L;

    return tmp;
}
