# GNU Autoconf config

AC_INIT([UCVM], [22.7.0], [software@scec.org])
AC_CONFIG_AUX_DIR([./aux-config])
AM_INIT_AUTOMAKE([foreign no-exeext])
AC_PROG_RANLIB

# Determine platform
AC_CANONICAL_HOST
# Check for which host we are on and setup a few things
# specifically based on the host
case $host_os in
  darwin* )
		AM_CONDITIONAL(USER_LINUX, false)
		AM_CONDITIONAL(USER_MAC, true)
        ;;
  linux* )
		AM_CONDITIONAL(USER_LINUX, true)
		AM_CONDITIONAL(USER_MAC, false)
		;;
  *)
        #Default Case
        AC_MSG_ERROR([Your platform is not currently supported])
        ;;
esac

# Determine MPI/CC compiler
#: ${CFLAGS=""}
AX_PROG_CC_MPI([true],[use_mpi=yes],[use_mpi=no])

# Check for GNU compiler
if test "x$ac_compiler_gnu" = "xno"; then
AC_MSG_ERROR(["GNU C compiler or MPI wrapper based on GNU is required. Please check your programming environment."])
fi

# Set UCVM_HAVE_MPI flag
AM_CONDITIONAL(UCVM_HAVE_MPI, [test x"$use_mpi" = xyes])

# Parse command-line arguments
AC_ARG_ENABLE([static],
        [AS_HELP_STRING([--enable-static],
        [enable static linking])],
        [enable_static=yes],
        [enable_static=no])

if test "x$enable_static" = xyes; then
	AM_CONDITIONAL(UCVM_AM_STATIC, true)
else
	AM_CONDITIONAL(UCVM_AM_STATIC, false)
fi

AC_ARG_ENABLE([netcdf],
        [AS_HELP_STRING([--enable-netcdf],
        [enable netCDF module])],
        [enable_netcdf=yes],
        [enable_netcdf=no])

AC_ARG_ENABLE([iobuf],
        [AS_HELP_STRING([--enable-iobuf],
        [enable IOBUF module])],
        [enable_iobuf=yes],
        [enable_iobuf=no])

AC_ARG_ENABLE([model-cvmh],
        [AS_HELP_STRING([--enable-model-cvmh],
        [enable model SCEC CVM-H])],
        [enable_model_cvmh=yes],
        [enable_model_cvmh=no])

AC_ARG_ENABLE([model-cvms],
        [AS_HELP_STRING([--enable-model-cvms],
        [enable model SCEC CVM-S])],
        [enable_model_cvms=yes],
        [enable_model_cvms=no])

AC_ARG_ENABLE([model-sjfz],
        [AS_HELP_STRING([--enable-model-sjfz],
        [enable model SCEC SJFZ])],
        [enable_model_sjfz=yes],
        [enable_model_fjfz=no])

AC_ARG_ENABLE([model-ivlsu],
        [AS_HELP_STRING([--enable-model-ivlsu],
        [enable model SCEC IMPERIAL])],
        [enable_model_ivlsu=yes],
        [enable_model_ivlsu=no])
        
AC_ARG_ENABLE([model-cvlsu],
        [AS_HELP_STRING([--enable-model-cvlsu],
        [enable model SCEC COACHELLA])],
        [enable_model_cvlsu=yes],
        [enable_model_cvlsu=no])
        
AC_ARG_ENABLE([model-albacore],
        [AS_HELP_STRING([--enable-model-albacore],
        [enable model SCEC ALBACORE])],
        [enable_model_albacore=yes],
        [enable_model_albacore=no])
        
AC_ARG_ENABLE([model-cvmsi],
        [AS_HELP_STRING([--enable-model-cvmsi],
        [enable model SCEC CVM-SI])],
        [enable_model_cvmsi=yes],
        [enable_model_cvmsi=no])

AC_ARG_ENABLE([model-cvms5],
        [AS_HELP_STRING([--enable-model-cvms5],
        [enable model SCEC CVM-S5])],
        [enable_model_cvms5=yes],
        [enable_model_cvms5=no])

AC_ARG_ENABLE([model-cca],
        [AS_HELP_STRING([--enable-model-cca],
        [enable model SCEC CCA])],
        [enable_model_cca=yes],
        [enable_model_cca=no])

AC_ARG_ENABLE([model-cvmhlabn],
        [AS_HELP_STRING([--enable-model-cvmhlabn],
        [enable model SCEC CVMHLABN])],
        [enable_model_cvmhlabn=yes],
        [enable_model_cvmhlabn=no])

AC_ARG_ENABLE([model-cvmhsgbn],
        [AS_HELP_STRING([--enable-model-cvmhsgbn],
        [enable model SCEC CVMHSGBN])],
        [enable_model_cvmhsgbn=yes],
        [enable_model_cvmhsgbn=no])

AC_ARG_ENABLE([model-cvmhvbn],
        [AS_HELP_STRING([--enable-model-cvmhvbn],
        [enable model SCEC CVMHVBN])],
        [enable_model_cvmhvbn=yes],
        [enable_model_cvmhvbn=no])

AC_ARG_ENABLE([model-cvmhibbn],
        [AS_HELP_STRING([--enable-model-cvmhibbn],
        [enable model SCEC CVMHIBBN])],
        [enable_model_cvmhibbn=yes],
        [enable_model_cvmhibbn=no])

AC_ARG_ENABLE([model-cvmhrbn],
        [AS_HELP_STRING([--enable-model-cvmhrbn],
        [enable model SCEC CVMHRBN])],
        [enable_model_cvmhrbn=yes],
        [enable_model_cvmhrbn=no])

AC_ARG_ENABLE([model-cvmhstbn],
        [AS_HELP_STRING([--enable-model-cvmhstbn],
        [enable model SCEC CVMHSTBN])],
        [enable_model_cvmhstbn=yes],
        [enable_model_cvmhstbn=no])

AC_ARG_ENABLE([model-cvmhsbbn],
        [AS_HELP_STRING([--enable-model-cvmhsbbn],
        [enable model SCEC CVMHSBBN])],
        [enable_model_cvmhsbbn=yes],
        [enable_model_cvmhsbbn=no])

AC_ARG_ENABLE([model-cvmhsbcbn],
        [AS_HELP_STRING([--enable-model-cvmhsbcbn],
        [enable model SCEC CVMHSBCBN])],
        [enable_model_cvmhsbcbn=yes],
        [enable_model_cvmhsbcbn=no])

AC_ARG_ENABLE([model-cvmhsmbn],
        [AS_HELP_STRING([--enable-model-cvmhsmbn],
        [enable model SCEC CVMHSMBN])],
        [enable_model_cvmhsmbn=yes],
        [enable_model_cvmhsmbn=no])

AC_ARG_ENABLE([model-cs173],
        [AS_HELP_STRING([--enable-model-cs173],
        [enable model SCEC CS173])],
        [enable_model_cs173=yes],
        [enable_model_cs173=no])

AC_ARG_ENABLE([model-cs173h],
        [AS_HELP_STRING([--enable-model-cs173h],
        [enable model SCEC CS173H])],
        [enable_model_cs173h=yes],
        [enable_model_cs173h=no])

AC_ARG_ENABLE([model-cencal],
        [AS_HELP_STRING([--enable-model-cencal],
        [enable model USGS CenCalVM])],
        [enable_model_cencal=yes],
        [enable_model_cencal=no])

