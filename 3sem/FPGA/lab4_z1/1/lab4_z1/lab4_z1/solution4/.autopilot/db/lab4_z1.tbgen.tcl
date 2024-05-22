set moduleName lab4_z1
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type loop_rewind
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {lab4_z1}
set C_modelType { void 0 }
set C_modelArgList {
	{ firstVector_arr int 16 regular {array 4 { 1 1 } 1 1 }  }
	{ secondVector_arr int 16 regular {array 4 { 1 3 } 1 1 }  }
	{ resultVecror_arr int 32 regular {array 4 { 0 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "firstVector_arr", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "secondVector_arr", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "resultVecror_arr", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 24
set portList { 
	{ ap_local_block sc_out sc_logic 1 signal -1 } 
	{ ap_local_deadlock sc_out sc_logic 1 signal -1 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ firstVector_arr_address0 sc_out sc_lv 2 signal 0 } 
	{ firstVector_arr_ce0 sc_out sc_logic 1 signal 0 } 
	{ firstVector_arr_q0 sc_in sc_lv 16 signal 0 } 
	{ firstVector_arr_address1 sc_out sc_lv 2 signal 0 } 
	{ firstVector_arr_ce1 sc_out sc_logic 1 signal 0 } 
	{ firstVector_arr_q1 sc_in sc_lv 16 signal 0 } 
	{ secondVector_arr_address0 sc_out sc_lv 2 signal 1 } 
	{ secondVector_arr_ce0 sc_out sc_logic 1 signal 1 } 
	{ secondVector_arr_q0 sc_in sc_lv 16 signal 1 } 
	{ resultVecror_arr_address0 sc_out sc_lv 2 signal 2 } 
	{ resultVecror_arr_ce0 sc_out sc_logic 1 signal 2 } 
	{ resultVecror_arr_we0 sc_out sc_logic 1 signal 2 } 
	{ resultVecror_arr_d0 sc_out sc_lv 32 signal 2 } 
	{ resultVecror_arr_address1 sc_out sc_lv 2 signal 2 } 
	{ resultVecror_arr_ce1 sc_out sc_logic 1 signal 2 } 
	{ resultVecror_arr_q1 sc_in sc_lv 32 signal 2 } 
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
 	{ "name": "firstVector_arr_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "firstVector_arr", "role": "address0" }} , 
 	{ "name": "firstVector_arr_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "firstVector_arr", "role": "ce0" }} , 
 	{ "name": "firstVector_arr_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "firstVector_arr", "role": "q0" }} , 
 	{ "name": "firstVector_arr_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "firstVector_arr", "role": "address1" }} , 
 	{ "name": "firstVector_arr_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "firstVector_arr", "role": "ce1" }} , 
 	{ "name": "firstVector_arr_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "firstVector_arr", "role": "q1" }} , 
 	{ "name": "secondVector_arr_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "secondVector_arr", "role": "address0" }} , 
 	{ "name": "secondVector_arr_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "secondVector_arr", "role": "ce0" }} , 
 	{ "name": "secondVector_arr_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "secondVector_arr", "role": "q0" }} , 
 	{ "name": "resultVecror_arr_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "address0" }} , 
 	{ "name": "resultVecror_arr_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "ce0" }} , 
 	{ "name": "resultVecror_arr_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "we0" }} , 
 	{ "name": "resultVecror_arr_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "d0" }} , 
 	{ "name": "resultVecror_arr_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "address1" }} , 
 	{ "name": "resultVecror_arr_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "ce1" }} , 
 	{ "name": "resultVecror_arr_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "lab4_z1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "Rewind", "UnalignedPipeline" : "0", "RewindPipeline" : "1", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "12", "EstimateLatencyMax" : "13",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "firstVector_arr", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "secondVector_arr", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "resultVecror_arr", "Type" : "Memory", "Direction" : "IO"}],
		"Loop" : [
			{"Name" : "L2", "PipelineType" : "rewind",
				"LoopDec" : {"FSMBitwidth" : "3", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter3", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter3", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ama_addmuladd_17s_17s_16s_32ns_32_4_1_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	lab4_z1 {
		firstVector_arr {Type I LastRead 3 FirstWrite -1}
		secondVector_arr {Type I LastRead 1 FirstWrite -1}
		resultVecror_arr {Type IO LastRead 1 FirstWrite 7}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "12", "Max" : "13"}
	, {"Name" : "Interval", "Min" : "8", "Max" : "8"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	firstVector_arr { ap_memory {  { firstVector_arr_address0 mem_address 1 2 }  { firstVector_arr_ce0 mem_ce 1 1 }  { firstVector_arr_q0 in_data 0 16 }  { firstVector_arr_address1 MemPortADDR2 1 2 }  { firstVector_arr_ce1 MemPortCE2 1 1 }  { firstVector_arr_q1 in_data 0 16 } } }
	secondVector_arr { ap_memory {  { secondVector_arr_address0 mem_address 1 2 }  { secondVector_arr_ce0 mem_ce 1 1 }  { secondVector_arr_q0 mem_dout 0 16 } } }
	resultVecror_arr { ap_memory {  { resultVecror_arr_address0 mem_address 1 2 }  { resultVecror_arr_ce0 mem_ce 1 1 }  { resultVecror_arr_we0 mem_we 1 1 }  { resultVecror_arr_d0 mem_din 1 32 }  { resultVecror_arr_address1 MemPortADDR2 1 2 }  { resultVecror_arr_ce1 MemPortCE2 1 1 }  { resultVecror_arr_q1 MemPortDOUT2 0 32 } } }
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
