#pragma once
#include "RtMidi.h"
#include "Player.h"

class Game
{
public:
	Game(RtMidiIn *input, RtMidiOut *output);
	~Game();

	void play();

private:
	bool handle_input();
	void update();
	void render();
	void doRipple();

	Player player;
	AllButtons allButtons;
	unsigned int ripple = 0;
	RtMidiIn *midiin;
	RtMidiOut *midiout;
	std::vector<std::vector<int>> buttonStates;
	std::vector<std::vector<int>> padStates;
};

