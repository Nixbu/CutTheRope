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

class World;


typedef std::unordered_map<std::string, std::shared_ptr<GameObject>(*)(const Data&, World&, const sf::Texture&)> FactoryMap; //?
// ================   class Factory   ============================
class FactoryManager {
public:
	static std::shared_ptr<GameObject> create(const std::string& name,
		const Data& data, World& world, const sf::Texture& texture);
	static bool registerit(const std::string& name, 
				std::shared_ptr<GameObject>(*f)(const Data&,
												World&,
											const sf::Texture&));
private:
	static FactoryMap& getMap()
	{
		static FactoryMap m_map;
		return m_map;
	}
};
