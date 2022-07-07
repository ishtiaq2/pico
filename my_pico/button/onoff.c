#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_PIN 18
#define LED_PIN 19

int main() {
    stdio_init_all();
    printf("Button Test LED ON OFF");
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(true) {
        if (!gpio_get(BUTTON_PIN)) {
            gpio_put(LED_PIN, 1);
            printf("Button Pressed >> \n");
        } else {
            gpio_put(LED_PIN, 0);
        }
        sleep_ms(200);
    }
}