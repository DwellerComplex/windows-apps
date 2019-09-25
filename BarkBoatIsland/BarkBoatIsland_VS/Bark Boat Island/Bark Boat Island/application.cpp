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

	short ReadColorFromConsole()
	{
		WORD color;
		
		std::unordered_map<char, int> pos = GetCursorPosition();
		COORD posC = { (short)pos['x'], (short)pos['y'] };

		DWORD numberOfCharactersReaded = 0;
		DWORD numberOfCharactersToRead = 1;
		ReadConsoleOutputAttribute(out, &color, numberOfCharactersToRead, posC, &numberOfCharactersReaded);

		return (short)color;
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

	std::vector<std::vector <char>> ReadFileChar(std::string const fileName)
	{
		std::vector<std::vector <char>> output;

		std::ifstream file(fileName);

		std::vector<char> temp;

		char c = ' ';

		while (file.get(c))
		{

			if (c == '\n' && temp.size() != 0)
			{
				output.emplace_back(temp);
				temp.clear();
			}
			else
			{
				temp.emplace_back(c);
			}
		}

		file.close();

		return output;
	}

	std::vector<std::vector <short>> ReadFileShort(std::string const fileName)
	{
		std::vector<std::vector <short>> output;

		std::ifstream file(fileName);

		std::vector<short> temp;

		char c = ' ';

		while (file.get(c))
		{

			if (c == '\n' && temp.size() != 0)
			{
				output.emplace_back(temp);
				temp.clear();
			}
			else
			{
				temp.emplace_back((SHORT)c);
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

	void TransformVector2D(std::vector<std::vector <short>>& vector2D)
	{
		std::vector<std::vector<short>> vector2DTrans(vector2D[0].size(), std::vector<short>(vector2D.size()));

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

		out.reserve(a.size());

		for (std::vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
		{
			if (std::find(b.begin(), b.end(), *i) != b.end())
			{
				out.emplace_back(*i);
			}
		}
		return ((a.size() && b.size()) ? (out) : (std::vector<int>()));
	}

	const std::vector<int> ExtractSameInts(const std::vector<std::vector<int>>& v)
	{
		std::vector<int> out;

		out.reserve(v.size());

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

	short InputAsync(int vKey)
	{
		return GetAsyncKeyState(vKey);
	}

	short Input(int vKey)
	{
		return GetKeyState(vKey);
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
		//auto currentTime = std::chrono::high_resolution_clock::now();

		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startTime).count() / 1000.0f;
	}

	std::unordered_map<char, int> Application::GetFontSize()
	{
		std::unordered_map<char, int> size;
		CONSOLE_FONT_INFOEX lpConsoleCurrentFontEx;
		lpConsoleCurrentFontEx.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(out, 0, &lpConsoleCurrentFontEx);

		size.insert(std::pair<char, int>('w', lpConsoleCurrentFontEx.dwFontSize.X));
		size.insert(std::pair<char, int>('h', lpConsoleCurrentFontEx.dwFontSize.Y));

		return size;
	}

	void SetFontSize(int w, int h)
	{
		CONSOLE_FONT_INFOEX lpConsoleCurrentFontEx;
		lpConsoleCurrentFontEx.cbSize = sizeof(lpConsoleCurrentFontEx);
		lpConsoleCurrentFontEx.nFont = 0;
		lpConsoleCurrentFontEx.dwFontSize.X = w;                   // Width of each character in the font
		lpConsoleCurrentFontEx.dwFontSize.Y = h;                  // Height
		lpConsoleCurrentFontEx.FontFamily = FF_DONTCARE;
		lpConsoleCurrentFontEx.FontWeight = FW_NORMAL;
		wcscpy_s(lpConsoleCurrentFontEx.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &lpConsoleCurrentFontEx);
	}

	void SetFontEncoding(int code)
	{
		SetConsoleCP(code);
		SetConsoleOutputCP(code);
	}
}