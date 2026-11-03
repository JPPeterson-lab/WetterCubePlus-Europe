# Changelog

## v0.1.0-beta9 (2026-11-08)

- **Set up Wi-Fi over the USB cable:** in setup mode the device accepts the Wi-Fi name and password over the USB cable (Improv Serial, through the UART port and through the built-in USB port). WetterCube Control and the web installer can send them to the device, you do not have to connect to the setup Wi-Fi. The device tries the connection and only saves it on success. The password is never written to the log.
- **Updates from our own website:** the device asks for new versions at `wettercube.de/dl/europe` and downloads the firmware from there; if the website does not answer it falls back to GitHub as before. The privacy notes in the setup and in the settings now name `wettercube.de` (GitHub as a fallback).
