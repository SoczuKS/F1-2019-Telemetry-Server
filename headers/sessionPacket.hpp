#pragma once

/*
	The session packet includes details about the current session in progress.

	Frequency: 2 per second
	Size : 149 bytes
*/

#include <array>

#include "packetHeader.hpp"

constexpr uint16 SessionPacketSize = 149;

struct MarshalZone {
	float zoneStart;	// Fraction (0..1) of way through the lap the marshal zone starts
	int8 zoneFlag;		// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
};

struct SessionPacket {
	PacketHeader    header;

	uint8           weather;              		// 0 = clear, 1 = light cloud, 2 = overcast, 3 = light rain, 4 = heavy rain, 5 = storm
	int8	        trackTemperature;    		// in degrees celsius
	int8	        airTemperature;      		// in degrees celsius
	uint8           totalLaps;           		// Total number of laps in this race
	uint16          trackLength;           		// in metres
	uint8           sessionType;         		// 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2, 12 = Time Trial
	int8            trackId;         			// -1 for unknown, 0-21 for tracks, see appendix
	uint8           formula;					// 0 = F1 Modern, 1 = F1 Classic, 2 = F2, 3 = F1 Generic
	uint16          sessionTimeLeft;    		// in seconds
	uint16          sessionDuration;     		// in seconds
	uint8           pitSpeedLimit;      		// in Kph
	uint8           gamePaused;
	uint8           isSpectating;
	uint8           spectatorCarIndex;
	uint8           sliProNativeSupport;		// 0 = inactive, 1 = active
	uint8           numMarshalZones;
	std::array<MarshalZone, 21> marshalZones;
	uint8           safetyCarStatus;			// 0 = no safety car, 1 = full safety car, 2 = virtual safety car
	uint8           networkGame;				// 0 = offline, 1 = online
};
