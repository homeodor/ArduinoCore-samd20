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

#include "variant.h"

const PinDescription g_APinDescription[] = {

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  MKR  Board pin  |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCx  |  TCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 00         | D0               |  PA22  |                 |  *06   |     |     | X10 |     |   3/00  |   5/00  |* TC4/0 | TC0/4 |          | GCLK_IO6 |
 | 01         | D1               |  PA23  |                 |  *07   |     |     | X11 |     |   3/01  |   5/01  |* TC4/1 | TC0/5 | USB/SOF  | GCLK_IO7 |
 | 02         | D2               |  PA10  |                 |   10   | *18 |     | X02 |     |   0/02  |   2/02  |*TC1/0 | TC0/2 | I2S/SCK0 | GCLK_IO4 |
 | 03         | D3               |  PA11  |                 |   11   | *19 |     | X03 |     |   0/03  |   2/03  |*TC1/1 | TC0/3 | I2S/FS0  | GCLK_IO5 |
 | 04         | D4               |  PB10  |                 |  *10   |     |     |     |     |         |   4/02  |* TC5/0 | TC0/4 | I2S/MCK1 | GCLK_IO4 |
 | 05         | D5               |  PB11  |                 |  *11   |     |     |     |     |         |   4/03  |* TC5/1 | TC0/5 | I2S/SCK1 | GCLK_IO5 |
 | 06         | D6               |  PA20  |                 |  *04   |     |     | X08 |     |   5/02  |   3/02  |        |*TC0/6 | I2S/SCK0 | GCLK_IO4 |
 | 07         | D7               |  PA21  |                 |  *05   |     |     | X09 |     |   5/03  |   3/03  |        |*TC0/7 | I2S/FS0  | GCLK_IO5 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */
  { PORTA,  0, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  1, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG /*DAC*/        ), ADC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  3, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // DAC/VREFP
  { PORTA,  4, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel4,   PWM0_CH0,   TC0_CH0,     EXTERNAL_INT_NONE },
  { PORTA,  5, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel5,   PWM0_CH1,   TC0_CH1,     EXTERNAL_INT_NONE },
  { PORTA,  6, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel6,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  7, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                ), ADC_Channel7,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  8, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL                             ), ADC_Channel16,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NMI  }, // SDA:  SERCOM2/PAD[0]
  { PORTA,  9, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL                             ), ADC_Channel17,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCL:  SERCOM2/PAD[1]
  { PORTA, 10, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel18,  PWM1_CH0,   TC1_CH0,     EXTERNAL_INT_NONE },
  { PORTA, 11, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel19,  PWM1_CH1,   TC1_CH1,     EXTERNAL_INT_NONE },
  // { PORTA, 12, PIO_SERCOM_ALT, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MOSI: SERCOM4/PAD[0]
  // { PORTA, 13, PIO_SERCOM_ALT, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCK:  SERCOM4/PAD[1]
  { PORTA, 14, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SS:   as GPIO
  { PORTA, 15, PIO_SERCOM_ALT, (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // MISO: SERCOM4/PAD[3]
  { PORTA, 16, PIO_SERCOM,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM2_CH0,   TC2_CH0,     EXTERNAL_INT_0    }, // MOSI: SERCOM1/PAD[0]
  { PORTA, 17, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1    }, // SCK:  SERCOM1/PAD[1]
  { PORTA, 18, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 19, PIO_SERCOM,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM3_CH1,   TC3_CH1,      EXTERNAL_INT_NONE }, // MISO: SERCOM1/PAD[3]
  // { PORTA, 20, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER,     EXTERNAL_INT_4    },
  // { PORTA, 21, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, NOT_ON_PWM,   NOT_ON_TIMER,     EXTERNAL_INT_5    },
  { PORTA, 22, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH0,   TC4_CH0,      EXTERNAL_INT_6    },
  { PORTA, 23, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_7    },
  { PORTA, 24, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM,     (PIN_ATTR_NONE                                   ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  { PORTA, 27, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA, 28, PIO_DIGITAL,    (PIN_ATTR_NONE                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  

                                                                                                                                               // PINOUT=0

                                                                                                                                               // RXPO=3 TXPO=1

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  MKR  Board pin  |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCx  |  TCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            |       SPI        |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 08         | MOSI             |  PA16  |                 |  *00   |     |     | X04 |     |  *1/00  |   3/00  |*TC2/0 | TC0/6 |          | GCLK_IO2 |
 | 09         | SCK              |  PA17  |                 |  *01   |     |     | X05 |     |  *1/01  |   3/01  | TC2/1 | TC0/7 |          | GCLK_IO3 |
 | 10         | MISO             |  PA19  |                 |   03   |     |     | X07 |     |  *1/03  |   3/03  |* TC3/1 | TC0/3 | I2S/SD0  | AC/CMP1  |
 +------------+------------------+--------+-----------------+--------------------+-----+-----+---------+---------+--------+--------+----------+----------+
 |            |       Wire       |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 11         | SDA              |  PA08  |                 |   NMI  | *16 |     | X00 |     |  *0/00  |   2/00  | TC0/0 | TC1/2 | I2S/SD1  |          |
 | 12         | SCL              |  PA09  |                 |   09   | *17 |     | X01 |     |  *0/01  |   2/01  | TC0/1 | TC1/3 | I2S/MCK0 |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            |      Serial1     |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 13         | RX               |  PB23  |                 |   07   |     |     |     |     |         |  *5/03  |        |        |          | GCLK_IO1 |
 | 14         | TX               |  PB22  |                 |   06   |     |     |     |     |         |  *5/02  |        |        |          | GCLK_IO0 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */
                                                                                                                                               // DIPO=3 DOPO=0


/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  MKR  Board pin  |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCx  |  TCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 15         | A0 / DAC0        |  PA02  |                 |   02   | *00 |     | Y00 | OUT |         |         |        |        |          |          |
 | 16         | A1               |  PB02  |                 |  *02   | *10 |     | Y08 |     |         |   5/00  |        |        |          |          |
 | 17         | A2               |  PB03  |                 |  *03   | *11 |     | Y09 |     |         |   5/01  |        |        |          |          |
 | 18         | A3               |  PA04  |                 |   04   | *04 |  00 | Y02 |     |         |   0/00  |*TC0/0 |        |          |          |
 | 19         | A4               |  PA05  |                 |   05   | *05 |  01 | Y03 |     |         |   0/01  |*TC0/1 |        |          |          |
 | 20         | A5               |  PA06  |                 |   06   | *06 |  02 | Y04 |     |         |   0/02  | TC1/0 |        |          |          |
 | 21         | A6               |  PA07  |                 |   07   | *07 |  03 | Y05 |     |         |   0/03  | TC1/1 |        | I2S/SD0  |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  MKR  Board pin  |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCx  |  TCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            |       USB        |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 22         |                  |  PA24  | USB N           |   12   |     |     |     |     |   3/02  |   5/02  |  TC5/0 | TC1/2 | USB/DM   |          |
 | 23         |                  |  PA25  | USB P           |   13   |     |     |     |     |   3/03  |   5/03  |  TC5/1 | TC1/3 | USB/DP   |          |
 | 24         |                  |  PA18  | USB ID          |   02   |     |     | X06 |     |   1/02  |   3/02  |  TC3/0 | TC0/2 |          | AC/CMP0  |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 25         | AREF             |  PA03  |                 |   03   |  01 |     | Y01 |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */

/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number |  MKR  Board pin  |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCx  |  TCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | SD SPI           |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 26         |                  |  PA12  | SD MOSI         |   12   |     |     |     |     |  *2/00  |   4/00  | TC2/0 | TC0/6 |          | AC/CMP0  |
 | 27         |                  |  PA13  | SD SCK          |   13   |     |     |     |     |  *2/01  |   4/01  | TC2/1 | TC0/7 |          | AC/CMP1  |
 | 28         |                  |  PA14  | SD SS           |   14   |     |     |     |     |   2/02  |   4/02  |  TC3/0 | TC0/4 |          | GCLK_IO0 |
 | 29         |                  |  PA15  | SD MISO         |   15   |     |     |     |     |  *2/03  |   4/03  |  TC3/1 | TC0/5 |          | GCLK_IO1 |
 | 30         |                  |  PA27  | SD CD           |   15   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 31         |                  |  PA28  | BOTTOM PAD      |   08   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 | 32         |                  |  PB08  | LED_BUILTIN     |   08   |  02 |     | Y14 |     |         |   4/00  |  TC4/0 |        |          |          |
 | 33         |                  |  PB09  | ADC_BATTERY     |  *09   |  03 |     | Y15 |     |         |   4/01  |  TC4/1 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | 32768Hz Crystal  |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 | 34         |                  |  PA00  | XIN32           |   00   |     |     |     |     |         |   1/00  | TC2/0 |        |          |          |
 | 35         |                  |  PA01  | XOUT32          |   01   |     |     |     |     |         |   1/01  | TC2/1 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */
                                                                                                                                               // DIPO=3 DOPO=0

};

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TC_INST_NUM]={ TC0, TC1, TC2, TC3, TC4, TC5 };

// Multi-serial objects instantiation
SERCOM sercom0(SERCOM0);
SERCOM sercom1(SERCOM1);
SERCOM sercom2(SERCOM2);
SERCOM sercom3(SERCOM3);

// Serial1
Uart Serial(&sercom3, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX);

void SERCOM5_Handler()
{
  Serial1.IrqHandler();
}

