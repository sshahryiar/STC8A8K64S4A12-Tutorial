//Interrupt Sub-Routines


/*

void EXT_0_ISR(void)        interrupt 0 
void EXT_1_ISR(void)        interrupt 2
void EXT_2_ISR(void)        interrupt 10
void EXT_3_ISR(void)        interrupt 11
void EXT_4_ISR(void)        interrupt 16

void TMR_0_ISR(void)        interrupt 1
void TMR_1_ISR(void)        interrupt 3
void TMR_2_ISR(void)        interrupt 12
void TMR_3_ISR(void)        interrupt 19
void TMR_4_ISR(void)        interrupt 20

void PCA_ISR(void)          interrupt 7

void PWM_ISR(void)          interrupt 22
void PWM_Fault_ISR(void)    interrupt 23

void UART_1_ISR(void)       interrupt 4
void UART_2_ISR(void)       interrupt 8
void UART_3_ISR(void)       interrupt 17
void UART_4_ISR(void)       interrupt 18

void SPI_ISR(void)          interrupt 9

void I2C_ISR(void)          interrupt 24

void ADC_ISR(void)          interrupt 5

void CMP_ISR(void)          interrupt 21

void LVD_ISR(void)          interrupt 6

*/


//External Interrupt Edge Selection

#define EXT_0_rising_and_falling_edge_detection         bit_clr(TCON, 0)
#define EXT_1_rising_and_falling_edge_detection         bit_clr(TCON, 2)

#define EXT_0_falling_edge_detection_only               bit_set(TCON, 0)
#define EXT_1_falling_edge_detection_only               bit_set(TCON, 2)


//Interrupt Setups


#define _enable_global_interrupt                        bit_set(IE, 7)
#define _disable_global_interrupt                       bit_clr(IE, 7)


#define _enable_EXT_0_interrupt                         bit_set(IE, 0)
#define _disable_EXT_0_interrupt                        bit_clr(IE, 0)

#define _enable_EXT_1_interrupt                         bit_set(IE, 2)
#define _disable_EXT_1_interrupt                        bit_clr(IE, 2)

#define _enable_EXT_2_interrupt                         bit_set(INTCLKO, 4)
#define _disable_EXT_2_interrupt                        bit_clr(INTCLKO, 4)

#define _enable_EXT_3_interrupt                         bit_set(INTCLKO, 5)
#define _disable_EXT_3_interrupt                        bit_clr(INTCLKO, 5)

#define _enable_EXT_4_interrupt                         bit_set(INTCLKO, 6)
#define _disable_EXT_4_interrupt                        bit_clr(INTCLKO, 6)


#define _enable_TMR_0_interrupt                         bit_set(IE, 1)
#define _disable_TMR_0_interrupt                        bit_clr(IE, 1)

#define _enable_TMR_1_interrupt                         bit_set(IE, 3)
#define _disable_TMR_1_interrupt                        bit_clr(IE, 3)

#define _enable_TMR_2_interrupt                         bit_set(IE2, 2)
#define _disable_TMR_2_interrupt                        bit_clr(IE2, 2)

#define _enable_TMR_3_interrupt                         bit_set(IE2, 5)
#define _disable_TMR_3_interrupt                        bit_clr(IE2, 5)

#define _enable_TMR_4_interrupt                         bit_set(IE2, 6)
#define _disable_TMR_4_interrupt                        bit_clr(IE2, 6)


#define _enable_PCA_counter_interrupt                   bit_set(CMOD, 0)
#define _disable_PCA_counter_interrupt                  bit_clr(CMOD, 0)

#define _enable_PCA_0_interrupt                         bit_set(CCAPM0, 0)
#define _disable_PCA_0_interrupt                        bit_clr(CCAPM0, 0)

#define _enable_PCA_1_interrupt                         bit_set(CCAPM1, 0)
#define _disable_PCA_1_interrupt                        bit_clr(CCAPM1, 0)

#define _enable_PCA_2_interrupt                         bit_set(CCAPM2, 0)
#define _disable_PCA_2_interrupt                        bit_clr(CCAPM2, 0)

#define _enable_PCA_3_interrupt                         bit_set(CCAPM3, 0)
#define _disable_PCA_3_interrupt                        bit_clr(CCAPM3, 0)


