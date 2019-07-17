#pragma once

/*
	The session packet includes details about the current session in progress.

	Frequency: 2 per second
	Size : 149 bytes
*/

#include <array>

#include "packetHeader.hpp"

enum class Track : int8 {
	UNKNOWN = -1,
	AUSTRALIA,
	FRANCE,
	CHINA,
	BAHRAIN,
	SPAIN,
	MONACO,
	CANADA,
	GREATBRITAIN,
	GERMANY,
	HUNGARY,
	BELGIUM,
	ITALY,
	SINGAPORE,
	JAPAN,
	UAE,
	USA,
	BRAZIL,
	AUSTRIA,
	RUSSIA,
	MEXICO,
	AZERBAIJAN,
	BAHRAIN_SHORT,
	GREATBRITAIN_SHORT,
	USA_SHORT,
	JAPAN_SHORT,
};

enum class Formula : uint8 { F1_MODERN, F1_CLASSIC, F2, F1_GENERIC };

enum class SessionType : uint8 { UNKNOWN, FP1, FP2, FP3, SP, Q1, Q2, Q3, SQ, OSQ, R, R2, TIME_TRIAL };

enum class SafetyCarStatus : uint8 { NO_SAFETY_CAR, FULL_SAFETY_CAR, VIRTUAL_SAFETY_CAR };

enum class Weather : uint8 { CLEAR, LIGHT_CLOUD, OVERCAST, LIGHT_RAIN, HEAVY_RAIN, STORM };

enum class ZoneFlag : int8 { UNKNOWN_INVALID = -1, NONE, GREEN, BLUE, YELLOW, RED };

constexpr uint16 SessionPacketSize = 149;

#pragma pack(push, 1)
struct MarshalZone {
	float zoneStart;	// Fraction (0..1) of way through the lap the marshal zone starts
	ZoneFlag zoneFlag;
};

struct SessionPacket {
	PacketHeader header;

	Weather weather;
	int8 trackTemperature;		// in degrees celsius
	int8 airTemperature;		// in degrees celsius
	uint8 totalLaps;			// Total number of laps in this race
	uint16 trackLength;			// in metres
	SessionType sessionType;
	Track trackId;
	Formula formula;
	uint16 sessionTimeLeft;		// in seconds
	uint16 sessionDuration;		// in seconds
	uint8 pitSpeedLimit;		// in Kph
	uint8 gamePaused;
	uint8 isSpectating;
	uint8 spectatorCarIndex;
	bool sliProNativeSupport;
	uint8 numMarshalZones;
	std::array<MarshalZone, 21> marshalZones;
	SafetyCarStatus safetyCarStatus;
	bool networkGame;
};
#pragma pack(pop)
