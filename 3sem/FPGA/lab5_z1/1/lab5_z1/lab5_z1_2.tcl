open_project -reset lab5_z1
add_files ./source/lab5_z1.c
set_top foo_m
add_files -tb ./source/lab5_z1_test.c

open_solution -reset "sol4_fifo"

set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1

config_dataflow -default_channel fifo
set_directive_dataflow "foo_m"

csynth_design
cosim_design -trace_level port -tool xsim


open_solution -reset "sol5_pingpong"

set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1

config_dataflow -default_channel pingpong
set_directive_dataflow "foo_m"

csynth_design
cosim_design -trace_level port -tool xsim