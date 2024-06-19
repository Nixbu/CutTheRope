#pragma once
#include "Commands/command.h"
#include <memory>
#include "GameState.h"

class Controller;

class ChangeScreen  :public Command{
public:
    ChangeScreen(Controller& controller, std::shared_ptr<GameState> newState);
    virtual void execute()  override;
private:
    Controller& m_controller;
    std::shared_ptr<GameState> m_newState;
};
