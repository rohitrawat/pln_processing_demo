all: pln_processing pln_processing_nofiles

%: %.c
	gcc -g $< -o $@

