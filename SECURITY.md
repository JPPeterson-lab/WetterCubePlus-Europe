# Security

Did you find a security vulnerability in **WetterCubePlus Europe**? Please report it **confidentially** and not as a public issue:

- through GitHub's private reporting: **Security → Report a vulnerability** in this repository, or
- by email to **info@wettercube.de** (subject "Security WetterCubePlus Europe").

Please describe what you found, which version is affected (see the web interface or `/log`) and how to reproduce it. I will answer as soon as I can and will credit you on request. This is a hobby open-source project without fixed response times and without guarantees.

Notes on safe operation (home network, passwords, updates) are in the [usage notes](https://wettercube.de/en/usage-notes/) and in the [wiki](https://wiki.wettercube.de/index.php/WetterCubePlus/Europe/en).

## Privacy

The device runs in your home network, has no user account and sends no data to the developer. It contacts Open-Meteo directly from your network (place name and coordinates that you enter yourself), NTP servers for the time and GitHub to check for new firmware; ntfy is optional. These services see the IP address of your connection. The device reads no location (such as GPS). The update check can be switched off in the web interface or in the set-up page. The privacy policy of wettercube.de (German) is at [wettercube.de/datenschutz](https://wettercube.de/datenschutz/).
