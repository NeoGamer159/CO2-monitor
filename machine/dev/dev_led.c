#include "dev_led.h"
#include "drv_led.h"
#include <stdint.h>

static led_mode_t current_mode = LED_MODE_OFF;
static uint32_t tick = 0;

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
    tick++;

    switch(current_mode) {
        case LED_MODE_OFF:
            drv_led_set(false);
            break;
        case LED_MODE_ON:
            drv_led_set(true);
            break;
        case LED_MODE_BLINK_SLOW:
            drv_led_set((tick % 40) < 2);
            break;
        case LED_MODE_BLINK_FAST:
            drv_led_set((tick % 4) < 2);
            break;
    }
}