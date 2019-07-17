#pragma once

/*
	This is a list of participants in the race.If the vehicle is controlled by AI, then the name will be the driver name.If this is a multiplayer game, the names will be the Steam Id on PC, or the LAN name if appropriate.
	N.B.on Xbox One, the names will always be the driver name, on PS4 the name will be the LAN name if playing a LAN game, otherwise it will be the driver name.
	The array should be indexed by vehicle index.

	Frequency: Every 5 seconds
	Size : 1104 bytes
*/

#include <array>

#include "packetHeader.hpp"

constexpr uint16 ParticipantsPacketSize = 1104;

#pragma pack(push, 1)
struct Participant {
	uint8      aiControlled;	// 0 = Human, 1 = AI
	uint8      driverId;
	uint8      teamId;
	uint8      raceNumber;
	uint8      nationality;
	char       name[48];		// Name of participant in UTF-8 format – null terminated; Will be truncated with … (U+2026) if too long
	uint8      yourTelemetry;	// 0 = restricted, 1 = public
};

struct ParticipantsPacket {
	PacketHeader    header;

	uint8           numActiveCars;
	std::array<Participant, 20> participants;
};
#pragma pack(pop)
