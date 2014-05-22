# optimization executables -- https://github.com/eschulte/optimization
OPT=goa
OBJ=objread
DELTA=delta
# optimization flags
WORKDIR:=
VERBOSE:=0
REPRSNT:=asm
THREADS:=2
POPSIZE:=256
OPTFLAG:=-t $(THREADS) -p $(POPSIZE) -R $(REPRSNT) -v $(VERBOSE)
ifneq ($(WORKDIR),)
	OPTFLAG+=-w $(WORKDIR)
endif

# cool compiler -- http://www.cs.virginia.edu/~weimer/4610/cool.html
CLC=bin/cool
MLC=ocamlopt
MLCFLAGS=-w -1..45

C_SRC=$(wildcard assignments/*.c)
C_ASM=$(C_SRC:.c=-c.s)
C_EXE=$(C_ASM:.s=)

C_DIRS=$(notdir $(C_EXE))
C_CYCL=$(addprefix results/cycles/,$(C_DIRS))
C_CACH=$(addprefix results/cache-references/,$(C_DIRS))
C_SIZE=$(addprefix results/size/,$(C_DIRS))

ML_SRC=$(wildcard assignments/*.ml)
ML_ASM=$(ML_SRC:.ml=-ml.s)
ML_EXE=$(ML_ASM:.s=)

ML_DIRE=$(knotted $(ML_EXE))
ML_CYCL=$(addprefix results/cycles/,$(ML_DIRS))
ML_CACH=$(addprefix results/cache-references/,$(ML_DIRS))
ML_SIZE=$(addprefix results/size/,$(ML_DIRS))

CL_SRC=$(wildcard assignments/*.cl)
CL_ASM=$(CL_SRC:.cl=-cl.s)
CL_EXE=$(CL_ASM:.s=)

.PHONY: clean all list tests graph-performance evolve-all evolve-cycles evolve-caches evolve-sizes

all: $(C_EXE) $(ML_EXE) $(CL_EXE) big-test big-checker bin/limit

## Program Compilation
%-c.s: %.c
	$(CC) -S $< -O3 -o $@

%-ml.s: %.ml
	$(MLC) $(MLCFLAGS) -dstartup -S $< -o $@
	chmod -x $@
	cat $*.s > $@
	echo "###----------------------------------------" >> $@
	cat $*-ml.s.startup.s >> $@
	rm $*{.s,-ml.s.startup.s,.o,.cmi,.cmx}

%-ml: %-ml.s
	mll -o $@ $<

%-cl.s:  %.cl
	$(CLC) --x86 $< --out $$(dirname $@)/$$(basename $@ .s)

list:
	@for i in assignments/*;do echo $$(basename $$i); done

big-test:
	@for top in $$(seq 10000);do \
	  echo $$top; \
	  echo $$((RANDOM % $$top)); \
	done > $@

big-checker: big-test
	@to-checker $<|gcc -x c - -static -O3 -o $@

## Program Evolution
CYCLES_SCRIPT="evaluate ~a -s0 -ecycles"
CACHE_SCRIPT="evaluate ~a -s0 -ecache-references"
SIZE_SCRIPT="evaluate ~a -s0 -b -S"

evolve-c-cycles: $(C_CYCL)
evolve-c-caches: $(C_CACH)
evolve-c-sizes:  $(C_SIZE)
evolve-ml-cycles: $(ML_CYCL)
evolve-ml-caches: $(ML_CACH)
evolve-ml-sizes:  $(ML_SIZE)

evolve-c-all: evolve-c-cycles evolve-c-caches evolve-c-sizes
evolve-ml-all: evolve-ml-cycles evolve-ml-caches evolve-ml-sizes

evolve-all: evolve-c-all evolve-ml-all

results/cycles/%-c: assignments/%-c.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) $(CYCLES_SCRIPT) $< $(OPTFLAG) -r $@

results/cycles/%-ml: assignments/%-ml.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) $(CYCLES_SCRIPT) $< -l mll $(OPTFLAG) -r $@

results/cache-references/%-c: assignments/%-c.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) $(CACHE_SCRIPT) $< $(OPTFLAG) -r $@

results/cache-references/%-ml: assignments/%-ml.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) $(CACHE_SCRIPT) $< -l mll $(OPTFLAG) -r $@

results/size/%-c: assignments/%-c.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) $(SIZE_SCRIPT) $< $(OPTFLAG) -r $@

results/size/%-ml: assignments/%-ml.s big-checker big-test bin/limit
	@mkdir -p $@
	@cp big-checker big-test $@
	-$(OPT) $(SIZE_SCRIPT) $< -l mll $(OPTFLAG) -r $@

results/cycles/%/minimized.store: results/cycles/%/final-best.store
	$(DELTA) $(CYCLES_SCRIPT) $(dir $<)original.store $< -o $@

results/cache-references/%/minimized.store: results/cache-references/%/final-best.store
	$(DELTA) $(CACHE_SCRIPT) $(dir $<)original.store $< -o $@

results/size/%/minimized.store: results/size/%/final-best.store
	$(DELTA) $(SIZE_SCRIPT) $(dir $<)original.store $< -o $@

## Results Collection
#
# Collect experimental results from REMOTE_DIR, the form of which
# should be acceptable by rsync, e.g. "host:experiments/stuop".
#
collect:
	rsync -aruvz --delete --exclude "best-*.store" --exclude "final-pop.store" \
	$(REMOTE_DIR)/results/ results

## Statistics Collection
%.exe: %.store
	$(OBJ) $< -l $@

%.out: %.exe
	-cat big-test|./$< > $@

%.check: %.out
	-./big-checker $<|tee $@

results/cycles/%.runs: results/cycles/%.exe
	@-for i in $$(seq 100);do evaluate $< -s0 -ecycles; done>$@

results/cache-references/%.runs: results/cache-references/%.exe
	@-for i in $$(seq 100);do evaluate $< -s0 -ecache-references; done>$@

results/size/%.runs: results/size/%.exe
	@-for i in $$(seq 100);do evaluate $< -s0 -b -s; done>$@

%.stats: %.runs
	@echo "$$(cat $<|mean) $$(cat $<|stdev)"|tee $@

results/cycles.improvement:
	@for run in results/cycles/*.stats;do \
	echo "$$(basename $$run) $$(cat $$run) $$(cat $${run%.stats}/stats.txt|tail -1|awk '{print $$2}')" \
	|awk '{print $$1, (($$2 - $$4)/$$2)*100}'; \
	done|tee $@

stats.txt:
	@stats|tee $@

graph-performance: stats.txt
	@tail -n +2 $<|grep -v NA|cut -f4-\
	|feedgnuplot --3d --domain --xlabel size --ylabel memory --zlabel runtime --title Performance

## Administrative
clean:
	@rm -f $(C_ASM) $(CL_ASM) $(C_EXE) $(CL_EXE) \
	assignments/*.{o,s,cmx,cmi} \
	tests/* big-test big-checker

real-clean: clean
	@rm -f stats
