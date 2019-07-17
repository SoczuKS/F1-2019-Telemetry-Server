#include <iostream>
#include <memory>
#include <csignal>

#include "../headers/logger.hpp"
#include "../headers/server.hpp"

std::shared_ptr<Server> server;

void signalHandler(int signum) {
	if (signum == SIGINT || signum == SIGTERM || signum == SIGQUIT || signum == SIGABRT) {
		server->stop();
	}
}

int main(int argc, char* arg[]) {
	signal(SIGINT, signalHandler);
	signal(SIGTERM, signalHandler);
	signal(SIGQUIT, signalHandler);
	signal(SIGABRT, signalHandler);

	server = std::make_shared<Server>();

	openlog("F1 2019 Telemetry", LOG_CONS | LOG_NDELAY | LOG_PERROR, LOG_USER);

	if (!server->init()) {
		std::cerr << "Failed to initialize server. See logs";
		return 1;
	}

	server->run();

	closelog();
	return 0;
}