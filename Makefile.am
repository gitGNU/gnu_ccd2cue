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
changelog_dirs = . po src doc doc/man
articles = GNU LINUX-GNU THE-GNU-PROJECT WHY-FREE

EXTRA_DIST = $(articles)

dist-hook:
##	Build and distribute top level documentation if checked from CVS.
	if test -d $(srcdir)/CVS; then \
	  for f in $(toplevel_doc); \
	  do \
	    echo Generating $$f top level documentation file... && \
	    $(MAKEINFO) --plaintext -I $(builddir)/doc \
	      --output=$(distdir)/"$$f" $(srcdir)/"$$f".texi; \
	  done; \
##	Top level documentation already built if not checked from CVS,
##	so just distribute it.
	else \
	  for f in $(toplevel_doc); \
	  do cp $(srcdir)/"$$f" $(distdir)/"$$f"; \
	  done; \
	fi
##	Build and distribute ChangeLog files if checked from CVS.
	if test -d $(srcdir)/CVS; then \
	  cd $(srcdir) && \
	  build-aux/cvs2cl.pl --distributed --group-within-date \
	    --no-times --no-indent && \
	  cd $(abs_builddir) && \
	  for d in $(changelog_dirs); \
	  do \
	    sed --file=$(srcdir)/changelog.sed \
	      $(srcdir)/"$$d"/ChangeLog > $(distdir)/"$$d"/ChangeLog; \
	  done; \
##	ChangeLog files already built if not checked from CVS, so just
##	distribute it.
	else \
	  for d in $(changelog_dirs); \
	  do cp $(srcdir)/"$$d"/ChangeLog $(distdir)/"$$d"; \
	  done; \
	fi

include doxygen.am
MOSTLYCLEANFILES = $(DX_CLEANFILES)
