##
## Makefile.am -- Process this file with automake to produce
##                Makefile.in.
##
#
# Copyright (C) 2013 Bruno Félix Rezende Ribeiro
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

SUBDIRS = man

TEXINPUTS = $(TEXINFO_TEX)$(PATH_SEPARATOR)$(top_srcdir)$(PATH_SEPARATOR)$(top_builddir)
export TEXINPUTS

AM_MAKEINFOFLAGS = -I $(top_srcdir) -I $(top_builddir)
info_TEXINFOS = ccd2cue.texi

ccd2cue_TEXINFOS = ../README.texi ../NEWS.texi ../TODO.texi	\
../AUTHORS.texi ../THANKS.texi ../DONORS.texi essay-header.texi	\
the-gnu-manifesto.texi the-gnu-project.texi			\
linux-and-the-gnu-system.texi					\
why-software-should-not-have-owners.texi			\
$(top_builddir)/package.texi.in copying.texi.in fdl.texi
