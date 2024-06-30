#include "GameObjectFactories/RopeFactory.h"
#include "GameObjects/Rope.h"


//===================================================================
// creats rope object
//===================================================================
std::shared_ptr<GameObject> RopeFactory::createObject(const std::string& line, World& world, const sf::Texture& texture)
{
	std::istringstream iss(line);
	Data objectData;

	iss >> objectData.m_type >> objectData.m_subType >> objectData.m_length >> objectData.m_pos.x >> objectData.m_pos.y >> objectData.m_angle;
	return std::make_shared<Rope>(objectData, world, texture);
}
