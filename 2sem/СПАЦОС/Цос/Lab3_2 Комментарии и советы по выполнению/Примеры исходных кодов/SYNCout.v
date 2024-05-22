module SYNCout #(parameter N=14)(
input CLK,
input RST,
input ENA,
input [N:1] D_in,
output reg [N:1] D_out);

always @(posedge CLK, negedge RST)
if (!RST) D_out <= 14'B10000001000000;
	else
		if (ENA)
			D_out <= D_in;
endmodule 
