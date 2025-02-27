#pragma once

#include "RopeSegment.h"
#include "FactoryManager.h"
#include <vector>
#include "GameObjects/ClickableObject.h"
#include "GameObjectFactories/RopeFactory.h"
#include "Settings.h"
#include "Hook.h"
#include "FactoryManager.h"

/*
   The Rope class represents a clickable rope object in the game.
   It extends ClickableObject and manages its own update, drawing, and click handling behavior.
*/

class Rope : public ClickableObject
{
public:
    Rope(const Data& data, World& world, const sf::Texture& texture);
    virtual void update(sf::Time& deltaTime) override;
    void handleClicked();
    virtual void draw(sf::RenderWindow& window) const override;
    virtual ~Rope() {};
    virtual bool isClicked(const std::pair<sf::Vector2f, sf::Vector2f>& mousePos) override;

private:
    std::vector<std::shared_ptr<RopeSegment>> m_segments;
    static bool m_registerit;
    std::unique_ptr<Hook> m_hook;
   
    static std::unordered_map < std::string, unsigned int> m_ropeLengthsMap;

    void connectToCandy(World& world);
    void addSegment(World& world, std::shared_ptr<RopeSegment> segment);
    void connectToHook(World& world, std::shared_ptr<RopeSegment> segment);
};

