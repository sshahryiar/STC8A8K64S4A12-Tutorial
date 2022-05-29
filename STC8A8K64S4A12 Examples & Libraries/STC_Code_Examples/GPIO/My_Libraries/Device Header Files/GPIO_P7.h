//P70
#define P70_quasi_bidirectional_mode	    do{bit_clr(P7M1, 0); bit_clr(P7M0, 0);}while(0) 
#define P70_push_pull_mode		    	    do{P70_quasi_bidirectional_mode; bit_clr(P7M1, 0); bit_set(P7M0, 0);}while(0)
#define P70_input_mode			    	    do{P70_quasi_bidirectional_mode; bit_set(P7M1, 0); bit_clr(P7M0, 0);}while(0)
#define P70_open_drain_mode		    	    do{P70_quasi_bidirectional_mode; bit_set(P7M1, 0); bit_set(P7M0, 0);}while(0)

#define P70_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P70_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P70_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P70_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P70_high				            bit_set(P7, 0)
#define P70_low 					        bit_clr(P7, 0)
#define P70_toggle				            bit_tgl(P7, 0)
#define P70_get_input			  	        get_bit(P7, 0)

//P71
#define P71_quasi_bidirectional_mode	    do{bit_clr(P7M1, 1); bit_clr(P7M0, 1);}while(0) 
#define P71_push_pull_mode			        do{P71_quasi_bidirectional_mode; bit_clr(P7M1, 1); bit_set(P7M0, 1);}while(0)
#define P71_input_mode				        do{P71_quasi_bidirectional_mode; bit_set(P7M1, 1); bit_clr(P7M0, 1);}while(0)
#define P71_open_drain_mode			        do{P71_quasi_bidirectional_mode; bit_set(P7M1, 1); bit_set(P7M0, 1);}while(0)

#define P71_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P71_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P71_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P71_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P71_high					        bit_set(P7, 1)
#define P71_low 					        bit_clr(P7, 1)
#define P71_toggle				            bit_tgl(P7, 1)
#define P71_get_input  				        get_bit(P7, 1)

//P72
#define P72_quasi_bidirectional_mode	    do{bit_clr(P7M1, 2); bit_clr(P7M0, 2);}while(0) 
#define P72_push_pull_mode			        do{P72_quasi_bidirectional_mode; bit_clr(P7M1, 2); bit_set(P7M0, 2);}while(0)
#define P72_input_mode				        do{P72_quasi_bidirectional_mode; bit_set(P7M1, 2); bit_clr(P7M0, 2);}while(0)
#define P72_open_drain_mode			        do{P72_quasi_bidirectional_mode; bit_set(P7M1, 2); bit_set(P7M0, 2);}while(0)

#define P72_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P72_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P72_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P72_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P72_high					        bit_set(P7, 2)
#define P72_low 					        bit_clr(P7, 2)
#define P72_toggle				            bit_tgl(P7, 2)
#define P72_get_input   			        get_bit(P7, 2)

//P73
#define P73_quasi_bidirectional_mode	    do{bit_clr(P7M1, 3); bit_clr(P7M0, 3);}while(0) 
#define P73_push_pull_mode			        do{P73_quasi_bidirectional_mode; bit_clr(P7M1, 3); bit_set(P7M0, 3);}while(0)
#define P73_input_mode				        do{P73_quasi_bidirectional_mode; bit_set(P7M1, 3); bit_clr(P7M0, 3);}while(0)
#define P73_open_drain_mode			        do{P73_quasi_bidirectional_mode; bit_set(P7M1, 3); bit_set(P7M0, 3);}while(0)

#define P73_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P73_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P73_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P73_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P73_high					        bit_set(P7, 3)
#define P73_low					            bit_clr(P7, 3)
#define P73_toggle				            bit_tgl(P7, 3)
#define P73_get_input				        get_bit(P7, 3)

//P74
#define P74_quasi_bidirectional_mode	    do{bit_clr(P7M1, 4); bit_clr(P7M0, 4);}while(0) 
#define P74_push_pull_mode			        do{P74_quasi_bidirectional_mode; bit_clr(P7M1, 4); bit_set(P7M0, 4);}while(0)
#define P74_input_mode				        do{P74_quasi_bidirectional_mode; bit_set(P7M1, 4); bit_clr(P7M0, 4);}while(0)
#define P74_open_drain_mode			        do{P74_quasi_bidirectional_mode; bit_set(P7M1, 4); bit_set(P7M0, 4);}while(0)

#define P74_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P74_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P74_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P74_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P74_high					        bit_set(P7, 4)
#define P74_low 					        bit_clr(P7, 4)
#define P74_toggle				            bit_tgl(P7, 4)
#define P74_get_input  				        get_bit(P7, 4)

//P75
#define P75_quasi_bidirectional_mode	    do{bit_clr(P7M1, 5); bit_clr(P7M0, 5);}while(0) 
#define P75_push_pull_mode			        do{P75_quasi_bidirectional_mode; bit_clr(P7M1, 5); bit_set(P7M0, 5);}while(0)
#define P75_input_mode				        do{P75_quasi_bidirectional_mode; bit_set(P7M1, 5); bit_clr(P7M0, 5);}while(0)
#define P75_open_drain_mode			        do{P75_quasi_bidirectional_mode; bit_set(P7M1, 5); bit_set(P7M0, 5);}while(0)

#define P75_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P75_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P75_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P75_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P75_high					        bit_set(P7, 5)
#define P75_low 					        bit_clr(P7, 5)
#define P75_toggle				            bit_tgl(P7, 5)
#define P75_get_input  				        get_bit(P7, 5)

//P76
#define P76_quasi_bidirectional_mode	    do{bit_clr(P7M1, 6); bit_clr(P7M0, 6);}while(0) 
#define P76_push_pull_mode			        do{P76_quasi_bidirectional_mode; bit_clr(P7M1, 6); bit_set(P7M0, 6);}while(0)
#define P76_input_mode				        do{P76_quasi_bidirectional_mode; bit_set(P7M1, 6); bit_clr(P7M0, 6);}while(0)
#define P76_open_drain_mode			        do{P76_quasi_bidirectional_mode; bit_set(P7M1, 6); bit_set(P7M0, 6);}while(0)

#define P76_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P76_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P76_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P76_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P76_high					        bit_set(P7, 6)
#define P76_low 					        bit_clr(P7, 6)
#define P76_toggle				            bit_tgl(P7, 6)
#define P76_get_input  				        get_bit(P7, 6)

//P77
#define P77_quasi_bidirectional_mode	    do{bit_clr(P7M1, 7); bit_clr(P7M0, 7);}while(0) 
#define P77_push_pull_mode			        do{P77_quasi_bidirectional_mode; bit_clr(P7M1, 7); bit_set(P7M0, 7);}while(0)
#define P77_input_mode				        do{P77_quasi_bidirectional_mode; bit_set(P7M1, 7); bit_clr(P7M0, 7);}while(0)
#define P77_open_drain_mode			        do{P77_quasi_bidirectional_mode; bit_set(P7M1, 7); bit_set(P7M0, 7);}while(0)

#define P77_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P7PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P77_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P7PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P77_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P7NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P77_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P7NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P77_high					        bit_set(P7, 7)
#define P77_low 					        bit_clr(P7, 7)
#define P77_toggle				            bit_tgl(P7, 7)
#define P77_get_input  				        get_bit(P7, 7)