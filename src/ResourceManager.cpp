#include "ResourceManager.h"

//=============================================================
// Constructor
ResourceManager::ResourceManager() {
    loadResource<sf::Texture>(m_textures, "PlayButton", "PlayButton.png");
    loadResource<sf::Texture>(m_textures, "SandboxButton", "Sandbox.png");
    loadResource<sf::Texture>(m_textures, "MainWindowBG", "MainWindowBG.png");
    loadResource<sf::Texture>(m_textures, "LevelSelectionBg", "LevelSelectionBg.png");
    loadResource<sf::Texture>(m_textures, "Candy", "Candy.png");
    loadResource<sf::Texture>(m_textures, "Star", "Star.png");
    loadResource<sf::Texture>(m_textures, "RedHat", "RedHat.png");
    loadResource<sf::Texture>(m_textures, "Bubble", "Bubble.png");
    loadResource<sf::Texture>(m_textures, "Omnom", "EatingAnimation.png");
    loadResource<sf::Texture>(m_textures, "HorizonalLongSpikes", "HorizonalLongSpikes.png"); // TODO change name
    loadResource<sf::Texture>(m_textures, "HorizonalShortSpikes", "HorizonalShortSpikes.png");
    loadResource<sf::Texture>(m_textures, "HorizonalMediumSpikes", "HorizonalMediumSpikes.png");
    loadResource<sf::Texture>(m_textures, "AirPillow", "AirPillowAnimations.png");
    loadResource<sf::Texture>(m_textures, "Hook", "Hook.png");
    loadResource<sf::Texture>(m_textures, "Rope", "RopeSegment.png");
    loadResource<sf::Texture>(m_textures, "Air", "Air.png");
    loadResource<sf::Texture>(m_textures, "betweenLevelBG", "betweenLevelBG.png");
    loadResource<sf::Texture>(m_textures, "ReplayButton", "ReplayButton.png");
    loadResource<sf::Texture>(m_textures, "ReturnToLevelsButton", "ReturnToLevelsButton.png");
    loadResource<sf::Texture>(m_textures, "NextLevelButton", "NextLevelButton.png");
    loadResource<sf::Texture>(m_textures, "GravityButton", "GravityButton.png");
    loadResource<sf::Texture>(m_textures, "LockedLevel", "Locked.png");
    loadResource<sf::Texture>(m_textures, "0Stars", "ZeroStarsLevel.png");
    loadResource<sf::Texture>(m_textures, "1Stars", "OneStarLevel.png");
    loadResource<sf::Texture>(m_textures, "2Stars", "TwoStarsLevel.png");
    loadResource<sf::Texture>(m_textures, "3Stars", "ThreeStarsLevel.png");
    loadResource<sf::Texture>(m_textures, "LevelBackground1", "LevelBackground1.png");
    loadResource<sf::Texture>(m_textures, "LevelBackground2", "LevelBackground2.png");
    loadResource<sf::Texture>(m_textures, "LevelBackground3", "LevelBackground3.png");
    loadResource<sf::Texture>(m_textures, "LevelBackground4", "LevelBackground4.png");
    loadResource<sf::Texture>(m_textures, "LevelBackground5", "LevelBackground5.png");
    loadResource<sf::Texture>(m_textures, "WinBG", "WinBG.png");
    loadResource<sf::Texture>(m_textures, "ReturnButton", "ReturnButton.png");
    loadResource<sf::Texture>(m_textures, "BetweenLevelsBG", "BetweenLevelsBG.png");
    loadResource<sf::Texture>(m_textures, "PlayingToLevelSelectButton", "PlayingToLevelSelectButton.png");
    loadResource<sf::Texture>(m_textures, "ReturnHomeButton", "ReturnHomeButton.png");

    loadResource<sf::Texture>(m_textures, "Chair1", "Chair1.png");
    loadResource<sf::Texture>(m_textures, "Chair2", "Chair2.png");
    loadResource<sf::Texture>(m_textures, "Chair3", "Chair3.png");
    loadResource<sf::Texture>(m_textures, "Chair4", "Chair4.png");
    loadResource<sf::Texture>(m_textures, "Chair5", "Chair5.png");
    loadResource<sf::Texture>(m_textures, "Chair6", "Chair6.png");
    loadResource<sf::Texture>(m_textures, "Chair7", "Chair7.png");
    loadResource<sf::Texture>(m_textures, "Chair8", "Chair8.png");
    loadResource<sf::Texture>(m_textures, "Chair9", "Chair9.png");
    loadResource<sf::Texture>(m_textures, "Chair10", "Chair10.png");
    loadResource<sf::Texture>(m_textures, "Chair11", "Chair11.png");
    loadResource<sf::Texture>(m_textures, "ResetLevelButton", "ResetLevelButton.png");
    loadResource<sf::Texture>(m_textures, "HelpStateBG", "HelpStateBG.png");
    loadResource<sf::Texture>(m_textures, "HelpButton", "HelpButton.png");

    loadResource<sf::Font>(m_fonts, "GoodDog", "GOODDC__.TTF");


    this->loadAnimations();

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
    return m_textures.at(name);
}

const sf::Font& ResourceManager::getFont(const std::string& name) const {
    return m_fonts.at(name);
}

const ListOfFrames& ResourceManager::getAnimation(const std::string& name) const
{
    return m_animations.at(name);
}

void ResourceManager::loadAnimations()
{
    this->loadAnimation("AirPillow", 160, 6);
    this->loadAnimation("Omnom", 102, 34);
}

void ResourceManager::loadAnimation(const std::string& type, int pageGap, int framesCount)
{

    auto texture = this->getImage(type);
    auto width = static_cast<int>(texture.getSize().x);

    sf::Vector2i currPos = { 0 , 0 },
        currSize = { width, pageGap };

    
    for (int idx = 0; idx < framesCount; idx++)
    {
        m_animations[type].emplace_back(currPos, currSize);
        currPos.y += pageGap;
    }

}
