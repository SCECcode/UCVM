#!/bin/bash

tmp=`uname -s`

#sudo apt-get install gfortran

if [ $tmp == 'Darwin' ]; then
## make sure have automake/aclocal
  brew install automake
fi

mkdir $UCVM_INSTALL_PATH

##["cvms5", "cca", "cs173", "cs173h", "cvms4", "cvms426", "cencal080", "cvmh-15.1.1", "albacore"]

cd $UCVM_SRC_PATH/largefiles
./get_large_files.py << EOF
n
n
n
n
n
n
n
y
n
EOF

if [ $tmp != 'Darwin' ]; then
  cd $UCVM_SRC_PATH/largefiles; ./check_largefiles_md5.py
else
  curl http://hypocenter.usc.edu/research/ucvmc/PARK/cvmh-15.1.1.tar.gz --output $UCVM_SRC_PATH/largefiles/cvmh-15.1.1.tar.gz
fi

cd $UCVM_SRC_PATH/largefiles; ./stage_large_files.py

cd $UCVM_SRC_PATH
./ucvm_setup.py -d -a << EOF &> ucvm_setup_install.log
$UCVM_INSTALL_PATH
EOF

more ucvm_setup_install.log

