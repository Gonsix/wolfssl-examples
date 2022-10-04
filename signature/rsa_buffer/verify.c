/* rsa_pub_2048.h
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

/* This file is an example of verifying an RSA signature.
 * The signature is PKCS#1.5 formatted.
 * Key and data are held in buffers.
 * "signature.h", used by this program, can be generated using "sign.c".
 */

// #include <wolfssl/options.h>
#include "user_settings.h"
#include <wolfssl/wolfcrypt/rsa.h>
#include <wolfssl/wolfcrypt/sha256.h>
#include <wolfssl/wolfcrypt/asn.h>
#include <wolfssl/wolfcrypt/asn_public.h>

#include "rsa_pub_2048.h"
#include "signature.h"
// #include <wolfssl/wolfcrypt/ftm.h>

#define LOOP 10000
/* Maximum bound on digest algorithm encoding around digest */
#define MAX_ENC_ALG_SZ      32

/* Verifies the signature with the message and RSA public key.
 * Returns 0 on success and 1 otherwise.
 */
int verify()
{
    int            ret = 0;
    Sha256         sha256;
    Sha256*        pSha256 = NULL;
    RsaKey         rsaKey;
    RsaKey*        pRsaKey = NULL;
    word32         idx;
    unsigned char  digest[WC_SHA256_DIGEST_SIZE];
    unsigned char  encSig[WC_SHA256_DIGEST_SIZE + MAX_ENC_ALG_SZ];
    word32         encSigLen = 0;
    unsigned char  decSig[sizeof(rsa_sig_2048)];
    word32         decSigLen = 0;

    long           cpu_time;
    double         start_sec;
    double         end_sec;
    /* Calculate SHA-256 digest of message */
    if (ret == 0)
        ret = wc_InitSha256(&sha256);
    if (ret == 0) {
        pSha256 = &sha256;
        ret = wc_Sha256Update(&sha256, msg, sizeof(msg));
    }
    if (ret == 0)
        ret = wc_Sha256Final(&sha256, digest);

    /* Encode digest with algorithm information as per PKCS#1.5 */
    if (ret == 0) {
        encSigLen = wc_EncodeSignature(encSig, digest, sizeof(digest), SHA256h);
        if ((int)encSigLen < 0)
            ret = (int)encSigLen;
    }

    /* Initialize the RSA key and decode the DER encoded public key. */
    if (ret == 0)
        ret = wc_InitRsaKey(&rsaKey, NULL);
    if (ret == 0) {
        pRsaKey = &rsaKey;

        idx = 0;
        ret = wc_RsaPublicKeyDecode(public_key_2048, &idx, &rsaKey,
                                    sizeof(public_key_2048));
    }

    /* bench mark*/
    cpu_time = clock();
    start_sec = (double)cpu_time / CLOCKS_PER_SEC;
    for ( int i = 0; i < LOOP; i++ ){
        /* Verify the signature by decrypting the value. */
        if (ret == 0) {
            decSigLen = wc_RsaSSL_Verify(rsa_sig_2048, sizeof(rsa_sig_2048),
                                            decSig, sizeof(decSig), &rsaKey);
            if ((int)decSigLen < 0)
                ret = (int)decSigLen;
        }
        /* Check the decrypted result matches the encoded digest. */
        if (ret == 0 && encSigLen != decSigLen)
            ret = -1;
        if (ret == 0 && XMEMCMP(encSig, decSig, encSigLen) != 0)
            ret = -1;
        
        if(ret == 0){}
        else {
            printf("Invalid Signature!\n");
            exit(ret);
        }

    }
    cpu_time = clock();
    end_sec = (double)cpu_time / CLOCKS_PER_SEC;
    printf("loop: %d\n", LOOP);
    printf("time: %f seconds,\n", end_sec - start_sec );
    printf("average: %f seconds,\n", (end_sec - start_sec)/LOOP );
    /* end benchmark*/

    /* Free the data structures */
    if (pRsaKey != NULL)
        wc_FreeRsaKey(pRsaKey);
    if (pSha256 != NULL)
        wc_Sha256Free(pSha256);

    return ret == 0 ? 0 : 1;
}

int main(){
#if defined(WOLFSSL_HAVE_SP_RSA)
    printf("===============================================================\n");
    printf("Enabled WOLFSSL SP RSA \n");
    printf("---------------------------------------------------------------\n");
    verify();
    printf("===============================================================\n");
#else 
    printf("===============================================================\n");
    printf("Disabled WOLFSSL SP RSA \n");
    printf("---------------------------------------------------------------\n");
    verify();
    printf("===============================================================\n");
#endif
}

