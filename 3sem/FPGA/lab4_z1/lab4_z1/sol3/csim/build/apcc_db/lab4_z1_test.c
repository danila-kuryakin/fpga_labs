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
void initialize_short_arr(signed short *llvm_cbe_temp_arr);
void check_func(signed short *llvm_cbe_tempA_arr, signed int *llvm_cbe_result_arr, signed short *llvm_cbe_expected_ar);
signed int arentEqual(signed short *llvm_cbe_expected_ar, signed short *llvm_cbe_actual_arr);
signed int main(void);
void lab4_z1(signed short *, signed short *, signed int *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[63] = " ERROR: actual second vector  =%d expected second vector = %d\n";
static  char aesl_internal__OC_str1[30] = "----------Pass!------------ \n";


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
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @initialize_int_arr\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i32* %%temp_arr to i8*, !dbg !6 for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__1 = ( char *)(( char *)llvm_cbe_temp_arr);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 16 for 0x%I64xth hint within @initialize_int_arr  --> \n", ++aesl_llvm_cbe_24_count);
  ( char *)memset(( char *)llvm_cbe_tmp__1, 0u, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @initialize_int_arr}\n");
  return;
}


void initialize_short_arr(signed short *llvm_cbe_temp_arr) {
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @initialize_short_arr\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast i16* %%temp_arr to i8*, !dbg !6 for 0x%I64xth hint within @initialize_short_arr  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__3 = ( char *)(( char *)llvm_cbe_temp_arr);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 8 for 0x%I64xth hint within @initialize_short_arr  --> \n", ++aesl_llvm_cbe_49_count);
  ( char *)memset(( char *)llvm_cbe_tmp__3, 0u, 8ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",8ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @initialize_short_arr}\n");
  return;
}


void check_func(signed short *llvm_cbe_tempA_arr, signed int *llvm_cbe_result_arr, signed short *llvm_cbe_expected_ar) {
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned short llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  signed short *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned short llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  signed short *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned short llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  signed short *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned short llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__18;
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
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned short llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned short llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  signed short *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned short llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  signed short *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  signed int *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned short llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  signed short *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @check_func\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = load i16* %%tempA_arr, align 2, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__5 = (unsigned short )*llvm_cbe_tempA_arr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i16 %%0 to i32, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__6 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i16* %%tempA_arr, i64 1, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__7 = (signed short *)(&llvm_cbe_tempA_arr[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i16* %%2, align 2, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__8 = (unsigned short )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i16 %%3 to i32, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__9 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%4, %%1, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__6&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i16* %%tempA_arr, i64 2, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__11 = (signed short *)(&llvm_cbe_tempA_arr[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i16* %%6, align 2, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__12 = (unsigned short )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i16 %%7 to i32, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__13 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%8, %%5, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_tmp__13&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__10&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i16* %%tempA_arr, i64 3, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__15 = (signed short *)(&llvm_cbe_tempA_arr[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i16* %%10, align 2, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__16 = (unsigned short )*llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i16 %%11 to i32, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__17 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%12, %%9, !dbg !5 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(llvm_cbe_tmp__17&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__14&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%result_arr, align 4, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__19 = (unsigned int )*llvm_cbe_result_arr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sdiv i32 %%14, %%13, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__20 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__19) / ((signed int )llvm_cbe_tmp__18)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__20));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = trunc i32 %%15 to i16, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__21 = (unsigned short )((unsigned short )llvm_cbe_tmp__20&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%16, i16* %%expected_ar, align 2, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_113_count);
  *llvm_cbe_expected_ar = llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i32* %%result_arr, i64 1, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__22 = (signed int *)(&llvm_cbe_result_arr[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__23 = (unsigned int )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sdiv i32 %%18, %%13, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__24 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__23) / ((signed int )llvm_cbe_tmp__18)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__24));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = trunc i32 %%19 to i16, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__25 = (unsigned short )((unsigned short )llvm_cbe_tmp__24&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i16* %%expected_ar, i64 1, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__26 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%20, i16* %%21, align 2, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_124_count);
  *llvm_cbe_tmp__26 = llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i32* %%result_arr, i64 2, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_result_arr[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 4, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__28 = (unsigned int )*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sdiv i32 %%23, %%13, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__29 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__28) / ((signed int )llvm_cbe_tmp__18)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__29));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = trunc i32 %%24 to i16, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__30 = (unsigned short )((unsigned short )llvm_cbe_tmp__29&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i16* %%expected_ar, i64 2, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__31 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%25, i16* %%26, align 2, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_135_count);
  *llvm_cbe_tmp__31 = llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i32* %%result_arr, i64 3, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__32 = (signed int *)(&llvm_cbe_result_arr[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%27, align 4, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__33 = (unsigned int )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sdiv i32 %%28, %%13, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__34 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__33) / ((signed int )llvm_cbe_tmp__18)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__34));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = trunc i32 %%29 to i16, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__35 = (unsigned short )((unsigned short )llvm_cbe_tmp__34&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i16* %%expected_ar, i64 3, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__36 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%30, i16* %%31, align 2, !dbg !6 for 0x%I64xth hint within @check_func  --> \n", ++aesl_llvm_cbe_146_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @check_func}\n");
  return;
}


