/* main.c
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

#include <stdio.h>

#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/asn.h>
#include <wolfssl/wolfcrypt/asn_public.h>
#include <wolfssl/wolfcrypt/ecc.h>
#include <wolfssl/wolfcrypt/random.h>
#include<wolfssl/test.h>

#include "channel.h"
#include "ecdh.h"

ecc_key alice;
ecc_key bob;


void genPublic_Alice(){
#ifdef DEBUG_MEMORY
    wolfCrypt_Init();
    InitMemoryTracker();
#endif
    genPublic(&alice, "Alice");
#ifdef DEBUG_MEMORY
    printf("------------------- memory -------------------\n");
    ShowMemoryTracker();
    CleanupMemoryTracker();
    wolfCrypt_Cleanup();
#endif
};

void genPublic_Bob(){
#ifdef DEBUG_MEMORY
    wolfCrypt_Init();
    InitMemoryTracker();
#endif
    genPublic(&bob, "Bob");
#ifdef DEBUG_MEMORY
    printf("------------------- memory -------------------\n");
    ShowMemoryTracker();
    CleanupMemoryTracker();
    wolfCrypt_Cleanup();
#endif
};

void genSharedSec_Bob(){

#ifdef DEBUG_MEMORY
    wolfCrypt_Init();
    InitMemoryTracker();
#endif
    genSharedSec(&bob, "Bob");
#ifdef DEBUG_MEMORY
    printf("------------------- memory -------------------\n");
    ShowMemoryTracker();
    CleanupMemoryTracker();
    wolfCrypt_Cleanup();
#endif
};

void genSharedSec_Alice(){
#ifdef DEBUG_MEMORY
    wolfCrypt_Init();
    InitMemoryTracker();
#endif
    genSharedSec(&alice,"Alice");
#ifdef DEBUG_MEMORY
    printf("------------------- memory -------------------\n");
    ShowMemoryTracker();
    CleanupMemoryTracker();
    wolfCrypt_Cleanup();
#endif
};


int do_keyShare()
{


#if defined(DEBUG_MEMORY)
    StackSizeCheck(NULL,(thread_func)genPublic_Alice);
    StackSizeCheck(NULL,(thread_func)genPublic_Bob);
    StackSizeCheck(NULL,(thread_func)genSharedSec_Bob);
    StackSizeCheck(NULL,(thread_func)genSharedSec_Alice);

#else

    genPublic_Alice();
    genPublic_Bob();
    genSharedSec_Bob();
    genSharedSec_Alice();

#endif
    return 0;
}


int main(){
#ifdef BENCHMARK
    int count = 0;
    double start, total_time;
#ifndef BENCH_TIME_SEC
    #define BENCH_TIME_SEC 3
#endif

    printf("---------------------------------------------------------------\n");
#if defined(SP_C64_FLAG)
    printf("Enabled 64-bit SP \n");
#elif defined(SP_C32_FLAG)
    printf("Enabled 32-bit SP \n");
#elif defined(SP_X86_64_FLAG)
    printf("Enabled SP for x86_64\n");
#elif defined(SP_ARM64_FLAG)
    printf("Enabled SP for Arm64\n");
#elif defined(TFM_FLAG)
    printf("Enabled TFM \n");
#endif
    printf("---------------------------------------------------------------\n");


    printf("Running benchmark...\n");
    printf("Please Wait %.2f seconds\n", (double)BENCH_TIME_SEC);
    start = current_time(0);
    while( (double)BENCH_TIME_SEC > (total_time = current_time(0) - start ) ){
        do_keyShare();
        count++;
    }
    printf("Takes %1.2f Sec for %d times,    %6.2f Cycles/sec\n", total_time, count, count/total_time);
    printf("Finished Benchmark \n");

#else
    do_keyShare();
#endif

}
