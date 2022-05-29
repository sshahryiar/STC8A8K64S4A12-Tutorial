#include "STC8xxx.h"
#include "BSP.h"


void setup(void);


void main(void)
{	
	setup();
	
	while(1)
	{
		P55_toggle;
		
		if(P52_get_input == 0)
		{
			delay_ms(400);
		}
		
		delay_ms(200);
	};
}


void setup(void)
{
	P55_open_drain_mode;
	
	P52_input_mode;
	P52_pull_up_enable;
}
