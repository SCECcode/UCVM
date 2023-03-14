# Autoconf/Automake binaries and headers
#
#
bin_PROGRAMS=

if UCVM_AM_ENABLE_CVMS5
bin_PROGRAMS += run_ucvm2surface_cvms5.sh
run_ucvm2surface_cvms5_sh_SOURCES = run_ucvm2surface_cvms5.sh
bin_PROGRAMS += run_ucvm2surface_cvms5_c.sh
run_ucvm2surface_cvms5_c_sh_SOURCES = run_ucvm2surface_cvms5_c.sh
endif


all: $(bin_PROGRAMS)
############################################
# Special build targets
############################################
check: $(bin_PROGRAMS)
	@( cd ${prefix}/tests/surface; \
	for i in $(bin_PROGRAMS); do \
		./$${i}; \
	done \
	)

install: $(bin_PROGRAMS)
	mkdir -p ${prefix}/tests/surface
	for i in $(bin_PROGRAMS); do \
		cp $${i} ${prefix}/tests/surface; \
		echo "(cd surface; ./$${i})" >> ${prefix}/tests/run-testing; \
	done

clean: 
	rm -f *.o *~


