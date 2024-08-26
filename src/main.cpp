#include <main.h>
#include <led.h>

Led status_led = Led(256);

int main(void){
	// Configure priority grouping
    //
    // 2 bits for pre-emption priority and 2 bits for subpriority.
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	// Update system core clock update
    SystemCoreClockUpdate();

	// Initialise the delay function
    Delay_Init();
	SDI_Printf_Enable();

	// Enable the high speed peripheral clock
    //
    // For APB2 peripheral GPIOD
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	// Initialise GPIO
    //
    // To initialise the GPIO pin and port defined for outputting the blink 
    // signal we need to populate a structure of type GPIO_InitTypeDef by
    // setting the pin, mode (output) and the speed (50MHz). We then call
    // GPIO_Init with the port defined in the header and the init structure
    // as arguments.
    GPIO_InitTypeDef GPIO_InitStructure = {0};
	GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

	uint16_t i = 0;
	uint8_t brightness = 0;
	bool brightness_direction = false;

	printf("Hello SDI console\n");
	printf("ChipID: %08X\n", DBGMCU_GetCHIPID());
	
	while(1){
		BitAction result = status_led.update_led();

		GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, result);

		i++;

		if(i>150){
			i = 0;
			status_led.set_brightness(brightness);
			if(brightness_direction){
				brightness++;
			} else{
				brightness--;
			}
			if(!brightness){
				brightness_direction = brightness_direction ^ 1;
			}
		}
		Delay_Us(10);
	}
}