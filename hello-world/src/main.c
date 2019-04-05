/*
 * main.c
 *
 *  Created on: Mar 17, 2019
 *      Author: diegomtassis
 */

#include <genesis.h>

#include "../inc/moon.h"

int main() {

	// drawMoon();

	// BG_drawDummyTile();

	drawSprite();

	while (1) {

		VDP_waitVSync();
	}

	return (0);
}
