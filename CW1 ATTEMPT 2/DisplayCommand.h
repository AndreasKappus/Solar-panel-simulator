#pragma once
#include"Components.h"

class DisplayCommand : public CommandBase
{
private:
	Components* mComponent;

public:
	
	DisplayCommand(Components *component) : mComponent(component) {}

	void execute() {
		dynamic_cast<TemperatureSensor*>(mComponent);
		mComponent->display();
	}

};