SUBDIRS = bar foo main1 main2

all : $(SUBDIRS)
foo : bar
main1 : foo
main2 : foo
install : $(SUBDIRS)

define versioning # version soversion
	$(MAKE) -C $@ soversion=lib$@.so.$(2)
	@ cp $@/$@ $@/lib$@.so.$(1)
	@ cd $@; ln -f -s lib$@.so.$(1) lib$@.so.$(2); cd ..
	@ cd $@; ln -f -s lib$@.so.$(1) lib$@.so; cd ..
endef

bar :
	$(call versioning,1.2.3,1.2) #,version,soversion
foo :
	$(call versioning,99.1890.70,99.1890) #,version,soversion

main1 :
	$(MAKE) -C $@
main2 :
	$(MAKE) -C $@

# make -C src/ DESTDIR=~/foo install
install :
	install -d "$(DESTDIR)/usr/local/bin"
	install -d "$(DESTDIR)/usr/local/lib"
	install -m0755 main1/main1 "$(DESTDIR)/usr/local/bin"
	install -m0755 main2/main2 "$(DESTDIR)/usr/local/bin"
	install -m0755 bar/*.so bar/*.so.* "$(DESTDIR)/usr/local/lib"
	install -m0755 foo/*.so foo/*.so.* "$(DESTDIR)/usr/local/lib"

clean :
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
.PHONY : $(SUBDIRS) all clean install
