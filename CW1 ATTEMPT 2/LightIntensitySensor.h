#pragma once
#include "SolarPanel.h"
#include "Components.h"
#include<memory>


class LightIntensitySensor : public Components
{
private:
	uint16_t ui16_currentLightIntensity; //*


public:
	void setIntensity(uint16_t intensity); //*

	float getIntensity();


	void display();

	void on();
	void off();

};
void LightIntensitySensor::setIntensity(uint16_t intensity) {
	ui16_currentLightIntensity = intensity;


}

float LightIntensitySensor::getIntensity() {

	return ui16_currentLightIntensity;
}


void LightIntensitySensor::display() {

	ui16_currentLightIntensity = 0;
	ui16_currentLightIntensity = (rand() % 10 + 1);

	cout << "Light Intensity: " << ui16_currentLightIntensity << endl;
}

void LightIntensitySensor::on() {
	cout << "Light Intensity sensor is on!\n";
}

void LightIntensitySensor::off() {
	cout << "Light Intensity sensor is off...\n";
}