AC_ARG_ENABLE([model-cvmnci],
        [AS_HELP_STRING([--enable-model-cvmnci],
        [enable model SCEC CVM-NCI])],
        [enable_model_cvmnci=yes],
        [enable_model_cvmnci=no])

AC_ARG_ENABLE([model-wfcvm],
        [AS_HELP_STRING([--enable-model-wfcvm],
        [enable model WFCVM])],
        [enable_model_wfcvm=yes],
        [enable_model_wfcvm=no])

AC_ARG_ENABLE([model-cvmlt],
        [AS_HELP_STRING([--enable-model-cvmlt],
        [enable model Lin-Thurber])],
        [enable_model_cvmlt=yes],
        [enable_model_cvmlt=no])

AC_ARG_ENABLE([model-cmrg],
        [AS_HELP_STRING([--enable-model-cmrg],
        [enable model CMRG])],
        [enable_model_cmrg=yes],
        [enable_model_cmrg=no])

AC_ARG_ENABLE([model-tape],
        [AS_HELP_STRING([--enable-model-tape],
        [enable model Tape])],
        [enable_model_tape=yes],
        [enable_model_tape=no])


# Get required Etree library and include locations
AC_ARG_WITH([etree-include-path],
  [AS_HELP_STRING([--with-etree-include-path],
    [location of the Etree headers])],
  [ETREE_INCL="-I$withval"],
  [ETREE_INCL=""])
AC_ARG_WITH([etree-lib-path],
  [AS_HELP_STRING([--with-etree-lib-path], [location of the Etree libraries])],
  [ETREE_LIB="-L$withval -letree"],
  [ETREE_LIB="-letree"])

# Get required Proj.4 library and include locations
AC_ARG_WITH([proj4-include-path],
  [AS_HELP_STRING([--with-proj4-include-path],
    [location of the Proj.4 headers])],
  [PROJ4_INCL="-I$withval"],
  [PROJ4_INCL=""])
AC_ARG_WITH([proj4-lib-path],
  [AS_HELP_STRING([--with-proj4-lib-path], [location of the Proj.4 libraries])],
  [PROJ4_LIB="-L$withval -lproj -lpthread"],
  [PROJ4_LIB="-lproj -lpthread"])

# Get optional netCDF library and include locations
if test "x$enable_netcdf" = xyes; then
   AC_ARG_WITH([netcdf-include-path],
   [AS_HELP_STRING([--with-netcdf-include-path],
   [location of the netCDF headers])],
   [NETCDF_INCL="-I$withval"],
   [NETCDF_INCL=""])
   AC_ARG_WITH([netcdf-lib-path],
   [AS_HELP_STRING([--with-netcdf-lib-path], [location of the netCDF libraries])],
   [NETCDF_LIB="-L$withval -lnetcdf -lhdf5_hl -lhdf5 -lz -lm -lcurl -ldl"],
   [NETCDF_LIB="-lnetcdf -lhdf5_hl -lhdf5 -lz -lm -lcurl -ldl"])
fi

# Get required FFTW library and include locations
AC_ARG_WITH([fftw-include-path],
  [AS_HELP_STRING([--with-fftw-include-path],
    [location of the FFTW headers])],
  [FFTW_INCL="-I$withval"],
  [FFTW_INCL=""])
AC_ARG_WITH([fftw-lib-path],
  [AS_HELP_STRING([--with-fftw-lib-path], [location of the FFTW libraries])],
  [FFTW_LIB="-L$withval -lfftw3"],
  [FFTW_LIB="-lfftw3"])

# Get USGS CenCalVM library, include, model locations
if test "x$enable_model_cencal" = xyes; then
AC_ARG_WITH([cencal-include-path],
  [AS_HELP_STRING([--with-cencal-include-path],
    [location of the USGS CenCalVM headers])],
  [CENCAL_INCL="-I$withval"],
  [CENCAL_INCL="/usr/include/cencalvm"])
AC_ARG_WITH([cencal-lib-path],
  [AS_HELP_STRING([--with-cencal-lib-path], [location of the USGS CenCalVM libraries])],
  [CENCAL_LIB="-L$withval -lcencalvm -lstdc++"],
  [CENCAL_LIB="-lcencalvm -lstdc++"])
AC_ARG_WITH([cencal-model-path],
  [AS_HELP_STRING([--with-cencal-model-path], [location of the USGS CenCalVM high-rez etree])],
  [CENCAL_MODEL="$withval"],
  [CENCAL_MODEL="/usr/cencalvm/high-rez.e"])
AC_ARG_WITH([cencal-extmodel-path],
  [AS_HELP_STRING([--with-cencal-extmodel-path], [location of the USGS CenCalVM extended etree])],
  [CENCAL_EXTMODEL="$withval"],
  [CENCAL_EXTMODEL="/usr/cencalvm/ext-model.e"])
fi

# Get SCEC CVM-H library and include locations
if test "x$enable_model_cvmh" = xyes; then
AC_ARG_WITH([cvmh-include-path],
  [AS_HELP_STRING([--with-cvmh-include-path],
    [location of the SCEC CVM-H headers])],
  [CVMH_INCL="-I$withval"],
  [CVMH_INCL="/usr/include/cvmh"])
AC_ARG_WITH([cvmh-lib-path],
  [AS_HELP_STRING([--with-cvmh-lib-path], [location of the SCEC CVM-H libraries])],
  [CVMH_LIB="-L$withval -lvxapi"],
  [CVMH_LIB="-lvxapi"])
AC_ARG_WITH([cvmh-model-path],
  [AS_HELP_STRING([--with-cvmh-model-path], [location of the SCEC CVM-H model files])],
  [CVMH_MODEL="$withval"],
  [CVMH_MODEL="/usr/cvmh/bin"])

# Get GCTPC projection library location (CVM-H dependency)
AC_ARG_WITH([gctpc-lib-path],
  [AS_HELP_STRING([--with-gctpc-lib-path], [location of the CVM-H GCTPC libraries (CVM-H 11.2.0)])],
  [CVMH_LIB="$CVMH_LIB -L$withval -lgeo"],
  [CVMH_LIB="$CVMH_LIB"])
fi

# Get SCEC CVM-S library and include locations
if test "x$enable_model_cvms" = xyes; then
AC_ARG_WITH([cvms-include-path],
  [AS_HELP_STRING([--with-cvms-include-path],
    [location of the SCEC CVM-S headers])],
  [CVMS_INCL="-I$withval"],
  [CVMS_INCL="/usr/include/cvms"])
AC_ARG_WITH([cvms-lib-path],
  [AS_HELP_STRING([--with-cvms-lib-path], [location of the SCEC CVM-S libraries])],
  [CVMS_LIB="-L$withval -lcvms -lgfortran"],
  [CVMS_LIB="-lcvms -lgfortran"])
AC_ARG_WITH([cvms-model-path],
  [AS_HELP_STRING([--with-cvms-model-path], [location of the SCEC CVM-S model files])],
  [CVMS_MODEL="$withval"],
  [CVMS_MODEL="/usr/cvms/src"])
fi

# Get SCEC CVM-SI library and include locations
if test "x$enable_model_cvmsi" = xyes; then
AC_ARG_WITH([cvmsi-include-path],
  [AS_HELP_STRING([--with-cvmsi-include-path],
    [location of the SCEC CVM-SI headers])],
  [CVMSI_INCL="-I$withval"],
  [CVMSI_INCL="/usr/include/cvmsi"])
