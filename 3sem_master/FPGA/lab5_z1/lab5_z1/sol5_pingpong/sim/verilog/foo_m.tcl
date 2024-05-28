
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_foo_m_top/AESL_inst_foo_m/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set return_group [add_wave_group return(axi_slave) -into $coutputgroup]
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_we1 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_q1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_d1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_ce1 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_address1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_we0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_q0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_d0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_ce0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out2_address0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_we1 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_q1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_d1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_ce1 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_address1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_we0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_q0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_d0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_ce0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_out1_address0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_local_deadlock -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_local_block -into $return_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set return_group [add_wave_group return(memory) -into $cinputgroup]
add_wave /apatb_foo_m_top/AESL_inst_foo_m/scale -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_we1 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_q1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_d1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_ce1 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_address1 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_we0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_q0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_d0 -into $return_group -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_ce0 -into $return_group -color #ffff00 -radix hex
add_wave /apatb_foo_m_top/AESL_inst_foo_m/data_in_address0 -into $return_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_start -into $blocksiggroup
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_done -into $blocksiggroup
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_ready -into $blocksiggroup
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_idle -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_foo_m_top/AESL_inst_foo_m/ap_clk -into $clockgroup
save_wave_config foo_m.wcfg
run all
quit

