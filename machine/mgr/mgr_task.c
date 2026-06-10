#include <stdint.h>
#include "mgr_task.h"
#include "dev_led.h"
#include "app_msm.h"
#include "app_hmi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct {
    const char  *name;
    void        (*fn)(void);
    uint32_t    interval_ms;
    uint32_t    last_run_ms;
} task_entry_t;

static task_entry_t task_table[] = {
    { "app_msm_taskHandler", app_msm_taskHandler, 10, 0 },
    { "app_hmi_taskHandler", app_hmi_taskHandler, 50, 0 },
    {"app_led_taskHandler", dev_led_taskHandler, 100, 0 },
};

void mgr_task_init(void) {
    // tabulka je statická, zatím nic
}

void mgr_task_run(void) {
    uint32_t now = xTaskGetTickCount() * portTICK_PERIOD_MS;

    for (int i = 0; i < ARRAY_SIZE(task_table); i++) {
        if (now - task_table[i].last_run_ms >= task_table[i].interval_ms) {
            task_table[i].fn();
            task_table[i].last_run_ms = now;
        }
    }
}