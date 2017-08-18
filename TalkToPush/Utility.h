#pragma once
#include <vector>

struct vec2
{
	int x;
	int y;
};

const unsigned char nn = 0x90;
const unsigned char cc = 0xB0;

struct MM {
	typedef std::vector<unsigned char> message;

	unsigned char statusByte;
	unsigned char dataByte;
	unsigned char velocity = 127;
	std::string name;

	MM(unsigned char statusByte, unsigned char dataByte)
		: statusByte(statusByte), dataByte(dataByte)
	{
	}

	MM(unsigned char statusByte, unsigned char dataByte, unsigned char v)
		: statusByte(statusByte), dataByte(dataByte), velocity(v)
	{
	}

	MM()
		:dataByte(0), statusByte(0), velocity(0)
	{
	}
	
	message on()
	{
		message data;
		data.push_back(statusByte);
		data.push_back(dataByte);
		data.push_back(velocity);
		return data;
	}

	message on(unsigned char v)
	{
		message data;
		data.push_back(statusByte);
		data.push_back(dataByte);
		data.push_back(v);
		return data;
	}

	message off()
	{
		message data;
		data.push_back(statusByte);
		data.push_back(dataByte);
		data.push_back(velocity);
		return data;
	}
	
	message off(unsigned char v)
	{
		message data;
		data.push_back(statusByte);
		data.push_back(dataByte);
		data.push_back(v);
		return data;
	}

	void setVelocity(unsigned char v)
	{
		velocity = v;
	}
};

enum BUTTONS {
	TAP_TEMPO = 3, METRONOME = 9, TOP_DIS_1 = 102, TOP_DIS_2 = 103, TOP_DIS_3 = 104, TOP_DIS_4 = 105, TOP_DIS_5 = 106, TOP_DIS_6 = 107, TOP_DIS_7 = 108, TOP_DIS_8 = 109, SETUP = 30, USER = 59,
	DELETE_ = 118, ADD_DEVICE = 52, DEVICE = 110, MIX = 112,
	UNDO = 119, ADD_TRACK = 53, BROWSE = 111, CLIP = 113,
	MUTE = 60, SOLO = 61, STOP = 29, BOT_DIS_1 = 20, BOT_DIS_2 = 21, BOT_DIS_3 = 22, BOT_DIS_4 = 23, BOT_DIS_5 = 24, BOT_DIS_6 = 25, BOT_DIS_7 = 26, BOT_DIS_8 = 27, MASTER = 28,
	UP_ARROW = 46, RIGHT_ARROW = 45, DOWN_ARROW = 47, LEFT_ARROW = 44,
	CONVERT = 35, QUANT_32T = 43, QUANT_32 = 42, QUANT_16T = 41, QUANT_16 = 40, QUANT_8T = 39, QUANT_8 = 38, QUANT_4T = 37, QUANT_4 = 36,
	DOUBLE_LOOP = 117, QUANTIZE = 116, DUPLICATE_ = 88, NEW = 87, REPEAT = 56, ACCENT = 57, SCALE = 58, LAYOUT = 31, NOTE = 50, SESSION = 51,
	OCTAVE_UP = 55, PAGE_RIGHT = 63, OCTAVE_DOWN = 54, PAGE_LEFT = 62,
	SHIFT = 49, SELECT = 48,
	FIXED_LENGTH = 90, AUTOMATE = 89, RECORD = 86, PLAY = 85
};


struct AllButtons {
	// indexes of the pads. Used for offsetting player movement to light up correct pads
	std::vector<int> yPads = { 17, 15, 13, 11, 10, 8, 6, 5 };
	std::vector<int> xPads = { 3,  4,  5,  6,  7,  8, 9, 10 };
	// indexes for the ripple effect
	std::vector<int> yRipple = { 0, 1, 2, 3, 5, 6, 8, 10, 11, 13, 15, 17 };
	std::vector<int> xRipple = { 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14 };

