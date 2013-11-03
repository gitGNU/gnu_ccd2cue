dnl
dnl configure.ac -- Process this file with autoconf to produce a
dnl                 configure script.
dnl
dnl Copyright (C) 2013 Bruno Félix Rezende Ribeiro <oitofelix@riseup.net>
dnl
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <http://www.gnu.org/licenses/>.
dnl

AC_INIT([ccd2cue], [0.2],
[https://savannah.nongnu.org/bugs/?group=ccd2cue], [ccd2cue],
[http://www.nongnu.org/ccd2cue/])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall])
AC_PREREQ(2.60)
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/ccd2cue.c])
AC_PROG_CC
dnl gl_EARLY
dnl gl_INIT

# i18n support from GNU gettext.
AM_GNU_GETTEXT_VERSION([0.18.1])
AM_GNU_GETTEXT([external])

AC_MSG_NOTICE([checking presence of programs necessary to build documentation])

# We generally cannot invoke the built program when cross-compiling,
# so we test to avoid that (the variable "cross_compiling" is set by
# AC_PROG_CC).
AS_IF(test $cross_compiling = no,
  [AM_MISSING_PROG(HELP2MAN, help2man)], HELP2MAN=:)

# Doxygen documentation;
DX_DOT_FEATURE(ON)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN(ccd2cue, '$(top_builddir)/doc/Doxyfile', '$(top_builddir)/doc/doxygen')

# Rerun configure script when the following files are modified.
AC_SUBST([CONFIG_STATUS_DEPENDENCIES],
['$(top_srcdir)/doc/copying.texi.in'],
['$(top_srcdir)/doc/Doxyfile.in'])

# Output files;
AC_CONFIG_FILES([Makefile
	po/Makefile.in
	src/Makefile
	doc/Makefile
	doc/copying.texi
	doc/Doxyfile
	doc/man/Makefile])

AC_OUTPUT
