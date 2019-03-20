/*
 * Main.
 */

#include <genesis.h>

#include "../inc/input-handling.h"
#include "../res/resources.h"

#define TILE1	1

int main() {

	JOY_init();
	JOY_setEventHandler(&inputHandler);

	VDP_drawText("Hello Genny World!", 10, 5);

	// Moon
	VDP_setPalette(PAL1, moon.palette->data);
	VDP_drawImageEx(PLAN_A, &moon, TILE_ATTR_FULL(PAL1, 0, 0, 0, 1), 12, 12, 0, CPU);


	// Platform
	VDP_loadTileData(platform.tiles, 1, 3, 0);

	int minX = 5;
	int maxX = 30;
	int y = 25;

	VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL2, 1, 0, 0, 1), minX, y);
	for (int var = 1; var < maxX; ++var) {
		VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL2, 1, 0, 0, 2), minX + var, y);
	}
	VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL2, 1, 0, 0, 3), minX + maxX, y);

	while (1) {

		VDP_waitVSync();
	}

	return (0);
}
