`timescale 1ns/1ns
module tb_Lab3_2 ();
reg 	tb_clk = 1'b0;
reg 	tb_rst = 1'b0;
reg 	tb_ena = 1'b0;
reg 	tb_dir;
wire 	[6:0]tb_hex_10;
wire 	[6:0]tb_hex_01;

reg 	[5:0]tb_mem[0:127];
wire 	[5:0]tb_ss_hex_01;
wire 	[5:0]tb_ss_hex_10;

initial
begin : clk_generation
	tb_clk = 1'd0;
	while (1) # 10 tb_clk = ~tb_clk;
end

initial
begin : rst_generation
tb_rst = 1'b0;
#100;
tb_rst = 1'b1;
end

initial
begin : ena_generation
tb_ena = 1'b0;
#250;
tb_ena = 1'b1;
end

initial
begin : dir_generation
tb_dir = 1'b0;
#3000;
tb_dir = 1'b1;
#2000;
$stop;
end 


Lab3_2 #(4) LAB3_2_inst (
	.CLK	(tb_clk		),
	.RST	(tb_rst		),
	.ENA	(tb_ena		),
	.DIR 	(tb_dir		),
	.HEX_1(tb_hex_10	),
	.HEX_0(tb_hex_01	)
	); 

initial
$readmemb ("ss_to_ascii.txt", tb_mem);

assign tb_ss_hex_10 = tb_mem[tb_hex_10];
assign tb_ss_hex_01 = tb_mem[tb_hex_01];
	
endmodule
