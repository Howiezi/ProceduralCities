#pragma once
#include <iostream>

#include "window.h"
#include "application.h"

const char* title = "ProceduralCities";

int main() {

	Window window(title);

	Application app(window);

	app.runLoop();

	return 0;
}