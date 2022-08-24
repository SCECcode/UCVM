## Current
* Added SCPBR

## 2022-07-01 Mei-Hui Su <mei@usc.edu>
* CVMS,CVMS5,CVMSI,WFCFM are all dynamically loadable models
* Added CVMHLABN/CVMHSGBN/CVMHVBN/CVMHIBBN/CVMHRBN and
        CVMHSBBN/CVMHSBCBN/CVMHSMBN/CVMHSTBN models
* Added continuous integrating testing using github action/runner
* Replace Vs30 map with Thompson California Vs30 Model(2018/2020)

## 2021-10-01  Mei-Hui Su <mei@usc.edu>
* Rework largefiles get/check/stage to use setup.list

## 2021-07-01  Mei-Hui Su <mei@usc.edu>
* Added ucvm_utah map
* Added IVLSU/CVLSU/WFCVM models
* Split ucvm_plotting into a separate release 
* MacOS Darwin support 
* Python2/Python 3 support 

## 2019-06-01  Mei-Hui Su <mei@usc.edu>
* Added z-range to plotting capability for external elygtl 

## 2019-04-15  Mei-Hui Su <mei@usc.edu>
* Added new plotting capability of using elevation in addition to depth 
* Replace Proj4 with Proj-5.0.0
* Update Wills map with newer Wills 2015 map, https://scec.usc.edu/scecpedia/Wills_Map
* Update CVMH-15.1.0 with misplaced scripts to enable standalone verification
* Added examples directory to showcase plotting scripts and programs using UCVM

## 2018-07-15  Mei-Hui Su <mei@usc.edu>
* Support for CCA06(optional GTL), Central California Velocity Model
* Support for CS17.3(optional GTL), Cypershake study 17.3 Central California Velocity Model 
* Support for CS17.3-H(optional GTL), Cypershake study 17.3 Central California Velocity Model with San Joaquin and Santa Maria Basins data from Havard's group
* Fixed the proper tiling of models 
* Fixed the implmenation of plugin schema for the dynamic loading of newer models
* Update to CVMH-15.1.1 to remove compilation errors on Mac
* Expanded processing result from basin_query_mpi to basin_query_mpi_complete
* Expanded scalability of ucvm2mesh_mpi with a new ucvm2mesh_mpi_layer program 
* Expanded plotting scripts to preserve intermediate data product and metadata

## 2017-01-30 Philip Maechling <maechlin@usc.edu>
* Janurary 2017 release
* Moved distribution to github repository
* Renamed codebase to UCVMC as C-language version of UCVM
* Removed unsupported models and features
* Updated installation scripts including get_largefiles.py, 
*  check_largefiles_md5.py, stage_large_files.py to be run
*  in UCVMC/and setup_ucvm_setup.py
* Modified make check to run from source directory
* Changed default UCVMC/conf/ucvm.conf to remove unused models
* Changed default CVM-H setting to no background model, and no GTL
* Changed default CVM-S5 to no GTL, and no background model

## 2015-10-01 David Gill <davidgil@usc.edu>
* Sept 2015 release

## 2014-07-28 David Gill <davidgil@usc.edu>
* Support for CVM-S5
* Dynamic loading of models
* Introduction of new Python querying and plotting API (PyCVM)
* Improved documentation
* Minor bug fixes on various compute systems

## 2014-03-31 David Gill <davidgil@usc.edu>
* Added utilities to generate small-scale heterogeneities
* CVM-S4.26 official support
* Broadband 1D model support (model used in CyberShake 14.2 study)
* Added vs30 calculator, vs30_query
* Scripts to plot horizontal slices, cross-sections, vs30 maps, and Z-maps
* Documentation enhancements
* Improved error handling
* Official supported systems list, plus bug fixes for those systems

## 2013-09-08 David Gill <davidgil@usc.edu>
* Added setup script for UCVM
* Added feature improvements
* Installable on Mac OS X

## 2012-02-09 Patrick Small <patrices@usc.edu>
* Release of UCVM 12.2.0

## 2011-08-22  Patrick Small <patrices@usc.edu>
* Release candidate preparation
