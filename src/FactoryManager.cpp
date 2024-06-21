#include "FactoryManager.h"
#include "World.h"

std::shared_ptr<GameObject> FactoryManager::create(const std::string& name,
    const std::string& line, World& world, const sf::Texture& texture)
{
    auto it = getMap().find(name);
    if (it == getMap().end())
        return nullptr;
    auto createFunc = it->second;

    return createFunc(line, world, texture);
}

bool FactoryManager::registerit(const std::string& name, 
    std::shared_ptr<GameObject>(*f)(const std::string&,
                                   World&,
                                    const sf::Texture&))
{
    getMap().emplace(name, f);
    return true;
}
