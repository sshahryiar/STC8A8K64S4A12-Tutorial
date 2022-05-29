#include "STC8xxx.h"
#include "BSP.h"
#include "LCD.c"
#include "lcd_print.c"
#include "DS3234.c"


#define SET           1
#define INC           2
#define SAVE          3

#define keypad_dly    10
#define disp_dly      90


void setup(void);
unsigned char get_keypad(void);
void display_value(unsigned char y_pos, unsigned char x_pos, unsigned char value);
void show_temperature();
void display_time(void);
void get_date_time_data(void);
unsigned char change_value(unsigned char y_pos, unsigned char x_pos, unsigned char value, unsigned char max_value, unsigned char min_value);
void setting(void);
void show_day(unsigned char value);


void main(void)
{

  setup();
	
	
	while(1)
	{
    P55_toggle;
    setting();
    get_date_time_data();
    show_temperature();
    display_time();
    delay_ms(200);
	};
}


void setup(void)
{
  CLK_set_sys_clk(IRC_24M, 2, MCLK_SYSCLK_no_output, MCLK_out_P54);

  P40_input_mode;
  P41_input_mode;
  P42_input_mode;
  
  P55_open_drain_mode;
  
  DS3234_init();

  LCD_init();
  LCD_clear_home();
  load_custom_symbol();
}


unsigned char get_keypad()
{
  if(!P40_get_input)
  {
    delay_ms(keypad_dly);
    return SET;
  }
  
  else if(!P41_get_input)
  {
    delay_ms(keypad_dly);
    return INC;
  }
  
  else if(!P42_get_input)
  {
    delay_ms(keypad_dly);
    return SAVE;
  }
  
  else
  {
    return 0;
  }
}


void display_value(unsigned char y_pos, unsigned char x_pos, unsigned char value)
{
  unsigned char ch = 0x00;

  ch = (value / 10);
  LCD_goto((x_pos - 1), (y_pos - 1));
  LCD_putchar((ch + 0x30));
  ch = (value % 10);
  LCD_goto(x_pos, (y_pos - 1));
  LCD_putchar((ch + 0x30));
}


void display_time()
{
  display_value(1, 1, hr);
  LCD_goto(2, 0);
  LCD_putstr(":");
  display_value(1, 4, min);
  LCD_goto(5, 0);
  LCD_putstr(":");
  
  display_value(1, 7, s);

  switch(hr_format)
  {
    case hr12:
    {
      switch(ampm)
      {
        case pm:
        {
          LCD_goto(9, 0);
          LCD_putstr("PM");
          break;
        }
        default:
        {
          LCD_goto(9, 0);
          LCD_putstr("AM");
          break;
        }
      }
      break;
    }
    default:
    {
      LCD_goto(9, 0);
      LCD_putstr("  ");
      break;
    }
  }

  display_value(2, 1, dt);
  LCD_goto(2, 1);
  LCD_putstr("/");
  display_value(2, 4, mt);
  LCD_goto(5, 1);
  LCD_putstr("/");
  display_value(2, 7, yr);
  show_day(dy);
}


void show_temperature()
{
  float t = 0;
  unsigned char temp = 0;

  t = DS3234_get_temp();
  
  temp = t;
  display_value(2, 10, temp);
  LCD_goto(11, 1);
  LCD_putstr(".");
  temp = ((t - temp) * 100);
  display_value(2, 13, temp);
  print_symbol(14, 1, 0);
  LCD_goto(15, 1);
  LCD_putstr("C");
}


void get_date_time_data()
{
  DS3234_get_date();
  DS3234_get_time(hr_format);
}


unsigned char change_value(unsigned char y_pos, unsigned char x_pos, unsigned char value, unsigned char max_value, unsigned char min_value)
{
  while(TRUE)
  {
    if(get_keypad() == INC)
    {
      value++;
    }
    
    if(value > max_value)
    {
      value = min_value;
    }

    LCD_goto((x_pos - 1), (y_pos - 1));
    LCD_putstr("  ");    
    delay_ms(disp_dly);
    
    display_value(y_pos, x_pos, value);
    delay_ms(disp_dly);
    
    if(get_keypad() == SAVE)
    {
      while(get_keypad() == SAVE);
      return value;
    }
  }
}


void setting()
{
     bit set_cmd;
     unsigned char tmp = 0;

     set_cmd = 0;
     if(get_keypad() == SET)
     {
         while(get_keypad() == SET);
         set_cmd = 1;
     }
     
     while(set_cmd)
     {
       while(1)
       {
         if(get_keypad() == INC)
         {
           tmp++;
         }
         if(tmp > 2)
         {
           tmp = 0;
         }
           
           
         LCD_goto(9, 0);
         LCD_putstr(" ");
           
         delay_ms(disp_dly);
         switch(tmp)
         {
            case 1:
            {
              LCD_goto(9, 0);
              LCD_putstr("AM");                    
              ampm = am;
              hr_format = hr12;
              break;
            }
         
            case 2:
            {
              LCD_goto(9, 0);
              LCD_putstr("PM"); 
              ampm = pm;
              hr_format = hr12;
              break;
            }

            default:
            {
              LCD_goto(9, 0);
              LCD_putstr("24"); 
              hr_format = hr24;
              break;
            }
          }

          delay_ms(disp_dly);
           
          if(get_keypad() == SAVE)
          {
            break;
          }
         }
         s = change_value(1, 7, s, 59, 0);
         min = change_value(1, 4, min, 59, 0);
         
         switch(hr_format)
         {
           case hr12:
           {
             hr = change_value(1, 1, hr, 12, 1);
             break;
           }
           default:
           {
             hr = change_value(1, 1, hr, 23, 0);
             break;
           }
         }

         dt = change_value(2, 1, dt, 31, 1);
         mt = change_value(2, 4, mt, 12, 1);
         yr = change_value(2, 7, yr, 99, 0);

         tmp = dy;
         while(1)
         {
           if(get_keypad() == INC)
           {
             tmp++;
           }
           if(tmp > 7)
           {
             tmp = 1;
           }

          
           LCD_goto(13, 0);
           LCD_putstr("    "); 
           delay_ms(disp_dly);
           show_day(tmp);
           delay_ms(disp_dly);

           if(get_keypad() == SAVE)
           {
             dy = tmp;
             break;
           }
         }
         
         DS3234_set_time(hr, min, s, ampm, hr_format);
         DS3234_set_date(dy, dt, mt, yr);
         set_cmd = 0;
     }
}


void show_day(unsigned char value)
{
  LCD_goto(13, 0);
  
  switch(value)
  {
    case 1:
    {
      LCD_putstr("SUN"); 
      break;
    }
    case 2:
    {
      LCD_putstr("MON");
      break;
    }
    case 3:
    {
      LCD_putstr("TUE");
      break;
    }
    case 4:
    {
      LCD_putstr("WED");
      break;
    }
    case 5:
    {
      LCD_putstr("THR");
      break;
    }
    case 6:
    {
      LCD_putstr("FRI");
      break;
    }
    case 7:
    {
      LCD_putstr("SAT");
      break;
    }
  }
}