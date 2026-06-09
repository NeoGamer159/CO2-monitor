#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "dev_led.h"

void app_main(void) {
    dev_led_init();

    while (1) {
        dev_led_init();
        dev_led_set_mode(LED_MODE_BLINK_SLOW);
        
        while (1) {
            dev_led_run();
            vTaskDelay(pdMS_TO_TICKS(50));
        }
    }
}