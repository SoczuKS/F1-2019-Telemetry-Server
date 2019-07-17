#pragma once

#include <string>
#include <array>

#include "types.hpp"

constexpr uint8 propertiesNum = 2;

enum Format { FORMAT_2019 = 0, FORMAT_2018, FORMAT_OLD };	// Currently using only the latest format

class Config {
public:
	static Config& instance() {
		static Config cfg;
		return cfg;
	}

	~Config() { save(); }

	void save();
	void reset();

	Format getFormat() const { return format; }
	void setFormat(const Format f) { format = f; }

	uint16 getPort() const { return port; }
	void setPort(uint16 p) { port = p; }

private:
	Config() { load(); }
	Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;

	Format format;
	uint16 port;

	const std::string configFileName = "config.cfg";

	void load();
};
