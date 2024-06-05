#include "Controller.h"


Controller::Controller() {

}


void Controller::run() {

	sf::Vector2f mousePos;
	sf::RenderWindow window(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Cut The Rope");

	std::shared_ptr<GameState> updatedState; 

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		window.clear();

		this->m_currentState->draw(window);

		window.display();


		for (auto event = sf::Event{}; window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window.close();
				break;

			case sf::Event::MouseButtonReleased:

				mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				updatedState = m_currentState->handleClicks(mousePos);
				this->changeState(updatedState);

			case sf::Event::MouseMoved:

				sf::Event::MouseMoveEvent mouse = event.mouseMove;
				mousePos = window.mapPixelToCoords({ mouse.x, mouse.y });
				this->m_currentState->handleFloating(mousePos);
			}
		}

	}
}

void Controller::changeState(std::shared_ptr<GameState> newState)
{
	if (newState) {
		this->m_currentState = newState;
	}
}
