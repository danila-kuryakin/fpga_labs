-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity foo_m is
port (
    ap_local_block : OUT STD_LOGIC;
    ap_local_deadlock : OUT STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    data_in_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
    data_in_ce0 : OUT STD_LOGIC;
    data_in_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    data_in_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    data_in_we0 : OUT STD_LOGIC;
    data_in_address1 : OUT STD_LOGIC_VECTOR (13 downto 0);
    data_in_ce1 : OUT STD_LOGIC;
    data_in_d1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    data_in_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    data_in_we1 : OUT STD_LOGIC;
    scale : IN STD_LOGIC_VECTOR (31 downto 0);
    data_out1_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
    data_out1_ce0 : OUT STD_LOGIC;
    data_out1_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    data_out1_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    data_out1_we0 : OUT STD_LOGIC;
    data_out1_address1 : OUT STD_LOGIC_VECTOR (13 downto 0);
    data_out1_ce1 : OUT STD_LOGIC;
    data_out1_d1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    data_out1_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    data_out1_we1 : OUT STD_LOGIC;
    data_out2_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
    data_out2_ce0 : OUT STD_LOGIC;
    data_out2_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    data_out2_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    data_out2_we0 : OUT STD_LOGIC;
    data_out2_address1 : OUT STD_LOGIC_VECTOR (13 downto 0);
    data_out2_ce1 : OUT STD_LOGIC;
    data_out2_d1 : OUT STD_LOGIC_VECTOR (31 downto 0);
    data_out2_q1 : IN STD_LOGIC_VECTOR (31 downto 0);
    data_out2_we1 : OUT STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC );
end;


