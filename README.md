Screen Saver Killer
-------------------

[![Build Status](https://travis-ci.org/wkoszek/unsaver.svg?branch=master)](https://travis-ci.org/wkoszek/unsaver)

This is a simple program for a 8hr hackathon organized in 2014Q4 at Xilinx Inc.

It will work on modestly decent GNU Linux distribution with X11 development
libraries.

This was the 2nd hackathon which I participated in, and I decided to finally
give a Literate Programming a try and create something small, yet useful.
The idea behind the program was to keep the remote VNC session active and
prevent its screensavers to get enabled (long story).

`unsaver` was probably one of the most successful pieces of code, if ranked
by popularity and positive feedback, compared to competitors. The policy
wrt.  screensavers impacted a lot of people, and a lot of people found
`unsaver` useful.

# Requirements

Binaries aren't provided, however `unsaver.pdf` is a rendered copy from a
`unsaver.w` file.  To compile this program you must have a ctangle/cweave
programs from a CWEB package:

- http://www.literateprogramming.com/cweb_download.html
- http://www-cs-faculty.stanford.edu/~uno/cweb.html

To build it automatically, run:

	make toolbuild

# How to build

Once `ctangle` and `cweave` is build and installed, you make build it:

	make

# How to use `unsaver`

To use the `unsaver`, just run it:

	./unsaver

You can pass 2 options:

	./unsaver -c 5

Which will start moving cursor back and forth of 5 pixels. You can also pass
`-s` option, which changes the wait interval:

	./unsaver -s 4

Will move the cursor every 4 seconds. Options `-c` and `-s` can be used
together.

# Author

- Wojciech Adam Koszek, [wojciech@koszek.com](mailto:wojciech@koszek.com)
- [http://www.koszek.com](http://www.koszek.com)
