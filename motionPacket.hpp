#pragma once

/*
	The motion packet gives physics data for all the cars being driven.There is additional data for the car being driven with the goal of being able to drive a motion platform setup.
	N.B.For the normalised vectors below, to convert to float values divide by 32767.0f – 16 - bit signed values are used to pack the data and on the assumption that direction values are always between - 1.0f and 1.0f.

	Frequency: Rate as specified in menus
	Size : 1343 bytes
*/

#include <array>

#include "packetHeader.hpp"

struct CarMotionData {
	float worldPositionX, worldPositionY, worldPositionZ;
	float worldVelocityX, worldVelocityY, worldVelocityZ;
	int16 worldForwardDirX, worldForwardDirY, worldForwardDirZ;
	int16 worldRightDirX, worldRightDirY, worldRightDirZ;
	float gForceLateral, gForceLongitudinal, gForceVertical;
	float yaw, pitch, roll;
};

struct PacketMotionData {
	PacketHeader header;

	std::array<CarMotionData, 20> carMotionData;

	// Extra player car ONLY data
	// Each wheel array have the following order: RearLeft, RearRight, FrontLeft, FrontRight
	std::array<float, 4> suspensionPosition, suspensionVelocity, suspensionAcceleration;
	std::array<float, 4> wheelSpeed, wheelSlip;
	float localVelocityX, localVelocityY, localVelocityZ;
	float angularVelocityX, angularVelocityY, angularVelocityZ;
	float angularAccelerationX, angularAccelerationY, angularAccelerationZ;
	float frontWheelsAngle;
};
