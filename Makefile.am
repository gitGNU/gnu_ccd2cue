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

toplevel_doc = README NEWS AUTHORS THANKS TODO DONORS
changelog_dirs = . po src doc doc/man build-aux m4
articles = GNU LINUX-GNU THE-GNU-PROJECT WHY-FREE

EXTRA_DIST = $(articles)

dist-hook:
#	Build top level documentation if checked from CVS.
	for f in $(toplevel_doc); \
	do \
	  if test -f $(srcdir)/"$$f".texi; then \
	    $(MAKEINFO) --plaintext -I $(builddir)/doc \
	      --output=$(distdir)/"$$f" $(srcdir)/"$$f".texi; \
	  fi; \
	done
#	Build ChangeLog files if checked from CVS.
	for d in $(changelog_dirs); \
	do \
	  if test ! -f $(abs_srcdir)/"$$d"/ChangeLog; then \
	    cd $(abs_srcdir)/"$$d" && \
	    $(abs_srcdir)/build-aux/cvs2cl.pl --group-within-date \
	      --no-times --no-indent && \
	    sed --in-place --file=$(abs_srcdir)/changelog.sed \
	      ChangeLog && \
	    cd $(abs_srcdir) && \
	    cp $(abs_srcdir)/"$$d"/ChangeLog $(distdir)/"$$d"; \
	  fi; \
	done

include doxygen.am
MOSTLYCLEANFILES = $(DX_CLEANFILES)
