#define PWM_stop_counter                                             bit_clr(PWMCR, 7)
#define PWM_start_counter                                            bit_set(PWMCR, 7)


//src
#define PWM_clk_sys_PS                                               0x00
#define PWM_clk_TMR2_overflow                                        0x10

//sys_PS
#define PWM_clk_ps_sys_clk_div_1                                     0x00
#define PWM_clk_ps_sys_clk_div_2                                     0x01
#define PWM_clk_ps_sys_clk_div_3                                     0x02
#define PWM_clk_ps_sys_clk_div_4                                     0x03
#define PWM_clk_ps_sys_clk_div_5                                     0x04
#define PWM_clk_ps_sys_clk_div_6                                     0x05
#define PWM_clk_ps_sys_clk_div_7                                     0x06
#define PWM_clk_ps_sys_clk_div_8                                     0x07
#define PWM_clk_ps_sys_clk_div_9                                     0x08
#define PWM_clk_ps_sys_clk_div_10                                    0x09
#define PWM_clk_ps_sys_clk_div_11                                    0x0A
#define PWM_clk_ps_sys_clk_div_12                                    0x0B
#define PWM_clk_ps_sys_clk_div_13                                    0x0C
#define PWM_clk_ps_sys_clk_div_14                                    0x0D
#define PWM_clk_ps_sys_clk_div_15                                    0x0E
#define PWM_clk_ps_sys_clk_div_16                                    0x0F

#define PWM_clk_set(src, sys_PS)                                     do{bit_set(P_SW2, 7); \
                                                                        PWMCKS = 0x00; \
                                                                        PWMCKS |= (src | sys_PS); \
                                                                        bit_clr(P_SW2, 7);}while(0);

#define PWM_ADC_not_related                                          bit_clr(PWMCFG, 6)
#define PWM_ADC_triggered_by_PWM                                     bit_set(PWMCFG, 6)

#define PWM_disable_external_fault_detection                         bit_clr(PWMFDCR, 5)
#define PWM_enable_external_fault_detection                          bit_set(PWMFDCR, 5)

#define PWM_fault_CMP_result_changing_from_L_to_H                    bit_clr(PWMFDCR, 7)
#define PWM_fault_CMP_result_changing_from_H_to_L                    bit_set(PWMFDCR, 7)

#define PWM_fault_P35_level_has_no_effect                            bit_clr(PWMFDCR, 1)
#define PWM_fault_sourced_by_P35_level                               bit_set(PWMFDCR, 1)

#define PWM_fault_P35_changing_from_L_to_H                           bit_clr(PWMFDCR, 6)
#define PWM_fault_P35_changing_from_H_to_L                           bit_set(PWMFDCR, 6)

#define PWM_fault_has_no_effect_on_PWM_output                        bit_clr(PWMFDCR, 4)
#define PWM_fault_sets_PWM_output_to_high_Z                          bit_set(PWMFDCR, 4)

#define PWM_CMP_not_related                                          bit_clr(PWMFDCR, 2)
#define PWM_fault_sourced_by_CMP_output                              bit_set(PWMFDCR, 2)


//Hold Levels HLD    
#define PWM_level_normal                                             0x00
#define PWM_HLD_L_low                                                0x01
#define PWM_HLD_H_high                                               0x02
                                                                         

#define PWM0_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM0HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM1_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM1HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM2_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM2HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM3_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM3HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)                                                                           

#define PWM4_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM4HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM5_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM4HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM6_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM6HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM7_hold_level(HLD)                                         do{bit_set(P_SW2, 7); \
                                                                        PWM7HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)      
                                                                        


//pin function
#define PWM_pin_is_GPIO                                              0x00
#define PWM_pin_is_PWM_output                                        0x80

//init_lvl
#define PWM_init_lvl_low                                             0x00
#define PWM_init_lvl_high                                            0x40

//PWM0 pins
#define PWM_0_pin_P20                                                0x00
#define PWM_0_pin_P10                                                0x08
#define PWM_0_pin_P60                                                0x10

