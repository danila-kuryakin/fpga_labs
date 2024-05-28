# Perform Repetitive Trigger function using few Tcl commands
#
set ARM  15
for {set i 1} {$i <= $ARM} {incr i} {
  run_hw_ila hw_ila_1
  wait_on_hw_ila hw_ila_1
  display_hw_ila_data [upload_hw_ila_data hw_ila_1] 
  puts "ARM = $i" 
} 
puts "Source the RT.tcl again to re-arm and perform Repetitive Trigger"

