#pragma once

/*
	This packet details the car setups for each vehicle in the session. Note that in multiplayer games, other player cars will appear as blank, you will only be able to see your car setup and AI cars.

	Frequency: 2 per second
	Size: 843 bytes
*/

#include <array>

#include "packetHeader.hpp"

constexpr uint16 CarSetupPacketSize = 843;

#pragma pack(push, 1)
struct CarSetup {
	uint8 frontWing, rearWing;
	uint8 onThrottle;									// Differential adjustment on throttle (percentage)
	uint8 offThrottle;									// Differential adjustment off throttle (percentage)
	float frontCamber;									// Front camber angle (suspension geometry)
	float rearCamber;									// Rear camber angle (suspension geometry)
	float frontToe;										// Front toe angle (suspension geometry)
	float rearToe;										// Rear toe angle (suspension geometry)
	uint8 frontSuspension, rearSuspension;
	uint8 frontAntiRollBar,rearAntiRollBar;
	uint8 frontSuspensionHeight, rearSuspensionHeight;	
	uint8 brakePressure;
	uint8 brakeBias;
	float frontTyrePressure, rearTyrePressure;			// in PSI
	uint8 ballast;
	float fuelLoad;
};

struct CarSetupPacket {
	PacketHeader header;

	std::array<CarSetup, 20> carSetup;
};
#pragma pack(pop)
