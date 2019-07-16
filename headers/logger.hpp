#pragma once

#include <string>
#include <ctime>

#include <syslog.h>

class Logger {
public:
	static void generateLogRecord(std::string, int);

private:
	Logger() = delete;
};