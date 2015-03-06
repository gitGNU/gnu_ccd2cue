##
## Makefile.am -- Process this file with automake to produce
##                Makefile.in.
##
#
# Copyright (C) 2013, 2014, 2015 Bruno Félix Rezende Ribeiro
# <oitofelix@gnu.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

bin_PROGRAMS = ccd2cue
ccd2cue_SOURCES = ccd2cue.c \
	memory.c memory.h \
	io.c io.h \
	file.c file.h \
	array.c array.h \
	errors.c errors.h \
	crc.c crc.h \
	ccd.c ccd.h \
	cue.c cue.h \
	cdt.c cdt.h \
	convert.c convert.h \
	i18n.h

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"
AM_CFLAGS = -Wall
