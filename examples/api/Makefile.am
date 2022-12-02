# Autoconf/Automake binaries and headers
#
#
bin_PROGRAMS = query_1d_gtl 
query_1d_gtl_SOURCES = *.c

# General compiler/linker flags
AM_CFLAGS = -I../../src/ucvm
AM_LDFLAGS = -L../../src/ucvm -lucvm $(LDFLAGS)

check_PROGRAMS = run_query_1d_gtl.sh
run_query_1d_gtl_sh_SOURCES = run_query_1d_gtl.sh

all: $(bin_PROGRAMS)

############################################
# Executables
############################################

query_1d_gtl: query_1d_gtl.o 
	$(CC) -o $@ $^ $(AM_LDFLAGS)


############################################
# Special build targets
############################################

check: $(check_PROGRAMS) 
	@( cd ${prefix}/tests/api; \
	for i in $(check_PROGRAMS); do \
		./$${i}; \
	done \
	)

install: $(bin_PROGRAMS) $(check_PROGRAMS)
	mkdir -p ${prefix}/tests/api
	@for i in $(bin_PROGRAMS); do \
		cp $${i} ${prefix}/tests/api; \
	done
	@for i in $(check_PROGRAMS); do \
		cp $${i} ${prefix}/tests/api; \
		echo "(cd api; ./$${i})" >> ${prefix}/tests/run-testing;\
	done

clean: 
	rm -f *.o *~ $(noinst_PROGRAMS)


