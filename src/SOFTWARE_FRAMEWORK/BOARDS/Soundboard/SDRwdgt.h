/* -*- mode: c; tab-width: 4; c-basic-offset: 4 -*- */
#ifndef _SDRwdgt_H_
#define _SDRwdgt_H_

 /*
 * Additions and Modifications to ATMEL AVR32-SoftwareFramework-AT32UC3 are:
 *
 * Copyright (C) Alex Lee
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "compiler.h"

#ifdef __AVR32_ABI_COMPILER__ // Automatically defined when compiling for AVR32, not when assembling.
#include "led.h"
#endif  // __AVR32_ABI_COMPILER__


/*! \name Oscillator Definitions
 */
//! @{

// RCOsc has no custom calibration by default. Set the following definition to
// the appropriate value if a custom RCOsc calibration has been applied to your
// part.
//#define FRCOSC          AVR32_PM_RCOSC_FREQUENCY              //!< RCOsc frequency: Hz.

#define FOSC32          32768                                 //!< Osc32 frequency: Hz.
#define OSC32_STARTUP   AVR32_PM_OSCCTRL32_STARTUP_8192_RCOSC //!< Osc32 startup time: RCOsc periods.

#define FOSC0           12000000                              //!< Osc0 frequency: Hz.
#define OSC0_STARTUP    AVR32_PM_OSCCTRL0_STARTUP_2048_RCOSC  //!< Osc0 startup time: RCOsc periods.

// Osc1 crystal is not mounted by default. Set the following definitions to the
// appropriate values if a custom Osc1 crystal is mounted on your board.
#define FOSC1           24576000  // 12288000                              //!< Osc1 frequency: Hz.
#define OSC1_STARTUP    AVR32_PM_OSCCTRL1_STARTUP_2048_RCOSC  //!< Osc1 startup time: RCOsc periods.

//! @}
/*! \name System Clock Frequencies
 */
//! @{
#define FMCK_HZ                       FOSC0
#define FCPU_HZ                       66000000
#define FHSB_HZ                       33000000
#define FPBB_HZ                       33000000
//#define FPBA_HZ                       33000000
#define FPBA_HZ                       66000000
//! @}


/*! \name USB Definitions
 */
//! @{

//! Multiplexed pin used for USB_ID: AVR32_USBB_USB_ID_x_x.
//! To be selected according to the AVR32_USBB_USB_ID_x_x_PIN and
//! AVR32_USBB_USB_ID_x_x_FUNCTION definitions from <avr32/uc3axxxx.h>.
#define USB_ID                      AVR32_USBB_USB_ID_0_3               // pin 124

//! Multiplexed pin used for USB_VBOF: AVR32_USBB_USB_VBOF_x_x.
//! To be selected according to the AVR32_USBB_USB_VBOF_x_x_PIN and
//! AVR32_USBB_USB_VBOF_x_x_FUNCTION definitions from <avr32/uc3axxxx.h>.
#define USB_VBOF                    AVR32_USBB_USB_VBOF_0_3             // pin 127

//! Active level of the USB_VBOF output pin.
#define USB_VBOF_ACTIVE_LEVEL       LOW


//! Number of LEDs.
#define LED_COUNT   4

/*! \name GPIO Connections of LEDs
 */
//! @{
#define LED0_GPIO   AVR32_PIN_PX39
#define LED1_GPIO   AVR32_PIN_PX43
#define LED2_GPIO   AVR32_PIN_PX47
#define LED3_GPIO   AVR32_PIN_PX51
//! @}

/*! \name PWM Channels of LEDs
 */
//! @{
#define LED0_PWM    (-1)
#define LED1_PWM    (-1)
#define LED2_PWM    (-1)
#define LED3_PWM    (-1)

//! @}

/*! \name PWM Functions of LEDs
 */
//! @{
#define LED0_PWM_FUNCTION   (-1)
#define LED1_PWM_FUNCTION   (-1)
#define LED2_PWM_FUNCTION   (-1)
#define LED3_PWM_FUNCTION   (-1)

//! @}

