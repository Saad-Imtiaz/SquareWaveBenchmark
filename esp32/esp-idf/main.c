#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define LEDC_LS_TIMER          LEDC_TIMER_0
#define LEDC_LS_MODE           LEDC_LOW_SPEED_MODE
#define LEDC_LS_CH0_GPIO       (7) // Use GPIO 17 for the output
#define LEDC_LS_CH0_CHANNEL    LEDC_CHANNEL_0
#define LEDC_TEST_DUTY         (2) // 50% duty cycle (with 2-bit resolution)
#define LEDC_TEST_FREQ         (20039138) // 20 MHz (lower frequency for testing)

void app_main(void)
{
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_2_BIT, // Lower duty resolution
        .freq_hz = LEDC_TEST_FREQ,
        .speed_mode = LEDC_LS_MODE,
        .timer_num = LEDC_LS_TIMER,
        .clk_cfg = LEDC_AUTO_CLK,
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .channel    = LEDC_LS_CH0_CHANNEL,
        .duty       = LEDC_TEST_DUTY,
        .gpio_num   = LEDC_LS_CH0_GPIO,
        .speed_mode = LEDC_LS_MODE,
        .hpoint     = 0,
        .timer_sel  = LEDC_LS_TIMER
    };
    ledc_channel_config(&ledc_channel);

    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
