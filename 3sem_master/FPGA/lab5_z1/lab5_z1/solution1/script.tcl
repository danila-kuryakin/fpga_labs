############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab5_z1
add_files source/lab5_z1.c
add_files -tb source/lab5_z1_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7a12ti-csg325-1L}
create_clock -period 10 -name default
#source "./lab5_z1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
