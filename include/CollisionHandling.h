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


using HitFunctionPtr = void (*)(std::shared_ptr<GameObject>, std::shared_ptr<GameObject>, World&);

using Key = std::pair<std::type_index, std::type_index>;

using HitMap = std::map<Key, HitFunctionPtr>;

HitMap initializeCollisionMap();
HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);


void candyAir(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyBubble(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyOmnom(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyStar(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candySpikes(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);
void candyHat(std::shared_ptr<GameObject>object1, std::shared_ptr<GameObject> object2, World& world);