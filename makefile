# (c) 2014 Wojciech A. Koszek <wkoszek@freebsd.czest.pl> 
all: unsaver unsaver.pdf

unsaver: unsaver.w 
	cweave unsaver.w
	ctangle unsaver.w
	$(CC) unsaver.c -o unsaver -lX11

unsaver.pdf: unsaver
	pdftex unsaver.tex

clean.j:
	rm -rf unsaver.dvi unsaver.idx unsaver.log \
	unsaver.scn unsaver.tex unsaver.toc unsaver.c

clean: clean.j
	rm -rf unsaver unsaver.pdf
