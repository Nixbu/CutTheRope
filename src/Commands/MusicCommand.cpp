#include "Commands/MusicCommand.h"
#include "Button.h"

MusicCommand::MusicCommand()
{
	
}

void MusicCommand::execute()
{
	ResourceManager::getInstance().setMusic("CutTheRope");
}
