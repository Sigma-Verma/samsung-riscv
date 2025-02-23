#include <ch32v00x.h>
#include <debug.h>
#include <stdio.h>

#define LED1_PIN GPIO_Pin_2 // Bit 0
#define LED2_PIN GPIO_Pin_3 // Bit 1
#define LED3_PIN GPIO_Pin_4 // Bit 2
#define LED4_PIN GPIO_Pin_5 // Bit 3
#define LED_PORT GPIOD

void GPIO_Config(void) {
    // Enable the clock for GPIOD
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    // Configure PD4, PD5, PD6, and PD7 as outputs
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // Push-pull output
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void display_binary(uint8_t value) {
    // Clear all LEDs
    GPIO_ResetBits(LED_PORT, LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN);

    // Set bits according to the counter value
    if (value & 0x01) GPIO_SetBits(LED_PORT, LED1_PIN); // Bit 0
    if (value & 0x02) GPIO_SetBits(LED_PORT, LED2_PIN); // Bit 1
    if (value & 0x04) GPIO_SetBits(LED_PORT, LED3_PIN); // Bit 2
    if (value & 0x08) GPIO_SetBits(LED_PORT, LED4_PIN); // Bit 3
}

int main(void) {   
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_Config(); // Initialize the GPIO for the LEDs

    uint8_t counter = 0;
    
    while (1) {
        display_binary(counter); // Show counter value on LEDs
        Delay_Ms(500); // Delay for 1 second
        counter = (counter + 1) & 0x0F; // Increment counter (wraps at 15)
    }
    
    return 0;
}
