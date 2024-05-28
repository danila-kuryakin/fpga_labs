############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab1_z1
set_top lab1_z1
add_files source/lab1_z1.c
add_files -tb source/lab1_z1_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution2" -flow_target vivado
set_part {xa7a12t-csg325-1Q}
create_clock -period 10 -name default
set_clock_uncertainty 1
source "./lab1_z1/solution2/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog
