#include "STC8xxx.h"
#include "BSP.h"


void setup(void);


void main(void)
{
    setup();
    
    while(1)
    {
        if(CMP_get_comp_status != 0x00)
        {
            P55_low;
        }
        else
        {
            P55_high;
        }
    };
}


void setup(void)
{
    CLK_set_sys_clk(IRC_24M, \ 
                    2, \
                    MCLK_SYSCLK_no_output, \
                    MCLK_out_P54);
    
    P55_open_drain_mode;
    
    CMP_setup(CMP_positive_input_P37, \
              CMP_negative_input_P36, \
              CMP_output_disable, \
              CMP_result_positive_output, \
              CMP_enable_analog_filtering, \
              0x04);
    
    CMP_enable;
}