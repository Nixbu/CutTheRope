#pragma once

#include "ResourceManager.h"


#include <SFML/Graphics.hpp>

using ListOfFrames = std::vector<sf::IntRect>;

class Animation
{
public:
    Animation(const ListOfFrames& data, sf::Sprite& sprite, bool looping);

    // Add more time to the elapsed time; if enough time passed, it
    // updates the sprite to show the next frame in the animation
    void update(sf::Time delta);
    void setAnimationFlag(const bool& flag);

private:
    // Update the sprite to take the correct part of the texture,
    // based on current dir and index
    void update();

    ListOfFrames m_data;
    sf::Time m_elapsed = {};
    int m_index = 0;
    sf::Sprite& m_sprite;
    bool m_showAnimation,
        m_looping;
};
