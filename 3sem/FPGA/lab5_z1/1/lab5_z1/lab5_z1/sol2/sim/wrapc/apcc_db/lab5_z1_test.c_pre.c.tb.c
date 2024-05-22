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
void initialize_int_arr(signed int *llvm_cbe_temp_arr);
void check_func(signed int *llvm_cbe_check_in1, signed int *llvm_cbe_check_in2, signed int llvm_cbe_scale, signed int *llvm_cbe_foo_m_out1, signed int *llvm_cbe_foo_m_out2);
signed int main(void);
signed int apatb_foo_m_sw();


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[59] = " ERROR: actual in1 = %d actual in2 = %d; expected in = %d\n";
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

void initialize_int_arr(signed int *llvm_cbe_temp_arr) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  signed int *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @initialize_int_arr\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__4;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%4, %%1  for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge1 to i64, !dbg !4 for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i32* %%temp_arr, i64 %%2, !dbg !4 for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__2 = (signed int *)(&llvm_cbe_temp_arr[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%3, align 4, !dbg !4 for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_10_count);
  *llvm_cbe_tmp__2 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge1, 1, !dbg !4 for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
  if (((llvm_cbe_tmp__3&4294967295U) == (16384u&4294967295U))) {
    goto llvm_cbe_tmp__5;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    goto llvm_cbe_tmp__4;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__5:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @initialize_int_arr}\n");
  return;
}


