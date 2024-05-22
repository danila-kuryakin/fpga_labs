// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module foo_m_Loop_Loop2_proc (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_continue,
        ap_idle,
        ap_ready,
        temp2_dout,
        temp2_empty_n,
        temp2_read,
        data_out1_address0,
        data_out1_ce0,
        data_out1_we0,
        data_out1_d0
);

parameter    ap_ST_fsm_state1 = 4'd1;
parameter    ap_ST_fsm_state2 = 4'd2;
parameter    ap_ST_fsm_state3 = 4'd4;
parameter    ap_ST_fsm_state4 = 4'd8;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
input   ap_continue;
output   ap_idle;
output   ap_ready;
input  [31:0] temp2_dout;
input   temp2_empty_n;
output   temp2_read;
output  [13:0] data_out1_address0;
output   data_out1_ce0;
output   data_out1_we0;
output  [31:0] data_out1_d0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg temp2_read;
reg data_out1_ce0;
reg data_out1_we0;

reg    ap_done_reg;
(* fsm_encoding = "none" *) reg   [3:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    temp2_blk_n;
wire    ap_CS_fsm_state2;
wire   [0:0] icmp_ln31_fu_79_p2;
wire   [63:0] zext_ln31_fu_75_p1;
reg   [63:0] zext_ln31_reg_108;
reg  signed [31:0] temp2_read_reg_116;
wire   [31:0] mul_ln34_fu_96_p2;
reg   [31:0] mul_ln34_reg_121;
wire    ap_CS_fsm_state3;
wire    ap_CS_fsm_state4;
reg   [14:0] j_fu_44;
wire   [14:0] add_ln31_fu_85_p2;
reg    ap_block_state2;
reg    ap_block_state1;
wire   [5:0] mul_ln34_fu_96_p1;
reg   [3:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
reg    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ST_fsm_state4_blk;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_done_reg = 1'b0;
#0 ap_CS_fsm = 4'd1;
end

foo_m_mul_32s_6ns_32_1_1 #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 6 ),
    .dout_WIDTH( 32 ))
mul_32s_6ns_32_1_1_U9(
    .din0(temp2_read_reg_116),
    .din1(mul_ln34_fu_96_p1),
    .dout(mul_ln34_fu_96_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((~((ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
        j_fu_44 <= 15'd0;
    end else if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        j_fu_44 <= add_ln31_fu_85_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        mul_ln34_reg_121 <= mul_ln34_fu_96_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln31_fu_79_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        temp2_read_reg_116 <= temp2_dout;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        zext_ln31_reg_108[14 : 0] <= zext_ln31_fu_75_p1[14 : 0];
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) | (ap_done_reg == 1'b1))) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0))) begin
        ap_ST_fsm_state2_blk = 1'b1;
    end else begin
        ap_ST_fsm_state2_blk = 1'b0;
    end
end

assign ap_ST_fsm_state3_blk = 1'b0;

assign ap_ST_fsm_state4_blk = 1'b0;

always @ (*) begin
    if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = ap_done_reg;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        data_out1_ce0 = 1'b1;
    end else begin
        data_out1_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        data_out1_we0 = 1'b1;
    end else begin
        data_out1_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln31_fu_79_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        temp2_blk_n = temp2_empty_n;
    end else begin
        temp2_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        temp2_read = 1'b1;
    end else begin
        temp2_read = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if ((~((ap_start == 1'b0) | (ap_done_reg == 1'b1)) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else if ((~((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0)) & (icmp_ln31_fu_79_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln31_fu_85_p2 = (j_fu_44 + 15'd1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

always @ (*) begin
    ap_block_state1 = ((ap_start == 1'b0) | (ap_done_reg == 1'b1));
end

always @ (*) begin
    ap_block_state2 = ((icmp_ln31_fu_79_p2 == 1'd0) & (temp2_empty_n == 1'b0));
end

assign data_out1_address0 = zext_ln31_reg_108;

assign data_out1_d0 = mul_ln34_reg_121;

assign icmp_ln31_fu_79_p2 = ((j_fu_44 == 15'd16384) ? 1'b1 : 1'b0);

assign mul_ln34_fu_96_p1 = 32'd22;

assign zext_ln31_fu_75_p1 = j_fu_44;

always @ (posedge ap_clk) begin
    zext_ln31_reg_108[63:15] <= 49'b0000000000000000000000000000000000000000000000000;
end

endmodule //foo_m_Loop_Loop2_proc
