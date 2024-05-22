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
void lab3_z2(signed short *, signed short *);


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
  if ((((signed int )llvm_cbe_storemerge) < ((signed int )8192u))) {
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
  signed short llvm_cbe_in[8192];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_out_count = 0;
  signed short llvm_cbe_out[8192];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_expected_ar_count = 0;
  signed short llvm_cbe_expected_ar[8192];    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned short llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  signed short *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned int llvm_cbe_tmp__25;
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
  static  unsigned long long aesl_llvm_cbe_exitcond10_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  signed short *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  signed short *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned int llvm_cbe_storemerge34;
  unsigned int llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  signed short *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned short llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  signed short *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  unsigned short llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned short llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge17_2e_1;
  unsigned int llvm_cbe_storemerge17_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned short llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  signed short *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_2e_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge25_2e_1;
  unsigned int llvm_cbe_storemerge25_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  signed short *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  signed short *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond9_2e_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge34_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge34_2e_1;
  unsigned int llvm_cbe_storemerge34_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  signed short *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned short llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed short *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned short llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned short llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge17_2e_2;
  unsigned int llvm_cbe_storemerge17_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  unsigned short llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned long long llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  signed short *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond10_2e_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge25_2e_2;
  unsigned int llvm_cbe_storemerge25_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  signed short *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  signed short *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond9_2e_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge34_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge34_2e_2;
  unsigned int llvm_cbe_storemerge34_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  unsigned long long llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  signed short *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  unsigned short llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  signed short *llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned short llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned short llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 0, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__17 = (signed short *)(&llvm_cbe_in[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [8192 x i16]* %%out, i64 0, i64 0, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__18 = (signed short *)(&llvm_cbe_out[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__19 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__83;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%9, %%3  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__20 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = srem i32 %%4, 8192, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__21 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__20) % ((signed int )8192u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__21));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i32 %%5 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__22 = (unsigned short )((unsigned short )llvm_cbe_tmp__21&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge17 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 %%7, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__24 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__23))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__23) < 8192 && "Write access out of array 'in' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%6, i16* %%8, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_63_count);
  *llvm_cbe_tmp__24 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge17, 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
  if (((llvm_cbe_tmp__25&4294967295U) == (8192u&4294967295U))) {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe_tmp__83;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%13, %%.preheader ], [ 0, %%3  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%storemerge25 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge25);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [8192 x i16]* %%out, i64 0, i64 %%10, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__27 = (signed short *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__26))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__26) < 8192 && "Write access out of array 'out' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%11, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_79_count);
  *llvm_cbe_tmp__27 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 %%10, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__28 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__26))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__26) < 8192 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%12, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_81_count);
  *llvm_cbe_tmp__28 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge25, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  if (((llvm_cbe_tmp__29&4294967295U) == (8192u&4294967295U))) {
    goto llvm_cbe_tmp__84;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__84:
if (AESL_DEBUG_TRACE)
printf("\n  call void @lab3_z2(i16* %%0, i16* %%1) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_95_count);
  lab3_z2((signed short *)llvm_cbe_tmp__17, (signed short *)llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__85;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i32 [ 0, %%14 ], [ %%23, %%15  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned int )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%X",llvm_cbe_storemerge34);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%storemerge34 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__30 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge34);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 %%16, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__31 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__30))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__30));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__30) < 8192)) fprintf(stderr, "%s:%d: warning: Read access out of array 'in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i16* %%17, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__32 = (unsigned short )*llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i16 %%18 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__33 = (unsigned long long )((signed long long )(signed short )llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 %%19, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__34 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__33))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__33));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__33) < 8192)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_ar' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i16* %%20, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__35 = (unsigned short )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i16 %%21, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__36 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__35&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__36&65535ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__33) < 8192 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%22, i16* %%20, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_115_count);
  *llvm_cbe_tmp__34 = llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%storemerge34, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__37 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__37&4294967295ull)));
  if (((llvm_cbe_tmp__37&4294967295U) == (8192u&4294967295U))) {
    goto llvm_cbe__2e_preheader6_2e_1;
  } else {
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__37;   /* for PHI node */
    goto llvm_cbe_tmp__85;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader6_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i32 @arentEqual(i16* %%1, i16* %%2), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_129_count);
  arentEqual((signed short *)llvm_cbe_tmp__18, (signed short *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
  llvm_cbe_storemerge17_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__86;

llvm_cbe_tmp__87:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__39 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct._iobuf* %%26, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__40 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__39[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str1, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%27), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_149_count);
  fwrite(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__41);
}
  goto llvm_cbe_tmp__88;

