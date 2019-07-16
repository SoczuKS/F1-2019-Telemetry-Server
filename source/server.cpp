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
	ssize_t n;

	while (running) {
		n = recvfrom(socketfd, static_cast<char*>(buffer), MaxSize, MSG_WAITALL, reinterpret_cast<sockaddr*>(&clientAddress), &length);
		buffer[n] = '\0';

		std::cout << buffer;
	}
}

void Server::stop() {
	running = false;
}

void Server::analyzePacket() {

}