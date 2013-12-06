# optimization executable -- https://github.com/eschulte/optimization
OPT=optimize
# optimization flags
WORKDIR:=
REPRSNT:=asm
THREADS:=2
POPSIZE:=256
OPTFLAG:=-t $(THREADS) -p $(POPSIZE) -R $(REPRSNT)
ifneq ($(WORKDIR),)
	OPTFLAG+=-w $(WORKDIR)
endif

# cool compiler -- http://www.cs.virginia.edu/~weimer/4610/cool.html
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

C_BASE=$(dir $(C_SRC))
C_DIRS=$(notdir $(C_BASE:/=-c))
C_CYCL=$(addprefix results/cycles/,$(C_DIRS))
C_CACH=$(addprefix results/cache-references/,$(C_DIRS))
C_SIZE=$(addprefix results/size/,$(C_DIRS))

CL_ALL=$(wildcard assignment/ps1/*/rosetta.cl)
CL_SRC=$(filter-out $(FAILING),$(CL_ALL))
CL_ASM=$(CL_SRC:.cl=-cl.s)
CL_EXE=$(CL_ASM:.s=)

.PHONY: clean all list tests graph-performance evolve-all evolve-cycles evolve-caches evolve-sizes

all: $(C_EXE) $(CL_EXE) big-test big-checker

## Program Compilation
%-c.s: %.c
	$(CC) -S $< -O3 -o $@

%-cl.s:  %.cl
	$(CLC) --x86 $< --out $$(dirname $@)/$$(basename $@ .s)

list:
	@for i in assignment/ps1/*;do echo $$(basename $$i); done

## Program Evaluation
tests:
	@for i in assignment/ps1/*/testcase.list;do \
	  cp $$i tests/$$(basename $$(dirname $$i)); \
	done

big-test:
	@for top in $$(seq 10000);do \
	  echo $$top; \
	  echo $$((RANDOM % $$top)); \
	done > $@

big-checker: big-test
	@to-checker $<|gcc -x c - -static -O3 -o $@

## Program Evolution
evolve-cycles: $(C_CYCL)
evolve-caches: $(C_CACH)
evolve-sizes:  $(C_SIZE)

evolve-all: evolve-cycles evolve-caches evolve-sizes

results/cycles/%-c: assignment/ps1/%/rosetta-c.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) "evaluate ~a -s0 -ecycles" $< $(OPTFLAG) -r $@

results/cache-references/%-c: assignment/ps1/%/rosetta-c.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) "evaluate ~a -s0 -ecache-reference" $< $(OPTFLAG) -r $@

results/size/%-c: assignment/ps1/%/rosetta-c.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) "evaluate ~a -s0 -b -S" $< $(OPTFLAG) -r $@

## Statistics Collection
stats.txt:
	@stats|tee $@

graph-performance: stats.txt
	@tail -n +2 $<|grep -v NA|cut -f4-\
	|feedgnuplot --3d --domain --xlabel size --ylabel memory --zlabel runtime --title Performance

## Administrative
clean:
	@rm -f $(C_ASM) $(CL_ASM) $(C_EXE) $(CL_EXE) \
	tests/* big-test big-checker

real-clean: clean
	@rm -f stats
