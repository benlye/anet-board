/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $

  Changelog
  -----------
  11/25/11  - ryan@ryanmsutton.com - Add pins for Sanguino 644P and 1284P
  07/15/12  - ryan@ryanmsutton.com - Updated for arduino0101
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NOT_A_PIN 0
#define NOT_A_PORT 0

#define NOT_ON_TIMER 0

const static uint8_t SS   = 4;
const static uint8_t MOSI = 5;
const static uint8_t MISO = 6;
const static uint8_t SCK  = 7;

static const uint8_t SDA = 17;
static const uint8_t SCL = 16;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 31;
static const uint8_t A1 = 30;
static const uint8_t A2 = 29;
static const uint8_t A3 = 28;
static const uint8_t A4 = 27;
static const uint8_t A5 = 26;
static const uint8_t A6 = 25;
static const uint8_t A7 = 24;

// ATMEL ATMEGA1284 TQFP/QFM/MLF 44pin (SANGUINO Pinout PA0..PA7 > D31..D24)
//
//                        +-----------------+
//     MOSI (D 5)  PB5   6|O                |44  PB4 (D 4) PWM
//     MISO (D 6)  PB6   2|                 |43  PB3 (D 3) PWM
//      SCK (D 7)  PB7   3|                 |42  PB2 (D 2)     INT2
//                 RST   4|                 |41  PB1 (D 1)
//                 VCC   5|                 |40  PB0 (D 0)
//                 GND   6|                 |39  GND
//               XTAL2   7|                 |38  VCC
//               XTAL1   8|                 |37  PA0 (AI 0 / D31)
//      RX0 (D 8)  PD0   9|                 |36  PA1 (AI 1 / D30)
//      TX0 (D 9)  PD1  10|                 |35  PA2 (AI 2 / D29)
// INT0 RX1 (D 10) PD2  11|                 |34  PA3 (AI 3 / D28)
//                        |                 |33  PA4 (AI 4 / D27)
// INT1 TX1 (D 11) PD3  12|                 |
//      PWM (D 12) PD4  13|                 |32  PA5 (AI 5 / D26)
//      PWM (D 13) PD5  14|                 |31  PA6 (AI 6 / D25)
//      PWM (D 14) PD6  15|                 |30  PA7 (AI 7 / D24)
//      PWM (D 15) PD7  16|                 |29  AREF
//                 VCC  17|                 |28  GND
//                 GND  18|                 |27  AVCC
//      SCL (D 16) PC0  19|                 |26  PC7 (D 23)
//      SDA (D 17) PC1  20|                 |25  PC6 (D 22)
//      TCK (D 18) PC2  21|                 |24  PC5 (D 21) TDI
//      TMS (D 19) PC3  22|                 |23  PC4 (D 20) TDO
//                        +-----------------+

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p) ((p < 8) ? 31 - (p): -1)

#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 4 || (p) == 12 || (p) == 13 || (p) == 14 || (p) == 15 )

#define digitalPinToPCICR(p)    ( (((p) >= 0) && ((p) <= 31)) ? (&PCICR) : ((uint8_t *)0) )

#define digitalPinToPCICRbit(p) ( (((p) >= 24) && ((p) <= 31)) ? 0 : \
                                ( (((p) >=  0) && ((p) <=  7)) ? 1 : \
                                ( (((p) >= 16) && ((p) <= 23)) ? 2 : \
                                ( (((p) >=  8) && ((p) <= 15)) ? 3 : \
                                0 ) ) ) )

#define digitalPinToPCMSK(p)    ( (((p) >= 24) && ((p) <= 31)) ? (&PCMSK0) : \
                                ( (((p) >=  0) && ((p) <=  7)) ? (&PCMSK1) : \
                                ( (((p) >= 16) && ((p) <= 23)) ? (&PCMSK2) : \
                                ( (((p) >=  8) && ((p) <= 15)) ? (&PCMSK3) : \
                                ((uint8_t *)0) ) ) ) )


