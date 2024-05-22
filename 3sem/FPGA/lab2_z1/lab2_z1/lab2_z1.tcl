open_project -reset lab2_z1

add_files ./source/lab2_z1.c

set_top lab2_z1

add_files -tb ./source/lab2_z1_test.c

open_solution -reset "ex_sol1"

set_part {xa7a12tcsg325-1Q}

create_clock -period 4 -name clk
set_clock_uncertainty 1

csynth_design

csim_design -clean


set all_solutions {ex_sol2 ex_sol3 ex_sol4}
set all_period    {{8}     {12}     {40}}

foreach the_solution $all_solutions the_period $all_period {

	open_solution -reset $the_solution

	create_clock -period $the_period -name clk
	set_clock_uncertainty 1

	set_part {xa7a12tcsg325-1Q}

	csynth_design

	cosim_design -trace_level all -tool xsim
}