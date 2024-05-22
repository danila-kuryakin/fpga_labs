-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
-- Version: 2021.2
-- Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity lab3_z1 is
port (
    ap_local_block : OUT STD_LOGIC;
    ap_local_deadlock : OUT STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_continue : IN STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    inA : IN STD_LOGIC_VECTOR (15 downto 0);
    inA_ap_vld : IN STD_LOGIC;
    inA_ap_ack : OUT STD_LOGIC;
    inB : IN STD_LOGIC_VECTOR (15 downto 0);
    inB_ap_vld : IN STD_LOGIC;
    inB_ap_ack : OUT STD_LOGIC;
    inC : IN STD_LOGIC_VECTOR (15 downto 0);
    inC_ap_vld : IN STD_LOGIC;
    inC_ap_ack : OUT STD_LOGIC;
    res : OUT STD_LOGIC_VECTOR (31 downto 0);
    res_ap_vld : OUT STD_LOGIC;
    res_ap_ack : IN STD_LOGIC;
    ap_return : OUT STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of lab3_z1 is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "lab3_z1_lab3_z1,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=8.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=2.702000,HLS_SYN_LAT=4,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=54,HLS_SYN_LUT=113,HLS_VERSION=2021_2}";
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (4 downto 0) := "00010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (4 downto 0) := "00100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (4 downto 0) := "01000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (4 downto 0) := "10000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";

    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_CS_fsm : STD_LOGIC_VECTOR (4 downto 0) := "00001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal inA_blk_n : STD_LOGIC;
    signal inB_blk_n : STD_LOGIC;
    signal inC_blk_n : STD_LOGIC;
    signal res_blk_n : STD_LOGIC;
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal inB_read_reg_79 : STD_LOGIC_VECTOR (15 downto 0);
    signal grp_fu_72_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal temp_reg_94 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_block_state1 : BOOLEAN;
    signal sext_ln7_fu_63_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_72_ce : STD_LOGIC;
    signal regslice_forward_res_U_apdone_blk : STD_LOGIC;
    signal ap_block_state5 : BOOLEAN;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (4 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_ST_fsm_state2_blk : STD_LOGIC;
    signal ap_ST_fsm_state3_blk : STD_LOGIC;
    signal ap_ST_fsm_state4_blk : STD_LOGIC;
    signal ap_ST_fsm_state5_blk : STD_LOGIC;
    signal res_int_regslice : STD_LOGIC_VECTOR (31 downto 0);
    signal res_ap_vld_int_regslice : STD_LOGIC;
    signal res_ap_ack_int_regslice : STD_LOGIC;
    signal regslice_forward_res_U_vld_out : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component lab3_z1_mul_mul_16s_16s_32_4_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (15 downto 0);
        din1 : IN STD_LOGIC_VECTOR (15 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component lab3_z1_regslice_forward IS
    generic (
        DataWidth : INTEGER );
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        data_in : IN STD_LOGIC_VECTOR (DataWidth-1 downto 0);
        vld_in : IN STD_LOGIC;
        ack_in : OUT STD_LOGIC;
        data_out : OUT STD_LOGIC_VECTOR (DataWidth-1 downto 0);
        vld_out : OUT STD_LOGIC;
        ack_out : IN STD_LOGIC;
        apdone_blk : OUT STD_LOGIC );
    end component;



begin
    mul_mul_16s_16s_32_4_1_U1 : component lab3_z1_mul_mul_16s_16s_32_4_1
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 16,
        din1_WIDTH => 16,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => inC,
        din1 => inA,
        ce => grp_fu_72_ce,
        dout => grp_fu_72_p2);

    regslice_forward_res_U : component lab3_z1_regslice_forward
    generic map (
        DataWidth => 32)
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        data_in => res_int_regslice,
        vld_in => res_ap_vld_int_regslice,
        ack_in => res_ap_ack_int_regslice,
        data_out => res,
        vld_out => regslice_forward_res_U_vld_out,
        ack_out => res_ap_ack,
        apdone_blk => regslice_forward_res_U_apdone_blk);





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


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif ((not(((res_ap_ack_int_regslice = ap_const_logic_0) or (regslice_forward_res_U_apdone_blk = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;

    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state1)) then
                inB_read_reg_79 <= inB;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                temp_reg_94 <= grp_fu_72_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_done_reg, ap_CS_fsm, ap_CS_fsm_state1, inA_ap_vld, inB_ap_vld, inC_ap_vld, ap_CS_fsm_state4, ap_CS_fsm_state5, regslice_forward_res_U_apdone_blk, res_ap_ack_int_regslice)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if ((not(((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state4) and (res_ap_ack_int_regslice = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state5;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state5 => 
                if ((not(((res_ap_ack_int_regslice = ap_const_logic_0) or (regslice_forward_res_U_apdone_blk = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state5))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when others =>  
                ap_NS_fsm <= "XXXXX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);

    ap_ST_fsm_state1_blk_assign_proc : process(ap_start, ap_done_reg, inA_ap_vld, inB_ap_vld, inC_ap_vld)
    begin
        if (((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) then 
            ap_ST_fsm_state1_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state1_blk <= ap_const_logic_0;
        end if; 
    end process;

    ap_ST_fsm_state2_blk <= ap_const_logic_0;
    ap_ST_fsm_state3_blk <= ap_const_logic_0;

    ap_ST_fsm_state4_blk_assign_proc : process(res_ap_ack_int_regslice)
    begin
        if ((res_ap_ack_int_regslice = ap_const_logic_0)) then 
            ap_ST_fsm_state4_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state4_blk <= ap_const_logic_0;
        end if; 
    end process;


    ap_ST_fsm_state5_blk_assign_proc : process(regslice_forward_res_U_apdone_blk, res_ap_ack_int_regslice)
    begin
        if (((res_ap_ack_int_regslice = ap_const_logic_0) or (regslice_forward_res_U_apdone_blk = ap_const_logic_1))) then 
            ap_ST_fsm_state5_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state5_blk <= ap_const_logic_0;
        end if; 
    end process;


    ap_block_state1_assign_proc : process(ap_start, ap_done_reg, inA_ap_vld, inB_ap_vld, inC_ap_vld)
    begin
                ap_block_state1 <= ((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0));
    end process;


    ap_block_state5_assign_proc : process(regslice_forward_res_U_apdone_blk, res_ap_ack_int_regslice)
    begin
                ap_block_state5 <= ((res_ap_ack_int_regslice = ap_const_logic_0) or (regslice_forward_res_U_apdone_blk = ap_const_logic_1));
    end process;


    ap_done_assign_proc : process(ap_done_reg, ap_CS_fsm_state5, regslice_forward_res_U_apdone_blk, res_ap_ack_int_regslice)
    begin
        if ((not(((res_ap_ack_int_regslice = ap_const_logic_0) or (regslice_forward_res_U_apdone_blk = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_done_reg;
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

    ap_ready_assign_proc : process(ap_CS_fsm_state5, regslice_forward_res_U_apdone_blk, res_ap_ack_int_regslice)
    begin
        if ((not(((res_ap_ack_int_regslice = ap_const_logic_0) or (regslice_forward_res_U_apdone_blk = ap_const_logic_1))) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    ap_return <= temp_reg_94;

    grp_fu_72_ce_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inA_ap_vld, inB_ap_vld, inC_ap_vld, ap_CS_fsm_state4, ap_CS_fsm_state5, res_ap_ack_int_regslice)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or ((ap_const_logic_1 = ap_CS_fsm_state4) and (res_ap_ack_int_regslice = ap_const_logic_0)) or ((ap_const_logic_1 = ap_CS_fsm_state1) and ((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))))) then 
            grp_fu_72_ce <= ap_const_logic_0;
        else 
            grp_fu_72_ce <= ap_const_logic_1;
        end if; 
    end process;


    inA_ap_ack_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inA_ap_vld, inB_ap_vld, inC_ap_vld)
    begin
        if ((not(((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            inA_ap_ack <= ap_const_logic_1;
        else 
            inA_ap_ack <= ap_const_logic_0;
        end if; 
    end process;


    inA_blk_n_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inA_ap_vld)
    begin
        if ((not(((ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            inA_blk_n <= inA_ap_vld;
        else 
            inA_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    inB_ap_ack_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inA_ap_vld, inB_ap_vld, inC_ap_vld)
    begin
        if ((not(((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            inB_ap_ack <= ap_const_logic_1;
        else 
            inB_ap_ack <= ap_const_logic_0;
        end if; 
    end process;


    inB_blk_n_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inB_ap_vld)
    begin
        if ((not(((ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            inB_blk_n <= inB_ap_vld;
        else 
            inB_blk_n <= ap_const_logic_1;
        end if; 
    end process;


    inC_ap_ack_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inA_ap_vld, inB_ap_vld, inC_ap_vld)
    begin
        if ((not(((inC_ap_vld = ap_const_logic_0) or (inB_ap_vld = ap_const_logic_0) or (inA_ap_vld = ap_const_logic_0) or (ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            inC_ap_ack <= ap_const_logic_1;
        else 
            inC_ap_ack <= ap_const_logic_0;
        end if; 
    end process;


    inC_blk_n_assign_proc : process(ap_start, ap_done_reg, ap_CS_fsm_state1, inC_ap_vld)
    begin
        if ((not(((ap_done_reg = ap_const_logic_1) or (ap_start = ap_const_logic_0))) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            inC_blk_n <= inC_ap_vld;
        else 
            inC_blk_n <= ap_const_logic_1;
        end if; 
    end process;

    res_ap_vld <= regslice_forward_res_U_vld_out;

    res_ap_vld_int_regslice_assign_proc : process(ap_CS_fsm_state4, res_ap_ack_int_regslice)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state4) and (res_ap_ack_int_regslice = ap_const_logic_1))) then 
            res_ap_vld_int_regslice <= ap_const_logic_1;
        else 
            res_ap_vld_int_regslice <= ap_const_logic_0;
        end if; 
    end process;


    res_blk_n_assign_proc : process(ap_CS_fsm_state4, ap_CS_fsm_state5, res_ap_ack_int_regslice)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state5) or (ap_const_logic_1 = ap_CS_fsm_state4))) then 
            res_blk_n <= res_ap_ack_int_regslice;
        else 
            res_blk_n <= ap_const_logic_1;
        end if; 
    end process;

    res_int_regslice <= std_logic_vector(signed(grp_fu_72_p2) + signed(sext_ln7_fu_63_p1));
        sext_ln7_fu_63_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(inB_read_reg_79),32));

end behav;