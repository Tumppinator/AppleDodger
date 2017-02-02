#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H
#include "GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void add(std::string name, GameObject* gameObject);
	void remove(std::string name);

	void drawAll(sf::RenderWindow& renderWindow);
	void updateAll();

	GameObject* Get(std::string name) const;

private:
	std::map<std::string, GameObject*> gameObjects;
	std::map<std::string, GameObject*>::const_iterator iter;
	sf::Clock clock;
	float timeDelta;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, GameObject*> & p) const
		{
			delete p.second;
		}
	};

};

#endif


