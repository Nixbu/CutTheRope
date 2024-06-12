#include "World.h"


World::World() : m_physicalWorld(b2Vec2(0.0f, -9.8f))
{
}

void World::addObject(std::string& line)
{
	try {
		auto& factoryManager = FactoryManager::getInstance();

		auto& resourceManager = ResourceManager::getInstance();

		std::istringstream iss(line);
		Data objectData;

		iss >> objectData.m_type >> objectData.m_pos.x >> objectData.m_pos.y;

		sf::Texture texture = resourceManager.getImage(objectData.m_type);

		auto factory = factoryManager.getFactory(objectData.m_type);

		std::unique_ptr<GameObject> &&object = factory->createObject(objectData, this->m_physicalWorld, texture);

		this->m_gameObjects.push_back(std::move(object));
	}
	catch(const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;

	}

}

void World::draw(sf::RenderWindow& window) const 
{
	for (const auto& object : this->m_gameObjects)
	{
		object->draw(window);
	}
}
