
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set return_group [add_wave_group return(axi_slave) -into $coutputgroup]
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/outArr_d0 -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/outArr_we0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/outArr_ce0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/outArr_address0 -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_local_deadlock -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_local_block -into $return_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set return_group [add_wave_group return(memory) -into $cinputgroup]
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/c -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/b -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/a -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/inArr_q0 -into $return_group -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/inArr_ce0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/inArr_address0 -into $return_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_start -into $blocksiggroup
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_done -into $blocksiggroup
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_idle -into $blocksiggroup
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_lab1_z2_top/AESL_inst_lab1_z2/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_lab1_z2_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_lab1_z2_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_lab1_z2_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_lab1_z2_top/LENGTH_inArr -into $tb_portdepth_group -radix hex
add_wave /apatb_lab1_z2_top/LENGTH_a -into $tb_portdepth_group -radix hex
add_wave /apatb_lab1_z2_top/LENGTH_b -into $tb_portdepth_group -radix hex
add_wave /apatb_lab1_z2_top/LENGTH_c -into $tb_portdepth_group -radix hex
add_wave /apatb_lab1_z2_top/LENGTH_outArr -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_return_group [add_wave_group return(axi_slave) -into $tbcoutputgroup]
add_wave /apatb_lab1_z2_top/outArr_d0 -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/outArr_we0 -into $tb_return_group -color #ffff00 -radix hex
add_wave /apatb_lab1_z2_top/outArr_ce0 -into $tb_return_group -color #ffff00 -radix hex
add_wave /apatb_lab1_z2_top/outArr_address0 -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/ap_local_deadlock -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/ap_local_block -into $tb_return_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_return_group [add_wave_group return(memory) -into $tbcinputgroup]
add_wave /apatb_lab1_z2_top/c -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/b -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/a -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/inArr_q0 -into $tb_return_group -radix hex
add_wave /apatb_lab1_z2_top/inArr_ce0 -into $tb_return_group -color #ffff00 -radix hex
add_wave /apatb_lab1_z2_top/inArr_address0 -into $tb_return_group -radix hex
save_wave_config lab1_z2.wcfg
run all
quit
