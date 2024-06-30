#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>

class PlayingState;

/*
   class ResetLevel
   The ResetLevel class is a command that resets the current level in the game.
   It holds a shared pointer to the playing state that needs to be reset.
*/

class ResetLevel : public Command {
public:
    ResetLevel(std::shared_ptr<PlayingState> playingState);
    virtual void execute()  override;
private:
    std::shared_ptr<PlayingState> m_playingState;
};
