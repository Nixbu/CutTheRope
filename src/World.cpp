#include "World.h"


World::World() : m_physicalWorld(b2Vec2(0.0f, -9.8f)) , m_candy(nullptr)
{
	m_gameObjects.reserve(MAX_SIZE);
}

void World::addObject(std::string& line)
{
	try {
		auto& resourceManager = ResourceManager::getInstance();

		std::istringstream iss(line);
		Data objectData;

		iss >> objectData.m_type >> objectData.m_subType >> objectData.m_pos.x >> objectData.m_pos.y >> objectData.m_angle;

		const sf::Texture& texture = resourceManager.getImage(objectData.m_subType);

		std::shared_ptr<GameObject> object = FactoryManager::create(objectData.m_type, objectData,
			*this, texture);

		if (object != nullptr)
		{
			if (objectData.m_type == "Candy") {
				this->m_candy = object;
			}
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

void World::addToGameObjects(std::shared_ptr<GameObject> object)
{
	this->m_gameObjects.emplace_back(object);
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

	this->deleteWantedObjects();
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
			if(this->checkCollision(m_gameObjects[index1], m_gameObjects[index2]))
			{
				auto collisionsFunc = lookup(typeid(*m_gameObjects[index1]), typeid(*m_gameObjects[index2]));

				if (collisionsFunc != nullptr)
				{
					collisionsFunc(m_gameObjects[index1], m_gameObjects[index2], this->m_physicalWorld);
				}
			}
		}
	}
}

void World::handleClicks(const sf::Vector2f& mousePos)
{
	for (auto& object : this->m_gameObjects)
	{
		auto clickable = std::dynamic_pointer_cast<ClickableObject>(object);
		if(clickable)
		{
			if (clickable->isClicked(mousePos))
			{
				clickable->handleClicked();
			}
		}
	}

	this->deleteWantedObjects();
}

b2World& World::getWorld()
{
	return this->m_physicalWorld;
}

std::shared_ptr<GameObject> World::getCandy()const
{
	return this->m_candy;
}


bool World::checkCollision(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2)
{
	b2Body* bodyA = object1->getBody();
	b2Body* bodyB = object2->getBody();

	if (bodyA && bodyB)
	{
		// Check contacts of bodyA
		for (b2ContactEdge* edge = bodyA->GetContactList(); edge; edge = edge->next)
		{
			b2Contact* contact = edge->contact;
			b2Body* contactBodyA = contact->GetFixtureA()->GetBody();
			b2Body* contactBodyB = contact->GetFixtureB()->GetBody();

			if ((contactBodyA == bodyA && contactBodyB == bodyB) || (contactBodyA == bodyB && contactBodyB == bodyA))
			{
				return true;
			}
		}
	}

	return false;
}


bool World::isContactBetween(b2Body* body1, b2Body* body2, b2Body* checkBodyA, b2Body* checkBodyB) {
	return (body1 == checkBodyA && body2 == checkBodyB) || (body1 == checkBodyB && body2 == checkBodyA);
}

void World::deleteWantedObjects()
{
	for (int i = 0; i < this->m_gameObjects.size(); i++) {
		if (this->m_gameObjects[i]->needToDelete()) {
			this->m_gameObjects.erase(m_gameObjects.begin() + i);
			i--;
		}
	}
}
