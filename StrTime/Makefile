.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -I../.Include

all: StrTime.o Prepare
	@MakeInfo dynamic StrTime
	@$(CC) -shared -fPIC $< -o ${BUILDDIR}/lib/libStrTime.so
	@MakeInfo static StrTime
	@$(AR) rcs ${BUILDDIR}/lib/libStrTime.a $<

StrTime.o: StrTime.cpp StrTime.h
	@MakeInfo module StrTime
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: StrTime.h
	@cp -f $< ${BUILDDIR}/inc/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libStrTime.so ${BUILDDIR}/lib/libStrTime.a