/*! \name Color Identifiers of LEDs to Use with LED Functions
 */
//! @{
#define LED_MONO0_GREEN   LED0
#define LED_MONO1_GREEN   LED1
#define LED_MONO2_GREEN   LED2
#define LED_MONO3_GREEN   LED3
//! @}

/*! \name GPIO Connections of the SW2 Push Button
 */
//! @{
#define GPIO_PUSH_BUTTON_SW2            AVR32_PIN_PB10
#define PRG_BUTTON						GPIO_PUSH_BUTTON_SW2
#define GPIO_PUSH_BUTTON_SW2_PRESSED    0
//! @}


/*! \name AK5493 24 bit hi-performance ADC
 */
//! @{
#define AT1201_DFS0                      AVR32_PIN_PX12		// sampling speed control
#define AT1201_DFS1                      AVR32_PIN_PX13		// sampling speed control
#define AT1201_RSTN                      AVR32_PIN_PX00		// reset 
#define AT1201_HPFE                      AVR32_PIN_PX09		// High Pass Filter

#define AT1201_MASTER 					 AVR32_PIN_PX29		// ADC master_mode
#define AT1201_MDIV						 AVR32_PIN_PX08		// MDIV
#define AT1201_LJUST					 AVR32_PIN_PX11		// i2s left justify 
#define AT1201_PHANTOM					 AVR32_PIN_PX16		//enable phantom power

#define AT1201_PCM_ENABLE				 AVR32_PIN_PX31		// PCM enable
#define AT1201_MULTIBIT_ENABLE			 AVR32_PIN_PX30		// Multibit disable
#define AT1201_DSD_ENABLE				 AVR32_PIN_PX33		// DSD disable

#define AT1201_TEST_SIG1				 AVR32_PIN_PX56		// test sig 1
#define AT1201_TEST_SIG2				 AVR32_PIN_PX57		// test sig 2

// NOTE:: need to work on these pin assignments
#define AT1201_LRCK                      AVR32_PIN_PX26		// Left Right clock
#define AT1201_SDATA                     AVR32_PIN_PX25
#define AT1201_SCLK                      AVR32_PIN_PX28		// trace on board to PX34  ??

//! @}

/*! \name 4 bit LCD display connections
 */
//! @{
#define LCD_BL_PIN                      AVR32_PIN_PX14		// PWM1 to gate of FET
#define LCD_D4                          AVR32_PIN_PX38
#define LCD_D5                          AVR32_PIN_PX39
#define LCD_D6                          AVR32_PIN_PX40
#define LCD_D7                          AVR32_PIN_PX41
#define LCD_E                           AVR32_PIN_PX48
#define LCD_RS                          AVR32_PIN_PX49
#define LCD_RW                          AVR32_PIN_PX53
//! @}

/*! \name TWI Connections of the Spare TWI Connector
 */
//! @{
#define TWIM1                    	(&AVR32_TWIM1)
#define TWIM1_SCL_PIN            	AVR32_TWIMS1_TWCK_0_PIN
#define TWIM1_SCL_FUNCTION       	AVR32_TWIMS1_TWCK_0_FUNCTION
#define TWIM1_SDA_PIN            	AVR32_TWIMS1_TWD_0_PIN
#define TWIM1_SDA_FUNCTION       	AVR32_TWIMS1_TWD_0_FUNCTION

#define TWIM0                   	(&AVR32_TWIM0)
#define TWIM0_SCL_PIN           	AVR32_TWIMS0_TWCK_0_0_PIN
#define TWIM0_SCL_FUNCTION      	AVR32_TWIMS0_TWCK_0_0_FUNCTION
#define TWIM0_SDA_PIN           	AVR32_TWIMS0_TWD_0_0_PIN
#define TWIM0_SDA_FUNCTION      	AVR32_TWIMS0_TWD_0_0_FUNCTION
//! @}


/*! \name Quadrature encoder w/pushbutton
 */