#define _enable_PWM_counter_interrupt                   bit_set(PWMCR, 6)
#define _disable_PWM_counter_interrupt                  bit_clr(PWMCR, 5)


#define _enable_PWM_fault_interrupt                    bit_set(PWMFDCR, 3)
#define _disable_PWM_fault_interrupt                   bit_clr(PWMFDCR, 3)


#define _enable_PWM_0_flipping_interrupt               bit_set(PWM0CR, 2)
#define _disable_PWM_0_flipping_interrupt              bit_clr(PWM0CR, 2)

#define _enable_PWM_0_1st_flipping_interrupt           bit_set(PWM0CR, 0)
#define _disable_PWM_0_1st_flipping_interrupt          bit_clr(PWM0CR, 0)

#define _enable_PWM_0_2nd_flipping_interrupt           bit_set(PWM0CR, 1)
#define _disable_PWM_0_2nd_flipping_interrupt          bit_clr(PWM0CR, 1)

#define _enable_PWM_1_flipping_interrupt               bit_set(PWM1CR, 2)
#define _disable_PWM_1_flipping_interrupt              bit_clr(PWM1CR, 2)

#define _enable_PWM_1_1st_flipping_interrupt           bit_set(PWM1CR, 0)
#define _disable_PWM_1_1st_flipping_interrupt          bit_clr(PWM1CR, 0)

#define _enable_PWM_1_2nd_flipping_interrupt           bit_set(PWM1CR, 1)
#define _disable_PWM_1_2nd_flipping_interrupt          bit_clr(PWM1CR, 1)

#define _enable_PWM_2_flipping_interrupt               bit_set(PWM2CR, 2)
#define _disable_PWM_2_flipping_interrupt              bit_clr(PWM2CR, 2)

#define _enable_PWM_2_1st_flipping_interrupt           bit_set(PWM2CR, 0)
#define _disable_PWM_2_1st_flipping_interrupt          bit_clr(PWM2CR, 0)

#define _enable_PWM_2_2nd_flipping_interrupt           bit_set(PWM2CR, 1)
#define _disable_PWM_2_2nd_flipping_interrupt          bit_clr(PWM2CR, 1)

#define _enable_PWM_3_flipping_interrupt               bit_set(PWM3CR, 2)
#define _disable_PWM_3_flipping_interrupt              bit_clr(PWM3CR, 2)

#define _enable_PWM_3_1st_flipping_interrupt           bit_set(PWM3CR, 0)
#define _disable_PWM_3_1st_flipping_interrupt          bit_clr(PWM3CR, 0)

#define _enable_PWM_3_2nd_flipping_interrupt           bit_set(PWM3CR, 1)
#define _disable_PWM_3_2nd_flipping_interrupt          bit_clr(PWM3CR, 1)

#define _enable_PWM_4_flipping_interrupt               bit_set(PWM4CR, 2)
#define _disable_PWM_4_flipping_interrupt              bit_clr(PWM4CR, 2)

#define _enable_PWM_4_1st_flipping_interrupt           bit_set(PWM4CR, 0)
#define _disable_PWM_4_1st_flipping_interrupt          bit_clr(PWM4CR, 0)

#define _enable_PWM_4_2nd_flipping_interrupt           bit_set(PWM4CR, 1)
#define _disable_PWM_4_2nd_flipping_interrupt          bit_clr(PWM4CR, 1)

#define _enable_PWM_5_flipping_interrupt               bit_set(PWM5CR, 2)
#define _disable_PWM_5_flipping_interrupt              bit_clr(PWM5CR, 2)

#define _enable_PWM_5_1st_flipping_interrupt           bit_set(PWM5CR, 0)
#define _disable_PWM_5_1st_flipping_interrupt          bit_clr(PWM5CR, 0)

#define _enable_PWM_5_2nd_flipping_interrupt           bit_set(PWM5CR, 1)
#define _disable_PWM_5_2nd_flipping_interrupt          bit_clr(PWM5CR, 1)

#define _enable_PWM_6_flipping_interrupt               bit_set(PWM6CR, 2)
#define _disable_PWM_6_flipping_interrupt              bit_clr(PWM6CR, 2)

#define _enable_PWM_6_1st_flipping_interrupt           bit_set(PWM6CR, 0)
#define _disable_PWM_6_1st_flipping_interrupt          bit_clr(PWM6CR, 0)

