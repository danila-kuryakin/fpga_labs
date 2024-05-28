############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab4_z1
add_files source/lab4_z1.c
add_files -tb source/lab4_z1_test.c
open_solution "solution1" -flow_target vivado
set_part {xc7a12ticsg325-1L}
create_clock -period 10 -name default
#source "./lab4_z1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
