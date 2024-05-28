`timescale 1 ns / 1 ns
module Lab2_top (
	input bit clk,
	input bit reset,
	output bit [3:0] dout
);
Lab2_1 Lab2_1_inst (
	.clk_clk       (clk),   
	.reset_reset_n (reset), 
	.dout_export   (dout)   
);
endmodule

