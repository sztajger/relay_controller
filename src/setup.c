#include "setup.h"
#include "button_handler.h"
#include "esp_log.h"
#include "driver/gpio.h"


void setup_gpio(void)
{
    // LED AND RELAY CONFIG AS OUTPUTS
    gpio_config_t io_conf =
    {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << LED_PIN) | (1ULL << RELAY_PIN),
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    }; 
    gpio_config(&io_conf);

    // BUTTON CONFIG AS INPUT PULL UP
    gpio_config_t btn_conf =
    {
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1ULL << BUTTON_PIN),
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_NEGEDGE, //For pullup resistor, if use pulldown GPIO_INTR_POSEDGE
    };
    gpio_config(&btn_conf);

    // START STATES
    gpio_set_level(LED_PIN, 0);
    gpio_set_level(RELAY_PIN, 1);
}

void setup_timer(TimerHandle_t *debounce_timer)
{
    *debounce_timer = xTimerCreate("debouncie_timer", pdMS_TO_TICKS(DEBOUNCE_TIME_MS), pdFALSE, NULL, debounce_timer_callback);
    if (*debounce_timer == NULL)
    {
        ESP_LOGE("SETUP", "Failed to create debounce timer");
        return;
    }
}
void setup_isr(TimerHandle_t debounce_timer)
{
    if (gpio_install_isr_service(0) != ESP_OK)
    {
        ESP_LOGE("SETUP", "ISR service install failed");
        return;
    }

    if (gpio_isr_handler_add(BUTTON_PIN, button_isr_handler, (void*) debounce_timer) != ESP_OK)
    {
        ESP_LOGE("SETUP", "ISR handler add failed");
    }
}