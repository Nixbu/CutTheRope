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

using HitFunctionPtr = void (*)(GameObject& object1, GameObject& object2, World& world);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap();
HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);


void candyAir(GameObject& object1, GameObject& object2, World& world);
void candyBubble(GameObject& object1, GameObject& object2, World& world);
void candyOmnom(GameObject& object1, GameObject& object2, World& world);
void candyStar(GameObject& object1, GameObject& object2, World& world);
void candySpikes(GameObject& object1, GameObject& object2, World& world);
void candyHat(GameObject& object1, GameObject& object2, World& world);