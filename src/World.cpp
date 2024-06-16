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

void World::update(float timeStep)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2; // TODO change to constants

	// Step the physics world
	m_physicalWorld.Step(timeStep, velocityIterations, positionIterations);

	// Update all game objects to match their physics bodies
	for (auto& object : m_gameObjects) {
		object->update();
	}
}

void World::handleCollisions()
{
	for (int index1 = 0; index1 < this->m_gameObjects.size(); index1++)
	{
		for (int index2 = 0; index2 < this->m_gameObjects.size(); index2++)
		{
			if (index1 == index2)
			{
				continue;
			}
			if(checkCollision(m_gameObjects[index1], m_gameObjects[index2]))
			{
				auto collisionsFunc = collisionsMap.lookup(typeid(m_gameObjects[index1]), typeid(m_gameObjects[index2]));

				if (collisionsFunc != nullptr)
				{
					collisionsFunc(m_gameObjects[index1], m_gameObjects[index2]);
				}
			}
		}
	}
	for (b2Contact* contact = this->m_physicalWorld.GetContactList(); contact; contact = contact->GetNext()) {
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		b2Body* bodyA = fixtureA->GetBody();
		b2Body* bodyB = fixtureB->GetBody();

		// Find the corresponding game objects for the bodies
		std::shared_ptr<GameObject> objectA = static_cast<GameObject*>(bodyA->GetUserData());
		std::shared_ptr<GameObject> objectB = static_cast<GameObject*>(bodyB->GetUserData());

		// Check for collisions between objects
		auto collisionsFunc = collisionsMap.lookup(typeid(*objectA), typeid(*objectB));
		if (collisionsFunc != nullptr) {
			collisionsFunc(objectA, objectB);
		}
	}
}
