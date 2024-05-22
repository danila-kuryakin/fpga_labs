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
    secondVector_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    secondVector_arr_ce0 : OUT STD_LOGIC;
    secondVector_arr_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    resultVecror_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    resultVecror_arr_ce0 : OUT STD_LOGIC;
    resultVecror_arr_we0 : OUT STD_LOGIC;
    resultVecror_arr_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    resultVecror_arr_q0 : IN STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of lab4_z1 is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "lab4_z1_lab4_z1,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=4.252000,HLS_SYN_LAT=53,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=266,HLS_SYN_LUT=238,HLS_VERSION=2021_2}";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (4 downto 0) := "00100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (4 downto 0) := "01000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv3_0 : STD_LOGIC_VECTOR (2 downto 0) := "000";
    constant ap_const_lv3_4 : STD_LOGIC_VECTOR (2 downto 0) := "100";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";

    signal ap_CS_fsm : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal trunc_ln6_fu_109_p1 : STD_LOGIC_VECTOR (1 downto 0);
    signal trunc_ln6_reg_128 : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal icmp_ln9_fu_91_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal secondVector_arr_load_reg_143 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal resultVecror_arr_load_reg_148 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_lab4_z1_Pipeline_L1_fu_72_ap_start : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_ap_done : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_ap_idle : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_ap_ready : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_address0 : STD_LOGIC_VECTOR (1 downto 0);
    signal grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_ce0 : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_we0 : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_d0 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_lab4_z1_Pipeline_L1_fu_72_firstVector_arr_address0 : STD_LOGIC_VECTOR (1 downto 0);
    signal grp_lab4_z1_Pipeline_L1_fu_72_firstVector_arr_ce0 : STD_LOGIC;
    signal grp_lab4_z1_Pipeline_L1_fu_72_ap_start_reg : STD_LOGIC := '0';
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal zext_ln9_fu_103_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal i_fu_42 : STD_LOGIC_VECTOR (2 downto 0);
    signal add_ln9_fu_97_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_ST_fsm_state2_blk : STD_LOGIC;
    signal ap_ST_fsm_state3_blk : STD_LOGIC;
    signal ap_ST_fsm_state4_blk : STD_LOGIC;
    signal ap_ST_fsm_state5_blk : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component lab4_z1_lab4_z1_Pipeline_L1 IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        resultVecror_arr_load : IN STD_LOGIC_VECTOR (31 downto 0);
        resultVecror_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
        resultVecror_arr_ce0 : OUT STD_LOGIC;
        resultVecror_arr_we0 : OUT STD_LOGIC;
        resultVecror_arr_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
        zext_ln9 : IN STD_LOGIC_VECTOR (1 downto 0);
        firstVector_arr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
        firstVector_arr_ce0 : OUT STD_LOGIC;
        firstVector_arr_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
        conv4 : IN STD_LOGIC_VECTOR (15 downto 0) );
    end component;



