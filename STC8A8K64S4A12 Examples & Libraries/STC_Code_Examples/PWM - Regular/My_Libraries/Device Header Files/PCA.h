/*
ECI         CCP0        CCP1      CCP2 		CCP3 		Hex            Option
P1.2        P1.7        P1.6	  P1.5		P1.4	    0x00           option 1
P2.2        P2.3        P2.4	  P2.5		P2.6	    0x10           option 2
P7.4        P7.0        P7.1	  P7.2		P7.3	    0x20           option 3
P3.5        P3.3        P3.2	  P3.1		P3.0	    0x30           option 4
*/

#define PCA_pin_option(value)                               do{P_SW1 |= value;}while(0)


#define PCA_reset                                       	do{CL = 0x00; \
                                                           	   CH = 0x00; \
                                                           	   CCON = 0x00; \
                                                           	   CMOD = 0x00; \
                                                           	   CCAPM0 = 0x00; \
                                                           	   CCAPM1 = 0x00; \
                                                           	   CCAPM2 = 0x00; \
                                                           	   CCAPM3 = 0x00; \
                                                               CCAP0L = 0x00; \
                                                               CCAP1L = 0x00; \
                                                               CCAP2L = 0x00; \
                                                               CCAP3L = 0x00; \
                                                               CCAP0H = 0x00; \
                                                               CCAP1H = 0x00; \
                                                               CCAP2H = 0x00; \
                                                               CCAP3H = 0x00; \
                                                               PCA_PWM0 = 0x00; \
                                                               PCA_PWM1 = 0x00; \
                                                               PCA_PWM2 = 0x00; \
                                                               PCA_PWM3 = 0x00;}while(0)

#define PCA_stop_counter                                	bit_clr(CCON, 6)
#define PCA_start_counter                               	bit_set(CCON, 6)

//cnt_mode
#define PCA_continue_counting_in_idle_mode              	0x00
#define PCA_stop_counting_in_idle_mode                  	0x80

//clk_src
#define PCA_clk_TMR0_OVF                                	0x04
#define PCA_clk_ECI_input                               	0x06
#define PCA_clk_sys_clk_div_1                           	0x08
#define PCA_clk_sys_clk_div_2                           	0x02
#define PCA_clk_sys_clk_div_4                           	0x0A
#define PCA_clk_sys_clk_div_6                           	0x0C
#define PCA_clk_sys_clk_div_8                           	0x0E
#define PCA_clk_sys_clk_div_12                          	0x00

#define PCA_setup(cnt_mode, clk_src)                    	do{PCA_reset; \
                                                           	   CMOD |= (cnt_mode | clk_src);}while(0)

//mode
#define PCA_nop                                         	0x00
#define PCA_PWM_without_interrupt                       	0x42
#define PCA_PWM_with_rising_edge_interrupt              	0x63
#define PCA_PWM_with_falling_edge_interrupt             	0x53
#define PCA_PWM_with_both_edge_interrupt                	0x73
#define PCA_16_bit_rising_edge_capture                  	0x20
#define PCA_16_bit_falling_edge_capture                 	0x10
#define PCA_16_bit_both_edge_capture                    	0x30
#define PCA_16_bit_software_timer                      	 	0x48
#define PCA_16_bit_high_speed_pulse_output              	0x4C

//PCA_mode
#define PCA_0_mode(mode)                                	do{CCAPM0 = mode;}while(0)
#define PCA_1_mode(mode)                                	do{CCAPM1 = mode;}while(0)
#define PCA_2_mode(mode)                                	do{CCAPM2 = mode;}while(0)
#define PCA_3_mode(mode)                                	do{CCAPM3 = mode;}while(0)

//PWM_bits
#define PCA_6_bit_PWM                                       0x80
#define PCA_7_bit_PWM                                       0x40
#define PCA_8_bit_PWM                                       0x00
#define PCA_10_bit_PWM                                      0xC0

#define PCA_n_PWM(n, PCA_mode, PWM_bits) 					do{ \
																if((PCA_mode == PCA_PWM_without_interrupt) || \
	    														   (PCA_mode == PCA_PWM_with_rising_edge_interrupt) || \
		 														   (PCA_mode == PCA_PWM_with_falling_edge_interrupt) || \
		  														   (PCA_mode == PCA_PWM_with_both_edge_interrupt)) \
																{ \
																	switch(n) \
																	{ \
																		case 1: \
																		{ \
																			PCA_1_mode(PCA_mode); \
																			PCA_PWM1 |= PWM_bits; \  
                                      break; \
																		} \
																		case 2: \
																		{ \
																			PCA_2_mode(PCA_mode); \
																			PCA_PWM2 |= PWM_bits; \  
                                      break; \
																		} \
																		case 3: \
																		{ \
																			PCA_3_mode(PCA_mode); \
																			PCA_PWM3 |= PWM_bits; \  	
                                      break; \
																		} \
																		default: \
																		{ \
																			PCA_0_mode(PCA_mode); \
																			PCA_PWM0 |= PWM_bits; \  
                                      break; \                                      
																		} \
																	} \
																} \
															}while(0)

