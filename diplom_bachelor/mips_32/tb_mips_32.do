vsim -gui -l msim_transcript -L altera_mf_ver work.mips_32
add wave -radix hexadecimal /mips_32/cpu/r_opcode_D
add wave -radix hexadecimal /mips_32/cpu/r_opcode_E
add wave -radix hexadecimal /mips_32/cpu/r_opcode_M
add wave -radix hexadecimal /mips_32/cpu/r_opcode_W

add wave -radix hexadecimal /mips_32/clk
add wave -radix hexadecimal /mips_32/cpu/need_jump
add wave -radix hexadecimal /mips_32/cpu/flag_jamp
add wave -radix hexadecimal /mips_32/cpu/address
add wave -radix hexadecimal /mips_32/command

add wave -radix hexadecimal /mips_32/cpu/rf_rden_1
add wave -radix hexadecimal /mips_32/cpu/rf_read_addr_1
add wave -radix hexadecimal /mips_32/cpu/rf_read_data_1
add wave -radix hexadecimal /mips_32/cpu/rf_rden_2
add wave -radix hexadecimal /mips_32/cpu/rf_read_addr_2
add wave -radix hexadecimal /mips_32/cpu/rf_read_data_2

add wave -radix hexadecimal /mips_32/cpu/rf_data_1
add wave -radix hexadecimal /mips_32/cpu/rf_data_2
add wave -radix hexadecimal /mips_32/cpu/rf_read_data_1_E
add wave -radix hexadecimal /mips_32/cpu/rf_read_data_2_E

add wave -radix hexadecimal /mips_32/cpu/alu_word 
add wave -radix hexadecimal /mips_32/cpu/alu_result

add wave -radix hexadecimal /mips_32/cpu/rf_read_addr_1_D
add wave -radix hexadecimal /mips_32/cpu/rf_read_addr_2_D

add wave -radix hexadecimal /mips_32/cpu/rf_write
add wave -radix hexadecimal /mips_32/cpu/rf_write_dest
add wave -radix hexadecimal /mips_32/cpu/rf_write_data

add wave -radix hexadecimal /mips_32/dm/wren
add wave -radix hexadecimal /mips_32/dm/wraddress
add wave -radix hexadecimal /mips_32/dm/data

add wave -radix hexadecimal /mips_32/dm/rden
add wave -radix hexadecimal /mips_32/dm/rdaddress
add wave -radix hexadecimal /mips_32/dm/q

add wave -radix hexadecimal /mips_32/cpu/reg_write_data_dm_M
add wave -radix hexadecimal /mips_32/cpu/reg_write_data_dm_W

add wave -radix hexadecimal /mips_32/cpu/retunt_data_W_1
add wave -radix hexadecimal /mips_32/cpu/retunt_data_W_2
add wave -radix hexadecimal /mips_32/cpu/retunt_data_M_1
add wave -radix hexadecimal /mips_32/cpu/retunt_data_M_2
force -freeze /mips_32/clk 1 0, 0 {20 ps} -r 40

view structure
view signals
run 11 ns
wave zoom full
