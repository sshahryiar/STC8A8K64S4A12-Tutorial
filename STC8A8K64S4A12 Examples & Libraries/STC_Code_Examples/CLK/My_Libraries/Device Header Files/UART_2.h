/*
RXD         TXD       	Hex            Option
P1.0        P1.1   	    0x00           option 1
P4.0        P4.2   	    0x01           option 2
*/

#define UART2_pin_option(value)             do{P_SW2 |= value;}while(0)

//T_value
#define UART2_timer_1T						0x00
#define UART2_timer_12T		    			0x01


void UART2_init(unsigned int baud, unsigned char T_value, unsigned long sysclk)
{
	unsigned long tmp = 0x00000000;

	S2CON = 0x10;

	tmp = (sysclk / (4 * baud));

	if(T_value == UART2_timer_12T)
	{
		tmp /= 12;
	}

	tmp = (65536 - tmp);

	if(T_value == UART2_timer_1T)
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


void UART2_write_buffer(unsigned char value)
{
  S2BUF = value;
  while(check_UART_2_TX_flag == FALSE);
  clear_UART_2_TX_flag;
}


unsigned char UART2_read_buffer(void)
{ 
  clear_UART_2_RX_flag;
  return S2BUF;
}
