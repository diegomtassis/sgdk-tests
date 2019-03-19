/*
 * Main.
 */

#include <genesis.h>
#include <input-handling.h>

int main() {

	JOY_init();
	JOY_setEventHandler(&inputHandler);

	VDP_drawText("Hello Genny World!", 10, 5);

	while (1) {

		VDP_waitVSync();
	}

	return (0);
}
