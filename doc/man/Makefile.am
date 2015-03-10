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

$(eval include ${srcdir}/Makefile.mk)

dist_man_MANS = ccd2cue.1
l10n_man = ${LINGUAS:%=ccd2cue.%.1}
EXTRA_DIST = Makefile.mk ${l10n_man}

MAINTAINERCLEANFILES = ${dist_man_MANS} ${l10n_man}

ccd2cue.1: $(top_srcdir)/src/ccd2cue.c
	${AM_V_GEN}
	${AM_V_at} $(MAKE) --directory=$(top_builddir)/src $(AM_MAKEFLAGS) ccd2cue
	${AM_V_at} $(HELP2MAN) \
	  --name='CCD sheet to CUE sheet converter' \
	  --output=$@  $(top_builddir)/src/ccd2cue

ccd2cue.%.1: $(top_srcdir)/src/ccd2cue.c $(top_srcdir)/po/%.gmo
	${AM_V_GEN}
	${AM_V_at} $(MAKE) --directory=$(top_builddir)/src $(AM_MAKEFLAGS) ccd2cue
	${AM_V_at} LINGUA=$$(echo $@ | $(SED) 's/^.*ccd2cue\.\(.*\)\.1$$/\1/'); \
	  LOCALE=$$($(GREP) ^$${LINGUA} /usr/share/i18n/SUPPORTED | \
	      $(SED) 's/^\(.*_..\).*$$/\1/' | head --lines=1).UTF-8; \
	  $(MKDIR_P) tmp/$${LINGUA}/LC_MESSAGES && \
	  cp $(top_srcdir)/po/$${LINGUA}.gmo \
	    tmp/$${LINGUA}/LC_MESSAGES/ccd2cue.mo && \
	  LANGUAGE=C LANG=C LC_MESSAGES=C \
	    LD_PRELOAD="/usr/lib/help2man/bindtextdomain.so" \
	    LOCALEDIR=tmp TEXTDOMAIN=ccd2cue $(HELP2MAN) \
	    --name="$$(TEXTDOMAIN=ccd2cue TEXTDOMAINDIR=tmp \
	      LANGUAGE=$${LOCALE} LANG=$${LOCALE} LC_MESSAGES=$${LOCALE} \
	      gettext 'CCD sheet to CUE sheet converter')" \
	    --locale=$${LOCALE} --output=$@ \
	    $(top_builddir)/src/ccd2cue && \
	  $(RM) -rf tmp

install-man-local : ${l10n_man}
	${AM_V_at} for f in $^; do \
	  LINGUA=$$(echo $$f | $(SED) 's/^.*ccd2cue\.\(.*\)\.1$$/\1/'); \
	   $(MKDIR_P) ${DESTDIR}${mandir}/$${LINGUA}.UTF-8/man1 && \
	   $(INSTALL_DATA) $$f ${DESTDIR}${mandir}/$${LINGUA}.UTF-8/man1/ccd2cue.1; done;

all-local : ${l10n_man}
