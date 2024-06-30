#pragma once
#include "Commands/command.h"
#include <memory>
#include "GameState.h"

class Controller;

/* 
 class changeScreen
 The ChangeScreen class is a command that allows changing the current screen or game state in the game.
 It holds a reference to the controller and the new game state to switch to.
*/

class ChangeScreen  :public Command{
public:
    ChangeScreen(Controller& controller, std::shared_ptr<GameState> newState);
    virtual void execute()  override;
private:
    Controller& m_controller;
    std::shared_ptr<GameState> m_newState;
};
