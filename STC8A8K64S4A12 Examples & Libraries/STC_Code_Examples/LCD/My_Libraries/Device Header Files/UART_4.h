/*
RXD         TXD       	Hex            Option
P0.2        P0.3   	    0x00           option 1
P5.2        P5.3   	    0x04           option 2
*/

#define UART4_pin_option(value)             do{P_SW2 |= value;}while(0)

//timer_sel
#define UART4_baud_source_TMR2				0x00
#define UART4_baud_source_TMR4				0x40

//T_value
#define UART4_timer_1T						0x00
#define UART4_timer_12T		    			0x01


void UART4_init(unsigned long baud, unsigned char timer_sel, unsigned char T_value, unsigned long sysclk)
{
	unsigned long tmp = 0x00000000;

	S4CON = (0x10 | timer_sel);

	tmp = (sysclk / (4 * baud));

	if(T_value == UART4_timer_12T)
	{
		tmp /= 12;
	}

	tmp = (65536 - tmp);

	if(timer_sel == UART4_baud_source_TMR2)
	{
		if(T_value == UART4_timer_1T)
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
		if(T_value == UART4_timer_1T)
		{
			TMR4_setup(TMR4_sysclk, TMR4_clk_prescalar_1T, TMR4_no_clk_out);
		}

		else
		{
			TMR4_setup(TMR4_sysclk, TMR4_clk_prescalar_12T, TMR4_no_clk_out);
		}

		TMR4_load_counter_16(tmp);
		TMR4_start;
	}
}


void UART4_write_buffer(unsigned char value)
{
  S4BUF = value;
  while(check_UART_4_TX_flag == FALSE);
  clear_UART_4_TX_flag;
}


unsigned char UART4_read_buffer(void)
{
	clear_UART_4_RX_flag;
  return S4BUF;
}
