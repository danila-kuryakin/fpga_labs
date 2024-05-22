############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab2_z0
add_files lab2_z0/source/lab2_z0.c
add_files -tb lab2_z0/source/lab2_z0_test.c
open_solution "solution1" -flow_target vivado
set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name default
#source "./lab2_z0/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
