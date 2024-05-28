module reg_file_ram(
input	  		 clk, aclr,
input	  		 wren,
input	[3:0]  wraddress,
input	[7:0]  data,

input	  		 rden_1, rden_2,
input	[3:0]  rdaddress_1, rdaddress_2,
output[7:0]  q_1, q_2
);
port_ram1 r1 (
	.clock(clk),
	.aclr(aclr),
	
	.wren(wren),
	.wraddress(wraddress),
	.data(data),
	
	.rden(rden_1),
	.rdaddress(rdaddress_1),
	.q(q_1));
	
port_ram2 r2 (
	.clock(clk),
	.aclr(aclr),
	
	.wren(wren),
	.wraddress(wraddress),
	.data(data),
	
	.rden(rden_2),
	.rdaddress(rdaddress_2),
	.q(q_2));

endmodule
