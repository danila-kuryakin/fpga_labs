############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab4_z1
set_top lab4_z1
add_files ./source/lab4_z1.c
add_files -tb source/lab4_z1_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "sol4" -flow_target vivado
set_part {xa7a12t-csg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1
source "./lab4_z1/sol4/directives.tcl"
csim_design -clean
csynth_design
cosim_design -trace_level port -tool xsim
export_design -format ip_catalog
