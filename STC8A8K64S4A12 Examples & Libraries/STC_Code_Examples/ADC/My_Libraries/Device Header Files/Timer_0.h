/* Timer 0 */

//mode
#define TMR0_16_bit_auto_reload                         0x00
#define TMR0_16_bit_non_auto_reload                     0x01
#define TMR0_8_bit_auto_reload                          0x02
#define TMR0_16_bit_auto_reload_with_interrupt          0x03

//clk_src
#define TMR0_sysclk                                     0x00
#define TMR0_ext_T0_P34_clk                             0x04

//clk_ps
#define TMR0_clk_prescalar_12T                          0x00
#define TMR0_clk_prescalar_1T                           0x80

//gate
#define TMR0_int_gate                                   0x00
#define TMR0_ext_gate                                   0x08

//out
#define TMR0_no_clk_out                                 0x00
#define TMR0_P35_clk_out                                0x01

#define TMR0_clear                                      do{TMOD &= 0xF0;}while(0)


#define TMR0_setup(mode, clk_src, clk_ps, gate, out)    do{ \
                                                            AUXR &= 0x7F; \
                                                            AUXR |= clk_ps; \
                                                            INTCLKO &= 0xFE; \
                                                            INTCLKO |= out; \                
                                                            TMR0_clear; \
                                                            TMOD |= (mode | clk_src | gate); \
                                                          }while(0)


#define TMR0_start                                      bit_set(TCON, 4)
#define TMR0_stop                                       bit_clr(TCON, 4)


#define TMR0_load_counter_8(HB, LB)                     do{ \
                                                            TL0 = LB; \
                                                            TH0 = HB; \
                                                          }while(0)

#define TMR0_load_counter_16(value)                     do{ \
                                                            TL0 = (value & 0x00FF); \
                                                            TH0 = (value >> 0x08); \
                                                          }while(0)

unsigned int TMR0_get_counter(void)
{
    unsigned int tmp = 0x0000;

    tmp = TH0;
    tmp <<= 8;
    tmp |= TL0;

    return tmp;
}                                
