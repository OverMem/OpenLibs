.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -I../.Include

all: MArgs.o Prepare
	@MakeInfo dynamic MArgs
	@$(CC) -shared -fPIC $< -o ${BUILDDIR}/lib/libMArgs.so
	@MakeInfo static MArgs
	@$(AR) rcs ${BUILDDIR}/lib/libMArgs.a $<

MArgs.o: MArgs.cpp MArgs.h
	@MakeInfo module MArgs
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: MArgs.h
	@cp -f $< ${BUILDDIR}/inc/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libMArgs.so ${BUILDDIR}/lib/libMArgs.a

