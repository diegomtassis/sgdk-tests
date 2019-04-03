/*
 * Main.
 */

#include <dma.h>
#include <string.h>
#include <types.h>
#include <vdp.h>
#include <vdp_bg.h>
#include <vdp_pal.h>
#include <vdp_tile.h>

#include "../inc/text-handling.h"
#include "../res/resources.h"

#define TILE1	1

int main() {

	VDP_setTextPlan(PLAN_A);
	VDP_setTextPriority(1);

	VDP_drawText("SGDK tutorial", 1, 1);
	VDP_drawText("BG image", 1, 2);

	u16 xPos = 1, yPos = 3;
	appendAndDrawText("Moon in different positions", &xPos, &yPos);

	xPos = 1, yPos = 1 + yPos;
	appendAndDrawText("Moon size: (", &xPos, &yPos);

	char w[2];
	sprintf(w, "%d", moon.map->w);

	char h[2];
	sprintf(h, "%d", moon.map->h);

	appendAndDrawText(w, &xPos, &yPos);
	appendAndDrawText("x", &xPos, &yPos);
	appendAndDrawText(h, &xPos, &yPos);
	appendAndDrawText(")", &xPos, &yPos);

	// Moon
	VDP_setPalette(PAL0, moon.palette->data);
	VDP_drawImageEx(PLAN_A, &moon, TILE_ATTR_FULL(PAL0, 0, 0, 0, 1), 1, 10, 0, CPU);
	VDP_drawImageEx(PLAN_A, &moon, TILE_ATTR_FULL(PAL1, 0, 1, 0, 1), 10, 10, 0, CPU);
	VDP_drawImageEx(PLAN_A, &moon, TILE_ATTR_FULL(PAL2, 0, 0, 1, 1), 19, 10, 0, CPU);
	VDP_drawImageEx(PLAN_A, &moon, TILE_ATTR_FULL(PAL3, 0, 1, 1, 1), 28, 10, 0, CPU);

	while (1) {

		VDP_waitVSync();
	}

	return (0);
}