	// Row 1
	MM PLAY{ cc, 85, 127 };
	MM PAD1{ nn, 36, 127 };
	MM PAD2{ nn, 37, 127 };
	MM PAD3{ nn, 38, 127 };
	MM PAD4{ nn, 39, 127 };
	MM PAD5{ nn, 40, 127 };
	MM PAD6{ nn, 41, 127 };
	MM PAD7{ nn, 42, 127 };
	MM PAD8{ nn, 43, 127 };
	MM QUANT14{ cc, 36, 127 };
	MM SHIFT{ cc, 49, 127 };
	MM SELECT{ cc, 48, 127 };
	std::vector<MM> row1{ PLAY, PAD1, PAD2, PAD3, PAD4, PAD5, PAD6, PAD7, PAD8, QUANT14, SHIFT, SELECT };

	// Row 2
	MM RECORD{ cc, 86, 127 };
	MM PAD9{ nn, 44, 127 };
	MM PAD10{ nn, 45, 127 };
	MM PAD11{ nn, 46, 127 };
	MM PAD12{ nn, 47, 127 };
	MM PAD13{ nn, 48, 127 };
	MM PAD14{ nn, 49, 127 };
	MM PAD15{ nn, 50, 127 };
	MM PAD16{ nn, 51, 127 };
	MM QUANT14T{ cc, 37, 127 };
	MM PAGELEFT{ cc, 62, 127 };
	MM OCTAVEUP{ cc, 55, 127 };
	MM OCTAVEDOWN{ cc, 54, 127 };
	MM PAGERIGHT{ cc, 63, 127 };
	std::vector<MM> row2{ RECORD, PAD9, PAD10, PAD11, PAD12, PAD13, PAD14, PAD15, PAD16, QUANT14T, PAGELEFT, OCTAVEUP, OCTAVEDOWN, PAGERIGHT };

	// Row 3
	MM AUTOMATE{ cc, 89, 127 };
	MM PAD17{ nn, 52, 127 };
	MM PAD18{ nn, 53, 127 };
	MM PAD19{ nn, 54, 127 };
	MM PAD20{ nn, 55, 127 };
	MM PAD21{ nn, 56, 127 };
	MM PAD22{ nn, 57, 127 };
	MM PAD23{ nn, 58, 127 };
	MM PAD24{ nn, 59, 127 };
	MM QUANT18{ cc, 38, 127 };
	std::vector<MM> row3{ AUTOMATE, PAD17, PAD18, PAD19, PAD20, PAD21, PAD22, PAD23, PAD24, QUANT18 };

	// Row 4
	MM FIXEDLENGTH{ cc, 90, 127 };
	MM NEW{ cc, 90, 127 };
	MM PAD25{ nn, 60, 127 };
	MM PAD26{ nn, 61, 127 };
	MM PAD27{ nn, 62, 127 };
	MM PAD28{ nn, 63, 127 };
	MM PAD29{ nn, 64, 127 };
	MM PAD30{ nn, 65, 127 };
	MM PAD31{ nn, 66, 127 };
	MM PAD32{ nn, 67, 127 };
	MM QUANT8T{ cc, 39, 127 };
	MM NOTE{ cc, 50, 127 };
	MM SESSION{ cc, 51, 127 };
	MM SCALE{ cc, 58, 127 };
	MM LAYOUT{ cc, 31, 127 };
	std::vector<MM> row4{ FIXEDLENGTH, NEW, PAD25, PAD26, PAD27, PAD28, PAD29, PAD30, PAD31, PAD32, QUANT8T, NOTE, SESSION, SCALE, LAYOUT };

	// Row 5
	MM DUPLICATE_{ cc, 88, 127 };
	MM PAD33{ nn, 68, 127 };
	MM PAD34{ nn, 69, 127 };
	MM PAD35{ nn, 70, 127 };
	MM PAD36{ nn, 71, 127 };
	MM PAD37{ nn, 72, 127 };
	MM PAD38{ nn, 73, 127 };
	MM PAD39{ nn, 74, 127 };
	MM PAD40{ nn, 75, 127 };
	MM QUANT16{ cc, 40, 127 };
	MM REPEAT{ cc, 56, 127 };
	MM ACCENT{ cc, 57, 127 };
	std::vector<MM> row5{ DUPLICATE_, PAD33, PAD34, PAD35, PAD36, PAD37, PAD38, PAD39, PAD40, QUANT16, REPEAT, ACCENT };

