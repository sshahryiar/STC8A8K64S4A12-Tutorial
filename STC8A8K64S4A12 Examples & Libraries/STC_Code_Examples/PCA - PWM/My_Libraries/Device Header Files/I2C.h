/*
SCL         SDA       	Hex            Option
P1.5        P1.4   	    0x00           option 1
P2.5        P2.4   	    0x10           option 2
P7.7        P7.6   	    0x20           option 3
P3.2        P3.3   	    0x30           option 4
*/

#define I2C_pin_option(value)             				do{P_SW2 |= value;}while(0)

//Timeout
#define I2C_timeout                     1000


//state
#define I2C_disable									    0x00
#define I2C_enable										0x80

//mode
#define I2C_slave_mode									0x00
#define I2C_master_mode									0x40


#define I2C_setup(state, mode, clk)						do{ \
														   	bit_set(P_SW2, 7); \ 
														   	I2CCFG = (state | mode | (clk & 0x3F)); \ 
                                							bit_clr(P_SW2, 7); \
														  }while(0)

void I2C_wait(void)
{
	unsigned int t = I2C_timeout;
  
  while((check_I2C_master_flag == FALSE) && (t > 0))
  {
    t--;
    delay_ms(1);
  };
	clear_I2C_master_flag;
}


void I2C_start(void)
{
	bit_set(P_SW2, 7);
	I2CMSCR = 0x01;
	I2C_wait();
	bit_clr(P_SW2, 7);	
}


void I2C_stop(void)
{
	bit_set(P_SW2, 7);
	I2CMSCR = 0x06;
	I2C_wait();
	bit_clr(P_SW2, 7);
}


void I2C_write(unsigned char value)
{
	bit_set(P_SW2, 7);
	I2CTXD = value;
	I2CMSCR = 0x02;
	I2C_wait();
	I2CMSCR = 0x03;
	I2C_wait();
	bit_clr(P_SW2, 7);	
}


unsigned char I2C_read(unsigned char ACK_state)
{
	unsigned char value = 0x00;

	bit_set(P_SW2, 7);
	I2CMSCR = 0x04;
	I2C_wait();
	value = I2CRXD;
	I2CMSST = ~ACK_state;
	I2CMSCR = 0x05;
	I2C_wait();
	bit_clr(P_SW2, 7);	

	return value;
}