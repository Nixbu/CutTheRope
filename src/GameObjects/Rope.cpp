#include "GameObjects/Rope.h"

Rope::Rope(const Data& data, World& world, const sf::Texture& texture)
    : ClickableObject(data, texture)
{
    auto& manager = ResourceManager::getInstance();
    const sf::Texture&  hookTexture = manager.getImage("Hook");
    // Convert starting position from pixels to meters

    b2Vec2 currentPosition = b2Vec2(data.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - data.m_pos.y) / SCALE);

    // Define the hook static body
    this->m_hook = std::make_unique<Hook>(data, world, hookTexture); // TODO change texture

    // Define the number of segments
    int segmentCount = 20; // Replace with desired segment count or parameter

    for (int i = 0; i < segmentCount; ++i)
    {
        // Create a new segment at the current position
        auto segment = std::make_shared<RopeSegment>(data, world, texture, currentPosition);

        // If there are already segments in the rope, join the new one to the previous one
        if (!m_segments.empty())
        {
            addSegment(world, segment);
        }
        else
        {
            connectToHook(world, segment);
        }


        // Add the new segment to the list of segments
        m_segments.push_back(std::move(segment));

        // Increment the y position for the next segment
        currentPosition.y -= 0.5f;  // Adjust as necessary for spacing
    }

    this->connectToCandy(world);
}

void Rope::update()
{
    for (auto& segment : m_segments)
    {
        segment->update();
    }

    this->m_hook->update();
    ////
    //  Remove segments marked for deletion
    //m_segments.erase(
    //    std::remove_if(m_segments.begin(), m_segments.end(),
    //        [](const std::unique_ptr<RopeSegment>& segment) { return segment->needToDelete(); }),
    //    m_segments.end());
}

void Rope::handleClicked()
{
    this->setDelete();
}

void Rope::draw(sf::RenderWindow& window) const
{
    for (const auto& segment : m_segments)
    {
        segment->draw(window);
    }
    this->m_hook->draw(window);
}

bool Rope::isClicked(const sf::Vector2f& mousePos) const
{
    for (const auto& segment : this->m_segments) {
        if (segment->isClicked(mousePos)) {
            return true;
        }
    }
    return false;
}

void Rope::connectToCandy(World& world )
{
    b2Body* lastSegmentBody = this->m_segments.back()->getBody();

    // Define a revolute joint to connect the last segment to the candy
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = lastSegmentBody;
    jointDef.bodyB = world.getCandy()->getBody();
    jointDef.localAnchorA.Set(0.0f, -0.1f); // Adjust as needed
    jointDef.localAnchorB.Set(0.0f, 0.1f);  // Adjust as needed
    jointDef.collideConnected = false;

    // Create the joint
    world.getWorld().CreateJoint(&jointDef);
}

void Rope::addSegment(World& world, std::shared_ptr<RopeSegment> segment)
{
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = m_segments.back()->getBody();
    jointDef.bodyB = segment->getBody();
    jointDef.localAnchorA.Set(0.0f, 0.1f);
    jointDef.localAnchorB.Set(0.0f, -0.1f);
    jointDef.collideConnected = false;

    world.getWorld().CreateJoint(&jointDef);
}

void Rope::connectToHook(World& world , std::shared_ptr<RopeSegment> segment)
{
    // Connect the first segment to the hook
    b2RevoluteJointDef hookJointDef;
    hookJointDef.bodyA = this->m_hook->getBody();
    hookJointDef.bodyB = segment->getBody();
    hookJointDef.localAnchorA.Set(0.0f, 0.1f);
    hookJointDef.localAnchorB.Set(0.0f, -0.1f);
    hookJointDef.collideConnected = false;

    world.getWorld().CreateJoint(&hookJointDef);
}

bool Rope::m_registerit = FactoryManager::registerit("Rope",
    &RopeFactory::createObject);