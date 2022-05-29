//P50
#define P50_quasi_bidirectional_mode	    do{bit_clr(P5M1, 0); bit_clr(P5M0, 0);}while(0) 
#define P50_push_pull_mode		    	    do{P50_quasi_bidirectional_mode; bit_clr(P5M1, 0); bit_set(P5M0, 0);}while(0)
#define P50_input_mode			    	    do{P50_quasi_bidirectional_mode; bit_set(P5M1, 0); bit_clr(P5M0, 0);}while(0)
#define P50_open_drain_mode		    	    do{P50_quasi_bidirectional_mode; bit_set(P5M1, 0); bit_set(P5M0, 0);}while(0)

#define P50_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P50_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P50_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P50_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P50_high				            bit_set(P5, 0)
#define P50_low 					        bit_clr(P5, 0)
#define P50_toggle				            bit_tgl(P5, 0)
#define P50_get_input			  	        get_bit(P5, 0)

//P51
#define P51_quasi_bidirectional_mode	    do{bit_clr(P5M1, 1); bit_clr(P5M0, 1);}while(0) 
#define P51_push_pull_mode			        do{P51_quasi_bidirectional_mode; bit_clr(P5M1, 1); bit_set(P5M0, 1);}while(0)
#define P51_input_mode				        do{P51_quasi_bidirectional_mode; bit_set(P5M1, 1); bit_clr(P5M0, 1);}while(0)
#define P51_open_drain_mode			        do{P51_quasi_bidirectional_mode; bit_set(P5M1, 1); bit_set(P5M0, 1);}while(0)

#define P51_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P51_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P51_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P51_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P51_high					        bit_set(P5, 1)
#define P51_low 					        bit_clr(P5, 1)
#define P51_toggle				            bit_tgl(P5, 1)
#define P51_get_input  				        get_bit(P5, 1)

//P52
#define P52_quasi_bidirectional_mode	    do{bit_clr(P5M1, 2); bit_clr(P5M0, 2);}while(0) 
#define P52_push_pull_mode			        do{P52_quasi_bidirectional_mode; bit_clr(P5M1, 2); bit_set(P5M0, 2);}while(0)
#define P52_input_mode				        do{P52_quasi_bidirectional_mode; bit_set(P5M1, 2); bit_clr(P5M0, 2);}while(0)
#define P52_open_drain_mode			        do{P52_quasi_bidirectional_mode; bit_set(P5M1, 2); bit_set(P5M0, 2);}while(0)

#define P52_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P52_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P52_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P52_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P52_high					        bit_set(P5, 2)
#define P52_low 					        bit_clr(P5, 2)
#define P52_toggle				            bit_tgl(P5, 2)
#define P52_get_input   			        get_bit(P5, 2)

//P53
#define P53_quasi_bidirectional_mode	    do{bit_clr(P5M1, 3); bit_clr(P5M0, 3);}while(0) 
#define P53_push_pull_mode			        do{P53_quasi_bidirectional_mode; bit_clr(P5M1, 3); bit_set(P5M0, 3);}while(0)
#define P53_input_mode				        do{P53_quasi_bidirectional_mode; bit_set(P5M1, 3); bit_clr(P5M0, 3);}while(0)
#define P53_open_drain_mode			        do{P53_quasi_bidirectional_mode; bit_set(P5M1, 3); bit_set(P5M0, 3);}while(0)

#define P53_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P53_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P53_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P53_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P53_high					        bit_set(P5, 3)
#define P53_low					            bit_clr(P5, 3)
#define P53_toggle				            bit_tgl(P5, 3)
#define P53_get_input				        get_bit(P5, 3)

//P54
#define P54_quasi_bidirectional_mode	    do{bit_clr(P5M1, 4); bit_clr(P5M0, 4);}while(0) 
#define P54_push_pull_mode			        do{P54_quasi_bidirectional_mode; bit_clr(P5M1, 4); bit_set(P5M0, 4);}while(0)
#define P54_input_mode				        do{P54_quasi_bidirectional_mode; bit_set(P5M1, 4); bit_clr(P5M0, 4);}while(0)
#define P54_open_drain_mode			        do{P54_quasi_bidirectional_mode; bit_set(P5M1, 4); bit_set(P5M0, 4);}while(0)

#define P54_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P54_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P54_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P54_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P54_high					        bit_set(P5, 4)
#define P54_low 					        bit_clr(P5, 4)
#define P54_toggle				            bit_tgl(P5, 4)
#define P54_get_input  				        get_bit(P5, 4)

//P55
#define P55_quasi_bidirectional_mode	    do{bit_clr(P5M1, 5); bit_clr(P5M0, 5);}while(0) 
#define P55_push_pull_mode			        do{P55_quasi_bidirectional_mode; bit_clr(P5M1, 5); bit_set(P5M0, 5);}while(0)
#define P55_input_mode				        do{P55_quasi_bidirectional_mode; bit_set(P5M1, 5); bit_clr(P5M0, 5);}while(0)
#define P55_open_drain_mode			        do{P55_quasi_bidirectional_mode; bit_set(P5M1, 5); bit_set(P5M0, 5);}while(0)

#define P55_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P55_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P55_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P55_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P55_high					        bit_set(P5, 5)
#define P55_low 					        bit_clr(P5, 5)
#define P55_toggle				            bit_tgl(P5, 5)
#define P55_get_input  				        get_bit(P5, 5)

//P56
#define P56_quasi_bidirectional_mode	    do{bit_clr(P5M1, 6); bit_clr(P5M0, 6);}while(0) 
#define P56_push_pull_mode			        do{P56_quasi_bidirectional_mode; bit_clr(P5M1, 6); bit_set(P5M0, 6);}while(0)
#define P56_input_mode				        do{P56_quasi_bidirectional_mode; bit_set(P5M1, 6); bit_clr(P5M0, 6);}while(0)
#define P56_open_drain_mode			        do{P56_quasi_bidirectional_mode; bit_set(P5M1, 6); bit_set(P5M0, 6);}while(0)

#define P56_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P56_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P56_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P56_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P56_high					        bit_set(P5, 6)
#define P56_low 					        bit_clr(P5, 6)
#define P56_toggle				            bit_tgl(P5, 6)
#define P56_get_input  				        get_bit(P5, 6)

//P57
#define P57_quasi_bidirectional_mode	    do{bit_clr(P5M1, 7); bit_clr(P5M0, 7);}while(0) 
#define P57_push_pull_mode			        do{P57_quasi_bidirectional_mode; bit_clr(P5M1, 7); bit_set(P5M0, 7);}while(0)
#define P57_input_mode				        do{P57_quasi_bidirectional_mode; bit_set(P5M1, 7); bit_clr(P5M0, 7);}while(0)
#define P57_open_drain_mode			        do{P57_quasi_bidirectional_mode; bit_set(P5M1, 7); bit_set(P5M0, 7);}while(0)

#define P57_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P5PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P57_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P5PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P57_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P5NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P57_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P5NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P57_high					        bit_set(P5, 7)
#define P57_low 					        bit_clr(P5, 7)
#define P57_toggle				            bit_tgl(P5, 7)
#define P57_get_input  				        get_bit(P5, 7)