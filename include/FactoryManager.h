#pragma once

#include <iostream>
#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include <stdexcept>
#include "GameObjects/GameObject.h"
#include "Settings.h"
#include "box2d/box2d.h"
#include "GameObjectFactories/GameObjectFactory.h"

class CandyFactory;
class HatFactory;
class StarFactory;
class BubbleFactory;
class OmnomFactory;


class FactoryManager {
public:
    static FactoryManager& getInstance();

    void registerFactory(const std::string& typeKey, std::shared_ptr<GameObjectFactory> factory);
    std::shared_ptr<GameObjectFactory> getFactory(const std::string& typeKey);

private:
    FactoryManager();
    FactoryManager(const FactoryManager&) = delete;
    FactoryManager& operator=(const FactoryManager&) = delete;

    std::unordered_map<std::string, std::shared_ptr<GameObjectFactory>> factoryMap;
};

