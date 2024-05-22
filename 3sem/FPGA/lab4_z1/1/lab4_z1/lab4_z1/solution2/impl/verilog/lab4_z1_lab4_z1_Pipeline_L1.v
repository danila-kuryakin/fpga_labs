// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module lab4_z1_lab4_z1_Pipeline_L1 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        resultVecror_arr_load,
        resultVecror_arr_address0,
        resultVecror_arr_ce0,
        resultVecror_arr_we0,
        resultVecror_arr_d0,
        zext_ln9,
        firstVector_arr_address0,
        firstVector_arr_ce0,
        firstVector_arr_q0,
        conv4
);

parameter    ap_ST_fsm_pp0_stage0 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [31:0] resultVecror_arr_load;
output  [1:0] resultVecror_arr_address0;
output   resultVecror_arr_ce0;
output   resultVecror_arr_we0;
output  [31:0] resultVecror_arr_d0;
input  [1:0] zext_ln9;
output  [1:0] firstVector_arr_address0;
output   firstVector_arr_ce0;
input  [15:0] firstVector_arr_q0;
input  [15:0] conv4;

reg ap_idle;
reg resultVecror_arr_ce0;
reg resultVecror_arr_we0;
reg firstVector_arr_ce0;

(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_enable_reg_pp0_iter2;
reg    ap_enable_reg_pp0_iter3;
reg    ap_enable_reg_pp0_iter4;
reg    ap_idle_pp0;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state2_pp0_stage0_iter1;
wire    ap_block_state3_pp0_stage0_iter2;
wire    ap_block_state4_pp0_stage0_iter3;
wire    ap_block_state5_pp0_stage0_iter4;
wire    ap_block_pp0_stage0_subdone;
wire   [0:0] icmp_ln12_fu_119_p2;
reg    ap_condition_exit_pp0_iter0_stage0;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
wire    ap_block_pp0_stage0_11001;
wire  signed [31:0] conv4_cast_fu_97_p1;
reg  signed [31:0] conv4_cast_reg_181;
reg   [1:0] resultVecror_arr_addr_reg_186;
reg   [1:0] resultVecror_arr_addr_reg_186_pp0_iter1_reg;
reg   [1:0] resultVecror_arr_addr_reg_186_pp0_iter2_reg;
reg   [1:0] resultVecror_arr_addr_reg_186_pp0_iter3_reg;
wire   [0:0] icmp_ln12_1_fu_136_p2;
reg   [0:0] icmp_ln12_1_reg_200;
reg   [0:0] icmp_ln12_1_reg_200_pp0_iter1_reg;
reg   [0:0] icmp_ln12_1_reg_200_pp0_iter2_reg;
reg   [0:0] icmp_ln12_1_reg_200_pp0_iter3_reg;
wire   [63:0] zext_ln9_cast_fu_101_p1;
wire    ap_block_pp0_stage0;
wire   [63:0] zext_ln12_fu_131_p1;
reg   [31:0] add3_fu_46;
wire   [31:0] grp_fu_158_p3;
reg   [31:0] ap_sig_allocacmp_add3_load;
wire    ap_loop_init;
reg   [2:0] j_fu_50;
wire   [2:0] add_ln12_fu_125_p2;
reg   [2:0] ap_sig_allocacmp_j_1;
wire  signed [15:0] grp_fu_158_p1;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg    ap_loop_exit_ready_pp0_iter1_reg;
reg    ap_loop_exit_ready_pp0_iter2_reg;
reg    ap_loop_exit_ready_pp0_iter3_reg;
reg   [0:0] ap_NS_fsm;
wire    ap_enable_pp0;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 1'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter3 = 1'b0;
#0 ap_enable_reg_pp0_iter4 = 1'b0;
#0 ap_done_reg = 1'b0;
end

lab4_z1_mac_muladd_16s_16s_32ns_32_4_1 #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 16 ),
    .din1_WIDTH( 16 ),
    .din2_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mac_muladd_16s_16s_32ns_32_4_1_U1(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(firstVector_arr_q0),
    .din1(grp_fu_158_p1),
    .din2(ap_sig_allocacmp_add3_load),
    .ce(1'b1),
    .dout(grp_fu_158_p3)
);

lab4_z1_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter0_stage0),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_loop_exit_ready_pp0_iter3_reg == 1'b1))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b1 == ap_condition_exit_pp0_iter0_stage0)) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter1 <= ap_start_int;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter3 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter3 <= ap_enable_reg_pp0_iter2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter4 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter4 <= ap_enable_reg_pp0_iter3;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
            add3_fu_46 <= resultVecror_arr_load;
        end else if ((ap_enable_reg_pp0_iter4 == 1'b1)) begin
            add3_fu_46 <= grp_fu_158_p3;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        if (((icmp_ln12_fu_119_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
            j_fu_50 <= add_ln12_fu_125_p2;
        end else if ((ap_loop_init == 1'b1)) begin
            j_fu_50 <= 3'd0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_loop_exit_ready_pp0_iter1_reg <= ap_loop_exit_ready;
        ap_loop_exit_ready_pp0_iter2_reg <= ap_loop_exit_ready_pp0_iter1_reg;
        conv4_cast_reg_181 <= conv4_cast_fu_97_p1;
        icmp_ln12_1_reg_200_pp0_iter1_reg <= icmp_ln12_1_reg_200;
        resultVecror_arr_addr_reg_186 <= zext_ln9_cast_fu_101_p1;
        resultVecror_arr_addr_reg_186_pp0_iter1_reg <= resultVecror_arr_addr_reg_186;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        ap_loop_exit_ready_pp0_iter3_reg <= ap_loop_exit_ready_pp0_iter2_reg;
        icmp_ln12_1_reg_200_pp0_iter2_reg <= icmp_ln12_1_reg_200_pp0_iter1_reg;
        icmp_ln12_1_reg_200_pp0_iter3_reg <= icmp_ln12_1_reg_200_pp0_iter2_reg;
        resultVecror_arr_addr_reg_186_pp0_iter2_reg <= resultVecror_arr_addr_reg_186_pp0_iter1_reg;
        resultVecror_arr_addr_reg_186_pp0_iter3_reg <= resultVecror_arr_addr_reg_186_pp0_iter2_reg;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln12_fu_119_p2 == 1'd0) & (1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        icmp_ln12_1_reg_200 <= icmp_ln12_1_fu_136_p2;
    end
end

always @ (*) begin
    if (((icmp_ln12_fu_119_p2 == 1'd1) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_condition_exit_pp0_iter0_stage0 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter0_stage0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_loop_exit_ready_pp0_iter3_reg == 1'b1))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if (((ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_start_int == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter4 == 1'b0) & (ap_enable_reg_pp0_iter3 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter4 == 1'b1))) begin
        ap_sig_allocacmp_add3_load = grp_fu_158_p3;
    end else begin
        ap_sig_allocacmp_add3_load = add3_fu_46;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_loop_init == 1'b1))) begin
        ap_sig_allocacmp_j_1 = 3'd0;
    end else begin
        ap_sig_allocacmp_j_1 = j_fu_50;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        firstVector_arr_ce0 = 1'b1;
    end else begin
        firstVector_arr_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter4 == 1'b1))) begin
        resultVecror_arr_ce0 = 1'b1;
    end else begin
        resultVecror_arr_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter4 == 1'b1) & (icmp_ln12_1_reg_200_pp0_iter3_reg == 1'd1))) begin
        resultVecror_arr_we0 = 1'b1;
    end else begin
        resultVecror_arr_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln12_fu_125_p2 = (ap_sig_allocacmp_j_1 + 3'd1);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage0_iter3 = ~(1'b1 == 1'b1);

assign ap_block_state5_pp0_stage0_iter4 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_enable_reg_pp0_iter0 = ap_start_int;

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage0;

assign conv4_cast_fu_97_p1 = $signed(conv4);

assign firstVector_arr_address0 = zext_ln12_fu_131_p1;

assign grp_fu_158_p1 = conv4_cast_reg_181;

assign icmp_ln12_1_fu_136_p2 = ((add_ln12_fu_125_p2 == 3'd4) ? 1'b1 : 1'b0);

assign icmp_ln12_fu_119_p2 = ((ap_sig_allocacmp_j_1 == 3'd4) ? 1'b1 : 1'b0);

assign resultVecror_arr_address0 = resultVecror_arr_addr_reg_186_pp0_iter3_reg;

assign resultVecror_arr_d0 = grp_fu_158_p3;

assign zext_ln12_fu_131_p1 = ap_sig_allocacmp_j_1;

assign zext_ln9_cast_fu_101_p1 = zext_ln9;

endmodule //lab4_z1_lab4_z1_Pipeline_L1
