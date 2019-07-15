#pragma once

#include "types.hpp"

class Config {
public:
	static Config& instance() {
		static Config cfg;
		return cfg;
	}

private:
	Config() = default;
	Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;

	uint8_t 
};