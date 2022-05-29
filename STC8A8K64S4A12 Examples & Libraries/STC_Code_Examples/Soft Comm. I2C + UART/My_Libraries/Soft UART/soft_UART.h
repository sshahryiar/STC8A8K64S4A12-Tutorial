#define tmr_max_cnt     0xFFFF

//sysclk
#define sysclk              12000000

//baud rate
#define baud_rate           9600

//T_value
#define _1T                 0x01
#define _12T                0x0C

#define tmr_load_value      (tmr_max_cnt - (sysclk / 3 / baud_rate / _1T))

sbit RXD_pin = P1^6;
sbit TXD_pin = P1^7;


unsigned char TXing = 0x00;
unsigned char RXing = 0x00;
unsigned char TX_Bit = 0x00;
unsigned char RX_Bit = 0x00;
unsigned char TX_CNT = 0x00;
unsigned char RX_CNT = 0x00;
unsigned char TX_Data = 0x00;
unsigned char RX_Data = 0x00;
unsigned char TX_done = 0x00;
unsigned char RX_done = 0x00;
unsigned char TX_Buffer = 0x00;
unsigned char RX_Buffer = 0x00;


void soft_UART_init(void);