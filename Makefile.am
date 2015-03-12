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

include documentation.am





#######################
# Automake directives #
#######################

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = po src doc

EXTRA_DIST = ${top_level_doc} ChangeLog po/Rules-ccd2cue po/LINGUAS.in

DISTCLEANFILES = po/LINGUAS





#########################
# Release documentation #
#########################

release_texi = ${abs_top_srcdir}/doc/release/release.texi.in

### Template recipe intended to generate the top-level release
### documentation files from the respective Texinfo sources.
define release_doc_recipe
${1} : $${top_srcdir}/doc/release/${1}.texi $${release_texi}
	$${AM_V_GEN}
	$${AM_V_at} $${makeinfo} -D file --plaintext \
	  --output=$$@ $$<
endef

### Instantiate the above recipe template for each top-level
### documentation file.
$(foreach f,${release_doc},$(eval $(call release_doc_recipe,$f)))

## Change log build recipe
ChangeLog :
	${AM_V_GEN}
	${AM_V_at} cd ${srcdir} && build-aux/git2cl > ChangeLog





############################
# Philosophy documentation #
############################

essay_header = ${abs_top_srcdir}/doc/philosophy/essay-header.texi

### Template recipe intended to generate the top-level release
### documentation files from the respective Texinfo sources.
define philosophy_doc_recipe
$(call uc,$1) : $${top_srcdir}/doc/philosophy/${1}.texi $${essay_header}
	$${AM_V_GEN}
	$${AM_V_at} $${makeinfo} -D GNUphiStandalone --plaintext \
	  --output=$$@ $$<
endef

### Instantiate the above recipe template for each top-level
### documentation file.
$(foreach f,${philosophy_doc},$(eval $(call philosophy_doc_recipe,$f)))





#############################
# Source-code documentation #
#############################

include doxygen.am
MOSTLYCLEANFILES = $(DX_CLEANFILES)
MAINTAINERCLEANFILES = ${top_level_doc}





################
# Distribution #
################

# 'po/LINGUAS' file is generated automatically at configuration time
# and thus should not be included.
dist-hook :
	$(RM) ${distdir}/po/LINGUAS





###############
# Maintenance #
###############

fetchpo : ensure-vcs
	${AM_V_at} echo 'Fetching PO files...'
	${AM_V_at} $(RSYNC) -Lrtvz translationproject.org::tp/latest/ccd2cue/ po

distgnu : ensure-vcs distcheck
	${AM_V_at} PATH=build-aux:${PATH} gnupload \
	  --to ftp.gnu.org:${PACKAGE_TARNAME} ${PACKAGE_TARNAME}-${PACKAGE_VERSION}.tar.gz

export PACKAGE_NAME PACKAGE_VERSION PACKAGE_MAILING_LIST

announcegnu : ensure-vcs ANNOUNCEMENT
	${AM_V_at} echo -n 'Sending announcement...'
	${AM_V_at} build-aux/make-announcement-mail | \
	  msmtp --read-recipients --account=gnu
	${AM_V_at} echo ' done.'

ensure-vcs :
	${AM_V_at} if test x${VCS} = xn; then \
	  echo "***** Sorry, the requested target can only be made from \
	VCS checkouts. *****"; exit 1; fi

.PHONY : doxygen-run doxygen-doc ensure-vcs
