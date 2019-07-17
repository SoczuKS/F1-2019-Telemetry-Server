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
#include <pthread.h>

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
	Packet packet;
	long packetSize;
	uint32 length;

	while (running) {
		packetSize = recvfrom(socketfd, &packet.rawData, MaxSize, MSG_DONTWAIT, reinterpret_cast<sockaddr*>(&clientAddress), &length);

		if (packetSize > 0) {
			auto functor = [this](const Packet& packet) { analyzePacket(packet); };

			std::thread analyzeThread(functor, packet);
		}
	}
}

void Server::stop() {
	running = false;
}

void Server::analyzePacket(Packet packet) {
	// TODO: read header


	switch (packet.header.packetId) {
		case PacketID::PACKET_CARSETUPS:
			analyzeCarSetups(packet.carSetup);
			break;

		case PacketID::PACKET_CARSTATUS:
			analyzeCarStatus(packet.carStatus);
			break;

		case PacketID::PACKET_CARTELEMETRY:
			analyzeCarTelemetry(packet.carTelemetry);
			break;

		case PacketID::PACKET_EVENT:
			analyzeEvent(packet.event);
			break;

		case PacketID::PACKET_LAPDATA:
			analyzeLapData(packet.lapData);
			break;

		case PacketID::PACKET_MOTION:
			analyzeMotion(packet.motion);
			break;

		case PacketID::PACKET_PARTICIPANTS:
			analyzeParticipants(packet.participants);
			break;

		case PacketID::PACKET_SESSION:
			analyzeSession(packet.session);
			break;
	}
}

void Server::analyzeCarSetups(CarSetupPacket& packet) {

}

void Server::analyzeCarStatus(CarStatusPacket& packet) {

}

void Server::analyzeCarTelemetry(CarTelemetryPacket& packet) {

}

void Server::analyzeEvent(EventPacket& packet) {

}

void Server::analyzeLapData(LapDataPacket& packet) {

}

void Server::analyzeMotion(MotionPacket& packet) {

}

void Server::analyzeParticipants(ParticipantsPacket& packet) {

}

void Server::analyzeSession(SessionPacket& packet) {

}