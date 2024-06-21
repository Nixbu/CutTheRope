#include "GameObjectFactories/DoubleHatFactory.h"
#include "GameObjects/DoubleHat.h"


std::shared_ptr<GameObject> DoubleHatFactory::createObject(const std::string& line, World& world, const sf::Texture& texture)
{
	// TODO add reading logic
	std::istringstream iss(line);
	Data objectData;

	iss >> objectData.m_type >> objectData.m_subType >> objectData.m_pos.x >> objectData.m_pos.y
		>> objectData.m_angle >> objectData.m_pos2.x >> objectData.m_pos2.y >> objectData.m_angle2;

	return std::make_shared<DoubleHat>(objectData, world, texture);
}