void check_func(signed int *llvm_cbe_check_in1, signed int *llvm_cbe_check_in2, signed int llvm_cbe_scale, signed int *llvm_cbe_foo_m_out1, signed int *llvm_cbe_foo_m_out2) {
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  signed int *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond4_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  signed int *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  signed int *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @check_func\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__20;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__20:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 0, %%0 ], [ %%8, %%1  for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge3 to i64, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__6 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i32* %%foo_m_out1, i64 %%2, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__7 = (signed int *)(&llvm_cbe_foo_m_out1[(((signed long long )llvm_cbe_tmp__6))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__8 = (unsigned int )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sdiv i32 %%4, 22, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__9 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__8) / ((signed int )22u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sdiv i32 %%5, %%scale, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__10 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__9) / ((signed int )llvm_cbe_scale)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i32* %%check_in1, i64 %%2, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_check_in1[(((signed long long )llvm_cbe_tmp__6))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__6));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%7, align 4, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%storemerge3, 1, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
  if (((llvm_cbe_tmp__12&4294967295U) == (16384u&4294967295U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__12;   /* for PHI node */
    goto llvm_cbe_tmp__20;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%15, %%.preheader ], [ 0, %%1  for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sext i32 %%storemerge12 to i64, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__13 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i32* %%foo_m_out2, i64 %%9, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__14 = (signed int *)(&llvm_cbe_foo_m_out2[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i32* %%10, align 4, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__15 = (unsigned int )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sdiv i32 %%11, 33, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__16 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__15) / ((signed int )33u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__16));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sdiv i32 %%12, %%scale, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__17 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__16) / ((signed int )llvm_cbe_scale)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__17));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i32* %%check_in2, i64 %%9, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__18 = (signed int *)(&llvm_cbe_check_in2[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%13, i32* %%14, align 4, !dbg !4 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_55_count);
  *llvm_cbe_tmp__18 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%storemerge12, 1, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
  if (((llvm_cbe_tmp__19&4294967295U) == (16384u&4294967295U))) {
    goto llvm_cbe_tmp__21;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__21:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @check_func}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_foo_m_in_count = 0;
  signed int llvm_cbe_foo_m_in[16384];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_foo_m_out1_count = 0;
  signed int llvm_cbe_foo_m_out1[16384];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_foo_m_out2_count = 0;
  signed int llvm_cbe_foo_m_out2[16384];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_check_in1_count = 0;
  signed int llvm_cbe_check_in1[16384];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_check_in2_count = 0;
  signed int llvm_cbe_check_in2[16384];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
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
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  signed int *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  signed int *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  signed int *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  signed int *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned int llvm_cbe_storemerge23;
  unsigned int llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned int llvm_cbe_tmp__36;
  unsigned int llvm_cbe_tmp__36__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  signed int *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  signed int *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  signed int *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  signed int *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__51;
  unsigned int llvm_cbe_tmp__51__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge14_2e_1;
  unsigned int llvm_cbe_storemerge14_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  signed int *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_2e_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge23_2e_1;
  unsigned int llvm_cbe_storemerge23_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned int llvm_cbe_tmp__68;
  unsigned int llvm_cbe_tmp__68__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed int *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  signed int *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  signed int *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  signed int *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  unsigned int llvm_cbe_tmp__83;
  unsigned int llvm_cbe_tmp__83__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [16384 x i32]* %%foo_m_in, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__22 = (signed int *)(&llvm_cbe_foo_m_in[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [16384 x i32]* %%foo_m_out1, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__23 = (signed int *)(&llvm_cbe_foo_m_out1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [16384 x i32]* %%foo_m_out2, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__24 = (signed int *)(&llvm_cbe_foo_m_out2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [16384 x i32]* %%check_in1, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__25 = (signed int *)(&llvm_cbe_check_in1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [16384 x i32]* %%check_in2, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__26 = (signed int *)(&llvm_cbe_check_in2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%1), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%2), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%3), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%4), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_83_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%5), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__27 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = srem i32 %%6, 15, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__28 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__27) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__28));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add nsw i32 %%7, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_tmp__28&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__85;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ 0, %%0 ], [ %%14, %%9  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__30 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = srem i32 %%10, 5, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__31 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__30) % ((signed int )5u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge14 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__32 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [16384 x i32]* %%foo_m_in, i64 0, i64 %%12, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__33 = (signed int *)(&llvm_cbe_foo_m_in[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__32) < 16384 && "Write access out of array 'foo_m_in' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%11, i32* %%13, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_100_count);
  *llvm_cbe_tmp__33 = llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add nsw i32 %%storemerge14, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__34 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__34&4294967295ull)));
  if (((llvm_cbe_tmp__34&4294967295U) == (16384u&4294967295U))) {
    goto llvm_cbe_tmp__86;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__34;   /* for PHI node */
    goto llvm_cbe_tmp__85;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call i32 bitcast (i32 (...)* @apatb_foo_m_sw to i32 (i32*, i32, i32*, i32*)*)(i32* %%1, i32 %%8, i32* %%2, i32* %%3) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  apatb_foo_m_sw((signed int *)llvm_cbe_tmp__22, llvm_cbe_tmp__29, (signed int *)llvm_cbe_tmp__23, (signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__29);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @check_func(i32* %%4, i32* %%5, i32 %%8, i32* %%2, i32* %%3), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  check_func((signed int *)llvm_cbe_tmp__25, (signed int *)llvm_cbe_tmp__26, llvm_cbe_tmp__29, (signed int *)llvm_cbe_tmp__23, (signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__29);
}
  llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__36__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__87;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__87:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i32 [ 0, %%15 ], [ %%39, %%37  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned int )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%X",llvm_cbe_storemerge23);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__52);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi i32 [ 0, %%15 ], [ %%38, %%37  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__36 = (unsigned int )llvm_cbe_tmp__36__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__36);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__51);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%storemerge23 to i64, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__37 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge23);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [16384 x i32]* %%foo_m_in, i64 0, i64 %%19, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__38 = (signed int *)(&llvm_cbe_foo_m_in[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__37) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'foo_m_in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__39 = (unsigned int )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [16384 x i32]* %%check_in1, i64 0, i64 %%19, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__40 = (signed int *)(&llvm_cbe_check_in1[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__37) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in1' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__41 = (unsigned int )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
  if (((llvm_cbe_tmp__39&4294967295U) == (llvm_cbe_tmp__41&4294967295U))) {
    goto llvm_cbe_tmp__88;
  } else {
    goto llvm_cbe_tmp__89;
  }

llvm_cbe_tmp__90:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = phi i32 [ 1, %%29 ], [ %%18, %%25  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__51 = (unsigned int )llvm_cbe_tmp__51__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__51);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add nsw i32 %%storemerge23, 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__52 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__52&4294967295ull)));
  if (((llvm_cbe_tmp__52&4294967295U) == (16384u&4294967295U))) {
    goto llvm_cbe_tmp__91;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__52;   /* for PHI node */
    llvm_cbe_tmp__36__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__51;   /* for PHI node */
    goto llvm_cbe_tmp__87;
  }

