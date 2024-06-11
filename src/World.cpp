#include "World.h"

World::World() : m_physicalWorld(b2Vec2(0.0f, -9.8f))
{
}

void World::addObject(std::string& line)
{
	std::istringstream iss(line);
	Data objectData;

	std::string type;

	iss >> type;

	iss >> objectData.m_pos.x >> objectData.m_pos.y;



	
}