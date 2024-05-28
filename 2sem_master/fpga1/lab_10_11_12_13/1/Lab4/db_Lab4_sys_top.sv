`timescale 1 ns / 1 ns
module db_Lab4_sys_top (
	(* altera_attribute = "-name IO_STANDARD \"3.3-V LVCMOS\"", chip_pin = "23"  *)    
	input bit clk
);
	bit reset ;
	bit [7:0] data_d;
	bit [7:0] dd_slave;
	bit [7:0] d_slave;
	bit [7:0] def_slave;

my_ISSP my_ISSP_inst (
	.source     ( {reset, data_d} ),     
	.source_clk ( clk)  			);

Lab4_sys_top Lab4_sys_top_inst (.*);

endmodule 

