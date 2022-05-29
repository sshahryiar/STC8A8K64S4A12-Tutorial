/* Timer 4 */

//clk_src
#define TMR4_sysclk                                     0x00
#define TMR4_ext_T3_P06_clk                             0x40

//clk_ps
#define TMR4_clk_prescalar_12T                          0x00
#define TMR4_clk_prescalar_1T                           0x20

//out
#define TMR4_no_clk_out                                 0x00
#define TMR4_P07_clk_out                                0x10

#define TMR4_clear                                      do{T4T3M &= 0x8F;}while(0)


#define TMR4_setup(clk_src, clk_ps, out)                do{ \
                                                            TMR4_clear; \
                                                            T4T3M |= (clk_src | clk_ps | out); \
                                                          }while(0)


#define TMR4_start                                      bit_set(T4T3M, 7)
#define TMR4_stop                                       bit_clr(T4T3M, 7)


#define TMR4_load_counter_8(HB, LB)                     do{ \
                                                            T4L = LB; \
                                                            T4H = HB; \
                                                          }while(0)

#define TMR4_load_counter_16(value)                     do{ \
                                                            T4L = (value & 0x00FF); \
                                                            T4H = (value >> 0x08); \
                                                          }while(0)

unsigned int TMR4_get_counter(void)
{
    unsigned int tmp = 0x0000;

    tmp = T4H;
    tmp <<= 8;
    tmp |= T4L;

    return tmp;
}  

