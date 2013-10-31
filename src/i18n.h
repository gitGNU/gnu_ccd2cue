/* i18n.h -- Internationalization support

   Copyright 2013 Bruno Félix Rezende Ribeiro (oitofelix)
   <oitofelix@gmail.com>

   This file is part of ccd2cue.

   ccd2cue is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ccd2cue is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */


#ifndef CCD2CUE_I18N_H
#define CCD2CUE_I18N_H

#include "libintl.h"


#define __(str) (str)
#define _(str) gettext (str)

#endif	/* CCD2CUE_I18N_H */