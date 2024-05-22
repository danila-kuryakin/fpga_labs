open_project -reset lab5_z1
add_files ./source/lab5_z1.c
set_top foo_m
add_files -tb ./source/lab5_z1_test.c

set all_solutions {sol1 sol2 sol3}
set all_period {{6} {10} {14}}

foreach the_solution $all_solutions the_period $all_period {
	open_solution -reset $the_solution
	
	create_clock -period $the_period -name clk
	set_clock_uncertainty 1
	
	set_part {xa7a12tcsg325-1Q}

	if {$the_solution == "sol1"} {
    	csim_design -clean
  	}
	
    csynth_design
	cosim_design -trace_level port -tool xsim
}