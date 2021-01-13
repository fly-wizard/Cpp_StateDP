#include <iostream>

#include "door.h"

int main() {
	std::cout << "The door" << std::endl;

	Door door;

	door.TurnKey();
	door.PushPull();
	door.TurnKey();
	door.PushPull();
	door.TurnKey();
	door.PushPull();

	return 0;
}