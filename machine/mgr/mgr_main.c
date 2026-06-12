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
    ssf_scheduler_init(mgr_task_table, mgr_task_count);

    while (1) {
        ssf_scheduler_tick();
        vTaskDelay(1);
    }
}