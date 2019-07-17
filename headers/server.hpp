#pragma once

#include <sys/socket.h>
#include <arpa/inet.h>

#include "packet.hpp"

class Server {
public:
	Server() = default;

	void run();
	bool init();

	void stop();

private:
	bool running = true;
	int socketfd;
	sockaddr_in serverAddress;
	sockaddr_in clientAddress;

	void analyzePacket(Packet);

	void analyzeCarSetups(CarSetupPacket&);
	void analyzeCarStatus(CarStatusPacket&);
	void analyzeCarTelemetry(CarTelemetryPacket&);
	void analyzeEvent(EventPacket&);
	void analyzeLapData(LapDataPacket&);
	void analyzeMotion(MotionPacket&);
	void analyzeParticipants(ParticipantsPacket&);
	void analyzeSession(SessionPacket&);
};
