#include "World.h"


World::World(levelStatus_t& status, int& stars) :
	m_physicalWorld(b2Vec2(GRAVITY_WORLD.x, GRAVITY_WORLD.y)), m_candy(nullptr), m_status(status), m_stars(stars)
{
	m_gameObjects.reserve(MAX_SIZE);
}

void World::addObject(std::string& line)
{
	try {
		auto& resourceManager = ResourceManager::getInstance();

		std::istringstream iss(line);
		std::string type, subtype;

		iss >> type >> subtype;

		const sf::Texture& texture = resourceManager.getImage(subtype);

		std::shared_ptr<GameObject> object = FactoryManager::create(type, line,
			*this, texture);

		if (object != nullptr)
		{
			if (type == "Candy") {
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
	this->m_candy = nullptr;
}

void World::update(float timeStep, sf::Time& deltaTime)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2; // TODO change to constants

	// Step the physics world
	m_physicalWorld.Step(timeStep, velocityIterations, positionIterations);

	// Update all game objects to match their physics bodies
	for (auto& object : m_gameObjects) {
		object->update(deltaTime);
	}

	this->validCandyPos();
	this->deleteWantedObjects();
}

void World::handleCollisions()
{
	for (int index1 = 0; index1 < this->m_gameObjects.size(); index1++)
	{
		if(this->checkCollision(m_candy, m_gameObjects[index1]))
		{
			auto collisionsFunc = lookup(typeid(*m_candy), typeid(*m_gameObjects[index1]));

			if (collisionsFunc != nullptr)
			{
				collisionsFunc(m_candy, m_gameObjects[index1], *this);
			}
		
		}
	}
}

void World::handleClicks(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos)
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

void World::setLevelStatus(const levelStatus_t& status)
{
	this->m_status = status;
}

void World::addStar()
{
	this->m_stars++;
}

void World::resetGravity()
{
	b2Vec2 gravity = this->m_physicalWorld.GetGravity();
	if (gravity.y > 0) {
		gravity.y *= -1;
		this->m_physicalWorld.SetGravity(gravity);
	}
}

int World::getStars()const
{
	return this->m_stars;
}

void World::setStarsToZero()
{
	this->m_stars = 0;
}

levelStatus_t World::getLevelStatus() const
{
	return this->m_status;
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

void World::validCandyPos()
{
	if (this->m_candy) {
		sf::Vector2f candyPos = this->m_candy->getPosition();

		sf::FloatRect localBounds = this->m_candy->getSprite().getLocalBounds();
		float candyWidth = localBounds.width;
		float candyHeight = localBounds.height;

		if (candyPos.y > WINDOW_MANAGER_HEIGHT + 100 || candyPos.x < 0 - candyWidth ||
			candyPos.x > WINDOW_MANAGER_WIDTH + candyWidth ||
			candyPos.y < 0 - candyHeight) {
			this->m_status = Lost;
		}
	}
	else
	{
		this->m_status = Lost;
	}

}
