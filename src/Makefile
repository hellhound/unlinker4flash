CC=gcc
CFLAGSCOMP=$(CFLAGS) -fPIC -Wall -shared -ldl

unlinker4flash.so: unlink.c
	$(CC) $(CFLAGSCOMP) $(LDFLAGS) $^ -o $@
