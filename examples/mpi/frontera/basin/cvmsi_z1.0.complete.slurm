#!/bin/bash
#SBATCH -J cvmsi_z1.0.complete
#SBATCH -o cvmsi_z1.0.complete.out
#SBATCH -e cvmsi_z1.0.complete.err
#SBATCH -p small
#SBATCH -N 2
#SBATCH -n 4 
#SBATCH -t 00:30:00 
#SBATCH --mail-user=mei@usc.edu

export TEST_TOP_PATH=/home1/07508/mei/scratch1/TARGET_UCVM/ucvm/examples/mpi/frontera/basin

###############################################################################

cp ${UCVM_INSTALL_PATH}/bin/basin_query_mpi_complete .
cp ${UCVM_INSTALL_PATH}/conf/ucvm.conf .
cp ${UCVM_INSTALL_PATH}/conf/ucvm_env.sh .

source ./ucvm_env.sh

TEST=cvmsi_z1.0.complete

ibrun -v --mpi=pmi2 ./basin_query_mpi_complete -b ${TEST_TOP_PATH}/RESULT/${TEST}.first,${TEST_TOP_PATH}/RESULT/${TEST}.firstOrSecond,${TEST_TOP_PATH}/RESULT/${TEST}.last,${TEST_TOP_PATH}/RESULT/${TEST}.secondOnly,${TEST_TOP_PATH}/RESULT/${TEST}.threeLast -o ${TEST_TOP_PATH}/RESULT/${EST}.result,${TEST_TOP_PATH}/RESULT/${TEST}.json -f ./ucvm.conf -m cvmsi -i 10 -v 1000 -l 33.25,-119.38 -s 0.005 -x 578 -y  366

ret=$?

echo "Slurm Jobs done" `date`
exit $ret