//! @{
#define ENCODER_ROTQ_PIN            AVR32_EIC_EXTINT_8_PIN	//AVR32_PIN_PA20
#define ENCODER_ROTQ_FUNCTION		AVR32_EIC_EXTINT_8_FUNCTION
//NMI does not require a #define ENCODER_ROTQ_IRQ
#define ENCODER_ROTQ_INT			EXT_NMI

#define ENCODER_ROTI_PIN            AVR32_EIC_EXTINT_7_PIN	//AVR32_PIN_PA13
#define ENCODER_ROTI_FUNCTION		AVR32_EIC_EXTINT_7_FUNCTION
#define ENCODER_ROTI_IRQ			AVR32_EIC_IRQ_7
#define ENCODER_ROTI_INT			EXT_INT7

#define ENCODER_SWITCH              AVR32_PIN_PA12

//! @}

/*! \name USART Settings for the SDR-Widget boards
 */
//! @{

#define USART               (&AVR32_USART1)
#define USART_RX_PIN        AVR32_USART1_RXD_0_2_PIN
#define USART_RX_FUNCTION   AVR32_USART1_RXD_0_2_FUNCTION
#define USART_TX_PIN        AVR32_USART1_TXD_0_2_PIN
#define USART_TX_FUNCTION   AVR32_USART1_TXD_0_2_FUNCTION
#define USART_CLOCK_MASK    AVR32_USART1_CLK_PBA

/*! \name SSC Settings for the SDR-Widget boards
 */
//! @{

#define SSC_RX_DATA				AVR32_SSC_RX_DATA_0_2_PIN
#define SSC_RX_DATA_FUNCTION	AVR32_SSC_RX_DATA_0_2_FUNCTION
#define SSC_RX_FRAME_SYNC		AVR32_SSC_RX_FRAME_SYNC_0_2_PIN
#define SSC_RX_FRAME_SYNC_FUNCTION	AVR32_SSC_RX_FRAME_SYNC_0_2_FUNCTION
#define SSC_RX_CLOCK			AVR32_SSC_RX_CLOCK_0_1_PIN
#define	SSC_RX_CLOCK_FUNCTION	AVR32_SSC_RX_CLOCK_0_1_FUNCTION
#define SSC_TX_DATA				AVR32_SSC_TX_DATA_0_1_PIN
#define SSC_TX_DATA_FUNCTION	AVR32_SSC_TX_DATA_0_1_FUNCTION
#define SSC_TX_FRAME_SYNC		AVR32_SSC_TX_FRAME_SYNC_0_1_PIN
#define SSC_TX_FRAME_SYNC_FUNCTION	AVR32_SSC_TX_FRAME_SYNC_0_1_FUNCTION
#define SSC_TX_CLOCK			AVR32_SSC_TX_CLOCK_0_1_PIN
#define	SSC_TX_CLOCK_FUNCTION	AVR32_SSC_TX_CLOCK_0_1_FUNCTION

/*! \name GCLK Settings for the SDR-Widget boards
 */
//! @{

#define GCLK0				AVR32_PM_GCLK_0_2_PIN
#define GCLK0_FUNCTION		AVR32_PM_GCLK_0_2_FUNCTION
#define	GCLK1				AVR32_PM_GCLK_1_1_PIN
#define GCLK1_FUNCTION		AVR32_PM_GCLK_1_1_FUNCTION
#define GCLK2				AVR32_PM_GCLK_2_PIN
#define GCLK2_FUNCTION		AVR32_PM_GCLK_2_FUNCTION

/*! \name GPIO Connections of the CW key inputs
 */
//! @{

//#define GPIO_CW_KEY_1        AVR32_PIN_PB9
#define GPIO_CW_KEY_1        AVR32_PIN_PX00
#define GPIO_CW_KEY_2        AVR32_PIN_PX01
#define GPIO_PTT_INPUT       AVR32_PIN_PX02

#define PTT_1				 AVR32_PIN_PX45
#define PTT_2				 AVR32_PIN_PX42
#define PTT_3				 AVR32_PIN_PX22
//! @}

// Inhale list of required modules
#include "SDR-Widget.h"

#endif  // _SDRwdgt_H_
