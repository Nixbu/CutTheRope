#include "GameObjects/Rope.h"

Rope::Rope(const Data& data, b2World& world, const sf::Texture& texture)// TODO?, int segmentCount)
    : ClickableObject(data, texture)
{
    
    b2Vec2 currentPosition = b2Vec2(data.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - data.m_pos.y) / SCALE); // ? - SCALE

    //TODO Add segment count instead of 7?
    for (int i = 0; i < 7; ++i)
    {
        auto segment = std::make_shared<RopeSegment>(data, world, texture, currentPosition);
        if (!m_segments.empty())
        {
            b2RevoluteJointDef jointDef;
            jointDef.bodyA = m_segments.back()->getBody();
            jointDef.bodyB = segment->getBody();
            jointDef.localAnchorA.Set(0.0f, 0.1f);
            jointDef.localAnchorB.Set(0.0f, -0.1f);
            jointDef.collideConnected = false;

            world.CreateJoint(&jointDef);
        }

        m_segments.push_back(std::move(segment));
        currentPosition.y += 0.2f;  // Adjust as necessary for spacing
    }
}

void Rope::update()
{
    for (auto& segment : m_segments)
    {
        segment->update();
    }
    //// Remove segments marked for deletion
    //m_segments.erase(
    //    std::remove_if(m_segments.begin(), m_segments.end(),
    //        [](const std::unique_ptr<RopeSegment>& segment) { return segment->needToDelete(); }),
    //    m_segments.end());
}

void Rope::handleClicked()
{
    // TODO Add fading and delete when clicked

    /*bool startFade = false;
    for (auto& segment : m_segments)
    {
        if (segment->isClicked(mousePos))
        {
            startFade = true;
        }
        if (startFade)
        {
            segment->startFading();
        }
    }*/
}

void Rope::draw(sf::RenderWindow& window) const
{
    for (const auto& segment : m_segments)
    {
        segment->draw(window);
    }
}

bool Rope::m_registerit = FactoryManager::registerit("Rope",
    &RopeFactory::createObject);