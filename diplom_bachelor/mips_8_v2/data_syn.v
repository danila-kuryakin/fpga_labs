// megafunction wizard: %RAM: 2-PORT%
// GENERATION: STANDARD
// VERSION: WM1.0
// MODULE: altsyncram 

// ============================================================
// File Name: data.v
// Megafunction Name(s):
// 			altsyncram
//
// Simulation Library Files(s):
// 			altera_mf
// ============================================================
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//
// 20.1.1 Build 720 11/11/2020 SJ Lite Edition
// ************************************************************


//Copyright (C) 2020  Intel Corporation. All rights reserved.
//Your use of Intel Corporation's design tools, logic functions 
//and other software and tools, and any partner logic 
//functions, and any output files from any of the foregoing 
//(including device programming or simulation files), and any 
//associated documentation or information are expressly subject 
//to the terms and conditions of the Intel Program License 
//Subscription Agreement, the Intel Quartus Prime License Agreement,
//the Intel FPGA IP License Agreement, or other applicable license
//agreement, including, without limitation, that your use is for
//the sole purpose of programming logic devices manufactured by
//Intel and sold by Intel or its authorized distributors.  Please
//refer to the applicable agreement for further details, at
//https://fpgasoftware.intel.com/eula.


//altsyncram ADDRESS_ACLR_B="CLEAR0" ADDRESS_REG_B="CLOCK0" CLOCK_ENABLE_INPUT_A="BYPASS" CLOCK_ENABLE_INPUT_B="BYPASS" CLOCK_ENABLE_OUTPUT_B="BYPASS" DEVICE_FAMILY="Cyclone IV E" INIT_FILE="../data.mif" NUMWORDS_A=256 NUMWORDS_B=256 OPERATION_MODE="DUAL_PORT" OUTDATA_ACLR_B="CLEAR0" OUTDATA_REG_B="UNREGISTERED" POWER_UP_UNINITIALIZED="FALSE" RAM_BLOCK_TYPE="M9K" RDCONTROL_REG_B="CLOCK0" READ_DURING_WRITE_MODE_MIXED_PORTS="DONT_CARE" WIDTH_A=8 WIDTH_B=8 WIDTH_BYTEENA_A=1 WIDTHAD_A=8 WIDTHAD_B=8 aclr0 address_a address_b clock0 data_a q_b rden_b wren_a
//VERSION_BEGIN 20.1 cbx_altera_syncram_nd_impl 2020:11:11:17:06:45:SJ cbx_altsyncram 2020:11:11:17:06:45:SJ cbx_cycloneii 2020:11:11:17:06:45:SJ cbx_lpm_add_sub 2020:11:11:17:06:45:SJ cbx_lpm_compare 2020:11:11:17:06:45:SJ cbx_lpm_decode 2020:11:11:17:06:45:SJ cbx_lpm_mux 2020:11:11:17:06:45:SJ cbx_mgl 2020:11:11:17:08:38:SJ cbx_nadder 2020:11:11:17:06:46:SJ cbx_stratix 2020:11:11:17:06:46:SJ cbx_stratixii 2020:11:11:17:06:46:SJ cbx_stratixiii 2020:11:11:17:06:46:SJ cbx_stratixv 2020:11:11:17:06:46:SJ cbx_util_mgl 2020:11:11:17:06:46:SJ  VERSION_END
// synthesis VERILOG_INPUT_VERSION VERILOG_2001
// altera message_off 10463


