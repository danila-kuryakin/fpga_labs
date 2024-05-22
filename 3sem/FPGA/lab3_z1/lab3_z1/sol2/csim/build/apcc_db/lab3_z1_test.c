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
signed int arentEqual(signed int llvm_cbe_expectedArr, signed int llvm_cbe_actualArr);
signed int main(void);
signed int lab3_z1(signed short , signed short , signed short *, signed int *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str1[34] = " GOOD!: expected=%d  actual=%d  \n";
static  char aesl_internal__OC_str[34] = " ERROR: expected=%d  actual=%d  \n";
static  char aesl_internal__OC_str2[30] = "----------Pass!------------ \n";
static  char aesl_internal__OC_str3[30] = "----------Fail!------------ \n";


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

signed int arentEqual(signed int llvm_cbe_expectedArr, signed int llvm_cbe_actualArr) {
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
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @arentEqual\n");
  if (((llvm_cbe_expectedArr&4294967295U) == (llvm_cbe_actualArr&4294967295U))) {
    goto llvm_cbe_tmp__7;
  } else {
    goto llvm_cbe_tmp__8;
  }

llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct._iobuf* %%3, i64 1, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__2 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__1[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%4, i8* getelementptr inbounds ([34 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%expectedArr, i32 %%actualArr) nounwind, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_13_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 34
#endif
])), llvm_cbe_expectedArr, llvm_cbe_actualArr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument expectedArr = 0x%X",llvm_cbe_expectedArr);
printf("\nArgument actualArr = 0x%X",llvm_cbe_actualArr);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__7:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__4 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct._iobuf* %%7, i64 1, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__5 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__4[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%8, i8* getelementptr inbounds ([34 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 %%expectedArr, i32 %%expectedArr) nounwind, !dbg !3 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_17_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__5, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 34
#endif
])), llvm_cbe_expectedArr, llvm_cbe_expectedArr);
if (AESL_DEBUG_TRACE) {
printf("\nArgument expectedArr = 0x%X",llvm_cbe_expectedArr);
printf("\nArgument expectedArr = 0x%X",llvm_cbe_expectedArr);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__6);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__9;

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 1, %%2 ], [ 0, %%6  for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @arentEqual}\n");
  return llvm_cbe_storemerge;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_inC_count = 0;
  signed short llvm_cbe_inC;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_res_count = 0;
  signed int llvm_cbe_res;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned short llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned short llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned short llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned short llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned short llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned short llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned short llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned short llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  unsigned short llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned short llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned short llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned short llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__2e_1_count = 0;
  unsigned int llvm_cbe__2e__2e_1;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned short llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned short llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned short llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned short llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned short llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned short llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__2e_2_count = 0;
  unsigned int llvm_cbe__2e__2e_2;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__10 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = srem i32 %%1, 15, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__11 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__10) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i32 %%2 to i16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__12 = (unsigned short )((unsigned short )llvm_cbe_tmp__11&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i16 %%3, 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__13 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__12&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__13&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__14 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = srem i32 %%5, 15, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__15 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__14) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__15));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i32 %%6 to i16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__16 = (unsigned short )((unsigned short )llvm_cbe_tmp__15&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i16 %%7, 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__17 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__16&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__17&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__18 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = srem i32 %%9, 15, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__19 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__18) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = trunc i32 %%10 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__20 = (unsigned short )((unsigned short )llvm_cbe_tmp__19&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i16 %%11, 5, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__21 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__20&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__21&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%12, i16* %%inC, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_52_count);
  *(&llvm_cbe_inC) = llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i16 %%4 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__22 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i16 %%12 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__23 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = mul nsw i32 %%14, %%13, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__23&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__22&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i16 %%8 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__25 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%15, %%16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__25&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i32 @lab3_z1(i16 signext %%4, i16 signext %%8, i16* %%inC, i32* %%res) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_61_count);
  lab3_z1(llvm_cbe_tmp__13, llvm_cbe_tmp__17, (signed short *)(&llvm_cbe_inC), (signed int *)(&llvm_cbe_res));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__13);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__17);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%res, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__28 = (unsigned int )*(&llvm_cbe_res);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = call i32 @arentEqual(i32 %%19, i32 %%17), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__29 = (unsigned int )arentEqual(llvm_cbe_tmp__28, llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__28);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__26);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%21, i32 0, i32 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__29&4294967295U) == (0u&4294967295U))) ? ((unsigned int )0u) : ((unsigned int )1u));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%res, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_77_count);
  *(&llvm_cbe_res) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__30 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = srem i32 %%22, 15, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__31 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__30) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__31));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = trunc i32 %%23 to i16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__32 = (unsigned short )((unsigned short )llvm_cbe_tmp__31&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i16 %%24, 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__33 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__32&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__33&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__34 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = srem i32 %%26, 15, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__35 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__34) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__35));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = trunc i32 %%27 to i16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__36 = (unsigned short )((unsigned short )llvm_cbe_tmp__35&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i16 %%28, 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__37 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__36&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__37&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__38 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = srem i32 %%30, 15, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__39 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__38) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__39));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = trunc i32 %%31 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__40 = (unsigned short )((unsigned short )llvm_cbe_tmp__39&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i16 %%32, 5, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__41 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__40&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__41&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%33, i16* %%inC, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_106_count);
  *(&llvm_cbe_inC) = llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sext i16 %%25 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__42 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sext i16 %%33 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__43 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = mul nsw i32 %%35, %%34, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(llvm_cbe_tmp__43&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__42&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__44&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i16 %%29 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__45 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add nsw i32 %%36, %%37, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__45&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__46&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call i32 @lab3_z1(i16 signext %%25, i16 signext %%29, i16* %%inC, i32* %%res) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_115_count);
  lab3_z1(llvm_cbe_tmp__33, llvm_cbe_tmp__37, (signed short *)(&llvm_cbe_inC), (signed int *)(&llvm_cbe_res));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__33);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__37);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%res, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__48 = (unsigned int )*(&llvm_cbe_res);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 @arentEqual(i32 %%40, i32 %%38), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__49 = (unsigned int )arentEqual(llvm_cbe_tmp__48, llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__48);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__46);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__49);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%..1 = select i1 %%42, i32 %%., i32 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e__2e_1_count);
  llvm_cbe__2e__2e_1 = (unsigned int )((((llvm_cbe_tmp__49&4294967295U) == (0u&4294967295U))) ? ((unsigned int )llvm_cbe__2e_) : ((unsigned int )1u));
