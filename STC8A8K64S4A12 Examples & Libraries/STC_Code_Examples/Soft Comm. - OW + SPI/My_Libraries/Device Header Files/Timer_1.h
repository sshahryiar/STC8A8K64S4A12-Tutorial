/* Timer 1 */

//mode
#define TMR1_16_bit_auto_reload                         0x00
#define TMR1_16_bit_non_auto_reload                     0x10
#define TMR1_8_bit_auto_reload                          0x20
#define TMR1_stopped                                    0x30

//clk_src
#define TMR1_sysclk                                     0x00
#define TMR1_ext_T1_P35_clk                             0x40

//clk_ps
#define TMR1_clk_prescalar_12T                          0x00
#define TMR1_clk_prescalar_1T                           0x40

//gate
#define TMR1_int_gate                                   0x00
#define TMR1_ext_gate                                   0x80

//out
#define TMR1_no_clk_out                                 0x00
#define TMR1_P34_clk_out                                0x02

#define TMR1_clear                                      do{TMOD &= 0x0F;}while(0)


#define TMR1_setup(mode, clk_src, clk_ps, gate, out)    do{ \
                                                            AUXR &= 0xBF; \
                                                            AUXR |= clk_ps; \
                                                            INTCLKO &= 0xFD; \
                                                            INTCLKO |= out; \       
                                                            TMR1_clear; \
                                                            TMOD |= (mode | clk_src | gate); \
                                                          }while(0)


#define TMR1_start                                      bit_set(TCON, 6)
#define TMR1_stop                                       bit_clr(TCON, 6)


#define TMR1_load_counter_8(HB, LB)                     do{ \
                                                            TL1 = LB; \
                                                            TH1 = HB; \
                                                          }while(0)

#define TMR1_load_counter_16(value)                     do{ \
                                                            TL1 = (value & 0x00FF); \
                                                            TH1 = (value >> 0x08); \
                                                          }while(0)

unsigned int TMR1_get_counter(void)
{
    unsigned int tmp = 0x0000;

    tmp = TH1;
    tmp <<= 8;
    tmp |= TL1;

    return tmp;
}  
