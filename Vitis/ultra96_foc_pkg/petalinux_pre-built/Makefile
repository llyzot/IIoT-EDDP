

#################################################################################
# petalinux_pre-built makefile
#

# set variables if not exported from parent makefile
OUT_DIR ?= ./output_test

# local variables
OUT_SW_DIR = ${OUT_DIR}/temp/sw_components


#JM all: sync_out sdk
all: sync_out

.PHONY: clean
clean:
	$(RM) -r ${OUT_SW_DIR}

.PHONY: sync_out
sync_out:
	mkdir -p ${OUT_SW_DIR}/boot
	mkdir -p ${OUT_SW_DIR}/image
	cp ./boot/* ${OUT_SW_DIR}/boot
	cp ./petalinux.bif ${OUT_SW_DIR}/boot
	cp ./image/* ${OUT_SW_DIR}/image


#JM .PHONY: sdk
#JM sdk: 
#JM 	mkdir -p ${OUT_SW_DIR}
#JM 	cp ./sdk.sh ${OUT_SW_DIR}


