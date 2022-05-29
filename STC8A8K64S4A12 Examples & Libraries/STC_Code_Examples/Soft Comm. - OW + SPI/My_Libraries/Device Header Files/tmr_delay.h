
/*

small time delay = ((1T / sysclk) * value)

large time delay = ((12T / sysclk) * value)

*/

void small_delay_TMR_0(unsigned int value)
{
	TMR0_setup(TMR0_16_bit_non_auto_reload, \
			   TMR0_sysclk, \
			   TMR0_clk_prescalar_1T, \
			   TMR0_int_gate, \
			   TMR0_no_clk_out);

	TMR0_load_counter_8(0x00, 0x00);
	TMR0_start;

	while(value >= TMR0_get_counter());
	TMR0_stop;
}


void large_delay_TMR_0(unsigned int value)
{
	TMR0_setup(TMR0_16_bit_non_auto_reload, \
			   TMR0_sysclk, \
			   TMR0_clk_prescalar_12T, \
			   TMR0_int_gate, \
			   TMR0_no_clk_out);

	TMR0_load_counter_8(0x00, 0x00);
	TMR0_start;

	while(value >= TMR0_get_counter());
	TMR0_stop;
}


void small_delay_TMR_1(unsigned int value)
{
	TMR1_setup(TMR1_16_bit_non_auto_reload, \
			   TMR1_sysclk, \
			   TMR1_clk_prescalar_1T, \
			   TMR1_int_gate, \
			   TMR1_no_clk_out);

	TMR1_load_counter_8(0x00, 0x00);
	TMR1_start;

	while(value >= TMR1_get_counter());
	TMR1_stop;
}


void large_delay_TMR_1(unsigned int value)
{
	TMR1_setup(TMR1_16_bit_non_auto_reload, \
			   TMR1_sysclk, \
			   TMR1_clk_prescalar_12T, \
			   TMR1_int_gate, \
			   TMR1_no_clk_out);

	TMR1_load_counter_8(0x00, 0x00);
	TMR1_start;

	while(value >= TMR1_get_counter());
	TMR1_stop;
}


void small_delay_TMR_2(unsigned int value)
{
	TMR2_setup(TMR2_sysclk, \
			   TMR2_clk_prescalar_1T);

	TMR2_load_counter_8(0x00, 0x00);
	TMR2_start;

	while(value >= TMR2_get_counter());
	TMR2_stop;
}


void large_delay_TMR_2(unsigned int value)
{
	TMR2_setup(TMR2_sysclk, \
			   TMR2_clk_prescalar_12T);

	TMR2_load_counter_8(0x00, 0x00);
	TMR2_start;

	while(value >= TMR2_get_counter());
	TMR2_stop;
}


void small_delay_TMR_3(unsigned int value)
{
	TMR3_setup(TMR3_sysclk, \
			   TMR3_clk_prescalar_1T, \
			   TMR3_no_clk_out);

	TMR3_load_counter_8(0x00, 0x00);
	TMR3_start;

	while(value >= TMR3_get_counter());
	TMR3_stop;
}


void large_delay_TMR_3(unsigned int value)
{
	TMR3_setup(TMR3_sysclk, \
			   TMR3_clk_prescalar_12T, \
			   TMR3_no_clk_out);

	TMR3_load_counter_8(0x00, 0x00);
	TMR3_start;

	while(value >= TMR3_get_counter());
	TMR3_stop;
}


void small_delay_TMR_4(unsigned int value)
{
	TMR4_setup(TMR4_sysclk, \
			   TMR4_clk_prescalar_1T, \
			   TMR4_no_clk_out);

	TMR4_load_counter_8(0x00, 0x00);
	TMR4_start;

	while(value >= TMR4_get_counter());
	TMR4_stop;
}


void large_delay_TMR_4(unsigned int value)
{
	TMR4_setup(TMR4_sysclk, \
			   TMR4_clk_prescalar_12T, \
			   TMR4_no_clk_out);

	TMR4_load_counter_8(0x00, 0x00);
	TMR4_start;

	while(value >= TMR4_get_counter());
	TMR4_stop;
}