llvm_cbe_tmp__88:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [16384 x i32]* %%check_in2, i64 0, i64 %%19, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__42 = (signed int *)(&llvm_cbe_check_in2[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__37) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in2' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__43 = (unsigned int )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  if (((llvm_cbe_tmp__39&4294967295U) == (llvm_cbe_tmp__43&4294967295U))) {
    llvm_cbe_tmp__51__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__36;   /* for PHI node */
    goto llvm_cbe_tmp__90;
  } else {
    goto llvm_cbe_tmp__89;
  }

llvm_cbe_tmp__89:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__44 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct._iobuf* %%30, i64 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__45 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__44[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__37) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in1' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i32* %%22, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__46 = (unsigned int )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [16384 x i32]* %%check_in2, i64 0, i64 %%19, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__47 = (signed int *)(&llvm_cbe_check_in2[(((signed long long )llvm_cbe_tmp__37))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__37) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in2' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* %%33, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__48 = (unsigned int )*llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__37) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'foo_m_in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* %%20, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__49 = (unsigned int )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%31, i8* getelementptr inbounds ([59 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%32, i32 %%34, i32 %%35) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_141_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__45, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 59
#endif
])), llvm_cbe_tmp__46, llvm_cbe_tmp__48, llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__46);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__48);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__49);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
  llvm_cbe_tmp__51__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__90;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__91:
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%1), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_159_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%2), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_160_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%3), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_161_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%4), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_162_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%5), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_163_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__53 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__53);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = srem i32 %%41, 15, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__54 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__53) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__54));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add nsw i32 %%42, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_tmp__54&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
  llvm_cbe_storemerge14_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__92;

llvm_cbe_tmp__93:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__56 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds %%struct._iobuf* %%45, i64 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__57 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__56[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str1, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%46), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_177_count);
  fwrite(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__58);
}
  goto llvm_cbe_tmp__94;

llvm_cbe_tmp__95:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__59 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds %%struct._iobuf* %%49, i64 2, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__60 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__59[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str2, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%50), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_181_count);
  fwrite(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__61);
}
  goto llvm_cbe_tmp__94;

llvm_cbe_tmp__94:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_tmp__83;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__92:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.1 = phi i32 [ 0, %%40 ], [ %%58, %%53  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge14_2e_1_count);
  llvm_cbe_storemerge14_2e_1 = (unsigned int )llvm_cbe_storemerge14_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.1 = 0x%X",llvm_cbe_storemerge14_2e_1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__66);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__62 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = srem i32 %%54, 5, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__63 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__62) % ((signed int )5u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__63));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = sext i32 %%storemerge14.1 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__64 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge14_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds [16384 x i32]* %%foo_m_in, i64 0, i64 %%56, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__65 = (signed int *)(&llvm_cbe_foo_m_in[(((signed long long )llvm_cbe_tmp__64))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__64));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__64) < 16384 && "Write access out of array 'foo_m_in' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%55, i32* %%57, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_188_count);
  *llvm_cbe_tmp__65 = llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add nsw i32 %%storemerge14.1, 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__66 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__66&4294967295ull)));
  if (((llvm_cbe_tmp__66&4294967295U) == (16384u&4294967295U))) {
    goto llvm_cbe_tmp__96;
  } else {
    llvm_cbe_storemerge14_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__66;   /* for PHI node */
    goto llvm_cbe_tmp__92;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__96:
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = call i32 bitcast (i32 (...)* @apatb_foo_m_sw to i32 (i32*, i32, i32*, i32*)*)(i32* %%1, i32 %%43, i32* %%2, i32* %%3) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_195_count);
  apatb_foo_m_sw((signed int *)llvm_cbe_tmp__22, llvm_cbe_tmp__55, (signed int *)llvm_cbe_tmp__23, (signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__55);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__67);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @check_func(i32* %%4, i32* %%5, i32 %%43, i32* %%2, i32* %%3), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_196_count);
  check_func((signed int *)llvm_cbe_tmp__25, (signed int *)llvm_cbe_tmp__26, llvm_cbe_tmp__55, (signed int *)llvm_cbe_tmp__23, (signed int *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__55);
}
  llvm_cbe_storemerge23_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__68__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__51;   /* for PHI node */
  goto llvm_cbe_tmp__97;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__97:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.1 = phi i32 [ 0, %%59 ], [ %%83, %%81  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge23_2e_1_count);
  llvm_cbe_storemerge23_2e_1 = (unsigned int )llvm_cbe_storemerge23_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.1 = 0x%X",llvm_cbe_storemerge23_2e_1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__84);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = phi i32 [ %%38, %%59 ], [ %%82, %%81  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__68 = (unsigned int )llvm_cbe_tmp__68__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__68);
