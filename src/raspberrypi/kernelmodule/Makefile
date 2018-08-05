KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build
obj-m := rascsidrv.o
ccflags-y := -O3

ifdef FULLSPEC	# フルスペック(SCSI論理,標準ピンアサイン)
ccflags-y+=-DCONNECT_TYPE_FULLSPEC
else
ifdef AIBOM	# AIBOM版(正論理,固有ピンアサイン)
ccflags-y+=-DCONNECT_TYPE_AIBOM
else
ifdef GAMERNIUM	# GAMERnium.com版(標準論理,固有ピンアサイン)
ccflags-y+=-DCONNECT_TYPE_GAMERNIUM
else	# 標準(SCSI論理,標準ピンアサイン)
ccflags-y+=-DCONNECT_TYPE_STANDARD
endif
endif
endif

all:
	$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) clean
