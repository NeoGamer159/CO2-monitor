#include "esp_wifi.h"
#include <string.h>

esp_err_t dev_wifi_init(void) {
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    esp_err_t ret;
    
    ret = esp_netif_init();
    if(ret != ESP_OK)
        return ret;
    
    ret = esp_event_loop_create_default();
    if(ret != ESP_OK)
        return ret;
    
    ret = esp_wifi_init(&cfg);
    if(ret != ESP_OK)
        return ret;

    return ESP_OK;
}

esp_err_t dev_wifi_sta_start(const char *ssid, const char *password) {
    wifi_config_t wifi_config = {0};
    
    esp_err_t ret;

    strncpy((char *)wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    strncpy((char *)wifi_config.sta.password, password, sizeof(wifi_config.sta.password));
    
    esp_netif_create_default_wifi_sta();

    ret = esp_wifi_set_mode(WIFI_MODE_STA);
    if(ret != ESP_OK)
        return ret;
    
    ret = esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    if(ret != ESP_OK)
        return ret;

    ret =esp_wifi_start();
    if(ret != ESP_OK)
        return ret;
    
    return ESP_OK;
}

esp_err_t dev_wifi_ap_start(void) {
    wifi_config_t wifi_config = {0};

    esp_err_t ret;

    strncpy((char *)wifi_config.ap.ssid, "CO2 Monitor Config", sizeof(wifi_config.ap.ssid));
    strncpy((char *)wifi_config.ap.password, "config123", sizeof(wifi_config.ap.password));
    

    esp_netif_create_default_wifi_ap();

    ret = esp_wifi_set_mode(WIFI_MODE_AP);
    if(ret != ESP_OK)
        return ret;

    ret = esp_wifi_set_config(WIFI_IF_AP, &wifi_config);
    if(ret != ESP_OK)
        return ret;

    ret = esp_wifi_start();
    if(ret != ESP_OK)
        return ret;
    
    return ESP_OK;
}