#define WOLFCRYPT_ONLY
#define XMALLOC_USER

#define NO_SIG_WRAPPER

#define WOLFSSL_PUBLIC_MP

/* hash */
#define NO_MD4
#define NO_MD5
#define NO_SHA

/* rsa */
#define WOLFSSL_RSA_VERIFY_INLINE
#define WC_NO_RSA_OAEP
#define WC_NO_HARDEN



/* sp_int */
#define NO_DH
#define NO_DSA
#define NO_DES3
#define NO_AES
// #define WOLFSSL_SP_NO_DYN_STACK
// #define WOLFSSL_SP_SMALL
// #define WOLFSSL_SP_MATH
// #define WOLFSSL_HAVE_SP_RSA 
#define USE_FAST_MATH

/* asn */
#define NO_ASN_TIME
#define IGNORE_NAME_CONSTRAINTS
#define WOLFSSL_NO_ASN_STRICT 

