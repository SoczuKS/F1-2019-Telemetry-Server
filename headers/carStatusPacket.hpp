#pragma once

/*
	This packet details car statuses for all the cars in the race. It includes values such as the damage readings on the car.
	
	Frequency: Rate as specified in menus
	Size: 1143 bytes 
*/

#include <array>

#include "packetHeader.hpp"

struct CarStatusData {
	uint8 tractionControl;          // 0 (off) - 2 (high)
	uint8 antiLockBrakes;           // 0 (off) - 1 (on)
	uint8 fuelMix;                  // 0 = lean, 1 = standard, 2 = rich, 3 = max
	uint8 frontBrakeBias;           // percentage
	uint8 pitLimiterStatus;         // 0 = off, 1 = on
	float fuelInTank;
	float fuelCapacity;
	float fuelRemainingLaps;        // Fuel remaining in terms of laps (value on MFD)
	uint16 maxRPM, idleRPM;
	uint8 maxGears;
	uint8 drsAllowed;					// 0 = not allowed, 1 = allowed, -1 = unknown
	std::array<uint8, 4> tyresWear;     //  percentage

	uint8 actualTyreCompound;			// F1 Modern - 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1, 7 = inter, 8 = wet
										// F1 Classic - 9 = dry, 10 = wet
										// F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard, 15 = wet

	uint8 tyreVisualCompound;			//  16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
	std::array<uint8, 4> tyresDamage;	// percentage
	uint8 frontLeftWingDamage, frontRightWingDamage, rearWingDamage, engineDamage, gearBoxDamage;	// percentage
	int8 vehicleFiaFlags;			// -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
	float ersStoreEnergy;           // ERS energy store in Joules
	uint8 ersDeployMode;            // 0 = none, 1 = low, 2 = medium,3 = high, 4 = overtake, 5 = hotlap
	float ersHarvestedThisLapMGUK;
	float ersHarvestedThisLapMGUH;
	float ersDeployedThisLap;
};

struct PacketCarStatusData {
	PacketHeader header;

	std::array<CarStatusData, 20> carStatusData;
};
