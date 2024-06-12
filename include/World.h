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
private:
	b2World m_physicalWorld;
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	
};