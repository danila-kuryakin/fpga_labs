-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity lab4_z1 is
port (
    ap_local_block : OUT STD_LOGIC;
    ap_local_deadlock : OUT STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    firstVector_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    firstVector_arr_ce0 : OUT STD_LOGIC;
    firstVector_arr_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    firstVector_arr_address1 : OUT STD_LOGIC_VECTOR (1 downto 0);
    firstVector_arr_ce1 : OUT STD_LOGIC;
    firstVector_arr_q1 : IN STD_LOGIC_VECTOR (15 downto 0);
    secondVector_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    secondVector_arr_ce0 : OUT STD_LOGIC;
    secondVector_arr_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    resultVecror_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    resultVecror_arr_ce0 : OUT STD_LOGIC;
    resultVecror_arr_we0 : OUT STD_LOGIC;
    resultVecror_arr_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    resultVecror_arr_address1 : OUT STD_LOGIC_VECTOR (1 downto 0);
    resultVecror_arr_ce1 : OUT STD_LOGIC;
    resultVecror_arr_q1 : IN STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of lab4_z1 is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "lab4_z1_lab4_z1,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.080750,HLS_SYN_LAT=12,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=391,HLS_SYN_LUT=269,HLS_VERSION=2021_2}";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_ST_fsm_pp0_stage0 : STD_LOGIC_VECTOR (2 downto 0) := "010";
    constant ap_ST_fsm_pp0_stage1 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_boolean_0 : BOOLEAN := false;
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv64_1 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000001";
    constant ap_const_lv64_2 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000010";
    constant ap_const_lv64_3 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000011";
    constant ap_const_lv2_3 : STD_LOGIC_VECTOR (1 downto 0) := "11";
    constant ap_const_lv2_1 : STD_LOGIC_VECTOR (1 downto 0) := "01";

    signal ap_CS_fsm : STD_LOGIC_VECTOR (2 downto 0) := "001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal icmp_ln8_reg_356 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_pp0_stage1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage1 : signal is "none";
    signal ap_enable_reg_pp0_iter0 : STD_LOGIC;
    signal ap_block_state3_pp0_stage1_iter0 : BOOLEAN;
    signal ap_block_state5_pp0_stage1_iter1 : BOOLEAN;
    signal ap_block_state7_pp0_stage1_iter2 : BOOLEAN;
    signal ap_block_pp0_stage1_11001 : BOOLEAN;
    signal do_init_reg_129 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_CS_fsm_pp0_stage0 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_pp0_stage0 : signal is "none";
    signal ap_block_state2_pp0_stage0_iter0 : BOOLEAN;
    signal ap_block_state4_pp0_stage0_iter1 : BOOLEAN;
    signal ap_block_state6_pp0_stage0_iter2 : BOOLEAN;
    signal ap_block_state8_pp0_stage0_iter3 : BOOLEAN;
    signal ap_block_pp0_stage0_11001 : BOOLEAN;
    signal i1_reg_145 : STD_LOGIC_VECTOR (1 downto 0);
    signal sext_ln8_phi_reg_220 : STD_LOGIC_VECTOR (16 downto 0);
    signal firstVector_arr_load_2_cast_phi_reg_232 : STD_LOGIC_VECTOR (16 downto 0);
    signal firstVector_arr_load_1_cast_phi_reg_244 : STD_LOGIC_VECTOR (16 downto 0);
    signal firstVector_arr_load_cast_phi_reg_256 : STD_LOGIC_VECTOR (16 downto 0);
    signal resultVecror_arr_addr_reg_350 : STD_LOGIC_VECTOR (1 downto 0);
    signal resultVecror_arr_addr_reg_350_pp0_iter1_reg : STD_LOGIC_VECTOR (1 downto 0);
    signal resultVecror_arr_addr_reg_350_pp0_iter2_reg : STD_LOGIC_VECTOR (1 downto 0);
    signal icmp_ln8_fu_274_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln8_reg_356_pp0_iter1_reg : STD_LOGIC_VECTOR (0 downto 0);
    signal icmp_ln8_reg_356_pp0_iter2_reg : STD_LOGIC_VECTOR (0 downto 0);
    signal firstVector_arr_load_reg_360 : STD_LOGIC_VECTOR (15 downto 0);
    signal firstVector_arr_load_1_reg_365 : STD_LOGIC_VECTOR (15 downto 0);
    signal secondVector_arr_load_reg_380 : STD_LOGIC_VECTOR (15 downto 0);
    signal resultVecror_arr_load_reg_385 : STD_LOGIC_VECTOR (31 downto 0);
    signal resultVecror_arr_load_reg_385_pp0_iter1_reg : STD_LOGIC_VECTOR (31 downto 0);
    signal i_fu_280_p2 : STD_LOGIC_VECTOR (1 downto 0);
    signal i_reg_390 : STD_LOGIC_VECTOR (1 downto 0);
    signal firstVector_arr_load_cast_fu_286_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal firstVector_arr_load_1_cast_fu_289_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal firstVector_arr_load_2_cast_fu_292_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal sext_ln8_fu_296_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_enable_reg_pp0_iter0_reg : STD_LOGIC := '0';
    signal ap_enable_reg_pp0_iter1 : STD_LOGIC := '0';
    signal ap_block_pp0_stage1_subdone : BOOLEAN;
    signal ap_block_pp0_stage0_subdone : BOOLEAN;
    signal ap_enable_reg_pp0_iter2 : STD_LOGIC := '0';
    signal ap_enable_reg_pp0_iter3 : STD_LOGIC := '0';
    signal ap_block_pp0_stage0 : BOOLEAN;
    signal ap_phi_mux_i1_phi_fu_149_p6 : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_phi_reg_pp0_iter0_sext_ln8_phi_reg_220 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter0_firstVector_arr_load_2_cast_phi_reg_232 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter0_firstVector_arr_load_1_cast_phi_reg_244 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter0_firstVector_arr_load_cast_phi_reg_256 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256 : STD_LOGIC_VECTOR (16 downto 0);
    signal zext_ln8_fu_268_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_block_pp0_stage1 : BOOLEAN;
    signal grp_fu_325_p4 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp4_fu_303_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal tmp5_fu_313_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal grp_fu_325_ce : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_idle_pp0_0to2 : STD_LOGIC;
    signal ap_reset_idle_pp0 : STD_LOGIC;
    signal ap_idle_pp0 : STD_LOGIC;
    signal ap_enable_pp0 : STD_LOGIC;
    signal ap_condition_180 : BOOLEAN;
    signal ap_ce_reg : STD_LOGIC;

    component lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        din2_WIDTH : INTEGER;
        din3_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (16 downto 0);
        din1 : IN STD_LOGIC_VECTOR (16 downto 0);
        din2 : IN STD_LOGIC_VECTOR (15 downto 0);
        din3 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    ama_addmuladd_17s_17s_16s_32ns_32_4_1_U1 : component lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 17,
        din1_WIDTH => 17,
        din2_WIDTH => 16,
        din3_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => tmp5_fu_313_p2,
        din1 => tmp4_fu_303_p2,
        din2 => secondVector_arr_load_reg_380,
        din3 => resultVecror_arr_load_reg_385_pp0_iter1_reg,
        ce => grp_fu_325_ce,
        dout => grp_fu_325_p4);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter0_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter0_reg <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_CS_fsm_pp0_stage0)) then 
                    ap_enable_reg_pp0_iter0_reg <= ap_start;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter1_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter1 <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_subdone))) then 
                    ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter2_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter2 <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_subdone))) then 
                    ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
                end if; 
            end if;
        end if;
    end process;


    ap_enable_reg_pp0_iter3_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_enable_reg_pp0_iter3 <= ap_const_logic_0;
            else
                if ((((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_enable_reg_pp0_iter2 = ap_const_logic_0)) or ((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_subdone)))) then 
                    ap_enable_reg_pp0_iter3 <= ap_enable_reg_pp0_iter2;
                elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                    ap_enable_reg_pp0_iter3 <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((do_init_reg_129 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244 <= firstVector_arr_load_1_cast_phi_reg_244;
            elsif (((do_init_reg_129 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244 <= firstVector_arr_load_1_cast_fu_289_p1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244 <= ap_phi_reg_pp0_iter0_firstVector_arr_load_1_cast_phi_reg_244;
            end if; 
        end if;
    end process;

    ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((do_init_reg_129 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232 <= firstVector_arr_load_2_cast_phi_reg_232;
            elsif (((do_init_reg_129 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232 <= firstVector_arr_load_2_cast_fu_292_p1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232 <= ap_phi_reg_pp0_iter0_firstVector_arr_load_2_cast_phi_reg_232;
            end if; 
        end if;
    end process;

    ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((do_init_reg_129 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256 <= firstVector_arr_load_cast_phi_reg_256;
            elsif (((do_init_reg_129 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256 <= firstVector_arr_load_cast_fu_286_p1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256 <= ap_phi_reg_pp0_iter0_firstVector_arr_load_cast_phi_reg_256;
            end if; 
        end if;
    end process;

    ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((do_init_reg_129 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220 <= sext_ln8_phi_reg_220;
            elsif (((do_init_reg_129 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220 <= sext_ln8_fu_296_p1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
                ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220 <= ap_phi_reg_pp0_iter0_sext_ln8_phi_reg_220;
            end if; 
        end if;
    end process;

    do_init_reg_129_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln8_reg_356 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                do_init_reg_129 <= ap_const_lv1_0;
            elsif ((((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln8_reg_356 = ap_const_lv1_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1)) or ((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1)))) then 
                do_init_reg_129 <= ap_const_lv1_1;
            end if; 
        end if;
    end process;

    i1_reg_145_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln8_reg_356 = ap_const_lv1_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then 
                i1_reg_145 <= i_reg_390;
            elsif ((((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (icmp_ln8_reg_356 = ap_const_lv1_1) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1)) or ((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1)))) then 
                i1_reg_145 <= ap_const_lv2_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1))) then
                firstVector_arr_load_1_cast_phi_reg_244 <= ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244;
                firstVector_arr_load_2_cast_phi_reg_232 <= ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232;
                firstVector_arr_load_cast_phi_reg_256 <= ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256;
                sext_ln8_phi_reg_220 <= ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((do_init_reg_129 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then
                firstVector_arr_load_1_reg_365 <= firstVector_arr_q0;
                firstVector_arr_load_reg_360 <= firstVector_arr_q1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then
                i_reg_390 <= i_fu_280_p2;
                resultVecror_arr_load_reg_385 <= resultVecror_arr_q1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001))) then
                icmp_ln8_reg_356 <= icmp_ln8_fu_274_p2;
                icmp_ln8_reg_356_pp0_iter1_reg <= icmp_ln8_reg_356;
                icmp_ln8_reg_356_pp0_iter2_reg <= icmp_ln8_reg_356_pp0_iter1_reg;
                resultVecror_arr_addr_reg_350 <= zext_ln8_fu_268_p1(2 - 1 downto 0);
                resultVecror_arr_addr_reg_350_pp0_iter1_reg <= resultVecror_arr_addr_reg_350;
                resultVecror_arr_addr_reg_350_pp0_iter2_reg <= resultVecror_arr_addr_reg_350_pp0_iter1_reg;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001))) then
                resultVecror_arr_load_reg_385_pp0_iter1_reg <= resultVecror_arr_load_reg_385;
                secondVector_arr_load_reg_380 <= secondVector_arr_q0;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_block_pp0_stage1_subdone, ap_block_pp0_stage0_subdone, ap_reset_idle_pp0)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_pp0_stage0 => 
                if (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_reset_idle_pp0 = ap_const_logic_0))) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage1;
                elsif (((ap_const_boolean_0 = ap_block_pp0_stage0_subdone) and (ap_reset_idle_pp0 = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                end if;
            when ap_ST_fsm_pp0_stage1 => 
                if ((ap_const_boolean_0 = ap_block_pp0_stage1_subdone)) then
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage0;
                else
                    ap_NS_fsm <= ap_ST_fsm_pp0_stage1;
                end if;
            when others =>  
                ap_NS_fsm <= "XXX";
        end case;
    end process;
    ap_CS_fsm_pp0_stage0 <= ap_CS_fsm(1);
    ap_CS_fsm_pp0_stage1 <= ap_CS_fsm(2);
    ap_CS_fsm_state1 <= ap_CS_fsm(0);

    ap_ST_fsm_state1_blk_assign_proc : process(ap_start)
    begin
        if ((ap_start = ap_const_logic_0)) then 
            ap_ST_fsm_state1_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state1_blk <= ap_const_logic_0;
        end if; 
    end process;

        ap_block_pp0_stage0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage0_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage1_11001 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_pp0_stage1_subdone <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state2_pp0_stage0_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state3_pp0_stage1_iter0 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state4_pp0_stage0_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state5_pp0_stage1_iter1 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state6_pp0_stage0_iter2 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state7_pp0_stage1_iter2 <= not((ap_const_boolean_1 = ap_const_boolean_1));
        ap_block_state8_pp0_stage0_iter3 <= not((ap_const_boolean_1 = ap_const_boolean_1));

    ap_condition_180_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter1, ap_block_pp0_stage0)
    begin
                ap_condition_180 <= ((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_1));
    end process;


    ap_done_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001, icmp_ln8_reg_356_pp0_iter2_reg, ap_enable_reg_pp0_iter3)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter3 = ap_const_logic_1) and (icmp_ln8_reg_356_pp0_iter2_reg = ap_const_lv1_1))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;

    ap_enable_pp0 <= (ap_idle_pp0 xor ap_const_logic_1);

    ap_enable_reg_pp0_iter0_assign_proc : process(ap_start, ap_CS_fsm_pp0_stage0, ap_enable_reg_pp0_iter0_reg)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_pp0_stage0)) then 
            ap_enable_reg_pp0_iter0 <= ap_start;
        else 
            ap_enable_reg_pp0_iter0 <= ap_enable_reg_pp0_iter0_reg;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1, ap_enable_reg_pp0_iter2, ap_enable_reg_pp0_iter3)
    begin
        if (((ap_enable_reg_pp0_iter0 = ap_const_logic_0) and (ap_enable_reg_pp0_iter3 = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0))) then 
            ap_idle_pp0 <= ap_const_logic_1;
        else 
            ap_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_pp0_0to2_assign_proc : process(ap_enable_reg_pp0_iter0, ap_enable_reg_pp0_iter1, ap_enable_reg_pp0_iter2)
    begin
        if (((ap_enable_reg_pp0_iter0 = ap_const_logic_0) and (ap_enable_reg_pp0_iter2 = ap_const_logic_0) and (ap_enable_reg_pp0_iter1 = ap_const_logic_0))) then 
            ap_idle_pp0_0to2 <= ap_const_logic_1;
        else 
            ap_idle_pp0_0to2 <= ap_const_logic_0;
        end if; 
    end process;

    ap_local_block <= ap_const_logic_0;
    ap_local_deadlock <= ap_const_logic_0;

    ap_phi_mux_i1_phi_fu_149_p6_assign_proc : process(icmp_ln8_reg_356, i1_reg_145, i_reg_390, ap_condition_180)
    begin
        if ((ap_const_boolean_1 = ap_condition_180)) then
            if ((icmp_ln8_reg_356 = ap_const_lv1_1)) then 
                ap_phi_mux_i1_phi_fu_149_p6 <= ap_const_lv2_0;
            elsif ((icmp_ln8_reg_356 = ap_const_lv1_0)) then 
                ap_phi_mux_i1_phi_fu_149_p6 <= i_reg_390;
            else 
                ap_phi_mux_i1_phi_fu_149_p6 <= i1_reg_145;
            end if;
        else 
            ap_phi_mux_i1_phi_fu_149_p6 <= i1_reg_145;
        end if; 
    end process;

    ap_phi_reg_pp0_iter0_firstVector_arr_load_1_cast_phi_reg_244 <= "XXXXXXXXXXXXXXXXX";
    ap_phi_reg_pp0_iter0_firstVector_arr_load_2_cast_phi_reg_232 <= "XXXXXXXXXXXXXXXXX";
    ap_phi_reg_pp0_iter0_firstVector_arr_load_cast_phi_reg_256 <= "XXXXXXXXXXXXXXXXX";
    ap_phi_reg_pp0_iter0_sext_ln8_phi_reg_220 <= "XXXXXXXXXXXXXXXXX";

    ap_ready_assign_proc : process(icmp_ln8_reg_356, ap_CS_fsm_pp0_stage1, ap_enable_reg_pp0_iter0, ap_block_pp0_stage1_11001)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1) and (icmp_ln8_reg_356 = ap_const_lv1_1))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;


    ap_reset_idle_pp0_assign_proc : process(ap_start, ap_idle_pp0_0to2)
    begin
        if (((ap_idle_pp0_0to2 = ap_const_logic_1) and (ap_start = ap_const_logic_0))) then 
            ap_reset_idle_pp0 <= ap_const_logic_1;
        else 
            ap_reset_idle_pp0 <= ap_const_logic_0;
        end if; 
    end process;


    firstVector_arr_address0_assign_proc : process(ap_CS_fsm_pp0_stage1, ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0, ap_block_pp0_stage1)
    begin
        if ((ap_enable_reg_pp0_iter0 = ap_const_logic_1)) then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1))) then 
                firstVector_arr_address0 <= ap_const_lv64_3(2 - 1 downto 0);
            elsif (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0))) then 
                firstVector_arr_address0 <= ap_const_lv64_1(2 - 1 downto 0);
            else 
                firstVector_arr_address0 <= "XX";
            end if;
        else 
            firstVector_arr_address0 <= "XX";
        end if; 
    end process;


    firstVector_arr_address1_assign_proc : process(ap_CS_fsm_pp0_stage1, ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0, ap_block_pp0_stage1)
    begin
        if ((ap_enable_reg_pp0_iter0 = ap_const_logic_1)) then
            if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1))) then 
                firstVector_arr_address1 <= ap_const_lv64_2(2 - 1 downto 0);
            elsif (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0))) then 
                firstVector_arr_address1 <= ap_const_lv64_0(2 - 1 downto 0);
            else 
                firstVector_arr_address1 <= "XX";
            end if;
        else 
            firstVector_arr_address1 <= "XX";
        end if; 
    end process;


    firstVector_arr_ce0_assign_proc : process(ap_CS_fsm_pp0_stage1, ap_enable_reg_pp0_iter0, ap_block_pp0_stage1_11001, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1)) or ((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1)))) then 
            firstVector_arr_ce0 <= ap_const_logic_1;
        else 
            firstVector_arr_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    firstVector_arr_ce1_assign_proc : process(ap_CS_fsm_pp0_stage1, ap_enable_reg_pp0_iter0, ap_block_pp0_stage1_11001, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1)) or ((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1)))) then 
            firstVector_arr_ce1 <= ap_const_logic_1;
        else 
            firstVector_arr_ce1 <= ap_const_logic_0;
        end if; 
    end process;

        firstVector_arr_load_1_cast_fu_289_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(firstVector_arr_load_1_reg_365),17));

        firstVector_arr_load_2_cast_fu_292_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(firstVector_arr_q1),17));

        firstVector_arr_load_cast_fu_286_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(firstVector_arr_load_reg_360),17));


    grp_fu_325_ce_assign_proc : process(ap_CS_fsm_pp0_stage1, ap_block_pp0_stage1_11001, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001)
    begin
        if ((((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001)) or ((ap_const_logic_1 = ap_CS_fsm_pp0_stage1) and (ap_const_boolean_0 = ap_block_pp0_stage1_11001)))) then 
            grp_fu_325_ce <= ap_const_logic_1;
        else 
            grp_fu_325_ce <= ap_const_logic_0;
        end if; 
    end process;

    i_fu_280_p2 <= std_logic_vector(unsigned(i1_reg_145) + unsigned(ap_const_lv2_1));
    icmp_ln8_fu_274_p2 <= "1" when (ap_phi_mux_i1_phi_fu_149_p6 = ap_const_lv2_3) else "0";
    resultVecror_arr_address0 <= resultVecror_arr_addr_reg_350_pp0_iter2_reg;
    resultVecror_arr_address1 <= zext_ln8_fu_268_p1(2 - 1 downto 0);

    resultVecror_arr_ce0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001, ap_enable_reg_pp0_iter3)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter3 = ap_const_logic_1))) then 
            resultVecror_arr_ce0 <= ap_const_logic_1;
        else 
            resultVecror_arr_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    resultVecror_arr_ce1_assign_proc : process(ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
            resultVecror_arr_ce1 <= ap_const_logic_1;
        else 
            resultVecror_arr_ce1 <= ap_const_logic_0;
        end if; 
    end process;

    resultVecror_arr_d0 <= grp_fu_325_p4;

    resultVecror_arr_we0_assign_proc : process(ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001, ap_enable_reg_pp0_iter3)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter3 = ap_const_logic_1))) then 
            resultVecror_arr_we0 <= ap_const_logic_1;
        else 
            resultVecror_arr_we0 <= ap_const_logic_0;
        end if; 
    end process;

    secondVector_arr_address0 <= zext_ln8_fu_268_p1(2 - 1 downto 0);

    secondVector_arr_ce0_assign_proc : process(ap_enable_reg_pp0_iter0, ap_CS_fsm_pp0_stage0, ap_block_pp0_stage0_11001)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_pp0_stage0) and (ap_const_boolean_0 = ap_block_pp0_stage0_11001) and (ap_enable_reg_pp0_iter0 = ap_const_logic_1))) then 
            secondVector_arr_ce0 <= ap_const_logic_1;
        else 
            secondVector_arr_ce0 <= ap_const_logic_0;
        end if; 
    end process;

        sext_ln8_fu_296_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(firstVector_arr_q0),17));

    tmp4_fu_303_p2 <= std_logic_vector(unsigned(ap_phi_reg_pp0_iter1_firstVector_arr_load_1_cast_phi_reg_244) + unsigned(ap_phi_reg_pp0_iter1_firstVector_arr_load_cast_phi_reg_256));
    tmp5_fu_313_p2 <= std_logic_vector(unsigned(ap_phi_reg_pp0_iter1_firstVector_arr_load_2_cast_phi_reg_232) + unsigned(ap_phi_reg_pp0_iter1_sext_ln8_phi_reg_220));
    zext_ln8_fu_268_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(ap_phi_mux_i1_phi_fu_149_p6),64));
end behav;
