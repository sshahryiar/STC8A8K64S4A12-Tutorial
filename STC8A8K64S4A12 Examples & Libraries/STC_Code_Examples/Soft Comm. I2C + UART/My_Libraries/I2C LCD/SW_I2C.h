#define SDA_DIR_OUT()   P10_push_pull_mode
#define SDA_DIR_IN()    P10_input_mode

#define SCL_DIR_OUT()   P11_push_pull_mode
#define SCL_DIR_IN()    P11_input_mode

#define SDA_HIGH()      P10_high
#define SDA_LOW()       P10_low

#define SCL_HIGH()      P11_high
#define SCL_LOW()       P11_low

#define SDA_IN()        P10_get_input

#define I2C_ACK         0xFF
#define I2C_NACK        0x00

#define I2C_timeout     1000


void SW_I2C_init(void);
void SW_I2C_start(void);
void SW_I2C_stop(void);
unsigned char SW_I2C_read(unsigned char ack);
void SW_I2C_write(unsigned char value);
void SW_I2C_ACK_NACK(unsigned char mode);
unsigned char SW_I2C_wait_ACK(void);
