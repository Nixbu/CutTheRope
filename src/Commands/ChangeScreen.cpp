#include "Commands/changeScreen.h"
#include "Controller.h"

ChangeScreen::ChangeScreen(Controller& controller, std::shared_ptr<GameState> newState)
	:m_controller(controller) , m_newState(newState)
{
	
}

void ChangeScreen::execute()
{
    if (this->m_newState) {
        this->m_controller.setCurrentState(this->m_newState);
    }
    else {
        std::cerr << "Error: newState is null." << std::endl;
    }
}
