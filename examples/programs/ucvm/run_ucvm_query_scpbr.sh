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
 -115.8000    32.9000      0.000     13.128    228.191      scpbr   5960.000   3390.000   2708.134       none      0.000      0.000      0.000      crust   5960.000   3390.000   2708.134
 -115.8000    32.9000   3000.000     13.128    228.191      scpbr   6120.000   3500.000   2742.913       none      0.000      0.000      0.000      crust   6120.000   3500.000   2742.913
 -115.8000    32.9000   6000.000     13.128    228.191      scpbr   6010.000   3440.000   2718.804       none      0.000      0.000      0.000      crust   6010.000   3440.000   2718.804
 -115.5000    32.7000      0.000     -0.968    228.251      scpbr   5520.000   3150.000   2621.678       none      0.000      0.000      0.000      crust   5520.000   3150.000   2621.678
 -115.5000    32.7000   3000.000     -0.968    228.251      scpbr   5620.000   3210.000   2640.195       none      0.000      0.000      0.000      crust   5620.000   3210.000   2640.195
 -115.5000    32.7000   6000.000     -0.968    228.251      scpbr   5740.000   3270.000   2663.274       none      0.000      0.000      0.000      crust   5740.000   3270.000   2663.274
 -115.7000    33.2000      0.000    -71.002    180.000      scpbr   4930.000   2750.000   2524.078       none      0.000      0.000      0.000      crust   4930.000   2750.000   2524.078
 -115.7000    33.2000   3000.000    -71.002    180.000      scpbr   5040.000   2820.000   2540.944       none      0.000      0.000      0.000      crust   5040.000   2820.000   2540.944
 -115.7000    33.2000   6000.000    -71.002    180.000      scpbr   5240.000   2940.000   2573.059       none      0.000      0.000      0.000      crust   5240.000   2940.000   2573.059
 -116.8000    33.0000      0.000    438.972    570.739      scpbr   5810.000   3390.000   2677.184       none      0.000      0.000      0.000      crust   5810.000   3390.000   2677.184
 -116.8000    33.0000   3000.000    438.972    570.739      scpbr   5930.000   3470.000   2701.817       none      0.000      0.000      0.000      crust   5930.000   3470.000   2701.817
 -116.8000    33.0000   6000.000    438.972    570.739      scpbr   6060.000   3550.000   2729.654       none      0.000      0.000      0.000      crust   6060.000   3550.000   2729.654
 -117.7000    34.0000      0.000    204.093    293.500      scpbr   5310.000   2940.000   2584.791       none      0.000      0.000      0.000      crust   5310.000   2940.000   2584.791
 -117.7000    34.0000   3000.000    204.093    293.500      scpbr   5450.000   3040.000   2609.089       none      0.000      0.000      0.000      crust   5450.000   3040.000   2609.089
 -117.7000    34.0000   6000.000    204.093    293.500      scpbr   5610.000   3150.000   2638.314       none      0.000      0.000      0.000      crust   5610.000   3150.000   2638.314
EOF_EXPECTED_RESULT

echo "Running examples_programs_ucvm ucvm_query_scpbr"
if diff $result $expect > /dev/null 2>&1
then
  echo [SUCCESS]
else
  echo [FAILURE]
fi

trap 'rm -f "$expect" "$result"' exit
