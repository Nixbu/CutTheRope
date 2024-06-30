#include "GameObjects/DoubleHat.h"


//===================================================================
//===================================================================
DoubleHat::DoubleHat(const Data& ObjectData, World& world, const sf::Texture& texture) 
	: NonClickableObject(ObjectData, texture), m_whichBody(false)
{
	Data hat1Data, hat2Data;

	hat1Data.m_pos.x = ObjectData.m_pos.x;
	hat1Data.m_pos.y = ObjectData.m_pos.y;
	hat1Data.m_angle = ObjectData.m_angle;

	hat2Data.m_pos.x = ObjectData.m_pos2.x;
	hat2Data.m_pos.y = ObjectData.m_pos2.y;
	hat2Data.m_angle = ObjectData.m_angle2;


	m_hat1 = std::make_unique<Hat>(hat1Data, world, texture);
	m_hat2 = std::make_unique<Hat>(hat2Data, world, texture);
}
//===================================================================
// Updates both Hat objects associated with the DoubleHat.
//===================================================================
void DoubleHat::update(sf::Time& deltaTime)
{
	this->m_hat1->update(deltaTime);
	this->m_hat2->update(deltaTime);
}
//===================================================================
void DoubleHat::draw(sf::RenderWindow& window) const
{
	this->m_hat1->draw(window);
	this->m_hat2->draw(window);
}

//============================================================
// The function changes the body that is being returned for
// the check collision to work on both hats
//===================================================================
b2Body* DoubleHat::getBody()
{
	if (m_whichBody)
	{
		m_whichBody = false;
		return this->m_hat1->getBody();
	}
	else
	{
		m_whichBody = true;
		return this->m_hat2->getBody();
	}
}

//===================================================================
// for the factory
//===================================================================
bool DoubleHat::m_registerit = FactoryManager::registerit("DoubleHat",
	&DoubleHatFactory::createObject);