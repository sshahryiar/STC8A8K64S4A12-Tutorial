//P10
#define P10_quasi_bidirectional_mode	    do{bit_clr(P1M1, 0); bit_clr(P1M0, 0);}while(0) 
#define P10_push_pull_mode		    	    do{P10_quasi_bidirectional_mode; bit_clr(P1M1, 0); bit_set(P1M0, 0);}while(0)
#define P10_input_mode			    	    do{P10_quasi_bidirectional_mode; bit_set(P1M1, 0); bit_clr(P1M0, 0);}while(0)
#define P10_open_drain_mode		    	    do{P10_quasi_bidirectional_mode; bit_set(P1M1, 0); bit_set(P1M0, 0);}while(0)

#define P10_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 0); bit_clr(P_SW2, 7);}while(0)
#define P10_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 0); bit_clr(P_SW2, 7);}while(0)

#define P10_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 0); bit_clr(P_SW2, 7);}while(0)
#define P10_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 0); bit_clr(P_SW2, 7);}while(0)

#define P10_high				            bit_set(P1, 0)
#define P10_low 					        bit_clr(P1, 0)
#define P10_toggle				            bit_tgl(P1, 0)
#define P10_get_input			  	        get_bit(P1, 0)

//P11
#define P11_quasi_bidirectional_mode	    do{bit_clr(P1M1, 1); bit_clr(P1M0, 1);}while(0) 
#define P11_push_pull_mode			        do{P11_quasi_bidirectional_mode; bit_clr(P1M1, 1); bit_set(P1M0, 1);}while(0)
#define P11_input_mode				        do{P11_quasi_bidirectional_mode; bit_set(P1M1, 1); bit_clr(P1M0, 1);}while(0)
#define P11_open_drain_mode			        do{P11_quasi_bidirectional_mode; bit_set(P1M1, 1); bit_set(P1M0, 1);}while(0)

#define P11_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 1); bit_clr(P_SW2, 7);}while(0)
#define P11_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 1); bit_clr(P_SW2, 7);}while(0)

#define P11_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 1); bit_clr(P_SW2, 7);}while(0)
#define P11_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 1); bit_clr(P_SW2, 7);}while(0)

#define P11_high					        bit_set(P1, 1)
#define P11_low 					        bit_clr(P1, 1)
#define P11_toggle				            bit_tgl(P1, 1)
#define P11_get_input  				        get_bit(P1, 1)

//P12
#define P12_quasi_bidirectional_mode	    do{bit_clr(P1M1, 2); bit_clr(P1M0, 2);}while(0) 
#define P12_push_pull_mode			        do{P12_quasi_bidirectional_mode; bit_clr(P1M1, 2); bit_set(P1M0, 2);}while(0)
#define P12_input_mode				        do{P12_quasi_bidirectional_mode; bit_set(P1M1, 2); bit_clr(P1M0, 2);}while(0)
#define P12_open_drain_mode			        do{P12_quasi_bidirectional_mode; bit_set(P1M1, 2); bit_set(P1M0, 2);}while(0)

#define P12_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 2); bit_clr(P_SW2, 7);}while(0)
#define P12_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 2); bit_clr(P_SW2, 7);}while(0)

#define P12_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 2); bit_clr(P_SW2, 7);}while(0)
#define P12_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 2); bit_clr(P_SW2, 7);}while(0)

#define P12_high					        bit_set(P1, 2)
#define P12_low 					        bit_clr(P1, 2)
#define P12_toggle				            bit_tgl(P1, 2)
#define P12_get_input   			        get_bit(P1, 2)

//P13
#define P13_quasi_bidirectional_mode	    do{bit_clr(P1M1, 3); bit_clr(P1M0, 3);}while(0) 
#define P13_push_pull_mode			        do{P13_quasi_bidirectional_mode; bit_clr(P1M1, 3); bit_set(P1M0, 3);}while(0)
#define P13_input_mode				        do{P13_quasi_bidirectional_mode; bit_set(P1M1, 3); bit_clr(P1M0, 3);}while(0)
#define P13_open_drain_mode			        do{P13_quasi_bidirectional_mode; bit_set(P1M1, 3); bit_set(P1M0, 3);}while(0)

#define P13_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 3); bit_clr(P_SW2, 7);}while(0)
#define P13_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 3); bit_clr(P_SW2, 7);}while(0)

#define P13_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 3); bit_clr(P_SW2, 7);}while(0)
#define P13_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 3); bit_clr(P_SW2, 7);}while(0)

#define P13_high					        bit_set(P1, 3)
#define P13_low					            bit_clr(P1, 3)
#define P13_toggle				            bit_tgl(P1, 3)
#define P13_get_input				        get_bit(P1, 3)

