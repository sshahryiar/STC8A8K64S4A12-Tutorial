//P40
#define P40_quasi_bidirectional_mode	    do{bit_clr(P4M1, 0); bit_clr(P4M0, 0);}while(0) 
#define P40_push_pull_mode		    	    do{P40_quasi_bidirectional_mode; bit_clr(P4M1, 0); bit_set(P4M0, 0);}while(0)
#define P40_input_mode			    	    do{P40_quasi_bidirectional_mode; bit_set(P4M1, 0); bit_clr(P4M0, 0);}while(0)
#define P40_open_drain_mode		    	    do{P40_quasi_bidirectional_mode; bit_set(P4M1, 0); bit_set(P4M0, 0);}while(0)

#define P40_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P40_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P40_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P40_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P40_high				            bit_set(P4, 0)
#define P40_low 					        bit_clr(P4, 0)
#define P40_toggle				            bit_tgl(P4, 0)
#define P40_get_input			  	        get_bit(P4, 0)

//P41
#define P41_quasi_bidirectional_mode	    do{bit_clr(P4M1, 1); bit_clr(P4M0, 1);}while(0) 
#define P41_push_pull_mode			        do{P41_quasi_bidirectional_mode; bit_clr(P4M1, 1); bit_set(P4M0, 1);}while(0)
#define P41_input_mode				        do{P41_quasi_bidirectional_mode; bit_set(P4M1, 1); bit_clr(P4M0, 1);}while(0)
#define P41_open_drain_mode			        do{P41_quasi_bidirectional_mode; bit_set(P4M1, 1); bit_set(P4M0, 1);}while(0)

#define P41_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P41_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P41_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P41_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P41_high					        bit_set(P4, 1)
#define P41_low 					        bit_clr(P4, 1)
#define P41_toggle				            bit_tgl(P4, 1)
#define P41_get_input  				        get_bit(P4, 1)

//P42
#define P42_quasi_bidirectional_mode	    do{bit_clr(P4M1, 2); bit_clr(P4M0, 2);}while(0) 
#define P42_push_pull_mode			        do{P42_quasi_bidirectional_mode; bit_clr(P4M1, 2); bit_set(P4M0, 2);}while(0)
#define P42_input_mode				        do{P42_quasi_bidirectional_mode; bit_set(P4M1, 2); bit_clr(P4M0, 2);}while(0)
#define P42_open_drain_mode			        do{P42_quasi_bidirectional_mode; bit_set(P4M1, 2); bit_set(P4M0, 2);}while(0)

#define P42_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P42_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P42_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P42_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P42_high					        bit_set(P4, 2)
#define P42_low 					        bit_clr(P4, 2)
#define P42_toggle				            bit_tgl(P4, 2)
#define P42_get_input   			        get_bit(P4, 2)

//P43
#define P43_quasi_bidirectional_mode	    do{bit_clr(P4M1, 3); bit_clr(P4M0, 3);}while(0) 
#define P43_push_pull_mode			        do{P43_quasi_bidirectional_mode; bit_clr(P4M1, 3); bit_set(P4M0, 3);}while(0)
#define P43_input_mode				        do{P43_quasi_bidirectional_mode; bit_set(P4M1, 3); bit_clr(P4M0, 3);}while(0)
#define P43_open_drain_mode			        do{P43_quasi_bidirectional_mode; bit_set(P4M1, 3); bit_set(P4M0, 3);}while(0)

#define P43_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P43_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P43_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P43_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P43_high					        bit_set(P4, 3)
#define P43_low					            bit_clr(P4, 3)
#define P43_toggle				            bit_tgl(P4, 3)
#define P43_get_input				        get_bit(P4, 3)

//P44
#define P44_quasi_bidirectional_mode	    do{bit_clr(P4M1, 4); bit_clr(P4M0, 4);}while(0) 
#define P44_push_pull_mode			        do{P44_quasi_bidirectional_mode; bit_clr(P4M1, 4); bit_set(P4M0, 4);}while(0)
#define P44_input_mode				        do{P44_quasi_bidirectional_mode; bit_set(P4M1, 4); bit_clr(P4M0, 4);}while(0)
#define P44_open_drain_mode			        do{P44_quasi_bidirectional_mode; bit_set(P4M1, 4); bit_set(P4M0, 4);}while(0)

#define P44_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P44_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P44_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P44_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P44_high					        bit_set(P4, 4)
#define P44_low 					        bit_clr(P4, 4)
#define P44_toggle				            bit_tgl(P4, 4)
#define P44_get_input  				        get_bit(P4, 4)

//P45
#define P45_quasi_bidirectional_mode	    do{bit_clr(P4M1, 5); bit_clr(P4M0, 5);}while(0) 
#define P45_push_pull_mode			        do{P45_quasi_bidirectional_mode; bit_clr(P4M1, 5); bit_set(P4M0, 5);}while(0)
#define P45_input_mode				        do{P45_quasi_bidirectional_mode; bit_set(P4M1, 5); bit_clr(P4M0, 5);}while(0)
#define P45_open_drain_mode			        do{P45_quasi_bidirectional_mode; bit_set(P4M1, 5); bit_set(P4M0, 5);}while(0)

#define P45_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P45_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P45_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P45_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P45_high					        bit_set(P4, 5)
#define P45_low 					        bit_clr(P4, 5)
#define P45_toggle				            bit_tgl(P4, 5)
#define P45_get_input  				        get_bit(P4, 5)

//P46
#define P46_quasi_bidirectional_mode	    do{bit_clr(P4M1, 6); bit_clr(P4M0, 6);}while(0) 
#define P46_push_pull_mode			        do{P46_quasi_bidirectional_mode; bit_clr(P4M1, 6); bit_set(P4M0, 6);}while(0)
#define P46_input_mode				        do{P46_quasi_bidirectional_mode; bit_set(P4M1, 6); bit_clr(P4M0, 6);}while(0)
#define P46_open_drain_mode			        do{P46_quasi_bidirectional_mode; bit_set(P4M1, 6); bit_set(P4M0, 6);}while(0)

#define P46_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P46_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P46_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P46_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P46_high					        bit_set(P4, 6)
#define P46_low 					        bit_clr(P4, 6)
#define P46_toggle				            bit_tgl(P4, 6)
#define P46_get_input  				        get_bit(P4, 6)

//P47
#define P47_quasi_bidirectional_mode	    do{bit_clr(P4M1, 7); bit_clr(P4M0, 7);}while(0) 
#define P47_push_pull_mode			        do{P47_quasi_bidirectional_mode; bit_clr(P4M1, 7); bit_set(P4M0, 7);}while(0)
#define P47_input_mode				        do{P47_quasi_bidirectional_mode; bit_set(P4M1, 7); bit_clr(P4M0, 7);}while(0)
#define P47_open_drain_mode			        do{P47_quasi_bidirectional_mode; bit_set(P4M1, 7); bit_set(P4M0, 7);}while(0)

#define P47_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P4PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P47_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P4PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P47_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P4NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P47_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P4NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P47_high					        bit_set(P4, 7)
#define P47_low 					        bit_clr(P4, 7)
#define P47_toggle				            bit_tgl(P4, 7)
#define P47_get_input  				        get_bit(P4, 7)