#define PCA_load_counter(value)                         	do{CL = (value & 0x00FF); \
                                                           	   CH = ((value & 0xFF00) >> 0x08);}while(0)

                                                               
#define PCA0_load_value(value)                            do{CCAP0L = (value & 0x00FF); \
                                                           	   CCAP0H = (value >> 0x08);}while(0)  

#define PCA1_load_value(value)                            do{CCAP1L = (value & 0x00FF); \
                                                           	   CCAP1H = (value >> 0x08);}while(0)                                                                 

#define PCA2_load_value(value)                            do{CCAP2L = (value & 0x00FF); \
                                                           	   CCAP2H = (value >> 0x08);}while(0)  

#define PCA3_load_value(value)                            do{CCAP3L = (value & 0x00FF); \
                                                           	   CCAP3H = (value >> 0x08);}while(0)                                                                      
                                                               
unsigned int PCA_get_counter(void)
{
    unsigned int tmp = 0x0000;

    tmp = CH;
    tmp <<= 8;
    tmp |= CL;

    return tmp;
}


unsigned int PCA_get_CCAP0(void)
{
    unsigned int tmp = 0x0000;

    tmp = CCAP0H;
    tmp <<= 8;
    tmp |= CCAP0L;

    return tmp;
}


unsigned int PCA_get_CCAP1(void)
{
    unsigned int tmp = 0x0000;

    tmp = CCAP1H;
    tmp <<= 8;
    tmp |= CCAP1L;

    return tmp;
}


unsigned int PCA_get_CCAP2(void)
{
    unsigned int tmp = 0x0000;

    tmp = CCAP2H;
    tmp <<= 8;
    tmp |= CCAP2L;

    return tmp;
}


unsigned int PCA_get_CCAP3(void)
{
    unsigned int tmp = 0x0000;

    tmp = CCAP3H;
    tmp <<= 8;
    tmp |= CCAP3L;

    return tmp;
}


void PCA_0_6_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM0 &= 0xFD;
	PCA_PWM0 |= (bit_shift_left((value & bit_mask(7)), 1));
	CCAP0H = (value & 0x003F);
} 


void PCA_0_6_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM0 &= 0xFE;
	PCA_PWM0 |= (bit_shift_left((value & bit_mask(7)), 0));
	CCAP0L = (value & 0x003F);
} 


void PCA_0_7_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM0 &= 0xFD;
	PCA_PWM0 |= (bit_shift_left((value & bit_mask(8)), 1));
	CCAP0H = (value & 0x007F);
} 


void PCA_0_7_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM0 &= 0xFE;
	PCA_PWM0 |= (bit_shift_left((value & bit_mask(8)), 0));
	CCAP0L = (value & 0x007F);
} 



void PCA_0_8_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM0 &= 0xFD;
	PCA_PWM0 |= (bit_shift_left((value & bit_mask(9)), 1));
	CCAP0H = (value & 0x00FF);
} 


void PCA_0_8_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM0 &= 0xFE;
	PCA_PWM0 |= (bit_shift_left((value & bit_mask(9)), 0));
	CCAP0L = (value & 0x00FF);
} 


void PCA_0_10_bit_PWM_reload_value(unsigned int value)	
{
	
  PCA_PWM0 &= 0xCD;
  PCA_PWM0 |= (((value & 0x0400) >> 9) | ((value & 0x0300) >> 4));
  CCAP0H = (value & 0x00FF);
} 


void PCA_0_10_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM0 &= 0xF2;
  PCA_PWM0 |= (((value & 0x0400) >> 10) | ((value & 0x0300) >> 6));
	CCAP0L = (value & 0x00FF);
} 


void PCA_1_6_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM1 &= 0xFD;
	PCA_PWM1 |= (bit_shift_left((value & bit_mask(7)), 1));
	CCAP1H = (value & 0x003F);
} 


void PCA_1_6_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM1 &= 0xFE;
	PCA_PWM1 |= (bit_shift_left((value & bit_mask(7)), 0));
	CCAP1L = (value & 0x003F);
} 


void PCA_1_7_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM1 &= 0xFD;
	PCA_PWM1 |= (bit_shift_left((value & bit_mask(8)), 1));
	CCAP1H = (value & 0x007F);
} 


