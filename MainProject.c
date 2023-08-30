#include "Main.h"
#include "Mcu_ini.h"


uint16_t delay_count=0;


void SysTick_Handler(void)
{
if (delay_count>0)
	{
		delay_count--;
	}
}

void delay_ms(uint16_t delay_temp)
{
delay_count=delay_temp;
	while (delay_count){}
}


int main (void)
{
LEDs_ini();
SysTick_Config(SystemCoreClock/1000); //1ms
	
	while(1)
	{
	BLUE_OFF();
	GREEN_ON();
	delay_ms(TIME);
	
	GREEN_OFF();
	ORANGE_ON();	
	delay_ms(TIME);
		
	ORANGE_OFF();
	RED_ON();
	delay_ms(TIME);
		
	RED_OFF();
	BLUE_ON();
	delay_ms(TIME);
	}

}
