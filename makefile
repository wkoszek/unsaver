# (c) 2014 Wojciech A. Koszek <wkoszek@freebsd.czest.pl> 
all: toolbuild unsaver

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
	unsaver.scn unsaver.tex unsaver.toc unsaver.c

clean: clean.j
	rm -rf unsaver unsaver.pdf

toolbuild:
	wget https://github.com/wkoszek/cweb/archive/20150814.tar.gz
	tar -xzf 20150814.tar.gz
	mv cweb-20150814 tools
	(cd tools && make)
