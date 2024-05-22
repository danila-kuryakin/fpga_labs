`timescale 1 ns / 1 ns
module tb_Lab4_sys_top ();
	bit clk;
	bit reset ;
	bit [7:0] data_d;
	bit [7:0] dd_slave;
	bit [7:0] d_slave;
	bit [7:0] def_slave;

assign data_d = 8'd1;

always #50 clk = ~ clk;

initial
begin
	clk 	= 1'b0;
	reset 	= 1'b0;
	#200;
	reset 	= 1'b1;
	#4000;
	$stop;
end 
	Lab4_sys_top Lab4_sys_top_inst (.*);
endmodule 


