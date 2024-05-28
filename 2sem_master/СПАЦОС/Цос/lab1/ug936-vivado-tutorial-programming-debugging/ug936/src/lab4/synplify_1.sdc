# Synopsys, Inc. constraint file
# C:/Data/demos/hdl_debug_demo/src_1/debug.sdc
# Written on Thu Dec 23 14:39:05 2010
# by Synplify Pro, D-2010.03 Scope Editor

#
# Collections
#

#
# Clocks
#  Clock period
#  200 MHz oscillator
create_clock -period 5 -name CLK_P [get_ports CLK_P]
create_clock -period 5 -name CLK_N [get_ports CLK_N]

#
# Clock to Clock
#

#
# Inputs/Outputs
# Locations and I/O Standards
#
define_attribute  {p:CLK_P} {xc_loc} {AD12}
define_io_standard {p:CLK_P} -delay_type input syn_pad_type {LVDS}
define_attribute  {p:CLK_N} {xc_loc} {AD11}
define_io_standard {p:CLK_N} -delay_type input syn_pad_type {LVDS}

define_attribute  {p:GPIO_BUTTONS[0]} {xc_loc} {AA12}
define_io_standard {p:GPIO_BUTTONS[0]} -delay_type input syn_pad_type {LVCMOS_15}
define_attribute  {p:GPIO_BUTTONS[1]} {xc_loc} {AG5}
define_io_standard {p:GPIO_BUTTONS[1]} -delay_type input syn_pad_type {LVCMOS_15}
define_attribute  {p:GPIO_SWITCH} {xc_loc} {Y28}
define_io_standard {p:GPIO_SWITCH} -delay_type input syn_pad_type {LVCMOS_25}

define_attribute  {p:LEDS_n[0]} {xc_loc} {AB8}
define_io_standard {p:LEDS_n[0]} -delay_type output syn_pad_type {LVCMOS_15}
define_attribute  {p:LEDS_n[1]} {xc_loc} {AA8}
define_io_standard {p:LEDS_n[1]} -delay_type output syn_pad_type {LVCMOS_15}
define_attribute  {p:LEDS_n[2]} {xc_loc} {AC9}
define_io_standard {p:LEDS_n[2]} -delay_type output syn_pad_type {LVCMOS_15}
define_attribute  {p:LEDS_n[3]} {xc_loc} {AB9}
define_io_standard {p:LEDS_n[3]} -delay_type output syn_pad_type {LVCMOS_15}


#
# Registers
#

#
# Delay Paths
#
#
# Other
#
