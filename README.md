# Arduino Core for SAMD20 CPU

This repository contains the source code and configuration files of the Arduino Core
for Atmel's SAMD20 processor.

## Warning

This is a highly experimental repo. Be warned.

## Installation

Despite being an Arduino core, it is only compatible with PlatformIO, and it doesn’t have typical Arduino
board definitions.

Add
```
platform_packages   = framework-arduino-samd-samd20 @ https://github.com/homeodor/ArduinoCore-samd20.git
```
to your platformio.ini and enjoy.

## Boards

There are hardly any boards out there with SAMD20s. So you will have to create a PlatformIO JSON file (board
definiton) as well as an Arduino core “variant”.

### The JSON

You may wish to create a directory called “boards” in your PlatformIO project, and put your custom board JSONs
there. An example JSON file is included (samd20e18.json), which you may use to kick things off.

### Custom variant

If you want to create your own variant, just create a directory called “variants” in your project, put
a new variant here (you can use the included samd20e18 variant as a starting point), and then add
```
    "variants_dir": "variants"
```
to your JSON file after the "variant" key and value pair.

## License and credits

The original core has been developed by Arduino LLC in collaboration with Atmel.

```
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
```
