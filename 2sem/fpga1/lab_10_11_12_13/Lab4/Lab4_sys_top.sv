`timescale 1 ns / 1 ns
module Lab4_sys_top (
	input bit clk,
	input bit reset,
	input bit [7:0] data_d,
	output bit [7:0] dd_slave,
	output bit [7:0] d_slave,
	output bit [7:0] def_slave
);
Lab4_sys Lab4_sys_inst (
		.clk_clk          (clk),          
		.reset_reset_n    (reset),    
		.def_slave_export (def_slave), 
		.dd_slave_export  (dd_slave),  
		.d_slave_export   (d_slave),   
		.data_d_export    (data_d)     
);
endmodule

