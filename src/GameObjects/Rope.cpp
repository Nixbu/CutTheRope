#include "GameObjects/Rope.h"

Rope::Rope(const Data& data, b2World& world, const sf::Texture& texture)
    : ClickableObject(data, texture)
{
    // Convert starting position from pixels to meters
    b2Vec2 currentPosition = b2Vec2(data.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - data.m_pos.y) / SCALE);

    // Define the hook static body
    b2BodyDef hookBodyDef;
    hookBodyDef.position = currentPosition; // Hook position is the same as the start of the rope
    hookBodyDef.type = b2_staticBody;
    b2Body* hookBody = world.CreateBody(&hookBodyDef);

    b2PolygonShape hookShape;
    hookShape.SetAsBox(0.1f, 0.1f); // Define hook size

    b2FixtureDef hookFixtureDef;
    hookFixtureDef.isSensor = true;
    hookFixtureDef.density = 1.0f; // Adjust density as needed
    hookFixtureDef.friction = 0.3f; // Adjust friction as needed
    hookFixtureDef.restitution = 0.5f; // Adjust restitution (bounciness) as needed
    hookFixtureDef.shape = &hookShape;

    hookBody->CreateFixture(&hookFixtureDef);

    // Define the number of segments
    int segmentCount = 80; // Replace with desired segment count or parameter

    for (int i = 0; i < segmentCount; ++i)
    {
        // Create a new segment at the current position
        auto segment = std::make_shared<RopeSegment>(data, world, texture, currentPosition);

        // If there are already segments in the rope, join the new one to the previous one
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
        else
        {
            // Connect the first segment to the hook
            b2RevoluteJointDef hookJointDef;
            hookJointDef.bodyA = hookBody;
            hookJointDef.bodyB = segment->getBody();
            hookJointDef.localAnchorA.Set(0.0f, 0.1f);
            hookJointDef.localAnchorB.Set(0.0f, -0.1f);
            hookJointDef.collideConnected = false;

            world.CreateJoint(&hookJointDef);
        }

        // Add the new segment to the list of segments
        m_segments.push_back(std::move(segment));

        // Increment the y position for the next segment
        currentPosition.y -= 0.5f;  // Adjust as necessary for spacing
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