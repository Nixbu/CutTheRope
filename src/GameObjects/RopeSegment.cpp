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
    fixtureDef.isSensor = true;

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
bool RopeSegment::isClicked(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos) const
{
    sf::Vector2f segmentStartPos = this->getPosition(),
                 sizeSegment = this->getSize();
    float angleSegment = this->getRotationAngle();

    sf::Vector2f segmentEndPos = sf::Vector2f(segmentStartPos.x + sizeSegment.y *
        cos(((90 + angleSegment) * std::numbers::pi) / 180),
        segmentStartPos.y + sizeSegment.y *
        sin(((90 + angleSegment) * std::numbers::pi) / 180));

    if(doIntersect(segmentStartPos, segmentEndPos, mousePos.first, mousePos.second))
    {
        return true;
    }
    return false;
}


bool RopeSegment::onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) const
{
    return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
}

int RopeSegment::orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) const
{
    float val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}
bool RopeSegment::doIntersect(sf::Vector2f p1, sf::Vector2f q1, sf::Vector2f p2, sf::Vector2f q2) const
{
    // Find the four orientations needed for general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case: the segments straddle each other
    if (o1 != o2 && o3 != o4)
        return true;

    // Special cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases 
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
