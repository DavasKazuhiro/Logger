#
# Compila todos os projetos
# (C) Prof. Luiz Lima Jr.
#

PROJECTS = \
	../cliente		\
	../servidor

TARGETS = $(addsuffix _dir,$(PROJECTS))
CLEAN_TARGS = $(addsuffix _rm,$(PROJECTS))

.KEEP_STATE:

all: $(TARGETS)

clean: $(CLEAN_TARGS)

$(TARGETS):
	@echo
	@echo "*** Making $(@:_dir=) ***"
	@echo
	@$(MAKE) --no-print-directory -C $(@:_dir=)

$(CLEAN_TARGS):
	@echo
	@echo "*** Cleaning $(@:_rm=) ***"
	@echo
	@$(MAKE) clean --no-print-directory -C $(@:_rm=)
