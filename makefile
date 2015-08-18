# (c) 2014 Wojciech A. Koszek <wkoszek@freebsd.czest.pl> 
all: unsaver

TOOLVER=20150814
CWEAVE=tools/cweave
CTANGLE=tools/ctangle

unsaver: unsaver.w 
	$(CWEAVE) unsaver.w
	$(CTANGLE) unsaver.w
	$(CC) unsaver.c -o unsaver -lX11

unsaver.pdf: unsaver
	pdftex unsaver.tex

clean.j:
	rm -rf unsaver.dvi unsaver.idx unsaver.log \
	unsaver.scn unsaver.tex unsaver.toc

clean: clean.j
	rm -rf unsaver

toolbuild:
	rm -rf tools $(TOOLVER).tar.gz
	wget https://github.com/wkoszek/cweb/archive/$(TOOLVER).tar.gz
	tar -xzf $(TOOLVER).tar.gz
	mv cweb-$(TOOLVER) tools
	(cd tools && make)
