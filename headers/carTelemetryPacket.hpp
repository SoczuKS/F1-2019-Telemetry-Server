#pragma once

/*
	This packet details telemetry for all the cars in the race. It details various values that would be recorded on the car such as speed, throttle application, DRS etc.
	
	Frequency: Rate as specified in menus
	Size: 1347 bytes
*/

#include <array>

#include "packetHeader.hpp"

constexpr uint16 CarTelemetryPacketSize = 1347;

struct CarTelemetry {
	uint16 speed;									// in Kph
	float throttle;									// 0.0 - 1.0
	float steer;									// -1.0 (full lock left), 1.0 (full lock right))
	float brake;									// 0.0 - 1.0
	uint8 clutch;									// 0 - 100
	int8 gear;										// 1-8, N=0, R=-1
	uint16 engineRPM;
	uint8 drs;										// 0 = off, 1 = on
	uint8 revLightsPercent;							// Rev lights indicator (percentage)
	std::array<uint16, 4> brakesTemperature;		// in celsius
	std::array<uint16, 4> tyresSurfaceTemperature;	// in celsius
	std::array<uint16, 4> tyresInnerTemperature;	// in celsius
	uint16 engineTemperature;						// in celsius
	std::array<float, 4> tyresPressure;				// in PSI
	std::array<uint8, 4> surfaceType;				// Driving surface, see appendices
};

struct CarTelemetryPacket {
	PacketHeader header;	      

	std::array<CarTelemetry, 20> carTelemetry;
	uint32 buttonStatus;								// Bit flags specifying which buttons are being pressed currently - see appendices
};
