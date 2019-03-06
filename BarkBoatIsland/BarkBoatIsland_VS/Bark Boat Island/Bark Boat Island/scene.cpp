#include "scene.h"

Scene::Scene(std::string const sceneName,
	char const floor, char const wallX, char const wallY,
	char const wall00, char const wallX0, char const wallXY, char const wall0Y,  int const w, int const h, int const topLeftX, int const topLeftY, short const floorColor, short const wallColor)
{
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	width = w;
	height = h;
	name = sceneName;
	nextName = 0;

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

void Scene::CreateAsSquare()
{
	this->Resize();

	//Paint charBuffer
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (x == 0 || x == width - 1)
			{
				charBuffer[x][y] = this->WallX;
				colorBuffer[x][y] = this->wallsColor;
			}
			else
			{
				if (y == 0 || y == height - 1)
				{
					charBuffer[x][y] = this->WallY;
					colorBuffer[x][y] = this->wallsColor;
				}
				else
				{
					charBuffer[x][y] = this->Floor;
					colorBuffer[x][y] = this->floorColor;
				}
			}
			if (x == 0 && y == 0)
			{
				charBuffer[x][y] = this->WallCorner00;
			}
			else if (x == width - 1 && y == 0)
			{
				charBuffer[x][y] = this->WallCornerX0;
			}
			else if (x == width - 1 && y == height - 1)
			{
				charBuffer[x][y] = this->WallCornerXY;
			}
			else if (x == 0 && y == height - 1)
			{
				charBuffer[x][y] = this->WallCorner0Y;
			}
		}
	}
	//Draw();
}

void Scene::Draw()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			if (charBuffer[x][y] == prevCharBuffer[x][y] && colorBuffer[x][y] == prevColorBuffer[x][y]) {
				continue;
			}

			Application::SetTextColor(this->colorBuffer[x][y]);

			Application::SetCursorPosition(x + topLeftX, y + topLeftY);
			std::cout << charBuffer[x][y];
		}
	}

	std::cout.flush();

	//Copy charBuffer to prevCharBuffer
	prevCharBuffer = charBuffer;
	prevColorBuffer = colorBuffer;
}

void Scene::DrawSprite(char const body, int const x, int const y, int const color)
{
	this->charBuffer[x][y] = body;

	this->colorBuffer[x][y] = color;
}

void Scene::DrawString(std::string const str, int const x, int const y, int const color, bool const autoFit, char const bgSprite, int const bgColor)
{
	if (autoFit)
	{
		for (int bg = x; bg < this->width - 1; bg++)
		{
			this->charBuffer[bg][y] = bgSprite;
			this->colorBuffer[bg][y] = bgColor;
		}
		for (int i = 0; i < str.size(); i++)
		{
			this->charBuffer[x + ((this->width) / str.size()) * i][y] = str.at(i);

			this->colorBuffer[x + ((this->width) / str.size()) * i][y] = color;
		}
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			this->charBuffer[x + i][y] = str.at(i);

			this->colorBuffer[x + i][y] = color;
		}
	}
}

bool Scene::GetIsPlaying()
{
	return isPlaying;
}

void Scene::SetIsPlaying(bool set)
{
	this->isPlaying = set;
}

void Scene::SetNextSceneName(short const next)
{
	this->nextName = next;
}

void Scene::Erase()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			charBuffer[x][y] = char(32);
			colorBuffer[x][y] = 0;
		}
	}
	Draw();
}

bool Scene::TryPositionIsFloor(int const x, int const y)
{
	if (charBuffer[x][y] == Floor)
	{
		return true;
	}
	return false;
}

char& Scene::GetFloor()
{
	return this->Floor;
}

short Scene::GetFloorColor()
{
	return this->floorColor;
}

short Scene::GetWallsColor()
{
	return this->wallsColor;
}

//1 = WallX
//2 = WallY
//3 = WallCorner00
//4 = WallCornerX0
//5 = WallCorner0Y
//6 = WallCornerXY
//7 = Floor
//8 = Space
void Scene::CreateFromVector2D(std::vector<std::vector <char>> vector2D)
{
	Application::TransformVector2D(vector2D);

	width = (int)vector2D.size();
	height = (int)vector2D[0].size();

	this->Resize();

	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			this->colorBuffer[x][y] = this->wallsColor;
			
			if (vector2D[x][y] == '7')
			{
				this->colorBuffer[x][y] = this->floorColor;
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

			charBuffer[x][y] = vector2D[x][y];
		}
	}
}

void Scene::Resize()
{
	//Resize prevCharBuffer and then charBuffer 
	prevCharBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		prevCharBuffer[i].resize(height);
	}

	charBuffer = prevCharBuffer;
	
	//resize colorbuffer
	colorBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		colorBuffer[i].resize(height);
	}
	prevColorBuffer = colorBuffer;
}

void Scene::SetName(std::string const name)
{
	this->name = name;
}

void Scene::BackupCreate()
{
	this->backupCharBuffer = this->charBuffer;
	this->backupColorBuffer = this->colorBuffer;
}

void Scene::BackupLoad()
{
	this->charBuffer = this->backupCharBuffer;
	this->colorBuffer = this->backupColorBuffer;
}