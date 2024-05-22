/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int arentEqual(signed short *llvm_cbe_expected_arr, signed short *llvm_cbe_actual_arr);
signed int main(void);
void apatb_lab3_z2_sw(signed short *, signed short *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[34] = " ERROR: expected=%d  actual=%d  \n";
static  char aesl_internal__OC_str1[30] = "----------Pass!------------ \n";
static  char aesl_internal__OC_str2[30] = "----------Fail!------------ \n";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

signed int arentEqual(signed short *llvm_cbe_expected_arr, signed short *llvm_cbe_actual_arr) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  signed short *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned short llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  signed short *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned short llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned short llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned short llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @arentEqual\n");
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__14;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 0, %%0 ], [ %%10, %%3  for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
  if ((((signed int )llvm_cbe_storemerge) < ((signed int )4096u))) {
    goto llvm_cbe_tmp__15;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__15:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge to i64, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i16* %%expected_arr, i64 %%4, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__2 = (signed short *)(&llvm_cbe_expected_arr[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i16* %%5, align 2, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__3 = (unsigned short )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i16* %%actual_arr, i64 %%4, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__4 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i16* %%7, align 2, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__5 = (unsigned short )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge, 1, !dbg !4 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__3&65535U) == (llvm_cbe_tmp__5&65535U))) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__14;
  } else {
    goto llvm_cbe_tmp__16;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__16:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__7 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct._iobuf* %%12, i64 1, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__8 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__7[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i16* %%5, align 2, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__9 = (unsigned short )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i16 %%14 to i32, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__10 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i16* %%7, align 2, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__11 = (unsigned short )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = sext i16 %%16 to i32, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__12 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%13, i8* getelementptr inbounds ([34 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%15, i32 %%17) nounwind, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_32_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__8, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 34
#endif
])), llvm_cbe_tmp__10, llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__10);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__12);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__13);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 1, %%11 ], [ 0, %%1  for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @arentEqual}\n");
  return llvm_cbe_storemerge1;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_in_count = 0;
  signed short llvm_cbe_in[4096];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  signed short llvm_cbe_out[4096];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_expected_ar_count = 0;
  signed short llvm_cbe_expected_ar[4096];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  signed short *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  signed short *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  signed short *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned short llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  signed short *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  signed short *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  signed short *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  signed short *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned short llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  signed short *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned short llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned short llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [4096 x i16]* %%in, i64 0, i64 0, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__17 = (signed short *)(&llvm_cbe_in[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [4096 x i16]* %%out, i64 0, i64 0, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__18 = (signed short *)(&llvm_cbe_out[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [4096 x i16]* %%expected_ar, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__19 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%27, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__39);
}
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__47:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 @arentEqual(i16* %%2, i16* %%3), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__38 = (unsigned int )arentEqual((signed short *)llvm_cbe_tmp__18, (signed short *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add nsw i32 %%storemerge8, 1, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
  if (((llvm_cbe_tmp__39&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe_tmp__48;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__39;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ 0, %%15 ], [ %%24, %%16  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = sext i32 %%storemerge34 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__30 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge34);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [4096 x i16]* %%in, i64 0, i64 %%17, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__31 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__30))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__30));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__30) < 4096)) fprintf(stderr, "%s:%d: warning: Read access out of array 'in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i16* %%18, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__32 = (unsigned short )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i16 %%19 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__33 = (unsigned long long )((signed long long )(signed short )llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [4096 x i16]* %%expected_ar, i64 0, i64 %%20, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__34 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__33))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__33));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__33) < 4096)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_ar' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i16* %%21, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__35 = (unsigned short )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i16 %%22, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__36 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__35&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__36&65535ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__33) < 4096 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%23, i16* %%21, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
  *llvm_cbe_tmp__34 = llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%storemerge34, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__37 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__37&4294967295ull)));
  if (((llvm_cbe_tmp__37&4294967295U) == (4096u&4294967295U))) {
    goto llvm_cbe_tmp__47;
  } else {
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe_tmp__49;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  call void @apatb_lab3_z2_sw(i16* %%1, i16* %%2) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  apatb_lab3_z2_sw((signed short *)llvm_cbe_tmp__17, (signed short *)llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%14, %%.preheader ], [ 0, %%4  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%storemerge25 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge25);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [4096 x i16]* %%out, i64 0, i64 %%11, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__27 = (signed short *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__26))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__26) < 4096 && "Write access out of array 'out' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%12, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  *llvm_cbe_tmp__27 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [4096 x i16]* %%expected_ar, i64 0, i64 %%11, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__28 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__26))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__26) < 4096 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%13, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  *llvm_cbe_tmp__28 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge25, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  if (((llvm_cbe_tmp__29&4294967295U) == (4096u&4294967295U))) {
    goto llvm_cbe_tmp__50;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%10, %%4  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__20 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = srem i32 %%5, 4096, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__21 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__20) % ((signed int )4096u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i32 %%6 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__22 = (unsigned short )((unsigned short )llvm_cbe_tmp__21&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%storemerge17 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [4096 x i16]* %%in, i64 0, i64 %%8, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__24 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__23))
#ifdef AESL_BC_SIM
 % 4096
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__23) < 4096 && "Write access out of array 'in' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%7, i16* %%9, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_64_count);
  *llvm_cbe_tmp__24 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge17, 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
  if (((llvm_cbe_tmp__25&4294967295U) == (4096u&4294967295U))) {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe_tmp__46;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
llvm_cbe_tmp__48:
  if (((llvm_cbe_tmp__38&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__51;
  } else {
    goto llvm_cbe_tmp__52;
  }

llvm_cbe_tmp__51:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__40 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct._iobuf* %%31, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__41 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__40[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str1, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%32), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  fwrite(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__42);
}
  goto llvm_cbe_tmp__53;

llvm_cbe_tmp__52:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__43 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct._iobuf* %%35, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__44 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__43[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str2, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%36), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  fwrite(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__45);
}
  goto llvm_cbe_tmp__53;

llvm_cbe_tmp__53:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_tmp__38;
}

