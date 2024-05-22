module Lab3_2 #(parameter div = 4) (
input CLK,
input RST,
input ENA,
input DIR,
output [6:0]HEX_1,
output [6:0]HEX_0);

wire int_rst;
wire int_ena;
wire int_dir;
wire cout;
wire cnt_ena;
wire [5:0]cnt_val;
wire [6:0]int_hex_1;
wire [6:0]int_hex_0;

SYNCin SYNCin_RST (
	.CLK 	(CLK		),
	.D_in (RST		),
	.D_out(int_rst	)
	);
SYNCin SYNCin_ENA (
	.CLK 	(CLK		),
	.D_in (ENA		),
	.D_out(int_ena	)
	);
SYNCin SYNCin_DIR (
	.CLK 	(CLK		),
	.D_in (DIR		),
	.D_out(int_dir	)
	);	
CNT_DIV #(div) CNT_DIV_inst (
	.CLK 	(CLK	),
	.RST 	(int_rst	),
	.ENA	(int_ena	),
	.C_out(cout		)
	);
assign cnt_ena = int_ena & cout;
CNT #(6'd23) CNT_inst (
	.CLK 		(CLK	),
	.RST 		(int_rst	),
	.ENA		(cnt_ena	),
	.DIR		(int_dir	),
	.CNT_out	(cnt_val	)
	);
CODER	CODER_inst (
	.address (cnt_val						),
	.clock 	(CLK							),
	.q 		({int_hex_1,int_hex_0}	)
	);
SYNCout #(14) SYNCout_inst (
	.CLK 		(CLK							),
	.RST 		(int_rst						),
	.ENA		(int_ena						),
	.D_in 	({int_hex_1,int_hex_0}	),
	.D_out	({HEX_1, HEX_0}			)
	);
endmodule

	