#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include "trixune/trixune.hpp"
#include "main.hpp"
#include "trixune/tools.hpp"

sf::Vector2u baseSize = {640, 360};

namespace TGame
{
#ifdef NDEBUG
	bool debugEnabled = false; // Only on Release Builds
#else
	bool debugEnabled = true; // Only on Debug Builds
#endif
}

void TGame::Update()
{
	while (const std::optional event = trixune::window->pollEvent()) {
		ImGui::SFML::ProcessEvent(*trixune::window, *event);

		if (event->is < sf::Event::Closed >()) {
			trixune::window->close();
		} else if(const auto *keyPress = event->getIf< sf::Event::KeyPressed >()) {
			if(keyPress->scancode == sf::Keyboard::Scancode::Escape) trixune::window->close(); // Exit Game
			else if (keyPress->scancode == sf::Keyboard::Scancode::Insert) trixune_tools::debugVisible ^= true; // Debug Toggle
		} else if (event->is < sf::Event::Resized >())
		{
			trixune::HandleResize(baseSize);
		}
	}
	trixune::frameTime = trixune::clock->restart();
	trixune::deltaTime = trixune::frameTime.asSeconds();
}

void TGame::Render()
{
	ImGui::SFML::Update(*trixune::window, trixune::frameTime);

	trixune_tools::ShowFPS();
	trixune_tools::ShowDebugWindow();

	trixune::window->clear();
	ImGui::SFML::Render(*trixune::window);
	trixune::window->display();
}

int main(int argc, char *argv[])
{

	trixune::window = new sf::RenderWindow(sf::VideoMode(baseSize), "TrixUne");

	trixune::window->setFramerateLimit(60);
	trixune::SetupView();


	if (!ImGui::SFML::Init(*trixune::window)){return 1;}

	trixune::clock = new sf::Clock();

	while (trixune::window->isOpen()) {
		TGame::Update();
		TGame::Render();
	}
	trixune::Exit();

	return 0;
}