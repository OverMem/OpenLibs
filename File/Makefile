.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -I../.Include

OBJS=BasicConf.o BConf.o SConf.o Loggr.o

all: BasicConf.o BConf.o SConf.o Loggr.o Prepare
	@MakeInfo dynamic File
	@$(CC) -shared -fPIC $(OBJS) -o ${BUILDDIR}/lib/libFile.so
	@MakeInfo static File
	@$(AR) rcs ${BUILDDIR}/lib/libFile.a $(OBJS)

BasicConf.o: Conf/BasicConf.cpp Conf/BasicConf.h
	@MakeInfo module BasicConf
	@$(CC) $(CXXFLAGS) -c $< -o $@

BConf.o: Conf/BConf.cpp Conf/BConf.h
	@MakeInfo module BConf
	@$(CC) $(CXXFLAGS) -c $< -o $@

SConf.o: Conf/SConf.cpp Conf/SConf.h
	@MakeInfo module SConf
	@$(CC) $(CXXFLAGS) -c $< -o $@

Loggr.o: Log/Loggr.cpp Log/Loggr.h
	@MakeInfo module Loggr
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: Conf/BasicConf.h Conf/BConf.h Conf/SConf.h Log/Loggr.h
	@mkdir ${BUILDDIR}/inc/File
	@cp -f $^ ${BUILDDIR}/inc/File/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libFile.so ${BUILDDIR}/lib/libFile.a

