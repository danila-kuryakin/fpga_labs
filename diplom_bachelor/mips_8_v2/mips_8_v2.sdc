create_clock -name clk -period 40.000 [get_ports clk]
derive_pll_clocks -create_base_clocks
derive_clock_uncertainty