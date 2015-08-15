Screen Saver Killer
-------------------

[![Build Status](https://travis-ci.org/wkoszek/unsaver.svg?branch=master)](https://travis-ci.org/wkoszek/unsaver)

This is a simple program for a 8hr hackathon organized in 2014Q4 at Xilinx Inc.
For 2nd hackathon I decided to finally give literate programming a try and
create something small, yet useful. The idea behind the program was to keep the
remote VNC session active and prevent its screensavers to get enabled (long story).

Unsaver was probably one of the most successful pieces of code, if ranked by
popularity and positive feedback that I've ever gotten. The policy wrt.
screensavers impacted a lot of people, and a lot of people found unsaver
useful.

Binaries aren't provided, however unsaver.pdf is a rendered copy from a .w file.

To compile this program you must have a ctangle/cweave programs from a CWEB package:

http://www.literateprogramming.com/cweb_download.html

Once installed, CWEB will give you ctangle and cweave programs. If you install
them successfuly, the "unsaver" can be built by:

	make

Copyright 2014-2015 Wojciech A. Koszek <wojciech@koszek.com>
