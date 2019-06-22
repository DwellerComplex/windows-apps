#include "canvas.h"

Canvas::Canvas(int const width, int const height, int const topLeftX, int const topLeftY, short const colorKey, std::vector<std::vector<char>> const charBuffer, std::vector<std::vector<short>> const colorBuffer, std::vector<std::vector<short>> const collisionBuffer)
{
	this->width = width;
	this->height = height;
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	this->colorKey = colorKey;

	this->frontCharBuffer = charBuffer;
	this->backCharBuffer = charBuffer;
	this->frontColorBuffer = colorBuffer;
	this->backColorBuffer = colorBuffer;
	this->frontCollisionBuffer = collisionBuffer;
	this->backCollisionBuffer = collisionBuffer;
}

Canvas::Canvas(int const topLeftX, int const topLeftY, short const colorKey, std::vector<std::vector<char>> const charBuffer, std::vector<std::vector<short>> const colorBuffer, std::vector<std::vector<short>> const collisionBuffer)
{
	this->width = charBuffer.size();
	if (charBuffer.size() != 0) { this->height = charBuffer[0].size(); } else { this->height = 0; };
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	this->colorKey = colorKey;

	this->frontCharBuffer = charBuffer;
	this->backCharBuffer = charBuffer;
	this->frontColorBuffer = colorBuffer;
	this->backColorBuffer = colorBuffer;
	this->frontCollisionBuffer = collisionBuffer;
	this->backCollisionBuffer = collisionBuffer;
}

void Canvas::Draw()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			if (frontCharBuffer[x][y] == backCharBuffer[x][y] && 
				frontColorBuffer[x][y] == backColorBuffer[x][y] ||
				frontColorBuffer[x][y] == colorKey) {
				continue;
			}

			Application::SetTextColor(frontColorBuffer[x][y]);

			Application::SetCursorPosition(x + topLeftX, y + topLeftY);
			std::cout << frontCharBuffer[x][y];
		}
	}

	std::cout.flush();

	backCharBuffer = frontCharBuffer;
	backColorBuffer = frontColorBuffer;
	backCollisionBuffer = frontCollisionBuffer;
}

void Canvas::CombineWith(Canvas * canvas)
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			if (x > canvas->GetWidth() ||
				y > canvas->GetHeight())
			{
				continue;
			}

			if (frontCharBuffer[x][y] == canvas->frontCharBuffer[x][y] &&
				frontColorBuffer[x][y] == canvas->frontCharBuffer[x][y] &&
				frontCollisionBuffer[x][y] == canvas->frontCollisionBuffer[x][y] ||
				canvas->frontColorBuffer[x][y] == canvas->GetColorKey()) {
				continue;
			}

			frontCharBuffer[x][y] = canvas->frontCharBuffer[x][y];
			frontColorBuffer[x][y] = canvas->frontColorBuffer[x][y];
			frontCollisionBuffer[x][y] = canvas->frontCollisionBuffer[x][y];
		}
	}
}

void Canvas::SetColorkey(short const color)
{
	colorKey = color;
}

void Canvas::SetCharBuffer(std::vector<std::vector<char>> const buffer)
{
	frontCharBuffer = buffer;
	backCharBuffer = buffer;
}

void Canvas::SetColorBuffer(std::vector<std::vector<short>> const buffer)
{
	frontColorBuffer = buffer;
	backColorBuffer = buffer;
}

void Canvas::SetCollisionBuffer(std::vector<std::vector<short>> const buffer)
{
	frontCollisionBuffer = buffer;
	backCollisionBuffer = buffer;
}

void Canvas::SetWidth(int const width)
{
	this->width = width;
}

void Canvas::SetHeight(int const height)
{
	this->height = height;
}

void Canvas::PutChar(char const character, int const x, int const y, short const color, short const collision)
{
	if (x >= width || x < 0 ||
		y >= height || y < 0)
	{
		return;
	}

	frontCharBuffer[x][y] = character;
	frontColorBuffer[x][y] = color;
	frontCollisionBuffer[x][y] = collision;
}

short const Canvas::GetCollisionAt(int const x, int const y)
{
	if (x >= width || x < 0 ||
		y >= height || y < 0)
	{
		return 0;
	}

	return frontCollisionBuffer[x][y];
}

short const Canvas::GetColorKey()
{
	return colorKey;
}

int const Canvas::GetWidth()
{
	return width;
}

int const Canvas::GetHeight()
{
	return height;
}

void Canvas::Resize()
{
	frontCharBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		frontCharBuffer[i].resize(height);
	}

	backCharBuffer = frontCharBuffer;

	frontColorBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		frontColorBuffer[i].resize(height);
	}
	backColorBuffer = frontColorBuffer;
	frontCollisionBuffer = frontColorBuffer;
	backCollisionBuffer = frontColorBuffer;
}

void Canvas::Copy(Canvas * canvas)
{
	width = canvas->width;
	height = canvas->height;
	topLeftX = canvas->topLeftX;
	topLeftY = canvas->topLeftY;
	colorKey = canvas->colorKey;

	frontCharBuffer = canvas->frontCharBuffer;
	backCharBuffer = canvas->backCharBuffer;
	frontColorBuffer = canvas->frontColorBuffer;
	backColorBuffer = canvas->backColorBuffer;
	frontCollisionBuffer = canvas->frontCollisionBuffer;
	backCollisionBuffer = canvas->backCollisionBuffer;
}

void Canvas::EraseBuffersContents()
{
	int const oldW = width;
	int const oldH = height;

	width = 0;
	height = 0;

	Resize();

	width = oldW;
	height = oldH;

	Resize();
}

void Canvas::SetBuffersToZero()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			if (x > width ||
				y > height)
			{
				continue;
			}

			frontCharBuffer[x][y] = char(32);
			frontColorBuffer[x][y] = 0;
			frontCollisionBuffer[x][y] = 0;
		}
	}
}

void Canvas::Erase()
{
	width = 0;
	height = 0;
	topLeftX = 0;
	topLeftY = 0;
	colorKey = 0;

	Resize();
}



