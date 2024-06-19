#pragma once

#include "box2d/box2d.h"
#include "GameObjects/GameObject.h"
#include <sstream>
#include "Settings.h"
#include <iostream>
#include "FactoryManager.h"
#include "ResourceManager.h"
#include "CollisionHandling.h"

class World
{
public:
	World();
	void addObject(std::string& line);
	void addToGameObjects(std::shared_ptr<GameObject> object);
	void draw(sf::RenderWindow& window) const;
	void reset();
	void update(float timeStep);
	void handleCollisions();
	void handleClicks(const sf::Vector2f& mousePos);
	b2World& getWorld();
	std::shared_ptr<GameObject> getCandy() const;

private:
	b2World m_physicalWorld;
	std::vector<std::shared_ptr<GameObject>> m_gameObjects;

	bool checkCollision(std::shared_ptr<GameObject> object1,
						std::shared_ptr<GameObject> object2);
	bool isContactBetween(b2Body* body1, b2Body* body2, b2Body* checkBodyA, b2Body* checkBodyB);
	void deleteWantedObjects();
	std::shared_ptr<GameObject> m_candy;
	
};