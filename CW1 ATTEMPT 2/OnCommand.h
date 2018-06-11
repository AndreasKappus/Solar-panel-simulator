#pragma once
#include"Components.h"

class OnCommand : public CommandBase
{
private:
	Components *mComponent;
public:
	OnCommand(Components *component) : mComponent(component) {}

	void execute() {
		mComponent->on();
	}
};