AC_ARG_WITH([cvmsi-lib-path],
  [AS_HELP_STRING([--with-cvmsi-lib-path], [location of the SCEC CVM-SI libraries])],
  [CVMSI_LIB="-L$withval -lcvmsi -lgfortran"],
  [CVMSI_LIB="-lcvmsi -lgfortran"])
AC_ARG_WITH([cvmsi-model-path],
  [AS_HELP_STRING([--with-cvmsi-model-path], [location of the CVM-SI model files])],
  [CVMS_MODEL="$withval"],
  [CVMS_MODEL="/usr/cvmsi/src"])
fi

# Get SCEC SJFZ library and include locations
if test "x$enable_model_sjfz" = xyes; then
AC_ARG_WITH([sjfz-include-path],
  [AS_HELP_STRING([--with-sjfz-include-path],
    [location of the SCEC SJFZ headers])],
  [SJFZ_INCL="-I$withval"],
  [SJFZ_INCL="/usr/include/sjfz"])
AC_ARG_WITH([sjfz-lib-path],
  [AS_HELP_STRING([--with-sjfz-lib-path], [location of the SCEC SJFZ libraries])],
  [SJFZ_LIB="-L$withval -lsjfz"],
  [SJFZ_LIB="-lsjfz"])
fi

# Get SCEC IMPERIAL library and include locations
if test "x$enable_model_ivlsu" = xyes; then
AC_ARG_WITH([ivlsu-include-path],
  [AS_HELP_STRING([--with-ivlsu-include-path],
    [location of the SCEC IMPERIAL headers])],
  [IVLSU_INCL="-I$withval"],
  [IVLSU_INCL="/usr/include/ivlsu"])
AC_ARG_WITH([ivlsu-lib-path],
  [AS_HELP_STRING([--with-ivlsu-lib-path], [location of the SCEC IMPERIAL libraries])],
  [IVLSU_LIB="-L$withval -livlsu -lproj"],
  [IVLSU_LIB="-livlsu -lproj"])
fi

# Get SCEC COACHELLA library and include locations
if test "x$enable_model_cvlsu" = xyes; then
AC_ARG_WITH([cvlsu-include-path],
  [AS_HELP_STRING([--with-coachell-include-path],
    [location of the SCEC COACHELLA headers])],
  [CVLSU_INCL="-I$withval"],
  [CVLSU_INCL="/usr/include/cvlsu"])
AC_ARG_WITH([cvlsu-lib-path],
  [AS_HELP_STRING([--with-cvlsu-lib-path], [location of the SCEC COACHELLA libraries])],
  [CVLSU_LIB="-L$withval -lcvlsu"],
  [CVLSU_LIB="-lcvlsu"])
fi

# Get SCEC ALBACORE library and include locations
if test "x$enable_model_albacore" = xyes; then
AC_ARG_WITH([albacore-include-path],
  [AS_HELP_STRING([--with-albacore-include-path],
    [location of the SCEC ALBACORE headers])],
  [ALBACORE_INCL="-I$withval"],
  [ALBACORE_INCL="/usr/include/albacore"])
AC_ARG_WITH([albacore-lib-path],
  [AS_HELP_STRING([--with-albacore-lib-path], [location of the SCEC ALBACORE libraries])],
  [ALBACORE_LIB="-L$withval -lalbacore -lproj -letree"],
  [ALBACORE_LIB="-lalbacore -lproj -letree"])
fi

# Get SCEC CVM-S5 library and include locations
if test "x$enable_model_cvms5" = xyes; then
AC_ARG_WITH([cvms5-include-path],
  [AS_HELP_STRING([--with-cvms5-include-path],
    [location of the SCEC CVM-S5 headers])],
  [CVMS5_INCL="-I$withval"],
  [CVMS5_INCL="/usr/include/cvms5"])
AC_ARG_WITH([cvms5-lib-path],
  [AS_HELP_STRING([--with-cvms5-lib-path], [location of the SCEC CVM-S5 libraries])],
  [CVMS5_LIB="-L$withval -lcvms5 -lgfortran -lproj -letree"],
  [CVMS5_LIB="-lcvms5 -lgfortran -lproj -letree"])
fi

# Get SCEC CCA library and include locations
if test "x$enable_model_cca" = xyes; then
AC_ARG_WITH([cca-include-path],
  [AS_HELP_STRING([--with-cca-include-path],
    [location of the SCEC CCA headers])],
  [CCA_INCL="-I$withval"],
  [CCA_INCL="/usr/include/cca"])
AC_ARG_WITH([cca-lib-path],
  [AS_HELP_STRING([--with-cca-lib-path], [location of the SCEC CCA libraries])],
  [CCA_LIB="-L$withval -lcca -lgfortran -lproj -letree"],
  [CCA_LIB="-lcca -lgfortran -lproj -letree"])
fi

# Get SCEC CVMHLABN library and include locations
if test "x$enable_model_cvmhlabn" = xyes; then
AC_ARG_WITH([cvmhlabn-include-path],
  [AS_HELP_STRING([--with-cvmhlabn-include-path],
    [location of the SCEC CVMHLABN headers])],
  [CVMHLABN_INCL="-I$withval"],
  [CVMHLABN_INCL="/usr/include/cvmhlabn"])
AC_ARG_WITH([cvmhlabn-lib-path],
  [AS_HELP_STRING([--with-cvmhlabn-lib-path], [location of the SCEC CVMHLABN libraries])],
  [CVMHLABN_LIB="-L$withval -lcvmhlabn"],
  [CVMHLABN_LIB="-lcvmhlabn"])
AC_ARG_WITH([cvmhlabn-model-path],
  [AS_HELP_STRING([--with-cvmhlabn-model-path], [location of the CVMHLABN  model files])],
  [CVMHLABN_MODEL="$withval"],
  [CVMHLABN_MODEL="/usr/cvmhlabn/src"])
fi

# Get SCEC CVMHSGBN library and include locations
if test "x$enable_model_cvmhsgbn" = xyes; then
AC_ARG_WITH([cvmhsgbn-include-path],
  [AS_HELP_STRING([--with-cvmhsgbn-include-path],
    [location of the SCEC CVMHSGBN headers])],
  [CVMHSGBN_INCL="-I$withval"],
  [CVMHSGBN_INCL="/usr/include/cvmhsgbn"])
AC_ARG_WITH([cvmhsgbn-lib-path],
  [AS_HELP_STRING([--with-cvmhsgbn-lib-path], [location of the SCEC CVMHSGBN libraries])],
  [CVMHSGBN_LIB="-L$withval -lcvmhsgbn"],
  [CVMHSGBN_LIB="-lcvmhsgbn"])
AC_ARG_WITH([cvmhsgbn-model-path],
  [AS_HELP_STRING([--with-cvmhsgbn-model-path], [location of the CVMHSGBN  model files])],
  [CVMHSGBN_MODEL="$withval"],
  [CVMHSGBN_MODEL="/usr/cvmhsgbn/src"])
fi

# Get SCEC CVMHVBN library and include locations
if test "x$enable_model_cvmhvbn" = xyes; then
AC_ARG_WITH([cvmhvbn-include-path],
  [AS_HELP_STRING([--with-cvmhvbn-include-path],
    [location of the SCEC CVMHVBN headers])],
  [CVMHVBN_INCL="-I$withval"],
  [CVMHVBN_INCL="/usr/include/cvmhvbn"])
