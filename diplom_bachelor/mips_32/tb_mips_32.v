`timescale 1ns / 1ps
module tb_mips_32();

reg	  		 clk;
wire	[31:0]  command;

mips_32 mips(
	.clk(clk),
	.command(command)
);

//initial begin

//end

always 
begin
	clk = 0;
	#20;
	clk = 1;
	#20;
end

endmodule
