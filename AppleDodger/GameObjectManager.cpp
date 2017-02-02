#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(gameObjects.begin(), gameObjects.end(), GameObjectDeallocator());
}


void GameObjectManager::add(std::string name, GameObject* gameObject)
{
	gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::remove(std::string name)
{
	std::map<std::string, GameObject*>::iterator results = gameObjects.find(name);
	if (results != gameObjects.end())
	{
		delete results->second;
		gameObjects.erase(results);
	}
}


void GameObjectManager::drawAll(sf::RenderWindow& renderWindow)
{
	iter = gameObjects.begin();
	while (iter != gameObjects.end())
	{
		iter->second->draw(renderWindow);
		iter++;
	}
}

void GameObjectManager::updateAll()
{
	iter = gameObjects.begin();
	timeDelta = clock.restart().asSeconds();
	while (iter != gameObjects.end())
	{
		iter->second->update(timeDelta);
		iter++;
	}
}


GameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, GameObject*>::const_iterator results = gameObjects.find(name);
	if (results == gameObjects.end())
		return NULL;
	return results->second;
}
