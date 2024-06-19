#include "CollisionHandling.h"
#include <thread>
#include <chrono>


HitMap initializeCollisionMap()
{
    HitMap collisionMap;
    collisionMap[Key(typeid(Candy), typeid(Bubble))] = &candyBubble;
    collisionMap[Key(typeid(Candy), typeid(Air))] = &candyAir;
    collisionMap[Key(typeid(Candy), typeid(Omnom))] = &candyOmnom;
    collisionMap[Key(typeid(Candy), typeid(Star))] = &candyStar;

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

void candyBubble(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, b2World& world)
{
     std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
     std::shared_ptr<Bubble> bubble = std::dynamic_pointer_cast<Bubble>(object2);

    bubble->changeToDynamic();
    candy->SetLinearVelocity(BUBBLE_VELOCITY);



    b2WeldJointDef weldJointDef;
    weldJointDef.bodyA = bubble->getBody();
    weldJointDef.bodyB = candy->getBody();
    weldJointDef.localAnchorA.Set(0, 0);
    weldJointDef.localAnchorB.Set(0, 0);


    world.CreateJoint(&weldJointDef);

    std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_DELAY_MS));

}
void candyOmnom(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, b2World& world)
{
    std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
    std::shared_ptr<Omnom> omnom = std::dynamic_pointer_cast<Omnom>(object2);


    candy->setDelete();
    //TODO add omnom collition animation

}

void candyStar(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, b2World& world)
{
    std::shared_ptr<Candy> candy = std::dynamic_pointer_cast<Candy>(object1);
    std::shared_ptr<Star> star = std::dynamic_pointer_cast<Star>(object2);

    star->setDelete();
}
void candyAir(std::shared_ptr<GameObject> object1, std::shared_ptr<GameObject> object2, b2World& world)
{
    auto candy = std::dynamic_pointer_cast<Candy>(object1);
    auto air = std::dynamic_pointer_cast<Air>(object2);

    candy->getBody()->ApplyForceToCenter(air->getForce(), true);

    //air->setDelete();

}


