#include "World.h"


World::World() : m_physicalWorld(b2Vec2(0.0f, -9.8f))
{
}

void World::addObject(std::string& line)
{
	try {
		auto& resourceManager = ResourceManager::getInstance();

		std::istringstream iss(line);
		Data objectData;

		iss >> objectData.m_type >> objectData.m_pos.x >> objectData.m_pos.y;

		const sf::Texture& texture = resourceManager.getImage(objectData.m_type);

		std::shared_ptr<GameObject> object = FactoryManager::create(objectData.m_type, objectData, this->m_physicalWorld, texture);

		if (object != nullptr)
		{
			this->m_gameObjects.push_back(object);
		}
		//	else
		//	{
		//		throw ObjectNotFoundException; //TODO
		//	}
		//}

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

void World::reset()
{
	this->m_gameObjects.clear();
}
