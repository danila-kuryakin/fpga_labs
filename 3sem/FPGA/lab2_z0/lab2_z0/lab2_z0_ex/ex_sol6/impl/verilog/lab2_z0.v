// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="lab2_z0_lab2_z0,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.450000,HLS_SYN_LAT=7,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=7,HLS_SYN_LUT=68,HLS_VERSION=2021_2}" *)

module lab2_z0 (
        ap_local_block,
        ap_local_deadlock,
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        in_a_address0,
        in_a_ce0,
        in_a_q0,
        in_b_address0,
        in_b_ce0,
        in_b_q0,
        res_address0,
        res_ce0,
        res_we0,
        res_d0
);

parameter    ap_ST_fsm_state1 = 3'd1;
parameter    ap_ST_fsm_state2 = 3'd2;
parameter    ap_ST_fsm_state3 = 3'd4;

output   ap_local_block;
output   ap_local_deadlock;
input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [1:0] in_a_address0;
output   in_a_ce0;
input  [15:0] in_a_q0;
output  [1:0] in_b_address0;
output   in_b_ce0;
input  [15:0] in_b_q0;
output  [1:0] res_address0;
output   res_ce0;
output   res_we0;
output  [31:0] res_d0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg in_a_ce0;
reg in_b_ce0;
reg res_ce0;
reg res_we0;

(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [63:0] zext_ln7_fu_91_p1;
reg   [63:0] zext_ln7_reg_140;
wire    ap_CS_fsm_state2;
wire   [0:0] icmp_ln7_fu_97_p2;
wire    ap_CS_fsm_state3;
reg   [1:0] i_fu_40;
wire   [1:0] add_ln7_fu_103_p2;
wire  signed [16:0] sext_ln13_1_fu_118_p1;
wire  signed [16:0] sext_ln13_fu_114_p1;
wire   [16:0] tmp_res_fu_122_p2;
reg   [2:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
wire    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_fu_40 <= 2'd0;
    end else if (((icmp_ln7_fu_97_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        i_fu_40 <= add_ln7_fu_103_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        zext_ln7_reg_140[1 : 0] <= zext_ln7_fu_91_p1[1 : 0];
    end
end

always @ (*) begin
    if ((ap_start == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

assign ap_ST_fsm_state2_blk = 1'b0;

assign ap_ST_fsm_state3_blk = 1'b0;

always @ (*) begin
    if (((icmp_ln7_fu_97_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln7_fu_97_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        in_a_ce0 = 1'b1;
    end else begin
        in_a_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        in_b_ce0 = 1'b1;
    end else begin
        in_b_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        res_ce0 = 1'b1;
    end else begin
        res_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        res_we0 = 1'b1;
    end else begin
        res_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((icmp_ln7_fu_97_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln7_fu_103_p2 = (i_fu_40 + 2'd1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_local_block = 1'b0;

assign ap_local_deadlock = 1'b0;

assign icmp_ln7_fu_97_p2 = ((i_fu_40 == 2'd3) ? 1'b1 : 1'b0);

assign in_a_address0 = zext_ln7_fu_91_p1;

assign in_b_address0 = zext_ln7_fu_91_p1;

assign res_address0 = zext_ln7_reg_140;

assign res_d0 = $signed(tmp_res_fu_122_p2);

assign sext_ln13_1_fu_118_p1 = $signed(in_b_q0);

assign sext_ln13_fu_114_p1 = $signed(in_a_q0);

assign tmp_res_fu_122_p2 = ($signed(sext_ln13_1_fu_118_p1) + $signed(sext_ln13_fu_114_p1));

assign zext_ln7_fu_91_p1 = i_fu_40;

always @ (posedge ap_clk) begin
    zext_ln7_reg_140[63:2] <= 62'b00000000000000000000000000000000000000000000000000000000000000;
end

endmodule //lab2_z0
