#pragma once
#include "Settings.h"
#include "FactoryManager.h"
#include "GameObjectFactories/DoubleHatFactory.h"
#include "GameObjects/NonClickableObject.h"
#include "GameObjects/Hat.h"

class DoubleHat : public NonClickableObject
{
public:
	DoubleHat(const Data& ObjectData, World& world, const sf::Texture& texture);
	virtual void update(sf::Time& deltaTime);
	virtual void draw(sf::RenderWindow& window) const override;
	virtual b2Body* getBody() override;
private:
	static bool m_registerit;
	std::unique_ptr<Hat> m_hat1,
						m_hat2;
	bool m_whichBody;
	

};