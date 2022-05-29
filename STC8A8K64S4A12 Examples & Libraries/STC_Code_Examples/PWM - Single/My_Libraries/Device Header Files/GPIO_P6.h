//P60
#define P60_quasi_bidirectional_mode	    do{bit_clr(P6M1, 0); bit_clr(P6M0, 0);}while(0) 
#define P60_push_pull_mode		    	    do{P60_quasi_bidirectional_mode; bit_clr(P6M1, 0); bit_set(P6M0, 0);}while(0)
#define P60_input_mode			    	    do{P60_quasi_bidirectional_mode; bit_set(P6M1, 0); bit_clr(P6M0, 0);}while(0)
#define P60_open_drain_mode		    	    do{P60_quasi_bidirectional_mode; bit_set(P6M1, 0); bit_set(P6M0, 0);}while(0)

#define P60_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P60_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P60_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P60_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P60_high				            bit_set(P6, 0)
#define P60_low 					        bit_clr(P6, 0)
#define P60_toggle				            bit_tgl(P6, 0)
#define P60_get_input			  	        get_bit(P6, 0)

//P61
#define P61_quasi_bidirectional_mode	    do{bit_clr(P6M1, 1); bit_clr(P6M0, 1);}while(0) 
#define P61_push_pull_mode			        do{P61_quasi_bidirectional_mode; bit_clr(P6M1, 1); bit_set(P6M0, 1);}while(0)
#define P61_input_mode				        do{P61_quasi_bidirectional_mode; bit_set(P6M1, 1); bit_clr(P6M0, 1);}while(0)
#define P61_open_drain_mode			        do{P61_quasi_bidirectional_mode; bit_set(P6M1, 1); bit_set(P6M0, 1);}while(0)

#define P61_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P61_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P61_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P61_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P61_high					        bit_set(P6, 1)
#define P61_low 					        bit_clr(P6, 1)
#define P61_toggle				            bit_tgl(P6, 1)
#define P61_get_input  				        get_bit(P6, 1)

//P62
#define P62_quasi_bidirectional_mode	    do{bit_clr(P6M1, 2); bit_clr(P6M0, 2);}while(0) 
#define P62_push_pull_mode			        do{P62_quasi_bidirectional_mode; bit_clr(P6M1, 2); bit_set(P6M0, 2);}while(0)
#define P62_input_mode				        do{P62_quasi_bidirectional_mode; bit_set(P6M1, 2); bit_clr(P6M0, 2);}while(0)
#define P62_open_drain_mode			        do{P62_quasi_bidirectional_mode; bit_set(P6M1, 2); bit_set(P6M0, 2);}while(0)

#define P62_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P62_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P62_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P62_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P62_high					        bit_set(P6, 2)
#define P62_low 					        bit_clr(P6, 2)
#define P62_toggle				            bit_tgl(P6, 2)
#define P62_get_input   			        get_bit(P6, 2)

//P63
#define P63_quasi_bidirectional_mode	    do{bit_clr(P6M1, 3); bit_clr(P6M0, 3);}while(0) 
#define P63_push_pull_mode			        do{P63_quasi_bidirectional_mode; bit_clr(P6M1, 3); bit_set(P6M0, 3);}while(0)
#define P63_input_mode				        do{P63_quasi_bidirectional_mode; bit_set(P6M1, 3); bit_clr(P6M0, 3);}while(0)
#define P63_open_drain_mode			        do{P63_quasi_bidirectional_mode; bit_set(P6M1, 3); bit_set(P6M0, 3);}while(0)

#define P63_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P63_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P63_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P63_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P63_high					        bit_set(P6, 3)
#define P63_low					            bit_clr(P6, 3)
#define P63_toggle				            bit_tgl(P6, 3)
#define P63_get_input				        get_bit(P6, 3)

//P64
#define P64_quasi_bidirectional_mode	    do{bit_clr(P6M1, 4); bit_clr(P6M0, 4);}while(0) 
#define P64_push_pull_mode			        do{P64_quasi_bidirectional_mode; bit_clr(P6M1, 4); bit_set(P6M0, 4);}while(0)
#define P64_input_mode				        do{P64_quasi_bidirectional_mode; bit_set(P6M1, 4); bit_clr(P6M0, 4);}while(0)
#define P64_open_drain_mode			        do{P64_quasi_bidirectional_mode; bit_set(P6M1, 4); bit_set(P6M0, 4);}while(0)

#define P64_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P64_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P64_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P64_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P64_high					        bit_set(P6, 4)
#define P64_low 					        bit_clr(P6, 4)
#define P64_toggle				            bit_tgl(P6, 4)
#define P64_get_input  				        get_bit(P6, 4)

//P65
#define P65_quasi_bidirectional_mode	    do{bit_clr(P6M1, 5); bit_clr(P6M0, 5);}while(0) 
#define P65_push_pull_mode			        do{P65_quasi_bidirectional_mode; bit_clr(P6M1, 5); bit_set(P6M0, 5);}while(0)
#define P65_input_mode				        do{P65_quasi_bidirectional_mode; bit_set(P6M1, 5); bit_clr(P6M0, 5);}while(0)
#define P65_open_drain_mode			        do{P65_quasi_bidirectional_mode; bit_set(P6M1, 5); bit_set(P6M0, 5);}while(0)

#define P65_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P65_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P65_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P65_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P65_high					        bit_set(P6, 5)
#define P65_low 					        bit_clr(P6, 5)
#define P65_toggle				            bit_tgl(P6, 5)
#define P65_get_input  				        get_bit(P6, 5)

//P66
#define P66_quasi_bidirectional_mode	    do{bit_clr(P6M1, 6); bit_clr(P6M0, 6);}while(0) 
#define P66_push_pull_mode			        do{P66_quasi_bidirectional_mode; bit_clr(P6M1, 6); bit_set(P6M0, 6);}while(0)
#define P66_input_mode				        do{P66_quasi_bidirectional_mode; bit_set(P6M1, 6); bit_clr(P6M0, 6);}while(0)
#define P66_open_drain_mode			        do{P66_quasi_bidirectional_mode; bit_set(P6M1, 6); bit_set(P6M0, 6);}while(0)

#define P66_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P66_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P66_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P66_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P66_high					        bit_set(P6, 6)
#define P66_low 					        bit_clr(P6, 6)
#define P66_toggle				            bit_tgl(P6, 6)
#define P66_get_input  				        get_bit(P6, 6)

//P67
#define P67_quasi_bidirectional_mode	    do{bit_clr(P6M1, 7); bit_clr(P6M0, 7);}while(0) 
#define P67_push_pull_mode			        do{P67_quasi_bidirectional_mode; bit_clr(P6M1, 7); bit_set(P6M0, 7);}while(0)
#define P67_input_mode				        do{P67_quasi_bidirectional_mode; bit_set(P6M1, 7); bit_clr(P6M0, 7);}while(0)
#define P67_open_drain_mode			        do{P67_quasi_bidirectional_mode; bit_set(P6M1, 7); bit_set(P6M0, 7);}while(0)

#define P67_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P6PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P67_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P6PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P67_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P6NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P67_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P6NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P67_high					        bit_set(P6, 7)
#define P67_low 					        bit_clr(P6, 7)
#define P67_toggle				            bit_tgl(P6, 7)
#define P67_get_input  				        get_bit(P6, 7)