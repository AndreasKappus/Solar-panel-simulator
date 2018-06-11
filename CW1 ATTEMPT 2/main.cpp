#include"SolarPanel.h"
#include"TemperatureSensor.h"
#include"LightIntensitySensor.h"
#include"BatteryStorageSensor.h"
#include "Components.h"
#include "DisplayCommand.h"
#include "RetractCommand.h"
#include "ProcessDataCommand.h"
#include "OnCommand.h"
#include "OffCommand.h"
#include "AuthenticatorPattern.h"
#include<sstream>

int main(void)
{
	Subject subject;
	Authenticator authenticator;
	ProofofID *proofofID = authenticator.authenticateUser(subject);

	Components* components[] = { new TemperatureSensor(), new LightIntensitySensor(), new BatteryStorageSensor() };
	// temperature sensor component address: 0. light intensity address: 1, battery storage address: 2


	CommandBase *commands[] = {
		new OnCommand(components[0]),
		new OnCommand(components[1]),
		new OnCommand(components[2]),

		new DisplayCommand(components[0]), // the components are represented by the values in the array
		new DisplayCommand(components[1]),
		new DisplayCommand(components[2]),

		new ProcessDataCommand(components[2]),
		new RetractCommand(components[0])

		////////////////////////////////////////////////
		//NEW COMMANDS CAN BE ADDED INTO HERE, IF COMMAND IS BRAND NEW, MAKE SURE TO CREATE A CLASS FOR THE NEW COMMAND 
	}; 

	unique_ptr<SolarPanel> panel(new SolarPanel); // UNIQUE POINTER, so it prevents pointer from dangling

	unsigned userChoice;

	ifstream Readfile;
	ofstream Writefile;
	//char buffers[40]
	
	cout << "subject proof of ID" << subject.getProofofIdentification() << endl;
	cout << "system proof of ID" << proofofID->getProofID() << endl;


	do
	{
		cout << "1: View Sensor Data\n"; 
		cout << "2: Save Sensor Data\n";
		cout << "3: Load Sensor Data\n";
		cout << "4: Secret Message\n";
		cout << "0: Power Off and Quit!" << endl;; // exit program
		
		cin >> userChoice;
		switch (userChoice)
		{
		case 1:

			for (uint16_t i = 0; i < 8; i++) { // change "i < num" when commands are added/removed

				panel->setCommand(i, commands[i]);
			}

			for (uint16_t i = 0; i < 8; i++) { // change "i < num" when commands are added/removed
				panel->commandChosen(i);
			}
			break;

		case 2:
			////////////////////////// FILE I/O Implemented ////////////////////
		{
			Writefile.open("SensorData.txt");

			if (Writefile.fail()) {
				cout << "Unable to open file for writing data\n";

			}
			else
			{
				/*if (!Writefile.write(buffer[1], sizeof(buffer)))
				{
					cout << "Unable to write to file!\n";
				}*/

				//else
				//{
				streamsize byteswritten = Writefile.tellp();
				if (byteswritten > sizeof(Writefile)) {
					cout << "unable to write expected number of bytes to file...\n";
					Writefile.close();
				}
				else
				{
					Writefile << components[0] << " " << components[1] << " " << components[2] << " " << components[0];

					cout << "File managed to save! (yay) " << endl;
				}
				Writefile.close();
				
			}
		}
		break;
		///////////////////// WRITE FILE I/O ENDS //////////////////////////
		
		case 3:
		{	
		////////////////////// READ FILE I/O BEGINS ////////////////////////////////
		
			Readfile.open("SensorData.txt");
			//maybe add exceptions

			if (Readfile.fail()) {
				cout << "Could not open Sensor Data...\n";
				
			}
			else
			{
				streamsize bytesRead = Readfile.gcount();
				if (bytesRead > sizeof(Readfile)) {
					cout << "Could not read expected number of bytes in file...\n";
					Readfile.close();
				}
				else { 
					while (!Readfile.eof()) { // while not at the end of the file
						Readfile;

					}
						
						/////////////////// FIX PLZ
				}
			}
		
		Readfile.close();
		}
		break;
		///////////////////// WRITE FILE I/O ENDS //////////////////////////

		case 4:
			cout << "Please pass me\n";
			break;
		case 0:
			//delete[] commands, components; // FIX PLZ
			cout << "Panel Powering off...\n";
			std::exit(0);

			}

			
			
		

		}  while (userChoice != 0);
		// plz pass me :/

		std::system("pause");
}
