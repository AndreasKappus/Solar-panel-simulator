#pragma once
#include "TemperatureSensor.h"
#include<iostream>

using namespace std;

class Update
{
private:
	vector<int> data;
	
public:
	float getTemperature(TemperatureSensor* temperature)
	{
		return temperature->getTemperature();
	}

	
	

	
	

};