//synthesis_resources = M9K 1 reg 1 
//synopsys translate_off
`timescale 1 ps / 1 ps
//synopsys translate_on
(* ALTERA_ATTRIBUTE = {"OPTIMIZE_POWER_DURING_SYNTHESIS=NORMAL_COMPILATION"} *)
module  data_altsyncram
	( 
	aclr0,
	address_a,
	address_b,
	clock0,
	data_a,
	q_b,
	rden_b,
	wren_a) /* synthesis synthesis_clearbox=1 */;
	input   aclr0;
	input   [7:0]  address_a;
	input   [7:0]  address_b;
	input   clock0;
	input   [7:0]  data_a;
	output   [7:0]  q_b;
	input   rden_b;
	input   wren_a;
`ifndef ALTERA_RESERVED_QIS
// synopsys translate_off
`endif
	tri0   aclr0;
	tri1   [7:0]  address_b;
	tri1   clock0;
	tri1   [7:0]  data_a;
	tri1   rden_b;
	tri0   wren_a;
`ifndef ALTERA_RESERVED_QIS
// synopsys translate_on
`endif

	reg	rden_b_store;
	wire  [0:0]   wire_ram_block1a_0portbdataout;
	wire  [0:0]   wire_ram_block1a_1portbdataout;
	wire  [0:0]   wire_ram_block1a_2portbdataout;
	wire  [0:0]   wire_ram_block1a_3portbdataout;
	wire  [0:0]   wire_ram_block1a_4portbdataout;
	wire  [0:0]   wire_ram_block1a_5portbdataout;
	wire  [0:0]   wire_ram_block1a_6portbdataout;
	wire  [0:0]   wire_ram_block1a_7portbdataout;
	wire  [7:0]  address_a_wire;
	wire  [7:0]  address_b_wire;

	// synopsys translate_off
	initial
		rden_b_store = 0;
	// synopsys translate_on
	always @ ( posedge clock0)
		  rden_b_store <= rden_b;
	cycloneive_ram_block   ram_block1a_0
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[0]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_0portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_0.clk0_core_clock_enable = "ena0",
		ram_block1a_0.clk0_input_clock_enable = "none",
		ram_block1a_0.clk1_core_clock_enable = "ena1",
		ram_block1a_0.clk1_input_clock_enable = "none",
		ram_block1a_0.connectivity_checking = "OFF",
		ram_block1a_0.init_file = "../data.mif",
		ram_block1a_0.init_file_layout = "port_b",
		ram_block1a_0.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_0.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000020000,
		ram_block1a_0.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_0.operation_mode = "dual_port",
		ram_block1a_0.port_a_address_width = 8,
		ram_block1a_0.port_a_data_width = 1,
		ram_block1a_0.port_a_first_address = 0,
		ram_block1a_0.port_a_first_bit_number = 0,
		ram_block1a_0.port_a_last_address = 255,
		ram_block1a_0.port_a_logical_ram_depth = 256,
		ram_block1a_0.port_a_logical_ram_width = 8,
		ram_block1a_0.port_b_address_clear = "clear0",
		ram_block1a_0.port_b_address_clock = "clock1",
		ram_block1a_0.port_b_address_width = 8,
		ram_block1a_0.port_b_data_out_clear = "clear0",
		ram_block1a_0.port_b_data_width = 1,
		ram_block1a_0.port_b_first_address = 0,
		ram_block1a_0.port_b_first_bit_number = 0,
		ram_block1a_0.port_b_last_address = 255,
		ram_block1a_0.port_b_logical_ram_depth = 256,
		ram_block1a_0.port_b_logical_ram_width = 8,
		ram_block1a_0.port_b_read_enable_clock = "clock1",
		ram_block1a_0.power_up_uninitialized = "false",
		ram_block1a_0.ram_block_type = "M9K",
		ram_block1a_0.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_1
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[1]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_1portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_1.clk0_core_clock_enable = "ena0",
		ram_block1a_1.clk0_input_clock_enable = "none",
		ram_block1a_1.clk1_core_clock_enable = "ena1",
		ram_block1a_1.clk1_input_clock_enable = "none",
		ram_block1a_1.connectivity_checking = "OFF",
		ram_block1a_1.init_file = "../data.mif",
		ram_block1a_1.init_file_layout = "port_b",
		ram_block1a_1.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_1.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000000000,
		ram_block1a_1.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_1.operation_mode = "dual_port",
		ram_block1a_1.port_a_address_width = 8,
		ram_block1a_1.port_a_data_width = 1,
		ram_block1a_1.port_a_first_address = 0,
		ram_block1a_1.port_a_first_bit_number = 1,
		ram_block1a_1.port_a_last_address = 255,
		ram_block1a_1.port_a_logical_ram_depth = 256,
		ram_block1a_1.port_a_logical_ram_width = 8,
		ram_block1a_1.port_b_address_clear = "clear0",
		ram_block1a_1.port_b_address_clock = "clock1",
		ram_block1a_1.port_b_address_width = 8,
		ram_block1a_1.port_b_data_out_clear = "clear0",
		ram_block1a_1.port_b_data_width = 1,
		ram_block1a_1.port_b_first_address = 0,
		ram_block1a_1.port_b_first_bit_number = 1,
		ram_block1a_1.port_b_last_address = 255,
		ram_block1a_1.port_b_logical_ram_depth = 256,
		ram_block1a_1.port_b_logical_ram_width = 8,
		ram_block1a_1.port_b_read_enable_clock = "clock1",
		ram_block1a_1.power_up_uninitialized = "false",
		ram_block1a_1.ram_block_type = "M9K",
		ram_block1a_1.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_2
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[2]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_2portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_2.clk0_core_clock_enable = "ena0",
		ram_block1a_2.clk0_input_clock_enable = "none",
		ram_block1a_2.clk1_core_clock_enable = "ena1",
		ram_block1a_2.clk1_input_clock_enable = "none",
		ram_block1a_2.connectivity_checking = "OFF",
		ram_block1a_2.init_file = "../data.mif",
		ram_block1a_2.init_file_layout = "port_b",
		ram_block1a_2.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_2.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000040000,
		ram_block1a_2.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_2.operation_mode = "dual_port",
		ram_block1a_2.port_a_address_width = 8,
		ram_block1a_2.port_a_data_width = 1,
		ram_block1a_2.port_a_first_address = 0,
		ram_block1a_2.port_a_first_bit_number = 2,
		ram_block1a_2.port_a_last_address = 255,
		ram_block1a_2.port_a_logical_ram_depth = 256,
		ram_block1a_2.port_a_logical_ram_width = 8,
		ram_block1a_2.port_b_address_clear = "clear0",
		ram_block1a_2.port_b_address_clock = "clock1",
		ram_block1a_2.port_b_address_width = 8,
		ram_block1a_2.port_b_data_out_clear = "clear0",
		ram_block1a_2.port_b_data_width = 1,
		ram_block1a_2.port_b_first_address = 0,
		ram_block1a_2.port_b_first_bit_number = 2,
		ram_block1a_2.port_b_last_address = 255,
		ram_block1a_2.port_b_logical_ram_depth = 256,
		ram_block1a_2.port_b_logical_ram_width = 8,
		ram_block1a_2.port_b_read_enable_clock = "clock1",
		ram_block1a_2.power_up_uninitialized = "false",
		ram_block1a_2.ram_block_type = "M9K",
		ram_block1a_2.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_3
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[3]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_3portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_3.clk0_core_clock_enable = "ena0",
		ram_block1a_3.clk0_input_clock_enable = "none",
		ram_block1a_3.clk1_core_clock_enable = "ena1",
		ram_block1a_3.clk1_input_clock_enable = "none",
		ram_block1a_3.connectivity_checking = "OFF",
		ram_block1a_3.init_file = "../data.mif",
		ram_block1a_3.init_file_layout = "port_b",
		ram_block1a_3.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_3.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000030000,
		ram_block1a_3.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_3.operation_mode = "dual_port",
		ram_block1a_3.port_a_address_width = 8,
		ram_block1a_3.port_a_data_width = 1,
		ram_block1a_3.port_a_first_address = 0,
		ram_block1a_3.port_a_first_bit_number = 3,
		ram_block1a_3.port_a_last_address = 255,
		ram_block1a_3.port_a_logical_ram_depth = 256,
		ram_block1a_3.port_a_logical_ram_width = 8,
		ram_block1a_3.port_b_address_clear = "clear0",
		ram_block1a_3.port_b_address_clock = "clock1",
		ram_block1a_3.port_b_address_width = 8,
		ram_block1a_3.port_b_data_out_clear = "clear0",
		ram_block1a_3.port_b_data_width = 1,
		ram_block1a_3.port_b_first_address = 0,
		ram_block1a_3.port_b_first_bit_number = 3,
		ram_block1a_3.port_b_last_address = 255,
		ram_block1a_3.port_b_logical_ram_depth = 256,
		ram_block1a_3.port_b_logical_ram_width = 8,
		ram_block1a_3.port_b_read_enable_clock = "clock1",
		ram_block1a_3.power_up_uninitialized = "false",
		ram_block1a_3.ram_block_type = "M9K",
		ram_block1a_3.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_4
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[4]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_4portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_4.clk0_core_clock_enable = "ena0",
		ram_block1a_4.clk0_input_clock_enable = "none",
		ram_block1a_4.clk1_core_clock_enable = "ena1",
		ram_block1a_4.clk1_input_clock_enable = "none",
		ram_block1a_4.connectivity_checking = "OFF",
		ram_block1a_4.init_file = "../data.mif",
		ram_block1a_4.init_file_layout = "port_b",
		ram_block1a_4.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_4.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000050000,
		ram_block1a_4.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_4.operation_mode = "dual_port",
		ram_block1a_4.port_a_address_width = 8,
		ram_block1a_4.port_a_data_width = 1,
		ram_block1a_4.port_a_first_address = 0,
		ram_block1a_4.port_a_first_bit_number = 4,
		ram_block1a_4.port_a_last_address = 255,
		ram_block1a_4.port_a_logical_ram_depth = 256,
		ram_block1a_4.port_a_logical_ram_width = 8,
		ram_block1a_4.port_b_address_clear = "clear0",
		ram_block1a_4.port_b_address_clock = "clock1",
		ram_block1a_4.port_b_address_width = 8,
		ram_block1a_4.port_b_data_out_clear = "clear0",
		ram_block1a_4.port_b_data_width = 1,
		ram_block1a_4.port_b_first_address = 0,
		ram_block1a_4.port_b_first_bit_number = 4,
		ram_block1a_4.port_b_last_address = 255,
		ram_block1a_4.port_b_logical_ram_depth = 256,
		ram_block1a_4.port_b_logical_ram_width = 8,
		ram_block1a_4.port_b_read_enable_clock = "clock1",
		ram_block1a_4.power_up_uninitialized = "false",
		ram_block1a_4.ram_block_type = "M9K",
		ram_block1a_4.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_5
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[5]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_5portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_5.clk0_core_clock_enable = "ena0",
		ram_block1a_5.clk0_input_clock_enable = "none",
		ram_block1a_5.clk1_core_clock_enable = "ena1",
		ram_block1a_5.clk1_input_clock_enable = "none",
		ram_block1a_5.connectivity_checking = "OFF",
		ram_block1a_5.init_file = "../data.mif",
		ram_block1a_5.init_file_layout = "port_b",
		ram_block1a_5.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_5.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000060000,
		ram_block1a_5.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_5.operation_mode = "dual_port",
		ram_block1a_5.port_a_address_width = 8,
		ram_block1a_5.port_a_data_width = 1,
		ram_block1a_5.port_a_first_address = 0,
		ram_block1a_5.port_a_first_bit_number = 5,
		ram_block1a_5.port_a_last_address = 255,
		ram_block1a_5.port_a_logical_ram_depth = 256,
		ram_block1a_5.port_a_logical_ram_width = 8,
		ram_block1a_5.port_b_address_clear = "clear0",
		ram_block1a_5.port_b_address_clock = "clock1",
		ram_block1a_5.port_b_address_width = 8,
		ram_block1a_5.port_b_data_out_clear = "clear0",
		ram_block1a_5.port_b_data_width = 1,
		ram_block1a_5.port_b_first_address = 0,
		ram_block1a_5.port_b_first_bit_number = 5,
		ram_block1a_5.port_b_last_address = 255,
		ram_block1a_5.port_b_logical_ram_depth = 256,
		ram_block1a_5.port_b_logical_ram_width = 8,
		ram_block1a_5.port_b_read_enable_clock = "clock1",
		ram_block1a_5.power_up_uninitialized = "false",
		ram_block1a_5.ram_block_type = "M9K",
		ram_block1a_5.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_6
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[6]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_6portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_6.clk0_core_clock_enable = "ena0",
		ram_block1a_6.clk0_input_clock_enable = "none",
		ram_block1a_6.clk1_core_clock_enable = "ena1",
		ram_block1a_6.clk1_input_clock_enable = "none",
		ram_block1a_6.connectivity_checking = "OFF",
		ram_block1a_6.init_file = "../data.mif",
		ram_block1a_6.init_file_layout = "port_b",
		ram_block1a_6.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_6.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000030000,
		ram_block1a_6.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_6.operation_mode = "dual_port",
		ram_block1a_6.port_a_address_width = 8,
		ram_block1a_6.port_a_data_width = 1,
		ram_block1a_6.port_a_first_address = 0,
		ram_block1a_6.port_a_first_bit_number = 6,
		ram_block1a_6.port_a_last_address = 255,
		ram_block1a_6.port_a_logical_ram_depth = 256,
		ram_block1a_6.port_a_logical_ram_width = 8,
		ram_block1a_6.port_b_address_clear = "clear0",
		ram_block1a_6.port_b_address_clock = "clock1",
		ram_block1a_6.port_b_address_width = 8,
		ram_block1a_6.port_b_data_out_clear = "clear0",
		ram_block1a_6.port_b_data_width = 1,
		ram_block1a_6.port_b_first_address = 0,
		ram_block1a_6.port_b_first_bit_number = 6,
		ram_block1a_6.port_b_last_address = 255,
		ram_block1a_6.port_b_logical_ram_depth = 256,
		ram_block1a_6.port_b_logical_ram_width = 8,
		ram_block1a_6.port_b_read_enable_clock = "clock1",
		ram_block1a_6.power_up_uninitialized = "false",
		ram_block1a_6.ram_block_type = "M9K",
		ram_block1a_6.lpm_type = "cycloneive_ram_block";
	cycloneive_ram_block   ram_block1a_7
	( 
	.clk0(clock0),
	.clk1(clock0),
	.clr0(aclr0),
	.ena0(wren_a),
	.ena1((rden_b_store | rden_b)),
	.portaaddr({address_a_wire[7:0]}),
	.portadatain({data_a[7]}),
	.portadataout(),
	.portawe(wren_a),
	.portbaddr({address_b_wire[7:0]}),
	.portbdataout(wire_ram_block1a_7portbdataout[0:0]),
	.portbre(rden_b)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_off
	`endif
	,
	.clr1(1'b0),
	.ena2(1'b1),
	.ena3(1'b1),
	.portaaddrstall(1'b0),
	.portabyteenamasks({1{1'b1}}),
	.portare(1'b1),
	.portbaddrstall(1'b0),
	.portbbyteenamasks({1{1'b1}}),
	.portbdatain({1{1'b0}}),
	.portbwe(1'b0)
	`ifndef FORMAL_VERIFICATION
	// synopsys translate_on
	`endif
	// synopsys translate_off
	,
	.devclrn(1'b1),
	.devpor(1'b1)
	// synopsys translate_on
	);
	defparam
		ram_block1a_7.clk0_core_clock_enable = "ena0",
		ram_block1a_7.clk0_input_clock_enable = "none",
		ram_block1a_7.clk1_core_clock_enable = "ena1",
		ram_block1a_7.clk1_input_clock_enable = "none",
		ram_block1a_7.connectivity_checking = "OFF",
		ram_block1a_7.init_file = "../data.mif",
		ram_block1a_7.init_file_layout = "port_b",
		ram_block1a_7.logical_ram_name = "ALTSYNCRAM",
		ram_block1a_7.mem_init0 = 256'h0000000000000000000000000000000000000000000000000000000000000000,
		ram_block1a_7.mixed_port_feed_through_mode = "dont_care",
		ram_block1a_7.operation_mode = "dual_port",
		ram_block1a_7.port_a_address_width = 8,
		ram_block1a_7.port_a_data_width = 1,
		ram_block1a_7.port_a_first_address = 0,
		ram_block1a_7.port_a_first_bit_number = 7,
		ram_block1a_7.port_a_last_address = 255,
		ram_block1a_7.port_a_logical_ram_depth = 256,
		ram_block1a_7.port_a_logical_ram_width = 8,
		ram_block1a_7.port_b_address_clear = "clear0",
		ram_block1a_7.port_b_address_clock = "clock1",
		ram_block1a_7.port_b_address_width = 8,
		ram_block1a_7.port_b_data_out_clear = "clear0",
		ram_block1a_7.port_b_data_width = 1,
		ram_block1a_7.port_b_first_address = 0,
		ram_block1a_7.port_b_first_bit_number = 7,
		ram_block1a_7.port_b_last_address = 255,
		ram_block1a_7.port_b_logical_ram_depth = 256,
		ram_block1a_7.port_b_logical_ram_width = 8,
		ram_block1a_7.port_b_read_enable_clock = "clock1",
		ram_block1a_7.power_up_uninitialized = "false",
		ram_block1a_7.ram_block_type = "M9K",
		ram_block1a_7.lpm_type = "cycloneive_ram_block";
	assign
		address_a_wire = address_a,
		address_b_wire = address_b,
		q_b = {wire_ram_block1a_7portbdataout[0], wire_ram_block1a_6portbdataout[0], wire_ram_block1a_5portbdataout[0], wire_ram_block1a_4portbdataout[0], wire_ram_block1a_3portbdataout[0], wire_ram_block1a_2portbdataout[0], wire_ram_block1a_1portbdataout[0], wire_ram_block1a_0portbdataout[0]};
endmodule //data_altsyncram
//VALID FILE


// synopsys translate_off
`timescale 1 ps / 1 ps
// synopsys translate_on
module data (
	aclr,
	clock,
	data,
	rdaddress,
	rden,
	wraddress,
	wren,
	q)/* synthesis synthesis_clearbox = 1 */;

	input	  aclr;
	input	  clock;
	input	[7:0]  data;
	input	[7:0]  rdaddress;
	input	  rden;
	input	[7:0]  wraddress;
	input	  wren;
	output	[7:0]  q;
`ifndef ALTERA_RESERVED_QIS
// synopsys translate_off
`endif
	tri0	  aclr;
	tri1	  clock;
	tri1	  rden;
	tri0	  wren;
`ifndef ALTERA_RESERVED_QIS
// synopsys translate_on
`endif

	wire [7:0] sub_wire0;
	wire [7:0] q = sub_wire0[7:0];

	data_altsyncram	data_altsyncram_component (
				.aclr0 (aclr),
				.address_a (wraddress),
				.address_b (rdaddress),
				.clock0 (clock),
				.data_a (data),
				.rden_b (rden),
				.wren_a (wren),
				.q_b (sub_wire0));

endmodule

// ============================================================
// CNX file retrieval info
// ============================================================
// Retrieval info: PRIVATE: ADDRESSSTALL_A NUMERIC "0"
// Retrieval info: PRIVATE: ADDRESSSTALL_B NUMERIC "0"
// Retrieval info: PRIVATE: BYTEENA_ACLR_A NUMERIC "0"
// Retrieval info: PRIVATE: BYTEENA_ACLR_B NUMERIC "0"
// Retrieval info: PRIVATE: BYTE_ENABLE_A NUMERIC "0"
// Retrieval info: PRIVATE: BYTE_ENABLE_B NUMERIC "0"
// Retrieval info: PRIVATE: BYTE_SIZE NUMERIC "8"
// Retrieval info: PRIVATE: BlankMemory NUMERIC "0"
// Retrieval info: PRIVATE: CLOCK_ENABLE_INPUT_A NUMERIC "0"
// Retrieval info: PRIVATE: CLOCK_ENABLE_INPUT_B NUMERIC "0"
// Retrieval info: PRIVATE: CLOCK_ENABLE_OUTPUT_A NUMERIC "0"
// Retrieval info: PRIVATE: CLOCK_ENABLE_OUTPUT_B NUMERIC "0"
// Retrieval info: PRIVATE: CLRdata NUMERIC "0"
// Retrieval info: PRIVATE: CLRq NUMERIC "1"
// Retrieval info: PRIVATE: CLRrdaddress NUMERIC "1"
// Retrieval info: PRIVATE: CLRrren NUMERIC "0"
// Retrieval info: PRIVATE: CLRwraddress NUMERIC "0"
// Retrieval info: PRIVATE: CLRwren NUMERIC "0"
// Retrieval info: PRIVATE: Clock NUMERIC "0"
// Retrieval info: PRIVATE: Clock_A NUMERIC "0"
// Retrieval info: PRIVATE: Clock_B NUMERIC "0"
// Retrieval info: PRIVATE: IMPLEMENT_IN_LES NUMERIC "0"
// Retrieval info: PRIVATE: INDATA_ACLR_B NUMERIC "0"
// Retrieval info: PRIVATE: INDATA_REG_B NUMERIC "0"
// Retrieval info: PRIVATE: INIT_FILE_LAYOUT STRING "PORT_B"
// Retrieval info: PRIVATE: INIT_TO_SIM_X NUMERIC "0"
// Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Cyclone IV E"
// Retrieval info: PRIVATE: JTAG_ENABLED NUMERIC "0"
// Retrieval info: PRIVATE: JTAG_ID STRING "NONE"
// Retrieval info: PRIVATE: MAXIMUM_DEPTH NUMERIC "0"
// Retrieval info: PRIVATE: MEMSIZE NUMERIC "2048"
// Retrieval info: PRIVATE: MEM_IN_BITS NUMERIC "0"
// Retrieval info: PRIVATE: MIFfilename STRING "../data.mif"
// Retrieval info: PRIVATE: OPERATION_MODE NUMERIC "2"
// Retrieval info: PRIVATE: OUTDATA_ACLR_B NUMERIC "1"
// Retrieval info: PRIVATE: OUTDATA_REG_B NUMERIC "0"
// Retrieval info: PRIVATE: RAM_BLOCK_TYPE NUMERIC "2"
// Retrieval info: PRIVATE: READ_DURING_WRITE_MODE_MIXED_PORTS NUMERIC "2"
// Retrieval info: PRIVATE: READ_DURING_WRITE_MODE_PORT_A NUMERIC "3"
// Retrieval info: PRIVATE: READ_DURING_WRITE_MODE_PORT_B NUMERIC "3"
// Retrieval info: PRIVATE: REGdata NUMERIC "1"
// Retrieval info: PRIVATE: REGq NUMERIC "1"
// Retrieval info: PRIVATE: REGrdaddress NUMERIC "1"
// Retrieval info: PRIVATE: REGrren NUMERIC "1"
// Retrieval info: PRIVATE: REGwraddress NUMERIC "1"
// Retrieval info: PRIVATE: REGwren NUMERIC "1"
// Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "1"
// Retrieval info: PRIVATE: USE_DIFF_CLKEN NUMERIC "0"
// Retrieval info: PRIVATE: UseDPRAM NUMERIC "1"
// Retrieval info: PRIVATE: VarWidth NUMERIC "0"
// Retrieval info: PRIVATE: WIDTH_READ_A NUMERIC "8"
// Retrieval info: PRIVATE: WIDTH_READ_B NUMERIC "8"
// Retrieval info: PRIVATE: WIDTH_WRITE_A NUMERIC "8"
// Retrieval info: PRIVATE: WIDTH_WRITE_B NUMERIC "8"
// Retrieval info: PRIVATE: WRADDR_ACLR_B NUMERIC "0"
// Retrieval info: PRIVATE: WRADDR_REG_B NUMERIC "0"
// Retrieval info: PRIVATE: WRCTRL_ACLR_B NUMERIC "0"
// Retrieval info: PRIVATE: enable NUMERIC "0"
// Retrieval info: PRIVATE: rden NUMERIC "1"
// Retrieval info: LIBRARY: altera_mf altera_mf.altera_mf_components.all
// Retrieval info: CONSTANT: ADDRESS_ACLR_B STRING "CLEAR0"
// Retrieval info: CONSTANT: ADDRESS_REG_B STRING "CLOCK0"
// Retrieval info: CONSTANT: CLOCK_ENABLE_INPUT_A STRING "BYPASS"
// Retrieval info: CONSTANT: CLOCK_ENABLE_INPUT_B STRING "BYPASS"
// Retrieval info: CONSTANT: CLOCK_ENABLE_OUTPUT_B STRING "BYPASS"
// Retrieval info: CONSTANT: INIT_FILE STRING "../data.mif"
// Retrieval info: CONSTANT: INTENDED_DEVICE_FAMILY STRING "Cyclone IV E"
// Retrieval info: CONSTANT: LPM_TYPE STRING "altsyncram"
// Retrieval info: CONSTANT: NUMWORDS_A NUMERIC "256"
// Retrieval info: CONSTANT: NUMWORDS_B NUMERIC "256"
// Retrieval info: CONSTANT: OPERATION_MODE STRING "DUAL_PORT"
// Retrieval info: CONSTANT: OUTDATA_ACLR_B STRING "CLEAR0"
// Retrieval info: CONSTANT: OUTDATA_REG_B STRING "UNREGISTERED"
// Retrieval info: CONSTANT: POWER_UP_UNINITIALIZED STRING "FALSE"
// Retrieval info: CONSTANT: RAM_BLOCK_TYPE STRING "M9K"
// Retrieval info: CONSTANT: RDCONTROL_REG_B STRING "CLOCK0"
// Retrieval info: CONSTANT: READ_DURING_WRITE_MODE_MIXED_PORTS STRING "DONT_CARE"
// Retrieval info: CONSTANT: WIDTHAD_A NUMERIC "8"
// Retrieval info: CONSTANT: WIDTHAD_B NUMERIC "8"
// Retrieval info: CONSTANT: WIDTH_A NUMERIC "8"
// Retrieval info: CONSTANT: WIDTH_B NUMERIC "8"
// Retrieval info: CONSTANT: WIDTH_BYTEENA_A NUMERIC "1"
// Retrieval info: USED_PORT: aclr 0 0 0 0 INPUT GND "aclr"
// Retrieval info: USED_PORT: clock 0 0 0 0 INPUT VCC "clock"
// Retrieval info: USED_PORT: data 0 0 8 0 INPUT NODEFVAL "data[7..0]"
// Retrieval info: USED_PORT: q 0 0 8 0 OUTPUT NODEFVAL "q[7..0]"
// Retrieval info: USED_PORT: rdaddress 0 0 8 0 INPUT NODEFVAL "rdaddress[7..0]"
// Retrieval info: USED_PORT: rden 0 0 0 0 INPUT VCC "rden"
// Retrieval info: USED_PORT: wraddress 0 0 8 0 INPUT NODEFVAL "wraddress[7..0]"
// Retrieval info: USED_PORT: wren 0 0 0 0 INPUT GND "wren"
// Retrieval info: CONNECT: @aclr0 0 0 0 0 aclr 0 0 0 0
// Retrieval info: CONNECT: @address_a 0 0 8 0 wraddress 0 0 8 0
// Retrieval info: CONNECT: @address_b 0 0 8 0 rdaddress 0 0 8 0
// Retrieval info: CONNECT: @clock0 0 0 0 0 clock 0 0 0 0
// Retrieval info: CONNECT: @data_a 0 0 8 0 data 0 0 8 0
// Retrieval info: CONNECT: @rden_b 0 0 0 0 rden 0 0 0 0
// Retrieval info: CONNECT: @wren_a 0 0 0 0 wren 0 0 0 0
// Retrieval info: CONNECT: q 0 0 8 0 @q_b 0 0 8 0
// Retrieval info: GEN_FILE: TYPE_NORMAL data.v TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL data.inc FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL data.cmp FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL data.bsf TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL data_inst.v FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL data_bb.v FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL data_syn.v TRUE
// Retrieval info: LIB_FILE: altera_mf
