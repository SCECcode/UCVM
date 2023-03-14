#!/usr/bin/env python

## 
##  models: [ %%UCVM_modelsToInstall% ]
##  libraries: [ %%UCVM_librariesToInstall% ]
## 

import os
UCVM_SRC_PATH="%%UCVM_SRC_PATH%"
UCVM_INSTALL_PATH="%%UCVM_INSTALL_PATH%"
my_env=os.environ

def _add2env(PNAME, path) :
  my_path=my_env.get(PNAME,False)
  if my_path != False :
    if my_path.find(path) != -1 :
        my_path = my_path + ":" + path
  else :
    my_path = path
  my_env[PNAME] = my_path

def add2PATH(path) :
  _add2env("PATH",path)

def add2LD_LIBRARY_PATH(path) :
  _add2env("LD_LIBRARY_PATH",path)

def add2DYLD_LIBRARY_PATH(path) :
  _add2env("DYLD_LIBRARY_PATH",path)

def setup_ucvm_env():

   mlist = [ %%UCVM_expandedModelsToInstall% ]
   for i in mlist:
     add2LD_LIBRARY_PATH(i)
     add2DYLD_LIBRARY_PATH(i)

   llist = [ %%UCVM_expandedLibrariesToInstall% ]
   for i in llist:
     add2LD_LIBRARY_PATH(i)
     add2DYLD_LIBRARY_PATH(i)

   add2PATH(UCVM_INSTALL_PATH + "/bin")
   add2PATH(UCVM_INSTALL_PATH + "/utilities")

