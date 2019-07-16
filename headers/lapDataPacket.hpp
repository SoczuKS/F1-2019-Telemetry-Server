#pragma once

/*
	The lap data packet gives details of all the cars in the session.

	Frequency: Rate as specified in menus
	Size : 843 bytes
*/

#include <array>

#include "packetHeader.hpp"

struct LapData {
	float       lastLapTime;		// in seconds
	float       currentLapTime;		// in seconds
	float       bestLapTime;		// in seconds
	float       sector1Time;		// in seconds
	float       sector2Time;		// in seconds
	float       lapDistance;		// Distance vehicle is around current lap in metres – could be negative if line hasn’t been crossed yet
	float       totalDistance;		// in metres – could be negative if line hasn’t been crossed yet
	float       safetyCarDelta;		// in seconds
	uint8       carPosition;
	uint8       currentLapNum;
	uint8       pitStatus;			// 0 = none, 1 = pitting, 2 = in pit area
	uint8       sector;				// 0 = sector1, 1 = sector2, 2 = sector3
	uint8       currentLapInvalid;	// 0 = valid, 1 = invalid
	uint8       penalties;			// in seconds, accumulated
	uint8       gridPosition;
	uint8       driverStatus;		// 0 = in garage, 1 = flying lap, 2 = in lap, 3 = out lap, 4 = on track
	uint8       resultStatus;		// 0 = invalid, 1 = inactive, 2 = active, 3 = finished, 4 = disqualified, 5 = not classified, 6 = retired
};

struct PacketLapData {
	PacketHeader header;

	std::array<LapData, 20> lapData;
};
