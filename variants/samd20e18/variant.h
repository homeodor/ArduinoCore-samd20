/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

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
*/

#pragma once

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

#include <WVariant.h>

// General definitions
// -------------------

// Frequency of the board main oscillator
#define VARIANT_MAINOSC (32768ul)

// Master clock frequency
#define VARIANT_MCK     (48000000ul)

// Pins
// ----

// Number of pins defined in PinDescription array
#ifdef __cplusplus
extern "C" unsigned int PINCOUNT_fn();
#endif
#define PINS_COUNT           (PINCOUNT_fn())
#define NUM_DIGITAL_PINS     (15u)
#define NUM_ANALOG_INPUTS    (7u)
#define NUM_ANALOG_OUTPUTS   (1u)

// Low-level pin register query macros
// -----------------------------------
#define digitalPinToPort(P)      (&(PORT->Group[g_APinDescription[P].ulPort]))
#define digitalPinToBitMask(P)   (1 << g_APinDescription[P].ulPin)
//#define analogInPinToBit(P)    ()
#define portOutputRegister(port) (&(port->OUT.reg))
#define portInputRegister(port)  (&(port->IN.reg))
#define portModeRegister(port)   (&(port->DIR.reg))
#define digitalPinHasPWM(P)      (g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER)

#define PA00	(0u)
#define PA01	(1u)
#define PA02	(2u)
#define PA03	(3u)
#define PA04	(4u)
#define PA05	(5u)
#define PA06	(6u)
#define PA07	(7u)
#define PA08	(8u)
#define PA09	(9u)
#define PA10	(10u)
#define PA11	(11u)

#define PA14	(12u)
#define PA15	(13u)
#define PA16	(14u)
#define PA17	(15u)
#define PA18	(16u)
#define PA19	(17u)

#define PA22	(18u)
#define PA23	(19u)
#define PA24	(20u)
#define PA25	(21u)
#define PA27	(22u)
#define PA28	(23u)

#define A0  PA02
#define A1  PA03
#define A2  PA04
#define A3  PA05
#define A4  PA06
#define A5  PA07

// LEDs
// ----
#define PIN_LED     PA01
#define LED_BUILTIN PIN_LED

// SPI Interfaces
// --------------
#define SPI_INTERFACES_COUNT 1
 
// SPI
#define PIN_SPI_MISO  PA19
#define PIN_SPI_MOSI  PA16
#define PIN_SPI_SCK   PA17
#define PIN_SPI_SS    PA18
#define PERIPH_SPI    sercom1
#define PAD_SPI_TX    SPI_PAD_0_SCK_1
#define PAD_SPI_RX    SERCOM_RX_PAD_3

static const uint8_t SS   = PIN_SPI_SS;   // SPI Slave SS not used. Set here only for reference.
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

// Wire Interfaces
// ---------------
#define WIRE_INTERFACES_COUNT 1

// Wire
#define PIN_WIRE_SDA        PA08
#define PIN_WIRE_SCL        PA09
#define PERIPH_WIRE         sercom0
#define WIRE_IT_HANDLER     SERCOM0_Handler
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// I2S Interfaces
// --------------
#define I2S_INTERFACES_COUNT 0

// Serial ports
// ------------
#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"

// Instances of SERCOM
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;

// Serial1
extern Uart Serial;
#define PIN_SERIAL1_RX PA25
#define PIN_SERIAL1_TX PA24
#define PAD_SERIAL1_TX (UART_TX_PAD_2)
#define PAD_SERIAL1_RX (SERCOM_RX_PAD_3)
#endif // __cplusplus

#ifdef __cplusplus
extern "C" {
#endif
unsigned int PINCOUNT_fn();
#ifdef __cplusplus
}
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial

#define Serial1 Serial