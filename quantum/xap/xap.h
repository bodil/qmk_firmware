/* Copyright 2021 Nick Brassel (@tzarc)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  xap_identifier_t;
typedef uint8_t  xap_response_flags_t;
typedef uint16_t xap_token_t;

#define XAP_RESPONSE_FLAG_FAILED 0
#define XAP_RESPONSE_FLAG_SUCCESS (1 << 0)

void xap_respond_failure(xap_token_t token, xap_response_flags_t response_flags);

void xap_send(xap_token_t token, xap_response_flags_t response_flags, const void *data, size_t length);

#include <xap_generated.h>
