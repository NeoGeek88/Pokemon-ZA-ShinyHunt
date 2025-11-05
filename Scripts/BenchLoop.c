#include "../Joystick.h"
#include "Scripts.h"

static uint16_t duration_count = 0;

void BenchLoop(USB_JoystickReport_Input_t* const ReportData)
{
	// Simple loop: Move down, wait, press A, wait, repeat
	// Total loop duration: 3000 counts/~22 seconds
	switch(duration_count % 3500)
	{
		case 25 ... 50:
		// move up
			ReportData->LY = STICK_MAX;
			break;
		case 75 ... 549:
		// press A
			if (duration_count % 50 < 25)
				ReportData->Button |= SWITCH_A;
			break;
		default:
		// wait for loading, do nothing
			break;
	}
	duration_count++;
}
