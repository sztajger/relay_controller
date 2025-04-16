#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#include "rom/ets_sys.h"
#include "esp_log.h"

#include "setup.h"
#include "button_handler.h"

//minicom -D /dev/ttyUSB0 -b 115200 uart debuger in bash

static const char *tag = "MAIN";

void app_main() 
{

    ESP_LOGI(tag, "hello world");
    
    //void setup(void);

    TimerHandle_t debounce_timer = NULL;

    setup_gpio();
    setup_timer(&debounce_timer);
    setup_isr(debounce_timer);

    ESP_LOGI(tag, "SYTEM INITIALIZED");

    while(1)
    {
        ESP_LOGI(tag, "Button state: %d", gpio_get_level(BUTTON_PIN));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}