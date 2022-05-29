#define read_cmd                     0x00
#define write_cmd                    0x80

#define second_reg                   0x00
#define minute_reg                   0x01
#define hour_reg                     0x02
#define day_reg                      0x03
#define date_reg                     0x04
#define month_reg                    0x05
#define year_reg                     0x06
#define alarm1sec_reg                0x07
#define alarm1min_reg                0x08
#define alarm1hr_reg                 0x09
#define alarm1date_reg               0x0A
#define alarm2min_reg                0x0B
#define alarm2hr_reg                 0x0C
#define alarm2date_reg               0x0D
#define control_reg                  0x0E
#define status_reg                   0x0F
#define ageoffset_reg                0x10
#define tempMSB_reg                  0x11
#define tempLSB_reg                  0x12
#define tempdisable_reg              0x13
#define sramaddr_reg                 0x18
#define sramdata_reg                 0x19

#define am                             0
#define pm                             1
#define hr24                           0
#define hr12                           1

#define DS3234_SS_HIGH			       P12_high
#define DS3234_SS_LOW			       P12_low


unsigned char s = 10;
unsigned char min = 10;
unsigned char hr = 10;
unsigned char ampm = pm;
unsigned char dy = 1;
unsigned char dt = 1;
unsigned char mt = 1;
unsigned char yr = 1;
unsigned char hr_format = hr12;


unsigned char bcd_to_decimal(unsigned char d);
unsigned char decimal_to_bcd(unsigned char d);
void DS3234_init(void);
unsigned char DS3234_read(unsigned char addr);
void DS3234_write(unsigned char addr, unsigned char value);
float DS3234_get_temp(void);
void DS3234_write_SRAM(unsigned char addr, unsigned char value);
unsigned char DS3234_read_SRAM(unsigned char addr);
void DS3234_get_time(unsigned short hour_format);
void DS3234_get_date(void);
void DS3234_set_time(unsigned char hSet, unsigned char mSet, unsigned char sSet, unsigned char am_pm_state, unsigned char hour_format);
void DS3234_set_date(unsigned char daySet, unsigned char dateSet, unsigned char monthSet, unsigned char yearSet);
