# The path to the wolfssl directory must be set correctly for your environment.
WOLFROOT = ../../../../wolfssl

CFLAGS = $(EX_CFLAGS) -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT) -Os
ASFLAGS = -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT)

OBJ=\
	$(WOLFROOT)/wolfcrypt/src/ed448.o\
	$(WOLFROOT)/wolfcrypt/src/ge_448.o\
	$(WOLFROOT)/wolfcrypt/src/fe_448.o\
	$(WOLFROOT)/wolfcrypt/src/sha3.o\
	$(WOLFROOT)/wolfcrypt/src/sha256.o\
	$(WOLFROOT)/wolfcrypt/src/hash.o\
	$(WOLFROOT)/wolfcrypt/src/random.o\
	$(WOLFROOT)/wolfcrypt/src/asn.o\
	$(WOLFROOT)/wolfcrypt/src/wc_port.o\
	$(WOLFROOT)/wolfcrypt/src/coding.o\
	$(WOLFROOT)/wolfcrypt/src/memory.o\
	$(WOLFROOT)/wolfcrypt/src/wolfmath.o\
	$(WOLFROOT)/wolfcrypt/src/tfm.o\


.PHONY: all clean mem size bench


# CFLAGS += -DSP_C64_FLAG
# OBJ += $(OBJ_TFM)

all : ed448_sign_verify bench mem

ed448_sign_verify: clean $(OBJ)
	$(CC) $(CFLAGS) -o ed448_sign_verify ed448_sign_verify.c $(OBJ) 

bench: clean $(OBJ)
	$(CC) $(CFLAGS) -DBENCHMARK -o ed448_sign_verify_bench ed448_sign_verify.c $(OBJ) -lpthread

mem: clean $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG_MEMORY -o ed448_sign_verify_mem ed448_sign_verify.c $(OBJ) -lpthread
clean:
	rm -f ed448_sign_verify ed448_sign_verify_bench ed448_sign_verify_mem $(WOLFROOT)/wolfcrypt/src/*.o

size :
	size $(OBJ) ed448_sign_verify
