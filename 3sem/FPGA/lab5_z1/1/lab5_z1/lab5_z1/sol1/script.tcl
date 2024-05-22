############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab5_z1
set_top foo_m
add_files ./source/lab5_z1.c
add_files -tb source/lab5_z1_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "sol1" -flow_target vivado
set_part {xa7a12t-csg325-1Q}
create_clock -period 6 -name clk
set_clock_uncertainty 1
source "./lab5_z1/sol1/directives.tcl"
csim_design -clean
csynth_design
cosim_design -trace_level port
export_design -format ip_catalog
