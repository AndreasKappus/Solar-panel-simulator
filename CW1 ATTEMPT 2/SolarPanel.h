#pragma once
#include"Components.h"
#include"CommandBase.h"
#include <iostream>
#include<fstream>

#include <vector>

using namespace std;

class SolarPanel // Invoker class as it invokes the commands from the base command class without having to know the commands directly
{
private:

	CommandBase * myCommands[10]; // Issue
	
public:
	
	void setCommand(int slot, CommandBase *cmd) {
		myCommands[slot] = cmd;
		
	}

	void commandChosen(int slot) {
		
		cout << "********************************" << endl;
		myCommands[slot]->execute();
	}

	
};

