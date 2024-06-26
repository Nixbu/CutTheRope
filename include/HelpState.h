#pragma once

#include "ResourceManager.h"
#include "Menu.h"
#include "Commands/changeScreen.h"
#include <memory>

class Controller;

class HelpState : public  GameState {
public:
	HelpState();
	virtual void draw(sf::RenderWindow& window) override;
	virtual void handleClicks(const sf::Vector2f& mousePos);
	virtual void update() {};
	virtual void handleFloating(const sf::Vector2f& mousePos);
	void addButtons(Controller& controller);
private:
	Menu m_menu;
	sf::Sprite m_bgImage;


};