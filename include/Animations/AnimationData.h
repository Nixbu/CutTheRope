#pragma once

#include "Settings.h"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <vector>

struct AnimationData
{
    using ListOfFrames = std::vector<sf::IntRect>;
    using AnimationType = std::unordered_map<AnimationType, ListOfFrames>;
    DataType m_data;
};
