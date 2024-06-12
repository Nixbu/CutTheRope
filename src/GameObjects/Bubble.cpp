#include "GameObjects/Bubble.h"

Bubble::Bubble(const Data& ObjectData, b2World& world, const sf::Texture& texture) : PhysicalObject(ObjectData, texture) {

    //TODO CHANGE SETTINGS IF NEEDED

    this->m_bodyDef.type = b2_dynamicBody; // Set the body type to dynamic
    this->m_bodyDef.position.Set(ObjectData.m_pos.x, ObjectData.m_pos.y); // Set the initial position
    this->m_bodyDef.angle = 0.0f; // Set the initial angle
    this->m_bodyDef.linearVelocity.Set(2.0f, 0.0f); // Set the initial linear velocity
    this->m_bodyDef.angularVelocity = 0.0f; // Set the initial angular velocity
    this->m_bodyDef.linearDamping = 0.1f; // Set the linear damping
    this->m_bodyDef.angularDamping = 0.1f; // Set the angular damping

    this->initBody(world, m_bodyDef);


}