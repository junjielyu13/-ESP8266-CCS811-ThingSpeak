<div align="center">

# ESP8266 + CCS811 + ThingSpeak: Air Quality Web Server

![cover](.etc/ESP8266_SERVER.png)

</div>

The purpose of this project is to create a Wi-Fi enabled web server that can send information to the server with a CCS11 air detector and display it on a Thingspeak web page in real time, compatible with multiple ESP8266 variants.

## Table of Contents

- [ESP8266 + CCS811 + ThingSpeak: Air Quality Web Server](#esp8266--ccs811--thingspeak-air-quality-web-server)
  - [Table of Contents](#table-of-contents)
  - [Requirements](#requirements)
  - [Install](#install)
  - [Usage](#usage)
  - [Hardware](#hardware)
  - [Structure](#structure)
- [Web Server](#web-server)
- [ThingSpeak](#thingspeak)
  - [Documentation](#documentation)
  - [Issues](#issues)
  - [License](#license)

## Requirements

- Hardware:
  - ESP8266
  - CSS811
- Statistics server:
  - ThingSpeak
- Development tools:
  - Android IDE

## Install

Clone to local directory:

`$ git clone https://github.com/junjielyu13/ESP8266-CCS811-ThingSpeak.git`

## Usage

## Hardware

![harware1](.etc/foto_1.jpg)

![harware2](.etc/foto_2-1.png)
![harware3](.etc/foto_2-2.png)

![harware4](.etc/plan.png)

The hardware is based on the adafruit-feather-huzzah ESP8266 board and uses an CCS811 Air Quality Sensor (Breakout) to check the air condition and quality. Wire seen in the schematic are variable and will depend on the specifications of on the versionCSS811.

Shopping List:

    - ESP8266
    - CSS811
    - ThingSpeak

These are just quick Amazon references. Parts can be purchased cheaper with longer shipping times from places like AliExpress

## Structure

![harware2](.etc/structure.png)

# Web Server

![harware3](.etc/ESP8266_SERVER.png)

# ThingSpeak

![harware3](.etc/ThingSpeak.png)

## Documentation

more documentation [here]().

## Issues

More issues, or other problems, please send them [here](https://github.com/SoftwareDistribuitUB-2023/practica-1-p1_f01/issues).

## License

[MIT](https://github.com/junjielyu13/ESP8266-CCS811-ThingSpeak/blob/main/LICENSE), [@All Contributors](#contributing).
