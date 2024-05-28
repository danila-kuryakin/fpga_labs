vsim -gui -l msim_transcript -L altera_mf_ver work.mips_8_v1
add wave -radix hexadecimal /mips_8_v1/clk
add wave -radix hexadecimal /mips_8_v1/cpu/need_jump
add wave -radix hexadecimal /mips_8_v1/cpu/flag_jamp
add wave -radix hexadecimal /mips_8_v1/cpu/address
add wave -radix hexadecimal /mips_8_v1/command

add wave -radix hexadecimal /mips_8_v1/cpu/rf_rden_1
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_addr_1
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_1
add wave -radix hexadecimal /mips_8_v1/cpu/rf_rden_2
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_addr_2
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_2

add wave -radix hexadecimal /mips_8_v1/cpu/rf_data_1
add wave -radix hexadecimal /mips_8_v1/cpu/rf_data_2
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_1_E
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_2_E

add wave -radix hexadecimal /mips_8_v1/cpu/alu_word 
add wave -radix hexadecimal /mips_8_v1/cpu/alu_result

add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_addr_1_D
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_addr_2_D

add wave -radix hexadecimal /mips_8_v1/cpu/rf_write
add wave -radix hexadecimal /mips_8_v1/cpu/rf_write_dest
add wave -radix hexadecimal /mips_8_v1/cpu/rf_write_data

add wave -radix hexadecimal /mips_8_v1/dm/rden
add wave -radix hexadecimal /mips_8_v1/dm/rdaddress
add wave -radix hexadecimal /mips_8_v1/dm/data

add wave -radix hexadecimal /mips_8_v1/dm/wren
add wave -radix hexadecimal /mips_8_v1/dm/wraddress
add wave -radix hexadecimal /mips_8_v1/dm/q

add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_1_E
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_1_M
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_1_W
add wave -radix hexadecimal /mips_8_v1/cpu/rf_read_data_2_E

add wave -radix hexadecimal /mips_8_v1/cpu/r_opcode_D 
add wave -radix hexadecimal /mips_8_v1/cpu/r_opcode_E 
add wave -radix hexadecimal /mips_8_v1/cpu/r_opcode_M 
add wave -radix hexadecimal /mips_8_v1/cpu/r_opcode_W

add wave -radix hexadecimal /mips_8_v1/cpu/num_command_I
add wave -radix hexadecimal /mips_8_v1/cpu/num_command_D 
add wave -radix hexadecimal /mips_8_v1/cpu/num_command_E 
add wave -radix hexadecimal /mips_8_v1/cpu/num_command_M 
add wave -radix hexadecimal /mips_8_v1/cpu/num_command_W
force -freeze /mips_8_v1/clk 1 0, 0 {20 ps} -r 40

view structure
view signals
run 3 ns
wave zoom full
