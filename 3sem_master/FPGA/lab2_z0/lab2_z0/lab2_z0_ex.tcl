open_project -reset lab2_z0_ex

add_files ./source/lab2_z0.c

set_top lab2_z0

add_files -tb ./source/lab2_z0_test.c

open_solution -reset "ex_sol1"

set_part {xa7a12tcsg325-1Q}

create_clock -period 5 -name clk
set_clock_uncertainty 1

csynth_design

csim_design -clean


set all_solutions {ex_sol2 ex_sol3 ex_sol4 ex_sol5 ex_sol6}
set all_period    {{6}     {7}     {8}     {9}     {10}}

foreach the_solution $all_solutions the_period $all_period {

	open_solution -reset $the_solution

	create_clock -period $the_period -name clk
	set_clock_uncertainty 1

	set_part {xa7a12tcsg325-1Q}

	csynth_design

	cosim_design -trace_level all -tool xsim
}