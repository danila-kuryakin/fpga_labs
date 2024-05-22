module db_Lab3_2 (
(* altera_attribute = "-name IO_STANDARD \"3.3-V LVCMOS\"", chip_pin = "V9"  *) 
input CLK
);

wire db_rst;
wire db_ena;
wire db_dir;
wire [6:0]db_hex_1;
wire [6:0]db_hex_0;
wire db_clk_high;

Lab3_2 #(50000000) Lab3_2_inst(
	.CLK		(CLK	),
	.RST		(db_rst	),
	.ENA		(db_ena	),
	.DIR		(db_dir	),
	.HEX_1	(db_hex_1),
	.HEX_0	(db_hex_0)
);

SP_unit SP_unit_inst (
		.source     ({db_rst, db_ena,db_dir}),    // sources.source
		.probe      ({db_hex_1, db_hex_0}	),    // probes.probe
		.source_clk (CLK							)  	// source_clk.clk
);
PLL_unit PLL_unit_inst (
	.inclk0 	(CLK				),
	.c0 		(db_clk_high	)
);
endmodule
