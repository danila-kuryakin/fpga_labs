module CNT_DIV #(parameter div_cnt = 4)  (
input CLK,
input RST,
input ENA,
output C_out);

reg [31:0] cnt_div = 0;

always @(posedge CLK, negedge RST)
if (!RST) cnt_div <= 1;
	else 
		if (ENA)
			begin
				cnt_div <= cnt_div + 1;
				if (C_out)
					cnt_div <= 1;
			end

assign C_out = (cnt_div == div_cnt);

endmodule
