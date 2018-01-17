TARGETS =

ifeq (,$(TARGETS))
endif

.PHONY: $(TARGETS)
$(TARGETS):
	$(MAKE) -C $@

.PHONY: clean
clean:
	$(foreach T, $(TARGETS), $(MAKE) clean -C $(T);)
