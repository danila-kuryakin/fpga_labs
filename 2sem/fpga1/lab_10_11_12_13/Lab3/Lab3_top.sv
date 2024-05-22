`timescale 1 ns / 1 ns
module Lab3_top (
	input bit clk,
	input bit reset,
	output bit [7:0] ledA,
	output bit [31:0] ledB
);
Lab3_1 Lab3_1_inst (
	.clk_clk       (clk),   
	.reset_reset_n (reset), 
	.dout_a_export (ledA),  
	.dout_b_export (ledB)   
);
endmodule

