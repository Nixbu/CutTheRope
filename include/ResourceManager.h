#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>
#include <SFML/Audio.hpp>

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
    void playSound(const std::string& soundName);
    const sf::Font& getFont(const std::string& name) const;
   



private:
    ResourceManager();

    template <typename Resource>
    void loadResource(std::unordered_map<std::string, Resource>& resourceMap, const std::string& name, 
                      const std::string& filename);
    template <>
    void loadResource<  std::shared_ptr<sf::Sound>>(std::unordered_map<std::string, std::shared_ptr<sf::Sound>>& resourceMap,
        const std::string& name, const std::string& filename);

    std::unordered_map<std::string, sf::Texture> m_textures;
    std::unordered_map<std::string, sf::Font> m_fonts;
    std::unordered_map<std::string, ListOfFrames> m_animations;
    std::unordered_map<std::string, std::shared_ptr<sf::Sound>> m_sounds;
    std::unordered_map<std::string, sf::SoundBuffer> m_soundBuffers;

};



