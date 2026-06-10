#pragma once

typedef enum {
    LED_MODE_OFF,
    LED_MODE_ON,
    LED_MODE_BLINK_SLOW,   // 1x za 2s
    LED_MODE_BLINK_FAST,   // 5x za 1s
} led_mode_t;

void dev_led_init(void);
void dev_led_set_mode(led_mode_t mode);
void dev_led_run(void);
void dev_led_taskHandler(void);