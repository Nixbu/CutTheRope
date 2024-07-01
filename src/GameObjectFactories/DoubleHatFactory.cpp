#include "GameObjectFactories/DoubleHatFactory.h"
#include "GameObjects/DoubleHat.h"

//===================================================================
// creats double hat object
//===================================================================
std::unique_ptr<GameObject> DoubleHatFactory::createObject(const std::string& line, World& world, const sf::Texture& texture)
{
	std::istringstream iss(line);
	Data objectData;

	iss >> objectData.m_type >> objectData.m_subType >> objectData.m_pos.x >> objectData.m_pos.y
		>> objectData.m_angle >> objectData.m_pos2.x >> objectData.m_pos2.y >> objectData.m_angle2;

	return std::make_unique<DoubleHat>(objectData, world, texture);
}
