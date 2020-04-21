#include "Application.h"

namespace Application
{
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
	HWND console = GetConsoleWindow();
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
}