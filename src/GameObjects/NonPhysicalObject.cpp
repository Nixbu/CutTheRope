#include "GameObjects/NonClickableObject.h"


NonClickableObject::NonClickableObject(const Data& data, const sf::Texture& texture)
	: GameObject(data.m_pos, texture)
{
}
NonClickableObject::~NonClickableObject()
{

}