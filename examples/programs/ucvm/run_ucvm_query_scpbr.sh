#!/bin/bash

if [ -z "$UCVM_INSTALL_PATH" ]; then
  echo "Need to set UCVM_INSTALL_PATH to run >" ${0##*/} 
  exit
fi
source $UCVM_INSTALL_PATH/conf/ucvm_env.sh

BIN_DIR=${UCVM_INSTALL_PATH}/bin
CONF_DIR=${UCVM_INSTALL_PATH}/conf
TEST_DIR=${UCVM_INSTALL_PATH}/tests/inputs
MODEL=scpbr

expect=$(mktemp) || exit 1
result=$(mktemp) || (trap 'rm -f "$expect"'; exit 1)

${BIN_DIR}/ucvm_query -m ${MODEL} -f ${CONF_DIR}/ucvm.conf < ${TEST_DIR}/test_latlons_scpbr_gd.txt  > $result 2>&1

cat > $expect << EOF_EXPECTED_RESULT
Using Geo Depth coordinates as default mode.
 -115.8000    32.9000      0.000     13.128    228.191      scpbr   2754.400   1197.794   2165.403       none      0.000      0.000      0.000      crust   2754.400   1197.794   2165.403
 -115.8000    32.9000   3000.000     13.128    228.191      scpbr   5153.300   3105.437   2558.892       none      0.000      0.000      0.000      crust   5153.300   3105.437   2558.892
 -115.8000    32.9000   6000.000     13.128    228.191      scpbr   6178.600   3630.745   2756.117       none      0.000      0.000      0.000      crust   6178.600   3630.745   2756.117
 -115.5000    32.7000      0.000     -0.968    228.251       none      0.000      0.000      0.000       none      0.000      0.000      0.000       none      0.000      0.000      0.000
 -115.5000    32.7000   3000.000     -0.968    228.251       none      0.000      0.000      0.000       none      0.000      0.000      0.000       none      0.000      0.000      0.000
 -115.5000    32.7000   6000.000     -0.968    228.251       none      0.000      0.000      0.000       none      0.000      0.000      0.000       none      0.000      0.000      0.000
 -115.7000    33.2000      0.000    -71.002    180.000      scpbr   2841.300   1273.127   2187.220       none      0.000      0.000      0.000      crust   2841.300   1273.127   2187.220
 -115.7000    33.2000   3000.000    -71.002    180.000      scpbr   4609.900   2750.054   2477.536       none      0.000      0.000      0.000      crust   4609.900   2750.054   2477.536
 -115.7000    33.2000   6000.000    -71.002    180.000      scpbr   5941.400   3522.052   2704.210       none      0.000      0.000      0.000      crust   5941.400   3522.052   2704.210
EOF_EXPECTED_RESULT

echo "Running examples_programs_ucvm ucvm_query_scpbr"
if diff $result $expect > /dev/null 2>&1
then
  echo [SUCCESS]
else
  echo [FAILURE]
fi

trap 'rm -f "$expect" "$result"' exit
