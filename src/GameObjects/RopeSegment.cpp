#include "GameObjects/RopeSegment.h"

RopeSegment::RopeSegment(const Data& data, World& world, const sf::Texture& texture, const b2Vec2& position)
    : ClickableObject(data, texture)//, m_isFading(false)
{

    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape box;

    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;

    
    box.SetAsBox(texture.getSize().x / SCALE, texture.getSize().y/ SCALE);  // Segment size

    
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;

    this->initBody(world, bodyDef, fixtureDef);
}

void RopeSegment::update()
{
    b2Vec2 position = this->getBody()->GetPosition();
    float angle = this->getBody()->GetAngle();

    // Convert Box2D position (meters) to SFML position (pixels)
    this->setPosition(position.x * SCALE, WINDOW_MANAGER_HEIGHT - position.y * SCALE);
    this->setRotation(angle * 180.0f / b2_pi);

    //TODO Create new method for chcking fading
    //if (m_isFading)
    //{
    //    float elapsed = m_fadeClock.getElapsedTime().asSeconds();
    //    if (elapsed >= 1.0f)
    //    {
    //        m_shape.setFillColor(sf::Color(255, 255, 255, 0));  // Fully transparent
    //        m_toDelete = true;  // Mark for deletion
    //    }
    //    else
    //    {
    //        int alpha = static_cast<int>(255 * (1.0f - elapsed));
    //        m_shape.setFillColor(sf::Color(255, 255, 255, alpha));
    //    }
    //}
}

void RopeSegment::handleClicked()
{
    //startFading();
}
//
//bool RopeSegment::isFading() const
//{
//    return m_isFading;
//}
//
//void RopeSegment::startFading()
//{
//    if (!m_isFading)
//    {
//        m_isFading = true;
//        m_fadeClock.restart();
//    }
//}
