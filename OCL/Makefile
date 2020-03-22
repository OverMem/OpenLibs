.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -I../.Include -I../.Include/deps

OBJS=SHA256.o Random.o Blowfish.o RSA.o CRC.o

all: SHA256.o Random.o Blowfish.o RSA.o CRC.o Prepare
	@MakeInfo dynamic OCL
	@$(CC) -shared -fPIC $(OBJS) -o ${BUILDDIR}/lib/libOCL.so
	@MakeInfo static OCL
	@$(AR) rcs ${BUILDDIR}/lib/libOCL.a $(OBJS)

SHA256.o: SHA256.cpp SHA256.h
	@MakeInfo module SHA256
	@$(CC) $(CXXFLAGS) -c $< -o $@

Random.o: Random.cpp Random.h
	@MakeInfo module Random
	@$(CC) $(CXXFLAGS) -c $< -o $@

Blowfish.o: Blowfish.cpp Blowfish.h
	@MakeInfo module Blowfish
	@$(CC) $(CXXFLAGS) -c $< -o $@

RSA.o: RSA.cpp RSA.h
	@MakeInfo module RSA
	@$(CC) $(CXXFLAGS) -c $< -o $@

CRC.o: CRC.cpp CRC.h
	@MakeInfo module CRC
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: SHA256.h Random.h Blowfish.h RSA.h CRC.h
	@mkdir ${BUILDDIR}/inc/OCL
	@cp -f $^ ${BUILDDIR}/inc/OCL/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libOCL.so ${BUILDDIR}/lib/libOCL.a

