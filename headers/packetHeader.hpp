#pragma once

#include "types.hpp"

enum PacketID : uint8 {
	PACKET_MOTION = 0,
	PACKET_SESSION = 1,
	PACKET_LAPDATA = 2,
	PACKET_EVENT = 3,
	PACKET_PARTICIPANTS = 4,
	PACKET_CARSETUPS = 5,
	PACKET_CARTELEMETRY = 6,
	PACKET_CARSTATUS = 7
};

#pragma pack(push, 1)
struct PacketHeader {
	uint16 packetFormat;
	uint8 gameMajorVersion;
	uint8 gameMinorVersion;
	uint8 packetVersion;
	PacketID packetId;
	uint64 sessionUID;
	float sessionTime;
	uint32 frameIdentifier;
	uint8 playerCarIndex;
};
#pragma pack(pop)
