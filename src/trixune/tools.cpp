#include <iostream>
#include <imgui.h>

#include <trixune/trixune.hpp>

namespace trixune_tools {
	void ShowFPS() {
		float fps = 0.0f;
		if(trixune::deltaTime > 0.0f)
			fps = 1.0f / trixune::deltaTime;
		char fpsText[64];
		sprintf(fpsText, "FPS: %.1f",
			fps);
		ImGui::GetBackgroundDrawList()->AddText(
			nullptr, 16.0f,
			ImVec2(10.0f, 10.0f),
			IM_COL32(255, 255, 0, 255),
			fpsText
		);
	}

	void ShowDebug() {
		ShowFPS();
	}

	void ShowDebugWindow() {
		ImGui::Begin("TrixUne Debug");
		float fps = 0.0f;
		if(trixune::deltaTime > 0.0f)
			fps = 1.0f / trixune::deltaTime;
		ImGui::Text("FPS %.1f", fps);
		ImGui::End();
	}
}
