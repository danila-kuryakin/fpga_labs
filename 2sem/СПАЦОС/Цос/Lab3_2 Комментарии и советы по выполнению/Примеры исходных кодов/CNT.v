module CNT #(parameter cnt_mod = 6'd23) (
input CLK,
input RST,
input ENA,
input DIR,
output reg [5:0] CNT_out);


always @(posedge CLK, negedge RST)
if (!RST) CNT_out <= 6'd0;
	else 
		if (ENA) 
			begin
				if (DIR)
					if (CNT_out == 6'd0)
						CNT_out <= cnt_mod-6'd1;
					else
						CNT_out <= CNT_out - 6'd1;
				else
					if (CNT_out == cnt_mod-6'd1)
						CNT_out <= 6'd0;
					else
						CNT_out <= CNT_out + 6'd1;
			end
endmodule

			
						
			
	