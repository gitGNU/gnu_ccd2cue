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

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = po src doc

toplevel_doc = README NEWS AUTHORS THANKS TODO DONORS
changelog_dirs = . po src doc doc/man
articles = THE-GNU-MANIFESTO THE-GNU-PROJECT LINUX-AND-THE-GNU-SYSTEM	\
WHY-SOFTWARE-SHOULD-NOT-HAVE-OWNERS

dist-hook:
##	Build and distribute top level documentation if checked from CVS.
	if test -d $(srcdir)/CVS; then \
	  for f in $(toplevel_doc); \
	  do \
	    echo Generating $$f top level documentation file... && \
	    $(MAKEINFO) -D file --plaintext -I $(builddir)/doc \
	      --output=$(distdir)/"$$f" $(srcdir)/"$$f".texi; \
	  done; \
##	Top level documentation already built if not checked from CVS,
##	so just distribute it.
	else \
	  for f in $(toplevel_doc); \
	  do cp $(srcdir)/"$$f" $(distdir)/"$$f"; \
	  done; \
	fi
##	Build and distribute GNU philosophy essays if checked from
##	CVS.
	if test -d $(srcdir)/CVS; then \
	  for f in $(articles); \
	  do \
	    echo Generating $$f top level GNU philosophy essay file... && \
	    $(MAKEINFO) -D GNUphiStandalone --plaintext --output=$(distdir)/"$$f" \
		$(srcdir)/doc/"$$(echo $$f | tr '[:upper:]' '[:lower:]')".texi; \
	  done; \
##	GNU philosophy essays already built if not checked from CVS,
##	so just distribute it.
	else \
	  for f in $(articles); \
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

# Update of the online web pages for the documentation with the
# gendocs.sh script; see
# http://www.gnu.org/prep/maintain/html_node/Invoking-gendocs_002esh.html
gendocs = $(abs_top_srcdir)/build-aux/gendocs.sh
gendocs_envvars = TEXINPUTS="../../build-aux:$TEXINPUTS" GENDOCS_TEMPLATE_DIR=..

doctemp = doc/wwwtemp
www_target = $(HOME)/savannah/web/ccd2cue/manual

manual = "ccd2cue"
manual_title = "<strong>GNU ccd2cue</strong> - <em>CCD sheet to CUE sheet converter</em>"
email = $(PACKAGE_BUGREPORT)
gendocs_args = --email $(email) $(manual) $(manual_title)

wwwdoc:
	rm -rf $(doctemp) && mkdir $(doctemp)
	cd $(doctemp) \
	&& ln -s ../*.texi . \
	&& env $(gendocs_envvars) $(gendocs) $(gendocs_args)
	cp -arf $(doctemp)/manual/. $(www_target)

maintainer-clean-local:
	-rm -rf $(doctemp)
