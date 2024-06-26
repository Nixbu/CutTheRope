#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>


using ListOfFrames = std::vector<sf::IntRect>;

/**
 * Represents a manager for loading and retrieving images (textures) for the game.
 */

class ResourceManager {
public:

    static ResourceManager& getInstance();
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    const sf::Texture& getImage(const std::string& name) const;
    const ListOfFrames& getAnimation(const std::string& name) const;
    void loadAnimations();
    void loadAnimation(const std::string& type, int pageGap, int framesCount);

private:

    ResourceManager();
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, ListOfFrames> m_animations;
    void loadImage(const std::string& name, const std::string& filename);

};


