# Makefile - ACE/TAO-CORBA
# SD - Escola Politécnica - PUCPR
# (C) Prof. Luiz Lima Jr.

include $(ACE_ROOT)/include/makeinclude/platform_macros.GNU

#
# Parâmetros:
#

PROJECT = servidor_conta
SERVER = true

IDL.idl = Conta.idl
COMMON.cpp =
SOURCES.cpp = \
	ContaI.cpp \
	servidor.cpp

BINDIR = ../bin
IDLDIR = ../idl
COMMONDIR = ../common

INCLUDES  = $(IDLDIR) $(ACE_ROOT) $(TAO_ROOT) $(TAO_ROOT)/orbsvcs $(COMMONDIR)
LIBRARIES = ACE TAO TAO_CosNaming TAO_AnyTypeCode TAO_IORTable
LIB_DIRS  = $(ACE_ROOT)/lib

# Derived variables

PROGRAM = $(addprefix $(BINDIR)/,$(PROJECT))
IDL = $(addprefix $(IDLDIR)/,$(IDL.idl))
STUBS = $(IDL:%.idl=%C.cpp)
SKELETONS = $(IDL:%.idl=%S.cpp)
COMMON = $(addprefix $(COMMONDIR)/,$(COMMON.cpp))
SOURCES_CLNT = $(STUBS) $(COMMON) $(SOURCES.cpp)
SOURCES = $(SOURCES_CLNT)
ifeq ($(SERVER),true)
	SOURCES += $(SKELETONS)
endif
OBJECTS = $(SOURCES:%.cpp=%.o)
GENERATED = $(STUBS) $(STUBS:%.cpp=%.h) $(STUBS:%.cpp=%.inl) $(OBJECTS) $(PROGRAM)
ifeq ($(SERVER),true)
	GENERATED += $(SKELETONS) $(SKELETONS:%.cpp=%.h) $(SKELETONS:%.cpp=%.inl)
	LIBRARIES += TAO_PortableServer
endif
INCS = $(foreach d, $(INCLUDES), -I$d)
LIBS = $(foreach l, $(LIBRARIES), -l$l)
LIBDIRS = $(foreach d, $(LIB_DIRS), -L$d)

# C++ Adtional Compliler and Linker Flags
# -Wno-tautological-undefined-compare

CPPFLAGS +=
LDFLAGS +=

# Rules for C++.

.SUFFIXES: .cpp .o
COMPILE.cpp = $(CXX) $(CPPFLAGS) $(INCS) $(CCFLAGS)
LINK.cpp = $(CXX) $(LDFLAGS)
.cpp.o:
	@echo -e "Compilando $(notdir $<)"
	@$(COMPILE.cpp) -c -o $(<:%.cpp=%.o) $<

# Rules for stubs/skeletons

%C.cpp:%.idl
	@echo -e "Gerando stubs/skeletons para $(notdir $<)"
	@tao_idl -Gstl -w -I$(IDLDIR) -o $(IDLDIR) $< 2> /dev/null

# Standard targets.

.KEEP_STATE:

all: $(PROGRAM)
objects: $(SOURCES) $(OBJECTS)
sources: $(SOURCES)
teste:
	@echo -e $(SOURCES)
$(PROGRAM): $(SOURCES.cpp) $(OBJECTS)
	@echo -e "\nLinkando $(notdir $@)\n"
	@$(LINK.cpp) -o $@ $(OBJECTS) $(LIBDIRS) $(LIBS)
clean:
	@echo -e "\nLimpando: $(notdir $(OBJECTS) $(PROGRAM))\n"
	@rm -f  $(OBJECTS) core $(PROGRAM)
cleanall:
	@echo -e "\nLimpando tudo : $(notdir $(GENERATED))\n"
	@rm -f core $(GENERATED)