	// Row6
	MM QUANTIZE{ cc, 116, 127 };
	MM PAD41{ nn, 76, 127 };
	MM PAD42{ nn, 77, 127 };
	MM PAD43{ nn, 78, 127 };
	MM PAD44{ nn, 79, 127 };
	MM PAD45{ nn, 80, 127 };
	MM PAD46{ nn, 81, 127 };
	MM PAD47{ nn, 82, 127 };
	MM PAD48{ nn, 83, 127 };
	MM QUANT16T{ cc, 41, 127 };
	std::vector<MM> row6{ QUANTIZE, PAD41, PAD42, PAD43, PAD44, PAD45, PAD46, PAD47, PAD48, QUANT16T };

	// Row7
	MM DOUBLELOOP{ cc, 117, 127 };
	MM PAD49{ nn, 84, 127 };
	MM PAD50{ nn, 85, 127 };
	MM PAD51{ nn, 86, 127 };
	MM PAD52{ nn, 87, 127 };
	MM PAD53{ nn, 88, 127 };
	MM PAD54{ nn, 89, 127 };
	MM PAD55{ nn, 90, 127 };
	MM PAD56{ nn, 91, 127 };
	MM QUANT32{ cc, 42, 127 };
	std::vector<MM> row7{ DOUBLELOOP, PAD50, PAD51, PAD52, PAD53, PAD54, PAD55, PAD56, QUANT32 };

	// Row8
	MM CONVERT{ cc, 35, 127 };
	MM PAD57{ nn, 92, 127 };
	MM PAD58{ nn, 93, 127 };
	MM PAD59{ nn, 94, 127 };
	MM PAD60{ nn, 95, 127 };
	MM PAD61{ nn, 96, 127 };
	MM PAD62{ nn, 97, 127 };
	MM PAD63{ nn, 98, 127 };
	MM PAD64{ nn, 99, 127 };
	MM QUANT32T{ cc, 43, 127 };
	MM LEFTARROW{ cc, 44, 127 };
	MM DOWNARROW{ cc, 47, 127 };
	MM RIGHTARROW{ cc, 45, 127 };
	std::vector<MM> row8{ CONVERT, PAD57, PAD58, PAD59, PAD60, PAD61, PAD62, PAD63, PAD64, QUANT32T, LEFTARROW, DOWNARROW, RIGHTARROW };

	// Row9
	MM MUTE{ cc, 60, 127 };
	MM SOLO{ cc, 61, 127 };
	MM STOP{ cc, 29, 127 };
	MM BOT1{ cc, 20, 127 };
	MM BOT2{ cc, 21, 127 };
	MM BOT3{ cc, 22, 127 };
	MM BOT4{ cc, 23, 127 };
	MM BOT5{ cc, 24, 127 };
	MM BOT6{ cc, 25, 127 };
	MM BOT7{ cc, 26, 127 };
	MM BOT8{ cc, 27, 127 };
	MM MASTER{ cc, 28, 127 };
	MM UPARROW{ cc, 46, 127 };
	std::vector<MM> row9{ MUTE, SOLO, STOP, BOT1, BOT2, BOT3, BOT4, BOT5, BOT6, BOT7, BOT8, MASTER, UPARROW };
	//
	// Row10
	MM UNDO{ cc, 119, 127 };
	MM ADDTRACK{ cc, 53, 127 };
	MM BROWSE{ cc, 111, 127 };
	MM CLIP{ cc, 113, 127 };
	std::vector<MM> row10{ UNDO, ADDTRACK, BROWSE, CLIP };

	// Row11
	MM DELETE_{ cc, 118, 127 };
	MM ADDDEVICE{ cc, 52, 127 };
	MM DEVICE{ cc, 110, 127 };
	MM MIX{ cc, 112, 127 };
	std::vector<MM> row11{ DELETE_, ADDDEVICE, DEVICE, MIX };

