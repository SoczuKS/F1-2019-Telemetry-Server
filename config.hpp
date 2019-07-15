#pragma once

#include "types.hpp"

enum Format { FORMAT_2019, FORMAT_2018, FORMAT_OLD };	// Currently using only the latest format

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

	uint8_t frequency;
	Format format;
};