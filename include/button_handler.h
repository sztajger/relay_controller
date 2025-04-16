#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

void IRAM_ATTR button_isr_handler(void *arg);
void debounce_timer_callback(TimerHandle_t xTimer);


#endif