//#include "inventorypanel.h"
//
//InventoryPanel::InventoryPanel(InventoryComponent* inventoryToDisplay)//,  int const topLeftX, int const topLeftY
//{
//	this->inventoryComp = inventoryToDisplay;
//
//	Room* inv = new Room("Inventory", char(239), char(248), char(248), char(248), char(248), char(248), char(248), 0, 0, Application::GetConsoleWidth() - 30, 0,8,3);
//	inv->CreateFromVector2D(Application::ReadFileToVector2D("Scenes/playerinventory.txt"));
//
//	inv->BackupCreate();
//	this->inventory = inv;
//}
//
//void InventoryPanel::setTitle(std::string const title)
//{
//	this->inventory->SetName(title);
//
//	char character;
//
//	//TITLE
//	for (int charPos = 0; charPos < this->inventory->GetWidth() - 2; charPos++)
//	{
//		character = char(32);
//		this->inventory->DrawSprite(character, charPos + 1, 1);
//	}
//
//	for (int charPos = 0; charPos < title.size(); charPos++)
//	{
//		character = title[charPos];
//		this->inventory->DrawSprite(character, charPos + 1, 1);
//	}
//}
//
//void InventoryPanel::draw()
//{
//	std::string entityName;
//	char character;
//
//	//ENTITIES
//	for (int row = 0; row < inventoryComp->size(); row++)
//	{
//		entityName = inventoryComp->getEntity(row)->name;
//
//		for (int charPos = 0; charPos < entityName.size(); charPos++)
//		{
//			character = entityName[charPos];
//			inventory->DrawSprite(character, charPos + 1, row + 3);
//		}
//	}
//
//	inventory->Draw();
//}
//
//void InventoryPanel::destroy()
//{
//	this->inventory->Erase();
//	delete this->inventory;
//}
//
//void InventoryPanel::erase()
//{
//	this->inventory->Erase();
//}