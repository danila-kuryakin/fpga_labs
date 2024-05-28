set SynModuleInfo {
  {SRCNAME foo_m MODELNAME foo_m RTLNAME foo_m IS_TOP 1
    SUBMODULES {
      {MODELNAME foo_m_mul_32s_32s_32_5_1 RTLNAME foo_m_mul_32s_32s_32_5_1 BINDTYPE op TYPE mul IMPL auto LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME foo_m_mul_32s_6ns_32_5_1 RTLNAME foo_m_mul_32s_6ns_32_5_1 BINDTYPE op TYPE mul IMPL auto LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME foo_m_temp1_RAM_AUTO_1R1W RTLNAME foo_m_temp1_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
}
