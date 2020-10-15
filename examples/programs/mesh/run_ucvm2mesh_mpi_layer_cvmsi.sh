#!/bin/bash

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
SCRATCH=./scratch
TEST=ucvm2mesh_mpi_layer_cvmsi

rm -rf la_habra_cvmsi.grid la_habra_cvmsi.media la_habra_cvmsi.conf ucvm2mesh_mpi_layer ucvm.conf 

cp ${BIN_DIR}/ucvm2mesh_mpi_layer .
cp ${CONF_DIR}/ucvm.conf .

sed 's ${CONF_DIR} '$CONF_DIR' ' la_habra_cvmsi.conf_template | sed 's ${SCRATCH} '$SCRATCH' ' > la_habra_cvmsi.conf

salloc -Q -N 2 --ntasks=4 --time=00:30:00 srun -Q --ntasks=4 -o ${TEST}_1.srun.out ./ucvm2mesh_mpi_layer -f la_habra_cvmsi.conf -l 1 -c 3
salloc -Q --ntasks=4 --time=00:30:00 srun -Q --ntasks=4 -o ${TEST}_2.srun.out ./ucvm2mesh_mpi_layer -f la_habra_cvmsi.conf -l 4 -c 3 
salloc -Q --ntasks=4 --time=00:30:00 srun -Q --ntasks=4 -o ${TEST}_3.srun.out ./ucvm2mesh_mpi_layer -f la_habra_cvmsi.conf -l 7 -c 4 

expect=$(mktemp) || exit 1
result=$(mktemp) || (trap 'rm -f "$expect"'; exit 1)

od la_habra_cvmsi.grid |head -20 > $result 2>& 1

cat > $expect << EOF_EXPECTED_RESULT
0000000 174435 077113 106520 140135 102123 164263 166405 040100
0000020 000000 000000 000000 000000 016774 137765 106515 140135
0000040 177031 025756 166402 040100 000000 000000 000000 000000
0000060 136227 000636 106513 140135 172115 067451 166376 040100
0000100 000000 000000 000000 000000 152354 041510 106510 140135
0000120 063356 131144 166372 040100 000000 000000 000000 000000
0000140 063374 102363 106505 140135 052777 172636 166366 040100
0000160 000000 000000 000000 000000 071310 143236 106502 140135
0000200 140576 034327 166363 040100 000000 000000 000000 000000
0000220 174116 004111 106500 140135 124555 076020 166357 040100
0000240 000000 000000 000000 000000 173615 044765 106475 140135
0000260 006716 137511 166353 040100 000000 000000 000000 000000
0000300 070206 105642 106472 140135 167236 001200 166350 040100
0000320 000000 000000 000000 000000 061472 146517 106467 140135
0000340 045737 042670 166344 040100 000000 000000 000000 000000
0000360 147647 007374 106465 140135 022621 104357 166340 040100
0000400 000000 000000 000000 000000 132717 050252 106462 140135
0000420 075665 146045 166334 040100 000000 000000 000000 000000
0000440 012661 111131 106457 140135 047112 007533 166331 040100
0000460 000000 000000 000000 000000 167513 152007 106454 140135
EOF_EXPECTED_RESULT

echo "Running examples_programs_mesh" ${TEST}
if diff $result $expect > /dev/null 2>&1
then
  echo [SUCCESS]
else
  echo [FAILURE]
fi

trap 'rm -f "$expect" "$result"' exit

