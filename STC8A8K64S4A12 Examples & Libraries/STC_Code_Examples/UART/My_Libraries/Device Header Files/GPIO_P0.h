//P00
#define P00_quasi_bidirectional_mode	    do{bit_clr(P0M1, 0); bit_clr(P0M0, 0);}while(0) 
#define P00_push_pull_mode		    	    do{P00_quasi_bidirectional_mode; bit_clr(P0M1, 0); bit_set(P0M0, 0);}while(0)
#define P00_input_mode			    	    do{P00_quasi_bidirectional_mode; bit_set(P0M1, 0); bit_clr(P0M0, 0);}while(0)
#define P00_open_drain_mode		    	    do{P00_quasi_bidirectional_mode; bit_set(P0M1, 0); bit_set(P0M0, 0);}while(0)

#define P00_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 0); bit_clr(P_SW2, 7);}while(0) 
#define P00_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 0); bit_clr(P_SW2, 7);}while(0) 

#define P00_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 0); bit_clr(P_SW2, 7);}while(0) 
#define P00_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 0); bit_clr(P_SW2, 7);}while(0) 

#define P00_high				            bit_set(P0, 0)
#define P00_low 					        bit_clr(P0, 0)
#define P00_toggle				            bit_tgl(P0, 0)
#define P00_get_input			  	        get_bit(P0, 0)

//P01
#define P01_quasi_bidirectional_mode	    do{bit_clr(P0M1, 1); bit_clr(P0M0, 1);}while(0) 
#define P01_push_pull_mode			        do{P01_quasi_bidirectional_mode; bit_clr(P0M1, 1); bit_set(P0M0, 1);}while(0)
#define P01_input_mode				        do{P01_quasi_bidirectional_mode; bit_set(P0M1, 1); bit_clr(P0M0, 1);}while(0)
#define P01_open_drain_mode			        do{P01_quasi_bidirectional_mode; bit_set(P0M1, 1); bit_set(P0M0, 1);}while(0)

#define P01_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P01_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P01_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P01_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P01_high					        bit_set(P0, 1)
#define P01_low 					        bit_clr(P0, 1)
#define P01_toggle				            bit_tgl(P0, 1)
#define P01_get_input  				        get_bit(P0, 1)

//P02
#define P02_quasi_bidirectional_mode	    do{bit_clr(P0M1, 2); bit_clr(P0M0, 2);}while(0) 
#define P02_push_pull_mode			        do{P02_quasi_bidirectional_mode; bit_clr(P0M1, 2); bit_set(P0M0, 2);}while(0)
#define P02_input_mode				        do{P02_quasi_bidirectional_mode; bit_set(P0M1, 2); bit_clr(P0M0, 2);}while(0)
#define P02_open_drain_mode			        do{P02_quasi_bidirectional_mode; bit_set(P0M1, 2); bit_set(P0M0, 2);}while(0)

#define P02_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P02_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P02_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P02_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P02_high					        bit_set(P0, 2)
#define P02_low 					        bit_clr(P0, 2)
#define P02_toggle				            bit_tgl(P0, 2)
#define P02_get_input   			        get_bit(P0, 2)

//P03
#define P03_quasi_bidirectional_mode	    do{bit_clr(P0M1, 3); bit_clr(P0M0, 3);}while(0) 
#define P03_push_pull_mode			        do{P03_quasi_bidirectional_mode; bit_clr(P0M1, 3); bit_set(P0M0, 3);}while(0)
#define P03_input_mode				        do{P03_quasi_bidirectional_mode; bit_set(P0M1, 3); bit_clr(P0M0, 3);}while(0)
#define P03_open_drain_mode			        do{P03_quasi_bidirectional_mode; bit_set(P0M1, 3); bit_set(P0M0, 3);}while(0)

#define P03_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P03_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P03_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P03_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P03_high					        bit_set(P0, 3)
#define P03_low					            bit_clr(P0, 3)
#define P03_toggle				            bit_tgl(P0, 3)
#define P03_get_input				        get_bit(P0, 3)

//P04
#define P04_quasi_bidirectional_mode	    do{bit_clr(P0M1, 4); bit_clr(P0M0, 4);}while(0) 
#define P04_push_pull_mode			        do{P04_quasi_bidirectional_mode; bit_clr(P0M1, 4); bit_set(P0M0, 4);}while(0)
#define P04_input_mode				        do{P04_quasi_bidirectional_mode; bit_set(P0M1, 4); bit_clr(P0M0, 4);}while(0)
#define P04_open_drain_mode			        do{P04_quasi_bidirectional_mode; bit_set(P0M1, 4); bit_set(P0M0, 4);}while(0)

#define P04_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P04_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P04_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P04_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P04_high					        bit_set(P0, 4)
#define P04_low 					        bit_clr(P0, 4)
#define P04_toggle				            bit_tgl(P0, 4)
#define P04_get_input  				        get_bit(P0, 4)

//P05
#define P05_quasi_bidirectional_mode	    do{bit_clr(P0M1, 5); bit_clr(P0M0, 5);}while(0) 
#define P05_push_pull_mode			        do{P05_quasi_bidirectional_mode; bit_clr(P0M1, 5); bit_set(P0M0, 5);}while(0)
#define P05_input_mode				        do{P05_quasi_bidirectional_mode; bit_set(P0M1, 5); bit_clr(P0M0, 5);}while(0)
#define P05_open_drain_mode			        do{P05_quasi_bidirectional_mode; bit_set(P0M1, 5); bit_set(P0M0, 5);}while(0)

#define P05_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P05_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P05_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P05_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P05_high					        bit_set(P0, 5)
#define P05_low 					        bit_clr(P0, 5)
#define P05_toggle				            bit_tgl(P0, 5)
#define P05_get_input  				        get_bit(P0, 5)

//P06
#define P06_quasi_bidirectional_mode	    do{bit_clr(P0M1, 6); bit_clr(P0M0, 6);}while(0) 
#define P06_push_pull_mode			        do{P06_quasi_bidirectional_mode; bit_clr(P0M1, 6); bit_set(P0M0, 6);}while(0)
#define P06_input_mode				        do{P06_quasi_bidirectional_mode; bit_set(P0M1, 6); bit_clr(P0M0, 6);}while(0)
#define P06_open_drain_mode			        do{P06_quasi_bidirectional_mode; bit_set(P0M1, 6); bit_set(P0M0, 6);}while(0)

#define P06_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P06_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P06_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P06_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P06_high					        bit_set(P0, 6)
#define P06_low 					        bit_clr(P0, 6)
#define P06_toggle				            bit_tgl(P0, 6)
#define P06_get_input  				        get_bit(P0, 6)

//P07
#define P07_quasi_bidirectional_mode	    do{bit_clr(P0M1, 7); bit_clr(P0M0, 7);}while(0) 
#define P07_push_pull_mode			        do{P07_quasi_bidirectional_mode; bit_clr(P0M1, 7); bit_set(P0M0, 7);}while(0)
#define P07_input_mode				        do{P07_quasi_bidirectional_mode; bit_set(P0M1, 7); bit_clr(P0M0, 7);}while(0)
#define P07_open_drain_mode			        do{P07_quasi_bidirectional_mode; bit_set(P0M1, 7); bit_set(P0M0, 7);}while(0)

#define P07_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P0PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P07_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P0PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P07_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P0NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P07_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P0NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P07_high					        bit_set(P0, 7)
#define P07_low 					        bit_clr(P0, 7)
#define P07_toggle				            bit_tgl(P0, 7)
#define P07_get_input  				        get_bit(P0, 7)