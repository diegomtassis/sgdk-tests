/*
 * input-handling.c
 *
 *  Created on: Mar 19, 2019
 *      Author: diegomtassis
 */

#include <genesis.h>

void logButtonStatus(const char *str, const char *isPushed, u16 x, u16 y);

void inputHandler(u16 joy, u16 changed, u16 state) {

	logInputButton(joy, BUTTON_START, changed, state, "S", 5, 12);

	logInputButton(joy, BUTTON_A, changed, state, "A", 5, 14);
	logInputButton(joy, BUTTON_B, changed, state, "B", 5, 15);
	logInputButton(joy, BUTTON_C, changed, state, "C", 5, 16);

	logInputButton(joy, BUTTON_X, changed, state, "X", 5, 18);
	logInputButton(joy, BUTTON_Y, changed, state, "Y", 5, 19);
	logInputButton(joy, BUTTON_Z, changed, state, "Z", 5, 20);

	logInputButton(joy, BUTTON_UP, changed, state, "U", 5, 22);
	logInputButton(joy, BUTTON_DOWN, changed, state, "D", 5, 23);
	logInputButton(joy, BUTTON_LEFT, changed, state, "L", 5, 24);
	logInputButton(joy, BUTTON_RIGHT, changed, state, "R", 5, 25);
}

void logInputButton(u16 joy, u16 button, u16 changed, u16 state, const char *str, u16 x, u16 y) {

	if (joy == JOY_1) {

		if (state & button) {
			logButtonStatus(str, "1", x, y);

		} else if (changed & button) {
			logButtonStatus(str, "0", x, y);
		}
	}
}

void logButtonStatus(const char *str, const char *isPushed, u16 x, u16 y) {

	char buf[strlen(str) + 3];
	strcat(strcat(buf, str), isPushed);
	VDP_drawText(buf, x, y);
}
