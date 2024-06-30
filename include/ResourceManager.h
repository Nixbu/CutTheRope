#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>
#include <SFML/Audio.hpp>

using ListOfFrames = std::vector<sf::IntRect>;

/**
 * Represents a manager for loading and retrieving images (textures) for the game.
 * it also contains the game music , sounds , and animations.
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
    void playMusic(const std::string& musicName);
    void setMusic(const std::string& musicName);



private:
    ResourceManager();

    template <typename Resource>
    void loadResource(std::unordered_map<std::string, Resource>& resourceMap, const std::string& name, 
                      const std::string& filename);
    template <>
    void loadResource(std::unordered_map<std::string, std::unique_ptr<sf::Sound>>& resourceMap,
        const std::string& name, const std::string& filename)
    {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(filename)) {
            throw std::runtime_error("Failed to load sound buffer from " + filename);
        }

        m_soundBuffers[name] = buffer;
        std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>();
        sound->setBuffer(m_soundBuffers[name]); // Assuming m_soundBuffers is defined elsewhere
        sound->setVolume(100); // Optionally set other properties
        resourceMap[name] = std::move(sound);
    }

    template <>
    void loadResource(std::unordered_map<std::string, std::unique_ptr<sf::Music>>& resourceMap,
        const std::string& name, const std::string& filename) {
        std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
        music->openFromFile(filename);
        resourceMap[name] = std::move(music);
    }

    std::unordered_map<std::string, sf::Texture> m_textures;
    std::unordered_map<std::string, sf::Font> m_fonts;
    std::unordered_map<std::string, ListOfFrames> m_animations;
    std::unordered_map<std::string, sf::SoundBuffer> m_soundBuffers;
    std::unordered_map<std::string, std::unique_ptr<sf::Sound>> m_sounds;
    std::unordered_map<std::string, std::unique_ptr<sf::Music>> m_musics;
};



