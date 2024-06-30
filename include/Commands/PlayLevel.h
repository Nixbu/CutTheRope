#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>


class PlayingState;
class GameState;
class Controller;

/*
class PlayLevel
The PlayLevel class is a command that initiates playing a specific level in the game.
It holds a reference to the controller, the playing state, the level name, and the level number.
*/

class PlayLevel : public Command {
public:
    PlayLevel(Controller& controller, std::shared_ptr<PlayingState> playingState, const std::string& levelName ,
                const int & levelNum);
    virtual void execute()  override;
private:
    Controller& m_controller;
    std::shared_ptr<PlayingState> m_playingState;
    std::string m_levelName;
    int m_levelNum;
};
