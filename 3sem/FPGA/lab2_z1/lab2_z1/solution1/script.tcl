############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab2_z1
set_top lab2_z1
add_files lab2_z1/source/lab2_z1.c
add_files -tb lab2_z1/source/lab2_z1_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xa7a12t-csg325-1Q}
create_clock -period 5 -name default
set_clock_uncertainty 1
source "./lab2_z1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
