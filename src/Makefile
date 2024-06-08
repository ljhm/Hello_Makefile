# Makefile for top dir

# $(call makever,1.2.3)
# major.minor.patch
# libtool manual: -version-number
define makever
	@ $(MAKE) -C $@ soname=lib$@.so.$(word 1,$(subst ., ,$(1)))
	@ # $(MAKE) -C $@ VER=$(1) MAJOR=$(word 1,$(subst ., ,$(1))) # macos

	@ cp $@/$@ $@/lib$@.so.$(1)

	@ ( cd $@; \
		ln -f -s lib$@.so.$(1) lib$@.so.$(word 1,$(subst ., ,$(1))) ; )

	@ ( cd $@; \
		ln -f -s lib$@.so.$(1) lib$@.so ; )
endef

SUBDIRS = main foo

all : $(SUBDIRS)
install : $(SUBDIRS)

main : foo
main : ; @ $(MAKE) -C $@
foo : ; $(call makever,1.2.3)

# make DESTDIR=~/foo install
# Alexandre Duret-Lutz's Autotools Tutorial (without animations):
# "is ready to be uncompressed in / on many hosts"
install :
	install -d $(DESTDIR)/usr/local/bin
	install -d $(DESTDIR)/usr/local/lib
	install -m 0755 main/main $(DESTDIR)/usr/local/bin
	cp -P foo/*.so* $(DESTDIR)/usr/local/lib
#	cp -a foo/*.so* $(DESTDIR)/usr/local/lib # macos

clean :
	@ for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
.PHONY : $(SUBDIRS) all install clean


#
# do not use rpath: https://wiki.debian.org/RpathIssue ,
#
# $ pwd
# /home/ljh/Documents/hello_c
# $ ls
# src  _vscode
# $ ls src/
# Makefile  foo  main
# $
# $ make -C src
# $ cp src/foo/foo src/foo/libfoo.so
# $ make -C src
# $
# $ LD_LIBRARY_PATH=src/foo  ./src/main/main
# hello
# foo
# $ make -C src DESTDIR=~/hello install
#
# $ DYLD_LIBRARY_PATH=src/foo  ./src/main/main # macos
# LDFLAGS += -install_name libfoo.so.$(MAJOR) -current_version $(VER) -compatibility_version $(MAJOR) # macos
#
