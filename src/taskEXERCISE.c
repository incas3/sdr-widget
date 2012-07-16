#include <stdint.h>
#include <string.h>

#include "board.h"

#include "FreeRTOS.h"
#include "task.h"
#include "taskEXERCISE.h"
#include "soundboard_toggles.h"

static void vtaskEXERCISE( void * pcParameters ) {
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	  while (TRUE){

		vTaskDelayUntil(&xLastWakeTime, configTSK_EXERCISE_PERIOD);

       // check_feature_change();

    }
}

void vStartTaskEXERCISE( unsigned portBASE_TYPE uxPriority )
{
	xTaskCreate( vtaskEXERCISE,
               ( signed char * ) "taskEXERCISE",
                 configTSK_EXERCISE_STACK_SIZE,
                 NULL,
                 configTSK_EXERCISE_PRIORITY,
                ( xTaskHandle * ) NULL );
}

