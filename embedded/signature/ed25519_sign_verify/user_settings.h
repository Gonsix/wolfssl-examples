#define HAVE_ED25519
#define HAVE_CURVE25519
#define WOLFCRYPT_ONLY
#define WOLFSSL_PUBLIC_MP

/* hash */
#define NO_MD4
#define NO_MD5
#define NO_SHA
#define WOLFSSL_SHA512
#define WOLFSSL_NOSHA512_224
#define WOLFSSL_NOSHA512_256

/* rsa */
#define WOLFSSL_RSA_VERIFY_INLINE
#define WC_NO_RSA_OAEP
#define WC_NO_HARDEN
#define NO_RSA
/* sp_int */
#define NO_DH
#define NO_DSA
#define NO_DES3
#define NO_AES

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








