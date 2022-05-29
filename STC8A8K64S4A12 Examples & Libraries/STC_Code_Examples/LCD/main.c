#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"


void setup(void);
void show_value(unsigned char value);


void main(void)
{
    unsigned char s = 0x00;

    char txt1[] = {"MICROARENA"};
    char txt2[] = {"SShahryiar"};
    char txt3[] = {"STC8A Series"};
    char txt4[] = {"STC8A8K64S4A12"};
    
	setup();
	
	LCD_clear_home();

    LCD_goto(3, 0);
    LCD_putstr(txt1);
    LCD_goto(3, 1);
    LCD_putstr(txt2);
    delay_ms(4000);

    LCD_clear_home();

    for(s = 0; s < 12; s++)
    {
        LCD_goto((2 + s), 0);
        LCD_putchar(txt3[s]);
        delay_ms(60);
    }
    for(s = 0; s < 14; s++)
    {
        LCD_goto((1 + s), 1);
        LCD_putchar(txt4[s]);
        delay_ms(60);
    }
    delay_ms(4000);

    s = 0;
    LCD_clear_home();

    LCD_goto(3, 0);
    LCD_putstr(txt1);

    while(1)
    {
        show_value(s);
        s++;
        delay_ms(400);
    };
}


void setup(void)
{
    CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_div_1, MCLK_out_P54);
    
    LCD_init();
}


void show_value(unsigned char value)
{
   unsigned char ch = 0x00;

   ch = ((value / 100) + 0x30);
   LCD_goto(6, 1);
   LCD_putchar(ch);

   ch = (((value / 10) % 10) + 0x30);
   LCD_goto(7, 1);
   LCD_putchar(ch);

   ch = ((value % 10) + 0x30);
   LCD_goto(8, 1);
   LCD_putchar(ch);
}