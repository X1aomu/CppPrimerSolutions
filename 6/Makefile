CC = g++
CCFLAGS = -Og -Wall -Wextra -ggdb -lm -std=c++11
INCLUDES =

CC_SRCS = $(wildcard *.cc)
CC_BINS = $(patsubst %.cc, %, $(CC_SRCS))

.PHONY: all

all: $(CC_BINS)

%: %.cc
	-$(CC) $(CCFLAGS) $(INCLUDES) -o $@ $<

clean:
	rm -f *\~ .*.un\~

clobber: clean
	rm -f $(CC_BINS)

