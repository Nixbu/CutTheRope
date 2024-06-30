#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>


/*
    Class MusicCommand: Inherits from command and it's purpose is to mute/unmute the music in the game
*/
class MusicCommand : public Command {
public:
    MusicCommand();
    virtual void execute() override;
private:
};
