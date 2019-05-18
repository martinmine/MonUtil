#include <Windows.h>
#include <iostream>

using namespace std;

void printUsageScreen()
{
	cout << "Usage:" << endl <<
		"--turn-off: Turn off monitors" << endl <<
		"--turn-on: Turn on monitors" << endl;
}

const int TURN_ON_COMMAND = -1;
const int TURN_OFF_COMMAND = 2;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "No arguments provided." << endl;
		printUsageScreen();
		return 1;
	}

	if (string("--turn-off") == argv[1])
	{
		cout << "Turning off computer screens" << endl;
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, TURN_OFF_COMMAND);
	}
	else if (string("--turn-on") == argv[1])
	{
		cout << "Turning on computer screens" << endl;
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, TURN_ON_COMMAND);
	}
	else
	{
		cout << "Unrecognzied argument " << argv[1] << endl;
		printUsageScreen();
		return 1;
	}

	return 0;
}
