#include "World.h"

// Constructor for World class.
// Initializes the level status, stars count, physical world with gravity, and candy pointer.
World::World() : m_levelStatus(OnGoing) , m_stars(0) ,
	m_physicalWorld(b2Vec2(GRAVITY_WORLD.x, GRAVITY_WORLD.y)), m_candy(nullptr)
{
	m_gameObjects.reserve(MAX_SIZE);
}

//======================================================================
// Adds an object to the game world from a string line.
// Throws an error if the object cannot be created.
//======================================================================
void World::addObject(std::string& line)
{
		auto& resourceManager = ResourceManager::getInstance();

		std::istringstream iss(line);
		std::string type, subtype;

		iss >> type >> subtype;

		const sf::Texture& texture = resourceManager.getImage(subtype);

		std::unique_ptr<GameObject> object = FactoryManager::create(type, line,
			*this, texture);

		if (object != nullptr)
		{
			if (type == "Candy") {
				this->m_candy = std::move(object);
			}
			else
			{
				this->m_gameObjects.push_back(std::move(object));
			}
		}
		else
		{
			throw std::runtime_error("Error: Cannot add object");
		}
}
//======================================================================
// Adds a shared pointer to a GameObject to the game objects vector.
//======================================================================
void World::addToGameObjects(std::unique_ptr<GameObject> object)
{
	this->m_gameObjects.emplace_back(std::move(object));
}
//======================================================================
// Draws all game objects in the world to the provided window.
//======================================================================
void World::draw(sf::RenderWindow& window) const 
{
	for (auto it = this->m_gameObjects.rbegin(); it != this->m_gameObjects.rend(); ++it)
	{
		(*it)->draw(window);
	}
}
//======================================================================
// Resets the game world by clearing the game objects vector and
//  setting the candy pointer to null.
//======================================================================
void World::reset()
{
	this->m_gameObjects.clear();
	this->m_candy = nullptr;
}
//======================================================================
// Updates the game world by stepping the physics world and updating all game objects.
//======================================================================
void World::update(float timeStep, sf::Time& deltaTime)
{
	int32 velocityIterations = 6;
	int32 positionIterations = 2; 
	// Step the physics world
	m_physicalWorld.Step(timeStep, velocityIterations, positionIterations);

	// Update all game objects to match their physics bodies
	for (auto& object : m_gameObjects) {
		object->update(deltaTime);
	}

	this->validCandyPos();
	this->deleteWantedObjects();
}
//======================================================================
// Handles collisions between the candy and other game objects.
//======================================================================
void World::handleCollisions()
{
	
	for (int index1 = 0; index1 < this->m_gameObjects.size(); index1++)
	{
		if (this->m_candy)
		{
			if (this->checkCollision(*m_candy, *m_gameObjects[index1]))
			{
				auto collisionsFunc = lookup(typeid(*m_candy), typeid(*m_gameObjects[index1]));

				if (collisionsFunc != nullptr)
				{
					collisionsFunc(*m_candy, *m_gameObjects[index1], *this);
				}

			}
		}
	}
}

void World::handleClicks(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos)
{
	for (auto& object : this->m_gameObjects)
	{
		try {
			auto& clickable = dynamic_cast<ClickableObject&>(*object);
			if (clickable.isClicked(mousePos))
			{
				clickable.handleClicked();
			}
		}
		catch (const std::bad_cast& e) {
			// Handle the case where the cast fails, if needed
		}
	}

	this->deleteWantedObjects();
}
//======================================================================
b2World& World::getWorld()
{
	return this->m_physicalWorld;
}
//======================================================================
GameObject* World::getCandy()
{
	if (this->m_candy) {
		return this->m_candy.get();
	}
	return nullptr;
}
//======================================================================
void World::setLevelStatus(const levelStatus_t& status)
{
	this->m_levelStatus = status;
}
//======================================================================
void World::addStar()
{
	if (this->m_stars < 3) {
		this->m_stars++;
	}	
}
//======================================================================
void World::resetGravity()
{
	b2Vec2 gravity = this->m_physicalWorld.GetGravity();
	if (gravity.y > 0) {
		gravity.y *= -1;
		this->m_physicalWorld.SetGravity(gravity);
	}
}
//======================================================================
int World::getStars()const
{
	return this->m_stars;
}
//======================================================================
void World::setStarsToZero()
{
	this->m_stars = 0;
}
//======================================================================
levelStatus_t World::getLevelStatus() const
{
	return this->m_levelStatus;
}
//======================================================================
void World::restartClock()
{
	this->m_animationClock.restart();
}
//======================================================================
double World::getTime() const
{
	return this->m_animationClock.getElapsedTime().asSeconds();
}

//======================================================================
// Checks if two game objects are colliding.
//======================================================================
bool World::checkCollision(GameObject& object1, GameObject& object2)
{
	b2Body* bodyB = object2.getBody();
	b2Body* bodyA = object1.getBody();
	

	if (bodyA && bodyB)
	{
		// Check contacts of the bodies
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
//======================================================================
// Checks if a contact is between two specified bodies.
//======================================================================
bool World::isContactBetween(b2Body* body1, b2Body* body2, b2Body* checkBodyA, b2Body* checkBodyB) {
	return (body1 == checkBodyA && body2 == checkBodyB) || (body1 == checkBodyB && body2 == checkBodyA);
}
//======================================================================
// Deletes game objects that are marked for deletion.
//======================================================================
void World::deleteWantedObjects()
{
	for (int i = 0; i < this->m_gameObjects.size(); i++) {
		if (this->m_gameObjects[i]->needToDelete()) {
			this->m_gameObjects.erase(m_gameObjects.begin() + i);
			i--;
		}
	}
}
//========================================================================
// Validates the position of the candy object and sets the 
// level status to Lost if it is out of bounds.
//======================================================================
void World::validCandyPos()
{
	if (this->m_levelStatus == OnGoing) {
		if (this->m_candy) {
			sf::Vector2f candyPos = this->m_candy->getPosition();

			sf::FloatRect localBounds = this->m_candy->getSprite().getLocalBounds();
			float candyWidth = localBounds.width;
			float candyHeight = localBounds.height;

			if (candyPos.y > WINDOW_MANAGER_HEIGHT + 100 || candyPos.x < 0 - candyWidth ||
				candyPos.x > WINDOW_MANAGER_WIDTH + candyWidth ||
				candyPos.y < 0 - candyHeight) {
				this->m_levelStatus = Lost;
			}
		}
		else
		{
			this->m_levelStatus = Lost;
		}
	}


}
void World::deleteCandy()
{
	m_candy = nullptr;
}