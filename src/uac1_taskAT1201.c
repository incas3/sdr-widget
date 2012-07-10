/* -*- mode: c++; tab-width: 4; c-basic-offset: 4 -*- */
/*
 * uac1_taskAT1201.c
 *
 *  Created on: Feb 14, 2010
 *  Refactored on: Feb 26, 2011
 *      Author: Alex
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
 *
 */

//_____  I N C L U D E S ___________________________________________________

//#include <stdio.h>
#include "usart.h"     // Shall be included before FreeRTOS header files, since 'inline' is defined to ''; leading to
                       // link errors
#include "conf_usb.h"


#include <avr32/io.h>
#if __GNUC__
#  include "intc.h"
#endif
#include "board.h"
#ifdef FREERTOS_USED
#include "FreeRTOS.h"
#include "task.h"
#endif
#include "usb_drv.h"
#include "gpio.h"
#include "ssc_i2s.h"
#include "pm.h"
#include "pdca.h"
#include "features.h"
#include "usb_standard_request.h"
#include "usb_specific_request.h"
#include "device_audio_task.h"
#include "uac1_device_audio_task.h"
#include "taskAT1201.h"
#include "uac1_taskAT1201.h"
#include "Mobo_config.h"

//_____ M A C R O S ________________________________________________________

//_____ D E F I N I T I O N S ______________________________________________

//_____ D E C L A R A T I O N S ____________________________________________

void uac1_AT1201_task(void*);

//!
//! @brief This function initializes the hardware/software resources
//! required for device CDC task.
//!
void uac1_AT1201_task_init(void) {
	AT1201_task_init(TRUE);
	xTaskCreate(uac1_AT1201_task,
				configTSK_AT1201_NAME,
				configTSK_AT1201_STACK_SIZE,
				NULL,
				UAC1_configTSK_AT1201_PRIORITY,
				NULL);
}

//!
//! @brief Entry point of the AT1201 task management
//!
void uac1_AT1201_task(void *pvParameters) {
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	int i;

	while (TRUE) {
		// All the hardwork is done by the pdca and the interrupt handler.
		// Just check whether alternate setting is changed, to do rate change etc.

		vTaskDelayUntil(&xLastWakeTime, UAC1_configTSK_AT1201_PERIOD);

		if (freq_changed) {
			spk_mute = TRUE;
			if (current_freq.frequency == 48000)
			{
				FB_rate = 48 << 14;
			}
			else
			{
				FB_rate = (44 << 14) + (1 << 14)/10 ;
			}
			spk_mute = FALSE;
			freq_changed = FALSE;
		}
		if (usb_alternate_setting_changed) {

			pdca_disable_interrupt_reload_counter_zero(PDCA_CHANNEL_SSC_RX);
			pdca_disable(PDCA_CHANNEL_SSC_RX);
			// L L  -> 48khz   L H  -> 96khz
			gpio_clr_gpio_pin(AT1201_DFS0);
			gpio_clr_gpio_pin(AT1201_DFS1);

			if (FEATURE_ADC_AT1201) {
				// re-sync SSC to LRCK
				// Wait for the next frame synchronization event
				// to avoid channel inversion.  Start with left channel - FS goes low
				while (!gpio_get_pin_value(AT1201_LRCK));
				while (gpio_get_pin_value(AT1201_LRCK));

				// Enable now the transfer.
				pdca_enable(PDCA_CHANNEL_SSC_RX);

				// Init PDCA channel with the pdca_options.
				AT1201_pdca_enable();
			}
			// reset usb_alternate_setting_changed flag
			usb_alternate_setting_changed = FALSE;
		}

		if (usb_alternate_setting_out_changed){
			if (usb_alternate_setting_out != 1){
				spk_mute = TRUE;
				for (i = 0; i < SPK_BUFFER_SIZE; i++){
					spk_buffer_0[i] = 0;
					spk_buffer_1[i] = 0;
				}
				spk_mute = FALSE;
			}
			usb_alternate_setting_out_changed = FALSE;
		}

		if (FEATURE_IMAGE_UAC1_DG8SAQ) {
			spk_mute = TX_state ? FALSE : TRUE;
			mute = TX_state ? TRUE : FALSE;
		}

	} // end while (TRUE)
}


