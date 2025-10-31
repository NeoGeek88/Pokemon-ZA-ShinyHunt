#include "../Joystick.h"
#include "Scripts.h"

static uint16_t duration_count = 0;

void EnterWildAreaCommon(USB_JoystickReport_Input_t* const ReportData)
{
	// Simple loop: Move up, wait, press A, open map, press A, press A, repeat
	// Total loop duration: 1600 counts/~12 seconds
	switch(duration_count % 1600)
	{
		case 25 ... 99:
		// move up
			ReportData->LY = STICK_MIN;
			break;
		case 125 ... 149:
		// press A
			ReportData->Button |= SWITCH_A;
			break;
		case 425 ... 449:
		// open map
			ReportData->Button |= SWITCH_START;
			break;
		case 475 ... 499:
		// press A
			ReportData->Button |= SWITCH_A;
			break;
		case 625 ... 649:
		// press A
			ReportData->Button |= SWITCH_A;
			break;
		default:
		// wait for loading, do nothing
			break;
	}
	duration_count++;
}