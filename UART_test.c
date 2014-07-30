/*
 * main.c
 */
//#define GPIO_PA0_U0RX           0x00000001
//#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB0_U1RX           0x00010001
#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_memmap.h>
#include <driverlib/sysctl.h>
#include<driverlib/gpio.h>
#include <driverlib/uart.h>
#include <inc/tm4c123gh6pm.h>
//#include "driverlib/pin_map.h"
void PortInit();
void UARTInit();
int main(void) {
	SysCtlClockSet(SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ|SYSCTL_SYSDIV_2_5);
	int clock_rate = SysCtlClockGet();
	PortInit();
	UARTInit();
	while(1){
		int index=0;
		char *msg;
		msg = "Hello Saleem ";
		while(msg[index]!='\0'){
			UARTCharPutNonBlocking(UART1_BASE,msg[index]);
			index++;
		}
		SysCtlDelay(800000);

	}
}
void PortInit()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	GPIOPinConfigure(GPIO_PB0_U1RX);
	GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0);

	GPIOPinConfigure(GPIO_PB1_U1TX);
	GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_1);
	}
void UARTInit()
{
	UARTClockSourceSet(UART1_BASE,UART_CLOCK_SYSTEM);
	UARTConfigSetExpClk(UART1_BASE,SysCtlClockGet(),9600,(UART_CONFIG_WLEN_8|UART_CONFIG_PAR_NONE|UART_CONFIG_STOP_ONE));
//	UARTFIFOEnable(UART1_BASE);
	UARTEnable(UART1_BASE);
}
