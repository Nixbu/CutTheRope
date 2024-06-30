#include "Commands/MusicCommand.h"

MusicCommand::MusicCommand()
{
}

void MusicCommand::execute()
{
	ResourceManager::getInstance().setMusic("CutTheRope");
}
