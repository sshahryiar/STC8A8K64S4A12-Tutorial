#define CLK_enable_IRC24_M                                          do{ \
                                                                          IRC24MCR = 0x80; \
                                                                          while((IRC24MCR & 0x01) == FALSE); \
                                                                      }while(0)

#define CLK_disable_IRC24_M                                         do{ \
                                                                          bit_set(P_SW2, 7);  \
                                                                          IRC24MCR = 0x00; \
                                                                          bit_clr(P_SW2, 7);  \
                                                                      }while(0)

#define CLK_enable_IRC32_k                                          do{ \
                                                                          IRC32KCR = 0x80; \
                                                                          while((IRC32KCR & 0x01) == FALSE); \
                                                                      }while(0)

#define CLK_disable_IRC32_k                                         do{ \
                                                                         bit_set(P_SW2, 7);  \
                                                                         IRC32KCR = 0x00; \
                                                                         bit_clr(P_SW2, 7);  \
                                                                      }while(0)

#define CLK_enable_EXT_clock_signal                                 do{ \
                                                                         XOSCCR = 0x80; \
                                                                         while((XOSCCR & 0x01) == FALSE); \
                                                                      }while(0)   

#define CLK_disable_EXT_clock_signal                                do{ \
                                                                         bit_set(P_SW2, 7);  \
                                                                         XOSCCR = 0x00; \
                                                                         bit_clr(P_SW2, 7);  \
                                                                      }while(0)    

#define CLK_enable_EXT_crystal                                      do{ \
                                                                         XOSCCR = 0xC0; \
                                                                         while((XOSCCR & 0x01) == FALSE); \
                                                                      }while(0)  
                                                               
#define CLK_disable_EXT_crystal                                     CLK_disable_EXT_clock_signal

//sys_div                                                              
#define CLK_sys_clk_scalar(div)                                     CLKDIV = div

//src                                                             
#define IRC_24M                                                     0
#define EXT_xtal                                                    1
#define EXT_clk                                                     2
#define IRC_32k                                                     3

#define CLK_set_sys_clk_source_and_div(clk_src, div)                  do{ \
                                                                          if(clk_src == IRC_32k) \
                                                                          { \
                                                                             CLK_enable_IRC32_k; \
                                                                          } \
                                                                          else if(clk_src == EXT_clk) \
                                                                          { \
                                                                             CLK_enable_EXT_clock_signal; \
                                                                          } \
                                                                          else if(clk_src == EXT_xtal) \
                                                                          { \
                                                                             CLK_enable_EXT_crystal; \
                                                                          } \
                                                                          else \
                                                                          { \
                                                                            CLK_enable_IRC24_M; \
                                                                          } \
                                                                          CLK_sys_clk_scalar(div); \
                                                                          CKSEL = clk_src; \
                                                                      }while(0)

//mclk_div
#define MCLK_SYSCLK_no_output                                        0x00
#define MCLK_SYSCLK_div_1                                            0x10
#define MCLK_SYSCLK_div_2                                            0x30
#define MCLK_SYSCLK_div_4                                            0x50
#define MCLK_SYSCLK_div_8                                            0x70
#define MCLK_SYSCLK_div_16                                           0x90
#define MCLK_SYSCLK_div_32                                           0xB0
#define MCLK_SYSCLK_div_64                                           0xD0
#define MCLK_SYSCLK_div_128                                          0xF0

#define CLK_MCLK_scalar(div)                                         CKSEL |= div

//mclk_pin_id
#define MCLK_out_P54                                                 0      
#define MCLK_out_P16                                                 1                  

#define CLK_set_MCLK(div, pin_id)                                    do{ \
                                                                          CLK_MCLK_scalar(div); \
                                                                          if(pin_id == MCLK_out_P16) \
                                                                          { \
                                                                             bit_set(CKSEL, 3); \
                                                                          } \
                                                                          else \
                                                                          { \
                                                                             bit_clr(CKSEL, 3); \
                                                                          } \
                                                                       }while(0)

#define CLK_set_sys_clk(sys_src, sys_div, mclk_div, mclk_pin_id)     do{ \
                                                                          bit_set(P_SW2, 7);  \
                                                                          CLK_set_sys_clk_source_and_div(sys_src, sys_div); \
                                                                          CLK_set_MCLK(mclk_div, mclk_pin_id); \
                                                                          bit_clr(P_SW2, 7);  \
                                                                       }while(0)