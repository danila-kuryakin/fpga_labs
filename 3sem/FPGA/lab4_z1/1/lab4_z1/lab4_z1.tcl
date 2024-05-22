open_project -reset lab4_z1
add_files ./source/lab4_z1.c
set_top lab4_z1
add_files -tb ./source/lab4_z1_test.c


open_solution -reset "solution1"
set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1

set_directive_pipeline -off "lab4_z1/L2"
set_directive_pipeline -off "lab4_z1/L1"

csim_design -clean
csynth_design
cosim_design -trace_level port -tool xsim


open_solution -reset "solution2"
set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1

set_directive_pipeline -II 1 "lab4_z1/L1"
set_directive_pipeline -off "lab4_z1/L2"

csim_design -clean
csynth_design
cosim_design -trace_level port -tool xsim


open_solution -reset "solution3"
set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1

set_directive_pipeline -II 1 "lab4_z1/L1"
set_directive_pipeline -off -rewind "lab4_z1/L2"

csim_design -clean
csynth_design
cosim_design -trace_level port -tool xsim


open_solution -reset "solution4"
set_part {xa7a12tcsg325-1Q}
create_clock -period 10 -name clk
set_clock_uncertainty 1

set_directive_pipeline -off "lab4_z1/L1"
set_directive_pipeline -II 1 -rewind "lab4_z1/L2"

csim_design -clean
csynth_design
cosim_design -trace_level port -tool xsim