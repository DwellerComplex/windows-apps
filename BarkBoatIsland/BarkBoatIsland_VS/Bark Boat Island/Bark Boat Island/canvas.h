#pragma once
#include "application.h"

class Canvas
{
public:
	Canvas();
	Canvas(int const width, int const height, int const topLeftX, int const topLeftY, short const colorKey,
		std::vector<std::vector<char>> const charBuffer, 
		std::vector<std::vector<short>> const colorBuffer,
		std::vector<std::vector<short>> const collisionBuffer = {});
	Canvas(int const topLeftX, int const topLeftY, short const colorKey,
		std::vector<std::vector<char>> const charBuffer,
		std::vector<std::vector<short>> const colorBuffer,
		std::vector<std::vector<short>> const collisionBuffer = {});
	void Draw();
	void CombineWith(Canvas* canvas);
	void SetColorkey(short const color);
	void SetCharBuffer(std::vector<std::vector<char>> const buffer);
	void SetColorBuffer(std::vector<std::vector<short>> const buffer);
	void SetCollisionBuffer(std::vector<std::vector<short>> const buffer);
	void SetWidth(int const width);
	void SetHeight(int const height);
	void SetDrawThisTick(bool const dTT);
	void PutChar(char const character, int const x, int const y, short const color);
	void PutCollision(int const x, int const y, short const collision);
	void PutString(std::string const str, int const x, int const y, int const color, bool const autoFit, char const bgSprite = ' ', int const bgColor = 0);
	short const GetCollisionAt(int const x, int const y);
	short const GetColorKey();
	int const GetWidth();
	int const GetHeight();
	bool const GetDrawThisTick();
	void Resize();
	void Copy(Canvas* canvas);
	void SetBuffersToZero();
	void Erase();
private:
	int width;
	int height;
	int topLeftX;
	int topLeftY;
	short colorKey;
	bool drawThisTick;
	
	std::vector<std::vector<char>> frontCharBuffer;
	std::vector<std::vector<char>> backCharBuffer;
	std::vector<std::vector<short>> frontColorBuffer;
	std::vector<std::vector<short>> backColorBuffer;
	std::vector<std::vector<short>> frontCollisionBuffer;
	std::vector<std::vector<short>> backCollisionBuffer;
};