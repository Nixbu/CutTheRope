#pragma once

#include "box2d/box2d.h"
#include "GameObjects/GameObject.h"
#include <sstream>
#include "Settings.h"
#include <iostream>
#include "FactoryManager.h"
#include "ResourceManager.h"

class World
{
public:
	World();
	void addObject(std::string& line);
	void draw(sf::RenderWindow& window) const;
private:
	b2World m_physicalWorld;
	std::vector<std::shared_ptr<GameObject>> m_gameObjects;
	
};