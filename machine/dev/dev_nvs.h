#pragma once

#include <stdbool.h>
#include "nvs_flash.h"
#include "esp_err.h"

typedef struct {
    char ssid[32];
    char password[64];
    char influxdb_token[128];
    bool lcd_enabled;
} dev_nvs_data_t;

esp_err_t dev_nvs_init(void);
void dev_nvs_getData(dev_nvs_data_t *out);
void dev_nvs_setData(const dev_nvs_data_t *in);