void PCA_1_7_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM1 &= 0xFE;
	PCA_PWM1 |= (bit_shift_left((value & bit_mask(8)), 0));
	CCAP1L = (value & 0x007F);
} 



void PCA_1_8_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM1 &= 0xFD;
	PCA_PWM1 |= (bit_shift_left((value & bit_mask(9)), 1));
	CCAP1H = (value & 0x00FF);
} 


void PCA_1_8_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM1 &= 0xFE;
	PCA_PWM1 |= (bit_shift_left((value & bit_mask(9)), 0));
	CCAP1L = (value & 0x00FF);
} 


void PCA_1_10_bit_PWM_reload_value(unsigned int value)	
{
	
  PCA_PWM1 &= 0xCD;
  PCA_PWM1 |= (((value & 0x0400) >> 9) | ((value & 0x0300) >> 4));
  CCAP1H = (value & 0x00FF);
} 


void PCA_1_10_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM1 &= 0xF2;
  PCA_PWM1 |= (((value & 0x0400) >> 10) | ((value & 0x0300) >> 6));
	CCAP1L = (value & 0x00FF);
} 


void PCA_2_6_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM2 &= 0xFD;
	PCA_PWM2 |= (bit_shift_left((value & bit_mask(7)), 1));
	CCAP2H = (value & 0x003F);
} 


void PCA_2_6_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM2 &= 0xFE;
	PCA_PWM2 |= (bit_shift_left((value & bit_mask(7)), 0));
	CCAP2L = (value & 0x003F);
} 


void PCA_2_7_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM2 &= 0xFD;
	PCA_PWM2 |= (bit_shift_left((value & bit_mask(8)), 1));
	CCAP2H = (value & 0x007F);
} 


void PCA_2_7_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM2 &= 0xFE;
	PCA_PWM2 |= (bit_shift_left((value & bit_mask(8)), 0));
	CCAP2L = (value & 0x007F);
} 



void PCA_2_8_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM2 &= 0xFD;
	PCA_PWM2 |= (bit_shift_left((value & bit_mask(9)), 1));
	CCAP2H = (value & 0x00FF);
} 


void PCA_2_8_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM2 &= 0xFE;
	PCA_PWM2 |= (bit_shift_left((value & bit_mask(9)), 0));
	CCAP2L = (value & 0x00FF);
} 


void PCA_2_10_bit_PWM_reload_value(unsigned int value)	
{
	
  PCA_PWM2 &= 0xCD;
  PCA_PWM2 |= (((value & 0x0400) >> 9) | ((value & 0x0300) >> 4));  
  CCAP2H = (value & 0x00FF);
} 


void PCA_2_10_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM2 &= 0xF2;
  PCA_PWM2 |= (((value & 0x0400) >> 10) | ((value & 0x0300) >> 6));
	CCAP2L = (value & 0x00FF);
} 


void PCA_3_6_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM3 &= 0xFD;
	PCA_PWM3 |= (bit_shift_left((value & bit_mask(7)), 1));
	CCAP3H = (value & 0x003F);
} 


void PCA_3_6_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM3 &= 0xFE;
	PCA_PWM3 |= (bit_shift_left((value & bit_mask(7)), 0));
	CCAP3L = (value & 0x003F);
} 


void PCA_3_7_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM3 &= 0xFD;
	PCA_PWM3 |= (bit_shift_left((value & bit_mask(8)), 1));
	CCAP3H = (value & 0x007F);
} 


void PCA_3_7_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM3 &= 0xFE;
	PCA_PWM3 |= (bit_shift_left((value & bit_mask(8)), 0));
	CCAP3L = (value & 0x007F);
} 



void PCA_3_8_bit_PWM_reload_value(unsigned int value)	
{
	PCA_PWM3 &= 0xFD;
	PCA_PWM3 |= (bit_shift_left((value & bit_mask(9)), 1));
	CCAP3H = (value & 0x00FF);
} 


void PCA_3_8_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM3 &= 0xFE;
	PCA_PWM3 |= (bit_shift_left((value & bit_mask(9)), 0));
	CCAP3L = (value & 0x00FF);
} 


void PCA_3_10_bit_PWM_reload_value(unsigned int value)	
{
	
  PCA_PWM3 &= 0xCD;
  PCA_PWM3 |= (((value & 0x0400) >> 9) | ((value & 0x0300) >> 4));
  CCAP3H = (value & 0x00FF);
} 


void PCA_3_10_bit_PWM_compare_value(unsigned int value)	
{
	PCA_PWM3 &= 0xF2;
  PCA_PWM3 |= (((value & 0x0400) >> 10) | ((value & 0x0300) >> 6));
	CCAP3L = (value & 0x00FF);
} 
