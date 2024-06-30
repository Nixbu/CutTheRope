#pragma once

#include "GameObjects/ClickableObject.h"
#include <numbers>

class RopeSegment : public ClickableObject
{
public:
    RopeSegment(const Data& data, World& world, const sf::Texture& texture, const b2Vec2& position);
    virtual void handleClicked()  override {};
    virtual bool isClicked(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos) override;

private:
    bool onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) const;
    int orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) const;
    bool doIntersect(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2) const;
    // bool m_isFading; TODO add fading when deleted
    //sf::Clock m_fadeClock;
};

