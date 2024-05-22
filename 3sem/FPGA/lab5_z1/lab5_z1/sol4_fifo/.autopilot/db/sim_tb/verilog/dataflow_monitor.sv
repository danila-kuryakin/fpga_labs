
`include "dump_file_agent.svh"
`include "csv_file_dump.svh"
`include "sample_agent.svh"
`include "loop_sample_agent.svh"
`include "sample_manager.svh"
`include "nodf_module_interface.svh"
`include "nodf_module_monitor.svh"
`include "df_fifo_interface.svh"
`include "df_fifo_monitor.svh"
`include "df_process_interface.svh"
`include "df_process_monitor.svh"
`include "seq_loop_interface.svh"
`include "seq_loop_monitor.svh"
`timescale 1ns/1ps

// top module for dataflow related monitors
module dataflow_monitor(
input logic clock,
input logic reset,
input logic finish
);

    df_fifo_intf fifo_intf_1(clock,reset);
    assign fifo_intf_1.rd_en = AESL_inst_foo_m.temp1_U.if_read;
    assign fifo_intf_1.wr_en = AESL_inst_foo_m.temp1_U.if_write;
    assign fifo_intf_1.fifo_rd_block = ~(AESL_inst_foo_m.split_U0.in_r_blk_n);
    assign fifo_intf_1.fifo_wr_block = ~(AESL_inst_foo_m.Loop_Loop1_proc_U0.temp1_blk_n);
    assign fifo_intf_1.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump fifo_csv_dumper_1;
    csv_file_dump cstatus_csv_dumper_1;
    df_fifo_monitor fifo_monitor_1;
    df_fifo_intf fifo_intf_2(clock,reset);
    assign fifo_intf_2.rd_en = AESL_inst_foo_m.temp2_U.if_read;
    assign fifo_intf_2.wr_en = AESL_inst_foo_m.temp2_U.if_write;
    assign fifo_intf_2.fifo_rd_block = ~(AESL_inst_foo_m.Loop_Loop2_proc_U0.temp2_blk_n);
    assign fifo_intf_2.fifo_wr_block = ~(AESL_inst_foo_m.split_U0.out1_blk_n);
    assign fifo_intf_2.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump fifo_csv_dumper_2;
    csv_file_dump cstatus_csv_dumper_2;
    df_fifo_monitor fifo_monitor_2;
    df_fifo_intf fifo_intf_3(clock,reset);
    assign fifo_intf_3.rd_en = AESL_inst_foo_m.temp3_U.if_read;
    assign fifo_intf_3.wr_en = AESL_inst_foo_m.temp3_U.if_write;
    assign fifo_intf_3.fifo_rd_block = ~(AESL_inst_foo_m.Loop_Loop3_proc_U0.temp3_blk_n);
    assign fifo_intf_3.fifo_wr_block = ~(AESL_inst_foo_m.split_U0.out2_blk_n);
    assign fifo_intf_3.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump fifo_csv_dumper_3;
    csv_file_dump cstatus_csv_dumper_3;
    df_fifo_monitor fifo_monitor_3;

    df_process_intf process_intf_1(clock,reset);
    assign process_intf_1.ap_start = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_start;
    assign process_intf_1.ap_ready = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_ready;
    assign process_intf_1.ap_done = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_done;
    assign process_intf_1.ap_continue = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_continue;
    assign process_intf_1.real_start = AESL_inst_foo_m.Loop_Loop1_proc_U0.real_start;
    assign process_intf_1.pin_stall = 1'b0;
    assign process_intf_1.pout_stall = 1'b0 | ~AESL_inst_foo_m.Loop_Loop1_proc_U0.temp1_blk_n;
    assign process_intf_1.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump pstall_csv_dumper_1;
    csv_file_dump pstatus_csv_dumper_1;
    df_process_monitor process_monitor_1;
    df_process_intf process_intf_2(clock,reset);
    assign process_intf_2.ap_start = AESL_inst_foo_m.split_U0.ap_start;
    assign process_intf_2.ap_ready = AESL_inst_foo_m.split_U0.ap_ready;
    assign process_intf_2.ap_done = AESL_inst_foo_m.split_U0.ap_done;
    assign process_intf_2.ap_continue = AESL_inst_foo_m.split_U0.ap_continue;
    assign process_intf_2.real_start = AESL_inst_foo_m.split_U0.real_start;
    assign process_intf_2.pin_stall = 1'b0 | ~AESL_inst_foo_m.split_U0.in_r_blk_n;
    assign process_intf_2.pout_stall = 1'b0 | ~AESL_inst_foo_m.split_U0.out1_blk_n | ~AESL_inst_foo_m.split_U0.out2_blk_n;
    assign process_intf_2.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump pstall_csv_dumper_2;
    csv_file_dump pstatus_csv_dumper_2;
    df_process_monitor process_monitor_2;
    df_process_intf process_intf_3(clock,reset);
    assign process_intf_3.ap_start = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_start;
    assign process_intf_3.ap_ready = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_ready;
    assign process_intf_3.ap_done = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_done;
    assign process_intf_3.ap_continue = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_continue;
    assign process_intf_3.real_start = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_start;
    assign process_intf_3.pin_stall = 1'b0 | ~AESL_inst_foo_m.Loop_Loop2_proc_U0.temp2_blk_n;
    assign process_intf_3.pout_stall = 1'b0;
    assign process_intf_3.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump pstall_csv_dumper_3;
    csv_file_dump pstatus_csv_dumper_3;
    df_process_monitor process_monitor_3;
    df_process_intf process_intf_4(clock,reset);
    assign process_intf_4.ap_start = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_start;
    assign process_intf_4.ap_ready = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_ready;
    assign process_intf_4.ap_done = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_done;
    assign process_intf_4.ap_continue = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_continue;
    assign process_intf_4.real_start = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_start;
    assign process_intf_4.pin_stall = 1'b0 | ~AESL_inst_foo_m.Loop_Loop3_proc_U0.temp3_blk_n;
    assign process_intf_4.pout_stall = 1'b0;
    assign process_intf_4.finish = finish | deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock;
    csv_file_dump pstall_csv_dumper_4;
    csv_file_dump pstatus_csv_dumper_4;
    df_process_monitor process_monitor_4;

    nodf_module_intf module_intf_1(clock,reset);
    assign module_intf_1.ap_start = AESL_inst_foo_m.ap_start;
    assign module_intf_1.ap_ready = AESL_inst_foo_m.ap_ready;
    assign module_intf_1.ap_done = AESL_inst_foo_m.ap_done;
    assign module_intf_1.ap_continue = 1'b1;
    assign module_intf_1.finish = finish;
    csv_file_dump mstatus_csv_dumper_1;
    nodf_module_monitor module_monitor_1;

    seq_loop_intf#(5) seq_loop_intf_1(clock,reset);
    assign seq_loop_intf_1.pre_loop_state0 = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_1.pre_states_valid = 1'b1;
    assign seq_loop_intf_1.post_loop_state0 = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_1.post_states_valid = 1'b1;
    assign seq_loop_intf_1.quit_loop_state0 = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_1.quit_states_valid = 1'b1;
    assign seq_loop_intf_1.cur_state = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_CS_fsm;
    assign seq_loop_intf_1.iter_start_state = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_1.iter_end_state0 = AESL_inst_foo_m.Loop_Loop1_proc_U0.ap_ST_fsm_state5;
    assign seq_loop_intf_1.iter_end_states_valid = 1'b1;
    assign seq_loop_intf_1.one_state_loop = 1'b0;
    assign seq_loop_intf_1.one_state_block = 1'b0;
    assign seq_loop_intf_1.finish = finish;
    csv_file_dump seq_loop_csv_dumper_1;
    seq_loop_monitor #(5) seq_loop_monitor_1;
    seq_loop_intf#(3) seq_loop_intf_2(clock,reset);
    assign seq_loop_intf_2.pre_loop_state0 = AESL_inst_foo_m.split_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_2.pre_states_valid = 1'b1;
    assign seq_loop_intf_2.post_loop_state0 = AESL_inst_foo_m.split_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_2.post_states_valid = 1'b1;
    assign seq_loop_intf_2.quit_loop_state0 = AESL_inst_foo_m.split_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_2.quit_states_valid = 1'b1;
    assign seq_loop_intf_2.cur_state = AESL_inst_foo_m.split_U0.ap_CS_fsm;
    assign seq_loop_intf_2.iter_start_state = AESL_inst_foo_m.split_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_2.iter_end_state0 = AESL_inst_foo_m.split_U0.ap_ST_fsm_state3;
    assign seq_loop_intf_2.iter_end_states_valid = 1'b1;
    assign seq_loop_intf_2.one_state_loop = 1'b0;
    assign seq_loop_intf_2.one_state_block = 1'b0;
    assign seq_loop_intf_2.finish = finish;
    csv_file_dump seq_loop_csv_dumper_2;
    seq_loop_monitor #(3) seq_loop_monitor_2;
    seq_loop_intf#(4) seq_loop_intf_3(clock,reset);
    assign seq_loop_intf_3.pre_loop_state0 = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_3.pre_states_valid = 1'b1;
    assign seq_loop_intf_3.post_loop_state0 = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_3.post_states_valid = 1'b1;
    assign seq_loop_intf_3.quit_loop_state0 = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_3.quit_states_valid = 1'b1;
    assign seq_loop_intf_3.cur_state = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_CS_fsm;
    assign seq_loop_intf_3.iter_start_state = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_3.iter_end_state0 = AESL_inst_foo_m.Loop_Loop2_proc_U0.ap_ST_fsm_state4;
    assign seq_loop_intf_3.iter_end_states_valid = 1'b1;
    assign seq_loop_intf_3.one_state_loop = 1'b0;
    assign seq_loop_intf_3.one_state_block = 1'b0;
    assign seq_loop_intf_3.finish = finish;
    csv_file_dump seq_loop_csv_dumper_3;
    seq_loop_monitor #(4) seq_loop_monitor_3;
    seq_loop_intf#(3) seq_loop_intf_4(clock,reset);
    assign seq_loop_intf_4.pre_loop_state0 = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_4.pre_states_valid = 1'b1;
    assign seq_loop_intf_4.post_loop_state0 = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_ST_fsm_state1;
    assign seq_loop_intf_4.post_states_valid = 1'b1;
    assign seq_loop_intf_4.quit_loop_state0 = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_4.quit_states_valid = 1'b1;
    assign seq_loop_intf_4.cur_state = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_CS_fsm;
    assign seq_loop_intf_4.iter_start_state = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_ST_fsm_state2;
    assign seq_loop_intf_4.iter_end_state0 = AESL_inst_foo_m.Loop_Loop3_proc_U0.ap_ST_fsm_state3;
    assign seq_loop_intf_4.iter_end_states_valid = 1'b1;
    assign seq_loop_intf_4.one_state_loop = 1'b0;
    assign seq_loop_intf_4.one_state_block = 1'b0;
    assign seq_loop_intf_4.finish = finish;
    csv_file_dump seq_loop_csv_dumper_4;
    seq_loop_monitor #(3) seq_loop_monitor_4;

    sample_manager sample_manager_inst;

