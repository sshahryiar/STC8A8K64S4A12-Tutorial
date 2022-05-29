/*
SS          MOSI        MISO        SCLK    Hex         Option
P1.2        P1.3        P1.4        P1.5    0x00        option 1
P2.2        P2.3        P2.4        P2.5    0x04        option 2
P7.4        P7.5        P7.6        P7.7    0x08        option 3
P3.5        P3.4        P3.3        P3.2    0x0C        option 4
*/

#define SPI_clear                                                        do{\
                                                                             SPCTL = 0x00; \
                                                                             SPSTAT = 0xC0; \
                                                                             SPDAT = 0x00;}while(0)
                                                                            

#define SPI_timeout                                                      300                                                                             
                                                                             

#define SPI_pin_option(value)                                            do{P_SW1 |= value;}while(0)


#define SPI_pins(value)

#define SPI_disable                                                      bit_clr(SPCTL, 6)
#define SPI_enable                                                       bit_set(SPCTL, 6)

//clk
#define SPI_clk_sysclk_div_4                                             0x00
#define SPI_clk_sysclk_div_8                                             0x01
#define SPI_clk_sysclk_div_16                                            0x02
#define SPI_clk_sysclk_div_32                                            0x03

//MS
#define SPI_slave                                                        0x00
#define SPI_master                                                       0x10

//data_orientation
#define SPI_MSB_first                                                    0x00
#define SPI_LSB_first                                                    0x20

//CPHA
#define SPI_CPHA_leading                                                 0x00
#define SPI_CPHA_trailing                                                0x04

//CPOL
#define SPI_CLK_CPOL_idle_low                                            0x00
#define SPI_CLK_CPOL_idle_high                                           0x08

//ss
#define SPI_SS_not_ignored                                              0x00
#define SPI_SS_ignored                                                  0x80



#define SPI_setup(clk, MS, data_orientation, CPHA, CPOL, ss)            do{ \
                                                                            SPI_clear; \
                                                                            SPCTL |= (clk | MS \
                                                                                    | data_orientation \
                                                                                    | CPHA \
                                                                                    | CPOL \
                                                                                    | ss); \
                                                                          }while(0)


unsigned char SPI_transfer(unsigned char write_value)
{
  unsigned char read_value = 0x00;
  unsigned int timeout = SPI_timeout;

  SPDAT = write_value;
  while((!check_SPI_flag) && (timeout > 0)) 
  {
    timeout--;
    delay_ms(1);
  };

  clear_SPI_flag;
  clear_SPI_write_collision_flag;

  read_value = SPDAT;
  
  return read_value;
}                                                      
