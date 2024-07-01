#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>

class Controller;

/*
class ExitCommand
The ExitCommand class is a command that exits the game.
*/

class ExitCommand : public Command {
public:
    ExitCommand(Controller& controller);
    virtual void execute() override;
private:
    Controller& m_controller;
};
