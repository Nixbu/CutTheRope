#include "FactoryManager.h"

std::shared_ptr<GameObject> FactoryManager::create(const std::string& name,
    const Data& data, b2World& world, const sf::Texture& texture)
{
    auto it = getMap().find(name);
    if (it == getMap().end())
        return nullptr;
    auto createFunc = it->second;

    return createFunc(data, world, texture);
}

bool FactoryManager::registerit(const std::string& name, 
    std::shared_ptr<GameObject>(*f)(const Data& ,
                                   b2World&,
                                    const sf::Texture&))
{
    getMap().emplace(name, f);
    return true;
}
