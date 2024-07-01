#include "Commands/ExitCommand.h"
#include "Controller.h"

ExitCommand::ExitCommand(Controller& controller)
	: m_controller(controller)
{
}

void ExitCommand::execute()
{
	this->m_controller.closeWindow();
}