AC_ARG_WITH([cvmhvbn-lib-path],
  [AS_HELP_STRING([--with-cvmhvbn-lib-path], [location of the SCEC CVMHVBN libraries])],
  [CVMHVBN_LIB="-L$withval -lcvmhvbn"],
  [CVMHVBN_LIB="-lcvmhvbn"])
AC_ARG_WITH([cvmhvbn-model-path],
  [AS_HELP_STRING([--with-cvmhvbn-model-path], [location of the CVMHVBN  model files])],
  [CVMHVBN_MODEL="$withval"],
  [CVMHVBN_MODEL="/usr/cvmhvbn/src"])
fi

# Get SCEC CVMHIBBN library and include locations
if test "x$enable_model_cvmhibbn" = xyes; then
AC_ARG_WITH([cvmhibbn-include-path],
  [AS_HELP_STRING([--with-cvmhibbn-include-path],
    [location of the SCEC CVMHIBBN headers])],
  [CVMHIBBN_INCL="-I$withval"],
  [CVMHIBBN_INCL="/usr/include/cvmhibbn"])
AC_ARG_WITH([cvmhibbn-lib-path],
  [AS_HELP_STRING([--with-cvmhibbn-lib-path], [location of the SCEC CVMHIBBN libraries])],
  [CVMHIBBN_LIB="-L$withval -lcvmhibbn"],
  [CVMHIBBN_LIB="-lcvmhibbn"])
AC_ARG_WITH([cvmhibbn-model-path],
  [AS_HELP_STRING([--with-cvmhibbn-model-path], [location of the CVMHIBBN  model files])],
  [CVMHIBBN_MODEL="$withval"],
  [CVMHIBBN_MODEL="/usr/cvmhibbn/src"])
fi

# Get SCEC CVMHRBN library and include locations
if test "x$enable_model_cvmhrbn" = xyes; then
AC_ARG_WITH([cvmhrbn-include-path],
  [AS_HELP_STRING([--with-cvmhrbn-include-path],
    [location of the SCEC CVMHRBN headers])],
  [CVMHRBN_INCL="-I$withval"],
  [CVMHRBN_INCL="/usr/include/cvmhrbn"])
AC_ARG_WITH([cvmhrbn-lib-path],
  [AS_HELP_STRING([--with-cvmhrbn-lib-path], [location of the SCEC CVMHRBN libraries])],
  [CVMHRBN_LIB="-L$withval -lcvmhrbn"],
  [CVMHRBN_LIB="-lcvmhrbn"])
AC_ARG_WITH([cvmhrbn-model-path],
  [AS_HELP_STRING([--with-cvmhrbn-model-path], [location of the CVMHRBN  model files])],
  [CVMHRBN_MODEL="$withval"],
  [CVMHRBN_MODEL="/usr/cvmhrbn/src"])
fi

# Get SCEC CVMHSTBN library and include locations
if test "x$enable_model_cvmhstbn" = xyes; then
AC_ARG_WITH([cvmhstbn-include-path],
  [AS_HELP_STRING([--with-cvmhstbn-include-path],
    [location of the SCEC CVMHSTBN headers])],
  [CVMHSTBN_INCL="-I$withval"],
  [CVMHSTBN_INCL="/usr/include/cvmhstbn"])
AC_ARG_WITH([cvmhstbn-lib-path],
  [AS_HELP_STRING([--with-cvmhstbn-lib-path], [location of the SCEC CVMHSTBN libraries])],
  [CVMHSTBN_LIB="-L$withval -lcvmhstbn"],
  [CVMHSTBN_LIB="-lcvmhstbn"])
AC_ARG_WITH([cvmhstbn-model-path],
  [AS_HELP_STRING([--with-cvmhstbn-model-path], [location of the CVMHSTBN  model files])],
  [CVMHSTBN_MODEL="$withval"],
  [CVMHSTBN_MODEL="/usr/cvmhstbn/src"])
fi

# Get SCEC CVMHSBBN library and include locations
if test "x$enable_model_cvmhsbbn" = xyes; then
AC_ARG_WITH([cvmhsbbn-include-path],
  [AS_HELP_STRING([--with-cvmhsbbn-include-path],
    [location of the SCEC CVMHSBBN headers])],
  [CVMHSBBN_INCL="-I$withval"],
  [CVMHSBBN_INCL="/usr/include/cvmhsbbn"])
AC_ARG_WITH([cvmhsbbn-lib-path],
  [AS_HELP_STRING([--with-cvmhsbbn-lib-path], [location of the SCEC CVMHSBBN libraries])],
  [CVMHSBBN_LIB="-L$withval -lcvmhsbbn"],
  [CVMHSBBN_LIB="-lcvmhsbbn"])
AC_ARG_WITH([cvmhsbbn-model-path],
  [AS_HELP_STRING([--with-cvmhsbbn-model-path], [location of the CVMHSBBN  model files])],
  [CVMHSBBN_MODEL="$withval"],
  [CVMHSBBN_MODEL="/usr/cvmhsbbn/src"])
fi

# Get SCEC CVMHSBCBN library and include locations
if test "x$enable_model_cvmhsbcbn" = xyes; then
AC_ARG_WITH([cvmhsbcbn-include-path],
  [AS_HELP_STRING([--with-cvmhsbcbn-include-path],
    [location of the SCEC CVMHSBCBN headers])],
  [CVMHSBCBN_INCL="-I$withval"],
  [CVMHSBCBN_INCL="/usr/include/cvmhsbcbn"])
AC_ARG_WITH([cvmhsbcbn-lib-path],
  [AS_HELP_STRING([--with-cvmhsbcbn-lib-path], [location of the SCEC CVMHSBCBN libraries])],
  [CVMHSBCBN_LIB="-L$withval -lcvmhsbcbn"],
  [CVMHSBCBN_LIB="-lcvmhsbcbn"])
AC_ARG_WITH([cvmhsbcbn-model-path],
  [AS_HELP_STRING([--with-cvmhsbcbn-model-path], [location of the CVMHSBCBN  model files])],
  [CVMHSBCBN_MODEL="$withval"],
  [CVMHSBCBN_MODEL="/usr/cvmhsbcbn/src"])
fi

# Get SCEC CVMHSMBN library and include locations
if test "x$enable_model_cvmhsmbn" = xyes; then
AC_ARG_WITH([cvmhsmbn-include-path],
  [AS_HELP_STRING([--with-cvmhsmbn-include-path],
    [location of the SCEC CVMHSMBN headers])],
  [CVMHSMBN_INCL="-I$withval"],
  [CVMHSMBN_INCL="/usr/include/cvmhsmbn"])
AC_ARG_WITH([cvmhsmbn-lib-path],
  [AS_HELP_STRING([--with-cvmhsmbn-lib-path], [location of the SCEC CVMHSMBN libraries])],
  [CVMHSMBN_LIB="-L$withval -lcvmhsmbn"],
  [CVMHSMBN_LIB="-lcvmhsmbn"])
AC_ARG_WITH([cvmhsmbn-model-path],
  [AS_HELP_STRING([--with-cvmhsmbn-model-path], [location of the CVMHSMBN  model files])],
  [CVMHSMBN_MODEL="$withval"],
  [CVMHSMBN_MODEL="/usr/cvmhsmbn/src"])
fi

# Get SCEC CS173 library and include locations
if test "x$enable_model_cs173" = xyes; then
AC_ARG_WITH([cs173-include-path],
  [AS_HELP_STRING([--with-cs173-include-path],
    [location of the SCEC CS173 headers])],
  [CS173_INCL="-I$withval"],
  [CS173_INCL="/usr/include/cs173"])
