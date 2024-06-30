#include "CollisionHandling.h"
#include <thread>
#include <chrono>

//======================================================
// hit map that holds collision functions
//======================================================
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
//======================================================
// function based on 2 classes returns a collision handle func
//======================================================
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
//======================================================
// handles collision between candy and bubble 
//======================================================
void candyBubble(GameObject& object1, GameObject& object2, World& world)
{
     auto& candy = std::dynamic_cast<Candy&>(object1);
     auto& bubble = std::dynamic_cast<Bubble&>(object2);
     
     ResourceManager::getInstance().playSound("CandyToBubble");
     
    bubble.changeToDynamic();
    candy.SetLinearVelocity(BUBBLE_VELOCITY);


    // unite them as a joint
    b2WeldJointDef weldJointDef;
    weldJointDef.bodyA = bubble.getBody();
    weldJointDef.bodyB = candy.getBody();
    weldJointDef.localAnchorA.Set(0, 0);
    weldJointDef.localAnchorB.Set(0, 0);


    world.getWorld().CreateJoint(&weldJointDef);

    std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_DELAY_MS));

}
//======================================================
// handles collision between candy and omnom
//======================================================
void candyOmnom(GameObject& object1, GameObject& object2, World& world)
{
    auto& candy = std::dynamic_cast<Candy&>(object1);
    auto& omnom = std::dynamic_cast<Omnom&>(object2);
    ResourceManager::getInstance().playSound("MonsterChewing");
    omnom.setAnimationFlag(true);
    world.restartClock();
    candy.setDelete();
    world.deleteCandy();
    world.setLevelStatus(Won);
}
//======================================================
// handles collision between candy and star
//======================================================
void candyStar(GameObject& object1, GameObject& object2, World& world)
{
    auto& candy = std::dynamic_cast<Candy&>(object1);
    auto& star = std::dynamic_cast<Star&>(object2);

    ResourceManager::getInstance().playSound("Star");

    world.addStar();

    star.setDelete();
}
//======================================================
// handles collision between candy and spikes
//======================================================
void candySpikes(GameObject& object1, GameObject& object2, World& world)
{
    auto candy = std::dynamic_cast<Candy&>(object1);
    auto spike = std::dynamic_cast<Spikes&>(object2);

    ResourceManager::getInstance().playSound("CandyBreak");

    world.setLevelStatus(Lost);
    candy.setDelete();
}
//======================================================
// handles collision between candy and hat
//======================================================
void candyHat(GameObject& object1, GameObject& object2, World& world)
{
    auto candy = std::dynamic_pointer_cast<Candy>(object1);
    auto doubleHat = std::dynamic_pointer_cast<DoubleHat>(object2);

    ResourceManager::getInstance().playSound("Teleport");

    
    auto hatBody = doubleHat->getBody();
    auto position = hatBody->GetPosition();
    auto angle = hatBody->GetAngle();

    // Calculate a small offset in the direction the hat is facing
    float offsetDistance = 5.0f; 
    b2Vec2 offset(sin(angle) * offsetDistance, cos(angle) * offsetDistance);

    // Set the new position slightly forward from the hats current position
    b2Vec2 newPosition = position + offset;
    candy->getBody()->SetTransform(newPosition, angle);


    b2Vec2 currentVelocity = candy->getBody()->GetLinearVelocity();


    float speed = currentVelocity.Length();

    // Calculate the new velocity components using the hats angle
    b2Vec2 newVelocity(sin(angle) * speed / 2, cos(angle) * speed / 2 );


    candy->getBody()->SetLinearVelocity(newVelocity);
}
//======================================================
// handles collision between candy and air object (created from the pillow)
//======================================================
void candyAir(GameObject& object1, GameObject& object2, World& world)
{
    // Attempt to cast to Candy and Air types using std::dynamic_pointer_cast
    auto& candy = std::dynamic_cast<Candy&>(object1));
    auto& air = std::dynamic_cast<Air&>(object1));

    // Check if casting was successful and objects are valid
    if (candy && air) {
        candy.getBody()->ApplyForceToCenter(air.getForce(), true);
    }
    else {
        // Handle invalid object types or null pointers
        throw std::runtime_error("Invalid object types for candyAir function.");
    }
}

