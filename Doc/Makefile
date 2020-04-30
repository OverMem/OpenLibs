.PHONY: clean

.SUFFIXES:

APID=API/Doxygen/latex
OSCD=OSC/latex

all: OSC/latex/OSC.pdf API/Doxygen/latex/API.pdf 

OSC/latex/OSC.pdf:
	@make -C ${OSCD} --no-print-directory
	@mv ${OSCD}/doc.pdf ${OSCD}/OSC.pdf

API/Doxygen/latex/API.pdf:
	@make -C API/Doxygen --no-print-directory
	@mv ${APID}/refman.pdf ${APID}/API.pdf

clean:
	@rm -f ${OSCD}/doc.out ${OSCD}/doc.toc ${OSCD}/doc.log ${OSCD}/doc.aux ${OSCD}/*.pdf
	@rm -f ${APID}/*.out ${APID}/*.toc ${APID}/*.log ${APID}/*.aux ${APID}/*.idx ${APID}/*.ilg ${APID}/*.ind ${APID}/*.pdf

