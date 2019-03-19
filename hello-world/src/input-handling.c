/*
 * input-handling.c
 *
 *  Created on: Mar 19, 2019
 *      Author: diegomtassis
 */

#include <genesis.h>

void inputHandler(u16 joy, u16 changed, u16 state) {

	logInputButton(joy, BUTTON_START, changed, state, "START", 5, 12);

	logInputButton(joy, BUTTON_A, changed, state, "A", 5, 14);
	logInputButton(joy, BUTTON_B, changed, state, "B", 5, 15);
	logInputButton(joy, BUTTON_C, changed, state, "C", 5, 16);

	logInputButton(joy, BUTTON_X, changed, state, "X", 5, 18);
	logInputButton(joy, BUTTON_Y, changed, state, "Y", 5, 19);
	logInputButton(joy, BUTTON_Z, changed, state, "Z", 5, 20);

	logInputButton(joy, BUTTON_UP, changed, state, "UP", 5, 22);
	logInputButton(joy, BUTTON_DOWN, changed, state, "DOWN", 5, 23);
	logInputButton(joy, BUTTON_LEFT, changed, state, "LEFT", 5, 24);
	logInputButton(joy, BUTTON_RIGHT, changed, state, "RIGHT", 5, 25);
}

void logInputButton(u16 joy, u16 button, u16 changed, u16 state, const char *str, u16 x, u16 y) {

	char buf[strlen(str) + 10];

	if (joy == JOY_1) {
		if (state & button) {
			strcat(strcat(buf, str), " button: 1");

		} else if (changed & button) {
			strcat(strcat(buf, str), " button: 0");
		}
		VDP_drawText(buf, x, y);
	}
}
