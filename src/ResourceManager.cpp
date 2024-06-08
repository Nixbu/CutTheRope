#include "ResourceManager.h"
//=============================================================
// ctor
ResourceManager::ResourceManager()
{
    this->loadImage("PlayButton", "PlayButton.png");
    this->loadImage("LoadButton", "LoadButton.png");
    this->loadImage("ExitButton", "ExitButton.png");
    this->loadImage("Background", "Background.png");
    this->loadImage("WinImage", "EndScreenWin.png");
    this->loadImage("LoseImage", "EndScreenLose.png");
    this->loadImage("HintButton", "HintButton.png");
    this->loadImage("SaveButton", "SaveButton.png");
    this->loadImage("GameBackground", "GameBackground.png");



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
