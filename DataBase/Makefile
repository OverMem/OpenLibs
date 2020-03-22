.PHONY: clean, Prepare

.SUFFIXES:

CC=g++
AR=ar
BUILDDIR=../build
CXXFLAGS = -fPIC -O2 -s -Wall -Wextra -Werror -I../.Include -I../.Include/deps

all: DataBase.o Prepare
	@MakeInfo dynamic DataBase
	@$(CC) -shared -fPIC $< -o ${BUILDDIR}/lib/libDataBase.so
	@MakeInfo static DataBase
	@$(AR) rcs ${BUILDDIR}/lib/libDataBase.a $<

DataBase.o: DataBase.cpp DataBase.h
	@MakeInfo module DataBase
	@$(CC) $(CXXFLAGS) -c $< -o $@

Prepare: DataBase.h
	@cp -f $< ${BUILDDIR}/inc/

clean:
	@rm -f *.o ${BUILDDIR}/lib/libDataBase.so ${BUILDDIR}/lib/libDataBase.a

