#!/bin/bash

## this is to run the ssh_generate with proper LD_LIBRARY_PATH and
## DYLD_LIBRARY_PATH that mac os seems to like to eliminate under
## SIP mode 

# Process options
FLAGS=""
CONF=""

# Pass along all arguments 
### location 

if [ "$UCVM_INSTALL_PATH" ] ; then
  SCRIPT_DIR="$UCVM_INSTALL_PATH"/bin
  else
    SCRIPT_DIR="$( cd "$( dirname "$0" )" && pwd )"
fi

source ${SCRIPT_DIR}/../conf/ucvm_env.sh
${SCRIPT_DIR}/../bin/ssh_generate "$@" 

exit 0
