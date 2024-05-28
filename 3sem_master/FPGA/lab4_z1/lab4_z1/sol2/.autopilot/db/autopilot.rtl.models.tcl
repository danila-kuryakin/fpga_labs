set SynModuleInfo {
  {SRCNAME lab4_z1_Pipeline_L1 MODELNAME lab4_z1_Pipeline_L1 RTLNAME lab4_z1_lab4_z1_Pipeline_L1
    SUBMODULES {
      {MODELNAME mac_muladd_16s_16s_32ns_32_4_1 RTLNAME lab4_z1_mac_muladd_16s_16s_32ns_32_4_1 BINDTYPE op TYPE add IMPL dsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME flow_control_loop_pipe_sequential_init RTLNAME lab4_z1_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME lab4_z1_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME lab4_z1 MODELNAME lab4_z1 RTLNAME lab4_z1 IS_TOP 1}
}
