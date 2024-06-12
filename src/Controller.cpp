#include "Controller.h"


Controller::Controller()
{
	m_mainState = std::make_shared<MainState>();
	m_levelSelectState = std::make_shared<LevelSelectState>();
	m_playingState = std::make_shared<PlayingState>();

	m_currentState = m_mainState;
}


void Controller::run() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Cut The Rope");

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		this->render(window);

		this->handleInput(window);

		this->m_currentState->update();
	}
}

void Controller::render(sf::RenderWindow& window)
{
	window.clear();

	this->m_currentState->draw(window);

	window.display();
}

void Controller::handleInput(sf::RenderWindow& window)
{
	static sf::Vector2f mousePos;
	state_t updatedState;

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
			break;
		case sf::Event::MouseMoved:

			sf::Event::MouseMoveEvent mouse = event.mouseMove;
			mousePos = window.mapPixelToCoords({ mouse.x, mouse.y });
			this->m_currentState->handleFloating(mousePos);
			break;
		}
	}
}

void Controller::changeState(state_t newState)
{
	try
	{
		switch (newState)
		{
		case Null:
			break;
		case MAIN_STATE:
			this->m_currentState = m_mainState;
			break;
		case LEVEL_SELECT_STATE:
			this->m_currentState = m_levelSelectState;
			break;
		default:
			// Level states
			this->m_playingState->setLevel(newState);

			this->m_currentState = this->m_playingState;
		}
	}
	catch (const  std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
