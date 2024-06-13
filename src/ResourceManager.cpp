#include "ResourceManager.h"
//=============================================================
// ctor
ResourceManager::ResourceManager()
{
    this->loadImage("PlayButton", "PlayButton.png");
    this->loadImage("SandboxButton", "Sandbox.png");
    this->loadImage("MainWindowBG", "MainWindowBG.png");
    this->loadImage("Candy", "Candy.png");
    this->loadImage("Star", "Star.png");
    this->loadImage("Hat", "Hat.png");
    this->loadImage("Bubble", "Bubble.png");
    this->loadImage("Omnom", "Omnom.png");
    this->loadImage("HorizonalLongSpikes", "HorizonalLongSpikes.png");
    this->loadImage("HorizonalShortSpikes", "HorizonalShortSpikes.png");
    this->loadImage("HorizonalMediumSpikes", "HorizonalMediumSpikes.png");
    this->loadImage("AirPillow", "AirPillow.png");

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
