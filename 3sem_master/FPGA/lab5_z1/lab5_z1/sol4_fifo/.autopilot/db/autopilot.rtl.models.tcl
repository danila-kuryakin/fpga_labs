set SynModuleInfo {
  {SRCNAME Loop_Loop1_proc MODELNAME Loop_Loop1_proc RTLNAME foo_m_Loop_Loop1_proc
    SUBMODULES {
      {MODELNAME mul_32s_32s_32_1_1 RTLNAME foo_m_mul_32s_32s_32_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME split MODELNAME split RTLNAME foo_m_split}
  {SRCNAME Loop_Loop2_proc MODELNAME Loop_Loop2_proc RTLNAME foo_m_Loop_Loop2_proc
    SUBMODULES {
      {MODELNAME mul_32s_6ns_32_1_1 RTLNAME foo_m_mul_32s_6ns_32_1_1 BINDTYPE op TYPE mul IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME Loop_Loop3_proc MODELNAME Loop_Loop3_proc RTLNAME foo_m_Loop_Loop3_proc}
  {SRCNAME foo_m MODELNAME foo_m RTLNAME foo_m IS_TOP 1
    SUBMODULES {
      {MODELNAME fifo_w32_d16384_A RTLNAME foo_m_fifo_w32_d16384_A BINDTYPE storage TYPE fifo IMPL memory LATENCY -1 ALLOW_PRAGMA 1 INSTNAME {$InstName}}
      {MODELNAME start_for_split_U0 RTLNAME foo_m_start_for_split_U0 BINDTYPE storage TYPE fifo IMPL srl LATENCY -1 ALLOW_PRAGMA 1 INSTNAME {$InstName}}
      {MODELNAME start_for_Loop_Loop2_proc_U0 RTLNAME foo_m_start_for_Loop_Loop2_proc_U0 BINDTYPE storage TYPE fifo IMPL srl LATENCY -1 ALLOW_PRAGMA 1 INSTNAME {$InstName}}
      {MODELNAME start_for_Loop_Loop3_proc_U0 RTLNAME foo_m_start_for_Loop_Loop3_proc_U0 BINDTYPE storage TYPE fifo IMPL srl LATENCY -1 ALLOW_PRAGMA 1 INSTNAME {$InstName}}
    }
  }
}
