DIRS = common 01 02 03 04 05 06 07 08 09 10 12 13

all:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) && cd .. &&) true;

clean:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clean && cd .. &&) true;

clobber:
	@$(foreach dir,$(DIRS),cd $(dir) && $(MAKE) clobber && cd .. &&) true;

