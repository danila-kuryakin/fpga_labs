#--------------------------------------------------------------
#-- (C) Copyright 2010-2011 Xilinx, Inc. All Rights Reserved.
#--
#-- XILINX, the Xilinx logo, the Brand Window and other
#-- designated brands included herein are trademarks of Xilinx,
#-- Inc. All other trademarks are the property of their
#-- respective owners.
#--
#-- NOTICE OF DISCLAIMER: The information disclosed to you
#-- hereunder (the "Information") is provided "AS-IS" with no
#-- warranty of any kind, express or implied. Xilinx does not
#-- assume any liability arising from your use of the
#-- Information. You are responsible for obtaining any rights
#-- you may require for your use of this Information. Xilinx
#-- reserves the right to make changes, at any time, to the
#-- Information without notice and at its sole discretion.
#-- Xilinx assumes no obligation to correct any errors contained
#-- in the Information or to advise you of any corrections or
#-- updates. Xilinx expressly disclaims any liability in
#-- connection with technical support or assistance that may be
#-- provided to you in connection with the Information. XILINX
#-- MAKES NO OTHER WARRANTIES, WHETHER EXPRESS, IMPLIED, OR
#-- STATUTORY, REGARDING THE INFORMATION, INCLUDING ANY
#-- WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
#-- PURPOSE, OR NONINFRINGEMENT OF THIRD-PARTY RIGHTS.
#--------------------------------------------------------------

###############################################
## KC705 Development Board (XC7K325TFFG900-2)
###############################################
#
#  Clock period
#  200 MHz oscillator
create_clock -period 5.000 -name CLK_P [get_ports CLK_P]
create_clock -period 5.000 -name CLK_N [get_ports CLK_N]
create_clock -period 5.000 -name clk [get_nets clk]

# Pin locs

set_property PACKAGE_PIN AD12 [get_ports CLK_P]
set_property PACKAGE_PIN AD11 [get_ports CLK_N]
set_property IOSTANDARD LVDS [get_ports CLK_P]
set_property IOSTANDARD LVDS [get_ports CLK_N]

set_property PACKAGE_PIN AA12 [get_ports {GPIO_BUTTONS[0]}]
set_property PACKAGE_PIN AG5 [get_ports {GPIO_BUTTONS[1]}]
set_property PACKAGE_PIN Y28 [get_ports GPIO_SWITCH]
set_property IOSTANDARD LVCMOS15 [get_ports {GPIO_BUTTONS[0]}]
set_property IOSTANDARD LVCMOS15 [get_ports {GPIO_BUTTONS[1]}]
set_property IOSTANDARD LVCMOS25 [get_ports GPIO_SWITCH]

set_property PACKAGE_PIN AB8 [get_ports {LEDS_n[0]}]
set_property PACKAGE_PIN AA8 [get_ports {LEDS_n[1]}]
set_property PACKAGE_PIN AC9 [get_ports {LEDS_n[2]}]
set_property PACKAGE_PIN AB9 [get_ports {LEDS_n[3]}]
set_property IOSTANDARD LVCMOS15 [get_ports {LEDS_n[0]}]
set_property IOSTANDARD LVCMOS15 [get_ports {LEDS_n[1]}]
set_property IOSTANDARD LVCMOS15 [get_ports {LEDS_n[2]}]
set_property IOSTANDARD LVCMOS15 [get_ports {LEDS_n[3]}]

set_input_delay 0.000 -clock [get_clocks {clk}] [get_ports GPIO_SWITCH]
set_input_delay 0.000 -clock [get_clocks {clk}] [get_ports {GPIO_BUTTONS[0]}]
set_input_delay 0.000 -clock [get_clocks {clk}] [get_ports {GPIO_BUTTONS[1]}]
set_output_delay -clock [get_clocks {clk}] -max -1.000 [get_ports {LEDS_n[*]}]
set_output_delay -clock [get_clocks {clk}]  -min -2.000 [get_ports {LEDS_n[*]}]
