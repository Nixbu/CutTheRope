#include "Commands/MusicCommand.h"

MusicCommand::MusicCommand()
{
	
}

//=======================================================
// The command mutes/unmutes the music
void MusicCommand::execute()
{
	ResourceManager::getInstance().setMusic("CutTheRope");
}
