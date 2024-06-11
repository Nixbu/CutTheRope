#pragma once

#include "Button.h"

class LevelSelectStateButton : public Button
{
public:
	using Button::Button;

	virtual state_t action() const override;
private:
};