#pragma once

#include "box2d/box2d.h"
#include "GameObjects/GameObject.h"
#include <sstream>
#include "Settings.h"
#include <iostream>
#include "FactoryManager.h"
#include "ResourceManager.h"
#include "CollisionHandling.h"
#include <string>


// class World
/*======================================================================================
The World class serves as the central manager for the game world in this "Cut the Rope" game 
 It handles the overall object state and behavior of the game using box2d, 
including managing game objects, updating the game physics, handling user input, and checking for collisions. 
======================================================================================*/

class World
{
public:
	World();
	void addObject(std::string& line);
	void addToGameObjects(std::unique_ptr<GameObject>&& object);
	void draw(sf::RenderWindow& window) const;
	void reset();
	void update(float timeStep, sf::Time& deltaTime);
	void handleCollisions();
	void handleClicks(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos);
	b2World& getWorld();
	std::unique_ptr<GameObject>& getCandy();
	void setLevelStatus(const levelStatus_t& status);
	void addStar();
	void resetGravity();
	int getStars()const;
	void setStarsToZero();
	levelStatus_t getLevelStatus()const;
	void restartClock();
	double getTime() const;
	void deleteCandy();

private:
	int m_stars;
	levelStatus_t m_levelStatus;
	b2World m_physicalWorld;
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	sf::Clock m_animationClock;
	std::unique_ptr<GameObject> m_candy;

	bool checkCollision(GameObject& object1, GameObject& object2);
	bool isContactBetween(b2Body* body1, b2Body* body2, b2Body* checkBodyA, b2Body* checkBodyB);
	void deleteWantedObjects();
	void validCandyPos();
};