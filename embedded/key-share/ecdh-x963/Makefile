WOLFROOT = ../../../../wolfssl

CFLAGS = $(EX_CFLAGS) -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT) -Os
ASFLAGS=-DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT)

OBJ = \
	$(WOLFROOT)/wolfcrypt/src/ecc.o\
	$(WOLFROOT)/wolfcrypt/src/random.o\
	$(WOLFROOT)/wolfcrypt/src/memory.o\
	$(WOLFROOT)/wolfcrypt/src/sha256.o\
	$(WOLFROOT)/wolfcrypt/src/wc_port.o\
	$(WOLFROOT)/wolfcrypt/src/wolfmath.o\

OBJ_SP_C32 := \
	$(WOLFROOT)/wolfcrypt/src/sp_int.o\
	$(WOLFROOT)/wolfcrypt/src/sp_c32.o\

OBJ_SP_C64 := \
	$(WOLFROOT)/wolfcrypt/src/sp_int.o\
	$(WOLFROOT)/wolfcrypt/src/sp_c64.o\

OBJ_SP_ARM64 := \
	$(WOLFROOT)/wolfcrypt/src/sp_int.o\
	$(WOLFROOT)/wolfcrypt/src/sp_arm64.o\


OBJ_SP_X86_64 := \
	$(WOLFROOT)/wolfcrypt/src/sp_int.o\
	$(WOLFROOT)/wolfcrypt/src/cpuid.o\
	$(WOLFROOT)/wolfcrypt/src/sp_x86_64.o\
	$(WOLFROOT)/wolfcrypt/src/sp_x86_64_asm.o\

.PHONY: all clean size bench mem 

ifeq ($(math) $(arch),sp x64) 
ASFLAGS+= -DSP_X86_64_FLAG
CFLAGS += -DSP_X86_64_FLAG
OBJ += $(OBJ_SP_X86_64)
else ifeq ($(math) $(arch),sp arm64)
CFLAGS += -DSP_ARM64_FLAG
OBJ += $(OBJ_SP_ARM64)
else ifeq ($(math) $(arch),sp c64)
CFLAGS += -DSP_C64_FLAG
OBJ += $(OBJ_SP_C64)
else ifeq ($(math) $(arch),sp c32)
CFLAGS += -DSP_C32_FLAG
OBJ += $(OBJ_SP_C32)
else 
CFLAGS += -DSP_C64_FLAG
OBJ += $(OBJ_SP_C64)
endif

all: ecdh bench mem

ecdh: clean $(OBJ)
	$(CC) $(CFLAGS) -o ecdh main.c ecdh.c channel.c $(OBJ) -lpthread
bench: clean $(OBJ)
	$(CC) $(CFLAGS) -DBENCHMARK -o ecdh_bench main.c ecdh.c channel.c $(OBJ) -lpthread
mem: clean $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG_MEMORY -o ecdh_mem main.c ecdh.c channel.c $(OBJ) -lpthread
clean:
	rm -f ecdh ecdh_* $(WOLFROOT)/wolfcrypt/src/*.o *.o
size :
	size $(OBJ) ecdh
