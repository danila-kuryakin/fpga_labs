set moduleName lab3_z1
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_chain
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {lab3_z1}
set C_modelType { int 32 }
set C_modelArgList {
	{ inA int 16 regular  }
	{ inB int 16 regular  }
	{ inC int 16 regular {pointer 0}  }
	{ res int 32 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "inA", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "inB", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "inC", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY"} , 
 	{ "Name" : "res", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 32} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_local_block sc_out sc_logic 1 signal -1 } 
	{ ap_local_deadlock sc_out sc_logic 1 signal -1 } 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ inA sc_in sc_lv 16 signal 0 } 
	{ inA_ap_vld sc_in sc_logic 1 invld 0 } 
	{ inA_ap_ack sc_out sc_logic 1 inacc 0 } 
	{ inB sc_in sc_lv 16 signal 1 } 
	{ inB_ap_vld sc_in sc_logic 1 invld 1 } 
	{ inB_ap_ack sc_out sc_logic 1 inacc 1 } 
	{ inC sc_in sc_lv 16 signal 2 } 
	{ inC_ap_vld sc_in sc_logic 1 invld 2 } 
	{ inC_ap_ack sc_out sc_logic 1 inacc 2 } 
	{ res sc_out sc_lv 32 signal 3 } 
	{ res_ap_vld sc_out sc_logic 1 outvld 3 } 
	{ res_ap_ack sc_in sc_logic 1 outacc 3 } 
	{ ap_return sc_out sc_lv 32 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_local_block", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_local_block", "role": "default" }} , 
 	{ "name": "ap_local_deadlock", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_local_deadlock", "role": "default" }} , 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "inA", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "inA", "role": "default" }} , 
 	{ "name": "inA_ap_vld", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "inA", "role": "ap_vld" }} , 
 	{ "name": "inA_ap_ack", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "inA", "role": "ap_ack" }} , 
 	{ "name": "inB", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "inB", "role": "default" }} , 
 	{ "name": "inB_ap_vld", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "inB", "role": "ap_vld" }} , 
 	{ "name": "inB_ap_ack", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "inB", "role": "ap_ack" }} , 
 	{ "name": "inC", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "inC", "role": "default" }} , 
 	{ "name": "inC_ap_vld", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "inC", "role": "ap_vld" }} , 
 	{ "name": "inC_ap_ack", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "inC", "role": "ap_ack" }} , 
 	{ "name": "res", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "res", "role": "default" }} , 
 	{ "name": "res_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "res", "role": "ap_vld" }} , 
 	{ "name": "res_ap_ack", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "res", "role": "ap_ack" }} , 
 	{ "name": "ap_return", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ap_return", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "lab3_z1",
		"Protocol" : "ap_ctrl_chain",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "4", "EstimateLatencyMax" : "4",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "inA", "Type" : "HS", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "inA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "inB", "Type" : "HS", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "inB_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "inC", "Type" : "HS", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "inC_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "res", "Type" : "HS", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "res_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_mul_16s_16s_32_4_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_forward_res_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	lab3_z1 {
		inA {Type I LastRead 0 FirstWrite -1}
		inB {Type I LastRead 0 FirstWrite -1}
		inC {Type I LastRead 0 FirstWrite -1}
		res {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "4", "Max" : "4"}
	, {"Name" : "Interval", "Min" : "5", "Max" : "5"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	inA { ap_hs {  { inA in_data 0 16 }  { inA_ap_vld in_vld 0 1 }  { inA_ap_ack in_acc 1 1 } } }
	inB { ap_hs {  { inB in_data 0 16 }  { inB_ap_vld in_vld 0 1 }  { inB_ap_ack in_acc 1 1 } } }
	inC { ap_hs {  { inC in_data 0 16 }  { inC_ap_vld in_vld 0 1 }  { inC_ap_ack in_acc 1 1 } } }
	res { ap_hs {  { res out_data 1 32 }  { res_ap_vld out_vld 1 1 }  { res_ap_ack out_acc 0 1 } } }
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
