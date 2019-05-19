#include <Windows.h>
#include <iostream>

using namespace std;

void printUsageScreen()
{
	cout << "Usage:" << endl <<
		"--turn-off: Turn off monitors" << endl <<
		"--turn-on: Turn on monitors" << endl;
}

const LPARAM POWER_OFF = 2;

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
		SendMessageTimeout(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, POWER_OFF, SMTO_ABORTIFHUNG, 100, NULL);
	}
	else if (string("--turn-on") == argv[1])
	{
		cout << "Turning on computer screens" << endl;

		INPUT in[1];
		KEYBDINPUT kb;
		kb.wVk = VK_CONTROL;
		in[0].type = INPUT_KEYBOARD;
		in[0].ki = kb;
		SendInput(1, in, sizeof(in));
	}
	else
	{
		cout << "Unrecognzied argument " << argv[1] << endl;
		printUsageScreen();
		return 1;
	}

	return 0;
}
