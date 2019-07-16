#pragma once

#include <string>
#include <array>

#include "types.hpp"

constexpr uint8 propertiesNum = 3;

enum Format { FORMAT_2019 = 0, FORMAT_2018, FORMAT_OLD };	// Currently using only the latest format
constexpr std::array<uint16, 4> frequencies = { 10, 20, 30, 60 };

class Config {
public:
	static Config& instance() {
		static Config cfg;
		return cfg;
	}

	~Config() { save(); }

	void save();
	void reset();

	uint16 getFrequency() const { return frequency; }
	void setFrequency(const uint16 freq) {
		for (auto f : frequencies) {
			if (f == freq) {
				frequency = freq;
				return;
			}
		}
	}

	Format getFormat() const { return format; }
	void setFormat(const Format f) { format = f; }

	uint32 getPort() const { return port; }
	void setPort(uint32 p) { if (p > 0 && p <= 65535) port = p; }

private:
	Config() { load(); }
	Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;

	uint16 frequency;	// in Hertz
	Format format;
	uint32 port;

	const std::string configFileName = "config.cfg";

	void load();
};
