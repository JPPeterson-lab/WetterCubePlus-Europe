# Changelog

## v0.1.0-beta8 (2026-11-05)

- **Read-only status page for other programs:** The device now answers `/api/status` with the current values (temperature, weather, air quality, number of warnings) as JSON. It needs no password and cannot change anything, like the existing traffic-light interface `/api/ampel`; like every page of the device it is only reachable in your home network and only with the device's own address. It is meant for companion programs and smart-home tools in your own network.
