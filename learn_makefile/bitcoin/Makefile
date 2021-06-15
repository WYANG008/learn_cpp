
# .DEFAULT_GOAL := generate
.PHONY: all say_hello generate clean

# Pattern rule to print variables, e.g. make print-CC
print-%:
	@echo '$*'='$($*)'

CC := gcc

MAKEOVERRIDES := $(filter V=%,$(MAKEOVERRIDES))
SOURCES_PATH ?= $(BASEDIR)/sources
WORK_PATH = $(BASEDIR)/work
BASE_CACHE ?= $(BASEDIR)/built
SDK_PATH ?= $(BASEDIR)/SDKs
NO_QT ?=
NO_QR ?=
NO_BDB ?=
NO_SQLITE ?=
NO_WALLET ?=
NO_ZMQ ?=
NO_UPNP ?=
NO_NATPMP ?=
MULTIPROCESS ?=
FALLBACK_DOWNLOAD_PATH ?= https://bitcoincore.org/depends-sources

BUILD = $(shell ./config.guess)
HOST ?= $(BUILD)
PATCHES_PATH = $(BASEDIR)/patches
BASEDIR = $(CURDIR)
HASH_LENGTH:=11
DOWNLOAD_CONNECT_TIMEOUT:=30
DOWNLOAD_RETRIES:=3
HOST_ID_SALT ?= salt
BUILD_ID_SALT ?= salt

host:=$(BUILD)
ifneq ($(HOST),)
host:=$(HOST)
endif

ifneq ($(DEBUG),)
release_type=debug
else
release_type=release
endif

base_build_dir=$(WORK_PATH)/build
base_staging_dir=$(WORK_PATH)/staging
base_download_dir=$(WORK_PATH)/download
canonical_host:=$(shell ./config.sub $(HOST))
build:=$(shell ./config.sub $(BUILD))

build_arch =$(firstword $(subst -, ,$(build)))
build_vendor=$(word 2,$(subst -, ,$(build)))
full_build_os:=$(subst $(build_arch)-$(build_vendor)-,,$(build))
build_os:=$(findstring linux,$(full_build_os))
build_os+=$(findstring darwin,$(full_build_os))
build_os:=$(strip $(build_os))
ifeq ($(build_os),)
build_os=$(full_build_os)
endif

host_arch=$(firstword $(subst -, ,$(canonical_host)))
host_vendor=$(word 2,$(subst -, ,$(canonical_host)))
full_host_os:=$(subst $(host_arch)-$(host_vendor)-,,$(canonical_host))
host_os:=$(findstring linux,$(full_host_os))
host_os+=$(findstring darwin,$(full_host_os))
host_os+=$(findstring mingw32,$(full_host_os))

ifeq (android,$(findstring android,$(full_host_os)))
host_os:=android
endif

host_os:=$(strip $(host_os))
ifeq ($(host_os),)
host_os=$(full_host_os)
endif

$(host_arch)_$(host_os)_prefix=$(BASEDIR)/$(host)
$(host_arch)_$(host_os)_host=$(host)
host_prefix=$($(host_arch)_$(host_os)_prefix)
build_prefix=$(host_prefix)/native
build_host=$(build)

AT_$(V):=
AT_:=@
AT:=$(AT_$(V))


include hosts/$(host_os).mk
include hosts/default.mk
include builders/$(build_os).mk
include builders/default.mk
include packages/packages.mk

build_id:=$(shell env CC='$(build_CC)' CXX='$(build_CXX)' AR='$(build_AR)' RANLIB='$(build_RANLIB)' STRIP='$(build_STRIP)' SHA256SUM='$(build_SHA256SUM)' DEBUG='$(DEBUG)' ./gen_id '$(BUILD_ID_SALT)' 'GUIX_ENVIRONMENT=$(realpath $(GUIX_ENVIRONMENT))')
$(host_arch)_$(host_os)_id:=$(shell env CC='$(host_CC)' CXX='$(host_CXX)' AR='$(host_AR)' RANLIB='$(host_RANLIB)' STRIP='$(host_STRIP)' SHA256SUM='$(build_SHA256SUM)' DEBUG='$(DEBUG)' ./gen_id '$(HOST_ID_SALT)' 'GUIX_ENVIRONMENT=$(realpath $(GUIX_ENVIRONMENT))')

