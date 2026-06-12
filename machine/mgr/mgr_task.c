#include "mgr_task.h"
#include "app_msm.h"
#include "app_hmi.h"
#include "dev_led.h"

ssf_task_t mgr_task_table[] = {
    { "app_msm", app_msm_taskHandler, 10,  0 },
    { "app_hmi", app_hmi_taskHandler, 50,  0 },
    { "dev_led", dev_led_taskHandler, 100, 0 },
};

const uint32_t mgr_task_count = sizeof(mgr_task_table) / sizeof(mgr_task_table[0]);