#ifndef SETUP_H
#define SETUP_H

#include "driver/gpio.h"
#include "driver/rtc_io.h"

#define LED_PIN GPIO_NUM_2
#define RELAY_PIN GPIO_NUM_18
#define BUTTON_PIN GPIO_NUM_15
#define BATTERY_PIN GPIO_NUM_34

void setup(void);

#endif