//PWM1 pins
#define PWM_1_pin_P21                                                0x00
#define PWM_1_pin_P11                                                0x08
#define PWM_1_pin_P61                                                0x10

//PWM2 pins
#define PWM_2_pin_P22                                                0x00
#define PWM_2_pin_P12                                                0x08
#define PWM_2_pin_P62                                                0x10

//PWM3 pins
#define PWM_3_pin_P23                                                0x00
#define PWM_3_pin_P13                                                0x08
#define PWM_3_pin_P63                                                0x10

//PWM4 pins
#define PWM_4_pin_P24                                                0x00
#define PWM_4_pin_P14                                                0x08
#define PWM_4_pin_P64                                                0x10

//PWM5 pins
#define PWM_5_pin_P25                                                0x00
#define PWM_5_pin_P15                                                0x08
#define PWM_5_pin_P65                                                0x10

//PWM6 pins
#define PWM_6_pin_P26                                                0x00
#define PWM_6_pin_P16                                                0x08
#define PWM_6_pin_P66                                                0x10

//PWM7 pins
#define PWM_7_pin_P27                                                0x00
#define PWM_7_pin_P17                                                0x08
#define PWM_7_pin_P67                                                0x10


#define PWM0_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7); \
                                                                        PWM0CR &= 0x07; \
                                                                        PWM0CR |= (pin_function | init_lvl | pins); \
                                                                        PWM0HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM1_setup(pin_function, init_lvl, pins, HLD)               do{bit_set(P_SW2, 7); \
                                                                        PWM1CR &= 0x07; \
                                                                        PWM1CR |= (pin_function | init_lvl | pins); \
                                                                        PWM1HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM2_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7);\
                                                                        PWM2CR &= 0x07; \
                                                                        PWM2CR |= (pin_function | init_lvl | pins); \
                                                                        PWM2HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM3_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7); \
                                                                        PWM3CR &= 0x07; \
                                                                        PWM3CR |= (pin_function | init_lvl | pins); \
                                                                        PWM3HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM4_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7); \
                                                                        PWM4CR &= 0x07; \
                                                                        PWM4CR |= (pin_function | init_lvl | pins); \
                                                                        PWM4HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM5_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7); \
                                                                        PWM5CR &= 0x07; \
                                                                        PWM5CR |= (pin_function | init_lvl | pins); \
                                                                        PWM5HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM6_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7); \
                                                                        PWM6CR &= 0x07; \
                                                                        PWM6CR |= (pin_function | init_lvl | pins); \
                                                                        PWM6HLD = HLD; \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM7_setup(pin_function, init_lvl, pins, HLD)                do{bit_set(P_SW2, 7); \
                                                                        PWM7CR &= 0x07; \
                                                                        PWM7CR |= (pin_function | init_lvl | pins); \
                                                                        PWM7HLD = HLD; \  
                                                                        bit_set(P_SW2, 7);}while(0)

                                                                        
#define PWM_set_counter(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWMCL = (value & 0x00FF); \
                                                                        PWMCH = ((value & 0xFF00) >> 0x08); \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM_set_ADC_trigger_counter(value)                           do{bit_set(P_SW2, 7); \
                                                                        TADCPL = (value & 0x00FF); \
                                                                        TADCPH = ((value & 0xFF00) >> 0x08); \
                                                                        bit_clr(P_SW2, 7);}while(0)

#define PWM_set_PWM0_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM0T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM0_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM0T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)             

#define PWM_set_PWM1_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM1T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM1_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM1T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM_set_PWM2_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM2T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM2_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM2T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM_set_PWM3_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM3T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM3_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM3T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM_set_PWM4_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM4T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM4_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM4T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM_set_PWM5_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM5T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM5_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM5T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM_set_PWM6_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM6T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM6_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM6T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 

#define PWM_set_PWM7_T1(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM7T1 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0)    

#define PWM_set_PWM7_T2(value)                                       do{bit_set(P_SW2, 7); \
                                                                        PWM7T2 = value; \
                                                                        bit_clr(P_SW2, 7);}while(0) 