#include "Animations/Animation.h"


const auto AnimationTime = sf::seconds(0.08f);

//===================================================================
// Constructs an Animation object with the provided animation data,
// sprite, and looping flag.
//===================================================================
Animation::Animation(const ListOfFrames& data, sf::Sprite& sprite, bool looping)
    : m_data(data), m_sprite(sprite), m_showAnimation(false), m_looping(looping)
{
    update();
}
//===================================================================
// Updates the animation based on elapsed time since the last update.
// Advances to the next frame when appropriate and handles looping
//===================================================================
void Animation::update(sf::Time delta)
{
    if(m_showAnimation)
    {
        m_elapsed += delta;
        if (m_elapsed >= AnimationTime)
        {
            m_elapsed -= AnimationTime;
            ++m_index;
            if (m_index == m_data.size())
            {
                if(!m_looping)
                {
                    m_showAnimation = false;
                }
                m_index = 0;

            }
            update();
        }
    }


}
//===================================================================
void Animation::setAnimationFlag(const bool& flag)
{
    this->m_showAnimation = flag;
}
//===================================================================
void Animation::update()
{
    m_sprite.setTextureRect(m_data[m_index]);
}
