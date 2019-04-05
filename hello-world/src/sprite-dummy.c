/*
 * sprite-dummy.c
 *
 *  Created on: Apr 5, 2019
 *      Author: diegomtassis
 */

#include <types.h>
#include <vdp_bg.h>
#include <vdp_spr.h>
#include <vdp_tile.h>

#define	TILE_1	1

const u32 spriteTiles[4 * 8] = { //
		0x00001111, // Tile Top Left
				0x00001111, //
				0x00001111, //
				0x00001111, //
				0x00001111, //
				0x00001111, //
				0x00001111, //
				0x00001111, //
				0x11112222, // Tile Bottom Left
				0x11112222, //
				0x11112222, //
				0x11112222, //
				0x11112222, //
				0x11112222, //
				0x11112222, //
				0x11112222, //
				0x11110000, // Tile Top Right
				0x11110000, //
				0x11110000, //
				0x11110000, //
				0x11110000, //
				0x11110000, //
				0x11110000, //
				0x11110000, //
				0x22221111, //Tile Bottom Right
				0x22221111, //
				0x22221111, //
				0x22221111, //
				0x22221111, //
				0x22221111, //
				0x22221111, //
				0x22221111 //
		};

void printHeader_DummySprite();

void drawSprite() {

	printHeader_DummySprite();

	// load the tiles on VRAM
	VDP_loadTileData((const u32 *) spriteTiles, TILE_1, 4, 0);

	VDP_clearSprites();
	VDP_allocateSprites(4);
	VDP_setSprite(0, 0, 50, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL0, 1, 0, 0, TILE_1));
	VDP_setSprite(1, 64, 100, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL1, 1, 0, 0, TILE_1));
	VDP_setSprite(2, 128, 150, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL2, 1, 0, 0, TILE_1));
	VDP_setSprite(3, 192, 200, SPRITE_SIZE(2, 2), TILE_ATTR_FULL(PAL3, 1, 0, 0, TILE_1));

	// ask for draw
	// VDP_refreshHighestAllocatedSpriteIndex();
	VDP_updateSprites(highestVDPSpriteIndex + 1, 0);
}

void printHeader_DummySprite() {

	VDP_setTextPriority(1);

	// header
	VDP_drawText("SGDK tutorial", 1, 1);
	VDP_drawText("Dummy sprites", 1, 2);
}
