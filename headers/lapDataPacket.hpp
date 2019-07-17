#pragma once

/*
	The lap data packet gives details of all the cars in the session.

	Frequency: Rate as specified in menus
	Size : 843 bytes
*/

#include <array>

#include "packetHeader.hpp"

enum class DriverStatus : uint8 { IN_GARAGE, FLYING_LAP, IN_LAP, OUT_LAP, ON_TRACK };

enum class Sector : uint8 { SECTOR1, SECTOR2, SECTOR3 };

enum class PitStatus : uint8 { NONE, PITTING, IN_PIT_AREA };

enum class ResultStatus : uint8 { INVALID, INACTIVE, ACTIVE, FINISHED, DISQUALIFIED, NOT_CLASSIFIED, RETIRED };

constexpr uint16 LapDataPacketSize = 843;

#pragma pack(push, 1)
struct LapData {
	float lastLapTime;		// in seconds
	float currentLapTime;	// in seconds
	float bestLapTime;		// in seconds
	float sector1Time;		// in seconds
	float sector2Time;		// in seconds
	float lapDistance;		// Distance vehicle is around current lap in metres – could be negative if line hasn’t been crossed yet
	float totalDistance;	// in metres – could be negative if line hasn’t been crossed yet
	float safetyCarDelta;	// in seconds
	uint8 carPosition;
	uint8 currentLapNum;
	PitStatus pitStatus;
	uint8 sector;
	bool currentLapInvalid;
	uint8 penalties;		// in seconds, accumulated
	uint8 gridPosition;
	DriverStatus driverStatus;
	ResultStatus resultStatus;
};

struct LapDataPacket {
	PacketHeader header;

	std::array<LapData, 20> lapData;
};
#pragma pack(pop)
