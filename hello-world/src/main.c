/*
 * Main.
 */

#include <genesis.h>

void inputHandler(u16 joy, u16 changed, u16 state) {

	if (joy == JOY_1) {
		if (state & BUTTON_START) {
			//player 1 press START button
		} else if (changed & BUTTON_START) {
			//player 1 released START button
		}
	}
}

int main() {

	JOY_init();
	JOY_setEventHandler(&inputHandler);

	VDP_drawText("Hello Genny World!", 10, 13);

	while (1) {

		VDP_waitVSync();
	}

	return (0);
}
