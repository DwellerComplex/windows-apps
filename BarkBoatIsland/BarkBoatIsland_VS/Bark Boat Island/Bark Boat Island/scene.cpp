#include "scene.h"

Canvas::Canvas(std::string const sceneName,
	char const floor, char const wallX, char const wallY,
	char const wall00, char const wallX0, char const wallXY, char const wall0Y,  int const w, int const h, int const topLeftX, int const topLeftY, short const floorColor, short const wallColor)
{
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	width = w;
	height = h;

	this->Floor = floor;
	this->WallX = wallX;
	this->WallY = wallY;
	this->WallCorner00 = wall00;
	this->WallCorner0Y = wall0Y;
	this->WallCornerX0 = wallX0;
	this->WallCornerXY = wallXY;

	this->floorColor = floorColor;
	this->wallsColor = wallColor;
}

void Canvas::CreateAsSquare()
{
	this->Resize();

	//Paint frontBuffer
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (x == 0 || x == width - 1)
			{
				backBuffer[x][y] = this->WallX;
				backColorBuffer[x][y] = this->wallsColor;
			}
			else
			{
				if (y == 0 || y == height - 1)
				{
					backBuffer[x][y] = this->WallY;
					backColorBuffer[x][y] = this->wallsColor;
				}
				else
				{
					backBuffer[x][y] = this->Floor;
					backColorBuffer[x][y] = this->floorColor;
				}
			}
			if (x == 0 && y == 0)
			{
				backBuffer[x][y] = this->WallCorner00;
			}
			else if (x == width - 1 && y == 0)
			{
				backBuffer[x][y] = this->WallCornerX0;
			}
			else if (x == width - 1 && y == height - 1)
			{
				backBuffer[x][y] = this->WallCornerXY;
			}
			else if (x == 0 && y == height - 1)
			{
				backBuffer[x][y] = this->WallCorner0Y;
			}
		}
	}
}

void Canvas::Draw()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			if (frontBuffer[x][y] == showBuffer[x][y] && frontColorBuffer[x][y] == showColorBuffer[x][y]) {
				continue;
			}

			Application::SetTextColor(this->frontColorBuffer[x][y]);

			Application::SetCursorPosition(x + topLeftX, y + topLeftY);
			std::cout << frontBuffer[x][y];
		}
	}

	std::cout.flush();

	//Copy frontBuffer to showBuffer
	showBuffer = frontBuffer;
	showColorBuffer = frontColorBuffer;
}

void Canvas::DrawSprite(char const body, int const x, int const y, int const color)
{
	if (x < width &&
		x >= 0 &&
		y < height &&
		y >= 0)
	{
		this->frontBuffer[x][y] = body;
		this->frontColorBuffer[x][y] = color;
	}
}

void Canvas::DrawString(std::string const str, int const x, int const y, int const color, bool const autoFit, char const bgSprite, int const bgColor)
{
	if (autoFit)
	{
		for (int bg = x; bg < this->width - 1; bg++)
		{
			this->frontBuffer[bg][y] = bgSprite;
			this->frontColorBuffer[bg][y] = bgColor;
		}
		for (int i = 0; i < str.size(); i++)
		{
			this->frontBuffer[x + ((this->width) / str.size()) * i][y] = str.at(i);

			this->frontColorBuffer[x + ((this->width) / str.size()) * i][y] = color;
		}
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			this->frontBuffer[x + i][y] = str.at(i);

			this->frontColorBuffer[x + i][y] = color;
		}
	}
}

void Canvas::Erase()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			frontBuffer[x][y] = char(32);
			frontColorBuffer[x][y] = 0;
		}
	}
	Draw();
}

bool Canvas::TryPositionIsFloor(int const x, int const y)
{
	if (x < width &&
		x >= 0 &&
		y < height &&
		y >= 0 && 
		frontBuffer[x][y] == Floor)
	{
		return true;
	}
	return false;
}

bool Canvas::TryPositionIsWall(int const x, int const y)
{
	if (x < width && 
		x >= 0 && 
		y < height && 
		y >= 0)
	{
		if (frontBuffer[x][y] == WallX ||
			frontBuffer[x][y] == WallY ||
			frontBuffer[x][y] == WallCorner00 ||
			frontBuffer[x][y] == WallCornerX0 ||
			frontBuffer[x][y] == WallCorner0Y ||
			frontBuffer[x][y] == WallCornerXY)
		{
			return true;
		}
	}

	return false;
}

char& Canvas::GetFloor()
{
	return this->Floor;
}

char& Canvas::GetChar(int const x, int const y)
{
	if (x < width &&
		x >= 0 &&
		y < height &&
		y >= 0)
	{
		return this->backBuffer[x][y];
	}
	return this->Floor;
}

short Canvas::GetFloorColor()
{
	return this->floorColor;
}

short Canvas::GetWallsColor()
{
	return this->wallsColor;
}

void Canvas::ClearFront()
{
	frontBuffer = backBuffer;
	frontColorBuffer = backColorBuffer;
}

//1 = WallX
//2 = WallY
//3 = WallCorner00
//4 = WallCornerX0
//5 = WallCorner0Y
//6 = WallCornerXY
//7 = Floor
//8 = Space
void Canvas::CreateFromVector2D(std::vector<std::vector <char>> vector2D)
{
	Application::TransformVector2D(vector2D);

	width = (int)vector2D.size();
	height = (int)vector2D[0].size();

	this->Resize();

	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			this->backColorBuffer[x][y] = this->wallsColor;
			
			if (vector2D[x][y] == '7')
			{
				this->backColorBuffer[x][y] = this->floorColor;
				vector2D[x][y] = Floor;
			}
			else if (vector2D[x][y] == '1')
			{
				vector2D[x][y] = WallX;
			}
			else if (vector2D[x][y] == '2')
			{
				vector2D[x][y] = WallY;
			}
			else if (vector2D[x][y] == '3')
			{
				vector2D[x][y] = WallCorner00;
			}
			else if (vector2D[x][y] == '4')
			{
				vector2D[x][y] = WallCornerX0;
			}
			else if (vector2D[x][y] == '5')
			{
				vector2D[x][y] = WallCorner0Y;
			}
			else if (vector2D[x][y] == '6')
			{
				vector2D[x][y] = WallCornerXY;
			}
			else if (vector2D[x][y] == '8')
			{
				vector2D[x][y] = ' ';
			}

			backBuffer[x][y] = vector2D[x][y];
		}
	}
}

void Canvas::Resize()
{
	showBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		showBuffer[i].resize(height);
	}

	frontBuffer = showBuffer;
	backBuffer = showBuffer;
	
	//resize colorbuffer
	frontColorBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		frontColorBuffer[i].resize(height);
	}
	showColorBuffer = frontColorBuffer;
	backColorBuffer = frontColorBuffer;
}

void Canvas::BackupCreate()
{
	this->backupCharBuffer = this->frontBuffer;
	this->backupColorBuffer = this->frontColorBuffer;
}

void Canvas::BackupLoad()
{
	this->frontBuffer = this->backupCharBuffer;
	this->frontColorBuffer = this->backupColorBuffer;
}