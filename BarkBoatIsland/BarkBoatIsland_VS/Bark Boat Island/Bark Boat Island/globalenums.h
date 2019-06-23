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
	MAINMENU = 1,
	STARTUP,
	NUMBER_OF_SCENES
};