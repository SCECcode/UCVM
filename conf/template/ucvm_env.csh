## 
##  models: [ %%UCVM_modelsToInstall% ]
##  libraries: [ %%UCVM_librariesToInstall% ]
## 

setenv UCVM_SRC_PATH %%UCVM_SRC_PATH%
setenv UCVM_INSTALL_PATH %%UCVM_INSTALL_PATH%

# update PATH

foreach f ( ${UCVM_INSTALL_PATH}/bin ${UCVM_INSTALL_PATH}/utilities )

set ff = ( $f )

if( $?PATH ) then
   if( `echo $PATH | gawk -v s="$ff[1]" -F":" 'BEGIN{x=0;}{for(i=1;i<=NF;i++)if($i==s)x=1;}END{print x;}'` == 0) then

      if( `echo $ff | gawk 'BEGIN{x=0;}{if(NF>1)x=$2;}END{print x;}'` == "after" ) then
         setenv PATH ${PATH}:${ff[1]}
      else
         setenv PATH ${ff[1]}:${PATH}
      endif
   endif
else
   setenv PATH $ff
endif

end

# update PYTHONPATH

foreach f ( ${UCVM_INSTALL_PATH}/utilities/pycvm )

set ff = ( $f )

if( $?PYTHONPATH ) then
   if( `echo $PYTHONPATH | gawk -v s="$ff[1]" -F":" 'BEGIN{x=0;}{for(i=1;i<=NF;i++)if($i==s)x=1;}END{print x;}'` == 0) then

      if( `echo $ff | gawk 'BEGIN{x=0;}{if(NF>1)x=$2;}END{print x;}'` == "after" ) then
         setenv PYTHONPATH ${PYTHONPATH}:${ff[1]}
      else
         setenv PYTHONPATH ${ff[1]}:${PYTHONPATH}
      endif
   endif
else
   setenv PYTHONPATH $ff
endif

end

# update LD_LIBRARY_PATH

foreach f ( %%UCVM_expandedLibrariesToInstall% %%UCVM_expandedModelsToInstall% )

set ff = ( $f )

if( $?LD_LIBRARY_PATH ) then
   if( `echo $LD_LIBRARY_PATH | gawk -v s="$ff[1]" -F":" 'BEGIN{x=0;}{for(i=1;i<=NF;i++)if($i==s)x=1;}END{print x;}'` == 0) then

      if( `echo $ff | gawk 'BEGIN{x=0;}{if(NF>1)x=$2;}END{print x;}'` == "after" ) then
         setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${ff[1]}
      else
         setenv LD_LIBRARY_PATH ${ff[1]}:${LD_LIBRARY_PATH}
      endif
   endif
else
   setenv LD_LIBRARY_PATH $ff
endif

end

# update DYLD_LIBRARY_PATH

foreach f ( %%UCVM_expandedLibrariesToInstall% %%UCVM_expandedModelsToInstall% )

set ff = ( $f )

if( $?DYLD_LIBRARY_PATH ) then
   if( `echo $DYLD_LIBRARY_PATH | gawk -v s="$ff[1]" -F":" 'BEGIN{x=0;}{for(i=1;i<=NF;i++)if($i==s)x=1;}END{print x;}'` == 0) then

      if( `echo $ff | gawk 'BEGIN{x=0;}{if(NF>1)x=$2;}END{print x;}'` == "after" ) then
         setenv DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH}:${ff[1]}
      else
         setenv DYLD_LIBRARY_PATH ${ff[1]}:${DYLD_LIBRARY_PATH}
      endif
   endif
else
   setenv DYLD_LIBRARY_PATH $ff
endif

end

exit


