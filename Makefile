# compile assembler from source files
CLC=bin/cool

# the following assignments don't compile
FAILING=assignment/ps1/2SSoOGQF/rosetta.c	\
	assignment/ps1/TLicMRny/rosetta.c	\
	assignment/ps1/2SSoOGQF/rosetta.cl	\
	assignment/ps1/SOu34Zkh/rosetta.cl	\
	assignment/ps1/bLmcriBf/rosetta.cl

C_ALL=$(wildcard assignment/ps1/*/rosetta.c)
C_SRC=$(filter-out $(FAILING),$(C_ALL))
C_ASM=$(C_SRC:.c=-c.s)
C_EXE=$(C_ASM:.s=)

CL_ALL=$(wildcard assignment/ps1/*/rosetta.cl)
CL_SRC=$(filter-out $(FAILING),$(CL_ALL))
CL_ASM=$(CL_SRC:.cl=-cl.s)
CL_EXE=$(CL_ASM:.s=)

.PHONY: clean all

all: $(C_EXE) $(CL_EXE)

%-c.s: %.c
	$(CC) -S $< -o $@

%-cl.s:  %.cl
	$(CLC) --x86 $< --out $$(dirname $@)/$$(basename $@ .s)

clean:
	@rm -f $(C_ASM) $(CL_ASM) $(C_EXE) $(CL_EXE)
