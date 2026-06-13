#include "nvs_flash.h"
#include "dev_nvs.h"

esp_err_t dev_nvs_init(void) {
    return nvs_flash_init();
}
/**
 * TODO: error handling
 * @author Miloslav Cerny
 * @brief Loads data from NVS into defined strucure
 * @return void
 */
void dev_nvs_getData(dev_nvs_data_t *out) {
    nvs_handle_t handle;

    esp_err_t err = nvs_open("storage", NVS_READONLY, &handle);
    if (err != ESP_OK) {
        return;
    }
    size_t len;

    len = sizeof(out->ssid);
    nvs_get_str(handle, "ssid", out->ssid, &len);

    len = sizeof(out->password);
    nvs_get_str(handle, "password", out->password, &len);

    len = sizeof(out->influxdb_token);
    nvs_get_str(handle, "influxdb_token", out->influxdb_token, &len);

    nvs_get_u8(handle, "lcd_enabled", (uint8_t *)&out->lcd_enabled);

    nvs_close(handle);
}

void dev_nvs_setData(const dev_nvs_data_t *in) {
    nvs_handle_t handle;
    esp_err_t err;

    err = nvs_open("storage", NVS_READWRITE, &handle);
    if (err != ESP_OK) {
        return;
    }

    err = nvs_set_str(handle, "ssid", in->ssid);
    if (err != ESP_OK) {
        nvs_close(handle);
        return;
    }

    err = nvs_set_str(handle, "password", in->password);
    if (err != ESP_OK) {
        nvs_close(handle);
        return;
    }

    err = nvs_set_str(handle, "influxdb_token", in->influxdb_token);
    if (err != ESP_OK) {
        nvs_close(handle);
        return;
    }

    err = nvs_set_u8(handle, "lcd_enabled", in->lcd_enabled);
    if (err != ESP_OK) {
        nvs_close(handle);
        return;
    }
    
    nvs_commit(handle);
    nvs_close(handle);
}
