#pragma once

/*
	This is a list of participants in the race.If the vehicle is controlled by AI, then the name will be the driver name.If this is a multiplayer game, the names will be the Steam Id on PC, or the LAN name if appropriate.
	N.B.on Xbox One, the names will always be the driver name, on PS4 the name will be the LAN name if playing a LAN game, otherwise it will be the driver name.
	The array should be indexed by vehicle index.

	Frequency: Every 5 seconds
	Size : 1104 bytes
*/

#include <array>

#include "packetHeader.hpp"

constexpr uint16 ParticipantsPacketSize = 1104;

enum Driver : uint8 {
	CARLOS_SAINZ = 0,
	PETER_BELOUSOV = 37,
	RUBEN_MEIJER = 69,
	DANIIL_KVYAT = 1,
	KLIMEK_MICHALSKI = 38,
	RASHID_NAIR = 70,
	DANIEL_RICCIARDO = 2,
	SANTIAGO_MORENO = 39,
	JACK_TREMBLAY = 71,
	KIMI_RÄIKKÖNEN = 6,
	BENJAMIN_COPPENS = 40,
	ANTONIO_GIOVINAZZI = 74,
	LEWIS_HAMILTON = 7,
	NOAH_VISSER = 41,
	ROBERT_KUBICA = 75,
	MAX_VERSTAPPEN = 9,
	GERT_WALDMULLER = 42,
	NICO_HULKENBURG = 10,
	JULIAN_QUESADA = 43,
	KEVIN_MAGNUSSEN = 11,
	DANIEL_JONES = 44,
	ROMAIN_GROSJEAN = 12,
	ARTEM_MARKELOV = 45,
	SEBASTIAN_VETTEL = 13,
	TADASUKE_MAKINO = 46,
	SERGIO_PEREZ = 14,
	SEAN_GELAEL = 47,
	VALTTERI_BOTTAS = 15,
	NYCK_DE_VRIES = 48,
	LANCE_STROLL = 19,
	JACK_AITKEN = 49,
	ARRON_BARNES = 20,
	GEORGE_RUSSELL = 50,
	MARTIN_GILES = 21,
	MAXIMILIAN_GÜNTHER = 51,
	ALEX_MURRAY = 22,
	NIREI_FUKUZUMI = 52,
	LUCAS_ROTH = 23,
	LUCA_GHIOTTO = 53,
	IGOR_CORREIA = 24,
	LANDO_NORRIS = 54,
	SOPHIE_LEVASSEUR = 25,
	SÉRGIO_SETTE_CÂMARA = 55,
	JONAS_SCHIFFER = 26,
	LOUIS_DELÉTRAZ = 56,
	ALAIN_FOREST = 27,
	ANTONIO_FUOCO = 57,
	JAY_LETOURNEAU = 28,
	CHARLES_LECLERC = 58,
	ESTO_SAARI = 29,
	PIERRE_GASLY = 59,
	YASAR_ATIYEH = 30,
	ALEXANDER_ALBON = 62,
	CALLISTO_CALABRESI = 31,
	NICHOLAS_LATIFI = 63,
	NAOTA_IZUM = 32,
	DORIAN_BOCCOLACCI = 64,
	HOWARD_CLARKE = 33,
	NIKO_KARI = 65,
	WILHEIM_KAUFMANN = 34,
	ROBERTO_MERHI = 66,
	MARIE_LAURSEN = 35,
	ARJUN_MAINI = 67,
	FLAVIO_NIEVES = 36,
	ALESSIO_LORANDI = 68
};

