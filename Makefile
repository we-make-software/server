Projects := B0 D0 C0 A0


.PHONY: all

all:
	for item in $(Projects); do \
		$(MAKE) -C $$item start; \
	done

stop:
	@for item in $(shell echo $(Projects) | tr ' ' '\n' | tac); do \
		$(MAKE) -C $$item remove; \
	done

test: all
	dmesg -w 

clear:
	dmesg -C

log:
	dmesg -w 

Service:
	dmesg -C
	make stop
	make all	