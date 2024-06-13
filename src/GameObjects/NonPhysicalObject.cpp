#include "GameObjects/NonPhysicalObject.h"


NonPhysicalObject::NonPhysicalObject(const Data& data, const sf::Texture& texture)
	: GameObject(data.m_pos, texture)
{
}
NonPhysicalObject::~NonPhysicalObject()
{

}