`timescale 1ns / 1ps
module tb_ram_file();

reg	  		 clk;
wire	[31:0]  command;

mips_8_v1 mips(
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
