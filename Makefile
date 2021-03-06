export MALLOC_MMAP_THRESHOLD_=1
export MALLOC_CHECK_=1
export MALLOC_PERTURB_=1
CC=gcc
CFLAGS=-Wall -Wextra -O2 -fstack-protector-all -D_FORTIFY_SOURCE=2

all: 
	$(CC) -o bin_test/ice_config_test src_test/main.c lib/ice_config.c lib/ice_config_mem.c $(CFLAGS)

clean:
	rm -rf *.o bin_test/*
