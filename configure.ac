dnl
dnl configure.ac -- Process this file with autoconf to produce a
dnl                 configure script.
dnl
dnl Copyright (C) 2013 Bruno Félix Rezende Ribeiro <oitofelix@gnu.org>
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

AC_INIT([GNU ccd2cue], [0.3],
[https://savannah.gnu.org/bugs/?group=ccd2cue], [ccd2cue],
[https://www.gnu.org/software/ccd2cue])

AC_DEFINE(PACKAGE_MAILING_LIST, "bug-ccd2cue@gnu.org", Users mailing list)
AC_DEFINE(PACKAGE_TRANSLATION_BUGREPORT,
"http://translationproject.org/team/", Translation bug reporting address)
AC_DEFINE(PACKAGE_COPYRIGHT_HOLDER, "Bruno Félix Rezende Ribeiro",
Copyright holder's name)

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

# Check for `sed'.
AC_PROG_SED

# Define GNU Texinfo minimal version.
m4_define(texinfo_minver, 5.1)

# Check for GNU Texinfo existence.
AC_PATH_PROG(MAKEINFO, makeinfo)
AS_IF(test x$MAKEINFO = x,
  AC_MSG_ERROR(
GNU Texinfo not found.  It is required at least version texinfo_minver.
You can find it at https://gnu.org/software/texinfo/.))

AS_VAR_SET(texinfo_version, `$MAKEINFO --version |
  $SED -n 's/^makeinfo.* \([[:digit:].]*\)$/\1/p'`)

# Check GNU Texinfo version.
AX_COMPARE_VERSION($texinfo_version, ge, texinfo_minver,
  AC_MSG_ERROR(
GNU Texinfo is too old.  It is required at least version texinfo_minver.
You can find it at https://gnu.org/software/texinfo/.))

# Check for GNU help2man existence.  It should only be used if not
# cross-compiling.
AS_IF(test $cross_compiling = no,
  [AM_MISSING_PROG(HELP2MAN, help2man)], HELP2MAN=:)

# Check for Doxygen existence and configure it;
DX_DOT_FEATURE(ON)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN(ccd2cue, '$(top_builddir)/doc/Doxyfile', '$(top_builddir)/doc/doxygen')

# Rerun configure script when the following files are modified.
AC_SUBST([CONFIG_STATUS_DEPENDENCIES],
['$(top_srcdir)/package.texi.in \
$(top_srcdir)/doc/copying.texi.in \
$(top_srcdir)/doc/Doxyfile.in'])

# Output files;
AC_CONFIG_FILES(
[Makefile
po/Makefile.in
src/Makefile
doc/Makefile
package.texi
doc/copying.texi
doc/Doxyfile
doc/man/Makefile])

AC_OUTPUT