AC_ARG_WITH([cs173-lib-path],
  [AS_HELP_STRING([--with-cs173-lib-path], [location of the SCEC CS173 libraries])],
  [CS173_LIB="-L$withval -lcs173 -lgfortran -lproj -letree"],
  [CS173_LIB="-lcs173 -lgfortran -lproj -letree"])
fi

# Get SCEC CS173H library and include locations
if test "x$enable_model_cs173h" = xyes; then
AC_ARG_WITH([cs173h-include-path],
  [AS_HELP_STRING([--with-cs173h-include-path],
    [location of the SCEC CS173H headers])],
  [CS173H_INCL="-I$withval"],
  [CS173H_INCL="/usr/include/cs173h"])
AC_ARG_WITH([cs173h-lib-path],
  [AS_HELP_STRING([--with-cs173h-lib-path], [location of the SCEC CS173H libraries])],
  [CS173H_LIB="-L$withval -lcs173h -lgfortran -lproj -letree"],
  [CS173H_LIB="-lcs173h -lgfortran -lproj -letree"])
fi


# Get SCEC CVM-NCI library and include locations
if test "x$enable_model_cvmnci" = xyes; then
AC_ARG_WITH([cvmnci-include-path],
  [AS_HELP_STRING([--with-cvmnci-include-path],
    [location of the SCEC CVM-NCI headers])],
  [CVMNCI_INCL="-I$withval"],
  [CVMNCI_INCL="/usr/include/cvmnci"])
AC_ARG_WITH([cvmnci-lib-path],
  [AS_HELP_STRING([--with-cvmnci-lib-path], [location of the SCEC CVM-NCI libraries])],
  [CVMNCI_LIB="-L$withval -lcvmnci"],
  [CVMNCI_LIB="-lcvmnci"])
AC_ARG_WITH([cvmnci-model-path],
  [AS_HELP_STRING([--with-cvmnci-model-path], [location of the SCEC CVM-NCI model files])],
  [CVMNCI_MODEL="$withval"],
  [CVMNCI_MODEL="/usr/cvmnci/model"])
fi

# Get WFCVM library and include locations
if test "x$enable_model_wfcvm" = xyes; then
AC_ARG_WITH([wfcvm-include-path],
  [AS_HELP_STRING([--with-wfcvm-include-path],
    [location of the WFCVM headers])],
  [WFCVM_INCL="-I$withval"],
  [WFCVM_INCL="/usr/include/wfcvm"])
AC_ARG_WITH([wfcvm-lib-path],
  [AS_HELP_STRING([--with-wfcvm-lib-path], [location of the WFCVM libraries])],
  [WFCVM_LIB="-L$withval -lwfcvm -lgfortran"],
  [WFCVM_LIB="-lwfcvm -lgfortan"])
AC_ARG_WITH([wfcvm-model-path],
  [AS_HELP_STRING([--with-wfcvm-model-path], [location of the WFCVM model files])],
  [WFCVM_MODEL="$withval"],
  [WFCVM_MODEL="/usr/wfcvm/src"])
fi

# Get CVMS library and include locations
if test "x$enable_model_cvms" = xyes; then
AC_ARG_WITH([cvms-include-path],
  [AS_HELP_STRING([--with-cvms-include-path],
    [location of the CVMS headers])],
  [CVMS_INCL="-I$withval"],
  [CVMS_INCL="/usr/include/cvms"])
AC_ARG_WITH([cvms-lib-path],
  [AS_HELP_STRING([--with-cvms-lib-path], [location of the CVMS libraries])],
  [CVMS_LIB="-L$withval -lwfcvm -lgfortran"],
  [CVMS_LIB="-lcvms -lgfortan"])
AC_ARG_WITH([cvms-model-path],
  [AS_HELP_STRING([--with-cvms-model-path], [location of the CVMS model files])],
  [CVMS_MODEL="$withval"],
  [CVMS_MODEL="/usr/cvms/src"])
fi


# Get CVMLT library and include locations
if test "x$enable_model_cvmlt" = xyes; then
AC_ARG_WITH([cvmlt-include-path],
  [AS_HELP_STRING([--with-cvmlt-include-path],
    [location of the CVMLT headers])],
  [CVMLT_INCL="-I$withval"],
  [CVMLT_INCL="/usr/include/cvmlt"])
AC_ARG_WITH([cvmlt-lib-path],
  [AS_HELP_STRING([--with-cvmlt-lib-path], [location of the CVMLT libraries])],
  [CVMLT_LIB="-L$withval -lcvmlt"],
  [CVMLT_LIB="-lcvmlt"])
AC_ARG_WITH([cvmlt-model-path],
  [AS_HELP_STRING([--with-cvmlt-model-path], [location of the CVMLT model files])],
  [CVMLT_MODEL="$withval"],
  [CVMLT_MODEL="/usr/cvmlt/model"])
fi

# Get CMRG library and include locations
if test "x$enable_model_cmrg" = xyes; then
AC_ARG_WITH([cmrg-include-path],
  [AS_HELP_STRING([--with-cmrg-include-path],
    [location of the CMRG headers])],
  [CMRG_INCL="-I$withval"],
  [CMRG_INCL="/usr/include/cmrg"])
AC_ARG_WITH([cmrg-lib-path],
  [AS_HELP_STRING([--with-cmrg-lib-path], [location of the CMRG libraries])],
  [CMRG_LIB="-L$withval -lcmrg"],
  [CMRG_LIB="-lcmrg"])
AC_ARG_WITH([cmrg-model-path],
  [AS_HELP_STRING([--with-cmrg-model-path], [location of the CMRG model files])],
  [CMRG_MODEL="$withval"],
  [CMRG_MODEL="/usr/cmrg/model"])
fi

# Get Tape library and include locations
if test "x$enable_model_tape" = xyes; then
AC_ARG_WITH([tape-include-path],
  [AS_HELP_STRING([--with-tape-include-path],
    [location of the TAPE headers])],
  [TAPE_INCL="-I$withval"],
  [TAPE_INCL="/usr/include/tape"])
AC_ARG_WITH([tape-lib-path],
  [AS_HELP_STRING([--with-tape-lib-path], [location of the TAPE libraries])],
  [TAPE_LIB="-L$withval -ltape"],
  [TAPE_LIB="-ltape"])
AC_ARG_WITH([tape-model-path],
  [AS_HELP_STRING([--with-tape-model-path], [location of the TAPE model files])],
  [TAPE_MODEL="$withval"],
  [TAPE_MODEL="/usr/tape/model"])
fi

# Make model paths visible to makefiles
AC_SUBST(CENCAL_MODEL)
AC_SUBST(CENCAL_EXTMODEL)
AC_SUBST(CVMH_MODEL)
AC_SUBST(CVMNCI_MODEL)
AC_SUBST(CVMLT_MODEL)
AC_SUBST(CMRG_MODEL)
AC_SUBST(TAPE_MODEL)

# Setup compiler/linker flags
if test "x$enable_static" = xyes; then
   LDFLAGS="-static $LDFLAGS"
fi
if test "x$enable_dynamic" = xyes; then
   LDFLAGS="-dynamic $LDFLAGS"
fi
if test "x$enable_iobuf" = xyes; then
   AC_DEFINE(USE_IOBUF_MACROS, 1)
fi

# Save copy of CFLAGS and LDFLAGS
CHECK_CFLAGS="-Wall -O3 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 $CFLAGS"
CHECK_LDFLAGS="$LDFLAGS"

