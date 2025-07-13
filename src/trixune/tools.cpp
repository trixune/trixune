#include <iostream>
#include <imgui.h>

#include <trixune/trixune.hpp>

namespace trixune_tools {
	bool debugVisible = false;

	void ShowFPS(bool debugVisibleOverride = true) {
		if (!debugVisibleOverride && !debugVisible) return;
		float fps = 0.0f; // FPS Calculation
		if(trixune::deltaTime > 0.0f)
			fps = 1.0f / trixune::deltaTime;

		char fpsText[64];
		sprintf(fpsText, "FPS: %.1f",
			fps);

		ImGui::GetForegroundDrawList()->AddText(
			nullptr, 16.0f*trixune::imScaleMult,
			ImVec2(10.0f, 10.0f),
			IM_COL32(255, 255, 0, 255),
			fpsText
		);
	}

	void ShowDebug(const int elements = 0) {
		if (!debugVisible) return;
		ShowFPS();

		char elementsText[64];
		sprintf(elementsText, "ELS: %.1d",
			elements);

		ImGui::GetForegroundDrawList()->AddText(
			nullptr, 16.0f*trixune::imScaleMult,
			ImVec2(10.0f, 10.0f),
			IM_COL32(255, 255, 0, 255),
			elementsText
		);
	}

	void ShowDebugWindow(const int elements = 0) {
		if (!debugVisible) return;
		ImGui::Begin("TrixUne Debug");

		float fps = 0.0f; // FPS Calculation
		if(trixune::deltaTime > 0.0f)
			fps = 1.0f / trixune::deltaTime;

		ImGui::Text("FPS: %.1f", fps);
		ImGui::Text("ELS: %.1d", elements);
		ImGui::End();
	}
}
