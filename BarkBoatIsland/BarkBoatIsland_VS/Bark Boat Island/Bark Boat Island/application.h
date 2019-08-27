#ifndef __APPLICATION_H_INCLUDED__
#define __APPLICATION_H_INCLUDED__
#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <Windows.h>
#include <conio.h>
#include <Lmcons.h>
#include <algorithm>
#include <unordered_map>
#include <string>

namespace Application
{
	void SetTitle(std::string const title);
	int GetConsoleWidth();
	int GetConsoleHeight();
	const char ReadCharacterFromConsole();
	void SetConsoleInputModeFalse();
	std::unordered_map<char, int> GetCursorPosition();
	void ShowConsoleCursor(bool);
	void SetCursorPosition(int, int);
	void SetConsoleSize(int w, int h);
	void SetConsoleScreenBuffer();
	void StartGlobalTimer();
	float GetGlobalTimer();
	std::unordered_map<char, int> GetFontSize();
	void TransformVector2D(std::vector<std::vector <char>>& vector2D);
	void TransformVector2D(std::vector<std::vector <short>>& vector2D);
	std::vector<std::vector <char>> ReadFileChar(std::string const fileName);
	std::vector<std::vector <short>> ReadFileShort(std::string const fileName);
	const std::vector<int> ExtractSameInts(const std::vector<std::vector<int>>& v);
	const std::vector<int> ExtractSameInts(const std::vector<int>& a, const std::vector<int>& b);
	std::string GetWindowsUserName();
	short InputAsync(int vKey);
	short Input(int vKey);
	void SetTextColor(int const color = 15);
	void SetFontSize(int w, int h);
	void SetFontEncoding(int code);

	extern std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
	extern HWND console;
	extern HANDLE out;
	extern HANDLE in;
};
#endif