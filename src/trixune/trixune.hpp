#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

namespace trixune {
	extern sf::RenderWindow* window;
	extern sf::Clock* clock;

	extern sf::Time deltaClock;
	extern float deltaTime;
	void Exit();
}
