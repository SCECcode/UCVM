# Autoconf/Automake binaries and headers
#
#
bin_PROGRAMS=

# CVM-H includes
if UCVM_AM_ENABLE_CVMH
bin_PROGRAMS += run_basin_query_cvmh.sh
run_basin_query_cvmh_sh_SOURCES = run_basin_query_cvmh.sh
endif

if UCVM_HAVE_MPI

if UCVM_AM_ENABLE_CVMS5
bin_PROGRAMS += run_basin_query_mpi_cvms5.sh
run_basin_query_mpi_cvms5_sh_SOURCES = run_basin_query_mpi_cvms5.sh
endif

if UCVM_AM_ENABLE_CENCAL

if UCVM_AM_ENABLE_CVMS
bin_PROGRAMS += run_basin_query_mpi_complete_cencal_cvms.sh
run_basin_query_mpi_complete_cencal_cvms_sh_SOURCES = run_basin_query_mpi_complete_cencal_cvms.sh
bin_PROGRAMS += run_basin_query_mpi_cencal_cvms.sh
run_basin_query_mpi_cencal_cvms_sh_SOURCES = run_basin_query_mpi_cencal_cvms.sh
endif

if UCVM_AM_ENABLE_CVMS5
bin_PROGRAMS += run_basin_query_mpi_complete_cencal_cvms5.sh
run_basin_query_mpi_complete_cencal_cvms5_sh_SOURCES = run_basin_query_mpi_complete_cencal_cvms5.sh
endif

if UCVM_AM_ENABLE_CVMSI
bin_PROGRAMS += run_basin_query_mpi_complete_cencal_cvmsi.sh
run_basin_query_mpi_complete_cencal_cvmsi_sh_SOURCES = run_basin_query_mpi_complete_cencal_cvmsi.sh
bin_PROGRAMS += run_basin_query_mpi_cencal_cvmsi.sh
run_basin_query_mpi_cencal_cvmsi_sh_SOURCES = run_basin_query_mpi_cencal_cvmsi.sh
bin_PROGRAMS += run_basin_query_mpi_complete_cvmsi_taper.sh 
run_basin_query_mpi_complete_cvmsi_taper_sh_SOURCES = run_basin_query_mpi_complete_cvmsi_taper.sh 
bin_PROGRAMS += run_basin_query_mpi_cvmsi_taper.sh
run_basin_query_mpi_cvmsi_taper_sh_SOURCES = run_basin_query_mpi_cvmsi_taper.sh
endif

endif #CENCAL

endif #MPI


all: $(bin_PROGRAMS)

############################################
# Special build targets
############################################
check: $(bin_PROGRAMS)
	@( cd ${prefix}/tests/basin; \
	for i in $(bin_PROGRAMS); do \
		./$${i}; \
	done \
	)

install: $(bin_PROGRAMS)
	mkdir -p ${prefix}/tests/basin
	for i in $(bin_PROGRAMS); do \
		cp $${i} ${prefix}/tests/basin; \
		echo "(cd basin; ./$${i})" >> ${prefix}/tests/run-testing;\
	done

clean: 
	rm -f *.o *~ basin_query_mpi*


