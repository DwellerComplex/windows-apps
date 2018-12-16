#include <Windows.h>
#include <conio.h>
#include <Lmcons.h>
#include "application.h"
#include <fstream> 
using namespace std;

void Application::SetTitle(string const title)
{
	string str(title);
	SetConsoleTitle(str.c_str());
}

void Application::SetConsoleSize(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}

int Application::GetConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int width;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	return width;
}

void Application::SetConsoleScreenBuffer()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

int Application::GetConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int height;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	height = csbi.srWindow.Bottom - csbi.srWindow.Top;

	return height;
}

void Application::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Application::SetCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

std::vector<std::vector <char>> Application::ReadFileToVector2D(std::string fileName)
{
	std::vector<std::vector <char>> output;

	std::ifstream file(fileName);

	vector<char> temp;

	char c = ' ';

	while (file.get(c))
	{
		
		if (c == '\n' && temp.size() != 0)
		{
			output.push_back(temp);
			temp.clear();
		}
		else
		{
			temp.push_back(c);
		}
	}

	file.close();

	return output;
}

void Application::TransformVector2D(std::vector<std::vector <char>>& vector2D)
{
	vector<vector<char>> vector2DTrans(vector2D[0].size(), vector<char>(vector2D.size()));

	for (size_t i = 0; i < vector2D.size(); ++i)
	{
		for (size_t j = 0; j < vector2D[0].size(); ++j)
		{
			vector2DTrans[j][i] = vector2D[i][j];
		}
	}

	vector2D = vector2DTrans;
}

string Application::GetWindowsUserName()
{
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);

	return username;
}

//string Application::input()
//{
//	string cmd = ' ';
//
//	if (_kbhit())
//	{
//		cmd = _getch();
//	}
//
//	return cmd;
//}

short Application::input(int vKey)
{
	return GetAsyncKeyState(vKey);
}

void Application::SetTextColor(int const color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void Application::StartGlobalTimer()
{
	this->startTime = std::chrono::high_resolution_clock::now();
}

float Application::GetGlobalTimer()
{	
	auto currentTime = std::chrono::high_resolution_clock::now();

	return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - this->startTime).count() / 1000.0f;
}