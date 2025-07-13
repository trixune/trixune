#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include "trixune/trixune.hpp"
#include "trixune/tools.hpp"

int main(int argc, char *argv[])
{
    sf::RenderWindow window(
	sf::VideoMode({1280, 720}), "TrixUne");
    trixune::window = &window;

    window.setFramerateLimit(60);

    bool imgui_init = ImGui::SFML::Init(window);
    if(!imgui_init) { return 1; }
    sf::Clock deltaClock;
    trixune::clock = &deltaClock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if (event->is < sf::Event::Closed >()) {
                window.close();
            } else if(const auto *keyPress = event->getIf< sf::Event::KeyPressed >()) {
                if(keyPress->scancode == sf::Keyboard::Scancode::Escape) window.close();
            }
        }
	trixune::deltaClock = deltaClock.restart();
	trixune::deltaTime = trixune::deltaClock.asSeconds();
	ImGui::SFML::Update(window, trixune::deltaClock);

        ImGui::ShowDemoWindow();

	trixune_tools::ShowFPS();
	trixune_tools::ShowDebugWindow();
        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }
    trixune::Exit();

    return 0;
}
