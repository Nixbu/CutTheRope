#include "Commands/ResetLevel.h"
#include "PlayingState.h"


ResetLevel::ResetLevel(std::shared_ptr<PlayingState> playingState)
	: m_playingState(playingState)
{}
//===================================================================
void ResetLevel::execute()
{
	this->m_playingState->reloadLevel();
}
