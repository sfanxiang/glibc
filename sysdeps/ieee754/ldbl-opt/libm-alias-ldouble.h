/* Define aliases for libm long double functions.  ldbl-opt version.
   Copyright (C) 2017 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _LIBM_ALIAS_LDOUBLE_H
#define _LIBM_ALIAS_LDOUBLE_H

#include <math_ldbl_opt.h>
#include <ldbl-compat-choose.h>

/* Define _FloatN / _FloatNx aliases for a long double libm function
   that has internal name FROM ## l ## R and public names TO ## suffix
   ## R for each suffix of a supported _FloatN / _FloatNx
   floating-point type with the same format as long double.  */
#define libm_alias_ldouble_other_r(from, to, r)

/* Likewise, but without the R suffix.  */
#define libm_alias_ldouble_other(from, to)	\
  libm_alias_ldouble_other_r (from, to, )

/* Define aliases for a long double libm function that has internal
   name FROM ## l ## R and public names TO ## suffix ## R for each
   suffix of a supported floating-point type with the same format as
   long double.  This should only be used for functions where such
   public names exist for _FloatN types, not for
   implementation-namespace exported names (where there is one name
   per format, not per type) or for obsolescent functions not provided
   for _FloatN types.  */
#define libm_alias_ldouble_r(from, to, r)			\
  LONG_DOUBLE_COMPAT_CHOOSE_libm_ ## to ## l ## r		\
    (long_double_symbol (libm, from ## l ## r, to ## l ## r),	\
     weak_alias (from ## l ## r, to ## l ## r));		\
  libm_alias_ldouble_other_r (from, to, r)

/* Likewise, but without the R suffix.  */
#define libm_alias_ldouble(from, to) libm_alias_ldouble_r (from, to, )

#endif
