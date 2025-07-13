#include <iostream>

#include <SFML/Graphics.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

namespace trixune {
	sf::RenderWindow* window;
	sf::Clock* clock;
	sf::View _gameView;

	sf::Time frameTime;
	float deltaTime;

	float imScaleMult;

	void SetupView()
	{
		_gameView.setSize(window->getDefaultView().getSize());
		_gameView.setCenter(_gameView.getSize()/2.f);
		window->setView(_gameView);

	}

	void Exit() {
		std::cout << "[TrixUne] Shutting Down ImGui..." << std::endl;
		ImGui::SFML::Shutdown();

		std::cout <<"[TrixUne] Cleaning Up..." << std::endl;
		// Cleanup of pointers
		delete window; window = nullptr;
		delete clock; clock = nullptr;


		std::cout <<"[TrixUne] Exiting..." << std::endl;
	}

	void HandleResize(const sf::Vector2u baseSize, bool scaleImGui = false, bool scaleDebugGui = true)
	{
		const sf::Vector2u size = window->getSize();
		sf::View view(sf::FloatRect({0.f, 0.f}, sf::Vector2<float>(baseSize)));
		window->setView(view);


		float scaleX = static_cast<float>(size.x) / static_cast<float>(baseSize.x); //Calculate Scale Difference
		float scaleY = static_cast<float>(size.y) / static_cast<float>(baseSize.y);

		float scale = std::min(scaleX, scaleY);
		if (scaleImGui)
		{
			//Sometimes ImGui shouldn't be scaled
			ImGui::GetIO().FontGlobalScale = scale; //Scale ImGui Accordingly
		}
		if (scaleDebugGui)
		{
			imScaleMult = scale;
		}
	}
}
