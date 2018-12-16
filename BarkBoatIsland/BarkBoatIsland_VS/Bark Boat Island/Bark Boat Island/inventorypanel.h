#ifndef __INVENTORYPANEL_H_INCLUDED__
#define __INVENTORYPANEL__

#pragma once
#include "room.h"
#include "ECS.h"

class InventoryPanel
{
public:
	InventoryPanel(InventoryComponent * inventoryToDisplay);
	//void create(int const topLeftX, int const topLeftY);//
	void setTitle(std::string const title);
	void draw();
	void destroy();
	void erase();
	Room* inventory;
	InventoryComponent* inventoryComp;
};

#endif