# The path to the wolfssl directory must be set correctly for your environment.
WOLFROOT = ../../../../wolfssl

CFLAGS = $(EX_CFLAGS) -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT) -Os
ASFLAGS = -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT)

OBJ=\
	$(WOLFROOT)/wolfcrypt/src/ed25519.o\
	$(WOLFROOT)/wolfcrypt/src/hash.o\
	$(WOLFROOT)/wolfcrypt/src/random.o\
	$(WOLFROOT)/wolfcrypt/src/wc_port.o\
	$(WOLFROOT)/wolfcrypt/src/memory.o\


OBJ_NORMAL=\
	$(WOLFROOT)/wolfcrypt/src/ge_operations.o\
	$(WOLFROOT)/wolfcrypt/src/fe_operations.o\
	$(WOLFROOT)/wolfcrypt/src/sha512.o\
	$(WOLFROOT)/wolfcrypt/src/sha256.o\


OBJ_LOW_MEM=\
	$(WOLFROOT)/wolfcrypt/src/ge_low_mem.o\
	$(WOLFROOT)/wolfcrypt/src/fe_low_mem.o\
	$(WOLFROOT)/wolfcrypt/src/sha512.o\
	$(WOLFROOT)/wolfcrypt/src/sha256.o\

OBJ_ARM64=\
	$(WOLFROOT)/wolfcrypt/src/ge_operations.o\
	$(WOLFROOT)/wolfcrypt/src/port/arm/armv8-curve25519.o\
	$(WOLFROOT)/wolfcrypt/src/port/arm/armv8-sha512.o\
	$(WOLFROOT)/wolfcrypt/src/port/arm/armv8-sha512-asm_c.o\
	$(WOLFROOT)/wolfcrypt/src/port/arm/armv8-sha256.o\

OBJ_X86_64=\
	$(WOLFROOT)/wolfcrypt/src/cpuid.o\
	$(WOLFROOT)/wolfcrypt/src/ge_operations.o\
	$(WOLFROOT)/wolfcrypt/src/fe_x25519_asm.o\
	$(WOLFROOT)/wolfcrypt/src/sha512.o\
	$(WOLFROOT)/wolfcrypt/src/sha256.o\


.PHONY: all clean mem size bench

ifeq ($(mem) ,low) 
OBJ += $(OBJ_LOW_MEM)
CFLAGS += -DED25519_SMALL
CFLAGS += -DCURVE25519_SMALL
else ifeq ($(arch), arm64)
OBJ += $(OBJ_ARM64)
ASFLAGS += -DFE_ARM64_FLAG
CFLAGS += -DFE_ARM64_FLAG
else ifeq ($(arch), x64)
OBJ += $(OBJ_X86_64)
ASFLAGS += -DFE_X86_64_FLAG
CFLAGS += -DFE_X86_64_FLAG
else
OBJ += $(OBJ_NORMAL)
endif

all : ed25519_sign_verify bench mem

ed25519_sign_verify: clean $(OBJ)
	$(CC) $(CFLAGS) -o ed25519_sign_verify ed25519_sign_verify.c $(OBJ) 

bench: clean $(OBJ)
	$(CC) $(CFLAGS) -DBENCHMARK -o ed25519_sign_verify_bench ed25519_sign_verify.c $(OBJ) -lpthread

mem: clean $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG_MEMORY -o ed25519_sign_verify_mem ed25519_sign_verify.c $(OBJ) -lpthread
clean:
	rm -f ed25519_sign_verify ed25519_sign_verify_bench ed25519_sign_verify_mem $(WOLFROOT)/wolfcrypt/src/*.o $(WOLFROOT)/wolfcrypt/src/port/arm/*.o

size :
	size $(OBJ) ed25519_sign_verify
