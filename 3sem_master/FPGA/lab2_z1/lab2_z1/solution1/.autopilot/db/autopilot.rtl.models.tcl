set SynModuleInfo {
  {SRCNAME lab2_z1 MODELNAME lab2_z1 RTLNAME lab2_z1 IS_TOP 1
    SUBMODULES {
      {MODELNAME lab2_z1_mul_16ns_32s_32_5_1 RTLNAME lab2_z1_mul_16ns_32s_32_5_1 BINDTYPE op TYPE mul IMPL auto LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME lab2_z1_flow_control_loop_pipe RTLNAME lab2_z1_flow_control_loop_pipe BINDTYPE interface TYPE internal_upc_flow_control INSTNAME lab2_z1_flow_control_loop_pipe_U}
    }
  }
}
