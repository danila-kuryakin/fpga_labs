module mips_8_v2(
	input clk
);
wire reset = 1'b0;

wire [31:0] command, data_instr;
wire [7:0] 	address_instr, wraddress_instr = 8'b0;
wire 			rden_instr, wren_instr = 1'b0;

wire        wren_dm, rden_dm;
wire [7:0]  wraddress_dm, rdaddress_dm;
wire [7:0] write_data_dm, read_data_dm;

inctructions im (
		.clock(clk),
		
		.wren(wren_instr),
		.wraddress(wraddress_instr),
		.data(data_instr),
		
		.rden(rden_instr),
		.rdaddress(address_instr),
		.q(command));
		
cpu cpu(
		.clk(clk),
		.reset(reset),
		//для памяти програм
		.rden(rden_instr),
		.address(address_instr),
		.command(command),
		// чтение из памяти данных
		.rden_dm(rden_dm),
		.rdaddress_dm(rdaddress_dm),
		.read_data_dm(read_data_dm),
		// сапись в память данных
		.wren_dm(wren_dm),
		.wraddress_dm(wraddress_dm),
		.write_data_dm(write_data_dm)
		);
		
data dm(
		.clock(clk),
		
		.wren(wren_dm),
		.wraddress(wraddress_dm),
		.data(write_data_dm),
		
		.rden(rden_dm),
		.rdaddress(rdaddress_dm),
		.q(read_data_dm));
endmodule
