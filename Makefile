.PHONY: clean, mrproper, install, uninstall

.SUFFIXES:

PDIR=${PATH}
LIBDIR=${LIBS}/lib/OPEN
INCDIR=${LIBS}/include/OPEN
SHAREDIR=${LIBS}/share/OPEN
BUILDDIR=./build
Dirs=BinRes DataBase File MArgs OCL StrTime Types Utils Doc

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
	@rm -Rf Doc/API/Doxygen/latex

install:
	@mkdir -p ${LIBDIR}/{Dynamic,Static}
	@mkdir ${INCDIR}
	@mkdir ${SHAREDIR}
	@MakeInfo install "Dynamic libs"
	@cp -f ${BUILDDIR}/lib/*.so ${LIBDIR}/Dynamic/
	@MakeInfo install "Static  libs"
	@cp -f ${BUILDDIR}/lib/*.a ${LIBDIR}/Static/
	@MakeInfo install "Headers"
	@cp -Rf ${BUILDDIR}/inc/*/ ${BUILDDIR}/inc/*.h ${INCDIR}
	@MakeInfo install "API doc"
	@cp -f Doc/API/Doxygen/latex/API.pdf Doc/API/Doxygen/latex/Logo.svg ${SHAREDIR}
	@MakeInfo install "OSC doc"
	@cp -f Doc/OSC/latex/OSC.pdf ${SHAREDIR}
#	@MakeInfo install "Deps Headers"
#	@cp -Rf ./.Include/deps/*/ ${INCDIR}/../

uninstall:
	@rm -Rf ${LIBDIR}
	@rm -Rf ${INCDIR}
	@rm -Rf ${SHAREDIR}

