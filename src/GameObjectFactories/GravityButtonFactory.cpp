#include "GameObjectFactories/GravityButtonFactory.h"


//===================================================================
// creats gravity button object
//===================================================================
std::unique_ptr<GameObject> GravityButtonFactory::createObject(const std::string& line, World& world, const sf::Texture& texture)
{

	std::istringstream iss(line);
	Data objectData;

	iss >> objectData.m_type >> objectData.m_subType >> objectData.m_pos.x >> objectData.m_pos.y;
	return std::make_unique<GravityButton>(objectData, world, texture);
}