#pragma once
#include "Components.h"
#include<time.h>

class BatteryStorageSensor : public Components
{
private:
	uint16_t ui16_currentCharge;

public:

	void setCharge(float f_charge);

	float getChargeData();

	void display();

	void conversionProcess();

	void on();

	void off();
};

/////////////////////////////////////////////////////



void BatteryStorageSensor::setCharge(float f_charge) {
	f_charge = ui16_currentCharge;

}

float BatteryStorageSensor::getChargeData() {

	return ui16_currentCharge;
}

void BatteryStorageSensor::display(void)
{
	ui16_currentCharge = 0;
	ui16_currentCharge = ((rand() % 100 + 1));
	cout << "Current battery charge: " << ui16_currentCharge << "watts" << endl;
}

void BatteryStorageSensor::conversionProcess() {

	uint16_t i16_panelWatts = 200;
	uint16_t ui16_weekscharging = (rand() % 10 + 1);
	uint16_t ui_kilowatts = 0;

	ui16_currentCharge = i16_panelWatts * ui16_weekscharging;
	ui_kilowatts = ui16_currentCharge / 100;
	cout << "\n Current charge in kilowats: " << ui_kilowatts << endl;
	// watts / light intensity = current charge per change of some shit
}

void BatteryStorageSensor::on() {
	cout << "Battery Charge Sensor is on!\n";
}
void BatteryStorageSensor::off() {
	cout << "Battery Charge Sensor is on!\n";
}