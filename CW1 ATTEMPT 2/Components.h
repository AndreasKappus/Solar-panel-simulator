#pragma once
#include"SolarPanel.h"


class Components 
{
private:
	//float temp;
	
public:

	virtual void display() = 0;
	virtual void on() = 0;
	virtual void off() = 0;
};