#define digitalPinToPCMSKbit(p) ( (((p) >= 24) && ((p) <= 31)) ? (31 - (p)) : \
                                ( (((p) >=  0) && ((p) <=  7)) ? (p) : \
                                ( (((p) >= 16) && ((p) <= 23)) ? ((p) - 16) : \
                                ( (((p) >=  8) && ((p) <= 15)) ? ((p) - 8) : \
                                0 ) ) ) )

#define digitalPinToInterrupt(p) ((p) == 10 ? 0 : ((p) == 11 ? 1 : ((p) == 2 ? 2 \
                                : NOT_AN_INTERRUPT)))	// mega1284p dip

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

#ifdef ARDUINO_MAIN
// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &DDRA,
        (uint16_t) &DDRB,
        (uint16_t) &DDRC,
        (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &PORTA,
        (uint16_t) &PORTB,
        (uint16_t) &PORTC,
        (uint16_t) &PORTD,
};
const uint16_t PROGMEM port_to_input_PGM[] =
{
        NOT_A_PORT,
        (uint16_t) &PINA,
        (uint16_t) &PINB,
        (uint16_t) &PINC,
        (uint16_t) &PIND,
};
const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
        PB, /* 0 */
        PB,
        PB,
        PB,
        PB,
        PB,
        PB,
        PB,
        PD, /* 8 */
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PD,
        PC, /* 16 */
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PC,
        PA, /* 24 */
        PA,
        PA,
        PA,
        PA,
        PA,
        PA,
        PA  /* 31 */
};
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
        _BV(0), /* 0, port B */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 8, port D */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(0), /* 16, port C */
        _BV(1),
        _BV(2),
        _BV(3),
        _BV(4),
        _BV(5),
        _BV(6),
        _BV(7),
        _BV(7), /* 24, port A */
        _BV(6),
        _BV(5),
        _BV(4),
        _BV(3),
        _BV(2),
        _BV(1),
        _BV(0)
};
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
        NOT_ON_TIMER,   /* 0  - PB0 */
        NOT_ON_TIMER,   /* 1  - PB1 */
        NOT_ON_TIMER,   /* 2  - PB2 */
        TIMER0A,        /* 3  - PB3 */
        TIMER0B,                /* 4  - PB4 */
        NOT_ON_TIMER,   /* 5  - PB5 */
        NOT_ON_TIMER,   /* 6  - PB6 */
        NOT_ON_TIMER,   /* 7  - PB7 */
        NOT_ON_TIMER,   /* 8  - PD0 */
        NOT_ON_TIMER,   /* 9  - PD1 */
        NOT_ON_TIMER,   /* 10 - PD2 */
        NOT_ON_TIMER,   /* 11 - PD3 */
        TIMER1B,        /* 12 - PD4 */
        TIMER1A,        /* 13 - PD5 */
        TIMER2B,        /* 14 - PD6 */
        TIMER2A,        /* 15 - PD7 */
        NOT_ON_TIMER,   /* 16 - PC0 */
        NOT_ON_TIMER,   /* 17 - PC1 */
        NOT_ON_TIMER,   /* 18 - PC2 */
        NOT_ON_TIMER,   /* 19 - PC3 */
        NOT_ON_TIMER,   /* 20 - PC4 */
        NOT_ON_TIMER,   /* 21 - PC5 */
        NOT_ON_TIMER,   /* 22 - PC6 */
        NOT_ON_TIMER,   /* 23 - PC7 */
        NOT_ON_TIMER,   /* 24 - PA0 */
        NOT_ON_TIMER,   /* 25 - PA1 */
        NOT_ON_TIMER,   /* 26 - PA2 */
        NOT_ON_TIMER,   /* 27 - PA3 */
        NOT_ON_TIMER,   /* 28 - PA4 */
        NOT_ON_TIMER,   /* 29 - PA5 */
        NOT_ON_TIMER,   /* 30 - PA6 */
        NOT_ON_TIMER   /* 31 - PA7 */
};
#endif
#endif