#define _enable_PWM_6_2nd_flipping_interrupt           bit_set(PWM6CR, 1)
#define _disable_PWM_6_2nd_flipping_interrupt          bit_clr(PWM6CR, 1)

#define _enable_PWM_7_flipping_interrupt               bit_set(PWM7CR, 2)
#define _disable_PWM_7_flipping_interrupt              bit_clr(PWM7CR, 2)

#define _enable_PWM_7_1st_flipping_interrupt           bit_set(PWM7CR, 0)
#define _disable_PWM_7_1st_flipping_interrupt          bit_clr(PWM7CR, 0)

#define _enable_PWM_7_2nd_flipping_interrupt           bit_set(PWM7CR, 1)
#define _disable_PWM_7_2nd_flipping_interrupt          bit_clr(PWM7CR, 1)


#define _enable_UART_1_interrupt                       bit_set(IE, 4)
#define _disable_UART_1_interrupt                      bit_clr(IE, 4)

#define _enable_UART_2_interrupt                       bit_set(IE2, 0)
#define _disable_UART_2_interrupt                      bit_clr(IE2, 0)

#define _enable_UART_3_interrupt                       bit_set(IE2, 3)
#define _disable_UART_3_interrupt                      bit_clr(IE2, 3)

#define _enable_UART_4_interrupt                       bit_set(IE2, 4)
#define _disable_UART_4_interrupt                      bit_clr(IE2, 4)


#define _enable_SPI_interrupt                          bit_set(IE2, 1)
#define _disable_SPI_interrupt                         bit_clr(IE2, 1)


#define _enable_I2C_master_mode_interrupt              bit_set(I2CMSCR, 7)
#define _disable_I2C_master_mode_interrupt             bit_clr(I2CMSCR, 7)

#define _enable_I2C_slave_start_receive_interrupt      bit_set(I2CSLCR, 6)
#define _disable_I2C_slave_start_receive_interrupt     bit_clr(I2CSLCR, 6)

#define _enable_I2C_slave_receive_interrupt            bit_set(I2CSLCR, 5)
#define _disable_I2C_slave_receive_interrupt           bit_clr(I2CSLCR, 5)

#define _enable_I2C_slave_transmit_interrupt           bit_set(I2CSLCR, 4)
#define _disable_I2C_slave_transmit_interrupt          bit_clr(I2CSLCR, 4)

#define _enable_I2C_slave_stop_receive_interrupt       bit_set(I2CSLCR, 3)
#define _disable_I2C_slave_stop_receive_interrupt      bit_clr(I2CSLCR, 3)


#define _enable_ADC_interrupt                           bit_set(IE, 5)
#define _disable_ADC_interrupt                          bit_clr(IE, 5)


#define _enable_CMP_rising_interrupt                    bit_set(CMPCR1, 5)
#define _disable_CMP_rising_interrupt                   bit_clr(CMPCR1, 5)

#define _enable_CMP_falling_interrupt                   bit_set(CMPCR1, 4)
#define _disable_CMP_falling_interrupt                  bit_clr(CMPCR1, 4)


#define _enable_LVD_interrupt                           bit_set(IE, 6)
#define _disable_LVD_interrupt                          bit_clr(IE, 6)




//Interrupt Flags

#define check_EXT_0_flag                                get_bit(TCON, 1)
#define check_EXT_1_flag                                get_bit(TCON, 3)
#define check_EXT_2_flag                                get_bit(AUXINTIF, 4)
#define check_EXT_3_flag                                get_bit(AUXINTIF, 5)
#define check_EXT_4_flag                                get_bit(AUXINTIF, 6)

#define check_TMR_0_overflow_flag                       get_bit(TCON, 5)
#define check_TMR_1_overflow_flag                       get_bit(TCON, 7)
#define check_TMR_2_overflow_flag                       get_bit(AUXINTIF, 0)
#define check_TMR_3_overflow_flag                       get_bit(AUXINTIF, 1)
#define check_TMR_4_overflow_flag                       get_bit(AUXINTIF, 2)

#define check_PCA_Counter_overflow_flag                 get_bit(CCON, 7)
#define check_PCA_0_flag                                get_bit(CCON, 0)
#define check_PCA_1_flag                                get_bit(CCON, 1)
#define check_PCA_2_flag                                get_bit(CCON, 2)
#define check_PCA_3_flag                                get_bit(CCON, 3)

