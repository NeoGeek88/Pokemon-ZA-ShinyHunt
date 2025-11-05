#include "../Joystick.h"
#include "Scripts.h"

static uint16_t duration_count = 0;

void BenchLoopArea20(USB_JoystickReport_Input_t* const ReportData)
{
	// Simple loop: Move right, move left, move up, wait, press A, wait, repeat
	// Total loop duration: 3800 counts/~27 seconds - Switch
	// Total loop duration: 3600 counts/~25 seconds - Switch 2
	switch(duration_count % 3800)
	{
		case 25 ... 200:
		// move right
			ReportData->LX = STICK_MAX;
			break;
		case 225 ... 385:
		// move left
			ReportData->LX = STICK_MIN;
			break;
		case 425 ... 450:
		// move up
			ReportData->LY = STICK_MAX;
			break;
		case 475 ... 949:
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