llvm_cbe_tmp__89:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__42 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct._iobuf* %%30, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__43 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__42[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str2, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%31), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_153_count);
  fwrite(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__44);
}
  goto llvm_cbe_tmp__88;

llvm_cbe_tmp__88:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_tmp__82;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17.1 = phi i32 [ 0, %%.preheader6.1 ], [ %%40, %%34  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge17_2e_1_count);
  llvm_cbe_storemerge17_2e_1 = (unsigned int )llvm_cbe_storemerge17_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17.1 = 0x%X",llvm_cbe_storemerge17_2e_1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__45 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = srem i32 %%35, 8192, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__46 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__45) % ((signed int )8192u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__46));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = trunc i32 %%36 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__47 = (unsigned short )((unsigned short )llvm_cbe_tmp__46&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sext i32 %%storemerge17.1 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__48 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge17_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 %%38, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__49 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__48))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__48) < 8192 && "Write access out of array 'in' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%37, i16* %%39, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_161_count);
  *llvm_cbe_tmp__49 = llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%storemerge17.1, 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__50 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__50&4294967295ull)));
  if (((llvm_cbe_tmp__50&4294967295U) == (8192u&4294967295U))) {
    llvm_cbe_storemerge25_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  } else {
    llvm_cbe_storemerge17_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__50;   /* for PHI node */
    goto llvm_cbe_tmp__86;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader.1' to make GCC happy */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25.1 = phi i32 [ %%44, %%.preheader.1 ], [ 0, %%34  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge25_2e_1_count);
  llvm_cbe_storemerge25_2e_1 = (unsigned int )llvm_cbe_storemerge25_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25.1 = 0x%X",llvm_cbe_storemerge25_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = sext i32 %%storemerge25.1 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__51 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge25_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds [8192 x i16]* %%out, i64 0, i64 %%41, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__52 = (signed short *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__51))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__51));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__51) < 8192 && "Write access out of array 'out' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%42, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_177_count);
  *llvm_cbe_tmp__52 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 %%41, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__53 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__51))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__51));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__51) < 8192 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%43, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_179_count);
  *llvm_cbe_tmp__53 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add nsw i32 %%storemerge25.1, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
  if (((llvm_cbe_tmp__54&4294967295U) == (8192u&4294967295U))) {
    goto llvm_cbe_tmp__90;
  } else {
    llvm_cbe_storemerge25_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

  } while (1); /* end of syntactic loop '.preheader.1' */
