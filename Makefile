#* Build SFN
#  CVS $Id$

INCLUDE := -I$(HOME)/c/include/
CPPFLAGS += $(INCLUDE)
CC := g++
CXXFLAGS = -std=c++17
CFLAGS   +=-g
LDFLAGS  +=-g
CXXFLAGS +=-g
CXXFLAGS += -Wsign-conversion

# set debug or optimized code
ifeq ($(GCC_OPT),)
  CXXFLAGS +=-O0 -DDEBUG
else
  CXXFLAGS +=-O$(GCC_OPT) -march=ivybridge
# retain assertions, even in production code
# CXXFLAGS +=-O$(GCC_OPT) -DNDEBUG
endif

sfn-x86: sfn-x86.o
evert: evert.o

all: sfn-x86

%.s: %.cpp
	$(CC) -S $@ -c $<

clean:
	rm -f *.o core sfn-x86

*.o: Makefile
