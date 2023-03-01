SUBDIRS = main foo

all : $(SUBDIRS)
install : $(SUBDIRS)

## makever ##
# $(call makever,1.x.y,1) # ,version,soname
# $(call makever,1.2.3,1) # ,1.2.3,1
# version: major.minor.patch
# soname: equals to the major number
# backwards compatibility is based on the major number
#
# libfoo.so -> libfoo.so.1.2.3
# libfoo.so.1 -> libfoo.so.1.2.3
# libfoo.so.1.2.3
#

define makever
	$(MAKE) -C $@ soname=lib$@.so.$(2)
	@ cp $@/$@ $@/lib$@.so.$(1)
	@ cd $@; ln -f -s lib$@.so.$(1) lib$@.so.$(2); cd ..
	@ cd $@; ln -f -s lib$@.so.$(1) lib$@.so; cd ..
endef

main : foo

main :
	$(MAKE) -C $@

foo :
	$(call makever,1.2.3,1) # ,version,soname

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
