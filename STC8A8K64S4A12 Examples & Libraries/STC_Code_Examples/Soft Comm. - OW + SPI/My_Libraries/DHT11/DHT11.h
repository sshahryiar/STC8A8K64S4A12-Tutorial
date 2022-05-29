#define DHT11_pin_init     		P10_quasi_bidirectional_mode		

#define DHT11_pin_HIGH        P10_high
#define DHT11_pin_LOW         P10_low

#define DHT11_pin_IN   				P10_get_input			


unsigned char values[5];


void DHT11_init(void);
unsigned char DHT11_get_byte(void);
unsigned char DHT11_get_data(void);
