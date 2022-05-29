//P20
#define P20_quasi_bidirectional_mode	    do{bit_clr(P2M1, 0); bit_clr(P2M0, 0);}while(0) 
#define P20_push_pull_mode		    	    do{P20_quasi_bidirectional_mode; bit_clr(P2M1, 0); bit_set(P2M0, 0);}while(0)
#define P20_input_mode			    	    do{P20_quasi_bidirectional_mode; bit_set(P2M1, 0); bit_clr(P2M0, 0);}while(0)
#define P20_open_drain_mode		    	    do{P20_quasi_bidirectional_mode; bit_set(P2M1, 0); bit_set(P2M0, 0);}while(0)

#define P20_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P20_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P20_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P20_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P20_high				            bit_set(P2, 0)
#define P20_low 					        bit_clr(P2, 0)
#define P20_toggle				            bit_tgl(P2, 0)
#define P20_get_input			  	        get_bit(P2, 0)

//P21
#define P21_quasi_bidirectional_mode	    do{bit_clr(P2M1, 1); bit_clr(P2M0, 1);}while(0) 
#define P21_push_pull_mode			        do{P21_quasi_bidirectional_mode; bit_clr(P2M1, 1); bit_set(P2M0, 1);}while(0)
#define P21_input_mode				        do{P21_quasi_bidirectional_mode; bit_set(P2M1, 1); bit_clr(P2M0, 1);}while(0)
#define P21_open_drain_mode			        do{P21_quasi_bidirectional_mode; bit_set(P2M1, 1); bit_set(P2M0, 1);}while(0)

#define P21_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P21_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P21_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P21_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P21_high					        bit_set(P2, 1)
#define P21_low 					        bit_clr(P2, 1)
#define P21_toggle				            bit_tgl(P2, 1)
#define P21_get_input  				        get_bit(P2, 1)

//P22
#define P22_quasi_bidirectional_mode	    do{bit_clr(P2M1, 2); bit_clr(P2M0, 2);}while(0) 
#define P22_push_pull_mode			        do{P22_quasi_bidirectional_mode; bit_clr(P2M1, 2); bit_set(P2M0, 2);}while(0)
#define P22_input_mode				        do{P22_quasi_bidirectional_mode; bit_set(P2M1, 2); bit_clr(P2M0, 2);}while(0)
#define P22_open_drain_mode			        do{P22_quasi_bidirectional_mode; bit_set(P2M1, 2); bit_set(P2M0, 2);}while(0)

#define P22_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P22_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P22_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P22_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P22_high					        bit_set(P2, 2)
#define P22_low 					        bit_clr(P2, 2)
#define P22_toggle				            bit_tgl(P2, 2)
#define P22_get_input   			        get_bit(P2, 2)

//P23
#define P23_quasi_bidirectional_mode	    do{bit_clr(P2M1, 3); bit_clr(P2M0, 3);}while(0) 
#define P23_push_pull_mode			        do{P23_quasi_bidirectional_mode; bit_clr(P2M1, 3); bit_set(P2M0, 3);}while(0)
#define P23_input_mode				        do{P23_quasi_bidirectional_mode; bit_set(P2M1, 3); bit_clr(P2M0, 3);}while(0)
#define P23_open_drain_mode			        do{P23_quasi_bidirectional_mode; bit_set(P2M1, 3); bit_set(P2M0, 3);}while(0)

#define P23_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P23_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P23_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P23_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P23_high					        bit_set(P2, 3)
#define P23_low					            bit_clr(P2, 3)
#define P23_toggle				            bit_tgl(P2, 3)
#define P23_get_input				        get_bit(P2, 3)

//P24
#define P24_quasi_bidirectional_mode	    do{bit_clr(P2M1, 4); bit_clr(P2M0, 4);}while(0) 
#define P24_push_pull_mode			        do{P24_quasi_bidirectional_mode; bit_clr(P2M1, 4); bit_set(P2M0, 4);}while(0)
#define P24_input_mode				        do{P24_quasi_bidirectional_mode; bit_set(P2M1, 4); bit_clr(P2M0, 4);}while(0)
#define P24_open_drain_mode			        do{P24_quasi_bidirectional_mode; bit_set(P2M1, 4); bit_set(P2M0, 4);}while(0)

#define P24_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P24_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P24_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P24_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P24_high					        bit_set(P2, 4)
#define P24_low 					        bit_clr(P2, 4)
#define P24_toggle				            bit_tgl(P2, 4)
#define P24_get_input  				        get_bit(P2, 4)

//P25
#define P25_quasi_bidirectional_mode	    do{bit_clr(P2M1, 5); bit_clr(P2M0, 5);}while(0) 
#define P25_push_pull_mode			        do{P25_quasi_bidirectional_mode; bit_clr(P2M1, 5); bit_set(P2M0, 5);}while(0)
#define P25_input_mode				        do{P25_quasi_bidirectional_mode; bit_set(P2M1, 5); bit_clr(P2M0, 5);}while(0)
#define P25_open_drain_mode			        do{P25_quasi_bidirectional_mode; bit_set(P2M1, 5); bit_set(P2M0, 5);}while(0)

#define P25_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P25_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P25_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P25_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P25_high					        bit_set(P2, 5)
#define P25_low 					        bit_clr(P2, 5)
#define P25_toggle				            bit_tgl(P2, 5)
#define P25_get_input  				        get_bit(P2, 5)

//P26
#define P26_quasi_bidirectional_mode	    do{bit_clr(P2M1, 6); bit_clr(P2M0, 6);}while(0) 
#define P26_push_pull_mode			        do{P26_quasi_bidirectional_mode; bit_clr(P2M1, 6); bit_set(P2M0, 6);}while(0)
#define P26_input_mode				        do{P26_quasi_bidirectional_mode; bit_set(P2M1, 6); bit_clr(P2M0, 6);}while(0)
#define P26_open_drain_mode			        do{P26_quasi_bidirectional_mode; bit_set(P2M1, 6); bit_set(P2M0, 6);}while(0)

#define P26_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P26_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P26_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P26_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P26_high					        bit_set(P2, 6)
#define P26_low 					        bit_clr(P2, 6)
#define P26_toggle				            bit_tgl(P2, 6)
#define P26_get_input  				        get_bit(P2, 6)

//P27
#define P27_quasi_bidirectional_mode	    do{bit_clr(P2M1, 7); bit_clr(P2M0, 7);}while(0) 
#define P27_push_pull_mode			        do{P27_quasi_bidirectional_mode; bit_clr(P2M1, 7); bit_set(P2M0, 7);}while(0)
#define P27_input_mode				        do{P27_quasi_bidirectional_mode; bit_set(P2M1, 7); bit_clr(P2M0, 7);}while(0)
#define P27_open_drain_mode			        do{P27_quasi_bidirectional_mode; bit_set(P2M1, 7); bit_set(P2M0, 7);}while(0)

#define P27_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P2PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P27_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P2PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P27_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P2NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P27_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P2NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P27_high					        bit_set(P2, 7)
#define P27_low 					        bit_clr(P2, 7)
#define P27_toggle				            bit_tgl(P2, 7)
#define P27_get_input  				        get_bit(P2, 7)