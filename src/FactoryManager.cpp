#include "FactoryManager.h"
#include "World.h"


//======================================================
// Create Function
// Creates a GameObject based on the registered factory function for the given name.
//======================================================
std::shared_ptr<GameObject> FactoryManager::create(const std::string& name,
    const std::string& line, World& world, const sf::Texture& texture)
{
    auto it = getMap().find(name);
    if (it == getMap().end())
        return nullptr;
    auto createFunc = it->second;

    return createFunc(line, world, texture);
}
//======================================================
// Registerit Function
// Registers a factory function for creating GameObjects with a specific name.
//======================================================
bool FactoryManager::registerit(const std::string& name, 
    std::shared_ptr<GameObject>(*f)(const std::string&,
                                   World&,
                                    const sf::Texture&))
{
    getMap().emplace(name, f);
    return true;
}