begin
    grp_lab4_z1_Pipeline_L1_fu_72 : component lab4_z1_lab4_z1_Pipeline_L1
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_lab4_z1_Pipeline_L1_fu_72_ap_start,
        ap_done => grp_lab4_z1_Pipeline_L1_fu_72_ap_done,
        ap_idle => grp_lab4_z1_Pipeline_L1_fu_72_ap_idle,
        ap_ready => grp_lab4_z1_Pipeline_L1_fu_72_ap_ready,
        resultVecror_arr_load => resultVecror_arr_load_reg_148,
        resultVecror_arr_address0 => grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_address0,
        resultVecror_arr_ce0 => grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_ce0,
        resultVecror_arr_we0 => grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_we0,
        resultVecror_arr_d0 => grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_d0,
        zext_ln9 => trunc_ln6_reg_128,
        firstVector_arr_address0 => grp_lab4_z1_Pipeline_L1_fu_72_firstVector_arr_address0,
        firstVector_arr_ce0 => grp_lab4_z1_Pipeline_L1_fu_72_firstVector_arr_ce0,
        firstVector_arr_q0 => firstVector_arr_q0,
        conv4 => secondVector_arr_load_reg_143);





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


    grp_lab4_z1_Pipeline_L1_fu_72_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_lab4_z1_Pipeline_L1_fu_72_ap_start_reg <= ap_const_logic_0;
            else
                if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
                    grp_lab4_z1_Pipeline_L1_fu_72_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_lab4_z1_Pipeline_L1_fu_72_ap_ready = ap_const_logic_1)) then 
                    grp_lab4_z1_Pipeline_L1_fu_72_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    i_fu_42_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_fu_42 <= ap_const_lv3_0;
            elsif (((icmp_ln9_fu_91_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                i_fu_42 <= add_ln9_fu_97_p2;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                resultVecror_arr_load_reg_148 <= resultVecror_arr_q0;
                secondVector_arr_load_reg_143 <= secondVector_arr_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln9_fu_91_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                trunc_ln6_reg_128 <= trunc_ln6_fu_109_p1;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln9_fu_91_p2, grp_lab4_z1_Pipeline_L1_fu_72_ap_done, ap_CS_fsm_state5)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln9_fu_91_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                if (((grp_lab4_z1_Pipeline_L1_fu_72_ap_done = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when others =>  
                ap_NS_fsm <= "XXXXX";
        end case;
    end process;
    add_ln9_fu_97_p2 <= std_logic_vector(unsigned(i_fu_42) + unsigned(ap_const_lv3_1));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);

    ap_ST_fsm_state1_blk_assign_proc : process(ap_start)
    begin
        if ((ap_start = ap_const_logic_0)) then 
            ap_ST_fsm_state1_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state1_blk <= ap_const_logic_0;
        end if; 
    end process;

    ap_ST_fsm_state2_blk <= ap_const_logic_0;
    ap_ST_fsm_state3_blk <= ap_const_logic_0;
    ap_ST_fsm_state4_blk <= ap_const_logic_0;

    ap_ST_fsm_state5_blk_assign_proc : process(grp_lab4_z1_Pipeline_L1_fu_72_ap_done)
    begin
        if ((grp_lab4_z1_Pipeline_L1_fu_72_ap_done = ap_const_logic_0)) then 
            ap_ST_fsm_state5_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state5_blk <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_assign_proc : process(ap_CS_fsm_state2, icmp_ln9_fu_91_p2)
    begin
        if (((icmp_ln9_fu_91_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
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

    ap_local_block <= ap_const_logic_0;
    ap_local_deadlock <= ap_const_logic_0;

    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln9_fu_91_p2)
    begin
        if (((icmp_ln9_fu_91_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    firstVector_arr_address0 <= grp_lab4_z1_Pipeline_L1_fu_72_firstVector_arr_address0;
    firstVector_arr_ce0 <= grp_lab4_z1_Pipeline_L1_fu_72_firstVector_arr_ce0;
    grp_lab4_z1_Pipeline_L1_fu_72_ap_start <= grp_lab4_z1_Pipeline_L1_fu_72_ap_start_reg;
    icmp_ln9_fu_91_p2 <= "1" when (i_fu_42 = ap_const_lv3_4) else "0";

    resultVecror_arr_address0_assign_proc : process(ap_CS_fsm_state2, grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_address0, ap_CS_fsm_state5, zext_ln9_fu_103_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            resultVecror_arr_address0 <= zext_ln9_fu_103_p1(2 - 1 downto 0);
        elsif ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            resultVecror_arr_address0 <= grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_address0;
        else 
            resultVecror_arr_address0 <= "XX";
        end if; 
    end process;


    resultVecror_arr_ce0_assign_proc : process(ap_CS_fsm_state2, grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_ce0, ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            resultVecror_arr_ce0 <= ap_const_logic_1;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            resultVecror_arr_ce0 <= grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_ce0;
        else 
            resultVecror_arr_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    resultVecror_arr_d0 <= grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_d0;

    resultVecror_arr_we0_assign_proc : process(grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_we0, ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            resultVecror_arr_we0 <= grp_lab4_z1_Pipeline_L1_fu_72_resultVecror_arr_we0;
        else 
            resultVecror_arr_we0 <= ap_const_logic_0;
        end if; 
    end process;

    secondVector_arr_address0 <= zext_ln9_fu_103_p1(2 - 1 downto 0);

    secondVector_arr_ce0_assign_proc : process(ap_CS_fsm_state2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            secondVector_arr_ce0 <= ap_const_logic_1;
        else 
            secondVector_arr_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    trunc_ln6_fu_109_p1 <= i_fu_42(2 - 1 downto 0);
    zext_ln9_fu_103_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_fu_42),64));
end behav;
