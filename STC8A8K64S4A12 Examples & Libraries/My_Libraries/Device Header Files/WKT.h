//  (10^6 / 32k) * 16 * (WKTCL + 1) = Wakeup Time Interval in microseconds

#define WKT_set_interval(value)             do{ \
                                                WKTCH |= ((value & 0x7F) >> 7); \
                                                WKTCL = (value & 0x00FF); \
                                              }while(0)

#define WKT_enable                          bit_set(WKTCH, 7)
#define WKT_disable                         bit_clr(WKTCH, 7)

#define Go_to_Power_Down_State              bit_set(PCON, 1)


