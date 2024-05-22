-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity lab2_z1 is
port (
    ap_local_block : OUT STD_LOGIC;
    ap_local_deadlock : OUT STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    in_r : IN STD_LOGIC_VECTOR (15 downto 0);
    ap_return : OUT STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of lab2_z1 is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "lab2_z1_lab2_z1,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=12.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=10.080000,HLS_SYN_LAT=7,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=67,HLS_SYN_LUT=88,HLS_VERSION=2021_2}";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (1 downto 0) := "10";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv16_1 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000001";

    signal ap_CS_fsm : STD_LOGIC_VECTOR (1 downto 0) := "01";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal sext_ln6_fu_51_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal sext_ln6_reg_117 : STD_LOGIC_VECTOR (16 downto 0);
    signal res_fu_34 : STD_LOGIC_VECTOR (31 downto 0);
    signal res_1_fu_81_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal icmp_ln6_fu_76_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal i_fu_38 : STD_LOGIC_VECTOR (15 downto 0);
    signal i_3_fu_87_p2 : STD_LOGIC_VECTOR (15 downto 0);
    signal zext_ln6_1_fu_72_p1 : STD_LOGIC_VECTOR (16 downto 0);
    signal res_1_fu_81_p0 : STD_LOGIC_VECTOR (15 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_ST_fsm_state2_blk : STD_LOGIC;
    signal res_1_fu_81_p00 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_ce_reg : STD_LOGIC;

    component lab2_z1_mul_16ns_32s_32_1_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        din0 : IN STD_LOGIC_VECTOR (15 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    mul_16ns_32s_32_1_1_U1 : component lab2_z1_mul_16ns_32s_32_1_1
    generic map (
        ID => 1,
        NUM_STAGE => 1,
        din0_WIDTH => 16,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        din0 => res_1_fu_81_p0,
        din1 => res_fu_34,
        dout => res_1_fu_81_p2);





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


    i_fu_38_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                i_fu_38 <= ap_const_lv16_1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln6_fu_76_p2 = ap_const_lv1_0))) then 
                i_fu_38 <= i_3_fu_87_p2;
            end if; 
        end if;
    end process;

    res_fu_34_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                res_fu_34 <= ap_const_lv32_1;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln6_fu_76_p2 = ap_const_lv1_0))) then 
                res_fu_34 <= res_1_fu_81_p2;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state1)) then
                sext_ln6_reg_117 <= sext_ln6_fu_51_p1;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln6_fu_76_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln6_fu_76_p2 = ap_const_lv1_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state2;
                end if;
            when others =>  
                ap_NS_fsm <= "XX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);

    ap_ST_fsm_state1_blk_assign_proc : process(ap_start)
    begin
        if ((ap_start = ap_const_logic_0)) then 
            ap_ST_fsm_state1_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state1_blk <= ap_const_logic_0;
        end if; 
    end process;

    ap_ST_fsm_state2_blk <= ap_const_logic_0;

    ap_done_assign_proc : process(ap_CS_fsm_state2, icmp_ln6_fu_76_p2)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln6_fu_76_p2 = ap_const_lv1_1))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;

    ap_local_block <= ap_const_logic_0;
    ap_local_deadlock <= ap_const_logic_0;

    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln6_fu_76_p2)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state2) and (icmp_ln6_fu_76_p2 = ap_const_lv1_1))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    ap_return <= res_fu_34;
    i_3_fu_87_p2 <= std_logic_vector(unsigned(i_fu_38) + unsigned(ap_const_lv16_1));
    icmp_ln6_fu_76_p2 <= "1" when (signed(zext_ln6_1_fu_72_p1) > signed(sext_ln6_reg_117)) else "0";
    res_1_fu_81_p0 <= res_1_fu_81_p00(16 - 1 downto 0);
    res_1_fu_81_p00 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_fu_38),32));
        sext_ln6_fu_51_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(in_r),17));

    zext_ln6_1_fu_72_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_fu_38),17));
end behav;
