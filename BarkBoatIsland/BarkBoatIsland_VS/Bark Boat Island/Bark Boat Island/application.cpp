#include "Application.h"
#include <fstream> 

namespace Application
{
	void SetTitle(std::string const title)
	{
		std::string str(title);
		SetConsoleTitle(str.c_str());
	}

	void SetConsoleSize(int w, int h)
	{
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions

		MoveWindow(console, r.left, r.top, w, h, TRUE);
	}

	int GetConsoleWidth()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int width;

		GetConsoleScreenBufferInfo(out, &csbi);
		width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

		return width;
	}

	void SetConsoleScreenBuffer()
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(out, &info);
		COORD new_size =
		{
			info.srWindow.Right - info.srWindow.Left + 1,
			info.srWindow.Bottom - info.srWindow.Top + 1
		};
		SetConsoleScreenBufferSize(out, new_size);
	}

	int GetConsoleHeight()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int height;

		GetConsoleScreenBufferInfo(out, &csbi);
		height = csbi.srWindow.Bottom - csbi.srWindow.Top;

		return height;
	}

	const char ReadCharacterFromConsole()
	{
		char charToRead;

		std::unordered_map<char, int> pos = GetCursorPosition();
		COORD posC = { (short)pos['x'], (short)pos['y'] };

		DWORD numberOfCharactersReaded = 0;
		DWORD numberOfCharactersToRead = 1;
		ReadConsoleOutputCharacter(out, &charToRead, numberOfCharactersToRead, posC, &numberOfCharactersReaded);

		return charToRead;
	}

	void SetConsoleInputModeFalse()
	{
		DWORD prev_mode;
		GetConsoleMode(in, &prev_mode);
		SetConsoleMode(in, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
	}

	std::unordered_map<char, int> GetCursorPosition()
	{
		//Convert to console coords
		POINT po;
		GetCursorPos(&po);

		ScreenToClient(console, &po);

		std::unordered_map<char, int> fontS = GetFontSize();
		SetCursorPosition(po.x / fontS['w'], po.y / fontS['h']);

		//Get Position
		std::unordered_map<char, int> position;

		CONSOLE_SCREEN_BUFFER_INFO cbsi;
		if (GetConsoleScreenBufferInfo(out, &cbsi))
		{
			position.insert(std::pair<char, int>('x', cbsi.dwCursorPosition.X));
			position.insert(std::pair<char, int>('y', cbsi.dwCursorPosition.Y));
		}
		else
		{
			position.insert(std::pair<char, int>('x', 0));
			position.insert(std::pair<char, int>('y', 0));
		}
		return position;
	}

	void ShowConsoleCursor(bool showFlag)
	{
		CONSOLE_CURSOR_INFO cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag;
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	void SetCursorPosition(int x, int y)
	{
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(out, coord);
	}

	std::vector<std::vector <char>> ReadFileToVector2D(std::string fileName)
	{
		std::vector<std::vector <char>> output;

		std::ifstream file(fileName);

		std::vector<char> temp;

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

	void TransformVector2D(std::vector<std::vector <char>>& vector2D)
	{
		std::vector<std::vector<char>> vector2DTrans(vector2D[0].size(), std::vector<char>(vector2D.size()));

		for (size_t i = 0; i < vector2D.size(); ++i)
		{
			for (size_t j = 0; j < vector2D[0].size(); ++j)
			{
				vector2DTrans[j][i] = vector2D[i][j];
			}
		}

		vector2D = vector2DTrans;
	}

	const std::vector<int> ExtractSameInts(const std::vector<int>& a, const std::vector<int>& b)
	{
		std::vector<int> out;
		for (std::vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
		{
			if (std::find(b.begin(), b.end(), *i) != b.end())
			{
				out.push_back(*i);
			}
		}
		return ((a.size() && b.size()) ? (out) : (std::vector<int>()));
	}

	const std::vector<int> ExtractSameInts(const std::vector<std::vector<int>>& v)
	{
		std::vector<int> out;

		if (v.size() != 1)
		{
			out = ExtractSameInts(v[0], v[1]);
		}

		for (int x = 2; x < v.size(); x++)
		{
			out = ExtractSameInts(out, v[x]);
		}

		return out;
	}

	std::string GetWindowsUserName()
	{
		char username[UNLEN + 1];
		DWORD username_len = UNLEN + 1;
		GetUserName(username, &username_len);

		return username;
	}

	short Input(int vKey)
	{
		return GetAsyncKeyState(vKey);
	}

	void SetTextColor(int const color)
	{
		SetConsoleTextAttribute(out, color);
	}

	void StartGlobalTimer()
	{
		startTime = std::chrono::high_resolution_clock::now();
	}

	float GetGlobalTimer()
	{
		auto currentTime = std::chrono::high_resolution_clock::now();

		return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0f;
	}

	std::unordered_map<char, int> GetFontSize()
	{
		std::unordered_map<char, int> size;
		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);

		size.insert(std::pair<char, int>('w', lpConsoleCurrentFontEx->dwFontSize.X));
		size.insert(std::pair<char, int>('h', lpConsoleCurrentFontEx->dwFontSize.Y));

		return size;
	}

	void SetFontSize(int w, int h)
	{
		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
		lpConsoleCurrentFontEx->dwFontSize.X = w;
		lpConsoleCurrentFontEx->dwFontSize.Y = h;
		lpConsoleCurrentFontEx->FontFamily = FF_DONTCARE;
		lpConsoleCurrentFontEx->FontWeight = FW_NORMAL;
		wcscpy_s(lpConsoleCurrentFontEx->FaceName, L"Consolas");
		SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	}
}
//#include <Windows.h>
//#include <conio.h>
//#include <Lmcons.h>
//#include "application.h"
//#include <fstream> 
//using namespace std;
//
//void Application::SetTitle(string const title)
//{
//	string str(title);
//	SetConsoleTitle(str.c_str());
//}
//
//void Application::SetConsoleSize(int w, int h)
//{
//	HWND console = GetConsoleWindow();
//	RECT r;
//	GetWindowRect(console, &r); //stores the console's current dimensions
//
//	MoveWindow(console, r.left, r.top, w, h, TRUE);
//}
//
//int Application::GetConsoleWidth()
//{
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	int width;
//
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//
//	return width;
//}
//
//void Application::SetConsoleScreenBuffer()
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO info;
//	GetConsoleScreenBufferInfo(handle, &info);
//	COORD new_size =
//	{
//		info.srWindow.Right - info.srWindow.Left + 1,
//		info.srWindow.Bottom - info.srWindow.Top + 1
//	};
//	SetConsoleScreenBufferSize(handle, new_size);
//}
//
//int Application::GetConsoleHeight()
//{
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	int height;
//
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
//	height = csbi.srWindow.Bottom - csbi.srWindow.Top;
//
//	return height;
//}
//
//void Application::ShowConsoleCursor(bool showFlag)
//{
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	CONSOLE_CURSOR_INFO     cursorInfo;
//
//	GetConsoleCursorInfo(out, &cursorInfo);
//	cursorInfo.bVisible = showFlag;
//	SetConsoleCursorInfo(out, &cursorInfo);
//}
//
//void Application::SetCursorPosition(int x, int y)
//{
//	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	cout.flush();
//	COORD coord = { (SHORT)x, (SHORT)y };
//	SetConsoleCursorPosition(hOut, coord);
//}
//
//std::vector<std::vector <char>> Application::ReadFileToVector2D(std::string fileName)
//{
//	std::vector<std::vector <char>> output;
//
//	std::ifstream file(fileName);
//
//	vector<char> temp;
//
//	char c = ' ';
//
//	while (file.get(c))
//	{
//		
//		if (c == '\n' && temp.size() != 0)
//		{
//			output.push_back(temp);
//			temp.clear();
//		}
//		else
//		{
//			temp.push_back(c);
//		}
//	}
//
//	file.close();
//
//	return output;
//}
//
//void Application::TransformVector2D(std::vector<std::vector <char>>& vector2D)
//{
//	vector<vector<char>> vector2DTrans(vector2D[0].size(), vector<char>(vector2D.size()));
//
//	for (size_t i = 0; i < vector2D.size(); ++i)
//	{
//		for (size_t j = 0; j < vector2D[0].size(); ++j)
//		{
//			vector2DTrans[j][i] = vector2D[i][j];
//		}
//	}
//
//	vector2D = vector2DTrans;
//}
//
//string Application::GetWindowsUserName()
//{
//	char username[UNLEN + 1];
//	DWORD username_len = UNLEN + 1;
//	GetUserName(username, &username_len);
//
//	return username;
//}
//
////string Application::input()
////{
////	string cmd = ' ';
////
////	if (_kbhit())
////	{
////		cmd = _getch();
////	}
////
////	return cmd;
////}
//
//short Application::input(int vKey)
//{
//	return GetAsyncKeyState(vKey);
//}
//
//void Application::SetTextColor(int const color)
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, color);
//}
//
//void Application::StartGlobalTimer()
//{
//	this->startTime = std::chrono::high_resolution_clock::now();
//}
//
//float Application::GetGlobalTimer()
//{	
//	auto currentTime = std::chrono::high_resolution_clock::now();
//
//	return std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - this->startTime).count() / 1000.0f;
//}
//
//void Application::SetFontSize(int w, int h)
//{
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
//	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
//	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
//	lpConsoleCurrentFontEx->dwFontSize.X = w;
//	lpConsoleCurrentFontEx->dwFontSize.Y = h;
//	lpConsoleCurrentFontEx->FontFamily = FF_DONTCARE;
//	lpConsoleCurrentFontEx->FontWeight = FW_NORMAL;
//	wcscpy_s(lpConsoleCurrentFontEx->FaceName, L"Consolas");
//	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
//}