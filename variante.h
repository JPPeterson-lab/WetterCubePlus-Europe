// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Jan Althaus (JPPeterson-lab)
// Names, addresses and version of the firmware "WetterCubePlus Europe".
#pragma once

// Texts that are translated in the German WetterCubePlus: TX("deutsch", "english") -- here always English
#define TX(de, en) en
#define POLLEN_N 9      // hazel, alder, ash, birch, grass, rye, mugwort, ragweed, olive (hazel, ash, rye are not delivered for Europe)
#define POLLEN_ALLE ((1 << POLLEN_N) - 1)

// Weather, air quality and pollen from Open-Meteo (CAMS Europe); no DWD data
#define VARIANTE_NAME     "WetterCubePlus Europe"
#define FIRMWARE_VERSION "0.1.0-beta10"
// Updates: version file and firmware come from our own website (wettercube.de/dl/europe); if it does not answer, GitHub (OTA_*_URL2) is the fallback.
// The firmware comes from the same source as the version file.
#define OTA_VERSION_URL   "https://wettercube.de/dl/europe/version.json"
#define OTA_BIN_URL       "https://wettercube.de/dl/europe/firmware.bin"
#define OTA_VERSION_URL2  "https://raw.githubusercontent.com/JPPeterson-lab/WetterCubePlus-Europe/main/docs/version.json"
#define OTA_BIN_URL2      "https://jppeterson-lab.github.io/WetterCubePlus-Europe/firmware/firmware.bin"
#define MDNS_NAME         "wettercubeplus-europe"
#define SETUP_SSID        "WetterCubePlus-Europe-Setup"
#define GEO_SPRACHE       "en"
#define MIT_DWD           0
