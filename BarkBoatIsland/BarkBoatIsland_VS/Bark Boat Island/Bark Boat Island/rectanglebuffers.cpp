#include "rectanglebuffers.h"

RectangleBuffers::RectangleBuffers(char const floor, char const wallX, char const wallY, char const wall00, char const wallX0, char const wallXY, char const wall0Y, int const width, int const height, short const floorColor, short const wallColor)
{
	//Resize
	charBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		charBuffer[i].resize(height);
	}

	colorBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		colorBuffer[i].resize(height);
	}

	//Fill buffers 
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (x == 0 || x == width - 1)
			{
				charBuffer[x][y] = wallY;
				colorBuffer[x][y] = wallColor;
			}
			else
			{
				if (y == 0 || y == height - 1)
				{
					charBuffer[x][y] = wallX;
					colorBuffer[x][y] = wallColor;
				}
				else
				{
					charBuffer[x][y] = floor;
					colorBuffer[x][y] = floorColor;
				}
			}
			if (x == 0 && y == 0)
			{
				charBuffer[x][y] = wall00;
			}
			else if (x == width - 1 && y == 0)
			{
				charBuffer[x][y] = wallX0;
			}
			else if (x == width - 1 && y == height - 1)
			{
				charBuffer[x][y] = wallXY;
			}
			else if (x == 0 && y == height - 1)
			{
				charBuffer[x][y] = wall0Y;
			}
		}
	}
}

std::vector<std::vector<char>>* RectangleBuffers::GetCharBuffer()
{
	return &charBuffer;
}

std::vector<std::vector<short>>* RectangleBuffers::GetColorBuffer()
{
	return &colorBuffer;
}
