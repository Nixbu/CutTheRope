#include "ResourceManager.h"
//=============================================================
// ctor
ResourceManager::ResourceManager()
{
    this->loadImage("PlayButton", "PlayButton.png");
    this->loadImage("SandboxButton", "Sandbox.png");
    this->loadImage("MainWindowBG", "MainWindowBG.png");
    this->loadImage("LevelSelectionBg", "LevelSelectionBg.png");
    this->loadImage("Candy", "Candy.png");
    this->loadImage("Star", "Star.png");
    this->loadImage("RedHat", "RedHat.png");
    this->loadImage("Bubble", "Bubble.png");
    this->loadImage("Omnom", "EatingAnimation.png");
    this->loadImage("HorizonalLongSpikes", "HorizonalLongSpikes.png"); // TODO change name
    this->loadImage("HorizonalShortSpikes", "HorizonalShortSpikes.png");
    this->loadImage("HorizonalMediumSpikes", "HorizonalMediumSpikes.png");
    this->loadImage("AirPillow", "AirPillowAnimations.png");
    this->loadImage("Hook", "Hook.png");
    this->loadImage("Rope", "RopeSegment.png");
    this->loadImage("Air", "Air.png");
    this->loadImage("betweenLevelBG", "betweenLevelBG.png");
    this->loadImage("ReplayButton", "ReplayButton.png");
    this->loadImage("ReturnToLevelsButton", "ReturnToLevelsButton.png");
    this->loadImage("NextLevelButton", "NextLevelButton.png");
    this->loadImage("GravityButton", "GravityButton.png");
    this->loadImage("LockedLevel", "Locked.png");
    this->loadImage("0Stars", "ZeroStarsLevel.png");
    this->loadImage("1Stars", "OneStarLevel.png");
    this->loadImage("2Stars", "TwoStarsLevel.png");
    this->loadImage("3Stars", "ThreeStarsLevel.png");
    this->loadImage("LevelBackground1", "LevelBackground1.png");
    this->loadImage("LevelBackground2", "LevelBackground2.png");
    this->loadImage("LevelBackground3", "LevelBackground3.png");
    this->loadImage("LevelBackground4", "LevelBackground4.png");
    this->loadImage("LevelBackground5", "LevelBackground5.png");
    this->loadImage("WinBG", "WinBG.png");
    this->loadImage("ReturnButton", "ReturnButton.png");
    this->loadImage("BetweenLevelsBG", "BetweenLevelsBG.png");
    this->loadImage("PlayingToLevelSelectButton", "PlayingToLevelSelectButton.png");
    this->loadImage("ReturnHomeButton", "ReturnHomeButton.png");
    this->loadImage("Chair1", "Chair1.png");
    this->loadImage("Chair2", "Chair2.png");
    this->loadImage("Chair3", "Chair3.png");
    this->loadImage("Chair4", "Chair4.png");
    this->loadImage("Chair5", "Chair5.png");
    this->loadImage("Chair6", "Chair6.png");
    this->loadImage("Chair7", "Chair7.png");
    this->loadImage("Chair8", "Chair8.png");
    this->loadImage("Chair9", "Chair9.png");
    this->loadImage("Chair10", "Chair10.png");
    this->loadImage("Chair11", "Chair11.png");
    this->loadImage("ResetLevelButton", "ResetLevelButton.png");
    this->loadImage("HelpStateBG", "HelpStateBG.png");
    this->loadImage("HelpButton", "HelpButton.png");

    this->loadAnimations();




}
//=============================================================
ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;

}
//=============================================================
// Method to load an image from file
void ResourceManager::loadImage(const std::string& name, const std::string& filename)
{
    sf::Texture texture;

    texture.loadFromFile(filename);   // Exception handling needed
    textures[name] = std::move(texture);


}
//=============================================================
// Method to get a reference to a loaded image
const sf::Texture& ResourceManager::getImage(const std::string& name) const
{
    return textures.at(name);
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
