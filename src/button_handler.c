#include "button_handler.h"
#include "setup.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_rom_sys.h"

static const char *tag = "BUTTON_HANDLER";
static uint8_t led_state = 0;

/** ISR: Handle interrupt when button is pressed */

static void IRAM_ATTR button_isr_handler(void *arg)
{
    TimerHandle_t debounce_timer = (TimerHandle_t)arg;
    BaseType_t result = xTimerResetFromISR(debounce_timer, NULL);
    if (result != pdPASS)
    {
        ets_printf("Timer reset filed\n");
    }
}

/** Debounce timer callback */
void debounce_timer_callback(TimerHandle_t xTimer)
{
    int button_level = gpio_get_level(BUTTON_PIN);
    ESP_LOGI(tag, "Debounce chceck - Buton level: %d", button_level);
    if(button_level  == 0)
        {
            ESP_LOGI(tag, "Button pressed! LED: %s", led_state ? "OFF" : "ON");
            led_state = !led_state;
            gpio_set_level(LED_PIN, led_state);
        }
}