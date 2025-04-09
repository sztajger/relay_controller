#include "setup.h"
#include "driver/gpio.h"
#include "driver/rtc_io.h"


void setup(void)
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
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&btn_conf);

    // START STATES
    gpio_set_level(LED_PIN, 0);
    gpio_set_level(RELAY_PIN, 1);

    // RTC FOR RELAY PIN (LATER)
}