signed int arentEqual(signed short *llvm_cbe_expected_ar, signed short *llvm_cbe_actual_arr) {
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned short llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned short llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned short llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned short llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  signed short *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned short llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  signed short *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned short llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  unsigned short llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned short llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  signed short *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned short llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  signed short *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned short llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned short llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned short llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  signed short *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned short llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  signed short *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  unsigned short llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned short llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned short llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @arentEqual\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i16* %%expected_ar, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__37 = (unsigned short )*llvm_cbe_expected_ar;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i16* %%actual_arr, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__38 = (unsigned short )*llvm_cbe_actual_arr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
  if (((llvm_cbe_tmp__37&65535U) == (llvm_cbe_tmp__38&65535U))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__80;
  }

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__39 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct._iobuf* %%5, i64 1, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__40 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__39[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i16* %%actual_arr, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__41 = (unsigned short )*llvm_cbe_actual_arr;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i16 %%7 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__42 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i16* %%expected_ar, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__43 = (unsigned short )*llvm_cbe_expected_ar;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i16 %%9 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__44 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%6, i8* getelementptr inbounds ([63 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%8, i32 %%10) nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_176_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__40, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
])), llvm_cbe_tmp__42, llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__42);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__44);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
  goto llvm_cbe_tmp__79;

llvm_cbe_tmp__79:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i16* %%expected_ar, i64 1, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__46 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i16* %%13, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__47 = (unsigned short )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i16* %%actual_arr, i64 1, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__48 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i16* %%15, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__49 = (unsigned short )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
  if (((llvm_cbe_tmp__47&65535U) == (llvm_cbe_tmp__49&65535U))) {
    goto llvm_cbe_tmp__81;
  } else {
    goto llvm_cbe_tmp__82;
  }

llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__50 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct._iobuf* %%19, i64 1, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__51 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__50[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i16* %%15, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__52 = (unsigned short )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i16 %%21 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__53 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i16* %%13, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__54 = (unsigned short )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i16 %%23 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__55 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%20, i8* getelementptr inbounds ([63 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%22, i32 %%24) nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_197_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__51, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
])), llvm_cbe_tmp__53, llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__53);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__55);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
  goto llvm_cbe_tmp__81;

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i16* %%expected_ar, i64 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__57 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i16* %%27, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__58 = (unsigned short )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i16* %%actual_arr, i64 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__59 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i16* %%29, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__60 = (unsigned short )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
  if (((llvm_cbe_tmp__58&65535U) == (llvm_cbe_tmp__60&65535U))) {
    goto llvm_cbe_tmp__83;
  } else {
    goto llvm_cbe_tmp__84;
  }

llvm_cbe_tmp__84:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__61 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct._iobuf* %%33, i64 1, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__62 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__61[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i16* %%29, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__63 = (unsigned short )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i16 %%35 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__64 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i16* %%27, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__65 = (unsigned short )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = sext i16 %%37 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__66 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%34, i8* getelementptr inbounds ([63 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%36, i32 %%38) nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_218_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__62, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
])), llvm_cbe_tmp__64, llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__64);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__66);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__67);
}
  goto llvm_cbe_tmp__83;

llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i16* %%expected_ar, i64 3, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_227_count);
  llvm_cbe_tmp__68 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i16* %%41, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__69 = (unsigned short )*llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i16* %%actual_arr, i64 3, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__70 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i16* %%43, align 2, !dbg !5 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__71 = (unsigned short )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
  if (((llvm_cbe_tmp__69&65535U) == (llvm_cbe_tmp__71&65535U))) {
    goto llvm_cbe_tmp__85;
  } else {
    goto llvm_cbe_tmp__86;
  }

llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__72 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__72);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct._iobuf* %%47, i64 1, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__73 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__72[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i16* %%43, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__74 = (unsigned short )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i16 %%49 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__75 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i16* %%41, align 2, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__76 = (unsigned short )*llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = sext i16 %%51 to i32, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__77 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%48, i8* getelementptr inbounds ([63 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%50, i32 %%52) nounwind, !dbg !6 for 0x%I64xth hint within @arentEqual  --> \n", ++aesl_llvm_cbe_239_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__73, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 63
#endif
])), llvm_cbe_tmp__75, llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__75);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__77);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__78);
}
  goto llvm_cbe_tmp__85;

llvm_cbe_tmp__85:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @arentEqual}\n");
  return 0u;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_firstVector_arr_count = 0;
  signed short llvm_cbe_firstVector_arr[4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_actual_arr_count = 0;
  signed short llvm_cbe_actual_arr[4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_expected_ar_count = 0;
  signed short llvm_cbe_expected_ar[4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_actual_ar_count = 0;
  signed int llvm_cbe_actual_ar[4];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  signed int *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  signed short *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  signed short *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  signed short *llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  unsigned short llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  unsigned short llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  unsigned short llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  signed short *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  unsigned short llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  signed short *llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  unsigned int llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  unsigned short llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  signed short *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  unsigned short llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  signed short *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned int llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned short llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  signed short *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned int llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  unsigned short llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  signed short *llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  unsigned int llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  unsigned short llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  unsigned int llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  unsigned short llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  unsigned int llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned short llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  unsigned int llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned short llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  unsigned int llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  unsigned short llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned short llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  unsigned int llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  unsigned int llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  unsigned short llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  unsigned short llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [4 x i32]* %%actual_ar, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_259_count);
  llvm_cbe_tmp__87 = (signed int *)(&llvm_cbe_actual_ar[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [4 x i16]* %%firstVector_arr, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__88 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [4 x i16]* %%actual_arr, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__89 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [4 x i16]* %%expected_ar, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__90 = (signed short *)(&llvm_cbe_expected_ar[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%1), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_263_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__91 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__91);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = srem i32 %%5, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__92 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__91) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__92));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i32 %%6 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__93 = (unsigned short )((unsigned short )llvm_cbe_tmp__92&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__93);

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%7, i16* %%2, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_272_count);
  *llvm_cbe_tmp__88 = llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_273_count);
  llvm_cbe_tmp__94 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__94);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = srem i32 %%8, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__95 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__94) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__95));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i32 %%9 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__96 = (unsigned short )((unsigned short )llvm_cbe_tmp__95&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__96);

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%10, i16* %%3, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_276_count);
  *llvm_cbe_tmp__89 = llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__97 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__97);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = srem i32 %%11, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__98 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__97) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__98));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = trunc i32 %%12 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__99 = (unsigned short )((unsigned short )llvm_cbe_tmp__98&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [4 x i16]* %%firstVector_arr, i64 0, i64 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__100 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%13, i16* %%14, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_286_count);
  *llvm_cbe_tmp__100 = llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__101 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__101);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = srem i32 %%15, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__102 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__101) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__102));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = trunc i32 %%16 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_289_count);
  llvm_cbe_tmp__103 = (unsigned short )((unsigned short )llvm_cbe_tmp__102&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [4 x i16]* %%actual_arr, i64 0, i64 1, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__104 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%17, i16* %%18, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_291_count);
  *llvm_cbe_tmp__104 = llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_297_count);
  llvm_cbe_tmp__105 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__105);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = srem i32 %%19, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__106 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__105) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__106));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = trunc i32 %%20 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__107 = (unsigned short )((unsigned short )llvm_cbe_tmp__106&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [4 x i16]* %%firstVector_arr, i64 0, i64 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__108 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%21, i16* %%22, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_301_count);
  *llvm_cbe_tmp__108 = llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__109 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__109);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = srem i32 %%23, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__110 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__109) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__110));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = trunc i32 %%24 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__111 = (unsigned short )((unsigned short )llvm_cbe_tmp__110&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [4 x i16]* %%actual_arr, i64 0, i64 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__112 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%25, i16* %%26, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_306_count);
  *llvm_cbe_tmp__112 = llvm_cbe_tmp__111;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__113 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__113);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = srem i32 %%27, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__114 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__113) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__114));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = trunc i32 %%28 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__115 = (unsigned short )((unsigned short )llvm_cbe_tmp__114&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [4 x i16]* %%firstVector_arr, i64 0, i64 3, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__116 = (signed short *)(&llvm_cbe_firstVector_arr[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%29, i16* %%30, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_316_count);
  *llvm_cbe_tmp__116 = llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__117 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__117);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = srem i32 %%31, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__118 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__117) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__118));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = trunc i32 %%32 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__119 = (unsigned short )((unsigned short )llvm_cbe_tmp__118&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [4 x i16]* %%actual_arr, i64 0, i64 3, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__120 = (signed short *)(&llvm_cbe_actual_arr[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%33, i16* %%34, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_321_count);
  *llvm_cbe_tmp__120 = llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  call void @lab4_z1(i16* %%2, i16* %%3, i32* %%1) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_327_count);
  lab4_z1((signed short *)llvm_cbe_tmp__88, (signed short *)llvm_cbe_tmp__89, (signed int *)llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_short_arr(i16* %%4), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_328_count);
  initialize_short_arr((signed short *)llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @check_func(i16* %%2, i32* %%1, i16* %%4), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_329_count);
  check_func((signed short *)llvm_cbe_tmp__88, (signed int *)llvm_cbe_tmp__87, (signed short *)llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_int_arr(i32* %%1), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_333_count);
  initialize_int_arr((signed int *)llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__121 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__121);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = srem i32 %%35, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__122 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__121) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__122));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = trunc i32 %%36 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__123 = (unsigned short )((unsigned short )llvm_cbe_tmp__122&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%37, i16* %%2, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_342_count);
  *llvm_cbe_tmp__88 = llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__124 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__124);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = srem i32 %%38, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__125 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__124) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__125));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = trunc i32 %%39 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__126 = (unsigned short )((unsigned short )llvm_cbe_tmp__125&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__126);

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%40, i16* %%3, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_346_count);
  *llvm_cbe_tmp__89 = llvm_cbe_tmp__126;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__127 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__127);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = srem i32 %%41, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__128 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__127) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__128));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = trunc i32 %%42 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__129 = (unsigned short )((unsigned short )llvm_cbe_tmp__128&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__129);

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%43, i16* %%14, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_355_count);
  *llvm_cbe_tmp__100 = llvm_cbe_tmp__129;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__130 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__130);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = srem i32 %%44, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__131 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__130) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__131));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = trunc i32 %%45 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__132 = (unsigned short )((unsigned short )llvm_cbe_tmp__131&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%46, i16* %%18, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_359_count);
  *llvm_cbe_tmp__104 = llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__133 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__133);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = srem i32 %%47, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_366_count);
  llvm_cbe_tmp__134 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__133) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__134));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = trunc i32 %%48 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__135 = (unsigned short )((unsigned short )llvm_cbe_tmp__134&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%49, i16* %%22, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_368_count);
  *llvm_cbe_tmp__108 = llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__136 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__136);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = srem i32 %%50, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__137 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__136) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__137));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = trunc i32 %%51 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__138 = (unsigned short )((unsigned short )llvm_cbe_tmp__137&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__138);

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%52, i16* %%26, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_372_count);
  *llvm_cbe_tmp__112 = llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__139 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__139);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = srem i32 %%53, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__140 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__139) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__140));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = trunc i32 %%54 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__141 = (unsigned short )((unsigned short )llvm_cbe_tmp__140&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__141);

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'firstVector_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%55, i16* %%30, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_381_count);
  *llvm_cbe_tmp__116 = llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = call i32 bitcast (i32 (...)* @rand to i32 ()*)() nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__142 = (unsigned int )rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__142);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = srem i32 %%56, 4, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__143 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__142) % ((signed int )4u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__143));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = trunc i32 %%57 to i16, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_384_count);
  llvm_cbe_tmp__144 = (unsigned short )((unsigned short )llvm_cbe_tmp__143&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__144);

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 4 && "Write access out of array 'actual_arr' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%58, i16* %%34, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_385_count);
  *llvm_cbe_tmp__120 = llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE)
printf("\n  call void @lab4_z1(i16* %%2, i16* %%3, i32* %%1) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_391_count);
  lab4_z1((signed short *)llvm_cbe_tmp__88, (signed short *)llvm_cbe_tmp__89, (signed int *)llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @initialize_short_arr(i16* %%4), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_392_count);
  initialize_short_arr((signed short *)llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @check_func(i16* %%2, i32* %%1, i16* %%4), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_393_count);
  check_func((signed short *)llvm_cbe_tmp__88, (signed int *)llvm_cbe_tmp__87, (signed short *)llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__145 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__145);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds %%struct._iobuf* %%59, i64 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__146 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__145[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = call i64 @fwrite(i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str1, i64 0, i64 0), i64 29, i64 1, %%struct._iobuf* %%60), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_399_count);
  fwrite(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), 29ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",29ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__147);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

