#define NO_ASN
#define WOLFSSL_HAVE_SP_ECC
#define WOLFSSL_SP_MATH_ALL

/* ecc */
#define NO_RSA
#define HAVE_ECC
#define ECC_TIMING_RESISTANT

/* ONLY FOR TEST. NEED GENSSED FOR OPERATION */
#define WOLFSSL_GENSEED_FORTEST

/* for embedded */
#define SINGLE_THREADED
#define NO_WOLFSSL_DIR
#define HAVE_HASHDRBG
#define NO_DEV_RANDOM

// #define DEBUG_MEMORY
#ifdef DEBUG_MEMORY
    #define USE_WOLFSSL_MEMORY
    #define WOLFSSL_TRACK_MEMORY
    #define HAVE_STACK_SIZE
    // #define WOLFSSL_DEBUG_MEMORY
    // #define WOLFSSL_DEBUG_MEMORY_PRINT
#endif

// #define SP_C64_FLAG

#ifdef SP_C32_FLAG 
    #define WOLFSSL_HAVE_SP_RSA
    #define WOLFSSL_SP_MATH_ALL
    #undef USE_FAST_MATH
#endif 

#ifdef SP_C64_FLAG
    #define WOLFSSL_HAVE_SP_RSA
    #define WOLFSSL_SP_MATH_ALL
    #define SP_WORD_SIZE 64
    #define HAVE___UINT128_T
    #undef USE_FAST_MATH
#endif

#ifdef SP_ARM64_FLAG
    #define WOLFSSL_HAVE_SP_RSA
    #define WOLFSSL_SP_MATH_ALL
    #define WOLFSSL_SP_ARM64
    #define WOLFSSL_SP_ARM64_ASM
#endif /*SP_ARM64_FLAG*/


#ifdef SP_X86_64_FLAG
    #define WOLFSSL_HAVE_SP_RSA
    #define WOLFSSL_SP_MATH_ALL
    #define WOLFSSL_SP_X86_64
    #define WOLFSSL_SP_X86_64_ASM
#endif /*SP_X86_64_FLAG*/
