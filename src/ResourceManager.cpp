#include "ResourceManager.h"

//=============================================================
// Constructor
ResourceManager::ResourceManager() {
    loadResource<sf::Texture>(textures, "PlayButton", "PlayButton.png");
    loadResource<sf::Texture>(textures, "SandboxButton", "Sandbox.png");
    loadResource<sf::Texture>(textures, "MainWindowBG", "MainWindowBG.png");
    loadResource<sf::Texture>(textures, "LevelSelectionBg", "LevelSelectionBg.png");
    loadResource<sf::Texture>(textures, "Candy", "Candy.png");
    loadResource<sf::Texture>(textures, "Star", "Star.png");
    loadResource<sf::Texture>(textures, "RedHat", "RedHat.png");
    loadResource<sf::Texture>(textures, "Bubble", "Bubble.png");
    loadResource<sf::Texture>(textures, "Omnom", "Omnom.png");
    loadResource<sf::Texture>(textures, "HorizonalLongSpikes", "HorizonalLongSpikes.png"); // TODO change name
    loadResource<sf::Texture>(textures, "HorizonalShortSpikes", "HorizonalShortSpikes.png");
    loadResource<sf::Texture>(textures, "HorizonalMediumSpikes", "HorizonalMediumSpikes.png");
    loadResource<sf::Texture>(textures, "AirPillow", "AirPillow.png");
    loadResource<sf::Texture>(textures, "Hook", "Hook.png");
    loadResource<sf::Texture>(textures, "Rope", "RopeSegment.png");
    loadResource<sf::Texture>(textures, "Air", "Air.png");
    loadResource<sf::Texture>(textures, "betweenLevelBG", "betweenLevelBG.png");
    loadResource<sf::Texture>(textures, "ReplayButton", "ReplayButton.png");
    loadResource<sf::Texture>(textures, "ReturnToLevelsButton", "ReturnToLevelsButton.png");
    loadResource<sf::Texture>(textures, "NextLevelButton", "NextLevelButton.png");
    loadResource<sf::Texture>(textures, "GravityButton", "GravityButton.png");
    loadResource<sf::Texture>(textures, "LockedLevel", "Locked.png");
    loadResource<sf::Texture>(textures, "0Stars", "ZeroStarsLevel.png");
    loadResource<sf::Texture>(textures, "1Stars", "OneStarLevel.png");
    loadResource<sf::Texture>(textures, "2Stars", "TwoStarsLevel.png");
    loadResource<sf::Texture>(textures, "3Stars", "ThreeStarsLevel.png");
    loadResource<sf::Texture>(textures, "LevelBackground1", "LevelBackground1.png");
    loadResource<sf::Texture>(textures, "LevelBackground2", "LevelBackground2.png");
    loadResource<sf::Texture>(textures, "LevelBackground3", "LevelBackground3.png");
    loadResource<sf::Texture>(textures, "LevelBackground4", "LevelBackground4.png");
    loadResource<sf::Texture>(textures, "LevelBackground5", "LevelBackground5.png");
    loadResource<sf::Texture>(textures, "WinBG", "WinBG.png");
    loadResource<sf::Texture>(textures, "ReturnButton", "ReturnButton.png");
    loadResource<sf::Texture>(textures, "BetweenLevelsBG", "BetweenLevelsBG.png");
    loadResource<sf::Texture>(textures, "PlayingToLevelSelectButton", "PlayingToLevelSelectButton.png");
    loadResource<sf::Texture>(textures, "ReturnHomeButton", "ReturnHomeButton.png");

    loadResource<sf::Font>(m_fonts, "GoodDog", "GOODDC__.TTF");
}

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

template <typename Resource>
void ResourceManager::loadResource(std::unordered_map<std::string, Resource>& resourceMap, 
                                    const std::string& name, const std::string& filename) {
    Resource resource;

    resource.loadFromFile(filename);
    resourceMap[name] = std::move(resource);
}

const sf::Texture& ResourceManager::getImage(const std::string& name) const {
    return textures.at(name);
}

const sf::Font& ResourceManager::getFont(const std::string& name) const {
    return m_fonts.at(name);
}
