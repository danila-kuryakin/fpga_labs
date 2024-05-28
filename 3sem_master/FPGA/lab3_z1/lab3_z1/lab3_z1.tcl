open_project -reset lab3_z1

add_files ./source/lab3_z1.c

set_top lab3_z1

add_files -tb ./source/lab3_z1_test.c

open_solution -reset "ex_sol1"

set_part {xa7a12tcsg325-1Q}

create_clock -period 8 -name clk
set_clock_uncertainty 1

csynth_design

cosim_design -trace_level all -tool xsim

open_solution -reset "ex_sol2"

set_directive_interface -mode ap_hs "lab3_z1" res
set_directive_interface -mode ap_hs "lab3_z1" inB
set_directive_interface -mode ap_hs "lab3_z1" inA
set_directive_interface -mode ap_hs "lab3_z1" inC
set_directive_interface -mode ap_ctrl_chain "lab3_z1"

create_clock -period 8 -name clk
set_clock_uncertainty 1

set_part {xa7a12tcsg325-1Q}

csynth_design

cosim_design -trace_level all -tool xsim


