#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

namespace trixune {
	sf::RenderWindow* window;
	sf::Clock* clock;

	sf::Time deltaClock;
	float deltaTime;
	void Exit() {
		std::cout << "[TrixUne] Shutting Down ImGui..." << std::endl;
		ImGui::SFML::Shutdown();
		std::cout <<"[TrixUne] Exitting..." << std::endl;
	}
}
