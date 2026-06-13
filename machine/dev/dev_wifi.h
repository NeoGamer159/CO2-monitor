#pragma once

#include "esp_err.h"

esp_err_t dev_wifi_init(void);
esp_err_t dev_wifi_sta_start(const char *ssid, const char *password);
esp_err_t dev_wifi_ap_start(void);
