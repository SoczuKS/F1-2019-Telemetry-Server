#pragma once

#include <sys/socket.h>
#include <arpa/inet.h>

#include "packets.hpp"

constexpr uint16 MaxSize = CarTelemetryPacketSize;

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

	void analyzePacket();
};
