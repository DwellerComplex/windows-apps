#pragma once
const enum Entities
{
	PLAYER = 1,
	MERIMEL,
	FLASHLIGHT,
	PLAYER_SPAWNPOINT,

	//_________________mainmenu_________________//
	MAINMENU_DOOR_PLAY,
	MAINMENU_DOOR_QUIT,

	WORLD1_1_DOOR1,
	WORLD1_1_TREE1,
	WORLD1_1_TREE2,
	WORLD1_1_TREE3,
	WORLD1_1_TREE4,
	WORLD1_1_TREE5,
	WORLD1_1_TREE6,
	WORLD1_1_TREE7,
	WORLD1_1_TREE8,
	WORLD1_1_TREE9,
	WORLD1_1_TREE10,
	WORLD1_1_TREE11,
	WORLD1_1_TREE12,

	WORLD1_2_OBSTACLE1,

	WORLD1_3_KEY,

	WORLD1_4_OBSTACLE1,
	WORLD1_4_OBSTACLE2,
	WORLD1_4_KEY,
	WORLD1_4_AXE,

	NUMBER_OF_ENTITIES
};

const enum BackPackItemTypes
{
	GOLD_KEY = 1,
	SILVER_KEY,
	AXE,
	LOG,
	NUMBER_OF_TYPES
};

const enum Scenes
{
	QUIT = 1,
	MAINMENU,
	WORLD1_1,
	WORLD1_2,
	WORLD1_3,
	WORLD1_4,
	WORLD1_5,
	NUMBER_OF_SCENES
};

const enum CollisionTypes
{
	NONE,
	//1: kinetic (ignore normal and kinetic items) 
	KINETIC,
	//2: solid (ignore no items, block all) 
	SOLID,
	//3: dynamic (ignore kinetic, interact with normal and solid, "pushable")
	DYNAMIC,
	NUMBER_OF_COLLISION_TYPES
};

const enum DrawLayers 
{
	ONE,
	TWO,
	THREE,
	NUMBER_OF_DRAW_LAYERS
};