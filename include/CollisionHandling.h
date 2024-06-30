#pragma once

#include "GameObjects/GameObject.h"
#include <typeinfo>
#include <typeindex>
#include <map>
#include "GameObjects/Candy.h"
#include "GameObjects/Bubble.h"
#include "GameObjects/Omnom.h"
#include "GameObjects/Star.h"
#include "GameObjects/Air.h"
#include "GameObjects/Spikes.h"
#include "World.h"
#include "GameObjects/DoubleHat.h"

/*
   The CollisionHandler manages collision functions between different types of GameObjects.
   It uses a map of type pairs to function pointers for handling collisions.
*/

//TODO create this exception class
// Sample struct for exception throwing
//struct UnknownCollision : public std::runtime_error
//{
//    UnknownCollision(GameObject& a, GameObject& b)
//        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
//    {
//    }
//};

using HitFunctionPtr = void (*)(std::shared_ptr<GameObject>, std::shared_ptr<GameObject>, World&);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
// std::unordered_map is better, but it requires defining good hash function for pair
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap();
HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);


void candyAir(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyBubble(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyOmnom(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyStar(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candySpikes(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyHat(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);