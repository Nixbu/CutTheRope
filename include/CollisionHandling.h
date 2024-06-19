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

//TODO create this exception class
// Sample struct for exception throwing
//struct UnknownCollision : public std::runtime_error
//{
//    UnknownCollision(GameObject& a, GameObject& b)
//        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
//    {
//    }
//};

using HitFunctionPtr = void (*)(std::shared_ptr<GameObject>, std::shared_ptr<GameObject>, b2World&);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
// std::unordered_map is better, but it requires defining good hash function for pair
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap();
HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);

void candyBubble(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, b2World& world);

void candyAir(std::shared_ptr<GameObject>candy, std::shared_ptr<GameObject> bubble, b2World& world);


void candyBubble(std::shared_ptr<GameObject>candy, std::shared_ptr<GameObject> bubble, b2World& world);
void candyOmnom(std::shared_ptr<GameObject>candy, std::shared_ptr<GameObject> Omnom, b2World& world);
void candyStar(std::shared_ptr<GameObject>candy, std::shared_ptr<GameObject> Omnom, b2World& world);