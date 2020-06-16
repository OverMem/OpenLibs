.PHONY: clean, mrproper, install, uninstall

.SUFFIXES:

PDIR=${PATH}
LIBDIR=/usr/lib/OPEN
INCDIR=/usr/include/OPEN
SHAREDIR=/usr/share/OPEN
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
	@install -d ${LIBDIR}
	@install -d ${LIBDIR}/Dynamic
	@install -d ${LIBDIR}/Static
	@install -d ${INCDIR}
	@install -d ${INCDIR}/File
	@install -d ${INCDIR}/OCL
	@install -d ${INCDIR}/Types
	@install -d ${SHAREDIR}
	@MakeInfo install "Dynamic libs"
	@install -D ${BUILDDIR}/lib/*.so ${LIBDIR}/Dynamic/
	@MakeInfo install "Static  libs"
	@install -D ${BUILDDIR}/lib/*.a ${LIBDIR}/Static/
	@MakeInfo install "Headers"
	@install -D ${BUILDDIR}/inc/File/*.h ${INCDIR}/File
	@install -D ${BUILDDIR}/inc/OCL/*.h ${INCDIR}/OCL
	@install -D ${BUILDDIR}/inc/Types/*.h ${INCDIR}/Types
	@install -D ${BUILDDIR}/inc/*.h ${INCDIR}
	@MakeInfo install "API doc"
	@install -D Doc/API/Doxygen/latex/API.pdf ${SHAREDIR}
	@install -D Doc/API/Doxygen/latex/Logo.svg ${SHAREDIR}
	@MakeInfo install "OSC doc"
	@install -D Doc/OSC/latex/OSC.pdf ${SHAREDIR}
#	@MakeInfo install "Deps Headers"
#	@install -D ./.Include/deps/*/ ${INCDIR}/../

uninstall:
	@rm -Rf ${LIBDIR}
	@rm -Rf ${INCDIR}
	@rm -Rf ${SHAREDIR}

