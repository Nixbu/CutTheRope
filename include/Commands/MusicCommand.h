#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

class Button;

class MusicCommand : public Command {
public:
    MusicCommand();
    virtual void execute() override;
private:
};
