#include "../Joystick.h"
#include "Scripts.h"

static uint16_t duration_count = 0;

void RestaurantFight(USB_JoystickReport_Input_t* const ReportData)
{
	// Simple loop: Press ZL and A repeatedly to farm restaurant fights
	// Total loop duration: 100 counts/~0.8 seconds
	switch(duration_count % 100)
	{
		case 25 ... 100:
			ReportData->Button |= SWITCH_ZL;
			if (duration_count % 50 > 25)
				ReportData->Button |= SWITCH_A;
			break;
		default:
		//do nothing
			break;
	}
	duration_count++;
}

