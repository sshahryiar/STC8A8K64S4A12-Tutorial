#define IAP_disable                         bit_clr(IAP_CONTR, 7)
#define IAP_enable                          bit_set(IAP_CONTR, 7)

#define IAP_SW_reset                        bit_set(IAP_CONTR, 5) 

#define IAP_CMD_status                      get_bit(IAP_CONTR, 4)
// 0 = ok           1 = fail

#define IAP_trigger                         do{ \
                                                IAP_TRIG = 0x5A; \
                                                IAP_TRIG = 0xA5; \
                                              }while(0)

#define IAP_address(value)                  do{ \
                                                IAP_ADDRL = (value & 0x00FF); \
                                                IAP_ADDRH = ((value & 0xFF00) >> 0x08); \
                                              }while(0)

#define IAP_no_command                      0x00
#define IAP_read_command                    0x01
#define IAP_write_command                   0x02
#define IAP_erase_command                   0x03                                              

#define IAP_clear                           do{ \
                                                IAP_CONTR = 0x00; \
                                                IAP_CMD = IAP_no_command; \
                                                IAP_TRIG = 0x00; \
                                                IAP_ADDRH = 0x80; \
                                                IAP_ADDRL = 0x00; \                                                
                                              }while(0)

//IAP_WT
#define IAP_WT_30M                          0x80
#define IAP_WT_24M                          0x81     
#define IAP_WT_20M                          0x82      
#define IAP_WT_12M                          0x83     
#define IAP_WT_6M                           0x84      
#define IAP_WT_3M                           0x85      
#define IAP_WT_2M                           0x86      
#define IAP_WT_1M                           0x87      


#define IAP_WT                              IAP_WT_12M                                   

//SWBS
#define IAP_execute_from_code_area          bit_clr(IAP_CONTR, 6)
#define IAP_execute_from_ISP_area           bit_set(IAP_CONTR, 6)


unsigned char IAP_read(unsigned int address)
{
  unsigned char value = 0x00;

  IAP_CONTR = IAP_WT;
  IAP_CMD = IAP_read_command;
  IAP_address(address);
  IAP_trigger;
  _nop_();
  value = IAP_DATA;
  IAP_clear;

  return value;
}


void IAP_write(unsigned int address, unsigned char value)
{
  IAP_CONTR = IAP_WT;
  IAP_CMD = IAP_write_command;
  IAP_address(address);
  IAP_DATA = value;
  IAP_trigger;
  _nop_();
  IAP_clear;
}


void IAP_erase(unsigned int address)
{
  IAP_CONTR = IAP_WT;
  IAP_CMD = IAP_erase_command;
  IAP_address(address);
  IAP_trigger;
  _nop_();
  IAP_clear;
}
