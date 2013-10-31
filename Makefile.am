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

SUBDIRS = po src doc

EXTRA_DIST = DONORS GNU LINUX-GNU THE-GNU-PROJECT WHY-FREE

include doc/doxygen.am
MOSTLYCLEANFILES = $(DX_CLEANFILES)

dist-hook: README NEWS AUTHORS THANKS TODO DONORS COPYING COPYING.DOC ChangeLog

define makeinfo_text
makeinfo --plaintext --output=$@ $<
endef

README: doc/README.texi
	$(makeinfo_text)

NEWS: doc/NEWS.texi
	$(makeinfo_text)

AUTHORS: doc/AUTHORS.texi
	$(makeinfo_text)

THANKS: doc/THANKS.texi
	$(makeinfo_text)

TODO: doc/TODO.texi
	$(makeinfo_text)

DONORS: doc/DONORS.texi
	$(makeinfo_text)

COPYING: doc/COPYING.texi
	$(makeinfo_text)

COPYING.DOC: doc/COPYING.texi
	$(makeinfo_text)

ChangeLog::
	build-aux/cvs2cl.pl --distributed --group-within-date --no-times --no-indent
	sed --in-place --file=changelog.sed $$(find -name ChangeLog)
