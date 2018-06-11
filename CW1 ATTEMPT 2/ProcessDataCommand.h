#pragma once
#include "Components.h"
#include "BatteryStorageSensor.h"

class ProcessDataCommand : public CommandBase
{
private:
	Components* mComponent;
public:
	ProcessDataCommand(Components *component) : mComponent(component) {}

	void execute() {
		(dynamic_cast<BatteryStorageSensor*>(mComponent)->conversionProcess());
	}
};