# Check required ETREE installation
CFLAGS="$ETREE_INCL $CHECK_CFLAGS"
LDFLAGS="$CHECK_LDFLAGS $ETREE_LIB"
AC_CHECK_LIB(etree, etree_open, [AC_CHECK_HEADER([etree.h], [], [AC_MSG_ERROR(["Etree headers not found in $ETREE_INCL; use --with-etree-include-path"])], [AC_INCLUDES_DEFAULT])],[AC_MSG_ERROR(["Etree library not found; use --with-etree-lib-path"])])

# Check required FFTW installation
CFLAGS="$FFTW_INCL $CHECK_CFLAGS"
LDFLAGS="$CHECK_LDFLAGS $FFTW_LIB"
AC_CHECK_LIB(fftw3, fftw_execute, [AC_CHECK_HEADER([fftw3.h], [], [AC_MSG_ERROR(["FFTW headers not found in $FFTW_INCL; use --with-fftw-include-path"])], [AC_INCLUDES_DEFAULT])],[AC_MSG_ERROR(["FFTW library not found; use --with-fftw-lib-path"])])

# Check required PROJ4 installation
CFLAGS="$PROJ4_INCL $CHECK_CFLAGS"
LDFLAGS="$CHECK_LDFLAGS $PROJ4_LIB"
AC_CHECK_LIB(proj, pj_init_plus, [AC_CHECK_HEADER([proj_api.h], [], [AC_MSG_ERROR(["Proj4 header not found in $PROJ4_INCL; use --with-proj4-include-path"])
  ], [AC_INCLUDES_DEFAULT])],[AC_MSG_ERROR(["Proj4 library not found; use --with-proj4-lib-path"])], [-lpthread -lm])

