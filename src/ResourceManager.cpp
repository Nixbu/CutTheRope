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
    this->loadImage("Omnom", "Omnom.png");
    this->loadImage("HorizonalLongSpikes", "HorizonalLongSpikes.png"); // TODO change name
    this->loadImage("HorizonalShortSpikes", "HorizonalShortSpikes.png");
    this->loadImage("HorizonalMediumSpikes", "HorizonalMediumSpikes.png");
    this->loadImage("AirPillow", "AirPillow.png");
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
