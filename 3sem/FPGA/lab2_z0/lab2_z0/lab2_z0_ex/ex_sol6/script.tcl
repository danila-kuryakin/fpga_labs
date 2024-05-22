############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab2_z0_ex
set_top lab2_z0
add_files ./source/lab2_z0.c
add_files -tb source/lab2_z0_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "ex_sol6" -flow_target vivado
set_part {xa7a12t-csg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1
source "./lab2_z0_ex/ex_sol6/directives.tcl"
csim_design -clean
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
