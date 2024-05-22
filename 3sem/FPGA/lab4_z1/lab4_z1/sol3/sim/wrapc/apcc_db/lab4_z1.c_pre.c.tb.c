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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void lab4_z1(signed short *llvm_cbe_firstVector_arr, signed short *llvm_cbe_secondVector_arr, signed int *llvm_cbe_resultVecror_arr);
void lab4_z1_hw_stub(signed short *llvm_cbe_firstVector_arr, signed short *llvm_cbe_secondVector_arr, signed int *llvm_cbe_resultVecror_arr);
void apatb_lab4_z1_sw(signed short *llvm_cbe_firstVector_arr, signed short *llvm_cbe_secondVector_arr, signed int *llvm_cbe_resultVecror_arr);
void apatb_lab4_z1_ir(signed short *, signed short *, signed int *);


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

void lab4_z1(signed short *llvm_cbe_firstVector_arr, signed short *llvm_cbe_secondVector_arr, signed int *llvm_cbe_resultVecror_arr) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  signed short *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  signed int *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned short llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned short llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  signed short *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned short llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned short llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  signed short *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned short llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned short llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  signed short *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned short llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned short llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @lab4_z1\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%32, %%.preheader  for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge3 to i64, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i16* %%secondVector_arr, i64 %%1, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = (signed short *)(&llvm_cbe_secondVector_arr[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i32* %%resultVecror_arr, i64 %%1, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (signed int *)(&llvm_cbe_resultVecror_arr[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i16* %%firstVector_arr, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__4 = (unsigned short )*llvm_cbe_firstVector_arr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i16 %%4 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__5 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i16* %%2, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__6 = (unsigned short )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i16 %%6 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__7 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul nsw i32 %%7, %%5, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_tmp__7&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%3, align 4, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__9 = (unsigned int )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%8, %%9, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_tmp__8&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__9&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%10, i32* %%3, align 4, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_26_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i16* %%firstVector_arr, i64 1, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__11 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i16* %%11, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__12 = (unsigned short )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i16 %%12 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__13 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i16* %%2, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__14 = (unsigned short )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i16 %%14 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__15 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul nsw i32 %%15, %%13, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__13&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%16, %%10, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__10&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%17, i32* %%3, align 4, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_38_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i16* %%firstVector_arr, i64 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__18 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i16* %%18, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__19 = (unsigned short )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i16 %%19 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__20 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i16* %%2, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__21 = (unsigned short )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i16 %%21 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__22 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = mul nsw i32 %%22, %%20, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__23 = (unsigned int )((unsigned int )(llvm_cbe_tmp__22&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__20&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__23&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%23, %%17, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__23&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%24, i32* %%3, align 4, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_50_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i16* %%firstVector_arr, i64 3, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__25 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i16* %%25, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__26 = (unsigned short )*llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i16 %%26 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__27 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i16* %%2, align 2, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__28 = (unsigned short )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i16 %%28 to i32, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__29 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = mul nsw i32 %%29, %%27, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_tmp__29&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__27&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%30, %%24, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__30&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__24&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%31, i32* %%3, align 4, !dbg !3 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_62_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge3, 1, !dbg !4 for 0x%I64xth hint within @lab4_z1  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
  if (((llvm_cbe_tmp__32&4294967295U) == (4u&4294967295U))) {
    goto llvm_cbe_tmp__33;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__32;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__33:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @lab4_z1}\n");
  return;
}


void lab4_z1_hw_stub(signed short *llvm_cbe_firstVector_arr, signed short *llvm_cbe_secondVector_arr, signed int *llvm_cbe_resultVecror_arr) {
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @lab4_z1_hw_stub\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @lab4_z1(i16* %%firstVector_arr, i16* %%secondVector_arr, i32* %%resultVecror_arr), !dbg !4 for 0x%I64xth hint within @lab4_z1_hw_stub  --> \n", ++aesl_llvm_cbe_81_count);
   /*tail*/ lab4_z1((signed short *)llvm_cbe_firstVector_arr, (signed short *)llvm_cbe_secondVector_arr, (signed int *)llvm_cbe_resultVecror_arr);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @lab4_z1_hw_stub}\n");
  return;
}


void apatb_lab4_z1_sw(signed short *llvm_cbe_firstVector_arr, signed short *llvm_cbe_secondVector_arr, signed int *llvm_cbe_resultVecror_arr) {
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @apatb_lab4_z1_sw\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @apatb_lab4_z1_ir(i16* %%firstVector_arr, i16* %%secondVector_arr, i32* %%resultVecror_arr) nounwind, !dbg !4 for 0x%I64xth hint within @apatb_lab4_z1_sw  --> \n", ++aesl_llvm_cbe_89_count);
   /*tail*/ apatb_lab4_z1_ir((signed short *)llvm_cbe_firstVector_arr, (signed short *)llvm_cbe_secondVector_arr, (signed int *)llvm_cbe_resultVecror_arr);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @apatb_lab4_z1_sw}\n");
  return;
}