#define check_PWM_Counter_overflow_flag                 get_bit(PWMCFG, 7)

#define check_PWM_0_flag                                get_bit(PWMIF, 0)    
#define check_PWM_1_flag                                get_bit(PWMIF, 1) 
#define check_PWM_2_flag                                get_bit(PWMIF, 2) 
#define check_PWM_3_flag                                get_bit(PWMIF, 3)
#define check_PWM_4_flag                                get_bit(PWMIF, 4)    
#define check_PWM_5_flag                                get_bit(PWMIF, 5) 
#define check_PWM_6_flag                                get_bit(PWMIF, 6) 
#define check_PWM_7_flag                                get_bit(PWMIF, 7)

#define check_PWM_fault_flag                            get_bit(PWMFDCR, 0)

#define check_UART_1_RX_flag                            get_bit(SCON, 0)
#define check_UART_1_TX_flag                            get_bit(SCON, 1)
#define check_UART_2_RX_flag                            get_bit(S2CON, 0)
#define check_UART_2_TX_flag                            get_bit(S2CON, 1)
#define check_UART_3_RX_flag                            get_bit(S3CON, 0)
#define check_UART_3_TX_flag                            get_bit(S3CON, 1)
#define check_UART_4_RX_flag                            get_bit(S4CON, 0)
#define check_UART_4_TX_flag                            get_bit(S4CON, 1)

#define check_SPI_flag                                  get_bit(SPSTAT, 7)
#define check_SPI_write_collision_flag                  get_bit(SPSTAT, 6)

#define check_I2C_master_flag                           get_bit(I2CMSST, 6)

#define check_I2C_slave_start_receive_flag              get_bit(I2CSLST, 6) 
#define check_I2C_slave_receive_flag                    get_bit(I2CSLST, 5) 
#define check_I2C_slave_transmit_flag                   get_bit(I2CSLST, 4) 
#define check_I2C_slave_stop_receive_flag               get_bit(I2CSLST, 3) 

#define check_LVD_flag                                  get_bit(PCON, 5)

#define check_ADC_flag                                  get_bit(ADC_CONTR, 5)

#define check_CMP_flag                                  get_bit(CMPCR1, 6)



//Clear Interrupt Flags

#define clear_EXT_0_flag                                bit_clr(TCON, 1)
#define clear_EXT_1_flag                                bit_clr(TCON, 3)
#define clear_EXT_2_flag                                bit_clr(AUXINTIF, 4)
#define clear_EXT_3_flag                                bit_clr(AUXINTIF, 5)
#define clear_EXT_4_flag                                bit_clr(AUXINTIF, 6)

#define clear_TMR_0_overflow_flag                       bit_clr(TCON, 5)
#define clear_TMR_1_overflow_flag                       bit_clr(TCON, 7)
#define clear_TMR_2_overflow_flag                       bit_clr(AUXINTIF, 0)
#define clear_TMR_3_overflow_flag                       bit_clr(AUXINTIF, 1)
#define clear_TMR_4_overflow_flag                       bit_clr(AUXINTIF, 2)

#define clear_PCA_Counter_overflow_flag                 bit_clr(CCON, 7)
#define clear_PCA_0_flag                                bit_clr(CCON, 0)
#define clear_PCA_1_flag                                bit_clr(CCON, 1)
#define clear_PCA_2_flag                                bit_clr(CCON, 2)
#define clear_PCA_3_flag                                bit_clr(CCON, 3)

#define clear_PWM_Counter_overflow_flag                 bit_clr(PWMCFG, 7)

#define clear_PWM_0_flag                                bit_clr(PWMIF, 0)    
#define clear_PWM_1_flag                                bit_clr(PWMIF, 1) 
#define clear_PWM_2_flag                                bit_clr(PWMIF, 2) 
#define clear_PWM_3_flag                                bit_clr(PWMIF, 3)
#define clear_PWM_4_flag                                bit_clr(PWMIF, 4)    
#define clear_PWM_5_flag                                bit_clr(PWMIF, 5) 
#define clear_PWM_6_flag                                bit_clr(PWMIF, 6) 
#define clear_PWM_7_flag                                bit_clr(PWMIF, 7)

