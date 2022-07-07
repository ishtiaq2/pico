#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main() {
    stdio_init_all();
    const uint _PIN = 21;
    gpio_init(_PIN);
    gpio_set_dir(_PIN, GPIO_IN);
    gpio_pull_up(_PIN);

    while(true) {
        if (!gpio_get(_PIN)) {
            printf("%s\n", ">>>> Button Pressed");
            //sleep_ms(3000);
        } else {
            //printf("Button Not Pressed \n");
            //sleep_ms(1000);
        }
        sleep_ms(250);
    }
}