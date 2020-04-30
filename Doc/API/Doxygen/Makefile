.SUFFIXES:

all: Doxyfile
	@MakeInfo doc API
	@doxygen Doxyfile >> /dev/null 2>&1
	@cp -f Makefile_latex latex/Makefile
	@make -C latex --no-print-directory