enum Team : uint8 {
	MERCEDES = 0,
	RED_BULL_2010 = 21,
	FERRARI_1990 = 63,
	FERRARI = 1,
	FERRARI_1976 = 22,
	MCLAREN_2010 = 64,
	RED_BULL_RACING = 2,
	ART_GRAND_PRIX = 23,
	FERRARI_2010 = 65,
	WILLIAMS = 3,
	CAMPOS_VEXATEC_RACING = 24,
	RACING_POINT = 4,
	CARLIN = 25,
	RENAULT = 5,
	CHAROUZ_RACING_SYSTEM = 26,
	TORO_ROSSO = 6,
	DAMS = 27,
	HAAS = 7,
	RUSSIAN_TIME = 28,
	MCLAREN = 8,
	MP_MOTORSPORT = 29,
	ALFA_ROMEO = 9,
	PERTAMINA = 30,
	MCLAREN_1988 = 10,
	MCLAREN_1990 = 31,
	MCLAREN_1991 = 11,
	TRIDENT = 32,
	WILLIAMS_1992 = 12,
	BWT_ARDEN = 33,
	FERRARI_1995 = 13,
	MCLAREN_1976 = 34,
	WILLIAMS_1996 = 14,
	LOTUS_1972 = 35,
	MCLAREN_1998 = 15,
	FERRARI_1979 = 36,
	FERRARI_2002 = 16,
	MCLAREN_1982 = 37,
	FERRARI_2004 = 17,
	WILLIAMS_2003 = 38,
	RENAULT_2006 = 18,
	BRAWN_2009 = 39,
	FERRARI_2007 = 19,
	LOTUS_1978 = 40
};

enum Nationality : uint8 {
	AMERICAN = 1,
	GREEK = 31,
	PANAMANIAN = 61,
	ARGENTINEAN = 2,
	GUATEMALAN = 32,
	PARAGUAYAN = 62,
	AUSTRALIAN = 3,
	HONDURAN = 33,
	PERUVIAN = 63,
	AUSTRIAN = 4,
	HONG_KONGER = 34,
	POLISH = 64,
	AZERBAIJANI = 5,
	HUNGARIAN = 35,
	PORTUGUESE = 65,
	BAHRAINI = 6,
	ICELANDER = 36,
	QATARI = 66,
	BELGIAN = 7,
	INDIAN = 37,
	ROMANIAN = 67,
	BOLIVIAN = 8,
	INDONESIAN = 38,
	RUSSIAN = 68,
	BRAZILIAN = 9,
	IRISH = 39,
	SALVADORAN = 69,
	BRITISH = 10,
	ISRAELI = 40,
	SAUDI = 70,
	BULGARIAN = 11,
	ITALIAN = 41,
	SCOTTISH = 71,
	CAMEROONIAN = 12,
	JAMAICAN = 42,
	SERBIAN = 72,
	CANADIAN = 13,
	JAPANESE = 43,
	SINGAPOREAN = 73,
	CHILEAN = 14,
	JORDANIAN = 44,
	SLOVAKIAN = 74,
	CHINESE = 15,
	KUWAITI = 45,
	SLOVENIAN = 75,
	COLOMBIAN = 16,
	LATVIAN = 46,
	SOUTH_KOREAN = 76,
	COSTA_RICAN = 17,
	LEBANESE = 47,
	SOUTH_AFRICAN = 77,
	CROATIAN = 18,
	LITHUANIAN = 48,
	SPANISH = 78,
	CYPRIOT = 19,
	LUXEMBOURGER = 49,
	SWEDISH = 79,
	CZECH = 20,
	MALAYSIAN = 50,
	SWISS = 80,
	DANISH = 21,
	MALTESE = 51,
	THAI = 81,
	DUTCH = 22,
	MEXICAN = 52,
	TURKISH = 82,
	ECUADORIAN = 23,
	MONEGASQUE = 53,
	URUGUAYAN = 83,
	ENGLISH = 24,
	NEW_ZEALANDER = 54,
	UKRAINIAN = 84,
	EMIRIAN = 25,
	NICARAGUAN = 55,
	VENEZUELAN = 85,
	ESTONIAN = 26,
	NORTH_KOREAN = 56,
	WELSH = 86,
	FINNISH = 27,
	NORTHERN_IRISH = 57,
	FRENCH = 28,
	NORWEGIAN = 58,
	GERMAN = 29,
	OMANI = 59,
	GHANAIAN = 30,
	PAKISTANI = 60
};

#pragma pack(push, 1)
struct Participant {
	bool aiControlled;
	Driver driverId;
	Team teamId;
	uint8 raceNumber;
	Nationality nationality;
	char name[48];			// Name of participant in UTF-8 format – null terminated; Will be truncated with … (U+2026) if too long
	bool publicTelemetry;
};

struct ParticipantsPacket {
	PacketHeader header;

	uint8 numActiveCars;
	std::array<Participant, 20> participants;
};
#pragma pack(pop)
