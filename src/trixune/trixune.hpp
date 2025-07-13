#pragma once
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>

namespace trixune {
	extern sf::RenderWindow* window;
	extern sf::Clock* clock;

	extern sf::Time frameTime;
	extern float deltaTime;
	extern float imScaleMult;

	void SetupView();
	void Exit();
	void HandleResize(sf::Vector2u baseSize, bool scaleImGui = false, bool scaleDebugGui = true);
}
