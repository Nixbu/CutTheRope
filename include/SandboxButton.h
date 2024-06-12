#pragma once

#include "Button.h"

class SandboxButton : public Button
{
public:
	using Button::Button;

	virtual state_t action() const override;
private:
};