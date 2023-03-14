## 
##  models: [ %%UCVM_modelsToInstall% ]
##  libraries: [ %%UCVM_librariesToInstall% ]
## 

export UCVM_SRC_PATH=%%UCVM_SRC_PATH%
export UCVM_INSTALL_PATH=%%UCVM_INSTALL_PATH%

function add2PATH() {
  if [ "$PATH" ] ; then
    if ! echo "$PATH" | grep -Eq "(^|:)$1($|:)" ; then
      if [ "$2" = "after" ] ; then
        export PATH="$PATH:$1"
      else
          export PATH="$1:$PATH"
      fi
    fi
    else
       export PATH="$1"
  fi
}

function add2LD_LIBRARY_PATH() {
  if [ "$LD_LIBRARY_PATH" ] ; then
    if ! echo "$LD_LIBRARY_PATH" | grep -Eq "(^|:)$1($|:)" ; then
      if [ "$2" = "after" ] ; then
        export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$1"
      else
          export LD_LIBRARY_PATH="$1:$LD_LIBRARY_PATH"
      fi
    fi
    else
       export LD_LIBRARY_PATH="$1"
  fi
}

function add2DYLD_LIBRARY_PATH() {
  if [ "$DYLD_LIBRARY_PATH" ] ; then
    if ! echo "$DYLD_LIBRARY_PATH" | grep -Eq "(^|:)$1($|:)" ; then
      if [ "$2" = "after" ] ; then
        export DYLD_LIBRARY_PATH="$DYLD_LIBRARY_PATH:$1"
      else
          export DYLD_LIBRARY_PATH="$1:$DYLD_LIBRARY_PATH"
      fi
    fi
    else
       export DYLD_LIBRARY_PATH="$1"
  fi
}

function add2PYTHONPATH() {
  if [ "$PYTHONPATH" ] ; then
    if ! echo "$PYTHONPATH" | grep -Eq "(^|:)$1($|:)" ; then
      if [ "$2" = "after" ] ; then
        export PYTHONPATH="$PYTHONPATH:$1"
      else
          export PYTHONPATH="$1:$PYTHONPATH"
      fi
    fi
    else
       export PYTHONPATH="$1"
  fi
}

for i in ${UCVM_INSTALL_PATH}/bin ${UCVM_INSTALL_PATH}/utilities
do 
  add2PATH "$i"
done

add2PYTHONPATH ${UCVM_INSTALL_PATH}/utilities/pycvm

for i in %%UCVM_expandedLibrariesToInstall% %%UCVM_expandedModelsToInstall% 
do 
  add2LD_LIBRARY_PATH "$i"
  add2DYLD_LIBRARY_PATH "$i"
done

for i in ${UCVM_INSTALL_PATH}/bin ${UCVM_INSTALL_PATH}/utilities
do 
  add2PATH "$i"
done
