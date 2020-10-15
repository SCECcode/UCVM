#!/bin/bash
## 
## example of running on usc/hpc cluster
##

if [ -z "$UCVM_INSTALL_PATH" ]; then
  echo "Need to set UCVM_INSTALL_PATH to run >" ${0##*/} 
  exit
fi

if [ -f "/usr/usc/openmpi/default/setup.sh" ]; then
  source /usr/usc/openmpi/default/setup.sh
  echo "Running on usc hpc cluster >" ${0##*/}             
fi

BIN_DIR=${UCVM_INSTALL_PATH}/bin
CONF_DIR=${UCVM_INSTALL_PATH}/conf
TEST=basin_query_mpi_cvms5

expect=$(mktemp) || exit 1
result=$(mktemp) || (trap 'rm -f "$expect"'; exit 1)

salloc --ntasks=2 --time=00:10:00 srun -Q --ntasks=2 -o ${TEST}.srun.out -v ${BIN_DIR}/basin_query_mpi -b ${TEST}.simple -f ${CONF_DIR}/ucvm.conf -m cvms5 -i 20 -v 2500 -l 35.0,-122.5 -s 0.1 -x 16 -y 11

od ${TEST}.simple |tail -10 > $result 2>&1

cat > $expect << EOF_EXPECTED_RESULT
*
0001040 000000 137600 000000 137600 000000 137600 000000 000000
0001060 000000 000000 000000 000000 000000 000000 000000 000000
0001100 000000 137600 000000 137600 000000 137600 000000 137600
*
0001160 000000 000000 000000 000000 000000 000000 000000 000000
0001200 000000 137600 000000 137600 000000 137600 000000 137600
*
0001260 000000 137600 000000 000000 000000 000000 000000 000000
0001300
EOF_EXPECTED_RESULT

echo "Running examples_programs_basin basin_query_mpi_cvms5"
if diff $result $expect > /dev/null 2>&1
then
  echo [SUCCESS]
else
  echo [FAILURE]
fi
                               
trap 'rm -f "$expect" "$result"' exit



