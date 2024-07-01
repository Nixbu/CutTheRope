#include "GameObjects/Rope.h"

//===================================================================
// types of ropes
//===================================================================
std::unordered_map<std::string, unsigned int> Rope::m_ropeLengthsMap = {
    {"longRope", 60},
    {"mediumRope", 40},
    {"shortRope", 20}
};
//===================================================================
// Constructs a Rope object based on provided data and initializes its
// segments, connecting them with joints, and linking them to a hook.
//===================================================================
Rope::Rope(const Data& data, World& world, const sf::Texture& texture)
    : ClickableObject(data, texture)
{
   
    auto& manager = ResourceManager::getInstance();
    const sf::Texture&  hookTexture = manager.getImage("Hook");

    b2Vec2 currentPosition = b2Vec2(data.m_pos.x / SCALE,
        (WINDOW_MANAGER_HEIGHT - data.m_pos.y) / SCALE);

    // Define the hook static body
    this->m_hook = std::make_unique<Hook>(data, world, hookTexture); 

    // Define the number of segments
    int segmentCount = m_ropeLengthsMap[data.m_length]; 

    for (int i = 0; i < segmentCount; ++i)
    {
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

        m_segments.push_back(std::move(segment));

        // Increment the y position for the next segment
        currentPosition.y -= 0.005f;
    }

    // connect the last segment to the candy object
    this->connectToCandy(world);
}
//===================================================================
// Updates the positions and states of all rope segments and the hook.
//===================================================================
void Rope::update(sf::Time& deltaTime)
{
    for (auto& segment : m_segments)
    {
        segment->update(deltaTime);
    }

    this->m_hook->update(deltaTime);
}
//===================================================================
// Sets the rope to be deleted when clicked.
//===================================================================
void Rope::handleClicked()
{
    this->setDelete();
}
//===================================================================
// Draws all rope segments and the hook to the specified SFML window.
//===================================================================
void Rope::draw(sf::RenderWindow& window) const
{
    for (const auto& segment : m_segments)
    {
        segment->draw(window);
    }
    this->m_hook->draw(window);
}
//===================================================================
// Checks if a given mouse position intersects with any rope segment.
// Plays a rope cut sound if a segment is clicked
//===================================================================
bool Rope::isClicked(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos)
{
    for (const auto& segment : this->m_segments) 
    {
        if (segment->isClicked(mousePos)) 
        {
            ResourceManager::getInstance().playSound("RopeCut");
            return true;
        }
    }
    return false;
}
//===================================================================
// Connects the last rope segment to the candy object with a revolute joint.
//===================================================================
void Rope::connectToCandy(World& world )
{
    b2Body* lastSegmentBody = this->m_segments.back()->getBody();

    // Define a revolute joint to connect the last segment to the candy
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = lastSegmentBody;
    auto candy = world.getCandy();
    if(candy)
    {
        auto candyBody = candy->getBody();
        jointDef.bodyB = candy->getBody();
    }
    else
    {
        
    }
    jointDef.localAnchorA.Set(0.0f, -0.1f); 
    jointDef.localAnchorB.Set(0.0f, 0.1f);  
    jointDef.collideConnected = false;

    world.getWorld().CreateJoint(&jointDef);
}
//===================================================================
// Adds a new rope segment to the rope and connects it to the last segment with a revolute joint.
//===================================================================
void Rope::addSegment(World& world, std::shared_ptr<RopeSegment> segment)
{
    auto lastSegment = m_segments.back();
    b2Vec2 lastSegmentPosition = lastSegment->getBody()->GetPosition();
    b2Vec2 newSegmentPosition(lastSegmentPosition.x, lastSegmentPosition.y - 0.005f);
    segment->getBody()->SetTransform(newSegmentPosition, 0.0f);

    // Define a revolute joint to connect the new segment to the last segment
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = lastSegment->getBody();
    jointDef.bodyB = segment->getBody();
    jointDef.localAnchorA.Set(0.0f, 0.1f);
    jointDef.localAnchorB.Set(0.0f, -0.1f);
    jointDef.collideConnected = false;

    world.getWorld().CreateJoint(&jointDef);

    m_segments.push_back(segment);
}
//===================================================================
//Connects the first rope segment to the hook with a revolute joint.
//===================================================================
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

//===================================================================
// register the rope to the factory
bool Rope::m_registerit = FactoryManager::registerit("Rope",
    &RopeFactory::createObject);