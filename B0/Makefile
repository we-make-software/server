MODULE := $(notdir $(CURDIR))
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
# EXTRA_CFLAGS += -I../A28 
# KBUILD_EXTRA_SYMBOLS := ../A28/Module.symvers 
obj-m := $(MODULE).o

all:
	cd .. && $(MAKE)

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

start:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	sudo insmod $(MODULE).ko

remove:
	sudo rmmod $(MODULE) || true
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

test:
	cd .. && $(MAKE) test
	
stop:
	cd .. && $(MAKE) stop

clear:
	cd .. && $(MAKE) clear
