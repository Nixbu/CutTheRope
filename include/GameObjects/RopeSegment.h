#pragma once

#include "GameObjects/ClickableObject.h"

class RopeSegment : public ClickableObject
{
public:
    RopeSegment(const Data& data, b2World& world, const sf::Texture& texture, const b2Vec2& position);
    virtual void update() override;
    virtual void handleClicked() override;

    // TODO add fading when deleted
    /*bool isFading() const;
    void startFading();*/

private:
    
    // bool m_isFading; TODO add fading when deleted
    //sf::Clock m_fadeClock;
};

