#pragma once
#include "application.h"
#include <iostream>
#include <vector>

class Room
{
public:
	Room(std::string const roomName,
		char const floor, char const wallX, char const wallY, 
		char const wall00, char const wallX0, char const wallXY, char const wall0Y,  int const w = 0, int const h = 0, int const topLeftX = 0, int const topLeftY = 0, short const floorColor = 15, short const wallColor = 15);
	void CreateAsSquare();
	void Draw();
	void CreateFromVector2D(std::vector<std::vector <char>> vector2D);
	bool GetIsPlaying();
	void SetIsPlaying(bool set);
	void DrawSprite(char const sprite, int const x, int const y, int const color = 15);
	bool TryPositionIsFloor(int const x, int const y);
	void SetNextRoomName(std::string const next);
	void SetName(std::string const name);
	std::string GetName() { return name; };
	std::string const GetNextName() { return nextName; };
	void Erase();
	void Resize();
	char& GetFloor();
	short GetFloorColor();
	short GetWallsColor();
	int GetWidth() { return width; };
	int GetHeight() { return height; };
	void BackupCreate();
	void BackupLoad();

	int const floorID = -1;
	int const wallID = -2;
private:
	char Floor;
	char WallX;
	char WallY;
	char WallCorner00;
	char WallCornerX0;
	char WallCornerXY;
	char WallCorner0Y;
	bool isPlaying = true;
	int width, height, topLeftX, topLeftY;
	std::string name, nextName;
	std::vector<std::vector <char>> playAreaBuffer; //rename charBufffer
	std::vector<std::vector <char>> prevPlayAreaBuffer;
	std::vector<std::vector <char>> backupPlayAreaBuffer;

	short floorColor;
	short wallsColor;
	std::vector<std::vector <short>> colorsPlayAreaBuffer;
	std::vector<std::vector <short>> prevColorsPlayAreaBuffer;
	std::vector<std::vector <short>> backupColorsPlayAreaBuffer;
};