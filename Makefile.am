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





#######################
# Automake directives #
#######################

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = po src doc

top_level_doc = ${release_doc} $(call uc,${philosophy_doc})

EXTRA_DIST = ${top_level_doc} ChangeLog build-aux/gendocs.sh po/Rules-ccd2cue





#######################
# Texinfo definitions #
#######################

export texinfo_includes = \
-I ${abs_top_srcdir}/build-aux \
-I ${abs_top_srcdir}/doc \
-I ${abs_top_srcdir}/doc/release \
-I ${abs_top_srcdir}/doc/philosophy \
-I ${abs_top_srcdir}/doc/www

export AM_MAKEINFOFLAGS = ${texinfo_includes}
export makeinfo = ${MAKEINFO} ${AM_MAKEINFOFLAGS} ${MAKEINFOFLAGS}

export MAKEINFOHTML = ${MAKEINFO} --html
export AM_MAKEINFOHTMLFLAGS = ${texinfo_includes}
export makeinfohtml = ${MAKEINFOHTML} ${AM_MAKEINFOHTMLFLAGS} ${MAKEINFOHTMLFLAGS}

export TEXI2DVI := ${TEXI2DVI} ${texinfo_includes}





#########################
# Release documentation #
#########################

export release_texi = ${abs_top_srcdir}/doc/release/release.texi

export release_doc = README NEWS TODO AUTHORS THANKS DONORS ANNOUNCEMENT

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

export essay_header = ${abs_top_srcdir}/doc/philosophy/essay-header.texi

export philosophy_doc = the-gnu-manifesto the-gnu-project	\
linux-and-the-gnu-system why-software-should-not-have-owners	\
why-free-software-needs-free-documentation			\
gnu-free-documentation-license

# Lower-case to upper-case conversion funtion
uc = $(shell echo ${1} | LC_ALL=C tr '[:lower:]' '[:upper:]')

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

## Distribute top-level release and philosophy documentation.
distdir-hook dist-hook : ${top_level_doc}
