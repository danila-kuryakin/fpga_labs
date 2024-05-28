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
      {MODELNAME temp1_RAM_AUTO_1R1W_memcore RTLNAME foo_m_temp1_RAM_AUTO_1R1W_memcore BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME temp1_RAM_AUTO_1R1W RTLNAME foo_m_temp1_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2}
    }
  }
}
