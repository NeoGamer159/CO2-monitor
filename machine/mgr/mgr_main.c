#include "mgr_main.h"
#include "mgr_task.h"
#include "app_msm.h"
#include "app_hmi.h"
#include "dev_led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void mgr_main(void) {
    app_msm_init();
    app_hmi_init();
    mgr_task_init();

    while (1) {
        mgr_task_run();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}