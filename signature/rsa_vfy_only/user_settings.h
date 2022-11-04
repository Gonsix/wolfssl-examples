#define WOLFCRYPT_ONLY
#define XMALLOC_USER


#define WOLFSSL_PUBLIC_MP

#define WC_NO_HARDEN

/* hash */
#define NO_MD4
#define NO_MD5
#define NO_SHA


/* rsa */
#define WC_NO_RSA_OAEP

/* math library */
#define NO_DH
#define NO_DSA
#define NO_DES3
#define NO_AES

// #define WOLFSSL_SP_NO_DYN_STACK
#define USE_FAST_MATH
