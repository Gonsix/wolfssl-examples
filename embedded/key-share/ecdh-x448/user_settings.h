#define HAVE_CURVE448
#define HAVE_CURVE448_KEY_EXPORT
#define HAVE_CURVE448_KEY_IMPORT
#define WOLFCRYPT_ONLY
#define WOLFSSL_PUBLIC_MP
#define NO_RSA

/* hash */
#define NO_MD4
#define NO_MD5
#define NO_SHA
#define WOLFSSL_SHA512
#define WOLFSSL_NOSHA512_224
#define WOLFSSL_NOSHA512_256

/* ONLY FOR TEST. NEED GENSSED FOR OPERATION */
#define WOLFSSL_GENSEED_FORTEST

/* for embedded */
#define SINGLE_THREADED
#define NO_WOLFSSL_DIR
#define HAVE_HASHDRBG
#define NO_DEV_RANDOM


/* asn */
#define NO_ASN_TIME
#define IGNORE_NAME_CONSTRAINTS
#define WOLFSSL_NO_ASN_STRICT

#ifdef FE_ARM64_FLAG
    #define WOLFSSL_ARMASM
    #define HAVE___UINT128_T
#endif

#ifdef FE_X86_64_FLAG
    #define CURVED25519_X64
    #define CURVED25519_128BIT
    #define HAVE___UINT128_T
    #define HAVE_CPUID
    #define HAVE_CPUID_INTEL

#endif

#ifdef DEBUG_MEMORY
    #define WOLFSSL_TRACK_MEMORY
    #define HAVE_STACK_SIZE
    // #define WOLFSSL_DEBUG_MEMORY
    // #define WOLFSSL_DEBUG_MEMORY_PRINT
    #undef BENCHMARK
#endif


#ifdef BENCHMARK
    #undef DEBUG_MEMORY
#endif








