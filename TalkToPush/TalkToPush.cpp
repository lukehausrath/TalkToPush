// TalkToPush.cpp : Experimenting with Push API
// ---------------------------------------------------------------------//

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "RtMidi.h"
#include "Game.h"

// ---------------------------------------------------------------------//

unsigned int PUSH_IN_PORT;
unsigned int PUSH_OUT_PORT;
RtMidiIn *midiin = nullptr;
RtMidiOut *midiout = nullptr;

// ---------------------------------------------------------------------//

void cleanup()
{
	if (midiin->isPortOpen())
		midiin->closePort();
	if (midiout->isPortOpen())
		midiout->closePort();
	delete midiin;
	delete midiout;
	midiin = nullptr;
	midiout = nullptr;
}

int main()
{
	try {
		midiin = new RtMidiIn();
		midiout = new RtMidiOut();
	}
	catch (RtMidiError &error) {
		error.printMessage();
		exit(EXIT_FAILURE);
	}

	// Check inputs and outputs
	unsigned int nInPorts = midiin->getPortCount();
	unsigned int nOutPorts = midiout->getPortCount();
	if (nInPorts == 0 || nOutPorts == 0) {
		std::cout << "No ports available! Press any key to exit.\n";
		std::getchar();
	}
	std::cout << "\nThere are " << nInPorts << " MIDI input sources available.\n";
	std::cout << "There are " << nOutPorts << " MIDI output ports available.\n";
	std::cout << "\nInputs:\n";
	std::string portName;
	for (unsigned int i = 0; i < nInPorts; i++) {
		try {
			portName = midiin->getPortName(i);
		}
		catch (RtMidiError &error) {
			error.printMessage();
			exit(EXIT_FAILURE);
		}
		if (portName.compare(0, 24, "MIDIIN2 (Ableton Push 2)") == 0) {
			PUSH_IN_PORT = i;
		}
		std::cout << "    Input Port #" << i << ": " << portName << "\n";
	}

	std::cout << "\nOutputs:\n";
	for (unsigned int i = 0; i < nOutPorts; i++) {
		try {
			portName = midiout->getPortName(i);
		}
		catch (RtMidiError &error) {
			error.printMessage();
			exit(EXIT_FAILURE);
		}
		if (portName.compare(0, 25, "MIDIOUT2 (Ableton Push 2)") == 0) {
			PUSH_OUT_PORT = i;
		}
		std::cout << "    Output Port #" << i << ": " << portName << '\n';
	}

	std::cout << "\nOpening input port " << PUSH_IN_PORT << "\n";
	std::cout << "Opening output port " << PUSH_OUT_PORT << "\n\n";

	try {
		if (midiin->getPortName(PUSH_IN_PORT).compare(0, 24, "MIDIIN2 (Ableton Push 2)") != 0)
			throw RtMidiError("Push not detected. Make sure Push is connected and restart the program. \n[Enter any key to exit]");
		if (midiout->getPortName(PUSH_OUT_PORT).compare(0, 25, "MIDIOUT2 (Ableton Push 2)") != 0)
			throw RtMidiError("Push not detected. Make sure Push is connected and restart the program. \n[Enter to exit]");
		midiin->openPort(PUSH_IN_PORT);
		midiin->ignoreTypes(false, false, false);
		midiout->openPort(PUSH_OUT_PORT);
	}
	catch (RtMidiError &error) {
		error.printMessage();
		std::cin.get();
		cleanup();
		return 0;
	}

	Game game = Game(midiin, midiout);
	game.play();
	cleanup();
	return 0;
}
