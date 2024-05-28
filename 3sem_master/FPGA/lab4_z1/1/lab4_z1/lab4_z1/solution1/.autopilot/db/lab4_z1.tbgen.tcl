set moduleName lab4_z1
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
set C_modelName {lab4_z1}
set C_modelType { void 0 }
set C_modelArgList {
	{ firstVector_arr int 16 regular {array 4 { 1 3 } 1 1 }  }
	{ secondVector_arr int 16 regular {array 4 { 1 3 } 1 1 }  }
	{ resultVecror_arr int 32 regular {array 4 { 2 3 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "firstVector_arr", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "secondVector_arr", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "resultVecror_arr", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 19
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
	{ secondVector_arr_address0 sc_out sc_lv 2 signal 1 } 
	{ secondVector_arr_ce0 sc_out sc_logic 1 signal 1 } 
	{ secondVector_arr_q0 sc_in sc_lv 16 signal 1 } 
	{ resultVecror_arr_address0 sc_out sc_lv 2 signal 2 } 
	{ resultVecror_arr_ce0 sc_out sc_logic 1 signal 2 } 
	{ resultVecror_arr_we0 sc_out sc_logic 1 signal 2 } 
	{ resultVecror_arr_d0 sc_out sc_lv 32 signal 2 } 
	{ resultVecror_arr_q0 sc_in sc_lv 32 signal 2 } 
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
 	{ "name": "secondVector_arr_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "secondVector_arr", "role": "address0" }} , 
 	{ "name": "secondVector_arr_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "secondVector_arr", "role": "ce0" }} , 
 	{ "name": "secondVector_arr_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "secondVector_arr", "role": "q0" }} , 
 	{ "name": "resultVecror_arr_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "address0" }} , 
 	{ "name": "resultVecror_arr_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "ce0" }} , 
 	{ "name": "resultVecror_arr_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "we0" }} , 
 	{ "name": "resultVecror_arr_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "d0" }} , 
 	{ "name": "resultVecror_arr_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "resultVecror_arr", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "lab4_z1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "93", "EstimateLatencyMax" : "93",
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
			{"Name" : "L1", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "8", "FirstState" : "ap_ST_fsm_state4", "LastState" : ["ap_ST_fsm_state8"], "QuitState" : ["ap_ST_fsm_state4"], "PreState" : ["ap_ST_fsm_state3"], "PostState" : ["ap_ST_fsm_state2"], "OneDepthLoop" : "0", "OneStateBlock": ""}},
			{"Name" : "L2", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "8", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state4"], "QuitState" : ["ap_ST_fsm_state2"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state1"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_16s_16s_32ns_32_4_1_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	lab4_z1 {
		firstVector_arr {Type I LastRead 3 FirstWrite -1}
		secondVector_arr {Type I LastRead 1 FirstWrite -1}
		resultVecror_arr {Type IO LastRead 1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "93", "Max" : "93"}
	, {"Name" : "Interval", "Min" : "94", "Max" : "94"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	firstVector_arr { ap_memory {  { firstVector_arr_address0 mem_address 1 2 }  { firstVector_arr_ce0 mem_ce 1 1 }  { firstVector_arr_q0 in_data 0 16 } } }
	secondVector_arr { ap_memory {  { secondVector_arr_address0 mem_address 1 2 }  { secondVector_arr_ce0 mem_ce 1 1 }  { secondVector_arr_q0 in_data 0 16 } } }
	resultVecror_arr { ap_memory {  { resultVecror_arr_address0 mem_address 1 2 }  { resultVecror_arr_ce0 mem_ce 1 1 }  { resultVecror_arr_we0 mem_we 1 1 }  { resultVecror_arr_d0 mem_din 1 32 }  { resultVecror_arr_q0 in_data 0 32 } } }
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
