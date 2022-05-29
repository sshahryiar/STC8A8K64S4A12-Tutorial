#define DS18B20_GPIO_init()				P30_quasi_bidirectional_mode

#define DS18B20_IN()					P30_get_input

#define DS18B20_OUT_LOW()				P30_low
#define DS18B20_OUT_HIGH()				P30_high

#define TRUE                      1
#define FALSE                     0


unsigned char onewire_reset(void); 
void onewire_write_bit(unsigned char bit_value);
unsigned char onewire_read_bit(void);
void onewire_write(unsigned char value);    
unsigned char onewire_read(void);