initial begin
    sample_manager_inst = new;

    fifo_csv_dumper_1 = new("./depth1.csv");
    cstatus_csv_dumper_1 = new("./chan_status1.csv");
    fifo_monitor_1 = new(fifo_csv_dumper_1,fifo_intf_1,cstatus_csv_dumper_1);
    fifo_csv_dumper_2 = new("./depth2.csv");
    cstatus_csv_dumper_2 = new("./chan_status2.csv");
    fifo_monitor_2 = new(fifo_csv_dumper_2,fifo_intf_2,cstatus_csv_dumper_2);
    fifo_csv_dumper_3 = new("./depth3.csv");
    cstatus_csv_dumper_3 = new("./chan_status3.csv");
    fifo_monitor_3 = new(fifo_csv_dumper_3,fifo_intf_3,cstatus_csv_dumper_3);

    pstall_csv_dumper_1 = new("./stalling1.csv");
    pstatus_csv_dumper_1 = new("./status1.csv");
    process_monitor_1 = new(pstall_csv_dumper_1,process_intf_1,pstatus_csv_dumper_1);
    pstall_csv_dumper_2 = new("./stalling2.csv");
    pstatus_csv_dumper_2 = new("./status2.csv");
    process_monitor_2 = new(pstall_csv_dumper_2,process_intf_2,pstatus_csv_dumper_2);
    pstall_csv_dumper_3 = new("./stalling3.csv");
    pstatus_csv_dumper_3 = new("./status3.csv");
    process_monitor_3 = new(pstall_csv_dumper_3,process_intf_3,pstatus_csv_dumper_3);
    pstall_csv_dumper_4 = new("./stalling4.csv");
    pstatus_csv_dumper_4 = new("./status4.csv");
    process_monitor_4 = new(pstall_csv_dumper_4,process_intf_4,pstatus_csv_dumper_4);

    mstatus_csv_dumper_1 = new("./module_status1.csv");
    module_monitor_1 = new(module_intf_1,mstatus_csv_dumper_1);



    seq_loop_csv_dumper_1 = new("./seq_loop_status1.csv");
    seq_loop_monitor_1 = new(seq_loop_intf_1,seq_loop_csv_dumper_1);
    seq_loop_csv_dumper_2 = new("./seq_loop_status2.csv");
    seq_loop_monitor_2 = new(seq_loop_intf_2,seq_loop_csv_dumper_2);
    seq_loop_csv_dumper_3 = new("./seq_loop_status3.csv");
    seq_loop_monitor_3 = new(seq_loop_intf_3,seq_loop_csv_dumper_3);
    seq_loop_csv_dumper_4 = new("./seq_loop_status4.csv");
    seq_loop_monitor_4 = new(seq_loop_intf_4,seq_loop_csv_dumper_4);


    sample_manager_inst.add_one_monitor(fifo_monitor_1);
    sample_manager_inst.add_one_monitor(fifo_monitor_2);
    sample_manager_inst.add_one_monitor(fifo_monitor_3);
    sample_manager_inst.add_one_monitor(process_monitor_1);
    sample_manager_inst.add_one_monitor(process_monitor_2);
    sample_manager_inst.add_one_monitor(process_monitor_3);
    sample_manager_inst.add_one_monitor(process_monitor_4);
    sample_manager_inst.add_one_monitor(module_monitor_1);
    sample_manager_inst.add_one_monitor(seq_loop_monitor_1);
    sample_manager_inst.add_one_monitor(seq_loop_monitor_2);
    sample_manager_inst.add_one_monitor(seq_loop_monitor_3);
    sample_manager_inst.add_one_monitor(seq_loop_monitor_4);
    
    fork
        sample_manager_inst.start_monitor();
        last_transaction_done;
    join
    disable fork;

    sample_manager_inst.start_dump();
end

    task last_transaction_done();
        wait(reset == 0);
        while(1) begin
            if (finish == 1'b1 || deadlock_detector.AESL_deadlock_report_unit_inst.find_df_deadlock == 1'b1)
                break;
            else
                @(posedge clock);
        end
    endtask


endmodule
