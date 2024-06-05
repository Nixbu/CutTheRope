#include <SFML/Graphics.hpp>

// Disable MSVC analysis warnings for the box2d include
#pragma warning(push)
#pragma warning(disable: 26495 26813)
#include "box2d/box2d.h"
#include "Controller.h"

int main()
{
	Controller controller;
	controller.run();
}
