#include "../Joystick.h"
#include "Scripts.h"

static uint16_t duration_count = 0;

void WildArea16(USB_JoystickReport_Input_t* const ReportData)
{
	// Simple loop: Open map, slightly move upper right, press A twice, repeat
    // Total loop duration: 1300 counts/~10 seconds
	switch(duration_count % 1300)
	{
		case 25 ... 49:
		// open map
			ReportData->Button |= SWITCH_START;
			break;
		case 75 ... 99:
		// Slightly move upper right
			ReportData->LX = STICK_CENTER + 75;
            ReportData->LY = STICK_MIN;
			break;
		case 125 ... 349:
		// press A
            if (duration_count % 50 > 25)
			    ReportData->Button |= SWITCH_A;
			break;
		default:
		// wait for loading, do nothing
			break;
	}
	duration_count++;
}