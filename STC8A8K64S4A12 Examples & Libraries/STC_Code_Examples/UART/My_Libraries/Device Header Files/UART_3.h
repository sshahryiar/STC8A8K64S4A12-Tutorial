/*
RXD         TXD       	Hex            Option
P0.0        P0.1   	    0x00           option 1
P5.0        P5.1   	    0x02           option 2
*/

#define UART3_pin_option(value)             do{P_SW2 |= value;}while(0)

//timer_sel
#define UART3_baud_source_TMR2				0x00
#define UART3_baud_source_TMR3				0x40

//T_value
#define UART3_timer_1T						0x00
#define UART3_timer_12T		    			0x01


void UART3_init(unsigned long baud, unsigned char timer_sel, unsigned char T_value, unsigned long sysclk)
{
	unsigned long tmp = 0x00000000;

	S3CON = (0x10 | timer_sel);

	tmp = (sysclk / (4 * baud));

	if(T_value == UART3_timer_12T)
	{
		tmp /= 12;
	}

	tmp = (65536 - tmp);

	if(timer_sel == UART3_baud_source_TMR2)
	{
		if(T_value == UART3_timer_1T)
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
		if(T_value == UART3_timer_1T)
		{
			TMR3_setup(TMR3_sysclk, TMR3_clk_prescalar_1T, TMR3_no_clk_out);
		}

		else
		{
			TMR3_setup(TMR3_sysclk, TMR3_clk_prescalar_12T, TMR3_no_clk_out);
		}

		TMR3_load_counter_16(tmp);
		TMR3_start;
	}	
}


void UART3_write_buffer(unsigned char value)
{
  S3BUF = value;
  while(check_UART_3_TX_flag == FALSE);
  clear_UART_3_TX_flag;
}


unsigned char UART3_read_buffer(void)
{
	clear_UART_3_RX_flag;
  return S3BUF;
}
