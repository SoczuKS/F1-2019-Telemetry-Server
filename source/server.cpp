#include "../headers/server.hpp"

#include "../headers/logger.hpp"
#include "../headers/config.hpp"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <thread>
#include <iostream>

bool Server::init() {
	if ((this->socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		Logger::generateLogRecord("Cannot create socket file descriptor", LOG_CRIT);
		return false;
	}

	memset(&this->serverAddress, 0, sizeof(sockaddr_in));
	memset(&this->clientAddress, 0, sizeof(sockaddr_in));

	this->serverAddress.sin_family = AF_INET;
	this->serverAddress.sin_addr.s_addr = INADDR_ANY;
	this->serverAddress.sin_port = htons(Config::instance().getPort());

	if (bind(this->socketfd, reinterpret_cast<sockaddr*>(&this->serverAddress), sizeof(this->serverAddress)) < 0) {
		Logger::generateLogRecord("Bind failed", LOG_CRIT);
		return false;
	}

	return true;
}

void Server::run() {
	char buffer[MaxSize];
	unsigned int length;
	ssize_t packetSize;

	while (running) {
		packetSize = recvfrom(socketfd, &buffer, MaxSize, MSG_DONTWAIT, reinterpret_cast<sockaddr*>(&clientAddress), &length);

		if (packetSize > 0) {
			std::cout << packetSize << ' ';
		}
	}
}

void Server::stop() {
	running = false;
}

void Server::analyzePacket() {

}