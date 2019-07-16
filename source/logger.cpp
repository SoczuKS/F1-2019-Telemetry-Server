#include "logger.hpp"

#include <syslog.h>

void Logger::generateLogRecord(std::string entry, int priority) {
	time_t t = time(nullptr);
	struct tm* now = localtime(&t);

	char date[80];
	strftime(date, sizeof(date), "%Y-%m-%d_%H:%M:%S", now);

	std::string record = std::string(date) + " | " + entry;

	syslog(priority, record.c_str());
}