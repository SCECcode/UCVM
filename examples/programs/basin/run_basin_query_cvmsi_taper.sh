#!/bin/bash

if [ -z "$UCVM_INSTALL_PATH" ]; then
  echo "Need to set UCVM_INSTALL_PATH to run >" ${0##*/} 
  exit
fi
source $UCVM_INSTALL_PATH/conf/ucvm_env.sh

BIN_DIR=${UCVM_INSTALL_PATH}/bin
CONF_DIR=${UCVM_INSTALL_PATH}/conf
TEST_DIR=${UCVM_INSTALL_PATH}/tests/inputs
MODEL=cvmsi,elygtl:taper

expect=$(mktemp) || exit 1
result=$(mktemp) || (trap 'rm -f "$expect"'; exit 1)

${BIN_DIR}/basin_query -m ${MODEL} -f ${CONF_DIR}/ucvm.conf -v 2500.0 < ${TEST_DIR}/test_latlons_taper.txt > $result 2>&1

cat > $expect << EOF_EXPECTED_RESULT_Z2500
 -117.9350    33.2550    520.000    520.000    520.000
 -119.0350    34.1100    420.000   2060.000   2120.000
 -118.7600    34.1100    500.000   1180.000   1180.000
EOF_EXPECTED_RESULT_Z2500

echo "Running examples_programs_basin z2500 basin_query_cvmi_taper"
if diff $result $expect > /dev/null 2>&1
then
  echo [SUCCESS]
else
  echo [FAILURE]
fi

trap 'rm -f "$expect" "$result"' exit

expect=$(mktemp) || exit 1
result=$(mktemp) || (trap 'rm -f "$expect"'; exit 1)

${BIN_DIR}/basin_query -m ${MODEL} -f ${CONF_DIR}/ucvm.conf -v 1000.0 < ${TEST_DIR}/test_latlons_taper.txt > $result 2>&1

cat > $expect << EOF_EXPECTED_RESULT_Z1000
 -117.9350    33.2550    140.000    140.000    140.000
 -119.0350    34.1100    320.000    320.000    320.000
 -118.7600    34.1100    160.000    320.000    320.000
EOF_EXPECTED_RESULT_Z1000

echo "Running examples_programs_basin z1000 basin_query_cvmi_taper"
if diff $result $expect > /dev/null 2>&1
then
  echo [SUCCESS]
else
  echo [FAILURE]
fi

trap 'rm -f "$expect" "$result"' exit