architecture behav of foo_m is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "foo_m_foo_m,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=dataflow,HLS_SYN_CLOCK=8.470000,HLS_SYN_LAT=163845,HLS_SYN_TPT=65538,HLS_SYN_MEM=192,HLS_SYN_DSP=0,HLS_SYN_FF=303,HLS_SYN_LUT=421,HLS_VERSION=2021_2}";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_lv14_0 : STD_LOGIC_VECTOR (13 downto 0) := "00000000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal temp1_i_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp1_t_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp2_i_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp2_t_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp3_i_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp3_t_q0 : STD_LOGIC_VECTOR (31 downto 0);
    signal Loop_Loop1_proc_U0_ap_start : STD_LOGIC;
    signal Loop_Loop1_proc_U0_ap_done : STD_LOGIC;
    signal Loop_Loop1_proc_U0_ap_continue : STD_LOGIC;
    signal Loop_Loop1_proc_U0_ap_idle : STD_LOGIC;
    signal Loop_Loop1_proc_U0_ap_ready : STD_LOGIC;
    signal Loop_Loop1_proc_U0_data_in_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal Loop_Loop1_proc_U0_data_in_ce0 : STD_LOGIC;
    signal Loop_Loop1_proc_U0_temp1_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal Loop_Loop1_proc_U0_temp1_ce0 : STD_LOGIC;
    signal Loop_Loop1_proc_U0_temp1_we0 : STD_LOGIC;
    signal Loop_Loop1_proc_U0_temp1_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal split_U0_ap_start : STD_LOGIC;
    signal split_U0_ap_done : STD_LOGIC;
    signal split_U0_ap_continue : STD_LOGIC;
    signal split_U0_ap_idle : STD_LOGIC;
    signal split_U0_ap_ready : STD_LOGIC;
    signal split_U0_in_r_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal split_U0_in_r_ce0 : STD_LOGIC;
    signal split_U0_out1_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal split_U0_out1_ce0 : STD_LOGIC;
    signal split_U0_out1_we0 : STD_LOGIC;
    signal split_U0_out1_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal split_U0_out2_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal split_U0_out2_ce0 : STD_LOGIC;
    signal split_U0_out2_we0 : STD_LOGIC;
    signal split_U0_out2_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_channel_done_temp3 : STD_LOGIC;
    signal split_U0_out2_full_n : STD_LOGIC;
    signal ap_sync_reg_channel_write_temp3 : STD_LOGIC := '0';
    signal ap_sync_channel_write_temp3 : STD_LOGIC;
    signal ap_channel_done_temp2 : STD_LOGIC;
    signal split_U0_out1_full_n : STD_LOGIC;
    signal ap_sync_reg_channel_write_temp2 : STD_LOGIC := '0';
    signal ap_sync_channel_write_temp2 : STD_LOGIC;
    signal Loop_Loop2_proc_U0_ap_start : STD_LOGIC;
    signal Loop_Loop2_proc_U0_ap_done : STD_LOGIC;
    signal Loop_Loop2_proc_U0_ap_continue : STD_LOGIC;
    signal Loop_Loop2_proc_U0_ap_idle : STD_LOGIC;
    signal Loop_Loop2_proc_U0_ap_ready : STD_LOGIC;
    signal Loop_Loop2_proc_U0_temp2_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal Loop_Loop2_proc_U0_temp2_ce0 : STD_LOGIC;
    signal Loop_Loop2_proc_U0_data_out1_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal Loop_Loop2_proc_U0_data_out1_ce0 : STD_LOGIC;
    signal Loop_Loop2_proc_U0_data_out1_we0 : STD_LOGIC;
    signal Loop_Loop2_proc_U0_data_out1_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal Loop_Loop3_proc_U0_ap_start : STD_LOGIC;
    signal Loop_Loop3_proc_U0_ap_done : STD_LOGIC;
    signal Loop_Loop3_proc_U0_ap_continue : STD_LOGIC;
    signal Loop_Loop3_proc_U0_ap_idle : STD_LOGIC;
    signal Loop_Loop3_proc_U0_ap_ready : STD_LOGIC;
    signal Loop_Loop3_proc_U0_temp3_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal Loop_Loop3_proc_U0_temp3_ce0 : STD_LOGIC;
    signal Loop_Loop3_proc_U0_data_out2_address0 : STD_LOGIC_VECTOR (13 downto 0);
    signal Loop_Loop3_proc_U0_data_out2_ce0 : STD_LOGIC;
    signal Loop_Loop3_proc_U0_data_out2_we0 : STD_LOGIC;
    signal Loop_Loop3_proc_U0_data_out2_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp1_i_full_n : STD_LOGIC;
    signal temp1_t_empty_n : STD_LOGIC;
    signal temp2_i_full_n : STD_LOGIC;
    signal temp2_t_empty_n : STD_LOGIC;
    signal temp3_i_full_n : STD_LOGIC;
    signal temp3_t_empty_n : STD_LOGIC;
    signal ap_sync_done : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component foo_m_Loop_Loop1_proc IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        data_in_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        data_in_ce0 : OUT STD_LOGIC;
        data_in_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        scale : IN STD_LOGIC_VECTOR (31 downto 0);
        temp1_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        temp1_ce0 : OUT STD_LOGIC;
        temp1_we0 : OUT STD_LOGIC;
        temp1_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component foo_m_split IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        in_r_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        in_r_ce0 : OUT STD_LOGIC;
        in_r_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        out1_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        out1_ce0 : OUT STD_LOGIC;
        out1_we0 : OUT STD_LOGIC;
        out1_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
        out2_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        out2_ce0 : OUT STD_LOGIC;
        out2_we0 : OUT STD_LOGIC;
        out2_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component foo_m_Loop_Loop2_proc IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        temp2_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        temp2_ce0 : OUT STD_LOGIC;
        temp2_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        data_out1_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        data_out1_ce0 : OUT STD_LOGIC;
        data_out1_we0 : OUT STD_LOGIC;
        data_out1_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component foo_m_Loop_Loop3_proc IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_continue : IN STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        temp3_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        temp3_ce0 : OUT STD_LOGIC;
        temp3_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
        data_out2_address0 : OUT STD_LOGIC_VECTOR (13 downto 0);
        data_out2_ce0 : OUT STD_LOGIC;
        data_out2_we0 : OUT STD_LOGIC;
        data_out2_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component foo_m_temp1_RAM_AUTO_1R1W IS
    generic (
        DataWidth : INTEGER;
        AddressRange : INTEGER;
        AddressWidth : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        i_address0 : IN STD_LOGIC_VECTOR (13 downto 0);
        i_ce0 : IN STD_LOGIC;
        i_we0 : IN STD_LOGIC;
        i_d0 : IN STD_LOGIC_VECTOR (31 downto 0);
        i_q0 : OUT STD_LOGIC_VECTOR (31 downto 0);
        t_address0 : IN STD_LOGIC_VECTOR (13 downto 0);
        t_ce0 : IN STD_LOGIC;
        t_we0 : IN STD_LOGIC;
        t_d0 : IN STD_LOGIC_VECTOR (31 downto 0);
        t_q0 : OUT STD_LOGIC_VECTOR (31 downto 0);
        i_ce : IN STD_LOGIC;
        t_ce : IN STD_LOGIC;
        i_full_n : OUT STD_LOGIC;
        i_write : IN STD_LOGIC;
        t_empty_n : OUT STD_LOGIC;
        t_read : IN STD_LOGIC );
    end component;



