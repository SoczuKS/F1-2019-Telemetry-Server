#pragma once

#include <string>
#include <ctime>

class Logger {
public:
	static void generateLogRecord(std::string, int);

private:
	Logger() = delete;
};