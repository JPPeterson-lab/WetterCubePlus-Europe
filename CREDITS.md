# Credits and third-party licences

This project uses third-party resources. Their licence terms are listed below.

---

## Weather icons

**Source:** [Meteocons](https://github.com/basmilius/weather-icons) by Bas Milius

**Licence:** MIT License (Copyright (c) 2020-present Bas Milius)

Used icons (style "Fill", static variant, embedded as PNG with 128×128 pixels and as arrays for LVGL; files in `src/ui/images/`): clear, partly cloudy, rain showers, snow showers (day and night), overcast, fog, mist, rain, rain with thunder, thunder, sleet, snow, and the alert icon.

Change from the original: the outline of the clouds and the fog stripes was set to a medium blue-grey (`#94A3B8`) so that they stay visible on the light colour theme.

```
MIT License

Copyright (c) 2020-present Bas Milius

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

## Control icons

**Source:** [Icons8 Flat Color Icons](https://github.com/icons8/flat-color-icons) – © Icons8

**Licence:** The icons are available under the MIT licence **or** the [Good Boy License](https://icons8.com/good-boy-license/) of Icons8 (according to their [LICENSE.md](https://github.com/icons8/flat-color-icons/blob/master/LICENSE.md)). Downloading, changing and redistributing, also commercially, is allowed; attribution is not required but gladly given here.

Used icons (embedded as PNG and as arrays for LVGL): home, settings (gear), left and right arrows, diagonal arrows, plus, calculator, and the game icon (Bubblebreaker).

---

## Weather data

**Source:** [Open-Meteo](https://open-meteo.com) – weather, pollen, air quality, location search

"Weather data by [Open-Meteo.com](https://open-meteo.com)". Licence and sources of the data: [open-meteo.com/en/licence](https://open-meteo.com/en/licence). The values are converted and summarised by the WetterCube (for example pollen levels and daily highs). Locations are searched through the geocoding interface, whose data comes from [GeoNames](https://www.geonames.org) (CC BY 4.0).

**Licence of the data:** [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/) (attribution, Open-Meteo.com). The free API is meant for **non-commercial** use only ([terms](https://open-meteo.com/en/terms)), no API key is required. The forecasts are based on models of national weather services such as DWD, NOAA, ECMWF and Météo-France (details: [open-meteo.com/en/docs](https://open-meteo.com/en/docs)).

**Pollen and air quality:** Data of the **Copernicus Atmosphere Monitoring Service (CAMS)** of ECMWF, provided through Open-Meteo. "Contains modified Copernicus Atmosphere Monitoring Service information." Neither the European Commission nor ECMWF is responsible for the use of the data.

The notices on the display (thunderstorm, heavy rain, heat, snow or ice, air quality, pressure change and others) are calculated by the device from this forecast data. They are **not** official weather warnings.

---

## Font

**Source:** [Montserrat](https://github.com/JulietaUla/Montserrat) – © The Montserrat Project Authors

**Licence:** [SIL Open Font License 1.1](https://openfontlicense.org)

The Montserrat font is included in several sizes as converted C files (`src/ui/fonts/`). The OFL allows embedding the font in software; the font itself must not be sold on its own.

---

## Libraries and framework

When you build the firmware yourself, these libraries are installed through the Arduino library manager; they are compiled into the published firmware files. Their sources are not part of this repository.

| Library | Licence |
|---|---|
| [LVGL](https://lvgl.io) (Light and Versatile Graphics Library), includes [LodePNG](https://lodev.org/lodepng/) | MIT; LodePNG: zlib |
| [LovyanGFX](https://github.com/lovyan03/LovyanGFX) (display and touch driver) | MIT and BSD-2-Clause |
| [ArduinoJson](https://arduinojson.org) | MIT |
| [Arduino-ESP32](https://github.com/espressif/arduino-esp32) (framework) | LGPL 2.1 |
| [ESP-IDF](https://github.com/espressif/esp-idf) (underneath) | Apache 2.0 |

The sources of this project are fully public, so you can always build the firmware yourself.

---

## Project licence

The source code is licensed under the **Apache License 2.0**, see [LICENSE](LICENSE) and [NOTICE](NOTICE). Texts, images and documentation are licensed under **CC BY-NC 4.0** ([LICENSE-Dokumentation.txt](LICENSE-Dokumentation.txt)). The 3D-print files of the case (in the repository of the WetterCubePlus and on Bambu MakerWorld) are licensed under **CC BY-NC-SA 4.0**.

The third-party resources named above keep their own licences (Meteocons: MIT, Icons8: MIT or Good Boy License, Montserrat: SIL OFL 1.1, libraries see above) and are not covered by the licence of this project.
