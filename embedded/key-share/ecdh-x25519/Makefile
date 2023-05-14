# The path to the wolfssl directory must be set correctly for your environment.
WOLFROOT = ../../../../wolfssl

CFLAGS = $(EX_CFLAGS) -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT) -Os
ASFLAGS = -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT)

OBJ=\
	$(WOLFROOT)/wolfcrypt/src/curve25519.o\
	$(WOLFROOT)/wolfcrypt/src/random.o\
	$(WOLFROOT)/wolfcrypt/src/memory.o\
	$(WOLFROOT)/wolfcrypt/src/wc_port.o\
	$(WOLFROOT)/wolfcrypt/src/wolfmath.o\


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

all: ecdh bench mem

ecdh: clean $(OBJ)
	$(CC) $(CFLAGS) -o ecdh_x25519 main.c ecdh_x25519.c channel.c $(OBJ) -lpthread
bench: clean $(OBJ)
	$(CC) $(CFLAGS) -DBENCHMARK -o ecdh_x25519_bench main.c ecdh_x25519.c channel.c $(OBJ) -lpthread
mem: clean $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG_MEMORY -o ecdh_x25519_mem main.c ecdh_x25519.c channel.c $(OBJ) -lpthread
clean:
	rm -f ecdh_x25519 ecdh_x25519_* $(WOLFROOT)/wolfcrypt/src/*.o *.o
size :
	size $(OBJ) ecdh