llvm_cbe_tmp__90:
if (AESL_DEBUG_TRACE)
printf("\n  call void @lab3_z2(i16* %%0, i16* %%1) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_193_count);
  lab3_z2((signed short *)llvm_cbe_tmp__17, (signed short *)llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge34_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__91;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__91:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34.1 = phi i32 [ 0, %%45 ], [ %%54, %%46  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge34_2e_1_count);
  llvm_cbe_storemerge34_2e_1 = (unsigned int )llvm_cbe_storemerge34_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34.1 = 0x%X",llvm_cbe_storemerge34_2e_1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = sext i32 %%storemerge34.1 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__55 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge34_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 %%47, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__56 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__55))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__55));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__55) < 8192)) fprintf(stderr, "%s:%d: warning: Read access out of array 'in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i16* %%48, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__57 = (unsigned short )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i16 %%49 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__58 = (unsigned long long )((signed long long )(signed short )llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 %%50, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__59 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__58))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__58));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__58) < 8192)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_ar' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i16* %%51, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__60 = (unsigned short )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i16 %%52, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__61 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__60&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__61&65535ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__58) < 8192 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%53, i16* %%51, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_213_count);
  *llvm_cbe_tmp__59 = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add nsw i32 %%storemerge34.1, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__62 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__62&4294967295ull)));
  if (((llvm_cbe_tmp__62&4294967295U) == (8192u&4294967295U))) {
    goto llvm_cbe__2e_preheader6_2e_2;
  } else {
    llvm_cbe_storemerge34_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__62;   /* for PHI node */
    goto llvm_cbe_tmp__91;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader6_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = call i32 @arentEqual(i16* %%1, i16* %%2), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_227_count);
  arentEqual((signed short *)llvm_cbe_tmp__18, (signed short *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__63);
}
  llvm_cbe_storemerge17_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__92;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__92:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17.2 = phi i32 [ 0, %%.preheader6.2 ], [ %%62, %%56  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge17_2e_2_count);
  llvm_cbe_storemerge17_2e_2 = (unsigned int )llvm_cbe_storemerge17_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17.2 = 0x%X",llvm_cbe_storemerge17_2e_2);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__69);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__64 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__64);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = srem i32 %%57, 8192, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__65 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__64) % ((signed int )8192u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__65));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = trunc i32 %%58 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__66 = (unsigned short )((unsigned short )llvm_cbe_tmp__65&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = sext i32 %%storemerge17.2 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__67 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge17_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 %%60, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__68 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__67))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__67));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__67) < 8192 && "Write access out of array 'in' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%59, i16* %%61, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_250_count);
  *llvm_cbe_tmp__68 = llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add nsw i32 %%storemerge17.2, 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__69&4294967295ull)));
  if (((llvm_cbe_tmp__69&4294967295U) == (8192u&4294967295U))) {
    llvm_cbe_storemerge25_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  } else {
    llvm_cbe_storemerge17_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__69;   /* for PHI node */
    goto llvm_cbe_tmp__92;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader.2' to make GCC happy */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25.2 = phi i32 [ %%66, %%.preheader.2 ], [ 0, %%56  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge25_2e_2_count);
  llvm_cbe_storemerge25_2e_2 = (unsigned int )llvm_cbe_storemerge25_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25.2 = 0x%X",llvm_cbe_storemerge25_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__73);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = sext i32 %%storemerge25.2 to i64, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_264_count);
  llvm_cbe_tmp__70 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge25_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [8192 x i16]* %%out, i64 0, i64 %%63, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__71 = (signed short *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__70))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__70));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__70) < 8192 && "Write access out of array 'out' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%64, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_266_count);
  *llvm_cbe_tmp__71 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 %%63, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__72 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__70))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__70));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__70) < 8192 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 0, i16* %%65, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_268_count);
  *llvm_cbe_tmp__72 = ((unsigned short )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add nsw i32 %%storemerge25.2, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__73 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__73&4294967295ull)));
  if (((llvm_cbe_tmp__73&4294967295U) == (8192u&4294967295U))) {
    goto llvm_cbe_tmp__93;
  } else {
    llvm_cbe_storemerge25_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__73;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

  } while (1); /* end of syntactic loop '.preheader.2' */
llvm_cbe_tmp__93:
if (AESL_DEBUG_TRACE)
printf("\n  call void @lab3_z2(i16* %%0, i16* %%1) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_282_count);
  lab3_z2((signed short *)llvm_cbe_tmp__17, (signed short *)llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge34_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__94;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__94:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34.2 = phi i32 [ 0, %%67 ], [ %%76, %%68  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge34_2e_2_count);
  llvm_cbe_storemerge34_2e_2 = (unsigned int )llvm_cbe_storemerge34_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34.2 = 0x%X",llvm_cbe_storemerge34_2e_2);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__81);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = sext i32 %%storemerge34.2 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__74 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge34_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds [8192 x i16]* %%in, i64 0, i64 %%69, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_296_count);
  llvm_cbe_tmp__75 = (signed short *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__74))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__74));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__74) < 8192)) fprintf(stderr, "%s:%d: warning: Read access out of array 'in' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i16* %%70, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__76 = (unsigned short )*llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = sext i16 %%71 to i64, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__77 = (unsigned long long )((signed long long )(signed short )llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds [8192 x i16]* %%expected_ar, i64 0, i64 %%72, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__78 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )llvm_cbe_tmp__77))
#ifdef AESL_BC_SIM
 % 8192
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__77));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__77) < 8192)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_ar' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i16* %%73, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__79 = (unsigned short )*llvm_cbe_tmp__78;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add i16 %%74, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__80 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__79&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__80&65535ull)));

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__77) < 8192 && "Write access out of array 'expected_ar' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%75, i16* %%73, align 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_302_count);
  *llvm_cbe_tmp__78 = llvm_cbe_tmp__80;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add nsw i32 %%storemerge34.2, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(llvm_cbe_storemerge34_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__81&4294967295ull)));
  if (((llvm_cbe_tmp__81&4294967295U) == (8192u&4294967295U))) {
    goto llvm_cbe_tmp__95;
  } else {
    llvm_cbe_storemerge34_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__81;   /* for PHI node */
    goto llvm_cbe_tmp__94;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__95:
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = call i32 @arentEqual(i16* %%1, i16* %%2), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__82 = (unsigned int )arentEqual((signed short *)llvm_cbe_tmp__18, (signed short *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__82);
}
  if (((llvm_cbe_tmp__82&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__87;
  } else {
    goto llvm_cbe_tmp__89;
  }

}

