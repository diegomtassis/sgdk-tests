/*
 * text-handling.c
 *
 *  Created on: Mar 20, 2019
 *      Author: diegomtassis
 */

#include <text-handling.h>

#include <string.h>
#include <types.h>
#include <vdp_bg.h>

void appendAndDrawText(const char *text, u16 *xOffset, u16 *yOffset) {

	VDP_drawText(text, *xOffset, *yOffset);
	*xOffset += strlen(text);
}
