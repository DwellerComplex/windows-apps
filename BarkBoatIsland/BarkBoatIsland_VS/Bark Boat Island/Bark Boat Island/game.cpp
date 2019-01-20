#include "game.h"

Game::Game()
{
	//Application and ecs controls
	Application& app = Application::get_instance();

	player = new Entity(1);
	playerNearby = new NearbyComponent;
	playerPosition = new PositionComponent(1, 4);
	playerSprite = new SpriteComponent('#', 13, 1);//14
	playerInput = new InputComponent;
	playerMotion = new MotionComponent(0,0,0,0,0,4);
	playerInventory = new InventoryComponent;
	playerLife = new LifeComponent(1);
	playerCollision = new CollisionComponent(0);
	playerPlatformRider = new PlatformRiderComponent;

	theEntityComponentSystem.theEntityManager.addEntity(player);
	theEntityComponentSystem.theComponentManagers.theNearbyManager.addComponent(player, playerNearby);
	theEntityComponentSystem.theComponentManagers.thePositionManager.addComponent(player, playerPosition);
	theEntityComponentSystem.theComponentManagers.theSpriteManager.addComponent(player, playerSprite);
	theEntityComponentSystem.theComponentManagers.theInputManager.addComponent(player, playerInput);
	theEntityComponentSystem.theComponentManagers.theMotionManager.addComponent(player, playerMotion);
	theEntityComponentSystem.theComponentManagers.theInventoryManager.addComponent(player, playerInventory);
	theEntityComponentSystem.theComponentManagers.theLifeManager.addComponent(player, playerLife);
	theEntityComponentSystem.theComponentManagers.theCollisionManager.addComponent(player, playerCollision);
	theEntityComponentSystem.theComponentManagers.thePlatformRiderManager.addComponent(player, playerPlatformRider);

	theInventoryPanel = new InventoryPanel(playerInventory);

	theConsolePanel = new ConsolePanel;
	theConsolePanel->create(0, app.GetConsoleHeight() - 8, app.GetConsoleWidth(), 8);
	theConsolePanel->console->CreateAsSquare();
	theConsolePanel->console->BackupCreate();
}

void Game::PlayRoom()
{
	if (currentRoom == "MainMenu")
	{
		this->MainMenu();
	}
	else if (currentRoom == "Hall")
	{
		this->Hall();
	}
	else
	{
		currentRoom = "";
	}
}

void Game::SetCurrentRoom(std::string room)
{
	currentRoom = room;
}