#define clear_PWM_fault_flag                            bit_clr(PWMFDCR, 0)

#define clear_UART_1_RX_flag                            bit_clr(SCON, 0)
#define clear_UART_1_TX_flag                            bit_clr(SCON, 1)
#define clear_UART_2_RX_flag                            bit_clr(S2CON, 0)
#define clear_UART_2_TX_flag                            bit_clr(S2CON, 1)
#define clear_UART_3_RX_flag                            bit_clr(S3CON, 0)
#define clear_UART_3_TX_flag                            bit_clr(S3CON, 1)
#define clear_UART_4_RX_flag                            bit_clr(S4CON, 0)
#define clear_UART_4_TX_flag                            bit_clr(S4CON, 1)

#define clear_SPI_flag                                  bit_set(SPSTAT, 7)
#define clear_SPI_write_collision_flag                  bit_set(SPSTAT, 6)

#define clear_I2C_master_flag                           bit_clr(I2CMSST, 6)

#define clear_I2C_slave_start_receive_flag              bit_clr(I2CSLST, 6) 
#define clear_I2C_slave_receive_flag                    bit_clr(I2CSLST, 5) 
#define clear_I2C_slave_transmit_flag                   bit_clr(I2CSLST, 4) 
#define clear_I2C_slave_stop_receive_flag               bit_clr(I2CSLST, 3) 

#define clear_LVD_flag                                  bit_clr(PCON, 5)

#define clear_ADC_flag                                  bit_clr(ADC_CONTR, 5)

#define clear_CMP_flag                                  bit_clr(CMPCR1, 6)



//Interrupt Priority Settings

#define EXT_0_priority_0                               do{bit_clr(IPH, 0); bit_clr(IP, 0);}while(0)
#define EXT_0_priority_1                               do{bit_clr(IPH, 0); bit_set(IP, 0);}while(0)
#define EXT_0_priority_2                               do{bit_set(IPH, 0); bit_clr(IP, 0);}while(0)
#define EXT_0_priority_3                               do{bit_set(IPH, 0); bit_set(IP, 0);}while(0)

#define EXT_1_priority_0                               do{bit_clr(IPH, 2); bit_clr(IP, 2);}while(0)
#define EXT_1_priority_1                               do{bit_clr(IPH, 2); bit_set(IP, 2);}while(0)
#define EXT_1_priority_2                               do{bit_set(IPH, 2); bit_clr(IP, 2);}while(0)
#define EXT_1_priority_3                               do{bit_set(IPH, 2); bit_set(IP, 2);}while(0)

#define EXT_4_priority_0                               do{bit_clr(IP2H, 4); bit_clr(IP2, 4);}while(0)
#define EXT_4_priority_1                               do{bit_clr(IP2H, 4); bit_set(IP2, 4);}while(0)
#define EXT_4_priority_2                               do{bit_set(IP2H, 4); bit_clr(IP2, 4);}while(0)
#define EXT_4_priority_3                               do{bit_set(IP2H, 4); bit_set(IP2, 4);}while(0)


#define TMR_0_priority_0                               do{bit_clr(IPH, 1); bit_clr(IP, 1);}while(0)
#define TMR_0_priority_1                               do{bit_clr(IPH, 1); bit_set(IP, 1);}while(0)
#define TMR_0_priority_2                               do{bit_set(IPH, 1); bit_clr(IP, 1);}while(0)
#define TMR_0_priority_3                               do{bit_set(IPH, 1); bit_set(IP, 1);}while(0)

#define TMR_1_priority_0                               do{bit_clr(IPH, 3); bit_clr(IP, 3);}while(0)
#define TMR_1_priority_1                               do{bit_clr(IPH, 3); bit_set(IP, 3);}while(0)
#define TMR_1_priority_2                               do{bit_set(IPH, 3); bit_clr(IP, 3);}while(0)
#define TMR_1_priority_3                               do{bit_set(IPH, 3); bit_set(IP, 3);}while(0)


#define PCA_priority_0                                 do{bit_clr(IPH, 7); bit_clr(IP, 7);}while(0)
#define PCA_priority_1                                 do{bit_clr(IPH, 7); bit_set(IP, 7);}while(0)
#define PCA_priority_2                                 do{bit_set(IPH, 7); bit_clr(IP, 7);}while(0)
#define PCA_priority_3                                 do{bit_set(IPH, 7); bit_set(IP, 7);}while(0)


