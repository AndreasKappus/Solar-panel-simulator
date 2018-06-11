#pragma once
#include"Components.h"

class OffCommand : public CommandBase
{
	Components *mComponent;
public:
	OffCommand(Components *component) : mComponent(component) {}

	void execute() {
		mComponent->off();
	}
};