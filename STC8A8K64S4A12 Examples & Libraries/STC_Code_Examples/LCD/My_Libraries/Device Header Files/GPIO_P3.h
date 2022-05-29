//P30
#define P30_quasi_bidirectional_mode	    do{bit_clr(P3M1, 0); bit_clr(P3M0, 0);}while(0) 
#define P30_push_pull_mode		    	    do{P30_quasi_bidirectional_mode; bit_clr(P3M1, 0); bit_set(P3M0, 0);}while(0)
#define P30_input_mode			    	    do{P30_quasi_bidirectional_mode; bit_set(P3M1, 0); bit_clr(P3M0, 0);}while(0)
#define P30_open_drain_mode		    	    do{P30_quasi_bidirectional_mode; bit_set(P3M1, 0); bit_set(P3M0, 0);}while(0)

#define P30_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P30_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P30_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P30_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P30_high				            bit_set(P3, 0)
#define P30_low 					        bit_clr(P3, 0)
#define P30_toggle				            bit_tgl(P3, 0)
#define P30_get_input			  	        get_bit(P3, 0)

//P31
#define P31_quasi_bidirectional_mode	    do{bit_clr(P3M1, 1); bit_clr(P3M0, 1);}while(0) 
#define P31_push_pull_mode			        do{P31_quasi_bidirectional_mode; bit_clr(P3M1, 1); bit_set(P3M0, 1);}while(0)
#define P31_input_mode				        do{P31_quasi_bidirectional_mode; bit_set(P3M1, 1); bit_clr(P3M0, 1);}while(0)
#define P31_open_drain_mode			        do{P31_quasi_bidirectional_mode; bit_set(P3M1, 1); bit_set(P3M0, 1);}while(0)

#define P31_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P31_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P31_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P31_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P31_high					        bit_set(P3, 1)
#define P31_low 					        bit_clr(P3, 1)
#define P31_toggle				            bit_tgl(P3, 1)
#define P31_get_input  				        get_bit(P3, 1)

//P32
#define P32_quasi_bidirectional_mode	    do{bit_clr(P3M1, 2); bit_clr(P3M0, 2);}while(0) 
#define P32_push_pull_mode			        do{P32_quasi_bidirectional_mode; bit_clr(P3M1, 2); bit_set(P3M0, 2);}while(0)
#define P32_input_mode				        do{P32_quasi_bidirectional_mode; bit_set(P3M1, 2); bit_clr(P3M0, 2);}while(0)
#define P32_open_drain_mode			        do{P32_quasi_bidirectional_mode; bit_set(P3M1, 2); bit_set(P3M0, 2);}while(0)

#define P32_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P32_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P32_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P32_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P32_high					        bit_set(P3, 2)
#define P32_low 					        bit_clr(P3, 2)
#define P32_toggle				            bit_tgl(P3, 2)
#define P32_get_input   			        get_bit(P3, 2)

//P33
#define P33_quasi_bidirectional_mode	    do{bit_clr(P3M1, 3); bit_clr(P3M0, 3);}while(0) 
#define P33_push_pull_mode			        do{P33_quasi_bidirectional_mode; bit_clr(P3M1, 3); bit_set(P3M0, 3);}while(0)
#define P33_input_mode				        do{P33_quasi_bidirectional_mode; bit_set(P3M1, 3); bit_clr(P3M0, 3);}while(0)
#define P33_open_drain_mode			        do{P33_quasi_bidirectional_mode; bit_set(P3M1, 3); bit_set(P3M0, 3);}while(0)

#define P33_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P33_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P33_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P33_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P33_high					        bit_set(P3, 3)
#define P33_low					            bit_clr(P3, 3)
#define P33_toggle				            bit_tgl(P3, 3)
#define P33_get_input				        get_bit(P3, 3)

//P34
#define P34_quasi_bidirectional_mode	    do{bit_clr(P3M1, 4); bit_clr(P3M0, 4);}while(0) 
#define P34_push_pull_mode			        do{P34_quasi_bidirectional_mode; bit_clr(P3M1, 4); bit_set(P3M0, 4);}while(0)
#define P34_input_mode				        do{P34_quasi_bidirectional_mode; bit_set(P3M1, 4); bit_clr(P3M0, 4);}while(0)
#define P34_open_drain_mode			        do{P34_quasi_bidirectional_mode; bit_set(P3M1, 4); bit_set(P3M0, 4);}while(0)

#define P34_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P34_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P34_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P34_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P34_high					        bit_set(P3, 4)
#define P34_low 					        bit_clr(P3, 4)
#define P34_toggle				            bit_tgl(P3, 4)
#define P34_get_input  				        get_bit(P3, 4)

//P35
#define P35_quasi_bidirectional_mode	    do{bit_clr(P3M1, 5); bit_clr(P3M0, 5);}while(0) 
#define P35_push_pull_mode			        do{P35_quasi_bidirectional_mode; bit_clr(P3M1, 5); bit_set(P3M0, 5);}while(0)
#define P35_input_mode				        do{P35_quasi_bidirectional_mode; bit_set(P3M1, 5); bit_clr(P3M0, 5);}while(0)
#define P35_open_drain_mode			        do{P35_quasi_bidirectional_mode; bit_set(P3M1, 5); bit_set(P3M0, 5);}while(0)

#define P35_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P35_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P35_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P35_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P35_high					        bit_set(P3, 5)
#define P35_low 					        bit_clr(P3, 5)
#define P35_toggle				            bit_tgl(P3, 5)
#define P35_get_input  				        get_bit(P3, 5)

//P36
#define P36_quasi_bidirectional_mode	    do{bit_clr(P3M1, 6); bit_clr(P3M0, 6);}while(0) 
#define P36_push_pull_mode			        do{P36_quasi_bidirectional_mode; bit_clr(P3M1, 6); bit_set(P3M0, 6);}while(0)
#define P36_input_mode				        do{P36_quasi_bidirectional_mode; bit_set(P3M1, 6); bit_clr(P3M0, 6);}while(0)
#define P36_open_drain_mode			        do{P36_quasi_bidirectional_mode; bit_set(P3M1, 6); bit_set(P3M0, 6);}while(0)

#define P36_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P36_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P36_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P36_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P36_high					        bit_set(P3, 6)
#define P36_low 					        bit_clr(P3, 6)
#define P36_toggle				            bit_tgl(P3, 6)
#define P36_get_input  				        get_bit(P3, 6)

//P37
#define P37_quasi_bidirectional_mode	    do{bit_clr(P3M1, 7); bit_clr(P3M0, 7);}while(0) 
#define P37_push_pull_mode			        do{P37_quasi_bidirectional_mode; bit_clr(P3M1, 7); bit_set(P3M0, 7);}while(0)
#define P37_input_mode				        do{P37_quasi_bidirectional_mode; bit_set(P3M1, 7); bit_clr(P3M0, 7);}while(0)
#define P37_open_drain_mode			        do{P37_quasi_bidirectional_mode; bit_set(P3M1, 7); bit_set(P3M0, 7);}while(0)

#define P37_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P3PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P37_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P3PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P37_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P3NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P37_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P3NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P37_high					        bit_set(P3, 7)
#define P37_low 					        bit_clr(P3, 7)
#define P37_toggle				            bit_tgl(P3, 7)
#define P37_get_input  				        get_bit(P3, 7)