# Check optional NetCDF library
if test "x$enable_netcdf" = xyes; then
   echo "Checking for NetCDF library"
   CFLAGS="$NETCDF_INCL $CHECK_CFLAGS"
   LDFLAGS="$CHECK_LDFLAGS $NETCDF_LIB"
   AC_CHECK_LIB(netcdf, nc_create,
	[AM_CONDITIONAL(UCVM_HAVE_NETCDF, true)], 
	[AC_MSG_ERROR([NetCDF library not found; use --with-netcdf-include-path"])],
	[-lhdf5_hl -lhdf5 -lz -lm -lcurl -ldl])
   AC_CHECK_HEADER(netcdf.h,
	[],
	[AC_MSG_ERROR([NetCDF header not found; use --with-netcdf-lib-path"])],
	[AC_INCLUDES_DEFAULT])

else
	AM_CONDITIONAL(UCVM_HAVE_NETCDF, false)
fi

# Set final CFLAGS and LDFLAGS
CFLAGS="$CHECK_CFLAGS $ETREE_INCL $PROJ4_INCL $FFTW_INCL"
LDFLAGS="$CHECK_LDFLAGS $ETREE_LIB $PROJ4_LIB $FFTW_LIB"
if test "x$enable_netcdf" = xyes; then
   CFLAGS="$CFLAGS $NETCDF_INCL"
   LDFLAGS="$LDFLAGS $NETCDF_LIB"
fi
LDFLAGS="$LDFLAGS -lm"

# Check optional USGS CenCalVM installation
if test "x$enable_model_cencal" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CENCAL_INCL $CFLAGS"
   LDFLAGS="$CENCAL_LIB $LDFLAGS"

   echo "Checking for USGS CenCalVM"
   AC_CHECK_LIB(cencalvm, cencalvm_createQuery, [AM_CONDITIONAL(UCVM_AM_ENABLE_CENCAL, true)], [AC_MSG_ERROR(["USGS CenCalVM library not found; use --with-cencal-lib-path"])], [-lstdc++ -lpthread -letree -lproj -lm])
   AC_CHECK_HEADER(cvmquery.h, [], [AC_MSG_ERROR(["USGS CenCalVM header not found; use --with-cencal-include-path"])], [AC_INCLUDES_DEFAULT])

   AC_CHECK_FILE([$CENCAL_MODEL], [], [AC_MSG_ERROR(["USGS CenCalVM model etree not found; use --with-cencal-model-path"])])
   AC_CHECK_FILE([$CENCAL_EXTMODEL], [], [AC_MSG_ERROR(["USGS CenCalVM extmodel etree not found; use --with-cencal-extmodel-path"])])

else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CENCAL, false)
fi

# Check optional SCEC CVM-H installation
if test "x$enable_model_cvmh" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMH_INCL $CFLAGS"
   LDFLAGS="$CVMH_LIB $LDFLAGS"

   echo "Checking for SCEC CVM-H"
   AC_CHECK_LIB(vxapi, vx_getcoord,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVMH, true)], [AC_MSG_ERROR(["SCEC CVM-H / GCTPC library not found; use --with-cvmh-lib-path and --with-gctpc-lib-path"])], [-lgeo -lm])
   AC_CHECK_HEADER(vx_sub.h, [], [AC_MSG_ERROR(["SCEC CVM-H header not found; use --with-cvmh-include-path"])], [AC_INCLUDES_DEFAULT])

   AC_CHECK_FILE([$CVMH_MODEL], [], [AC_MSG_ERROR(["SCEC CVM-H model dir not found; use --with-cvmh-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMH, false)
fi

if test "x$enable_static" = xyes; then 
# Check optional SCEC CVM-S installation
if test "x$enable_model_cvms" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMS_INCL $CFLAGS"
   LDFLAGS="$CVMS_LIB $LDFLAGS"

   echo "Checking for SCEC CVM-S"
   AC_CHECK_LIB(cvms,cvms_init_,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVMS, true)],[AC_MSG_ERROR(["SCEC CVM-S library requires C compiler that can link Fortran libraries"])],[-lgfortran -lm])
   AC_CHECK_HEADER(cvms.h,[],[AC_MSG_ERROR(["SCEC CVM-S header not found; use --with-cvms-include-path"])],[AC_INCLUDES_DEFAULT])
   AC_CHECK_FILE([$CVMS_MODEL], [], [AC_MSG_ERROR(["SCEC CVM-S model dir not found; use --with-cvms-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMS, false)
fi
else 
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMS, [test x"$enable_model_cvms" = xyes])
fi

# Check optional SCEC CVM-SI installation
if test "x$enable_static" = xyes; then
if test "x$enable_model_cvmsi" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMSI_INCL $CFLAGS"
   LDFLAGS="$CVMSI_LIB $LDFLAGS"

   echo "Checking for SCEC CVM-SI"
   AC_CHECK_LIB(cvmsi,utm_geo_,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVMSI, true)],[AC_MSG_ERROR(["SCEC CVM-SI library requires C compiler that can link Fortran libraries"])],[-lgfortran -lm])

   echo "Checking for SCEC CVM-SI header"
   AC_CHECK_HEADER(cvmsi.h,[],[AC_MSG_ERROR(["SCEC CVM-SI header not found; use --with-cvmsi-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMSI, false)
fi
else
    AM_CONDITIONAL(UCVM_AM_ENABLE_CVMSI, [test x"$enable_model_cvmsi" = xyes])
fi

# Check optional SCEC SJFZ installation
if test "x$enable_static" = xyes; then
if test "x$enable_model_sjfz" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$SJFZ_INCL $CFLAGS"
   LDFLAGS="$SJFZ_LIB $LDFLAGS"

   echo "Checking for SCEC SJFZ"
   AC_CHECK_LIB(sjfz, sjfz_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_SJFZ, true)], [AC_MSG_ERROR(["SCEC SJFZ library not found; use --with-sjfz-lib-path"])],[-lm])
   AC_CHECK_HEADER(sjfz.h,[],[AC_MSG_ERROR(["SCEC SJFZ header not found; use --with-sjfz-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_SJFZ, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_SJFZ, [test x"$enable_model_sjfz" = xyes])
fi

# Check optional SCEC IMPERIAL installation
if test "x$enable_static" = xyes; then
if test "x$enable_model_ivlsu" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$IVLSU_INCL $CFLAGS"
   LDFLAGS="$IVLSU_LIB $LDFLAGS"

   echo "Checking for SCEC IMPERIAL"
   AC_CHECK_LIB(ivlsu, ivlsu_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_IVLSU, true)], [AC_MSG_ERROR(["SCEC IMPERIAL library not found; use --with-ivlsu-lib-path"])],[-lproj -letree -lm])
   AC_CHECK_HEADER(ivlsu.h,[],[AC_MSG_ERROR(["SCEC IMPERIAL header not found; use --with-ivlsu-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_IVLSU, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_IVLSU, [test x"$enable_model_ivlsu" = xyes])
fi

# Check optional SCEC CVLSU installation
if test "x$enable_static" = xyes; then
if test "x$enable_model_cvlsu" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVLSU_INCL $CFLAGS"
   LDFLAGS="$CVLSU_LIB $LDFLAGS"

   echo "Checking for SCEC CVLSU"
   AC_CHECK_LIB(cvlsu, coachell_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVLSU, true)], [AC_MSG_ERROR(["SCEC CVLSU library not found; use --with-cvlsu-lib-path"])],[-lm])
   AC_CHECK_HEADER(cvlsu.h,[],[AC_MSG_ERROR(["SCEC CVLSU header not found; use --with-cvlsu-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVLSU, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVLSU, [test x"$enable_model_cvlsu" = xyes])
fi

# Check optional SCEC ALBACORE installation
if test "x$enable_static" = xyes; then
if test "x$enable_model_albacore" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$ALBACORE_INCL $CFLAGS"
   LDFLAGS="$ALBACORE_LIB $LDFLAGS"

   echo "Checking for SCEC ALBACORE"
   AC_CHECK_LIB(albacore, albacore_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_ALBACORE, true)], [AC_MSG_ERROR(["SCEC ALBACORE library not found; use --with-albacore-lib-path"])],[-lproj -letree -lm])
   AC_CHECK_HEADER(albacore.h,[],[AC_MSG_ERROR(["SCEC ALBACORE header not found; use --with-albacore-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_ALBACORE, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_ALBACORE, [test x"$enable_model_albacore" = xyes])
fi

# Check optional SCEC CVM-S5 installation
if test "x$enable_static" = xyes; then
if test "x$enable_model_cvms5" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMS5_INCL $CFLAGS"
   LDFLAGS="$CVMS5_LIB $LDFLAGS"

   echo "Checking for SCEC CVM-S5"
   AC_CHECK_LIB(cvms5,utm_geo_,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVMS5, true)],[AC_MSG_ERROR(["SCEC CVM-S5 library requires C compiler that can link Fortran libraries"])],[-lproj -letree -lgfortran -lm])
   AC_CHECK_HEADER(cvms5.h,[],[AC_MSG_ERROR(["SCEC CVM-S5 header not found; use --with-cvms5-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMS5, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMS5, [test x"$enable_model_cvms5" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CCA installation
if test "x$enable_model_cca" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CCA_INCL $CFLAGS"
   LDFLAGS="$CCA_LIB $LDFLAGS"

   echo "Checking for SCEC CCA"
   AC_CHECK_LIB(cca,utm_geo_,[AM_CONDITIONAL(UCVM_AM_ENABLE_CCA, true)],[AC_MSG_ERROR(["SCEC CCA library requires C compiler that can link Fortran libraries"])],[-lproj -letree -lgfortran -lm])
   AC_CHECK_HEADER(cca.h,[],[AC_MSG_ERROR(["SCEC CCA header not found; use --with-cca-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CCA, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CCA, [test x"$enable_model_cca" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHLABN installation
if test "x$enable_model_cvmhlabn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHLABN_INCL $CFLAGS"
   LDFLAGS="$CVMHLABN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHLABN"
   AC_CHECK_HEADER(cvmhlabn.h,[],[AC_MSG_ERROR(["SCEC CVMHLABN header not found; use --with-cvmhlabn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHLABN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHLABN, [test x"$enable_model_cvmhlabn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHSGBN installation
if test "x$enable_model_cvmhsgbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHSGBN_INCL $CFLAGS"
   LDFLAGS="$CVMHSGBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHSGBN"
   AC_CHECK_HEADER(cvmhsgbn.h,[],[AC_MSG_ERROR(["SCEC CVMHSGBN header not found; use --with-cvmhsgbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSGBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSGBN, [test x"$enable_model_cvmhsgbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHVBN installation
if test "x$enable_model_cvmhvbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHVBN_INCL $CFLAGS"
   LDFLAGS="$CVMHVBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHVBN"
   AC_CHECK_HEADER(cvmhvbn.h,[],[AC_MSG_ERROR(["SCEC CVMHVBN header not found; use --with-cvmhvbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHVBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHVBN, [test x"$enable_model_cvmhvbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHIBBN installation
if test "x$enable_model_cvmhibbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHIBBN_INCL $CFLAGS"
   LDFLAGS="$CVMHIBBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHIBBN"
   AC_CHECK_HEADER(cvmhibbn.h,[],[AC_MSG_ERROR(["SCEC CVMHIBBN header not found; use --with-cvmhibbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHIBBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHIBBN, [test x"$enable_model_cvmhibbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHRBN installation
if test "x$enable_model_cvmhrbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHRBN_INCL $CFLAGS"
   LDFLAGS="$CVMHRBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHRBN"
   AC_CHECK_HEADER(cvmhrbn.h,[],[AC_MSG_ERROR(["SCEC CVMHRBN header not found; use --with-cvmhibbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHRBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHRBN, [test x"$enable_model_cvmhrbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHSTBN installation
if test "x$enable_model_cvmhstbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHSTBN_INCL $CFLAGS"
   LDFLAGS="$CVMHSTBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHSTBN"
   AC_CHECK_HEADER(cvmhstbn.h,[],[AC_MSG_ERROR(["SCEC CVMHSTBN header not found; use --with-cvmhibbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSTBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSTBN, [test x"$enable_model_cvmhstbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHSBBN installation
if test "x$enable_model_cvmhsbbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHSBBN_INCL $CFLAGS"
   LDFLAGS="$CVMHSBBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHSBBN"
   AC_CHECK_HEADER(cvmhsbbn.h,[],[AC_MSG_ERROR(["SCEC CVMHSBBN header not found; use --with-cvmhibbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSBBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSBBN, [test x"$enable_model_cvmhsbbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHSBCBN installation
if test "x$enable_model_cvmhsbcbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHSBCBN_INCL $CFLAGS"
   LDFLAGS="$CVMHSBCBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHSBCBN"
   AC_CHECK_HEADER(cvmhsbcbn.h,[],[AC_MSG_ERROR(["SCEC CVMHSBCBN header not found; use --with-cvmhibbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSBCBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSBCBN, [test x"$enable_model_cvmhsbcbn" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CVMHSMBN installation
if test "x$enable_model_cvmhsmbn" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMHSMBN_INCL $CFLAGS"
   LDFLAGS="$CVMHSMBN_LIB $LDFLAGS"

   echo "Checking for SCEC CVMHSMBN"
   AC_CHECK_HEADER(cvmhsmbn.h,[],[AC_MSG_ERROR(["SCEC CVMHSMBN header not found; use --with-cvmhibbn-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSMBN, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMHSMBN, [test x"$enable_model_cvmhsmbn" = xyes])
fi


if test "x$enable_static" = xyes; then
# Check optional SCEC CS173 installation
if test "x$enable_model_cs173" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CS173_INCL $CFLAGS"
   LDFLAGS="$CS173_LIB $LDFLAGS"

   echo "Checking for SCEC CS173"
   AC_CHECK_LIB(cs173, cs173_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_CS173, true)], [AC_MSG_ERROR(["SCEC CS173 library requires a C compiler that can link Fortran libraries"])],[-lproj -letree -lgfortran -lm])
   AC_CHECK_HEADER(cs173.h,[],[AC_MSG_ERROR(["SCEC CS173 header not found; use --with-cs173-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CS173, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CS173, [test x"$enable_model_cs173" = xyes])
fi

if test "x$enable_static" = xyes; then
# Check optional SCEC CS173H installation
if test "x$enable_model_cs173h" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CS173H_INCL $CFLAGS"
   LDFLAGS="$CS173H_LIB $LDFLAGS"

   echo "Checking for SCEC CS173H"
   AC_CHECK_LIB(cs173h, cs173h_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_CS173H, true)], [AC_MSG_ERROR(["SCEC CS173H library requires a C compiler that can link Fortran libraries"])],[-lproj -letree -lgfortran -lm])
   AC_CHECK_HEADER(cs173h.h,[],[AC_MSG_ERROR(["SCEC CS173H header not found; use --with-cs173h-include-path"])],[AC_INCLUDES_DEFAULT])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CS173H, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CS173H, [test x"$enable_model_cs173h" = xyes])
fi

# Check optional SCEC CVM-NCI installation
if test "x$enable_model_cvmnci" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMNCI_INCL $CFLAGS"
   LDFLAGS="$CVMNCI_LIB $LDFLAGS"

   echo "Checking for SCEC CVM-NCI"
   AC_CHECK_LIB(cvmnci, cvmnci_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVMNCI, true)], [AC_MSG_ERROR(["SCEC CVM-NCI library not found; use --with-cvmnci-lib-path"])],[-lm])
   AC_CHECK_HEADER(cvmnci.h,[],[AC_MSG_ERROR(["SCEC CVM-NCI header not found; use --with-cvmnci-include-path"])],[AC_INCLUDES_DEFAULT])

   AC_CHECK_FILE([$CVMNCI_MODEL], [], [AC_MSG_ERROR(["SCEC CVM-NCI model dir not found; use --with-cvmnci-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMNCI, false)
fi


if test "x$enable_static" = xyes; then
# Check optional WFCVM installation
if test "x$enable_model_wfcvm" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$WFCVM_INCL $CFLAGS"
   LDFLAGS="$WFCVM_LIB $LDFLAGS"

   echo "Checking for WFCVM"
   AC_CHECK_LIB(wfcvm, wfcvm_init_,[AM_CONDITIONAL(UCVM_AM_ENABLE_WFCVM, true)],[AC_MSG_ERROR(["SCEC WFCVM library requires a C compiler that can link Fortran libraries"])],[-lgfortran -lm])
   AC_CHECK_HEADER(wfcvm.h,[],[AC_MSG_ERROR(["WFCVM header not found; use --with-wfcvm-include-path"])],[AC_INCLUDES_DEFAULT])
   AC_CHECK_FILE([$WFCVM_MODEL], [], [AC_MSG_ERROR(["WFCVM model dir not found; use --with-wfcvm-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_WFCVM, false)
fi
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_WFCVM, [test x"$enable_model_wfcvm" = xyes])
fi


# Check optional CVMLT installation
if test "x$enable_model_cvmlt" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CVMLT_INCL $CFLAGS"
   LDFLAGS="$CVMLT_LIB $LDFLAGS"

   echo "Checking for CVMLT"
   AC_CHECK_LIB(cvmlt, cvmlt_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_CVMLT, true)], [AC_MSG_ERROR(["CVMLT library not found; use --with-cvmlt-lib-path"])], [-lm])
   AC_CHECK_HEADER(cvmlt.h,[],[AC_MSG_ERROR(["CVMLT header not found; use --with-cvmlt-include-path"])],[AC_INCLUDES_DEFAULT])

   AC_CHECK_FILE([$CVMLT_MODEL], [], [AC_MSG_ERROR(["CVMLT model dir not found; use --with-cvmlt-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CVMLT, false)
fi

# Check optional CMRG installation
if test "x$enable_model_cmrg" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$CMRG_INCL $CFLAGS"
   LDFLAGS="$CMRG_LIB $LDFLAGS"

   echo "Checking for CMRG"
   AC_CHECK_LIB(cmrg, cmrg_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_CMRG, true)], [AC_MSG_ERROR(["CMRG library not found; use --with-cmrg-lib-path"])], [-lm])
   AC_CHECK_HEADER(cmrg.h,[],[AC_MSG_ERROR(["CMRG header not found; use --with-cmrg-include-path"])],[AC_INCLUDES_DEFAULT])

   AC_CHECK_FILE([$CMRG_MODEL], [], [AC_MSG_ERROR(["CMRG model dir not found; use --with-cmrg-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_CMRG, false)
fi

# Check optional Tape installation
if test "x$enable_model_tape" = xyes; then
   # Setup compiler/linker flags
   CFLAGS="$TAPE_INCL $CFLAGS"
   LDFLAGS="$TAPE_LIB $LDFLAGS"

   echo "Checking for TAPE"
   AC_CHECK_LIB(tape, tape_init,[AM_CONDITIONAL(UCVM_AM_ENABLE_TAPE, true)], [AC_MSG_ERROR(["TAPE library not found; use --with-tape-lib-path"])], [-lpthread -lproj -lm])
   AC_CHECK_HEADER(tape.h,[],[AC_MSG_ERROR(["TAPE header not found; use --with-tape-include-path"])],[AC_INCLUDES_DEFAULT])

   AC_CHECK_FILE([$TAPE_MODEL], [], [AC_MSG_ERROR(["TAPE model dir not found; use --with-tape-model-path"])])
else
   AM_CONDITIONAL(UCVM_AM_ENABLE_TAPE, false)
fi

# Link -ldl if needed.
if test "x$enable_static" = xno; then
   LDFLAGS="$LDFLAGS -ldl"
fi

AC_CONFIG_FILES([Makefile aux-config/Makefile conf/Makefile model/ucvm/Makefile model/1d/Makefile src/ucvm/Makefile src/ucvm2etree/Makefile src/ucvm2mesh/Makefile src/grd/Makefile src/grd2etree/Makefile src/patch/Makefile src/ecoalesce/Makefile src/ecompact/Makefile src/basin/Makefile test/Makefile examples/Makefile examples/api/Makefile examples/programs/basin/Makefile examples/programs/etree/Makefile examples/programs/ucvm/Makefile examples/programs/mesh/Makefile examples/programs/surface/Makefile  man/Makefile src/ssh/Makefile src/vs30/Makefile utilities/Makefile])

AC_OUTPUT

