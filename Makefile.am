##
## Makefile.am -- Process this file with automake to produce
##                Makefile.in.
##
#
# Copyright (C) 2013 Bruno Félix Rezende Ribeiro
# <oitofelix@riseup.net>
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

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = po src doc

EXTRA_DIST = DONORS GNU LINUX-GNU THE-GNU-PROJECT WHY-FREE

dist-hook: README NEWS AUTHORS THANKS TODO DONORS ChangeLog

define makeinfo_text
makeinfo --plaintext -I doc --output=$@ $<
endef

README: README.texi
	$(makeinfo_text)

NEWS: NEWS.texi
	$(makeinfo_text)

AUTHORS: AUTHORS.texi
	$(makeinfo_text)

THANKS: THANKS.texi
	$(makeinfo_text)

TODO: TODO.texi
	$(makeinfo_text)

DONORS: DONORS.texi
	$(makeinfo_text)

ChangeLog::
	build-aux/cvs2cl.pl --distributed --group-within-date --no-times --no-indent
	sed --in-place --file=changelog.sed $$(find -name ChangeLog)

include doxygen.am
MOSTLYCLEANFILES = $(DX_CLEANFILES)
