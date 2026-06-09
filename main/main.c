#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "drv_led.h"

void app_main(void) {
    drv_led_init();

    while (1) {
        drv_led_set(true);
        vTaskDelay(pdMS_TO_TICKS(500));
        drv_led_set(false);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}