begin
    temp1_U : component foo_m_temp1_RAM_AUTO_1R1W
    generic map (
        DataWidth => 32,
        AddressRange => 16384,
        AddressWidth => 14)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        i_address0 => Loop_Loop1_proc_U0_temp1_address0,
        i_ce0 => Loop_Loop1_proc_U0_temp1_ce0,
        i_we0 => Loop_Loop1_proc_U0_temp1_we0,
        i_d0 => Loop_Loop1_proc_U0_temp1_d0,
        i_q0 => temp1_i_q0,
        t_address0 => split_U0_in_r_address0,
        t_ce0 => split_U0_in_r_ce0,
        t_we0 => ap_const_logic_0,
        t_d0 => ap_const_lv32_0,
        t_q0 => temp1_t_q0,
        i_ce => ap_const_logic_1,
        t_ce => ap_const_logic_1,
        i_full_n => temp1_i_full_n,
        i_write => Loop_Loop1_proc_U0_ap_done,
        t_empty_n => temp1_t_empty_n,
        t_read => split_U0_ap_ready);

    temp2_U : component foo_m_temp1_RAM_AUTO_1R1W
    generic map (
        DataWidth => 32,
        AddressRange => 16384,
        AddressWidth => 14)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        i_address0 => split_U0_out1_address0,
        i_ce0 => split_U0_out1_ce0,
        i_we0 => split_U0_out1_we0,
        i_d0 => split_U0_out1_d0,
        i_q0 => temp2_i_q0,
        t_address0 => Loop_Loop2_proc_U0_temp2_address0,
        t_ce0 => Loop_Loop2_proc_U0_temp2_ce0,
        t_we0 => ap_const_logic_0,
        t_d0 => ap_const_lv32_0,
        t_q0 => temp2_t_q0,
        i_ce => ap_const_logic_1,
        t_ce => ap_const_logic_1,
        i_full_n => temp2_i_full_n,
        i_write => ap_channel_done_temp2,
        t_empty_n => temp2_t_empty_n,
        t_read => Loop_Loop2_proc_U0_ap_ready);

    temp3_U : component foo_m_temp1_RAM_AUTO_1R1W
    generic map (
        DataWidth => 32,
        AddressRange => 16384,
        AddressWidth => 14)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        i_address0 => split_U0_out2_address0,
        i_ce0 => split_U0_out2_ce0,
        i_we0 => split_U0_out2_we0,
        i_d0 => split_U0_out2_d0,
        i_q0 => temp3_i_q0,
        t_address0 => Loop_Loop3_proc_U0_temp3_address0,
        t_ce0 => Loop_Loop3_proc_U0_temp3_ce0,
        t_we0 => ap_const_logic_0,
        t_d0 => ap_const_lv32_0,
        t_q0 => temp3_t_q0,
        i_ce => ap_const_logic_1,
        t_ce => ap_const_logic_1,
        i_full_n => temp3_i_full_n,
        i_write => ap_channel_done_temp3,
        t_empty_n => temp3_t_empty_n,
        t_read => Loop_Loop3_proc_U0_ap_ready);

    Loop_Loop1_proc_U0 : component foo_m_Loop_Loop1_proc
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => Loop_Loop1_proc_U0_ap_start,
        ap_done => Loop_Loop1_proc_U0_ap_done,
        ap_continue => Loop_Loop1_proc_U0_ap_continue,
        ap_idle => Loop_Loop1_proc_U0_ap_idle,
        ap_ready => Loop_Loop1_proc_U0_ap_ready,
        data_in_address0 => Loop_Loop1_proc_U0_data_in_address0,
        data_in_ce0 => Loop_Loop1_proc_U0_data_in_ce0,
        data_in_q0 => data_in_q0,
        scale => scale,
        temp1_address0 => Loop_Loop1_proc_U0_temp1_address0,
        temp1_ce0 => Loop_Loop1_proc_U0_temp1_ce0,
        temp1_we0 => Loop_Loop1_proc_U0_temp1_we0,
        temp1_d0 => Loop_Loop1_proc_U0_temp1_d0);

    split_U0 : component foo_m_split
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => split_U0_ap_start,
        ap_done => split_U0_ap_done,
        ap_continue => split_U0_ap_continue,
        ap_idle => split_U0_ap_idle,
        ap_ready => split_U0_ap_ready,
        in_r_address0 => split_U0_in_r_address0,
        in_r_ce0 => split_U0_in_r_ce0,
        in_r_q0 => temp1_t_q0,
        out1_address0 => split_U0_out1_address0,
        out1_ce0 => split_U0_out1_ce0,
        out1_we0 => split_U0_out1_we0,
        out1_d0 => split_U0_out1_d0,
        out2_address0 => split_U0_out2_address0,
        out2_ce0 => split_U0_out2_ce0,
        out2_we0 => split_U0_out2_we0,
        out2_d0 => split_U0_out2_d0);

    Loop_Loop2_proc_U0 : component foo_m_Loop_Loop2_proc
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => Loop_Loop2_proc_U0_ap_start,
        ap_done => Loop_Loop2_proc_U0_ap_done,
        ap_continue => Loop_Loop2_proc_U0_ap_continue,
        ap_idle => Loop_Loop2_proc_U0_ap_idle,
        ap_ready => Loop_Loop2_proc_U0_ap_ready,
        temp2_address0 => Loop_Loop2_proc_U0_temp2_address0,
        temp2_ce0 => Loop_Loop2_proc_U0_temp2_ce0,
        temp2_q0 => temp2_t_q0,
        data_out1_address0 => Loop_Loop2_proc_U0_data_out1_address0,
        data_out1_ce0 => Loop_Loop2_proc_U0_data_out1_ce0,
        data_out1_we0 => Loop_Loop2_proc_U0_data_out1_we0,
        data_out1_d0 => Loop_Loop2_proc_U0_data_out1_d0);

    Loop_Loop3_proc_U0 : component foo_m_Loop_Loop3_proc
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => Loop_Loop3_proc_U0_ap_start,
        ap_done => Loop_Loop3_proc_U0_ap_done,
        ap_continue => Loop_Loop3_proc_U0_ap_continue,
        ap_idle => Loop_Loop3_proc_U0_ap_idle,
        ap_ready => Loop_Loop3_proc_U0_ap_ready,
        temp3_address0 => Loop_Loop3_proc_U0_temp3_address0,
        temp3_ce0 => Loop_Loop3_proc_U0_temp3_ce0,
        temp3_q0 => temp3_t_q0,
        data_out2_address0 => Loop_Loop3_proc_U0_data_out2_address0,
        data_out2_ce0 => Loop_Loop3_proc_U0_data_out2_ce0,
        data_out2_we0 => Loop_Loop3_proc_U0_data_out2_we0,
        data_out2_d0 => Loop_Loop3_proc_U0_data_out2_d0);





    ap_sync_reg_channel_write_temp2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_sync_reg_channel_write_temp2 <= ap_const_logic_0;
            else
                if (((split_U0_ap_done and split_U0_ap_continue) = ap_const_logic_1)) then 
                    ap_sync_reg_channel_write_temp2 <= ap_const_logic_0;
                else 
                    ap_sync_reg_channel_write_temp2 <= ap_sync_channel_write_temp2;
                end if; 
            end if;
        end if;
    end process;


    ap_sync_reg_channel_write_temp3_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_sync_reg_channel_write_temp3 <= ap_const_logic_0;
            else
                if (((split_U0_ap_done and split_U0_ap_continue) = ap_const_logic_1)) then 
                    ap_sync_reg_channel_write_temp3 <= ap_const_logic_0;
                else 
                    ap_sync_reg_channel_write_temp3 <= ap_sync_channel_write_temp3;
                end if; 
            end if;
        end if;
    end process;

    Loop_Loop1_proc_U0_ap_continue <= temp1_i_full_n;
    Loop_Loop1_proc_U0_ap_start <= ap_start;
    Loop_Loop2_proc_U0_ap_continue <= ap_sync_done;
    Loop_Loop2_proc_U0_ap_start <= temp2_t_empty_n;
    Loop_Loop3_proc_U0_ap_continue <= ap_sync_done;
    Loop_Loop3_proc_U0_ap_start <= temp3_t_empty_n;
    ap_channel_done_temp2 <= (split_U0_ap_done and (ap_sync_reg_channel_write_temp2 xor ap_const_logic_1));
    ap_channel_done_temp3 <= (split_U0_ap_done and (ap_sync_reg_channel_write_temp3 xor ap_const_logic_1));
    ap_done <= ap_sync_done;
    ap_idle <= (split_U0_ap_idle and (temp3_t_empty_n xor ap_const_logic_1) and (temp2_t_empty_n xor ap_const_logic_1) and (temp1_t_empty_n xor ap_const_logic_1) and Loop_Loop3_proc_U0_ap_idle and Loop_Loop2_proc_U0_ap_idle and Loop_Loop1_proc_U0_ap_idle);
    ap_local_block <= ap_const_logic_0;
    ap_local_deadlock <= ap_const_logic_0;
    ap_ready <= Loop_Loop1_proc_U0_ap_ready;
    ap_sync_channel_write_temp2 <= ((split_U0_out1_full_n and ap_channel_done_temp2) or ap_sync_reg_channel_write_temp2);
    ap_sync_channel_write_temp3 <= ((split_U0_out2_full_n and ap_channel_done_temp3) or ap_sync_reg_channel_write_temp3);
    ap_sync_done <= (Loop_Loop3_proc_U0_ap_done and Loop_Loop2_proc_U0_ap_done);
    data_in_address0 <= Loop_Loop1_proc_U0_data_in_address0;
    data_in_address1 <= ap_const_lv14_0;
    data_in_ce0 <= Loop_Loop1_proc_U0_data_in_ce0;
    data_in_ce1 <= ap_const_logic_0;
    data_in_d0 <= ap_const_lv32_0;
    data_in_d1 <= ap_const_lv32_0;
    data_in_we0 <= ap_const_logic_0;
    data_in_we1 <= ap_const_logic_0;
    data_out1_address0 <= Loop_Loop2_proc_U0_data_out1_address0;
    data_out1_address1 <= ap_const_lv14_0;
    data_out1_ce0 <= Loop_Loop2_proc_U0_data_out1_ce0;
    data_out1_ce1 <= ap_const_logic_0;
    data_out1_d0 <= Loop_Loop2_proc_U0_data_out1_d0;
    data_out1_d1 <= ap_const_lv32_0;
    data_out1_we0 <= Loop_Loop2_proc_U0_data_out1_we0;
    data_out1_we1 <= ap_const_logic_0;
    data_out2_address0 <= Loop_Loop3_proc_U0_data_out2_address0;
    data_out2_address1 <= ap_const_lv14_0;
    data_out2_ce0 <= Loop_Loop3_proc_U0_data_out2_ce0;
    data_out2_ce1 <= ap_const_logic_0;
    data_out2_d0 <= Loop_Loop3_proc_U0_data_out2_d0;
    data_out2_d1 <= ap_const_lv32_0;
    data_out2_we0 <= Loop_Loop3_proc_U0_data_out2_we0;
    data_out2_we1 <= ap_const_logic_0;
    split_U0_ap_continue <= (ap_sync_channel_write_temp3 and ap_sync_channel_write_temp2);
    split_U0_ap_start <= temp1_t_empty_n;
    split_U0_out1_full_n <= temp2_i_full_n;
    split_U0_out2_full_n <= temp3_i_full_n;
end behav;
