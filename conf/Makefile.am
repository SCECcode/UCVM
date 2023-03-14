# GNU Automake config

# Customizes ucvm.conf with configured models.

EXTRA_DIST = ucvm_template.conf

CHANGE_LIST=ucvm.conf

# USGS CenCalVM config
if UCVM_AM_ENABLE_CENCAL
CHANGE_LIST += cencal_model cencal_extmodel
endif

# CVM-H config
if UCVM_AM_ENABLE_CVMH
CHANGE_LIST += cvmh_model
endif

# CVM-S config
if UCVM_AM_ENABLE_CVMS
CHANGE_LIST += cvms_model
endif

# CVM-SI config
if UCVM_AM_ENABLE_CVMSI
CHANGE_LIST += cvmsi_model
endif

# CVMS5 config
if UCVM_AM_ENABLE_CVMS5
CHANGE_LIST += cvms5_model
endif

# WFCVM config
if UCVM_AM_ENABLE_WFCVM
CHANGE_LIST += wfcvm_model
endif

# SED Command
if USER_MAC
SED = sed -i ''
endif

if USER_LINUX
SED = sed -i''
endif

.PHONY=cencal_model cencal_extmodel cvmh_model \
	cvms_model cvmsi_model cvms5_model wfcvm_model cvmnci_model \
	wfcvm_model cvmlt_model cmrg_model

all: ${CHANGE_LIST}

ucvm.conf: template/ucvm.conf
	cp $^ $@
	${SED} "s,PREFIX,${prefix},g" $@

cencal_model: ucvm.conf
	${SED} "s,#cencal_modelpath,cencal_modelpath,g" $^
	${SED} "s,CENCAL_MODEL,${CENCAL_MODEL},g" $^

cencal_extmodel: ucvm.conf
	${SED} "s,#cencal_extmodelpath,cencal_extmodelpath,g" $^
	${SED} "s,CENCAL_EXTMODEL,${CENCAL_EXTMODEL},g" $^

cvmh_model: ucvm.conf
	${SED} "s,#cvmh_modelpath,cvmh_modelpath,g" $^
	${SED} "s,CVMH_MODEL,${CVMH_MODEL},g" $^

cvms_model: ucvm.conf
	${SED} "s,#cvms_modelpath,cvms_modelpath,g" $^
	${SED} "s,CVMS_MODEL,${CVMS_MODEL},g" $^

cvmsi_model: ucvm.conf
	${SED} "s,#cvmsi_modelpath,cvmsi_modelpath,g" $^
	${SED} "s,CVMSI_MODEL,${CVMSI_MODEL},g" $^

cvms5_model: ucvm.conf
	${SED} "s,#cvms5_modelpath,cvms5_modelpath,g" $^
	${SED} "s,CVMS5_MODEL,${CVMS5_MODEL},g" $^

wfcvm_model: ucvm.conf
	${SED} "s,#wfcvm_modelpath,wfcvm_modelpath,g" $^
	${SED} "s,WFCVM_MODEL,${WFCVM_MODEL},g" $^


install:
	mkdir -p ${prefix}/conf
	if ! test . -ef ${prefix}/conf; then \
		cp ucvm.conf ${prefix}/conf; \
		if test -e ucvm_env.sh; then \
			cp ucvm_env.sh ${prefix}/conf; \
		fi; \
		if test -e ucvm_env.py; then \
			cp ucvm_env.py ${prefix}/conf; \
		fi; \
		if test -e call_install_name_tool; then \
			mkdir -p ${prefix}/utilities; \
			chmod +x call_install_name_tool; \
			cp call_install_name_tool ${prefix}/utilities/call_install_name_tool; \
		fi; \
        fi

clean:
	rm -rf ucvm.conf
