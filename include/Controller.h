#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameState.h"
#include "MainState.h"
#include "LevelSelectState.h"
#include "PlayingState.h"
#include "HelpState.h"

class Controller
{
public:
    Controller();
    void run();
    std::shared_ptr<MainState> getMainState();
    std::shared_ptr<LevelSelectState> getLevelSelectionState();
    std::shared_ptr<PlayingState> getPlayingState();
    std::shared_ptr<HelpState> getHelpState();
    void setCurrentState(std::shared_ptr<GameState> next);
    void closeWindow();

private:
    void render(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);

    sf::RenderWindow m_window;
    sf::Image m_windowIconImage;
    sf::Sprite m_mouseCursor;

    std::shared_ptr<GameState> m_currentState;
    std::shared_ptr<MainState> m_mainState;
    std::shared_ptr<LevelSelectState> m_levelSelectState;
    std::shared_ptr<PlayingState> m_playingState;
    std::shared_ptr<HelpState> m_helpState;
};