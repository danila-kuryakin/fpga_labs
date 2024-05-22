set moduleName dct
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {dct}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_r int 16 regular {array 64 { 1 3 } 1 1 }  }
	{ output_r int 16 regular {array 64 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_r", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "output_r", "interface" : "memory", "bitwidth" : 16, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 15
set portList { 
	{ ap_local_block sc_out sc_logic 1 signal -1 } 
	{ ap_local_deadlock sc_out sc_logic 1 signal -1 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_r_address0 sc_out sc_lv 6 signal 0 } 
	{ input_r_ce0 sc_out sc_logic 1 signal 0 } 
	{ input_r_q0 sc_in sc_lv 16 signal 0 } 
	{ output_r_address0 sc_out sc_lv 6 signal 1 } 
	{ output_r_ce0 sc_out sc_logic 1 signal 1 } 
	{ output_r_we0 sc_out sc_logic 1 signal 1 } 
	{ output_r_d0 sc_out sc_lv 16 signal 1 } 
}
set NewPortList {[ 
	{ "name": "ap_local_block", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_local_block", "role": "default" }} , 
 	{ "name": "ap_local_deadlock", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_local_deadlock", "role": "default" }} , 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "input_r", "role": "address0" }} , 
 	{ "name": "input_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_r", "role": "ce0" }} , 
 	{ "name": "input_r_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "input_r", "role": "q0" }} , 
 	{ "name": "output_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "output_r", "role": "address0" }} , 
 	{ "name": "output_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_r", "role": "ce0" }} , 
 	{ "name": "output_r_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_r", "role": "we0" }} , 
 	{ "name": "output_r_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "output_r", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "16", "26", "28", "38", "40"],
		"CDFG" : "dct",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "415", "EstimateLatencyMax" : "415",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "14", "SubInstance" : "grp_dct_Pipeline_RD_Loop_Row_RD_Loop_Col_fu_70", "Port" : "input_r", "Inst_start_state" : "1", "Inst_end_state" : "2"}]},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "40", "SubInstance" : "grp_dct_Pipeline_WR_Loop_Row_WR_Loop_Col_fu_134", "Port" : "output_r", "Inst_start_state" : "11", "Inst_end_state" : "12"}]},
			{"Name" : "dct_coeff_table_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_0", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_0", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_1", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_1", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_2", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_2", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_3", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_3", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_3", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_4", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_4", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_4", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_5", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_5", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_5", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_6", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_6", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_6", "Inst_start_state" : "3", "Inst_end_state" : "4"}]},
			{"Name" : "dct_coeff_table_7", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "28", "SubInstance" : "grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Port" : "dct_coeff_table_7", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "16", "SubInstance" : "grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Port" : "dct_coeff_table_7", "Inst_start_state" : "3", "Inst_end_state" : "4"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_0_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_1_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_2_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_3_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_4_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_5_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_6_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dct_coeff_table_7_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.row_outbuf_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.col_outbuf_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.col_inbuf_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.buf_2d_in_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.buf_2d_out_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_RD_Loop_Row_RD_Loop_Col_fu_70", "Parent" : "0", "Child" : ["15"],
		"CDFG" : "dct_Pipeline_RD_Loop_Row_RD_Loop_Col",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "66", "EstimateLatencyMax" : "66",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "buf_2d_in", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "RD_Loop_Row_RD_Loop_Col", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_RD_Loop_Row_RD_Loop_Col_fu_70.flow_control_loop_pipe_sequential_init_U", "Parent" : "14"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78", "Parent" : "0", "Child" : ["17", "18", "19", "20", "21", "22", "23", "24", "25"],
		"CDFG" : "dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "70", "EstimateLatencyMax" : "70",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "buf_2d_in", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "row_outbuf", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "dct_coeff_table_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_7", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "Row_DCT_Loop_DCT_Outer_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter5", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter5", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mul_mul_16s_15s_29_4_1_U3", "Parent" : "16"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mul_mul_16s_15s_29_4_1_U4", "Parent" : "16"},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mul_mul_16s_15s_29_4_1_U5", "Parent" : "16"},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mac_muladd_16s_15s_13ns_29_4_1_U6", "Parent" : "16"},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mac_muladd_16s_14ns_29s_29_4_1_U7", "Parent" : "16"},
	{"ID" : "22", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mac_muladd_16s_15s_29s_29_4_1_U8", "Parent" : "16"},
	{"ID" : "23", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mac_muladd_16s_15s_29s_29_4_1_U9", "Parent" : "16"},
	{"ID" : "24", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.mac_muladd_16s_15s_29ns_29_4_1_U10", "Parent" : "16"},
	{"ID" : "25", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop_fu_78.flow_control_loop_pipe_sequential_init_U", "Parent" : "16"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Xpose_Row_Outer_Loop_Xpose_Row_Inner_Loop_fu_100", "Parent" : "0", "Child" : ["27"],
		"CDFG" : "dct_Pipeline_Xpose_Row_Outer_Loop_Xpose_Row_Inner_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "66", "EstimateLatencyMax" : "66",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "row_outbuf", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "col_inbuf", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "Xpose_Row_Outer_Loop_Xpose_Row_Inner_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "27", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Xpose_Row_Outer_Loop_Xpose_Row_Inner_Loop_fu_100.flow_control_loop_pipe_sequential_init_U", "Parent" : "26"},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106", "Parent" : "0", "Child" : ["29", "30", "31", "32", "33", "34", "35", "36", "37"],
		"CDFG" : "dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "70", "EstimateLatencyMax" : "70",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "col_inbuf", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "col_outbuf", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "dct_coeff_table_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dct_coeff_table_7", "Type" : "Memory", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "Col_DCT_Loop_DCT_Outer_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter5", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter5", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "29", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mul_mul_16s_15s_29_4_1_U28", "Parent" : "28"},
	{"ID" : "30", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mul_mul_16s_15s_29_4_1_U29", "Parent" : "28"},
	{"ID" : "31", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mul_mul_16s_15s_29_4_1_U30", "Parent" : "28"},
	{"ID" : "32", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mac_muladd_16s_15s_13ns_29_4_1_U31", "Parent" : "28"},
	{"ID" : "33", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mac_muladd_16s_14ns_29s_29_4_1_U32", "Parent" : "28"},
	{"ID" : "34", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mac_muladd_16s_15s_29s_29_4_1_U33", "Parent" : "28"},
	{"ID" : "35", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mac_muladd_16s_15s_29s_29_4_1_U34", "Parent" : "28"},
	{"ID" : "36", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.mac_muladd_16s_15s_29ns_29_4_1_U35", "Parent" : "28"},
	{"ID" : "37", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop_fu_106.flow_control_loop_pipe_sequential_init_U", "Parent" : "28"},
	{"ID" : "38", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Xpose_Col_Outer_Loop_Xpose_Col_Inner_Loop_fu_128", "Parent" : "0", "Child" : ["39"],
		"CDFG" : "dct_Pipeline_Xpose_Col_Outer_Loop_Xpose_Col_Inner_Loop",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "66", "EstimateLatencyMax" : "66",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "col_outbuf", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buf_2d_out", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "Xpose_Col_Outer_Loop_Xpose_Col_Inner_Loop", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "39", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_Xpose_Col_Outer_Loop_Xpose_Col_Inner_Loop_fu_128.flow_control_loop_pipe_sequential_init_U", "Parent" : "38"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_WR_Loop_Row_WR_Loop_Col_fu_134", "Parent" : "0", "Child" : ["41"],
		"CDFG" : "dct_Pipeline_WR_Loop_Row_WR_Loop_Col",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "66", "EstimateLatencyMax" : "66",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "buf_2d_out", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "WR_Loop_Row_WR_Loop_Col", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter0", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "41", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_dct_Pipeline_WR_Loop_Row_WR_Loop_Col_fu_134.flow_control_loop_pipe_sequential_init_U", "Parent" : "40"}]}


set ArgLastReadFirstWriteLatency {
	dct {
		input_r {Type I LastRead 0 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 1}
		dct_coeff_table_0 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_1 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_2 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_3 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_4 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_5 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_6 {Type I LastRead -1 FirstWrite -1}
		dct_coeff_table_7 {Type I LastRead -1 FirstWrite -1}}
	dct_Pipeline_RD_Loop_Row_RD_Loop_Col {
		buf_2d_in {Type O LastRead -1 FirstWrite 1}
		input_r {Type I LastRead 0 FirstWrite -1}}
	dct_Pipeline_Row_DCT_Loop_DCT_Outer_Loop {
		buf_2d_in {Type I LastRead 1 FirstWrite -1}
		row_outbuf {Type O LastRead -1 FirstWrite 5}
		dct_coeff_table_0 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_1 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_2 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_3 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_4 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_5 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_6 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_7 {Type I LastRead 0 FirstWrite -1}}
	dct_Pipeline_Xpose_Row_Outer_Loop_Xpose_Row_Inner_Loop {
		row_outbuf {Type I LastRead 0 FirstWrite -1}
		col_inbuf {Type O LastRead -1 FirstWrite 1}}
	dct_Pipeline_Col_DCT_Loop_DCT_Outer_Loop {
		col_inbuf {Type I LastRead 1 FirstWrite -1}
		col_outbuf {Type O LastRead -1 FirstWrite 5}
		dct_coeff_table_0 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_1 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_2 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_3 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_4 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_5 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_6 {Type I LastRead 0 FirstWrite -1}
		dct_coeff_table_7 {Type I LastRead 0 FirstWrite -1}}
	dct_Pipeline_Xpose_Col_Outer_Loop_Xpose_Col_Inner_Loop {
		col_outbuf {Type I LastRead 0 FirstWrite -1}
		buf_2d_out {Type O LastRead -1 FirstWrite 1}}
	dct_Pipeline_WR_Loop_Row_WR_Loop_Col {
		buf_2d_out {Type I LastRead 0 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "415", "Max" : "415"}
	, {"Name" : "Interval", "Min" : "416", "Max" : "416"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	input_r { ap_memory {  { input_r_address0 mem_address 1 6 }  { input_r_ce0 mem_ce 1 1 }  { input_r_q0 mem_dout 0 16 } } }
	output_r { ap_memory {  { output_r_address0 mem_address 1 6 }  { output_r_ce0 mem_ce 1 1 }  { output_r_we0 mem_we 1 1 }  { output_r_d0 mem_din 1 16 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
