#include <stdio.h>
#include "esp_timer.h"
#include "mhz19.h"

void app_main(void)
{
    mhz19_init(MHZ19_UART_NUM);
    int co2;
    int64_t last_read = 0;
    
    while (1) {
        int64_t now = esp_timer_get_time(); // mikrosekundy
        if (now - last_read >= 5000000) {   // 5 sekund
            last_read = now;
            if (mhz19_read_co2(MHZ19_UART_NUM, &co2) == ESP_OK) {
                printf("CO2: %d ppm\n", co2);
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10)); // malý delay aby FreeRTOS mohl dýchat
    }
}