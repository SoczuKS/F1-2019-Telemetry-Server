#pragma once

/*
	This packet details car statuses for all the cars in the race. It includes values such as the damage readings on the car.
	
	Frequency: Rate as specified in menus
	Size: 1143 bytes 
*/

#include <array>

#include "packetHeader.hpp"

enum class FuelMix : uint8 { LEAN, STANDARD, RICH, MAX };

enum class TyreCompound : uint8 { C5 = 16, C4, C3, C2, C1, INTERMEDIATE = 7, WET, CLASSIC_DRY, CLASSIC_WET, F2_SUPERSOFT, F2_SOFT, F2_MEDIUM, F2_HARD, F2_WET};

enum class VisualTyreCompound : uint8 { SOFT = 16, MEDIUM, HARD, INTERMEDIATE = 7, WET };

enum class ERSMode : uint8 { NONE, LOW, MEDIUM, HIGH, OVERTAKE, HOTLAP };

enum class VehicleFIAFlags : int8 { UNKNOWN_INVALID = -1, NONE, GREEN, BLUE, YELLOW, RED };

constexpr uint16 CarStatusPacketSize = 1143;

#pragma pack(push, 1)
struct CarStatus {
	uint8 tractionControl;				// 0 (off) - 2 (high)
	bool antiLockBrakes;
	FuelMix fuelMix;
	uint8 frontBrakeBias;				// percentage
	bool pitLimiterStatus;
	float fuelInTank;
	float fuelCapacity;
	float fuelRemainingLaps;			// Fuel remaining in terms of laps (value on MFD)
	uint16 maxRPM, idleRPM;
	uint8 maxGears;
	uint8 drsAllowed;					// 0 = not allowed, 1 = allowed, -1 = unknown

	TyreCompound actualTyreCompound;
	uint8 tyreVisualCompound;

	std::array<uint8, 4> tyresWear;     // percentage
	std::array<uint8, 4> tyresDamage;	// percentage
	uint8 frontLeftWingDamage, frontRightWingDamage, rearWingDamage, engineDamage, gearBoxDamage;	// percentage

	VehicleFIAFlags vehicleFiaFlags;
	float ersStoreEnergy;				// ERS energy store in Joules
	ERSMode ersDeployMode;
	float ersHarvestedThisLapMGUK;
	float ersHarvestedThisLapMGUH;
	float ersDeployedThisLap;
};

struct CarStatusPacket {
	PacketHeader header;

	std::array<CarStatus, 20> carStatus;
};
#pragma pack(pop)
