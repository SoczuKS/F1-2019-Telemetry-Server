#pragma once

#include <string>
#include <array>

#include "types.hpp"

constexpr uint8 propertiesNum = 3;

enum Format { FORMAT_2019 = 0, FORMAT_2018, FORMAT_OLD };	// Currently using only the latest format
constexpr std::array<uint8, 4> frequencies = { 10, 20, 30, 60 };

class Config {
public:
	static Config& instance() {
		static Config cfg;
		return cfg;
	}

	~Config() { save(); }

	void save();
	void reset();

private:
	Config() { load(); }
	Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;

	uint16 frequency; // in Hertz
	Format format;
	uint32 port;

	const std::string configFileName = "config.cfg";

	void load();
};