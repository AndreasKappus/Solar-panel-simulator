#pragma once
#include "Components.h"


class RetractCommand : public CommandBase
{
private:
	Components* mComponent;

public:
	RetractCommand(Components *component) : mComponent(component) {}

	void execute() {
		(dynamic_cast<TemperatureSensor*>(mComponent)->retractPanel());
		
	}

};