Projects := B0 C0 D0 A0


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

push:
	git add .
	git commit -m "WeMakeSoftware Update macros,Codes and docs"
	git push origin main --force
