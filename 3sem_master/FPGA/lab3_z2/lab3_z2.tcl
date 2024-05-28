open_project -reset lab3_z2

add_files ./lab3_z2/source/lab3_z2.c

set_top lab3_z2

add_files -tb ./lab3_z2/source/lab3_z2_test.c

open_solution -reset "ex_sol1"

set_directive_top -name lab3_z2 "lab3_z2"
set_part {xa7a12tcsg325-1Q}
create_clock -period 8 -name clk
set_clock_uncertainty 1

csynth_design
csim_design -clean
cosim_design -trace_level all -tool xsim

open_solution -reset "ex_sol2"

set_directive_top -name lab3_z2 "lab3_z2"
set_directive_interface -mode ap_fifo "lab3_z2" in_Mass

set_part {xa7a12tcsg325-1Q}
create_clock -period 8 -name clk
set_clock_uncertainty 1

csynth_design
csim_design -clean
cosim_design -trace_level all -tool xsim

open_solution -reset "ex_sol3"

set_directive_top -name lab3_z2 "lab3_z2"
set_directive_pipeline -off "lab3_z2"
set_directive_interface -mode ap_fifo "lab3_z2" in_Mass

set_part {xa7a12tcsg325-1Q}
create_clock -period 8 -name clk
set_clock_uncertainty 1

csynth_design
csim_design -clean
cosim_design -trace_level all -tool xsim


