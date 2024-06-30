#include "Controller.h"

//======================================================
// Constructor
// Initializes all states (MainState, LevelSelectState, PlayingState, HelpState),
// adds buttons to each state, sets the initial state to MainState, and loads the window icon.
//======================================================
Controller::Controller()
{
	m_mainState = std::make_shared<MainState>();
	m_levelSelectState = std::make_shared<LevelSelectState>();
	m_playingState = std::make_shared<PlayingState>(*this);
	m_helpState = std::make_shared<HelpState>();


	this->m_mainState->addButtons(*this);
	this->m_levelSelectState->addButtons(*this);
	this->m_playingState->addButtons();
	this->m_helpState->addButtons(*this);

	m_currentState = m_mainState;

	auto& iconTexture = ResourceManager::getInstance().getImage("Icon");
	m_windowIconImage = iconTexture.copyToImage();
}

//======================================================
// run
// Main game loop. Handles rendering, user input, and updates the current state.
//======================================================
void Controller::run() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_MANAGER_WIDTH,
		WINDOW_MANAGER_HEIGHT),
		"Cut The Rope");

	ResourceManager::getInstance().playMusic("CutTheRope");

	window.setIcon(m_windowIconImage.getSize().x, m_windowIconImage.getSize().y, m_windowIconImage.getPixelsPtr());

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		this->render(window);

		this->handleInput(window);

		this->m_currentState->update();
	}
}
//======================================================
std::shared_ptr<MainState> Controller::getMainState()
{
	return this->m_mainState;
}
//======================================================
std::shared_ptr<LevelSelectState> Controller::getLevelSelectionState()
{
	return this->m_levelSelectState;
}
//======================================================
std::shared_ptr<PlayingState> Controller::getPlayingState()
{
	return this->m_playingState;
}
//======================================================
void Controller::setCurrentState(std::shared_ptr<GameState> next)
{
	this->m_currentState = next;
}
//======================================================
std::shared_ptr<HelpState> Controller::getHelpState()
{
	return this->m_helpState;
}
//======================================================
// render
// Clears the window, draws the current state, and displays the window.
//======================================================
void Controller::render(sf::RenderWindow& window)
{
	window.clear();

	this->m_currentState->draw(window);

	window.display();
}
//======================================================
// handleInput
// Handles user input events such as window close, mouse button press,
// mouse button release, and mouse movement.
//======================================================
void Controller::handleInput(sf::RenderWindow& window)
{
	static sf::Vector2f mousePos;

	for (auto event = sf::Event{}; window.pollEvent(event); )
	{
		switch (event.type)
		{
		case sf::Event::Closed:

			window.close();
			break;

		case sf::Event::MouseButtonPressed:
			mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			m_playingState->MousePressPos(mousePos);
			break;

		case sf::Event::MouseButtonReleased:

			mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			m_currentState->handleClicks(mousePos);
			break;
		case sf::Event::MouseMoved:

			sf::Event::MouseMoveEvent mouse = event.mouseMove;
			mousePos = window.mapPixelToCoords({ mouse.x, mouse.y });
			this->m_currentState->handleFloating(mousePos);
			break;
		}
	}
}


