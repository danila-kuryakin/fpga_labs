set moduleName lab3_z2
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
set C_modelName {lab3_z2}
set C_modelType { void 0 }
set C_modelArgList {
	{ inA_ar int 16 regular {array 4096 { 1 3 } 1 1 }  }
	{ out_ar int 16 regular {array 4096 { 2 3 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "inA_ar", "interface" : "memory", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "out_ar", "interface" : "memory", "bitwidth" : 16, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 16
set portList { 
	{ ap_local_block sc_out sc_logic 1 signal -1 } 
	{ ap_local_deadlock sc_out sc_logic 1 signal -1 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ inA_ar_address0 sc_out sc_lv 12 signal 0 } 
	{ inA_ar_ce0 sc_out sc_logic 1 signal 0 } 
	{ inA_ar_q0 sc_in sc_lv 16 signal 0 } 
	{ out_ar_address0 sc_out sc_lv 12 signal 1 } 
	{ out_ar_ce0 sc_out sc_logic 1 signal 1 } 
	{ out_ar_we0 sc_out sc_logic 1 signal 1 } 
	{ out_ar_d0 sc_out sc_lv 16 signal 1 } 
	{ out_ar_q0 sc_in sc_lv 16 signal 1 } 
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
 	{ "name": "inA_ar_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "inA_ar", "role": "address0" }} , 
 	{ "name": "inA_ar_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inA_ar", "role": "ce0" }} , 
 	{ "name": "inA_ar_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "inA_ar", "role": "q0" }} , 
 	{ "name": "out_ar_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "out_ar", "role": "address0" }} , 
 	{ "name": "out_ar_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_ar", "role": "ce0" }} , 
 	{ "name": "out_ar_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_ar", "role": "we0" }} , 
 	{ "name": "out_ar_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "out_ar", "role": "d0" }} , 
 	{ "name": "out_ar_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "out_ar", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "lab3_z2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "16385", "EstimateLatencyMax" : "16385",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "inA_ar", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_ar", "Type" : "Memory", "Direction" : "IO"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_7_1", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "5", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state5"], "QuitState" : ["ap_ST_fsm_state2"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state1"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]}]}


set ArgLastReadFirstWriteLatency {
	lab3_z2 {
		inA_ar {Type I LastRead 1 FirstWrite -1}
		out_ar {Type IO LastRead 2 FirstWrite 4}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "16385", "Max" : "16385"}
	, {"Name" : "Interval", "Min" : "16386", "Max" : "16386"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	inA_ar { ap_memory {  { inA_ar_address0 mem_address 1 12 }  { inA_ar_ce0 mem_ce 1 1 }  { inA_ar_q0 in_data 0 16 } } }
	out_ar { ap_memory {  { out_ar_address0 mem_address 1 12 }  { out_ar_ce0 mem_ce 1 1 }  { out_ar_we0 mem_we 1 1 }  { out_ar_d0 mem_din 1 16 }  { out_ar_q0 mem_dout 0 16 } } }
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
