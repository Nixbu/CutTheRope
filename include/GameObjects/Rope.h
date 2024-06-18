#pragma once

#include "RopeSegment.h"
#include "FactoryManager.h"
#include <vector>
#include "GameObjects/ClickableObject.h"
#include "GameObjectFactories/RopeFactory.h"
#include "Settings.h"

class Rope : public ClickableObject
{
public:
    Rope(const Data& data, World& world, const sf::Texture& texture);// TODO add int segmentCount?
    virtual void update() override;
    void handleClicked();
    virtual void draw(sf::RenderWindow& window) const override;
    virtual ~Rope() {};

private:
    std::vector<std::shared_ptr<RopeSegment>> m_segments;
    static bool m_registerit;

};

