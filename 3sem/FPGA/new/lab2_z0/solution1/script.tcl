############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab2_z0
set_top lab2_z0
add_files lab2_z0/source/lab2_z0.c
add_files -tb lab2_z0/source/lab2_z0_test.c
open_solution "solution1" -flow_target vivado
set_part {xc7a12ticsg325-1L}
create_clock -period 6 -name default
set_clock_uncertainty 1
#source "./lab2_z0/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
