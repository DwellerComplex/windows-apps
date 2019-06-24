#pragma once
const enum Entities
{
	PLAYER = 1,
	FLASHLIGHT,

	//_________________mainmenu_________________//
	MAINMENU_DOOR_PLAY,
	MAINMENU_DOOR_QUIT,

	//_________________startup_________________//
	STARTUP_SILVER_KEY,
	STARTUP_SILVER_KEY2,
	STARTUP_DOOR_MAINMENU,
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