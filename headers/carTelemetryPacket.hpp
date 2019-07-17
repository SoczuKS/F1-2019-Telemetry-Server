#pragma once

/*
	This packet details telemetry for all the cars in the race. It details various values that would be recorded on the car such as speed, throttle application, DRS etc.
	
	Frequency: Rate as specified in menus
	Size: 1347 bytes
*/

#include <array>

#include "packetHeader.hpp"

constexpr uint16 CarTelemetryPacketSize = 1347;

enum class Gear : int8 { REVERSE = -1, NEUTRAL, GEAR1, GEAR2, GEAR3, GEAR4, GEAR5, GEAR6, GEAR7, GEAR8 };

enum class Surface : uint8 { TARMAC, RUMBLE_STRIP, CONCRETE, ROCK, GRAVEL, MUD, SAND, GRASS, WATER, COBBLESTIONE, METAL, RIDGED };

enum class ButtonXbox : uint32 {
	A = 0x0001,
	Y = 0x0002,
	B = 0x0004,
	X = 0x0008,
	DPAD_LEFT  = 0x0010,
	DPAD_RIGHT = 0x0020,
	DPAD_UP    = 0x0040,
	DPAD_DOWN  = 0x0080,
	MENU = 0x0100,
	LB = 0x0200,
	RB = 0x0400,
	LT = 0x0800,
	RT = 0x1000,
	LS = 0x2000,
	RS = 0x4000,
};

enum class ButtonPS : uint32 {
	CROSS = 0x0001,
	TRIANGLE = 0x0002,
	CIRCLE = 0x0004,
	SQAURE = 0x0008,
	DPAD_LEFT = 0x0010,
	DPAD_RIGHT = 0x0020,
	DPAD_UP = 0x0040,
	DPAD_DOWN = 0x0080,
	OPTIONS = 0x0100,
	L1 = 0x0200,
	R1 = 0x0400,
	L2 = 0x0800,
	R2 = 0x1000,
	LS = 0x2000,
	RS = 0x4000,
};

#pragma pack(push, 1)
struct CarTelemetry {
	uint16 speed;									// in Kph
	float throttle;									// 0.0 - 1.0
	float steer;									// -1.0 (full lock left), 1.0 (full lock right))
	float brake;									// 0.0 - 1.0
	uint8 clutch;									// 0 - 100
	Gear gear;
	uint16 engineRPM;
	bool drs;
	uint8 revLightsPercent;							// Rev lights indicator (percentage)
	std::array<uint16, 4> brakesTemperature;		// in celsius
	std::array<uint16, 4> tyresSurfaceTemperature;	// in celsius
	std::array<uint16, 4> tyresInnerTemperature;	// in celsius
	uint16 engineTemperature;						// in celsius
	std::array<float, 4> tyresPressure;				// in PSI
	std::array<Surface, 4> surfaceType;
};

struct CarTelemetryPacket {
	PacketHeader header;	      

	std::array<CarTelemetry, 20> carTelemetry;

	union {
		ButtonPS PSButtonStatus;
		ButtonXbox XboxButtonStatus;
	} buttonStatus;
};
#pragma pack(pop)
