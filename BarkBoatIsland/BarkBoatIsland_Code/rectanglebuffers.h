#pragma once
#include "application.h"

class RectangleBuffers
{
public:
	RectangleBuffers(
		int const w,
		int const h);

	RectangleBuffers(
		char const floor,
		char const wallX,
		char const wallY,
		char const wall00,
		char const wallX0,
		char const wallXY,
		char const wall0Y,
		int const w,
		int const h,
		short const floorColor,
		short const wallColor);

	void BuildRectangle(
		char const floor, 
		char const wallX, 
		char const wallY,
		char const wall00, 
		char const wallX0, 
		char const wallXY, 
		char const wall0Y, 
		int const w, 
		int const h, 
		short const floorColor, 
		short const wallColor);

	std::vector<std::vector<char>>* LoadCharBufferFile(std::string const fileName);
	std::vector<std::vector<short>>* LoadColorBufferFile(std::string const fileName);
	std::vector<std::vector<short>>* LoadCollisionBufferFile(std::string const fileName);
	std::vector<std::vector<char>>* GetCharBuffer();
	std::vector<std::vector<short>>* GetColorBuffer();
	std::vector<std::vector<short>>* GetCollisionBuffer();
	void Resize();
private:
	std::vector<std::vector<char>> charBuffer;
	std::vector<std::vector<short>> colorBuffer;
	std::vector<std::vector<short>> collisionBuffer;

	int width, height;
};