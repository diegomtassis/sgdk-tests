/*
 * main.c
 *
 *  Created on: Mar 17, 2019
 *      Author: diegomtassis
 */

#include <vdp.h>

#include "../inc/moon.h"

int main() {

	drawMoon();

	while (1) {

		VDP_waitVSync();
	}

	return (0);
}
