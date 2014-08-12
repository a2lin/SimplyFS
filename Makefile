TARGETS = simplyfs

CC ?= gcc
CFLAGS_OSXFUSE = -D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26 -I/usr/local/include/osxfuse/fuse
CFLAGS_EXTRA = -Wall -g $(CFLAGS)
LIBS = -losxfuse

.c:
	$(CC) $(CFLAGS_OSXFUSE) $(CFLAGS_EXTRA) -o $@ $< $(LIBS)

all: $(TARGETS)

simplyfs: simplyfs.c

clean:
	rm -f $(TARGETS) *.o
