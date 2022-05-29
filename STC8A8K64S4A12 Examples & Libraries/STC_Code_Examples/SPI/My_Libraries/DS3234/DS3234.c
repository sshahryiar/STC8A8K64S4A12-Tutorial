#include "DS3234.h"


unsigned char bcd_to_decimal(unsigned char d)
{                                                                                          
  return ((d & 0x0F) + (((d & 0xF0) >> 4) * 10));
}                                
                                                             

unsigned char decimal_to_bcd(unsigned char d)
{
  return (((d / 10) << 4) & 0xF0) | ((d % 10) & 0x0F);
}     


void DS3234_init(void)
{
  P12_push_pull_mode;
  DS3234_SS_HIGH;

  SPI_pin_option(0x00);

  SPI_setup(SPI_clk_sysclk_div_16, \
            SPI_master, \
            SPI_MSB_first, \
            SPI_CPHA_trailing, \
            SPI_CLK_CPOL_idle_low, \
            SPI_SS_ignored);
  
  SPI_enable;
  
  DS3234_write(control_reg, 0x20);
  DS3234_write(status_reg, 0x48);
  DS3234_set_time(hr, min, s, ampm, hr_format);
  DS3234_set_date(dy, dt, mt, yr);
}


unsigned char DS3234_read(unsigned char addr)
{
  unsigned char value = 0;

  DS3234_SS_LOW;
  SPI_transfer(addr | read_cmd);
  value = SPI_transfer(0x00);
  DS3234_SS_HIGH;

  return value;
}


void DS3234_write(unsigned char addr, unsigned char value)
{
  unsigned long temp = 0;

  DS3234_SS_LOW;
  temp = (addr | write_cmd);
  SPI_transfer(temp);
  SPI_transfer(value);
  DS3234_SS_HIGH;
}


float DS3234_get_temp(void)
{
  float t = 0;
  signed char highByte = 0;
  unsigned char lowByte = 0;

  highByte = DS3234_read(tempMSB_reg);
  lowByte = DS3234_read(tempLSB_reg);

  lowByte >>= 6;
  t = (lowByte & 0x03);
  t *= 0.25;
  t += highByte;

  return t;
} 


void DS3234_write_SRAM(unsigned char addr, unsigned char value)
{
  DS3234_write(sramaddr_reg, addr);
  DS3234_write(sramdata_reg, value);
}


unsigned char DS3234_read_SRAM(unsigned char addr)
{
  unsigned char value = 0;

  DS3234_SS_LOW;
  SPI_transfer(sramaddr_reg);
  SPI_transfer(addr);
  value = DS3234_read(sramdata_reg);
  DS3234_SS_HIGH;

  return value;
}


void DS3234_get_time(unsigned short hour_format)
{
  unsigned char tmp = 0;

  s = DS3234_read(second_reg);
  s = bcd_to_decimal(s);
  min = DS3234_read(minute_reg);
  min = bcd_to_decimal(min);
  tmp = DS3234_read(hour_reg);
  
  switch(hour_format)
  {
    case hr12:
    {
       ampm = (tmp & 0x20);
       ampm >>= 5;
       hr = (tmp & 0x1F);
       hr = bcd_to_decimal(hr);
       break;
    }
    
    default:
    {
       hr = (0x3F & tmp);
       hr = bcd_to_decimal(hr);
       break;
    }
  }
}


void DS3234_get_date(void)
{
  yr = DS3234_read(year_reg);
  yr = bcd_to_decimal(yr);
  mt = (0x1F & DS3234_read(month_reg));
  mt = bcd_to_decimal(mt);
  dt = (0x3F & DS3234_read(date_reg));
  dt = bcd_to_decimal(dt);
  dy = (0x07 & DS3234_read(day_reg));
  dy = bcd_to_decimal(dy);
}


void DS3234_set_time(unsigned char hSet, unsigned char mSet, unsigned char sSet, unsigned char am_pm_state, unsigned char hour_format)
{
  unsigned char tmp = 0;

  DS3234_write(second_reg, (decimal_to_bcd(sSet)));
  DS3234_write(minute_reg, (decimal_to_bcd(mSet)));
  
  switch(hour_format)
  {
    case hr12:
    {
       switch(am_pm_state)
       {
          case pm:
          {
               tmp = 0x20;
               break;
          }
          
          default:
          {
               tmp = 0x00;
               break;
          }
       }
       
       DS3234_write(hour_reg, ((tmp | 0x40 | (0x1F & (decimal_to_bcd(hSet))))));
       break;
    }
    
    default:
    {
       DS3234_write(hour_reg, (0xBF & (0x3F & (decimal_to_bcd(hSet)))));
       break;
    }
  }
}


void DS3234_set_date(unsigned char daySet, unsigned char dateSet, unsigned char monthSet, unsigned char yearSet)
{
  DS3234_write(day_reg, (decimal_to_bcd(daySet)));
  DS3234_write(date_reg, (decimal_to_bcd(dateSet)));
  DS3234_write(month_reg, (decimal_to_bcd(monthSet)));
  DS3234_write(year_reg, (decimal_to_bcd(yearSet)));
}