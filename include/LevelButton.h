#pragma once

#include <string>
#include "Button.h"

class LevelButton : public Button {
public:
	using Button::Button;

	virtual state_t action() const override;
private:

};