printf("\n = 0x%X",llvm_cbe_tmp__51);
printf("\n = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = sext i32 %%storemerge23.1 to i64, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__69 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge23_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [16384 x i32]* %%foo_m_in, i64 0, i64 %%63, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__70 = (signed int *)(&llvm_cbe_foo_m_in[(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'foo_m_in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load i32* %%64, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__71 = (unsigned int )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds [16384 x i32]* %%check_in1, i64 0, i64 %%63, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__72 = (signed int *)(&llvm_cbe_check_in1[(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in1' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = load i32* %%66, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__73 = (unsigned int )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
  if (((llvm_cbe_tmp__71&4294967295U) == (llvm_cbe_tmp__73&4294967295U))) {
    goto llvm_cbe_tmp__98;
  } else {
    goto llvm_cbe_tmp__99;
  }

llvm_cbe_tmp__100:
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = phi i32 [ 1, %%73 ], [ %%62, %%69  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__83 = (unsigned int )llvm_cbe_tmp__83__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__83);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__68);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = add nsw i32 %%storemerge23.1, 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__84 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__84&4294967295ull)));
  if (((llvm_cbe_tmp__84&4294967295U) == (16384u&4294967295U))) {
    goto llvm_cbe_tmp__101;
  } else {
    llvm_cbe_storemerge23_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__84;   /* for PHI node */
    llvm_cbe_tmp__68__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__83;   /* for PHI node */
    goto llvm_cbe_tmp__97;
  }

llvm_cbe_tmp__98:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds [16384 x i32]* %%check_in2, i64 0, i64 %%63, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__74 = (signed int *)(&llvm_cbe_check_in2[(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in2' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i32* %%70, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
  if (((llvm_cbe_tmp__71&4294967295U) == (llvm_cbe_tmp__75&4294967295U))) {
    llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__68;   /* for PHI node */
    goto llvm_cbe_tmp__100;
  } else {
    goto llvm_cbe_tmp__99;
  }

llvm_cbe_tmp__99:
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_223_count);
  llvm_cbe_tmp__76 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__76);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds %%struct._iobuf* %%74, i64 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__77 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__76[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in1' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load i32* %%66, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__78 = (unsigned int )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds [16384 x i32]* %%check_in2, i64 0, i64 %%63, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__79 = (signed int *)(&llvm_cbe_check_in2[(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 16384
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'check_in2' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load i32* %%77, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__80 = (unsigned int )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__69) < 16384)) fprintf(stderr, "%s:%d: warning: Read access out of array 'foo_m_in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load i32* %%64, align 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__81 = (unsigned int )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%75, i8* getelementptr inbounds ([59 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%76, i32 %%78, i32 %%79) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_229_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__77, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 59
#endif
])), llvm_cbe_tmp__78, llvm_cbe_tmp__80, llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__78);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__80);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__81);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__82);
}
  llvm_cbe_tmp__83__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__100;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__101:
  if (((llvm_cbe_tmp__83&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__93;
  } else {
    goto llvm_cbe_tmp__95;
  }

}