	// Row12
	MM TAPTEMPO{ cc, 3, 127 };
	MM METRONOME{ cc, 9, 127 };
	MM TOP1{ cc, 102, 127 };
	MM TOP2{ cc, 103, 127 };
	MM TOP3{ cc, 104, 127 };
	MM TOP4{ cc, 105, 127 };
	MM TOP5{ cc, 106, 127 };
	MM TOP6{ cc, 107, 127 };
	MM TOP7{ cc, 108, 127 };
	MM TOP8{ cc, 109, 127 };
	MM SETUP{ cc, 30, 127 };
	MM USER{ cc, 59, 127 };
	std::vector<MM> row12{ TAPTEMPO, METRONOME, TOP1, TOP2, TOP3, TOP4, TOP5, TOP6, TOP7, TOP8, SETUP, USER };

	std::vector<std::vector<MM>> rows { row1, row2, row3, row4, row5, row6, row7, row8, row9, row10, row11, row12 };

	std::vector<std::vector<MM>> get = {
		std::vector<MM> { MM(cc, 3),   MM(),       MM(cc, 9),  MM(cc, 102),MM(cc, 103),MM(cc, 104),MM(cc, 105),MM(cc, 106),MM(cc, 107),MM(cc, 108),MM(cc, 109),MM(),        MM(cc, 30), MM(),       MM(cc, 59) },
		std::vector<MM> { MM(cc, 118), MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(cc, 52),  MM(cc, 110),MM(),       MM(cc, 112)},
		std::vector<MM> { MM(cc, 119), MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(cc, 53),  MM(cc, 111),MM(),       MM(cc, 113)},
		std::vector<MM> { MM(cc, 60),  MM(cc, 61), MM(cc, 29), MM(cc, 20), MM(cc, 21), MM(cc, 22), MM(cc, 23), MM(cc, 24), MM(cc, 25), MM(cc, 26), MM(cc, 27), MM(cc, 28),  MM(),       MM(cc, 46), MM()       },
		std::vector<MM> { MM(),        MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),        MM(cc, 44), MM(cc, 45), MM()       },
		std::vector<MM> { MM(cc, 35),  MM(),       MM(),       MM(nn, 92), MM(nn, 93), MM(nn, 94), MM(nn, 95), MM(nn, 96), MM(nn, 97), MM(nn, 98), MM(nn, 99), MM(cc, 43),  MM(),       MM(cc, 47), MM()       },
		std::vector<MM> { MM(cc, 117), MM(),       MM(),       MM(nn, 84), MM(nn, 85), MM(nn, 86), MM(nn, 87), MM(nn, 88), MM(nn, 89), MM(nn, 90), MM(nn, 91), MM(cc, 42),  MM(),       MM(),       MM()       },
		std::vector<MM> { MM(cc, 116), MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),        MM(),       MM(),       MM()       },
		std::vector<MM> { MM(),        MM(),       MM(),       MM(nn, 76), MM(nn, 77), MM(nn, 78), MM(nn, 79), MM(nn, 80), MM(nn, 81), MM(nn, 82), MM(nn, 83), MM(cc, 41),  MM(),       MM(),       MM()       },
		std::vector<MM> { MM(cc, 88),  MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),        MM(),       MM(),       MM()       },
		std::vector<MM> { MM(cc, 87),  MM(),       MM(),       MM(nn, 68), MM(nn, 69), MM(nn, 70), MM(nn, 71), MM(nn, 72), MM(nn, 73), MM(nn, 74), MM(nn, 75), MM(cc, 40),  MM(cc, 56), MM(),       MM(cc, 57) },
		std::vector<MM> { MM(),        MM(),       MM(),       MM(nn, 60), MM(nn, 61), MM(nn, 62), MM(nn, 63), MM(nn, 64), MM(nn, 65), MM(nn, 66), MM(nn, 67), MM(cc, 39),  MM(cc, 58), MM(),       MM(cc, 31) },
		std::vector<MM> { MM(cc, 90),  MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),        MM(cc, 50), MM(),       MM(cc, 51) },
		std::vector<MM> { MM(cc, 89),  MM(),       MM(),       MM(nn, 52), MM(nn, 53), MM(nn, 54), MM(nn, 55), MM(nn, 56), MM(nn, 57), MM(nn, 58), MM(nn, 59), MM(cc, 38),  MM(),       MM(),       MM()       },
		std::vector<MM> { MM(),        MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),        MM(),       MM(cc, 55), MM()       },
		std::vector<MM> { MM(cc, 86),  MM(),       MM(),       MM(nn, 44), MM(nn, 45), MM(nn, 46), MM(nn, 47), MM(nn, 48), MM(nn, 49), MM(nn, 50), MM(nn, 51), MM(cc, 37),  MM(cc, 62), MM(),       MM(cc, 63) },
		std::vector<MM> { MM(),        MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),       MM(),        MM(),       MM(cc, 54), MM()       },
		std::vector<MM> { MM(cc, 85),  MM(),       MM(),       MM(nn, 36), MM(nn, 37), MM(nn, 38), MM(nn, 39), MM(nn, 40), MM(nn, 41), MM(nn, 42), MM(nn, 43), MM(cc, 36),  MM(cc, 49), MM(),       MM(cc, 48) }
	};
};



