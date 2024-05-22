open_project -reset lab2_z0

add_files ./source/lab2_z0.c

set_top lab2_z0

add_files -tb ./source/lab2_z0_test.c

open_solution -reset "solution1"

set_part {xa7a12tcsg325-1Q}

create_clock -period 6 -name clk
set_clock_uncertainty 1

csim_design -clean

csynth_design

cosim_design -trace_level all -tool xsim