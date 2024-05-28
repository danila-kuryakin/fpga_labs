transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/reg_file_ram.v}
vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/mips_8_v1.v}
vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/inctructions.v}
vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/data.v}
vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/cpu.v}
vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/port_ram1.v}

vlog -vlog01compat -work work +incdir+D:/QuartusProject/mips_32/mips_32 {D:/QuartusProject/mips_32/mips_32/tb_ram_file.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  tb_ram_file

do D:/QuartusProject/mips_32/mips_32/tb_mips_8.do
