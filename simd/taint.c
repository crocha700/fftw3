/*
 * Copyright (c) 2003 Matteo Frigo
 * Copyright (c) 2003 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* $Id: taint.c,v 1.1 2003-04-05 00:30:37 athena Exp $ */

#include "ifftw.h"
#include "simd.h"

R *X(taint)(R *p, int s)
{
     if (((unsigned)s * sizeof(R)) % ALIGNMENT)
	  p = (R *) (PTRINT(p) | TAINT_BIT);
     if (((unsigned)s * sizeof(R)) % ALIGNMENTA)
	  p = (R *) (PTRINT(p) | TAINT_BITA);
     return p;
}
