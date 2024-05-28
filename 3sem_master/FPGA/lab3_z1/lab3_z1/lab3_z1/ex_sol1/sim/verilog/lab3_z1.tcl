
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set return_group [add_wave_group return(axi_slave) -into $coutputgroup]
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_return -into $return_group -radix hex
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/res_ap_vld -into $return_group -color #ffff00 -radix hex
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/res -into $return_group -radix hex
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_local_deadlock -into $return_group -radix hex
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_local_block -into $return_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set return_group [add_wave_group return(wire) -into $cinputgroup]
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/inC -into $return_group -radix hex
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/inB -into $return_group -radix hex
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/inA -into $return_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_start -into $blocksiggroup
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_done -into $blocksiggroup
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_idle -into $blocksiggroup
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_lab3_z1_top/AESL_inst_lab3_z1/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_lab3_z1_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_lab3_z1_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_lab3_z1_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_lab3_z1_top/LENGTH_inA -into $tb_portdepth_group -radix hex
add_wave /apatb_lab3_z1_top/LENGTH_inB -into $tb_portdepth_group -radix hex
add_wave /apatb_lab3_z1_top/LENGTH_inC -into $tb_portdepth_group -radix hex
add_wave /apatb_lab3_z1_top/LENGTH_res -into $tb_portdepth_group -radix hex
add_wave /apatb_lab3_z1_top/LENGTH_ap_return -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_return_group [add_wave_group return(axi_slave) -into $tbcoutputgroup]
add_wave /apatb_lab3_z1_top/ap_return -into $tb_return_group -radix hex
add_wave /apatb_lab3_z1_top/res_ap_vld -into $tb_return_group -color #ffff00 -radix hex
add_wave /apatb_lab3_z1_top/res -into $tb_return_group -radix hex
add_wave /apatb_lab3_z1_top/ap_local_deadlock -into $tb_return_group -radix hex
add_wave /apatb_lab3_z1_top/ap_local_block -into $tb_return_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_return_group [add_wave_group return(wire) -into $tbcinputgroup]
add_wave /apatb_lab3_z1_top/inC -into $tb_return_group -radix hex
add_wave /apatb_lab3_z1_top/inB -into $tb_return_group -radix hex
add_wave /apatb_lab3_z1_top/inA -into $tb_return_group -radix hex
save_wave_config lab3_z1.wcfg
run all
quit

