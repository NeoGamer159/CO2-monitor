#include <stdint.h>
#include "app_hmi.h"
#include "app_msm.h"
#include "dev_led.h"

void app_hmi_init(void) {
    dev_led_init();
    // TODO: dev_lcd_init();
}

void app_hmi_taskHandler(void) {
    switch(app_msm_getState()) {
        case APP_MSM_STATE_INIT:
            dev_led_set_mode(LED_MODE_OFF);
            break;
        case APP_MSM_STATE_AP_CONFIG:
            dev_led_set_mode(LED_MODE_BLINK_FAST);
            break;
        case APP_MSM_STATE_WIFI:
            dev_led_set_mode(LED_MODE_BLINK_SLOW);
            break;
        case APP_MSM_STATE_RUN:
            dev_led_set_mode(LED_MODE_OFF);
            break;
        case APP_MSM_STATE_ERROR:
            dev_led_set_mode(LED_MODE_OFF);
            break;
    }
}