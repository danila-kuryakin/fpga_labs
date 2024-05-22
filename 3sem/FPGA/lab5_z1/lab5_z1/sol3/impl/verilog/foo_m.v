// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="foo_m_foo_m,hls_ip_2021_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xa7a12t-csg325-1Q,HLS_INPUT_CLOCK=14.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=11.727000,HLS_SYN_LAT=163844,HLS_SYN_TPT=none,HLS_SYN_MEM=96,HLS_SYN_DSP=0,HLS_SYN_FF=195,HLS_SYN_LUT=345,HLS_VERSION=2021_2}" *)

module foo_m (
        ap_local_block,
        ap_local_deadlock,
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        data_in_address0,
        data_in_ce0,
        data_in_q0,
        scale,
        data_out1_address0,
        data_out1_ce0,
        data_out1_we0,
        data_out1_d0,
        data_out2_address0,
        data_out2_ce0,
        data_out2_we0,
        data_out2_d0
);

parameter    ap_ST_fsm_state1 = 11'd1;
parameter    ap_ST_fsm_state2 = 11'd2;
parameter    ap_ST_fsm_state3 = 11'd4;
parameter    ap_ST_fsm_state4 = 11'd8;
parameter    ap_ST_fsm_state5 = 11'd16;
parameter    ap_ST_fsm_state6 = 11'd32;
parameter    ap_ST_fsm_state7 = 11'd64;
parameter    ap_ST_fsm_state8 = 11'd128;
parameter    ap_ST_fsm_state9 = 11'd256;
parameter    ap_ST_fsm_state10 = 11'd512;
parameter    ap_ST_fsm_state11 = 11'd1024;

output   ap_local_block;
output   ap_local_deadlock;
input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [13:0] data_in_address0;
output   data_in_ce0;
input  [31:0] data_in_q0;
input  [31:0] scale;
output  [13:0] data_out1_address0;
output   data_out1_ce0;
output   data_out1_we0;
output  [31:0] data_out1_d0;
output  [13:0] data_out2_address0;
output   data_out2_ce0;
output   data_out2_we0;
output  [31:0] data_out2_d0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg data_in_ce0;
reg data_out1_ce0;
reg data_out1_we0;
reg data_out2_ce0;
reg data_out2_we0;

(* fsm_encoding = "none" *) reg   [10:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [63:0] zext_ln21_fu_198_p1;
reg   [63:0] zext_ln21_reg_346;
wire    ap_CS_fsm_state2;
wire   [0:0] icmp_ln21_fu_203_p2;
wire   [31:0] mul_ln24_fu_225_p2;
reg   [31:0] mul_ln24_reg_366;
wire    ap_CS_fsm_state3;
wire   [63:0] zext_ln8_fu_233_p1;
reg   [63:0] zext_ln8_reg_371;
wire    ap_CS_fsm_state5;
wire   [0:0] icmp_ln8_fu_238_p2;
wire   [63:0] zext_ln31_fu_263_p1;
reg   [63:0] zext_ln31_reg_392;
wire    ap_CS_fsm_state7;
wire   [0:0] icmp_ln31_fu_268_p2;
wire   [31:0] temp2_q0;
reg  signed [31:0] temp2_load_reg_412;
wire    ap_CS_fsm_state8;
wire   [63:0] zext_ln38_fu_299_p1;
reg   [63:0] zext_ln38_reg_417;
wire    ap_CS_fsm_state10;
wire   [0:0] icmp_ln38_fu_304_p2;
reg   [13:0] temp1_address0;
reg    temp1_ce0;
reg    temp1_we0;
wire   [31:0] temp1_q0;
reg   [13:0] temp2_address0;
reg    temp2_ce0;
reg    temp2_we0;
reg   [13:0] temp3_address0;
reg    temp3_ce0;
reg    temp3_we0;
wire   [31:0] temp3_q0;
wire    ap_CS_fsm_state4;
wire    ap_CS_fsm_state6;
wire    ap_CS_fsm_state9;
wire    ap_CS_fsm_state11;
reg   [14:0] i_fu_58;
wire   [14:0] add_ln21_fu_209_p2;
reg   [14:0] i_1_fu_74;
wire   [14:0] add_ln8_fu_244_p2;
reg   [14:0] j_fu_78;
wire   [14:0] add_ln31_fu_274_p2;
reg   [14:0] k_fu_82;
wire   [14:0] add_ln38_fu_310_p2;
wire   [31:0] mul_ln34_fu_290_p2;
wire   [5:0] mul_ln34_fu_290_p1;
wire   [31:0] shl_ln41_fu_321_p2;
reg   [10:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
wire    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ST_fsm_state4_blk;
wire    ap_ST_fsm_state5_blk;
wire    ap_ST_fsm_state6_blk;
wire    ap_ST_fsm_state7_blk;
wire    ap_ST_fsm_state8_blk;
wire    ap_ST_fsm_state9_blk;
wire    ap_ST_fsm_state10_blk;
wire    ap_ST_fsm_state11_blk;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 11'd1;
end

foo_m_temp1_RAM_AUTO_1R1W #(
    .DataWidth( 32 ),
    .AddressRange( 16384 ),
    .AddressWidth( 14 ))
temp1_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(temp1_address0),
    .ce0(temp1_ce0),
    .we0(temp1_we0),
    .d0(mul_ln24_reg_366),
    .q0(temp1_q0)
);