//enum nn {
//	P1 = 36,
//	P2, P3, P4, P5, P6, P7, P8,
//	P9, P10, P11, P12, P13, P14, P15, P16,
//	P17, P18, P19, P20, P21, P22, P23, P24,
//	P25, P26, P27, P28, P29, P30, P31, P32,
//	P33, P34, P35, P36, P37, P38, P39, P40,
//	P41, P42, P43, P44, P45, P46, P47, P48,
//	P49, P50, P51, P52, P53, P54, P55, P56,
//	P57, P58, P59, P60, P61, P62, P63, P64
//};


//struct PadsOnly {
//	std::vector<std::vector<MM>> get = {
//		std::vector<MM> { MM(nn, 0x5C), MM(nn, 0x5D), MM(nn, 0x5E), MM(nn, 0x5F), MM(nn, 0x60), MM(nn, 0x61), MM(nn, 0x62), MM(nn, 0x63) },
//		std::vector<MM> { MM(nn, 0x54), MM(nn, 0x55), MM(nn, 0x56), MM(nn, 0x57), MM(nn, 0x58), MM(nn, 0x59), MM(nn, 0x5A), MM(nn, 0x5B) },
//		std::vector<MM> { MM(nn, 0x4C), MM(nn, 0x4D), MM(nn, 0x4E), MM(nn, 0x4F), MM(nn, 0x50), MM(nn, 0x51), MM(nn, 0x52), MM(nn, 0x53) },
//		std::vector<MM> { MM(nn, 0x44), MM(nn, 0x45), MM(nn, 0x46), MM(nn, 0x47), MM(nn, 0x48), MM(nn, 0x49), MM(nn, 0x4A), MM(nn, 0x4B) },
//		std::vector<MM> { MM(nn, 0x3C), MM(nn, 0x3D), MM(nn, 0x3E), MM(nn, 0x3F), MM(nn, 0x40), MM(nn, 0x41), MM(nn, 0x42), MM(nn, 0x43) },
//		std::vector<MM> { MM(nn, 0x34), MM(nn, 0x35), MM(nn, 0x36), MM(nn, 0x37), MM(nn, 0x38), MM(nn, 0x39), MM(nn, 0x3A), MM(nn, 0x3B) },
//		std::vector<MM> { MM(nn, 0x2C), MM(nn, 0x2D), MM(nn, 0x2E), MM(nn, 0x2F), MM(nn, 0x30), MM(nn, 0x31), MM(nn, 0x32), MM(nn, 0x33) },
//		std::vector<MM> { MM(nn, 0x24), MM(nn, 0x25), MM(nn, 0x26), MM(nn, 0x27), MM(nn, 0x28), MM(nn, 0x29), MM(nn, 0x2A), MM(nn, 0x2B) },
//	};
//};
