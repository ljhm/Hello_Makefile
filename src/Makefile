SUBDIRS = main foo

all : $(SUBDIRS)
install : $(SUBDIRS)

# $(call version_number,1.2.3) # major.minor.patch
# libtool manual chapter 4.2: -version-number
define version_number
	$(MAKE) -C $@ soname=lib$@.so.$(word 1,$(subst ., ,$(1)))
	@ cp $@/$@ $@/lib$@.so.$(1)
	@ cd $@; ln -f -s lib$@.so.$(1) lib$@.so.$(word 1,$(subst ., ,$(1))); cd ..
	@ cd $@; ln -f -s lib$@.so.$(1) lib$@.so; cd ..
endef

main : foo

main :
	$(MAKE) -C $@

foo :
	$(call version_number,5.2.3)

# make DESTDIR=~/foo install
install :
	install -d "$(DESTDIR)/usr/local/bin"
	install -d "$(DESTDIR)/usr/local/lib"
	install -m 0755 main/main "$(DESTDIR)/usr/local/bin"
	install -m 0755 foo/*.so* "$(DESTDIR)/usr/local/lib"

clean :
	@ for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
.PHONY : $(SUBDIRS) all install clean
