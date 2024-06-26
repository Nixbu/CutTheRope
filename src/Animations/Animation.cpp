#include "Animations/Animation.h"


const auto AnimationTime = sf::seconds(0.08f);

Animation::Animation(const ListOfFrames& data, sf::Sprite& sprite, bool& animationFlag)
    : m_data(data), m_sprite(sprite), m_animationFlag(animationFlag)
{
    m_sprite.setTexture(ResourceManager::getInstance().getImage("AirPillow"));
    update();
}

void Animation::update(sf::Time delta)
{
    if(m_animationFlag)
    {
        m_elapsed += delta;
        if (m_elapsed >= AnimationTime)
        {
            m_elapsed -= AnimationTime;
            ++m_index;
            if (m_index == m_data.size())
            {
                m_animationFlag = false;
                m_index = 0;
            }
            update();
        }
    }


}

void Animation::update()
{
    m_sprite.setTextureRect(m_data[m_index]);
}
