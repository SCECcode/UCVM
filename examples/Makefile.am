############################################
# Special build targets
############################################
SUBDIRS = api programs/basin programs/ucvm programs/etree programs/mesh programs/surface

install:
	mkdir -p ${prefix}/tests
	@for i in $(SUBDIRS); do \
		(cd $${i}; make -s install;) \
	done

