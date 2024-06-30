#include "CollisionHandling.h"
#include <thread>
#include <chrono>
#include <stdexcept>


HitMap initializeCollisionMap()
{
    HitMap collisionMap;
    collisionMap[Key(typeid(Candy), typeid(Bubble))] = &candyBubble;
    collisionMap[Key(typeid(Candy), typeid(Air))] = &candyAir;
    collisionMap[Key(typeid(Candy), typeid(Omnom))] = &candyOmnom;
    collisionMap[Key(typeid(Candy), typeid(Star))] = &candyStar;
    collisionMap[Key(typeid(Candy), typeid(Spikes))] = &candySpikes;
    collisionMap[Key(typeid(Candy), typeid(DoubleHat))] = &candyHat;

    return collisionMap;
}

HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

void candyBubble(std::unique_ptr<GameObject> object1, std::unique_ptr<GameObject> object2, World& world)
{
     std::unique_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
     std::unique_ptr<Bubble> bubble = std::dynamic_pointer_cast<Bubble>(object2);
     
     ResourceManager::getInstance().playSound("CandyToBubble");
     
    bubble->changeToDynamic();
    candy->SetLinearVelocity(BUBBLE_VELOCITY);



    b2WeldJointDef weldJointDef;
    weldJointDef.bodyA = bubble->getBody();
    weldJointDef.bodyB = candy->getBody();
    weldJointDef.localAnchorA.Set(0, 0);
    weldJointDef.localAnchorB.Set(0, 0);


    world.getWorld().CreateJoint(&weldJointDef);

    std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_DELAY_MS));

}
void candyOmnom(std::unique_ptr<GameObject> object1, std::unique_ptr<GameObject> object2, World& world)
{
    std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
    std::shared_ptr<Omnom> omnom = std::dynamic_pointer_cast<Omnom>(object2);
    ResourceManager::getInstance().playSound("MonsterChewing");
    omnom->setAnimationFlag(true);
    world.restartClock();
    candy->setDelete();
    world.setLevelStatus(Won);
}

void candyStar(std::unique_ptr<GameObject> object1, std::unique_ptr<GameObject> object2, World& world)
{
    std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
    std::shared_ptr<Star> star = std::dynamic_pointer_cast<Star>(object2);

    ResourceManager::getInstance().playSound("Star");

    world.addStar();

    star->setDelete();
}
void candySpikes(std::unique_ptr<GameObject> object1, std::unique_ptr<GameObject> object2, World& world)
{
    auto candy = std::dynamic_pointer_cast<Candy>(object1);
    auto Spike = std::dynamic_pointer_cast<Spikes>(object2);

    ResourceManager::getInstance().playSound("CandyBreak");

    world.setLevelStatus(Lost);
    candy->setDelete();
}

void candyHat(std::unique_ptr<GameObject> object1, std::unique_ptr<GameObject> object2, World& world)
{
    auto candy = std::dynamic_pointer_cast<Candy>(object1);
    auto doubleHat = std::dynamic_pointer_cast<DoubleHat>(object2);

    ResourceManager::getInstance().playSound("Teleport");

    // Get the second body's position and angle
    auto hatBody = doubleHat->getBody();
    auto position = hatBody->GetPosition();
    auto angle = hatBody->GetAngle();

    // Calculate a small offset in the direction the hat is facing
    float offsetDistance = 5.0f; // Adjust this value as needed
    b2Vec2 offset(sin(angle) * offsetDistance, cos(angle) * offsetDistance);

    // Set the new position slightly forward from the hat's current position
    b2Vec2 newPosition = position + offset;
    candy->getBody()->SetTransform(newPosition, angle);

    // Get the current velocity of the candy
    b2Vec2 currentVelocity = candy->getBody()->GetLinearVelocity();

    // Calculate the speed (magnitude) of the current velocity
    float speed = currentVelocity.Length();

    // Calculate the new velocity components using the hat's angle
    b2Vec2 newVelocity(sin(angle) * speed / 2, cos(angle) * speed / 2 );

    // Set the new velocity for the candy
    candy->getBody()->SetLinearVelocity(newVelocity);
}


void candyAir(std::unique_ptr<GameObject>& object1, std::unique_ptr<GameObject>& object2, World& world)
{
    // Attempt to cast to Candy and Air types using std::dynamic_pointer_cast
    auto candy = std::move(std::dynamic_pointer_cast<Candy>(object1));
    auto air = std::dynamic_pointer_cast<Air>(object2);

    // Check if casting was successful and objects are valid
    if (candy && air) {
        candy->getBody()->ApplyForceToCenter(air->getForce(), true);
    }
    else {
        // Handle invalid object types or null pointers
        throw std::runtime_error("Invalid object types for candyAir function.");
    }
}

