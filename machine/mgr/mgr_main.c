#include "mgr_main.h"
#include "mgr_task.h"
#include "app_msm.h"
#include "dev_led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void mgr_main(void) {
    dev_led_init();
    app_msm_init();
    dev_led_set_mode(LED_MODE_BLINK_SLOW);
    mgr_task_init();

    while (1) {
        mgr_task_run();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}