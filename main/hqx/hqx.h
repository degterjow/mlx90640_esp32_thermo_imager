/*
 * Copyright (C) 2003 Maxim Stepin ( maxst@hiend3d.com )
 *
 * Copyright (C) 2010 Cameron Zemek ( grom@zeminvaders.net)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef __HQX_H_
#define __HQX_H_

#include <stdint.h>

void hq2x_32(int16_t * src, int16_t * dest, int width, int height );
void hq3x_32(int16_t * src, int16_t * dest, int width, int height );
void hq4x_32(int16_t * src, int16_t * dest, int width, int height );

void hq2x_32_rb(int16_t * src, uint32_t src_rowBytes, int16_t * dest, uint32_t dest_rowBytes, int width, int height );
void hq3x_32_rb(int16_t * src, uint32_t src_rowBytes, int16_t * dest, uint32_t dest_rowBytes, int width, int height );
void hq4x_32_rb(int16_t * src, uint32_t src_rowBytes, int16_t * dest, uint32_t dest_rowBytes, int width, int height );


void hqx_scale(uint8_t scaleBy, uint16_t width, uint16_t height, int16_t *pInput, int16_t *pOutput);

#endif
