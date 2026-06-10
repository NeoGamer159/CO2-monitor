#include <stdint.h>
#include "app_msm.h"
#include "esp_log.h"

typedef enum {
    MSM_LOCAL_STATE_ENTRY,
    MSM_LOCAL_STATE_RUN,
    MSM_LOCAL_STATE_EXIT,
} app_msm_local_state_t;

typedef struct {
    app_msm_local_state_t localState;
} app_msm_args_t;

static void msm_handler_init(app_msm_args_t *args);
static void msm_handler_ap_config(app_msm_args_t *args);
static void msm_handler_wifi(app_msm_args_t *args);
static void msm_handler_run(app_msm_args_t *args);
static void msm_handler_error(app_msm_args_t *args);

typedef void (*msm_state_fn)(app_msm_args_t *args);

static msm_state_fn msm[5] =  {
    &msm_handler_init,
    &msm_handler_ap_config,
    &msm_handler_wifi,
    &msm_handler_run,
    &msm_handler_error,
};

//State machine actual state
static app_msm_state_t current_state;

//local state 
static app_msm_args_t args;  

app_msm_state_t app_msm_getState(void) {
    return current_state;
}
void app_msm_init(void) {
    current_state = APP_MSM_STATE_INIT;
    args.localState = MSM_LOCAL_STATE_ENTRY;
}

void app_msm_taskHandler(void) {
    msm[current_state](&args);
}

static void msm_handler_init(app_msm_args_t *args) {
    switch(args->localState) {
        case MSM_LOCAL_STATE_ENTRY:
            ESP_LOGI("MSM", "INIT - ENTRY");
            args->localState = MSM_LOCAL_STATE_RUN;
            /* fall through */
        case MSM_LOCAL_STATE_RUN:
            ESP_LOGI("MSM", "INIT - RUN");
            // TODO: if (sys_nvs_load_credentials() == ESP_OK)
            current_state = APP_MSM_STATE_WIFI;
            args->localState = MSM_LOCAL_STATE_EXIT;
            break;
        case MSM_LOCAL_STATE_EXIT:
            args->localState = MSM_LOCAL_STATE_ENTRY;
            break;
    }
}

static void msm_handler_wifi(app_msm_args_t *args) {
    switch(args->localState) {
        case MSM_LOCAL_STATE_ENTRY:
            ESP_LOGI("MSM", "WIFI - ENTRY");
            args->localState = MSM_LOCAL_STATE_RUN;
            /* fall through */
        case MSM_LOCAL_STATE_RUN:
            break;
        case MSM_LOCAL_STATE_EXIT:
            args->localState = MSM_LOCAL_STATE_ENTRY;
            break;
    }
}

static void msm_handler_ap_config(app_msm_args_t *args) {

}

static void msm_handler_error(app_msm_args_t *args) {

}

static void msm_handler_run(app_msm_args_t *args) {

}