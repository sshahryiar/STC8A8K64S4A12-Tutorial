/*
    Watchdog Overflow Time = ((12 * 32768 * 2^(WDT_PS + 1)) / Sysclk)
*/


#define WDT_div_factor_2                        0x00
#define WDT_div_factor_4                        0x01
#define WDT_div_factor_8                        0x02
#define WDT_div_factor_16                       0x03
#define WDT_div_factor_32                       0x04
#define WDT_div_factor_64                       0x05
#define WDT_div_factor_128                      0x06
#define WDT_div_factor_256                      0x07

#define WDT_set_prescalar(value)                do{ \
                                                    WDT_CONTR &= 0xF8; \
                                                    WDT_CONTR |= value; \
                                                  }while(0)

//CNT_mode
#define WDT_stop_counting_in_idle_mode          0x00
#define WDT_continue_counting_in_idle_mode      0x08


#define WDT_start                               bit_set(WDT_CONTR, 5)

#define WDT_get_overflow_flag                   get_bit(WDT_CONTR, 7)
#define WDT_clear_overflow_flag                 bit_set(WDT_CONTR, 7)

#define WDT_reset                               bit_set(WDT_CONTR, 4)


#define WDT_clear                               do{ \
                                                    WDT_CONTR = 0x00; \
                                                  }while(0)


#define WDT_setup(CNT_mode, PS)                 do{ \
                                                    WDT_clear; \
                                                    WDT_CONTR |= CNT_mode; \
                                                    WDT_set_prescalar(PS); \
                                                  }while(0)
                                                   