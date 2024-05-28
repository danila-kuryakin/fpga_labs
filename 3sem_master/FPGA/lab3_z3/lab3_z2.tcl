open_project -reset lab3_z2
add_files ./source/lab3_z2.c
set_top lab3_z2
add_files -tb ./source/lab3_z2_test.c

open_solution -reset sol1

create_clock -period 8 -name clk
set_clock_uncertainty 1
set_part {xa7a12tcsg325-1Q}

set_directive_interface -mode ap_fifo lab3_z2 inA_ar

csim_design -clean
csynth_design
cosim_design -trace_level all -tool xsim