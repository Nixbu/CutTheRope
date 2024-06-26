#pragma once

#include "GameObjects/ClickableObject.h"

class RopeSegment : public ClickableObject
{
public:
    RopeSegment(const Data& data, World& world, const sf::Texture& texture, const b2Vec2& position);
    virtual void update() override;
    virtual void handleClicked() override;
    sf::Vector2f getPosition() const;
    // TODO add fading when deleted
    /*bool isFading() const;
    void startFading();*/

private:
    
    // bool m_isFading; TODO add fading when deleted
    //sf::Clock m_fadeClock;
};