if (AESL_DEBUG_TRACE)
printf("\n..1 = 0x%X\n", llvm_cbe__2e__2e_1);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%res, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_131_count);
  *(&llvm_cbe_res) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__50 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = srem i32 %%43, 15, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__51 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__50) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__51));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = trunc i32 %%44 to i16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__52 = (unsigned short )((unsigned short )llvm_cbe_tmp__51&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i16 %%45, 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__53 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__52&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__53&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__54 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__54);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = srem i32 %%47, 15, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__55 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__54) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__55));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = trunc i32 %%48 to i16, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__56 = (unsigned short )((unsigned short )llvm_cbe_tmp__55&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i16 %%49, 5, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__57 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__56&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__57&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__58 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = srem i32 %%51, 15, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__59 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__58) % ((signed int )15u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__59));
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = trunc i32 %%52 to i16, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__60 = (unsigned short )((unsigned short )llvm_cbe_tmp__59&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add i16 %%53, 5, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__61 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__60&65535ull)) + ((unsigned short )(((unsigned short )5)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__61&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%54, i16* %%inC, align 2, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_160_count);
  *(&llvm_cbe_inC) = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = sext i16 %%46 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__62 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = sext i16 %%54 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__63 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = mul nsw i32 %%56, %%55, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__62&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__64&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = sext i16 %%50 to i32, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__65 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add nsw i32 %%57, %%58, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__66 = (unsigned int )((unsigned int )(llvm_cbe_tmp__64&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__65&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__66&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = call i32 @lab3_z1(i16 signext %%46, i16 signext %%50, i16* %%inC, i32* %%res) nounwind, !dbg !4 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_169_count);
  lab3_z1(llvm_cbe_tmp__53, llvm_cbe_tmp__57, (signed short *)(&llvm_cbe_inC), (signed int *)(&llvm_cbe_res));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__53);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__57);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__67);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i32* %%res, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__68 = (unsigned int )*(&llvm_cbe_res);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = call i32 @arentEqual(i32 %%61, i32 %%59), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__69 = (unsigned int )arentEqual(llvm_cbe_tmp__68, llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__68);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__66);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__69);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%..2 = select i1 %%63, i32 %%..1, i32 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe__2e__2e_2_count);
  llvm_cbe__2e__2e_2 = (unsigned int )((((llvm_cbe_tmp__69&4294967295U) == (0u&4294967295U))) ? ((unsigned int )llvm_cbe__2e__2e_1) : ((unsigned int )1u));
if (AESL_DEBUG_TRACE)
printf("\n..2 = 0x%X\n", llvm_cbe__2e__2e_2);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%res, align 4, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_185_count);
  *(&llvm_cbe_res) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
  if (((llvm_cbe__2e__2e_2&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__76;
  } else {
    goto llvm_cbe_tmp__77;
  }

llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__70 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__70);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds %%struct._iobuf* %%66, i64 1, !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__71 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__70[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str2, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%67), !dbg !5 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_194_count);
  fwrite(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__72);
}
  goto llvm_cbe_tmp__78;

llvm_cbe_tmp__77:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__73 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__73);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds %%struct._iobuf* %%70, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__74 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__73[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str3, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%71), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_198_count);
  fwrite(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__75);
}
  goto llvm_cbe_tmp__78;

llvm_cbe_tmp__78:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe__2e__2e_2;
}

