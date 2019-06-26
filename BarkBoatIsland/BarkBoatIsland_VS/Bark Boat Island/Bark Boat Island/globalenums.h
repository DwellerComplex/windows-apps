#pragma once
const enum Entities
{
	PLAYER = 1,
	FLASHLIGHT,
	PLAYER_SPAWNPOINT,

	//_________________mainmenu_________________//
	MAINMENU_DOOR_PLAY,
	MAINMENU_DOOR_QUIT,

	//_________________startup_________________//
	STARTUP_DOOR_SMALLHOUSE,
	STARTUP_SPIKETRAP,

	//_________________startup_________________//
	SMALLHOUSE_DOOR_STARTUP,
	SMALLHOUSE_SILVER_KEY,

	NUMBER_OF_ENTITIES
};

const enum BackPackItemTypes
{
	GOLD_KEY = 1,
	SILVER_KEY,
	NUMBER_OF_TYPES
};

const enum Scenes
{
	QUIT = 1,
	MAINMENU,
	STARTUP,
	SMALLHOUSE,
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