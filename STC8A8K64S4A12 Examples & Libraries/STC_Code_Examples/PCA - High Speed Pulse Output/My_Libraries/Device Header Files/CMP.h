#define CMP_enable                              bit_set(CMPCR1, 7)
#define CMP_disable                             bit_clr(CMPCR1, 7)

#define CMP_output_pin_P34                      bit_clr(P_SW2, 3)
#define CMP_output_pin_P41                      bit_set(P_SW2, 3)

//PI
#define CMP_positive_input_ADC                  0x08 
#define CMP_positive_input_P37                  0x00     

//NI
#define CMP_negative_input_P36                  0x04 
#define CMP_negative_input_REFV                 0x00  

//OE
#define CMP_output_enable                       0x02
#define CMP_output_disable                      0x00


#define CMP_get_comp_status                     get_bit(CMPCR1, 0)  
// 0 = CMP+ < CMP-      1 = CMP+ > CMP- 

//RO
#define CMP_result_negative_output              0x80
#define CMP_result_positive_output              0x00

//AFE
#define CMP_disable_analog_filtering            0x40
#define CMP_enable_analog_filtering             0x00

//value = filtering delay amount

#define CMP_clear                               do{ \
                                                    CMPCR1 = 0x00; \
                                                    CMPCR2 = 0x00; \
                                                  }while(0)


#define CMP_setup(PI, NI, OE, RO, AFE, value)   do{ \
                                                    CMP_clear; \
                                                    CMPCR1 |= (PI | NI | OE); \
                                                    CMPCR2 |= (RO | AFE | (value & 0x3F)); \
                                                  }while(0)

