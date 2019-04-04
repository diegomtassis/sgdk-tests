/*
 * bg_dummy_tile.c
 *
 *  Created on: Apr 4, 2019
 *      Author: diegomtassis
 */

#include "../inc/bg_dummy_tile.h"

#include <types.h>
#include <vdp.h>
#include <vdp_bg.h>
#include <vdp_tile.h>

#define	TILE1	1

const u32 tile[8] = { 0x00111100, //
		0x01144110,  //
		0x11244211,  //
		0x11244211,  //
		0x11222211,  //
		0x11222211,  //
		0x01122110,  //
		0x00111100 };

void printHeader_DummyTile();

void BG_drawDummyTile() {

	printHeader_DummyTile();

	VDP_loadTileData((const u32 *) tile, 1, 1, 0);

	VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL0, 0, 0, 0, TILE1), 5, 5);

	VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL1, 0, 0, 0, TILE1), 6, 5);

	VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL2, 1, 0, 0, TILE1), 7, 7);
	VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL3, 0, 0, 0, TILE1), 8, 7);

	// fill a 5x5 square of grey tile at (12,12)
	VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL0, 0, 0, 0, TILE1), 12, 12, 5, 5);
}

void printHeader_DummyTile() {

	VDP_setTextPriority(1);

	// header
	VDP_drawText("SGDK tutorial", 1, 1);
	VDP_drawText("BG tiles", 1, 2);
}
