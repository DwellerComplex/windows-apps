#include "rectanglebuffers.h"
#include "globalenums.h"

RectangleBuffers::RectangleBuffers(int const w, int const h)
{
	this->width = w;
	this->height = h;
}

RectangleBuffers::RectangleBuffers(char const floor, char const wallX, char const wallY, char const wall00, char const wallX0, char const wallXY, char const wall0Y, int const w, int const h, short const floorColor, short const wallColor)
{
	this->width = w;
	this->height = h;

	BuildRectangle(floor, wallX, wallY, wall00, wallX0, wallXY, wall0Y, w, h, floorColor, wallColor);
}

void RectangleBuffers::BuildRectangle(char const floor, char const wallX, char const wallY, char const wall00, char const wallX0, char const wallXY, char const wall0Y, int const width, int const height, short const floorColor, short const wallColor)
{
	//Resize
	this->Resize();

	//Fill buffers 
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (x == 0 || x == width - 1)
			{
				charBuffer[x][y] = wallY;
				colorBuffer[x][y] = wallColor;
				collisionBuffer[x][y] = CollisionTypes::SOLID;
			}
			else
			{
				if (y == 0 || y == height - 1)
				{
					charBuffer[x][y] = wallX;
					colorBuffer[x][y] = wallColor;
					collisionBuffer[x][y] = CollisionTypes::SOLID;
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
				collisionBuffer[x][y] = CollisionTypes::SOLID;
			}
			else if (x == width - 1 && y == 0)
			{
				charBuffer[x][y] = wallX0;
				collisionBuffer[x][y] = CollisionTypes::SOLID;
			}
			else if (x == width - 1 && y == height - 1)
			{
				charBuffer[x][y] = wallXY;
				collisionBuffer[x][y] = CollisionTypes::SOLID;
			}
			else if (x == 0 && y == height - 1)
			{
				charBuffer[x][y] = wall0Y;
				collisionBuffer[x][y] = CollisionTypes::SOLID;
			}
		}
	}
}

std::vector<std::vector<char>>* RectangleBuffers::LoadCharBufferFile(std::string const fileName)
{
	std::ifstream myfile(fileName.c_str());

	if (myfile.is_open())
	{
		std::string contents((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());

		int i = 0;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				charBuffer[x][y] = contents[i];
				i++;
			}
			i++;
		}
	}
	myfile.close();

	return &charBuffer;
}

std::vector<std::vector<short>>* RectangleBuffers::LoadColorBufferFile(std::string const fileName)
{
	std::ifstream myfile(fileName.c_str());

	if (myfile.is_open())
	{
		std::string contents((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());

		int i = 0;
		for (int y = 1; y < height - 1; y++)
		{
			for (int x = 1; x < width - 1; x++)
			{
				short c = (short)contents[i];

				if (c < 0)
				{
					c += 256;
				}

				colorBuffer[x][y] = c;

				i++;
			}
			i++;
		}
	}
	myfile.close();

	return &colorBuffer;
}

std::vector<std::vector<short>>* RectangleBuffers::LoadCollisionBufferFile(std::string const fileName)
{
	std::ifstream myfile(fileName.c_str());

	if (myfile.is_open())
	{
		std::string contents((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());

		int i = 0;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				collisionBuffer[x][y] = (short)contents[i];
				i++;
			}
			i++;
		}
	}
	myfile.close();

	return &collisionBuffer;
}

std::vector<std::vector<char>>* RectangleBuffers::GetCharBuffer()
{
	return &charBuffer;
}

std::vector<std::vector<short>>* RectangleBuffers::GetColorBuffer()
{
	return &colorBuffer;
}

std::vector<std::vector<short>>* RectangleBuffers::GetCollisionBuffer()
{
	return &collisionBuffer;
}

void RectangleBuffers::Resize()
{
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

	collisionBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		collisionBuffer[i].resize(height);
	}
}
