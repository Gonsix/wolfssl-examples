/* ed448_sign_verify.c
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.
 *
 * This file is part of wolfSSL. (formerly known as CyaSSL)
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdio.h>
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/ed448.h>
#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/signature.h>
#include <wolfssl/wolfcrypt/sha3.h>
#include <wolfssl/wolfcrypt/hash.h>
#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/error-crypt.h>
#include<wolfssl/test.h>

#define CHECK_RET(a, b, eLabel, msg) { \
                                        if (a != b) {                    \
                                            printf("failed %s\n", msg);  \
                                            printf("ret = %d\n", a);   \
                                            goto eLabel;                 \
                                        }                                \
                                     }


int ed448_sign_verify(){

#ifdef DEBUG_MEMORY
    wolfCrypt_Init();
    InitMemoryTracker();
#endif

    int ret = 0;
    byte msg[] = "This is a message";
    byte hash[SHA3_256_DIGEST_SIZE];
    byte signature[ED448_SIG_SIZE];
    word32 sigLen = ED448_SIG_SIZE; /* will be stored signed digest size. */
    WC_RNG rng;
    ed448_key key;
    byte context[60];
    int verified = 0;
    wc_Shake shake;

/* Variables for Benchmark */
#ifdef BENCHMARK
    double start_time, total_time;
    #ifndef BENCH_TIME_SEC
        #define BENCH_TIME_SEC 1
    #endif
        int count;   
#endif

    /* Create the digest of the msg[] */
    ret = wc_InitShake256(&shake, NULL, INVALID_DEVID);
    CHECK_RET(ret, 0, finish, "wc_InitShake256()");
    ret = wc_Shake256_Update(&shake, msg, sizeof(msg));
    CHECK_RET(ret, 0, finish, "wc_Shake256_Update()");
    ret = wc_Shake256_Final(&shake, hash, sizeof(hash));
    CHECK_RET(ret, 0, finish, "wc_Shake256_Final()");


    ret = wc_InitRng(&rng);
    CHECK_RET(ret, 0, shake_done, "wc_InitRng()");

#ifdef BENCHMARK
    count = 0;
    start_time = current_time(1);
    printf("Running Benchmark for Ed448...\n");
    printf("Please wait %.1f seconds,\n", (double)BENCH_TIME_SEC);


    while( (double)BENCH_TIME_SEC > (total_time = current_time(0) - start_time ) ){
#endif 

        ret = wc_ed448_init(&key);
        ret = wc_ed448_make_key(&rng, 57, &key);
        CHECK_RET(ret, 0, rng_done, "wc_ed448_make_key()");
        /* key_done from Here */

        /* Sign the digest */
        ret = wc_ed448_sign_msg(hash, sizeof(hash), signature, &sigLen, &key, context, sizeof(context));
        CHECK_RET(ret, 0, key_done, "wc_ed25519_sign_msg()");

        /* Verify the signature */
        ret = wc_ed448_verify_msg(signature, sigLen, hash, sizeof(hash), &verified, &key, context, sizeof(context));

        CHECK_RET(ret, 0, rng_done, "wc_ed448_verify_msg()"); 
        CHECK_RET(verified, 1, rng_done, "verification check");
        verified = 0;
        sigLen = ED448_SIG_SIZE; /* Initialization for the benchmark */

#ifdef BENCHMARK
        count++;
    }   
    // Running benchmark...
    // Please Wait 3.00 seconds
    // Takes 3.00 Sec for 110199 times,    36732.89 Cycles/sec
    // Finished Benchmark
    printf("  %.2f Cycles/sec\n",  count/total_time);
    printf("Finished Benchmark!\n");
#else 
    printf("Verified!\n");
#endif


key_done:
    wc_ed448_free(&key);
rng_done:
    wc_FreeRng(&rng);
shake_done:
    wc_Shake256_Free(&shake);
finish:
#ifdef DEBUG_MEMORY
    printf("[Memory Usage]\n");
    ShowMemoryTracker();
    CleanupMemoryTracker();
    wolfCrypt_Cleanup();
#endif
    return ret;

}

                                    
int main(){

#ifdef DEBUG_MEMORY
    return StackSizeCheck(NULL, (thread_func)ed448_sign_verify);
#else
    return ed448_sign_verify();
#endif
}
