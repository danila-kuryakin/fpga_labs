; ModuleID = 'D:/Labs/3sem/FPGA/lab2_z0/lab2_z0/lab2_z0_ex/ex_sol5/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: argmemonly noinline
define void @apatb_lab2_z0_ir(i16* %in_a, i16* %in_b, i32* %res) local_unnamed_addr #0 {
entry:
  %in_a_copy = alloca [3 x i16], align 512
  %in_b_copy = alloca [3 x i16], align 512
  %res_copy = alloca [3 x i32], align 512
  %0 = bitcast i16* %in_a to [3 x i16]*
  %1 = bitcast i16* %in_b to [3 x i16]*
  %2 = bitcast i32* %res to [3 x i32]*
  call fastcc void @copy_in([3 x i16]* %0, [3 x i16]* nonnull align 512 %in_a_copy, [3 x i16]* %1, [3 x i16]* nonnull align 512 %in_b_copy, [3 x i32]* %2, [3 x i32]* nonnull align 512 %res_copy)
  %3 = getelementptr inbounds [3 x i16], [3 x i16]* %in_a_copy, i32 0, i32 0
  %4 = getelementptr inbounds [3 x i16], [3 x i16]* %in_b_copy, i32 0, i32 0
  %5 = getelementptr inbounds [3 x i32], [3 x i32]* %res_copy, i32 0, i32 0
  call void @apatb_lab2_z0_hw(i16* %3, i16* %4, i32* %5)
  call fastcc void @copy_out([3 x i16]* %0, [3 x i16]* nonnull align 512 %in_a_copy, [3 x i16]* %1, [3 x i16]* nonnull align 512 %in_b_copy, [3 x i32]* %2, [3 x i32]* nonnull align 512 %res_copy)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_in([3 x i16]* readonly, [3 x i16]* noalias align 512, [3 x i16]* readonly, [3 x i16]* noalias align 512, [3 x i32]* readonly, [3 x i32]* noalias align 512) unnamed_addr #1 {
entry:
  call fastcc void @onebyonecpy_hls.p0a3i16([3 x i16]* align 512 %1, [3 x i16]* %0)
  call fastcc void @onebyonecpy_hls.p0a3i16([3 x i16]* align 512 %3, [3 x i16]* %2)
  call fastcc void @onebyonecpy_hls.p0a3i32([3 x i32]* align 512 %5, [3 x i32]* %4)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a3i16([3 x i16]* noalias align 512, [3 x i16]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [3 x i16]* %0, null
  %3 = icmp eq [3 x i16]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [3 x i16], [3 x i16]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [3 x i16], [3 x i16]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i16, i16* %src.addr, align 2
  store i16 %5, i16* %dst.addr, align 2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 3
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a3i32([3 x i32]* noalias align 512, [3 x i32]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [3 x i32]* %0, null
  %3 = icmp eq [3 x i32]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [3 x i32], [3 x i32]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [3 x i32], [3 x i32]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i32, i32* %src.addr, align 4
  store i32 %5, i32* %dst.addr, align 4
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 3
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_out([3 x i16]*, [3 x i16]* noalias readonly align 512, [3 x i16]*, [3 x i16]* noalias readonly align 512, [3 x i32]*, [3 x i32]* noalias readonly align 512) unnamed_addr #3 {
entry:
  call fastcc void @onebyonecpy_hls.p0a3i16([3 x i16]* %0, [3 x i16]* align 512 %1)
  call fastcc void @onebyonecpy_hls.p0a3i16([3 x i16]* %2, [3 x i16]* align 512 %3)
  call fastcc void @onebyonecpy_hls.p0a3i32([3 x i32]* %4, [3 x i32]* align 512 %5)
  ret void
}

declare void @apatb_lab2_z0_hw(i16*, i16*, i32*)

define void @lab2_z0_hw_stub_wrapper(i16*, i16*, i32*) #4 {
entry:
  %3 = bitcast i16* %0 to [3 x i16]*
  %4 = bitcast i16* %1 to [3 x i16]*
  %5 = bitcast i32* %2 to [3 x i32]*
  call void @copy_out([3 x i16]* null, [3 x i16]* %3, [3 x i16]* null, [3 x i16]* %4, [3 x i32]* null, [3 x i32]* %5)
  %6 = bitcast [3 x i16]* %3 to i16*
  %7 = bitcast [3 x i16]* %4 to i16*
  %8 = bitcast [3 x i32]* %5 to i32*
  call void @lab2_z0_hw_stub(i16* %6, i16* %7, i32* %8)
  call void @copy_in([3 x i16]* null, [3 x i16]* %3, [3 x i16]* null, [3 x i16]* %4, [3 x i32]* null, [3 x i32]* %5)
  ret void
}

declare void @lab2_z0_hw_stub(i16*, i16*, i32*)

attributes #0 = { argmemonly noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
