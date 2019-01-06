#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <chrono>

class Application
{
public:
	void SetTitle(std::string const title);
	int GetConsoleWidth();
	int GetConsoleHeight();
	void ShowConsoleCursor(bool);
	void SetCursorPosition(int, int);
	void SetConsoleSize(int w, int h);
	void SetConsoleScreenBuffer();
	void StartGlobalTimer();
	float GetGlobalTimer();
	void TransformVector2D(std::vector<std::vector <char>>& vector2D);
	std::vector<std::vector <char>> ReadFileToVector2D(std::string fileName);
	std::string GetWindowsUserName();
	//char input();
	short input(int vKey);
	void SetTextColor(int const color = 15);
	void SetFontSize(int w, int h);

	static Application& get_instance()
	{
		static Application instance;
		return instance;
	}

	Application(Application const&) = delete;

	Application(Application&&) = delete;

private:
	Application() { }
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};
