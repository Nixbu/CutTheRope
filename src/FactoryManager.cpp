#include "FactoryManager.h"
#include "GameObjectFactories/CandyFactory.h"
#include "GameObjectFactories/SpikesFactory.h"


// Singleton instance
FactoryManager& FactoryManager::getInstance() {
    static FactoryManager instance;
    return instance;
}

// Constructor
FactoryManager::FactoryManager() {
    // Initialize with some predefined factory functions
    registerFactory("Candy", std::make_shared<CandyFactory>());
    registerFactory("HorizonalLongSpikes", std::make_shared<SpikesFactory>());

}

// Register a new factory
void FactoryManager::registerFactory(const std::string& typeKey, std::shared_ptr<GameObjectFactory> factory) {
    factoryMap[typeKey] = factory;
}

// Retrieve a factory
std::shared_ptr<GameObjectFactory> FactoryManager::getFactory(const std::string& typeKey) {
    auto it = factoryMap.find(typeKey);
    if (it != factoryMap.end()) {
        return it->second;
    }
    else {
        throw std::runtime_error("No factory registered for the requested type: " + typeKey);
    }
}