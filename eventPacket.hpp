#pragma once

/*
	This packet gives details of events that happen during the course of a session.

	Frequency: When the event occurs
	Size : 32 bytes
*/

#include <array>

#include "packetHeader.hpp"

// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
union EventDataDetails {
	struct {
		uint8 vehicleIdx; // Vehicle index of car achieving fastest lap
		float lapTime;    // Lap time is in seconds
	} FastestLap;

	struct {
		uint8 vehicleIdx; // Vehicle index of car retiring
	} Retirement;

	struct {
		uint8 vehicleIdx; // Vehicle index of team mate
	} TeamMateInPits;

	struct {
		uint8 vehicleIdx; // Vehicle index of the race winner
	} RaceWinner;
};

struct PacketEventData {
	PacketHeader header;

	std::array<uint8, 4> eventStringCode;	// Event string code, see below
	EventDataDetails eventDetails;			// Event details - should be interpreted differently for each type
};

/*
	Event String Codes

	Session Started "SSTA" Sent when the session starts
	Session Ended "SEND" Sent when the session ends
	Fastest Lap "FTLP" When a driver achieves the fastest lap
	Retirement "RTMT" When a driver retires
	DRS enabled "DRSE" Race control have enabled DRS
	DRS disabled "DRSD" Race control have disabled DRS
	Team mate in pits "TMPT" Your team mate has entered the pits
	Chequered flag "CHQF" The chequered flag has been waved
	Race Winner "RCWN" The race winner is announced
*/
