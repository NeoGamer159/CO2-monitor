#pragma once

typedef enum {
    APP_MSM_STATE_INIT,
    APP_MSM_STATE_AP_CONFIG,
    APP_MSM_STATE_WIFI,
    APP_MSM_STATE_RUN,
    APP_MSM_STATE_ERROR,
} app_msm_state_t;

void app_msm_init(void);
void app_msm_taskHandler(void);

app_msm_state_t app_msm_getState(void);