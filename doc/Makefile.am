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

include ../documentation.am





#######################
# Automake directives #
#######################

SUBDIRS = man

TEXI2DVI := ${TEXI2DVI} ${texinfo_includes}





######################
# Main documentation #
######################

info_TEXINFOS = ccd2cue.texi

# 'release/release.texi' file is not in the list below because
# although 'ccd2cue.texi' includes it, as does every other Texinfo
# source, we don't want to trigger a rebuild of the manual after the
# user has configured the package, since it is generated at that
# phase.  Therefore, before a release it's best to start with a clean
# source tree to ensure every file is up to date.

ccd2cue_TEXINFOS = \
  release/release.texi.in \
  $(addprefix release/,${release_doc:=.texi}) \
  philosophy/essay-header.texi \
  $(addprefix philosophy/,${philosophy_doc:=.texi}) \
  copying.texi \
  release/manifesto.texi \
  release/description.texi





##########################
# Homepage documentation #
##########################

# Directory to put the homepage into
homepage_dir = homepage

homepage_header := ${srcdir}/www/header.shtml
homepage_footer := ${srcdir}/www/footer.texi

homepage-local : ensure-vcs ${release_doc:%=${homepage_dir}/%.html}

${homepage_dir}/%.html : release/%.texi ${release_texi} \
  ${homepage_header} ${homepage_footer} homepage-doc
	${AM_V_GEN}
	${AM_V_at} test -d ${homepage_dir} || mkdir -p ${homepage_dir}
	${AM_V_at} ${makeinfohtml} -D homepage --no-split --no-node-files --no-headers \
	  -c SHOW_TITLE=undef --output=$@ $<
	${AM_V_at} ${SED} --in-place \
	  '/^<!DOCTYPE/,/^<\/head>$$/d;/^<div class="header">$$/,/^<\/div>$$/d;/^<body/d' $@
	${AM_V_at} cat ${homepage_header} $@ > $@-2 && mv $@-2 $@
	${AM_V_at} cp -r ${srcdir}/www/.symlinks ${srcdir}/www/images ${homepage_dir}

clean-local ::
	-${AM_V_at} rm -rf ${homepage_dir}


###########
### Homepage Documentation
#######

manual_title = "<strong>GNU ccd2cue</strong> - <em>CCD sheet to CUE sheet converter</em>"

### Gendocs settings

# Script executable
gendocs := ${abs_top_srcdir}/build-aux/gendocs.sh

# Environment variables
gendocs_envvars := TEXINPUTS="${abs_top_srcdir}/build-aux:$$TEXINPUTS"	\
  GENDOCS_TEMPLATE_DIR=${abs_top_srcdir}/doc/www

# Arguments
gendocs_args := ${texinfo_includes} --email ${PACKAGE_BUGREPORT} \
  -s ${abs_srcdir}/${PACKAGE}.texi ${PACKAGE} ${manual_title}

homepage-doc:
	${AM_V_GEN}
	${AM_V_at} test -d ${homepage_dir} || mkdir -p ${homepage_dir}
	${AM_V_at} cd ${homepage_dir} && \
	  if test -z ${AM_V_at}; \
	     then env ${gendocs_envvars} ${gendocs} ${gendocs_args}; \
	     else env ${gendocs_envvars} ${gendocs} ${gendocs_args} > \
	       /dev/null; \
	   fi;
	${AM_V_at} rm -f ${homepage_dir}/${PACKAGE}.*


ensure-vcs :
	${AM_V_at} if test x${VCS} = xn; then \
	  echo "***** Sorry, the requested target can only be made from \
	VCS checkouts. *****"; exit 1; fi


.PHONY: ensure-vcs homepage-doc
