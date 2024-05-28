module SYNCin (
input CLK,
input D_in,
output reg D_out
);
reg tmp=1'd0;
always @(posedge CLK)
begin
	tmp 	<= D_in;
	D_out <= tmp;
end
endmodule

