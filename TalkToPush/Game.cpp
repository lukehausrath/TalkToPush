#include "Game.h"
#include "Player.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <chrono>
#include <cstdlib>

// --------------------------------------------------------------------- //

constexpr std::chrono::nanoseconds timestep(50000000); // 75ms

// --------------------------------------------------------------------- //

Game::Game(RtMidiIn *input, RtMidiOut *output)
	: midiin(input)
	, midiout(output)
	, player()
	, allButtons()
{
	for (int i = 0; i < allButtons.get.size(); i++) {
		buttonStates.push_back(std::vector<int>());
		for (int j = 0; j < allButtons.get[i].size(); j++)
			buttonStates[i].push_back(0);
	}
}


Game::~Game()
{
}

void Game::play()
{
	using clock = std::chrono::high_resolution_clock;
	auto time_start = clock::now();
	std::chrono::nanoseconds nsdt(0);
	bool quit_game = false;

	while (!quit_game) {
		auto clockdt = clock::now() - time_start;
		time_start = clock::now();
		nsdt += std::chrono::duration_cast<std::chrono::nanoseconds>(clockdt);

		quit_game = handle_input();

		while (nsdt >= timestep) {
			nsdt -= timestep;
			update();
		}

		render();
	}
}


bool Game::handle_input()
{
	MM::message message;
	int nBytes, i;
	double stamp;

	bool done = false;
	while (!done) {
		stamp = midiin->getMessage(&message);
		if (message == MM(cc, OCTAVE_UP).on())
			player.setDirection(Player::DIRECTION::UP);
		if (message == MM(cc, OCTAVE_DOWN).on())
			player.setDirection(Player::DIRECTION::DOWN);
		if (message == MM(cc, PAGE_RIGHT).on())
			player.setDirection(Player::DIRECTION::RIGHT);
		if (message == MM(cc, PAGE_LEFT).on())
			player.setDirection(Player::DIRECTION::LEFT);
		if (message == MM(cc, PLAY).on())
			ripple = 1;

		// Display incoming message. Can be deleted someday.
		nBytes = message.size();
		for (i = 0; i < nBytes; i++) {
			std::cout << "Byte " << i << " = " << (int)message[i] << ", ";
		}
		if (nBytes > 0)
			std::cout << "stamp = " << stamp << std::endl;
		else {
			done = true;
		}
	}

	return false;
}


void Game::update()
{
	// All LEDs off
	for (int y = 0; y < buttonStates.size(); y++) {
		for (int x = 0; x < buttonStates[y].size(); x++)
			buttonStates[y][x] = 0;
	}

	if (ripple)
		doRipple();

	player.move();
	buttonStates[allButtons.yPads[player.getPos().y]][allButtons.xPads[player.getPos().x]] = 1;
}


void Game::render()
{
	for (int y = 0; y < allButtons.get.size(); y++) {
		for (int x = 0; x < allButtons.get[y].size(); x++) {
			if (buttonStates[y][x]) {
				midiout->sendMessage(&allButtons.get[y][x].on(126));
			}
			else
				midiout->sendMessage(&allButtons.get[y][x].off());
		}
	}
}


void Game::doRipple()
{
	unsigned int yIndex = ripple - 1;
	for (int xIndex = 0; xIndex < allButtons.get.at(0).size(); xIndex++)
		buttonStates.at(allButtons.yRipple.at(yIndex)).at(xIndex) = 1;
	ripple++;
	if (ripple > allButtons.yRipple.size())
		ripple = 0;
}

	// Set midi mode to user
	/*message.push_back(0xF0);
	message.push_back(0x00);
	message.push_back(0x21);
	message.push_back(0x1D);
	message.push_back(0x01);
	message.push_back(0x01);
	message.push_back(0x0A);
	message.push_back(0x01);
	message.push_back(0xF7);

	midiout->sendMessage(&message);
	message.clear();*/

	// Sysex Header
	//message.push_back(0xF0);
	//message.push_back(0x00);
	//message.push_back(0x21);
	//message.push_back(0x1D);
	//message.push_back(0x01);
	//message.push_back(0x01);
	//// Command ID
	//message.push_back(0x04); // - this command should get a reply
	//// EOX
	//message.push_back(0xF7);
	//midiout->sendMessage(&message);
	//message.clear();


	// send note
	/*message.push_back(144);
	message.push_back(43);
	message.push_back(79);
	midiout->sendMessage(&message);*/

	// top right RGB LED white
	/*message.push_back(0x90);
	message.push_back(0x63);
	message.push_back(0x7F);
	midiout->sendMessage(&message);*/

	//message.push_back(0xF7);
	//message.clear();

	/*message.push_back(0xF0);
	message.push_back(0x00);
	message.push_back(0x21);
	message.push_back(0x1D);
	message.push_back(0x01);
	message.push_back(0x01);
	message.push_back(0x05);

	message.push_back(0xF7);

	message.clear();*/

	// bottom left RGB LED green
	/*message.push_back(144);
	message.push_back(99);
	message.push_back(127);
	midiout->sendMessage(&message);

	message.clear();*/