foo_m_temp1_RAM_AUTO_1R1W #(
    .DataWidth( 32 ),
    .AddressRange( 16384 ),
    .AddressWidth( 14 ))
temp2_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(temp2_address0),
    .ce0(temp2_ce0),
    .we0(temp2_we0),
    .d0(temp1_q0),
    .q0(temp2_q0)
);

foo_m_temp1_RAM_AUTO_1R1W #(
    .DataWidth( 32 ),
    .AddressRange( 16384 ),
    .AddressWidth( 14 ))
temp3_U(
    .clk(ap_clk),
    .reset(ap_rst),
    .address0(temp3_address0),
    .ce0(temp3_ce0),
    .we0(temp3_we0),
    .d0(temp1_q0),
    .q0(temp3_q0)
);

foo_m_mul_32s_32s_32_1_1 #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mul_32s_32s_32_1_1_U1(
    .din0(data_in_q0),
    .din1(scale),
    .dout(mul_ln24_fu_225_p2)
);

foo_m_mul_32s_6ns_32_1_1 #(
    .ID( 1 ),
    .NUM_STAGE( 1 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 6 ),
    .dout_WIDTH( 32 ))
mul_32s_6ns_32_1_1_U2(
    .din0(temp2_load_reg_412),
    .din1(mul_ln34_fu_290_p1),
    .dout(mul_ln34_fu_290_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln21_fu_203_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        i_1_fu_74 <= 15'd0;
    end else if (((icmp_ln8_fu_238_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state5))) begin
        i_1_fu_74 <= add_ln8_fu_244_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_fu_58 <= 15'd0;
    end else if (((icmp_ln21_fu_203_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        i_fu_58 <= add_ln21_fu_209_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln8_fu_238_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state5))) begin
        j_fu_78 <= 15'd0;
    end else if (((icmp_ln31_fu_268_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state7))) begin
        j_fu_78 <= add_ln31_fu_274_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln31_fu_268_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state7))) begin
        k_fu_82 <= 15'd0;
    end else if (((1'b1 == ap_CS_fsm_state10) & (icmp_ln38_fu_304_p2 == 1'd0))) begin
        k_fu_82 <= add_ln38_fu_310_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        mul_ln24_reg_366 <= mul_ln24_fu_225_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state8)) begin
        temp2_load_reg_412 <= temp2_q0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        zext_ln21_reg_346[14 : 0] <= zext_ln21_fu_198_p1[14 : 0];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        zext_ln31_reg_392[14 : 0] <= zext_ln31_fu_263_p1[14 : 0];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        zext_ln38_reg_417[14 : 0] <= zext_ln38_fu_299_p1[14 : 0];
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        zext_ln8_reg_371[14 : 0] <= zext_ln8_fu_233_p1[14 : 0];
    end
end

assign ap_ST_fsm_state10_blk = 1'b0;

assign ap_ST_fsm_state11_blk = 1'b0;

