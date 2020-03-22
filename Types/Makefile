.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -Wno-deprecated-copy -I../.Include

OBJS=Defines.o Bitwise.o Convert.o

all: Defines.o Bitwise.o Convert.o Prepare
	@MakeInfo dynamic Types
	@$(CC) -shared -fPIC $(OBJS) -o ${BUILDDIR}/lib/libTypes.so
	@MakeInfo static Types
	@$(AR) rcs ${BUILDDIR}/lib/libTypes.a $(OBJS)

Defines.o: Defines.cpp Defines.h
	@MakeInfo module Defines
	@$(CC) $(CXXFLAGS) -c $< -o $@

Bitwise.o: Bitwise.cpp Bitwise.h
	@MakeInfo module Bitwise
	@$(CC) $(CXXFLAGS) -c $< -o $@

Convert.o: Convert.cpp Convert.h
	@MakeInfo module Convert
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: Defines.h Bitwise.h Convert.h
	@mkdir ${BUILDDIR}/inc/Types
	@cp -f $^ ${BUILDDIR}/inc/Types/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libTypes.so ${BUILDDIR}/lib/libTypes.a

