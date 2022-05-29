#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"


#define sync_high     5850    //approx 1.3 * 4500us
#define sync_low      3150    //approx 0.7 * 4500us
#define one_high      2200    //approx 1.3 * (2250 - 562.5)us
#define one_low       1180    //approx 0.7 * (2250 - 562.5)us  
#define zero_high     732     //approx 1.3 * (1125 - 562.5)us
#define zero_low      394     //approx 0.7 * (1125 - 562.5)us


unsigned char bits = 0x00; 
unsigned char received = 0x00; 

unsigned int frames[33];


void setup(void);
void erase_frames(void);
unsigned char decode(unsigned char start_pos, unsigned char end_pos);
void decode_NEC(unsigned char *addr, unsigned char *cmd);


void EXT_0_ISR(void)        
interrupt 0
{
  frames[bits] = TMR0_get_counter(); 
  bits++; 
  TMR0_start; 

  if(bits >= 33) 
  { 
    received = 1; 
    _disable_global_interrupt; 
    TMR0_stop; 
  } 
  
  TMR0_load_counter_16(0x0000); 
}


void main(void)
{
  unsigned char addr = 0x00;
  unsigned char cmd = 0x00;
    
  setup();

  LCD_goto(1, 0); 
  LCD_putstr("NEC IR Decoder"); 
  LCD_goto(0, 1); 
  LCD_putstr("Adr      Cmd");

  while(1)
  {
     if(received != FALSE)
		 {
		   decode_NEC(&addr, &cmd);
       
       print_C(3, 1, addr); 
       print_C(12, 1, cmd); 
       
			 delay_ms(100);
			 
       erase_frames();
			 _enable_global_interrupt;
		 }
  };
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_div_1, MCLK_SYSCLK_no_output);
  
  erase_frames();
  
  TMR0_setup(TMR0_16_bit_non_auto_reload, \
             TMR0_sysclk, \
             TMR0_clk_prescalar_12T, \
             TMR0_ext_gate, \
             TMR0_no_clk_out);
  
  EXT_0_priority_0;
  EXT_0_falling_edge_detection_only;
  _enable_EXT_0_interrupt;
  _enable_global_interrupt;

  LCD_init();
  LCD_clear_home();
}


void erase_frames(void)
{
	for(bits = 0; bits < 33; bits++)
	{
		frames[bits] = 0x0000;
	}

	TMR0_load_counter_16(0x0000);
  
	received = 0;
	bits = 0;
}


unsigned char decode(unsigned char start_pos, unsigned char end_pos)
{
	unsigned char value = 0;

	for(bits = start_pos; bits <= end_pos; bits++)
	{
		value <<= 1;
		
		if((frames[bits] >= one_low) && (frames[bits] <= one_high))
		{
			value |= 1;
		}
		
		else if((frames[bits] >= zero_low) && (frames[bits] <= zero_high))
		{
			value |= 0;
		}
		
		else if((frames[bits] >= sync_low) && (frames[bits] <= sync_high))
		{
			return 0xFF;
		}
	}

	return value;
}


void decode_NEC(unsigned char *addr, unsigned char *cmd)
{
	*addr = decode(2, 9);
	*cmd = decode(18, 25);
}
