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
void candyBubble(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, World& world)
{
     std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
     std::shared_ptr<Bubble> bubble = std::dynamic_pointer_cast<Bubble>(object2);
     
     ResourceManager::getInstance().playSound("CandyToBubble");
     
    bubble->changeToDynamic();
    candy->SetLinearVelocity(BUBBLE_VELOCITY);


    // unite them as a joint
    b2WeldJointDef weldJointDef;
    weldJointDef.bodyA = bubble->getBody();
    weldJointDef.bodyB = candy->getBody();
    weldJointDef.localAnchorA.Set(0, 0);
    weldJointDef.localAnchorB.Set(0, 0);


    world.getWorld().CreateJoint(&weldJointDef);

    std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_DELAY_MS));

}
//======================================================
// handles collision between candy and omnom
//======================================================
void candyOmnom(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, World& world)
{
    std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
    std::shared_ptr<Omnom> omnom = std::dynamic_pointer_cast<Omnom>(object2);
    ResourceManager::getInstance().playSound("MonsterChewing");
    omnom->setAnimationFlag(true);
    world.restartClock();
    candy->setDelete();
    world.setLevelStatus(Won);
    ResourceManager::getInstance().playSound("Win");
}
//======================================================
// handles collision between candy and star
//======================================================
void candyStar(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, World& world)
{
    std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
    std::shared_ptr<Star> star = std::dynamic_pointer_cast<Star>(object2);

    ResourceManager::getInstance().playSound("Star");

    world.addStar();

    star->setDelete();
}
//======================================================
// handles collision between candy and spikes
//======================================================
void candySpikes(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, World& world)
{
    auto candy = std::dynamic_pointer_cast<Candy>(object1);
    auto Spike = std::dynamic_pointer_cast<Spikes>(object2);

    ResourceManager::getInstance().playSound("CandyBreak");

    world.setLevelStatus(Lost);
    candy->setDelete();
}
//======================================================
// handles collision between candy and hat
//======================================================
void candyHat(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, World& world)
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
void candyAir(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, World& world)
{
    auto candy = std::dynamic_pointer_cast<Candy>(object1);
    auto air = std::dynamic_pointer_cast<Air>(object2);

    candy->getBody()->ApplyForceToCenter(air->getForce(), true);
}


