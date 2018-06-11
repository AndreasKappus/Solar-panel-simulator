#pragma once
#include "Components.h"
#include<time.h>
#include<iostream>


using namespace std;

class TemperatureSensor : public Components
{
private:
	float f_currentTemperature;
	Components* components;
public:
	// PUT METHODS UNDERNEATH CLASS

	 
	void setTemperature(float f_temperature);

	 float getTemperature();

	 void display();

	 void retractPanel();
	 void on();

	 void off();
};

void TemperatureSensor::setTemperature(float f_temperature) {
	f_temperature = f_currentTemperature;

}

float TemperatureSensor::getTemperature(){
	return f_currentTemperature; }

void TemperatureSensor::display() {
	f_currentTemperature = static_cast<float> (rand() % 80 + 1); // random float generator
	cout << "Current Temperature: " << f_currentTemperature << " degrees celcius" << endl;
}

void TemperatureSensor::retractPanel()
{
	if (f_currentTemperature >= 70) {
		cout << "Temperature too hot! Retracting panel..." << endl;
	}
}
void TemperatureSensor::on() {
	cout << "Temperature Sensor is on!\n";
}

void TemperatureSensor::off() {
	cout << "Temperature Sensor is off...!\n";
}