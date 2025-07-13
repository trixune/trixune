#pragma once
namespace trixune_tools {
	extern bool debugVisible;
	void ShowFPS(bool debugVisibleOverride = true);
	void ShowDebug(int elements = 0, bool debugVisibleOverride = true);
	void ShowDebugWindow(int elements = 0);
}
