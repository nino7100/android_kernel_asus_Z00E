/* IEEE754 floating point arithmetic
 * double precision: common utilities
 */
/*
 * MIPS floating point support
 * Copyright (C) 1994-2000 Algorithmics Ltd.
 *
 * ########################################################################
 *
 *  This program is free software; you can distribute it and/or modify it
 *  under the terms of the GNU General Public License (Version 2) as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
 *
 * ########################################################################
 */


#include "ieee754dp.h"

ieee754dp ieee754dp_logb(ieee754dp x)
{
	COMPXDP;

	CLEARCX;

	EXPLODEXDP;

	switch (xc) {
	case IEEE754_CLASS_SNAN:
		return ieee754dp_nanxcpt(x, "logb", x);
	case IEEE754_CLASS_QNAN:
		return x;
	case IEEE754_CLASS_INF:
		return ieee754dp_inf(0);
	case IEEE754_CLASS_ZERO:
		return ieee754dp_inf(1);
	case IEEE754_CLASS_DNORM:
		DPDNORMX;
		break;
	case IEEE754_CLASS_NORM:
		break;
	}
	return ieee754dp_fint(xe);
}
