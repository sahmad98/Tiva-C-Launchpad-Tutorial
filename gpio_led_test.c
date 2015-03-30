#define BASE_F 0x40025000
#include <stdint.h>
#include <stdbool.h>

#include "inc/tm4c123gh6pm.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
int main(void) {
	SysCtlClockSet(SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_RCC_XTAL_16MHZ|SYSCTL_SYSDIV_2_5);
	SysCtlDelay(100);
	int clock = SysCtlClockGet();
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
	GPIOPadConfigSet(BASE_F,GPIO_PIN_3,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPD);
	GPIODirModeSet(BASE_F,GPIO_PIN_3,GPIO_DIR_MODE_OUT);
	while(1){
		SysCtlDelay(8000000);
		GPIOPinWrite(BASE_F,GPIO_PIN_3,0x00);
		SysCtlDelay(8000000);
		GPIOPinWrite(BASE_F,GPIO_PIN_3,0x08);

	}

}
