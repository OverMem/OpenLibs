.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -Wno-deprecated-copy -I../.Include

all: BinRes.o Prepare
	@MakeInfo dynamic BinRes
	@$(CC) -shared -fPIC $< -o ${BUILDDIR}/lib/libBinRes.so
	@MakeInfo static BinRes
	@$(AR) rcs ${BUILDDIR}/lib/libBinRes.a $<

BinRes.o: BinRes.cpp BinRes.h
	@MakeInfo module BinRes
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: BinRes.h
	@cp -f $< ${BUILDDIR}/inc/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libBinRes.so ${BUILDDIR}/lib/libBinRes.a

