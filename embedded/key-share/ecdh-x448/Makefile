# The path to the wolfssl directory must be set correctly for your environment.
WOLFROOT = ../../../../wolfssl

CFLAGS = $(EX_CFLAGS) -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT) -Os
ASFLAGS = -DWOLFSSL_USER_SETTINGS -I. -I$(WOLFROOT)

OBJ=\
	$(WOLFROOT)/wolfcrypt/src/curve448.o\
	$(WOLFROOT)/wolfcrypt/src/random.o\
	$(WOLFROOT)/wolfcrypt/src/memory.o\
	$(WOLFROOT)/wolfcrypt/src/wc_port.o\
	$(WOLFROOT)/wolfcrypt/src/wolfmath.o\
	$(WOLFROOT)/wolfcrypt/src/ge_448.o\
	$(WOLFROOT)/wolfcrypt/src/fe_448.o\
	$(WOLFROOT)/wolfcrypt/src/sha512.o\
	$(WOLFROOT)/wolfcrypt/src/sha256.o\





.PHONY: all clean mem size bench


all: ecdh bench mem

ecdh: clean $(OBJ)
	$(CC) $(CFLAGS) -o ecdh_x448 main.c ecdh_x448.c channel.c $(OBJ) -lpthread
bench: clean $(OBJ)
	$(CC) $(CFLAGS) -DBENCHMARK -o ecdh_x448_bench main.c ecdh_x448.c channel.c $(OBJ) -lpthread
mem: clean $(OBJ)
	$(CC) $(CFLAGS) -DDEBUG_MEMORY -o ecdh_x448_mem main.c ecdh_x448.c channel.c $(OBJ) -lpthread
clean:
	rm -f ecdh_x448 ecdh_x448_* $(WOLFROOT)/wolfcrypt/src/*.o *.o
size :
	size $(OBJ) ecdh
