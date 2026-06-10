#include "dev_led.h"
#include "drv_led.h"
#include <stdint.h>
#include "freertos/FreeRTOS.h"

static led_mode_t current_mode = LED_MODE_OFF;

void dev_led_init(void) {
    drv_led_init();
}

void dev_led_set_mode(led_mode_t mode) {
    current_mode = mode;
}

void dev_led_taskHandler(void) {
    dev_led_run();
}

void dev_led_run(void) {
    uint32_t now = xTaskGetTickCount() * portTICK_PERIOD_MS;

    switch(current_mode) {
        case LED_MODE_OFF:
            drv_led_set(false);
            break;
        case LED_MODE_ON:
            drv_led_set(true);
            break;
        case LED_MODE_BLINK_SLOW:
            drv_led_set((now % 2000) < 100);
            break;
        case LED_MODE_BLINK_FAST:
            drv_led_set((now % 200) < 100);
            break;
    }
}