.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -I../.Include

all: Utils.o Prepare
	@MakeInfo dynamic Utils
	@$(CC) -shared -fPIC $< -o ${BUILDDIR}/lib/libUtils.so
	@MakeInfo static Utils
	@$(AR) rcs ${BUILDDIR}/lib/libUtils.a $<

Utils.o: Utils.cpp Utils.h
	@MakeInfo module Utils
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: Utils.h
	@cp -f $< ${BUILDDIR}/inc/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libUtils.so ${BUILDDIR}/lib/libUtils.a