always @ (*) begin
    if ((ap_start == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

assign ap_ST_fsm_state2_blk = 1'b0;

assign ap_ST_fsm_state3_blk = 1'b0;

assign ap_ST_fsm_state4_blk = 1'b0;

assign ap_ST_fsm_state5_blk = 1'b0;

assign ap_ST_fsm_state6_blk = 1'b0;

assign ap_ST_fsm_state7_blk = 1'b0;

assign ap_ST_fsm_state8_blk = 1'b0;

assign ap_ST_fsm_state9_blk = 1'b0;

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state10) & (icmp_ln38_fu_304_p2 == 1'd1))) begin
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
    if (((1'b1 == ap_CS_fsm_state10) & (icmp_ln38_fu_304_p2 == 1'd1))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        data_in_ce0 = 1'b1;
    end else begin
        data_in_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        data_out1_ce0 = 1'b1;
    end else begin
        data_out1_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state9)) begin
        data_out1_we0 = 1'b1;
    end else begin
        data_out1_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state11)) begin
        data_out2_ce0 = 1'b1;
    end else begin
        data_out2_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state11)) begin
        data_out2_we0 = 1'b1;
    end else begin
        data_out2_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state5)) begin
        temp1_address0 = zext_ln8_fu_233_p1;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        temp1_address0 = zext_ln21_reg_346;
    end else begin
        temp1_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state5) | (1'b1 == ap_CS_fsm_state4))) begin
        temp1_ce0 = 1'b1;
    end else begin
        temp1_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        temp1_we0 = 1'b1;
    end else begin
        temp1_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state7)) begin
        temp2_address0 = zext_ln31_fu_263_p1;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        temp2_address0 = zext_ln8_reg_371;
    end else begin
        temp2_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state7) | (1'b1 == ap_CS_fsm_state6))) begin
        temp2_ce0 = 1'b1;
    end else begin
        temp2_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        temp2_we0 = 1'b1;
    end else begin
        temp2_we0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state10)) begin
        temp3_address0 = zext_ln38_fu_299_p1;
    end else if ((1'b1 == ap_CS_fsm_state6)) begin
        temp3_address0 = zext_ln8_reg_371;
    end else begin
        temp3_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) | (1'b1 == ap_CS_fsm_state10))) begin
        temp3_ce0 = 1'b1;
    end else begin
        temp3_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state6)) begin
        temp3_we0 = 1'b1;
    end else begin
        temp3_we0 = 1'b0;
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
            if (((icmp_ln21_fu_203_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state5;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        ap_ST_fsm_state5 : begin
            if (((icmp_ln8_fu_238_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state5))) begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        ap_ST_fsm_state6 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state7 : begin
            if (((icmp_ln31_fu_268_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state7))) begin
                ap_NS_fsm = ap_ST_fsm_state10;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state8;
            end
        end
        ap_ST_fsm_state8 : begin
            ap_NS_fsm = ap_ST_fsm_state9;
        end
        ap_ST_fsm_state9 : begin
            ap_NS_fsm = ap_ST_fsm_state7;
        end
        ap_ST_fsm_state10 : begin
            if (((1'b1 == ap_CS_fsm_state10) & (icmp_ln38_fu_304_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state11;
            end
        end
        ap_ST_fsm_state11 : begin
            ap_NS_fsm = ap_ST_fsm_state10;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln21_fu_209_p2 = (i_fu_58 + 15'd1);

assign add_ln31_fu_274_p2 = (j_fu_78 + 15'd1);

assign add_ln38_fu_310_p2 = (k_fu_82 + 15'd1);

assign add_ln8_fu_244_p2 = (i_1_fu_74 + 15'd1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state10 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd10];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state8 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_state9 = ap_CS_fsm[32'd8];

assign ap_local_block = 1'b0;

assign ap_local_deadlock = 1'b0;

assign data_in_address0 = zext_ln21_fu_198_p1;

assign data_out1_address0 = zext_ln31_reg_392;

assign data_out1_d0 = mul_ln34_fu_290_p2;

assign data_out2_address0 = zext_ln38_reg_417;

assign data_out2_d0 = (temp3_q0 + shl_ln41_fu_321_p2);

assign icmp_ln21_fu_203_p2 = ((i_fu_58 == 15'd16384) ? 1'b1 : 1'b0);

assign icmp_ln31_fu_268_p2 = ((j_fu_78 == 15'd16384) ? 1'b1 : 1'b0);

assign icmp_ln38_fu_304_p2 = ((k_fu_82 == 15'd16384) ? 1'b1 : 1'b0);

assign icmp_ln8_fu_238_p2 = ((i_1_fu_74 == 15'd16384) ? 1'b1 : 1'b0);

assign mul_ln34_fu_290_p1 = 32'd22;

assign shl_ln41_fu_321_p2 = temp3_q0 << 32'd5;

assign zext_ln21_fu_198_p1 = i_fu_58;

assign zext_ln31_fu_263_p1 = j_fu_78;

assign zext_ln38_fu_299_p1 = k_fu_82;

assign zext_ln8_fu_233_p1 = i_1_fu_74;

always @ (posedge ap_clk) begin
    zext_ln21_reg_346[63:15] <= 49'b0000000000000000000000000000000000000000000000000;
    zext_ln8_reg_371[63:15] <= 49'b0000000000000000000000000000000000000000000000000;
    zext_ln31_reg_392[63:15] <= 49'b0000000000000000000000000000000000000000000000000;
    zext_ln38_reg_417[63:15] <= 49'b0000000000000000000000000000000000000000000000000;
end

endmodule //foo_m
