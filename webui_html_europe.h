// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Jan Althaus (JPPeterson-lab)
// Web interface and set-up portal of the variant "WetterCubePlus Europe" (English).
// Placeholders (%NAME%) are filled in by WetterCubePlus.ino, same as in webui_html.h.
#pragma once
#include "webui_theme.h"

const char PORTAL_HTML[] PROGMEM = R"rawhtml(
<!DOCTYPE html><html lang="en"><head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>WetterCubePlus Europe – Set-up</title>
<style>
  body{font-family:Arial,sans-serif;background:#0d1117;color:#e6edf3;margin:0;padding:20px}
  h1{color:#58a6ff;font-size:1.4em}
  .card{background:#161b22;border:1px solid #30363d;border-radius:8px;padding:20px;max-width:420px;margin:auto}
  label{display:block;margin-top:12px;color:#8b949e;font-size:.9em}
  input,select{width:100%;padding:8px;border-radius:4px;border:1px solid #30363d;
    background:#21262d;color:#e6edf3;box-sizing:border-box;margin-top:4px}
  button{margin-top:20px;width:100%;padding:10px;background:#238636;color:#fff;
    border:none;border-radius:4px;font-size:1em;cursor:pointer}
  button:hover{background:#2ea043}
  .hint{font-size:.8em;color:#8b949e;margin-top:4px}
</style></head><body>
<div class="card">
  <h1>WetterCubePlus Europe set-up</h1>
  <form action="/speichern" method="post">
    <label>Wi-Fi network</label>
    <select name="ssid">%NETZWERKE%</select>
    <label>Wi-Fi password</label>
    <input type="password" name="pass" placeholder="Enter password">
    <label>Location (city)</label>
    <input type="text" name="location" placeholder="e.g. Paris" value="%LOCATION%">
    <label>Country</label>
    <select name="country">%COUNTRY_OPTIONS%</select>
    <p class="hint">Choose the country to avoid mix-ups between cities with the same name.</p>
    <button type="submit">Save &amp; restart</button>
  </form>
</div></body></html>
)rawhtml";

const char PORTAL_OK_HTML[] PROGMEM = R"rawhtml(
<!DOCTYPE html><html lang="en"><head>
<meta charset="UTF-8"><title>Saved</title>
<meta http-equiv="refresh" content="5;url=/">
<style>
  body{font-family:Arial;background:#0d1117;color:#e6edf3;text-align:center;padding-top:60px}
  .ok{color:#2ea043;font-size:2em}
</style></head><body>
<div class="ok">Saved</div>
<p>The device is restarting...</p>
</body></html>
)rawhtml";

const char WEBUI_HTML[] PROGMEM = R"rawhtml(
<!DOCTYPE html><html lang="en"><head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>WetterCubePlus Europe</title>
)rawhtml" WEBUI_THEME_HEAD WEBUI_THEME_CSS R"rawhtml(
<style>
  *{box-sizing:border-box}
  body{font-family:Arial,sans-serif;background:var(--bg);color:var(--txt);margin:0;padding:16px;max-width:860px;margin:auto}
  h1{color:var(--acc);margin:0 0 4px}
  .top{display:flex;justify-content:space-between;align-items:flex-start;gap:10px;margin-bottom:14px}
  .ver{color:var(--mut);font-size:.85em}
  .tabs{display:flex;gap:6px;overflow-x:auto;margin:0 0 16px;padding-bottom:4px;-webkit-overflow-scrolling:touch}
  .tabs a{flex:0 0 auto;padding:9px 16px;border-radius:8px;background:var(--tab);color:var(--txt);text-decoration:none;font-size:.95em;border:1px solid var(--bd);white-space:nowrap}
  .tabs a.aktiv{background:#1f6feb;border-color:#1f6feb;color:#fff}
  .tab{display:none}
  .card{background:var(--card);border:1px solid var(--bd);border-radius:8px;padding:16px;margin-bottom:16px}
  h2{color:var(--txt);font-size:1em;margin:0 0 12px}
  h3.sub{margin:16px 0 4px;font-size:.95em;color:var(--txt);border-top:1px solid var(--bd);padding-top:14px}
  label{display:block;color:var(--mut);font-size:.85em;margin-top:10px}
  input[type=text],input[type=number],select{width:100%;padding:7px;border-radius:4px;
    border:1px solid var(--bd);background:var(--in);color:var(--txt);margin-top:3px}
  input[type=range]{width:100%;margin-top:6px}
  input[type=file]{width:100%;margin-top:6px;color:var(--txt)}
  .row{display:flex;align-items:center;justify-content:space-between;gap:10px;margin-top:10px}
  .row span{color:var(--txt);font-size:.95em}
  .grid2{display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:8px}
  .toggle{position:relative;width:44px;height:24px;flex-shrink:0;margin:0}
  .toggle input{opacity:0;width:0;height:0}
  .slider{position:absolute;inset:0;background:var(--slider);border-radius:12px;cursor:pointer;transition:.3s}
  .slider::before{content:'';position:absolute;width:18px;height:18px;left:3px;bottom:3px;
    background:#fff;border-radius:50%;transition:.3s}
  input:checked+.slider{background:#238636}
  input:checked+.slider::before{transform:translateX(20px)}
  .btn{display:inline-block;padding:9px 16px;border:none;border-radius:4px;cursor:pointer;font-size:.9em;margin-top:6px;text-decoration:none}
  .btn-gruen{background:#238636;color:#fff}.btn-gruen:hover{background:#2ea043}
  .btn-blau{background:#1f6feb;color:#fff}.btn-blau:hover{background:#388bfd}
  .btn-rot{background:#b91c1c;color:#fff}.btn-rot:hover{background:#dc2626}
  .status{font-size:.85em;color:var(--mut);margin-top:6px}
  .hint{font-size:.78em;color:var(--mut);margin-top:3px}
  .savebar{position:sticky;bottom:0;background:var(--bg);border-top:1px solid var(--bd);padding:10px 0;margin-top:4px;display:flex;align-items:center;gap:12px;z-index:5}
  .savebar .btn{margin:0}
  #dirty{font-size:.85em;color:#d29922;display:none}
  .col{flex:1}
</style></head><body>
<div class="top">
  <div><h1>WetterCubePlus Europe</h1>
  <div class="ver">Firmware: %VERSION% | IP: %IP% | wettercubeplus-europe.local</div></div>
  <button id="wcpThemeBtn" class="themebtn" onclick="wcpTheme()" title="Light or dark"></button>
</div>

<div class="tabs" id="tabs">
  <a href="#anzeige" data-t="anzeige">Display</a>
  <a href="#wetter" data-t="wetter">Weather &amp; data</a>
  <a href="#ampel" data-t="ampel">Traffic light</a>
  <a href="#system" data-t="system">System</a>
</div>

<form action="/speichern" method="post" id="einst">
<input type="hidden" name="main_box" value="0">

<div class="tab" id="t-anzeige">
<div class="card">
  <h2>Display</h2>
  <label>Brightness: <span id="bv">%BRIGHT%</span>%</label>
  <input type="range" name="brightness" min="10" max="100" value="%BRIGHT%"
    oninput="document.getElementById('bv').textContent=this.value">
  <label>Wind speed unit</label>
  <select name="wind_unit">
    <option value="0" %WU0%>km/h</option>
    <option value="1" %WU1%>mph</option>
    <option value="2" %WU2%>m/s</option>
    <option value="3" %WU3%>knots</option>
  </select>
  <label>Dim timeout</label>
  <select name="dim_time">
    <option value="0" %DT0%>Off</option>
    <option value="-1" %DTT%>30 seconds (test)</option>
    <option value="1" %DT1%>1 minute</option>
    <option value="3" %DT3%>3 minutes (default)</option>
    <option value="5" %DT5%>5 minutes</option>
    <option value="10" %DT10%>10 minutes</option>
  </select>
</div>

<div class="card">
  <h2>Night mode</h2>
  <p class="hint">During the chosen time the display glows at its own, lower brightness.</p>
  <div class="row"><span>Night mode on</span>
    <label class="toggle"><input type="checkbox" name="night_mode" %NM%><span class="slider"></span></label></div>
  <div style="display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:8px">
    <div>
      <label>From</label>
      <select name="night_from">%NIGHT_FROM_OPTIONS%</select>
    </div>
    <div>
      <label>To</label>
      <select name="night_to">%NIGHT_TO_OPTIONS%</select>
    </div>
  </div>
  <label style="margin-top:8px;display:block">Brightness at night: <span id="nbv">%NBR%</span>%</label>
  <input type="range" name="night_bright" min="0" max="50" value="%NBR%"
    oninput="document.getElementById('nbv').textContent=this.value">
</div>

<div class="card">
  <h2>Main screen</h2>
  <p class="hint">The right-hand field shows your two strongest pollen values (card &ldquo;My allergens&rdquo;).</p>
  <div class="row"><span>Rain bars in the temperature history</span>
    <label class="toggle"><input type="checkbox" name="vl_regen" %VR%><span class="slider"></span></label></div>
</div>

<div class="card">
  <h2>Notice tile</h2>
  <p class="hint">A tile at the bottom of the main screen shows thunderstorms, heavy rain, rain, storm gusts, heat, snow or ice, frost, strong UV radiation, poor air quality and fast pressure changes. New notices blink until you tap the tile; after that it stays lit as long as the notice applies. With several notices, the order is: thunderstorm, heavy rain, rain, storm gusts, heat, snow or ice, frost, UV, air quality, pressure. These notices are calculated from the forecast; they are not official weather warnings.</p>
  <div class="row"><span>Rain</span>
    <label class="toggle"><input type="checkbox" name="hw_regen" %HR%><span class="slider"></span></label></div>
  <div class="row"><span>Storm (gusts of 62 km/h or more in the next 6 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_wind" %HW%><span class="slider"></span></label></div>
  <div class="row"><span>Frost (0 &deg;C or below in the next 12 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_frost" %HF%><span class="slider"></span></label></div>
  <div class="row"><span>UV index 6 or higher</span>
    <label class="toggle"><input type="checkbox" name="hw_uv" %HU%><span class="slider"></span></label></div>
  <div class="row"><span>Weather change (pressure falling 3 hPa or more within 3 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_druck" %HD%><span class="slider"></span></label></div>
  <div class="row"><span>Thunderstorm (in the next 6 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_gew" %HG%><span class="slider"></span></label></div>
  <div class="row"><span>Heavy rain (5 mm per hour or more in the next 6 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_sturz" %HS%><span class="slider"></span></label></div>
  <div class="row"><span>Heat (feels like 32 &deg;C or more in the next 6 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_hitze" %HH%><span class="slider"></span></label></div>
  <div class="row"><span>Snow or ice (snow, freezing rain, or frost with precipitation in the next 6 hours)</span>
    <label class="toggle"><input type="checkbox" name="hw_glaette" %HE%><span class="slider"></span></label></div>
  <div class="row"><span>Poor air quality (European AQI 60 or higher)</span>
    <label class="toggle"><input type="checkbox" name="hw_luft" %HL%><span class="slider"></span></label></div>
</div>
</div>

<div class="tab" id="t-wetter">
<div class="card">
  <h2>Location &amp; country</h2>
  <label>City</label>
  <input type="text" name="location" value="%LOCATION%">
  <label>Country</label>
  <select name="country">%COUNTRY_OPTIONS%</select>
  <p class="hint">The time zone is taken from the location automatically.</p>
</div>

<div class="card">
  <h2>Pollen warning</h2>
  <div class="row"><span>Pollen warning</span>
    <label class="toggle"><input type="checkbox" name="pollen_warn" %PW%><span class="slider"></span></label></div>
  <label>Pollen warning threshold</label>
  <select name="pol_schw">
    <option value="0" %PS0%>Low</option>
    <option value="1" %PS1%>Medium</option>
    <option value="2" %PS2%>High (default)</option>
    <option value="3" %PS3%>Very high</option>
  </select>
</div>

<div class="card">
  <h2>My allergens</h2>
  <p class="hint">The pollen warning and the pollen screens only consider the selected pollen. Pollen data covers Europe during the pollen season (forecast for 3 days, source: CAMS via Open-Meteo).</p>
  %POL_AUSWAHL%
</div>
</div>

<div class="savebar" id="savebar">
  <button type="submit" class="btn btn-gruen">Save settings</button>
  <span id="dirty">&bull; unsaved changes</span>
</div>
</form>

<div class="tab" id="t-ampel">
<div class="card">
  <h2>Traffic light settings</h2>
  <p class="hint">Settings for the hardware add-on (traffic light). Now: <strong id="amp_d">…</strong> &nbsp;|&nbsp; Active: <strong id="amp_a">…</strong></p>
  <form action="/api/ampel_save" method="post">
  <label>What the traffic light shows</label>
  <select name="amp_modus">
    <option value="0" %AMP_M0%>Temperature</option>
    <option value="1" %AMP_M1%>Pollen (my allergens)</option>
    <option value="2" %AMP_M2%>Air quality</option>
  </select>
  <p class="hint">Pollen: green for none to low, yellow for medium to high, red for heavy load. Air quality (European AQI): green up to 40, yellow up to 60, red above. The temperature limits below only apply in temperature mode.</p>
  <div class="row">
    <div class="col">
      <label>Green min (&deg;C)</label>
      <input type="number" name="amp_gn_min" value="%AMP_GN_MIN%" min="-30" max="60">
    </div>
    <div class="col">
      <label>Green max (&deg;C)</label>
      <input type="number" name="amp_gn_max" value="%AMP_GN_MAX%" min="-30" max="60">
    </div>
  </div>
  <div class="row">
    <div class="col">
      <label>Yellow min (&deg;C)</label>
      <input type="number" name="amp_ge_min" value="%AMP_GE_MIN%" min="-30" max="60">
    </div>
    <div class="col">
      <label>Yellow max (&deg;C)</label>
      <input type="number" name="amp_ge_max" value="%AMP_GE_MAX%" min="-30" max="60">
    </div>
  </div>
  <div class="row">
    <div class="col">
      <label>Red min (&deg;C)</label>
      <input type="number" name="amp_ro_min" value="%AMP_RO_MIN%" min="-30" max="60">
    </div>
    <div class="col">
      <label>Red max (&deg;C)</label>
      <input type="number" name="amp_ro_max" value="%AMP_RO_MAX%" min="-30" max="60">
    </div>
  </div>
  <button type="submit" class="btn btn-gruen">Save traffic light limits</button>
  </form>
</div>
</div>

<div class="tab" id="t-system">
<div class="card">
  <h2>Password for the web interface</h2>
  <p class="hint">%WPSTATUS%</p>
  <p class="hint">With a password the device asks for a user name (<b>admin</b>) and password when you open this page. The WetterAmpel keeps reading the values (<code>/api/ampel</code>). In your home network the password is sent unencrypted (HTTP): it protects against access from other devices and foreign web pages, not against someone who reads the network traffic. <b>Forgotten?</b> On the login page &ldquo;Forgot password?&rdquo; leads on: a code appears on the display that lets you delete the password.</p>
  <form action="/passwort_speichern" method="post" onsubmit="var w=this.pw_weg;return !(w&&w.checked)||confirm('Remove the password? Then anyone in your home network can change the settings.')">
    <label>New password (at least 6 characters)</label>
    <input type="password" name="pw1" autocomplete="new-password">
    <label>Repeat</label>
    <input type="password" name="pw2" autocomplete="new-password">
    <button type="submit" class="btn btn-blau" style="margin-top:8px">Save password</button>
    <label style="display:flex;gap:8px;align-items:center;margin-top:10px"><input type="checkbox" name="pw_weg" style="width:auto"> Remove password</label>
  </form>
</div>

<div class="card">
  <h2>Firmware update</h2>
  <div class="status">Current version: %VERSION%</div>
  <button type="button" class="btn btn-blau" onclick="checkOta()">Check for updates</button>
  <a href="/log" target="_blank" class="btn btn-blau">View log</a>
  <div id="ota_status" class="status"></div>
  <div class="status" style="margin-top:10px">Note: during the update the display shows a progress bar. <b>Do not disconnect the power</b> &ndash; the device restarts by itself afterwards (about 1 minute). The device also checks for updates regularly and shows an update symbol at the top right of the main screen.</div>
</div>

<div class="card">
  <h2>Back up settings</h2>
  <p class="hint">Saves all settings (without the Wi-Fi password) as a file and restores them when needed, for example after a fresh installation that erased the memory.</p>
  <a href="/backup" class="btn btn-blau">Download settings</a>
  <label>Restore backup</label>
  <input type="file" id="restore_file" accept=".json,application/json">
  <button type="button" class="btn btn-rot" onclick="restoreSettings()">Restore</button>
  <div id="restore_status" class="status"></div>
</div>

<div class="card">
  <h2>Change Wi-Fi credentials</h2>
  <p class="hint">Change SSID/password without flashing again.</p>
  <a href="/wlan" class="btn btn-blau">Change Wi-Fi</a>
</div>

<div class="card">
  <h2>Data sources</h2>
  <p class="hint">Weather data: <a href="https://open-meteo.com" target="_blank" rel="noopener">Weather data by Open-Meteo.com</a> (<a href="https://open-meteo.com/en/licence" target="_blank" rel="noopener">CC BY 4.0</a>). The free interface is for non-commercial use only. Values are partly converted and summarised in the WetterCube, for example to pollen levels and daily highs. Pollen and air quality: Contains modified Copernicus Atmosphere Monitoring Service information, via Open-Meteo. Location search: Location data by <a href="https://www.geonames.org" target="_blank" rel="noopener">GeoNames</a> via Open-Meteo.</p>
</div>
</div>

<script>
function checkOta(){
  document.getElementById('ota_status').textContent='Checking...';
  fetch('/ota_check').then(function(r){return r.json();}).then(function(d){
    if(d.update_available){
      document.getElementById('ota_status').innerHTML=
        'New version: '+d.latest+' &nbsp;'+
        '<button class="btn btn-rot" onclick="doUpdate()">Install now</button>';
    } else {
      document.getElementById('ota_status').textContent='Already up to date ('+d.latest+')';
    }
  }).catch(function(){document.getElementById('ota_status').textContent='Error while checking';});
}
function restoreSettings(){
  var f=document.getElementById('restore_file').files[0];
  var st=document.getElementById('restore_status');
  if(!f){st.textContent='Please choose a file first.';return;}
  if(!confirm('Restore the settings from the file now? The device restarts afterwards.')) return;
  var r=new FileReader();
  r.onload=function(){
    st.textContent='Restoring ...';
    fetch('/restore',{method:'POST',headers:{'Content-Type':'application/json'},body:r.result})
      .then(function(x){return x.text().then(function(tx){return {ok:x.ok,t:tx};});})
      .then(function(o){st.textContent=o.ok?'Restored. The device restarts (reload the page in about 30 seconds).':'Error: '+o.t;})
      .catch(function(){st.textContent='Connection closed. If the device is restarting right now, that is normal.';});
  };
  r.readAsText(f);
}
function doUpdate(){
  if(!confirm('Install the update now?\n\nDo NOT disconnect the power. The device restarts by itself afterwards (about 1 minute).')) return;
  document.getElementById('ota_status').textContent='Updating... Do NOT switch the device off (about 1 minute).';
  fetch('/ota_update',{method:'POST'}).then(function(r){return r.text();}).then(function(t){
    document.getElementById('ota_status').textContent=(t==='ok')?'Update installed. The device restarts ...':'Error: '+t;
  }).catch(function(){
    document.getElementById('ota_status').textContent='Connection closed. If the device is restarting right now, that is normal.';
  });
}
function ladeAmpel(){
  fetch('/api/ampel').then(function(r){return r.json();}).then(function(d){
    document.getElementById('amp_d').textContent=d.detail||(d.temperature.toFixed(1)+' °C');
    var farben={'green':'Green','yellow':'Yellow','red':'Red','none':'none'};
    document.getElementById('amp_a').textContent=farben[d.active]||d.active;
  }).catch(function(){});
}
ladeAmpel();

var TABS=['anzeige','wetter','ampel','system'];
function zeige(t){
  if(TABS.indexOf(t)<0)t='anzeige';
  for(var i=0;i<TABS.length;i++){
    var s=document.getElementById('t-'+TABS[i]);if(s)s.style.display=(TABS[i]===t)?'block':'none';
    var a=document.querySelector('.tabs a[data-t="'+TABS[i]+'"]');if(a)a.className=(TABS[i]===t)?'aktiv':'';
  }
  var sb=document.getElementById('savebar');if(sb)sb.style.display=(t==='anzeige'||t==='wetter')?'flex':'none';
  try{localStorage.setItem('wcp-tab',t);}catch(e){}
  if(location.hash!=='#'+t&&history.replaceState)history.replaceState(null,'','#'+t);
}
function startTab(){
  var t=location.hash.replace('#','');
  if(!t){try{t=localStorage.getItem('wcp-tab')||'';}catch(e){}}
  zeige(t);
}
window.addEventListener('hashchange',function(){zeige(location.hash.replace('#',''));});
document.getElementById('tabs').addEventListener('click',function(e){var a=e.target.closest?e.target.closest('a[data-t]'):null;if(a){e.preventDefault();zeige(a.getAttribute('data-t'));}});
document.getElementById('einst').addEventListener('input',function(){var d=document.getElementById('dirty');if(d)d.style.display='inline';});
wcpThemeLabel();startTab();
</script>
</body></html>
)rawhtml";

const char WLAN_HTML[] PROGMEM = R"rawhtml(
<!DOCTYPE html><html lang="en"><head>
<meta charset="UTF-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>Change Wi-Fi</title>
)rawhtml" WEBUI_THEME_HEAD WEBUI_THEME_CSS R"rawhtml(
<style>
  body{font-family:Arial;background:var(--bg);color:var(--txt);padding:20px}
  .card{background:var(--card);border:1px solid var(--bd);border-radius:8px;padding:20px;max-width:420px;margin:auto}
  h1{color:var(--acc);font-size:1.3em}
  label{display:block;color:var(--mut);font-size:.85em;margin-top:10px}
  input,select{width:100%;padding:8px;border-radius:4px;border:1px solid var(--bd);
    background:var(--in);color:var(--txt);box-sizing:border-box;margin-top:3px}
  .btn{width:100%;padding:10px;background:#238636;color:#fff;border:none;border-radius:4px;font-size:1em;cursor:pointer;margin-top:16px}
  .btn:hover{background:#2ea043}
  a{color:var(--acc)}
</style></head><body>
<div class="card">
  <h1>Change Wi-Fi credentials</h1>
  <form action="/wlan_speichern" method="post">
    <label>Network</label>
    <select name="ssid">%NETZWERKE%</select>
    <label>Password</label>
    <input type="password" name="pass">
    <button type="submit" class="btn">Save &amp; restart</button>
  </form>
  <br><a href="/#system">Back</a>
</div></body></html>
)rawhtml";
