#!/bin/bash

## this is to run the ucvm_query with proper LD_LIBRARY_PATH and
## DYLD_LIBRARY_PATH that mac os seems to like to eliminate under
## SIP mode

# Process options
FLAGS=""
CONF=""

# Pass along any arguments to UCVM
while getopts 'm:p:c:f:z:bl:I:O:' OPTION
do
  if [ "$OPTION" == "O" ]; then
      OUT=$OPTARG
  elif [ "$OPTION" == "I" ]; then
      IN=$OPTARG
  elif [ "$OPTION" == "f" ]; then
      CONF=$OPTARG
      FLAGS="${FLAGS} -$OPTION $OPTARG"
  elif [ "$OPTARG" != "" ]; then
      FLAGS="${FLAGS} -$OPTION $OPTARG"
  else
      FLAGS="${FLAGS} -$OPTION"
  fi
done
shift $(($OPTIND - 1))

### run_ucvm_query.sh can be run with 'absolute' path to installed
### location 

if [ "$UCVM_INSTALL_PATH" ] ; then
  SCRIPT_DIR="$UCVM_INSTALL_PATH"/bin
  else
    SCRIPT_DIR="$( cd "$( dirname "$0" )" && pwd )"
fi

## 
export LD_LIBRARY_PATH=${SCRIPT_DIR}/../lib/euclid3/lib:${SCRIPT_DIR}/../lib/proj-5/lib:${SCRIPT_DIR}/../model/cvms426/lib:${SCRIPT_DIR}/../model/cvms5/lib:${SCRIPT_DIR}/../model/cca/lib:${SCRIPT_DIR}/../model/cencal/lib:${SCRIPT_DIR}/../model/cs173/lib

export DYLD_LIBRARY_PATH=${SCRIPT_DIR}/../lib/euclid3/lib:${SCRIPT_DIR}/../lib/proj-5/lib:${SCRIPT_DIR}/../model/cvms426/lib:${SCRIPT_DIR}/../model/cvms5/lib:${SCRIPT_DIR}/../model/cca/lib:${SCRIPT_DIR}/../model/cencal/lib:${SCRIPT_DIR}/../model/cs173/lib

if [ "$CONF" == "" ]; then
   if [ -f ./ucvm_conf  ]; then 
      FLAGS="${FLAGS} -f ./ucvm_conf"
   else
      if [ ! -z "${UCVM_INSTALL_PATH}" ]; then
          FLAGS="${FLAGS} -f ${UCVM_INSTALL_PATH}/conf/ucvm.conf"
      fi 
   fi
fi

if [ "$IN" != "" ]; then
  if [ "$OUT" != "" ]; then
      ${SCRIPT_DIR}/ucvm_query ${FLAGS} < $IN 1 >> $OUT 2>/dev/null 
  else
      ${SCRIPT_DIR}/ucvm_query ${FLAGS} < $IN
  fi
else
  ${SCRIPT_DIR}/ucvm_query ${FLAGS} 
fi

