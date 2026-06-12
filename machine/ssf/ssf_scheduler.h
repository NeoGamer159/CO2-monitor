#pragma once

#include <stdint.h>

typedef struct {
    const char *name;
    void       (*fn)(void);
    uint32_t   interval_ms;
    uint32_t   last_run_ms;
} ssf_task_t;

void ssf_scheduler_init(ssf_task_t *tasks, uint32_t count);
void ssf_scheduler_tick(void);