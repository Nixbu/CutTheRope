#include "World.h"

World::World() : m_physicalWorld(b2Vec2(0.0f, -9.8f))
{
}

void World::addObject(std::string& line)
{
	try {
		auto& manager = FactoryManager::getInstance();
		std::istringstream iss(line);
		Data objectData;

		std::string type;

		iss >> type;

		iss >> objectData.m_pos.x >> objectData.m_pos.y;

		auto factory = manager.getFactory(type);

		std::unique_ptr<GameObject> &&object = factory->createObject(objectData, this->m_physicalWorld);

		this->m_gameObjects.push_back(std::move(object));
	}
	catch(const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;

	}

}