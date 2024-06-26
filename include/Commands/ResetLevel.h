#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>

class PlayingState;

class ResetLevel : public Command {
public:
    ResetLevel(std::shared_ptr<PlayingState> playingState);
    virtual void execute()  override;
private:
    std::shared_ptr<PlayingState> m_playingState;
};
