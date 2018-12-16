#include "room.h"

Room::Room(std::string const roomName,
	char const floor, char const wallX, char const wallY,
	char const wall00, char const wallX0, char const wallXY, char const wall0Y,  int const w, int const h, int const topLeftX, int const topLeftY, short const floorColor, short const wallColor)
{
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	width = w;
	height = h;
	name = roomName;
	nextName = "";

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

void Room::CreateAsSquare()
{
	this->Resize();

	//Paint playAreaBuffer
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (x == 0 || x == width - 1)
			{
				playAreaBuffer[x][y] = this->WallX;
				colorsPlayAreaBuffer[x][y] = this->wallsColor;
			}
			else
			{
				if (y == 0 || y == height - 1)
				{
					playAreaBuffer[x][y] = this->WallY;
					colorsPlayAreaBuffer[x][y] = this->wallsColor;
				}
				else
				{
					playAreaBuffer[x][y] = this->Floor;
					colorsPlayAreaBuffer[x][y] = this->floorColor;
				}
			}
			if (x == 0 && y == 0)
			{
				playAreaBuffer[x][y] = this->WallCorner00;
			}
			else if (x == width - 1 && y == 0)
			{
				playAreaBuffer[x][y] = this->WallCornerX0;
			}
			else if (x == width - 1 && y == height - 1)
			{
				playAreaBuffer[x][y] = this->WallCornerXY;
			}
			else if (x == 0 && y == height - 1)
			{
				playAreaBuffer[x][y] = this->WallCorner0Y;
			}
		}
	}
	//Draw();
}

void Room::Draw()
{
	Application& app = Application::get_instance();

	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			if (playAreaBuffer[x][y] == prevPlayAreaBuffer[x][y] && colorsPlayAreaBuffer[x][y] == prevColorsPlayAreaBuffer[x][y]) {
				continue;
			}

			app.SetTextColor(this->colorsPlayAreaBuffer[x][y]);

			app.SetCursorPosition(x + topLeftX, y + topLeftY);
			std::cout << playAreaBuffer[x][y];
		}
	}

	std::cout.flush();

	//Copy playAreaBuffer to prevPlayAreaBuffer
	prevPlayAreaBuffer = playAreaBuffer;
	prevColorsPlayAreaBuffer = colorsPlayAreaBuffer;
}

void Room::DrawSprite(char const body, int const x, int const y, int const color)
{
	this->playAreaBuffer[x][y] = body;

	this->colorsPlayAreaBuffer[x][y] = color;
}

bool Room::GetIsPlaying()
{
	return isPlaying;
}

void Room::SetIsPlaying(bool set)
{
	this->isPlaying = set;
}

void Room::SetNextRoomName(std::string const next)
{
	this->nextName = next;
}

void Room::Erase()
{
	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			playAreaBuffer[x][y] = char(32);
			colorsPlayAreaBuffer[x][y] = 0;
		}
	}
	Draw();
}

bool Room::TryPositionIsFloor(int const x, int const y)
{
	if (playAreaBuffer[x][y] == Floor)
	{
		return true;
	}
	return false;
}

char& Room::GetFloor()
{
	return this->Floor;
}

short Room::GetFloorColor()
{
	return this->floorColor;
}

short Room::GetWallsColor()
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
void Room::CreateFromVector2D(std::vector<std::vector <char>> vector2D)
{
	Application& app = Application::get_instance();
	app.TransformVector2D(vector2D);

	width = (int)vector2D.size();
	height = (int)vector2D[0].size();

	this->Resize();

	for (int y = 0; y != height; ++y)
	{
		for (int x = 0; x != width; ++x)
		{
			this->colorsPlayAreaBuffer[x][y] = this->wallsColor;
			
			if (vector2D[x][y] == '7')
			{
				this->colorsPlayAreaBuffer[x][y] = this->floorColor;
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

			playAreaBuffer[x][y] = vector2D[x][y];
		}
	}
}

void Room::Resize()
{
	//Resize prevPlayAreaBuffer and then playAreaBuffer 
	prevPlayAreaBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		prevPlayAreaBuffer[i].resize(height);
	}

	playAreaBuffer = prevPlayAreaBuffer;
	
	//resize colorbuffer
	colorsPlayAreaBuffer.resize(width);
	for (int i = 0; i < width; i++)
	{
		colorsPlayAreaBuffer[i].resize(height);
	}
	prevColorsPlayAreaBuffer = colorsPlayAreaBuffer;
}

void Room::SetName(std::string const name)
{
	this->name = name;
}

void Room::BackupCreate()
{
	this->backupPlayAreaBuffer = this->playAreaBuffer;
	this->backupColorsPlayAreaBuffer = this->colorsPlayAreaBuffer;
}

void Room::BackupLoad()
{
	this->playAreaBuffer = this->backupPlayAreaBuffer;
	this->colorsPlayAreaBuffer = this->backupColorsPlayAreaBuffer;
}