#include<ch32v00x.h>
#include<debug.h>

#define BLINKY_GPIO_PORT GPIOC
#define BLINKY_GPIO_PIN GPIO_Pin_1

#define BLINKY_ON                   0
#define BLINKY_OFF                  1
#define BLINK_LENGTH_MS             100

#define OK                          0
#define ERR_OUT_OF_RANGE            1

int main(void);

/**
 * @brief Handler for non-maskable interrupts (nmi)
 * 
 * Non-maskable interrupts (nmi) are interrupts that the mcu canot ignore and that 
 * need to be attended to immediately. In our mini blinky example, the nmi
 * handler will just do nothing. Who really cares if we crash and burn.
 */
void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/**
 * @brief Fault handler
 * 
 * Faults are errors that occure during runtime. An example would be a NULL
 * pointer derefference. This handler for our blinky example will just enter
 * and infinite loop, effectively thorwing the system to non action in ever
 * lasting limbo.
 */
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));