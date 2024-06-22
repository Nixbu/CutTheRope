#include "Commands/PlayLevel.h"
#include "PlayingState.h"
#include "GameState.h"
#include "Controller.h"


PlayLevel::PlayLevel(Controller& controller, std::shared_ptr<PlayingState> playingState,
	const std::string& levelName , const  int& levelNum)
	: m_controller(controller), m_playingState(playingState), m_levelName(levelName) , m_levelNum(levelNum) {}

void PlayLevel::execute()
{
	this->m_playingState->setLevel(this->m_levelName);
	this->m_playingState->setLevelNum(this->m_levelNum);
	this->m_controller.setCurrentState(this->m_playingState);

}
