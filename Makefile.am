## {
##
##  encode_weak_cisco, encodes passphrase like the old "7" weak and reversible cisco crypto algorithm 
##  Copyright (C) 2016-2020 Jean-Daniel Pauget <jdpauget@rezopole.net>
##  
##  This program is free software; you can redistribute it and/or
##  modify it under the terms of the GNU General Public License
##  as published by the Free Software Foundation; either version 2
##  of the License, or (at your option) any later version.
##  
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##  
##  You should have received a copy of the GNU General Public License
##  along with this program; if not, write to the Free Software
##  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
##
## }


ACLOCAL_AMFLAGS = -I m4

vimtest: encode_weak_cisco
	./encode_weak_cisco --salt=2 totoIStoto
	echo "02120B4F042F3C35435A06"
	./encode_weak_cisco -h
	./encode_weak_cisco --help
	./encode_weak_cisco --salt=3 -- -tagada

bin_PROGRAMS = encode_weak_cisco
man1_MANS = encode_weak_cisco.1

encode_weak_cisco_SOURCES = encode_weak_cisco.cpp
encode_weak_cisco_CXXFLAGS = @CXXFLAGS@

clean-local:
	:

distclean-local:
	:
	rm -f m4/*.m4
	rm -f config.h.in~
	rm -rf debian
	rm -f Makefile
	rm -f encode-weak-cisco*.deb


