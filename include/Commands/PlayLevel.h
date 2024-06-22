#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>


class PlayingState;
class GameState;
class Controller;

class PlayLevel : public Command {
public:
    PlayLevel(Controller& controller, std::shared_ptr<PlayingState> playingState, const std::string& levelName ,
                const int & levelNum, bool open);
    virtual void execute()  override;
private:
    Controller& m_controller;
    std::shared_ptr<PlayingState> m_playingState;
    std::string m_levelName;
    int m_levelNum;
    bool m_open;
};
