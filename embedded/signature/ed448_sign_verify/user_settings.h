#define HAVE_ED448
#define WOLFSSL_SHA3
#define WOLFSSL_SHAKE256
#define USE_FAST_MATH
#define WOLFCRYPT_ONLY
#define WOLFSSL_PUBLIC_MP

/* hash */
#define NO_MD4
#define NO_MD5
#define NO_SHA

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
