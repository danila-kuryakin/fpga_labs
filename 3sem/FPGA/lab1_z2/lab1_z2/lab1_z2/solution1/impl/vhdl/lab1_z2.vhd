-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity lab1_z2 is
port (
    ap_local_block : OUT STD_LOGIC;
    ap_local_deadlock : OUT STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    inArr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    inArr_ce0 : OUT STD_LOGIC;
    inArr_q0 : IN STD_LOGIC_VECTOR (15 downto 0);
    a : IN STD_LOGIC_VECTOR (15 downto 0);
    b : IN STD_LOGIC_VECTOR (15 downto 0);
    c : IN STD_LOGIC_VECTOR (15 downto 0);
    outArr_address0 : OUT STD_LOGIC_VECTOR (1 downto 0);
    outArr_ce0 : OUT STD_LOGIC;
    outArr_we0 : OUT STD_LOGIC;
    outArr_d0 : OUT STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of lab1_z2 is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "lab1_z2_lab1_z2,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=6.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=4.332750,HLS_SYN_LAT=10,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=60,HLS_SYN_LUT=121,HLS_VERSION=2021_2}";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (3 downto 0) := "0010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (3 downto 0) := "0100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (3 downto 0) := "1000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv2_3 : STD_LOGIC_VECTOR (1 downto 0) := "11";
    constant ap_const_lv2_1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";

    signal ap_CS_fsm : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal sext_ln8_fu_104_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal sext_ln8_reg_177 : STD_LOGIC_VECTOR (16 downto 0);
    signal sext_ln12_1_fu_114_p1 : STD_LOGIC_VECTOR (17 downto 0);
    signal sext_ln12_1_reg_182 : STD_LOGIC_VECTOR (17 downto 0);
    signal zext_ln8_fu_126_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln8_reg_187 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal icmp_ln8_fu_131_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln12_1_fu_152_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal add_ln12_1_reg_200 : STD_LOGIC_VECTOR (16 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal i_fu_48 : STD_LOGIC_VECTOR (1 downto 0);
    signal add_ln8_fu_137_p2 : STD_LOGIC_VECTOR (1 downto 0);
    signal b_cast_fu_100_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal a_cast_fu_96_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal add_ln12_fu_108_p2 : STD_LOGIC_VECTOR (16 downto 0);
    signal sext_ln12_fu_148_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal sext_ln12_2_fu_157_p1 : STD_LOGIC_VECTOR (17 downto 0);
    signal y_fu_160_p2 : STD_LOGIC_VECTOR (17 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (3 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_ST_fsm_state2_blk : STD_LOGIC;
    signal ap_ST_fsm_state3_blk : STD_LOGIC;
    signal ap_ST_fsm_state4_blk : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;


begin




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


    i_fu_48_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_fu_48 <= ap_const_lv2_0;
            elsif (((icmp_ln8_fu_131_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                i_fu_48 <= add_ln8_fu_137_p2;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                add_ln12_1_reg_200 <= add_ln12_1_fu_152_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state1)) then
                sext_ln12_1_reg_182 <= sext_ln12_1_fu_114_p1;
                sext_ln8_reg_177 <= sext_ln8_fu_104_p1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                    zext_ln8_reg_187(1 downto 0) <= zext_ln8_fu_126_p1(1 downto 0);
            end if;
        end if;
    end process;
    zext_ln8_reg_187(63 downto 2) <= "00000000000000000000000000000000000000000000000000000000000000";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln8_fu_131_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln8_fu_131_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state2;
            when others =>  
                ap_NS_fsm <= "XXXX";
        end case;
    end process;
        a_cast_fu_96_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(a),17));

    add_ln12_1_fu_152_p2 <= std_logic_vector(signed(sext_ln8_reg_177) + signed(sext_ln12_fu_148_p1));
    add_ln12_fu_108_p2 <= std_logic_vector(signed(b_cast_fu_100_p1) + signed(a_cast_fu_96_p1));
    add_ln8_fu_137_p2 <= std_logic_vector(unsigned(i_fu_48) + unsigned(ap_const_lv2_1));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);

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

    ap_done_assign_proc : process(ap_CS_fsm_state2, icmp_ln8_fu_131_p2)
    begin
        if (((icmp_ln8_fu_131_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
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

    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln8_fu_131_p2)
    begin
        if (((icmp_ln8_fu_131_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

        b_cast_fu_100_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(b),17));

    icmp_ln8_fu_131_p2 <= "1" when (i_fu_48 = ap_const_lv2_3) else "0";
    inArr_address0 <= zext_ln8_fu_126_p1(2 - 1 downto 0);

    inArr_ce0_assign_proc : process(ap_CS_fsm_state2)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state2)) then 
            inArr_ce0 <= ap_const_logic_1;
        else 
            inArr_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    outArr_address0 <= zext_ln8_reg_187(2 - 1 downto 0);

    outArr_ce0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            outArr_ce0 <= ap_const_logic_1;
        else 
            outArr_ce0 <= ap_const_logic_0;
        end if; 
    end process;

        outArr_d0 <= std_logic_vector(IEEE.numeric_std.resize(signed(y_fu_160_p2),32));


    outArr_we0_assign_proc : process(ap_CS_fsm_state4)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
            outArr_we0 <= ap_const_logic_1;
        else 
            outArr_we0 <= ap_const_logic_0;
        end if; 
    end process;

        sext_ln12_1_fu_114_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(add_ln12_fu_108_p2),18));

        sext_ln12_2_fu_157_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(add_ln12_1_reg_200),18));

        sext_ln12_fu_148_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(inArr_q0),17));

        sext_ln8_fu_104_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(c),17));

    y_fu_160_p2 <= std_logic_vector(signed(sext_ln12_2_fu_157_p1) + signed(sext_ln12_1_reg_182));
    zext_ln8_fu_126_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_fu_48),64));
end behav;
