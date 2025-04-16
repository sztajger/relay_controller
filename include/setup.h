#ifndef SETUP_H
#define SETUP_H

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "driver/rtc_io.h"
#include <freertos/projdefs.h>

#define LED_PIN GPIO_NUM_2
#define RELAY_PIN GPIO_NUM_18
#define BUTTON_PIN GPIO_NUM_15
#define BATTERY_PIN GPIO_NUM_34

#define DEBOUNCE_TIME_MS 300

void setup_gpio(void);
void setup_timer(TimerHandle_t *debounce_timer);
void setup_isr(TimerHandle_t debounce_timer);

#endif