qrencode_packages_$(NO_QR) = $(qrencode_packages)

qt_packages_$(NO_QT) = $(qt_packages) $(qt_$(host_os)_packages) $(qt_$(host_arch)_$(host_os)_packages) $(qrencode_packages_)

bdb_packages_$(NO_BDB) = $(bdb_packages)
sqlite_packages_$(NO_SQLITE) = $(sqlite_packages)
wallet_packages_$(NO_WALLET) = $(bdb_packages_) $(sqlite_packages_)

upnp_packages_$(NO_UPNP) = $(upnp_packages)
natpmp_packages_$(NO_NATPMP) = $(natpmp_packages)

zmq_packages_$(NO_ZMQ) = $(zmq_packages)
multiprocess_packages_$(MULTIPROCESS) = $(multiprocess_packages)

packages += $($(host_arch)_$(host_os)_packages) $($(host_os)_packages) $(qt_packages_) $(wallet_packages_) $(upnp_packages_) $(natpmp_packages_)
native_packages += $($(host_arch)_$(host_os)_native_packages) $($(host_os)_native_packages)

ifneq ($(zmq_packages_),)
packages += $(zmq_packages)
endif

ifeq ($(multiprocess_packages_),)
packages += $(multiprocess_packages)
native_packages += $(multiprocess_native_packages)
endif

all_packages = $(packages) $(native_packages)

meta_depends = Makefile funcs.mk builders/default.mk hosts/default.mk hosts/$(host_os).mk builders/$(build_os).mk

$(host_arch)_$(host_os)_native_binutils?=$($(host_os)_native_binutils)
$(host_arch)_$(host_os)_native_toolchain?=$($(host_os)_native_toolchain)

include funcs.mk

final_build_id_long+=$(shell $(build_SHA256SUM) config.site.in)
final_build_id+=$(shell echo -n "$(final_build_id_long)" | $(build_SHA256SUM) | cut -c-$(HASH_LENGTH))
$(host_prefix)/.stamp_$(final_build_id): $(native_packages) $(packages)
	$(AT)rm -rf $(@D)
	$(AT)mkdir -p $(@D)
	$(AT)echo copying packages: $^
	$(AT)echo to: $(@D)
	$(AT)cd $(@D); $(foreach package,$^, tar xf $($(package)_cached); )
	$(AT)touch $@


# hello: hello.c
# 	${CC} hello.c -o hello

all: say_hello
	@echo ${MAKEOVERRIDES}
	@echo $(SOURCES_PATH)
	@echo build $(build)
	@echo canonical_host $(canonical_host)
	@echo build_arch $(build_arch)
	@echo build_vendor $(build_vendor)
	@echo full_build_os $(full_build_os)
	@echo build_os $(build_os)
	@echo host_arch $(host_arch)
	@echo host_vendor $(host_vendor)
	@echo full_host_os $(full_host_os)
	@echo host_os $(host_os)
	@echo host_prefix $(host_prefix)
	@echo build_prefix $(build_prefix)
	@echo build_host $(build_host)
	@echo at $(AT)
	@echo host env CC='$(host_CC)' CXX='$(host_CXX)' AR='$(host_AR)' RANLIB='$(host_RANLIB)' STRIP='$(host_STRIP)' SHA256SUM='$(build_SHA256SUM)' DEBUG='$(DEBUG)' ./gen_id '$(HOST_ID_SALT)' 'GUIX_ENVIRONMENT=$(realpath $(GUIX_ENVIRONMENT))'
	@echo [NO_QR] ${NO_QR}
	@echo [native_packages] ${native_packages}
	@echo [all_packages] ${all_packages}
	@echo [meta_depends] ${meta_depends}
	@echo $(host_arch)_$(host_os)_native_binutils ${$(host_arch)_$(host_os)_native_binutils}
	@echo $(host_arch)_$(host_os)_native_toolchain ${$(host_arch)_$(host_os)_native_toolchain}
	@echo [final_build_id_long] $(final_build_id_long)
	@echo $(shell echo -n "$(final_build_id_long)" | $(build_SHA256SUM) | cut -c-$(HASH_LENGTH))
say_hello:
	@echo "Hello World"

generate:
	@echo "Creating empty text files..."
# touch file-{1..10}.txt

clean:
	@echo "Cleaning up..."
	rm *.txt