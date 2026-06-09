#include "drv_led.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_2

void drv_led_init(void) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
}

void drv_led_set(bool on) {
    gpio_set_level(LED_GPIO, on ? 1 : 0);
}