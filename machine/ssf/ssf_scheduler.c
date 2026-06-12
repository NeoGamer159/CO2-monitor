#include "ssf_scheduler.h"
#include "esp_timer.h"

static ssf_task_t *s_tasks;
static uint32_t    s_count;

void ssf_scheduler_init(ssf_task_t *tasks, uint32_t count) {
    s_tasks = tasks;
    s_count = count;
}

void ssf_scheduler_tick(void) {

    uint32_t now = (uint32_t)(esp_timer_get_time() / 1000);

    for (uint32_t i = 0; i < s_count; i++) {
        if (now - s_tasks[i].last_run_ms >= s_tasks[i].interval_ms) {
            s_tasks[i].fn();
            s_tasks[i].last_run_ms = now;
        }
    }
}