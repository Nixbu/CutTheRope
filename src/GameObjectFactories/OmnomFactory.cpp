#include "GameObjectFactories/OmnomFactory.h"
#include "GameObjects/Omnom.h"

//===================================================================
// creats Omnom object
//===================================================================
std::shared_ptr<GameObject> OmnomFactory::createObject(const std::string& line,
	World& world,
	const sf::Texture& texture)
{
	std::istringstream iss(line);
	Data objectData;

	iss >> objectData.m_type >> objectData.m_subType >> objectData.m_pos.x >> objectData.m_pos.y >> objectData.m_angle;
	return std::make_shared<Omnom>(objectData, world, texture);
}
