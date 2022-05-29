/*
RXD         TXD       	Hex            Option
P3.0        P3.1   	    0x00           option 1
P3.6        P3.7   	    0x40           option 2
P1.6        P1.7   	    0x80           option 3
P4.3        P4.4   	    0xC0           option 4
*/

#define UART1_pin_option(value)             do{P_SW1 |= value;}while(0)

//timer_sel
#define UART1_baud_source_TMR2				0x00
#define UART1_baud_source_TMR1_mode_0   	0x40

//T_value
#define UART1_timer_1T						0x00
#define UART1_timer_12T		    			0x01


void UART1_init(unsigned long baud, unsigned char timer_sel, unsigned char T_value, unsigned long sysclk)
{
	unsigned long tmp = 0x00000000;

	SCON = 0x50;

	tmp = (sysclk / (4 * baud));

	if(T_value == UART1_timer_12T)
	{
		tmp /= 12;
	}

	tmp = (65536 - tmp);

	if(timer_sel == UART1_baud_source_TMR2)
	{
		if(T_value == UART1_timer_1T)
		{
			TMR2_setup(TMR2_sysclk, TMR2_clk_prescalar_1T);
		}

		else
		{
			TMR2_setup(TMR2_sysclk, TMR2_clk_prescalar_12T);
		}

		TMR2_load_counter_16(tmp);
		TMR2_start;
	}

	else
	{
		if(T_value == UART1_timer_1T)
		{
			TMR1_setup(TMR1_16_bit_auto_reload, TMR1_sysclk, TMR1_clk_prescalar_1T, TMR1_int_gate, TMR1_no_clk_out);
		}

		else
		{
			TMR1_setup(TMR1_16_bit_auto_reload, TMR1_sysclk, TMR1_clk_prescalar_1T, TMR1_int_gate, TMR1_no_clk_out);
		}

		TMR1_load_counter_16(tmp);
		TMR1_start;
	}
}


void UART1_write_buffer(unsigned char value)
{
  SBUF = value;
  while(check_UART_1_TX_flag == FALSE);
  clear_UART_1_TX_flag;
}


unsigned char UART1_read_buffer(void)
{
  clear_UART_1_RX_flag;
  return SBUF;
}