//P14
#define P14_quasi_bidirectional_mode	    do{bit_clr(P1M1, 4); bit_clr(P1M0, 4);}while(0) 
#define P14_push_pull_mode			        do{P14_quasi_bidirectional_mode; bit_clr(P1M1, 4); bit_set(P1M0, 4);}while(0)
#define P14_input_mode				        do{P14_quasi_bidirectional_mode; bit_set(P1M1, 4); bit_clr(P1M0, 4);}while(0)
#define P14_open_drain_mode			        do{P14_quasi_bidirectional_mode; bit_set(P1M1, 4); bit_set(P1M0, 4);}while(0)

#define P14_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 4); bit_clr(P_SW2, 7);}while(0)
#define P14_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 4); bit_clr(P_SW2, 7);}while(0)

#define P14_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 4); bit_clr(P_SW2, 7);}while(0)
#define P14_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 4); bit_clr(P_SW2, 7);}while(0)

#define P14_high					        bit_set(P1, 4)
#define P14_low 					        bit_clr(P1, 4)
#define P14_toggle				            bit_tgl(P1, 4)
#define P14_get_input  				        get_bit(P1, 4)

//P15
#define P15_quasi_bidirectional_mode	    do{bit_clr(P1M1, 5); bit_clr(P1M0, 5);}while(0) 
#define P15_push_pull_mode			        do{P15_quasi_bidirectional_mode; bit_clr(P1M1, 5); bit_set(P1M0, 5);}while(0)
#define P15_input_mode				        do{P15_quasi_bidirectional_mode; bit_set(P1M1, 5); bit_clr(P1M0, 5);}while(0)
#define P15_open_drain_mode			        do{P15_quasi_bidirectional_mode; bit_set(P1M1, 5); bit_set(P1M0, 5);}while(0)

#define P15_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 5); bit_clr(P_SW2, 7);}while(0)
#define P15_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 5); bit_clr(P_SW2, 7);}while(0)

#define P15_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 5); bit_clr(P_SW2, 7);}while(0)
#define P15_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 5); bit_clr(P_SW2, 7);}while(0)

#define P15_high					        bit_set(P1, 5)
#define P15_low 					        bit_clr(P1, 5)
#define P15_toggle				            bit_tgl(P1, 5)
#define P15_get_input  				        get_bit(P1, 5)

//P16
#define P16_quasi_bidirectional_mode	    do{bit_clr(P1M1, 6); bit_clr(P1M0, 6);}while(0) 
#define P16_push_pull_mode			        do{P16_quasi_bidirectional_mode; bit_clr(P1M1, 6); bit_set(P1M0, 6);}while(0)
#define P16_input_mode				        do{P16_quasi_bidirectional_mode; bit_set(P1M1, 6); bit_clr(P1M0, 6);}while(0)
#define P16_open_drain_mode			        do{P16_quasi_bidirectional_mode; bit_set(P1M1, 6); bit_set(P1M0, 6);}while(0)

#define P16_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 6); bit_clr(P_SW2, 7);}while(0)
#define P16_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 6); bit_clr(P_SW2, 7);}while(0)

#define P16_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 6); bit_clr(P_SW2, 7);}while(0)
#define P16_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 6); bit_clr(P_SW2, 7);}while(0)

#define P16_high					        bit_set(P1, 6)
#define P16_low 					        bit_clr(P1, 6)
#define P16_toggle				            bit_tgl(P1, 6)
#define P16_get_input  				        get_bit(P1, 6)

//P17
#define P17_quasi_bidirectional_mode	    do{bit_clr(P1M1, 7); bit_clr(P1M0, 7);}while(0) 
#define P17_push_pull_mode			        do{P17_quasi_bidirectional_mode; bit_clr(P1M1, 7); bit_set(P1M0, 7);}while(0)
#define P17_input_mode				        do{P17_quasi_bidirectional_mode; bit_set(P1M1, 7); bit_clr(P1M0, 7);}while(0)
#define P17_open_drain_mode			        do{P17_quasi_bidirectional_mode; bit_set(P1M1, 7); bit_set(P1M0, 7);}while(0)

#define P17_pull_up_enable                  do{bit_set(P_SW2, 7); bit_set(P1PU, 7); bit_clr(P_SW2, 7);}while(0)
#define P17_pull_up_disable                 do{bit_set(P_SW2, 7); bit_clr(P1PU, 7); bit_clr(P_SW2, 7);}while(0)

#define P17_schmitt_trigger_enable          do{bit_set(P_SW2, 7); bit_set(P1NCS, 7); bit_clr(P_SW2, 7);}while(0)
#define P17_schmitt_trigger_disable         do{bit_set(P_SW2, 7); bit_clr(P1NCS, 7); bit_clr(P_SW2, 7);}while(0)

#define P17_high					        bit_set(P1, 7)
#define P17_low 					        bit_clr(P1, 7)
#define P17_toggle				            bit_tgl(P1, 7)
#define P17_get_input  				        get_bit(P1, 7)