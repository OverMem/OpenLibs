.PHONY: clean, mrproper, install, uninstall

.SUFFIXES:

LIBDIR=${LIBS}/lib/OPEN
INCDIR=${LIBS}/include/OPEN
BUILDDIR=./build
Dirs=BinRes DataBase File MArgs OCL StrTime Types Utils

all:
	@mkdir -p ${BUILDDIR}/{lib,inc}
	@@for d in $(Dirs); do \
	MakeInfo making $$d; \
	Lines 1; \
	make -C $$d --no-print-directory; \
	Lines 2; \
	done

clean:
	@@for d in $(Dirs); do \
	MakeInfo clean $$d; \
	make -C $$d clean --no-print-directory; \
	done

mrproper: clean
	@rm -Rf ${BUILDDIR}/

install:
	@mkdir -p ${LIBDIR}/{Dynamic,Static} ${INCDIR}
	@MakeInfo install "Dynamic libs"
	@cp -f ${BUILDDIR}/lib/*.so ${LIBDIR}/Dynamic/
	@MakeInfo install "Static  libs"
	@cp -f ${BUILDDIR}/lib/*.a ${LIBDIR}/Static/
	@MakeInfo install "Headers"
	@cp -Rf ${BUILDDIR}/inc/*/ ${BUILDDIR}/inc/*.h ${INCDIR}
	@MakeInfo install "Deps Headers"
	@cp -Rf ./.Include/deps/*/ ${INCDIR}/../

uninstall:
	@rm -Rf ${LIBDIR}
	@rm -Rf ${INCDIR}

