#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>

/**
 * Represents a manager for loading and retrieving images (textures) for the game.
 */

class ResourceManager {
public:

    static ResourceManager& getInstance();
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    const sf::Texture& getImage(const std::string& name) const;

private:

    ResourceManager();
    std::unordered_map<std::string, sf::Texture> textures;

    void loadImage(const std::string& name, const std::string& filename);

};