#define PWM_priority_0                                 do{bit_clr(IP2H, 2); bit_clr(IP2, 2);}while(0)
#define PWM_priority_1                                 do{bit_clr(IP2H, 2); bit_set(IP2, 2);}while(0)
#define PWM_priority_2                                 do{bit_set(IP2H, 2); bit_clr(IP2, 2);}while(0)
#define PWM_priority_3                                 do{bit_set(IP2H, 2); bit_set(IP2, 2);}while(0)


#define PWM_fault_priority_0                           do{bit_clr(IP2H, 3); bit_clr(IP2, 3);}while(0)
#define PWM_fault_priority_1                           do{bit_clr(IP2H, 3); bit_set(IP2, 3);}while(0)
#define PWM_fault_priority_2                           do{bit_set(IP2H, 3); bit_clr(IP2, 3);}while(0)
#define PWM_fault_priority_3                           do{bit_set(IP2H, 3); bit_set(IP2, 3);}while(0)


#define UART_1_priority_0                              do{bit_clr(IPH, 4); bit_clr(IP, 4);}while(0)
#define UART_1_priority_1                              do{bit_clr(IPH, 4); bit_set(IP, 4);}while(0)
#define UART_1_priority_2                              do{bit_set(IPH, 4); bit_clr(IP, 4);}while(0)
#define UART_1_priority_3                              do{bit_set(IPH, 4); bit_set(IP, 4);}while(0)

#define UART_2_priority_0                              do{bit_clr(IP2H, 0); bit_clr(IP2, 0);}while(0)
#define UART_2_priority_1                              do{bit_clr(IP2H, 0); bit_set(IP2, 0);}while(0)
#define UART_2_priority_2                              do{bit_set(IP2H, 0); bit_clr(IP2, 0);}while(0)
#define UART_2_priority_3                              do{bit_set(IP2H, 0); bit_set(IP2, 0);}while(0)

#define SPI_priority_0                                 do{bit_clr(IP2H, 1); bit_clr(IP2, 1);}while(0)
#define SPI_priority_1                                 do{bit_clr(IP2H, 1); bit_set(IP2, 1);}while(0)
#define SPI_priority_2                                 do{bit_set(IP2H, 1); bit_clr(IP2, 1);}while(0)
#define SPI_priority_3                                 do{bit_set(IP2H, 1); bit_set(IP2, 1);}while(0)


#define I2C_priority_0                                 do{bit_clr(IP2H, 6); bit_clr(IP2, 6);}while(0)
#define I2C_priority_1                                 do{bit_clr(IP2H, 6); bit_set(IP2, 6);}while(0)
#define I2C_priority_2                                 do{bit_set(IP2H, 6); bit_clr(IP2, 6);}while(0)
#define I2C_priority_3                                 do{bit_set(IP2H, 6); bit_set(IP2, 6);}while(0)


#define ADC_priority_0                                 do{bit_clr(IPH, 5); bit_clr(IP, 5);}while(0)
#define ADC_priority_1                                 do{bit_clr(IPH, 5); bit_set(IP, 5);}while(0)
#define ADC_priority_2                                 do{bit_set(IPH, 5); bit_clr(IP, 5);}while(0)
#define ADC_priority_3                                 do{bit_set(IPH, 5); bit_set(IP, 5);}while(0)


#define CMP_priority_0                                 do{bit_clr(IP2H, 5); bit_clr(IP2, 5);}while(0)
#define CMP_priority_1                                 do{bit_clr(IP2H, 5); bit_set(IP2, 5);}while(0)
#define CMP_priority_2                                 do{bit_set(IP2H, 5); bit_clr(IP2, 5);}while(0)
#define CMP_priority_3                                 do{bit_set(IP2H, 5); bit_set(IP2, 5);}while(0)


#define LVD_priority_0                                 do{bit_clr(IPH, 6); bit_clr(IP, 6);}while(0)
#define LVD_priority_1                                 do{bit_clr(IPH, 6); bit_set(IP, 6);}while(0)
#define LVD_priority_2                                 do{bit_set(IPH, 6); bit_clr(IP, 6);}while(0)
#define LVD_priority_3                                 do{bit_set(IPH, 6); bit_set(IP, 6);}while(0)